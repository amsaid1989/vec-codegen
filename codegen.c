#include "aliases.h"
#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// clang-format off
#define VEC_TYPEINFO(TYPE, SPEC) (vec_typeinfo){#TYPE, SPEC}
// clang-format on

#define ARR_LEN(ARR) sizeof(ARR) / sizeof(ARR[0])

#define MIN_ELEM_COUNT 2

typedef struct {
  const char *type_name;
  const char *format_spec;
} vec_typeinfo;

typedef struct {
  vec_typeinfo info;
  u64 min;
  u64 max;
} vec_type_decl;

typedef struct {
  vec_typeinfo info;
  u64 elem_count;
} vec_typedef;

void str_toupper(char *dst, const char *src, u64 len);
void create_vector_struct(const vec_typedef *vt, FILE *fp);
void decl_print_vector(const vec_typedef *vt, FILE *fp);
void def_print_vector(const vec_typedef *vt, FILE *fp);

static char elem_names[] = {'x', 'y', 'z', 'w'};
static vec_typeinfo elem_types[] = {
    VEC_TYPEINFO(int, "%d"),
    VEC_TYPEINFO(float, "%f"),
    VEC_TYPEINFO(double, "%lf"),
};

i32 main(i32 argc, char *argv[]) {
  if (argc < 2) {
    printf("Provide base file name\n");
    return 1;
  }

  u64 type_count = ARR_LEN(elem_types);
  u64 max_elem_count = ARR_LEN(elem_names);

  vec_type_decl vec_decls[type_count];

  for (u32 i = 0; i < type_count; ++i) {
    vec_decls[i] =
        (vec_type_decl){elem_types[i], MIN_ELEM_COUNT, max_elem_count};
  }

  const char *base_filename = argv[1];

  char header_name[1024] = {0};
  char source_name[1024] = {0};

  sprintf(header_name, "%s.h", base_filename);
  sprintf(source_name, "%s.c", base_filename);

  // CREATE HEADER FILE
  FILE *fp = fopen(header_name, "w");
  if (!fp) {
    printf("Failed to open file %s\n", header_name);
    return 2;
  }

  u64 len = strlen(base_filename);
  char header_guard[len + 1];
  memset((void *)header_guard, 0, len + 1);
  str_toupper(header_guard, base_filename, len);

  fprintf(fp, "#ifndef %s_H\n", header_guard);
  fprintf(fp, "#define %s_H\n\n", header_guard);

  fprintf(fp, "#include \"aliases.h\"\n");
  fprintf(fp, "#include <stdint.h>\n");
  fprintf(fp, "#include <stdio.h>\n\n");

  fprintf(fp, "#define VEC(TYPE, COUNT) vec##COUNT##_##TYPE\n");
  fprintf(fp, "#define PRINT_VEC(TYPE, COUNT) print_vec##COUNT##_##TYPE\n\n");

  for (u32 i = 0; i < type_count; ++i) {
    vec_type_decl *vec_decl = &(vec_decls[i]);
    vec_typedef vt = {vec_decl->info};

    for (u8 j = vec_decl->min; j <= vec_decl->max; ++j) {
      vt.elem_count = j;

      create_vector_struct(&vt, fp);
      decl_print_vector(&vt, fp);
    }
  }

  fprintf(fp, "\n#endif // %s_H\n", header_guard);

  fclose(fp);

  // CREATE SOURCE FILE
  fp = fopen(source_name, "w");
  if (!fp) {
    printf("Failed to open file %s\n", source_name);
    return 2;
  }

  fprintf(fp, "#include \"%s\"\n\n", header_name);

  for (u32 i = 0; i < type_count; ++i) {
    vec_type_decl *vec_decl = &(vec_decls[i]);
    vec_typedef vt = {vec_decl->info};

    for (u8 j = vec_decl->min; j <= vec_decl->max; ++j) {
      vt.elem_count = j;

      def_print_vector(&vt, fp);
    }
  }

  fclose(fp);

  return EXIT_SUCCESS;
}

void str_toupper(char *dst, const char *src, u64 len) {
  for (u32 i = 0; i < len; ++i) {
    dst[i] = toupper(src[i]);
  }
}

void create_vector_struct(const vec_typedef *vt, FILE *fp) {
  fprintf(fp, "typedef struct {\n");

  for (u8 i = 0; i < vt->elem_count; ++i) {
    fprintf(fp, "\t%s %c;\n", vt->info.type_name, elem_names[i]);
  }

  fprintf(fp, "} vec%zu_%s;\n", vt->elem_count, vt->info.type_name);
}

void decl_print_vector(const vec_typedef *vt, FILE *fp) {
  fprintf(fp, "void print_vec%zu_%s(const vec%zu_%s *vec);\n\n", vt->elem_count,
          vt->info.type_name, vt->elem_count, vt->info.type_name);
}

void def_print_vector(const vec_typedef *vt, FILE *fp) {
  fprintf(fp, "void print_vec%zu_%s(const vec%zu_%s *vec) {\n", vt->elem_count,
          vt->info.type_name, vt->elem_count, vt->info.type_name);

  for (u8 i = 0; i < vt->elem_count; ++i) {
    fprintf(fp, "\tprintf(\"%c: %s\t\", vec->%c);\n", elem_names[i],
            vt->info.format_spec, elem_names[i]);
  }

  fprintf(fp, "}\n\n");
}
