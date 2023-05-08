#ifndef VEC_H
#define VEC_H

#include "aliases.h"
#include <stdint.h>
#include <stdio.h>

#define VEC(TYPE, COUNT) vec##COUNT##_##TYPE
#define PRINT_VEC(TYPE, COUNT) print_vec##COUNT##_##TYPE

typedef struct {
	int x;
	int y;
} vec2_int;
void print_vec2_int(const vec2_int *vec);

typedef struct {
	int x;
	int y;
	int z;
} vec3_int;
void print_vec3_int(const vec3_int *vec);

typedef struct {
	int x;
	int y;
	int z;
	int w;
} vec4_int;
void print_vec4_int(const vec4_int *vec);

typedef struct {
	float x;
	float y;
} vec2_float;
void print_vec2_float(const vec2_float *vec);

typedef struct {
	float x;
	float y;
	float z;
} vec3_float;
void print_vec3_float(const vec3_float *vec);

typedef struct {
	float x;
	float y;
	float z;
	float w;
} vec4_float;
void print_vec4_float(const vec4_float *vec);

typedef struct {
	double x;
	double y;
} vec2_double;
void print_vec2_double(const vec2_double *vec);

typedef struct {
	double x;
	double y;
	double z;
} vec3_double;
void print_vec3_double(const vec3_double *vec);

typedef struct {
	double x;
	double y;
	double z;
	double w;
} vec4_double;
void print_vec4_double(const vec4_double *vec);


#endif // VEC_H
