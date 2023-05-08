#include "vec.h"

void print_vec2_int(const vec2_int *vec) {
	printf("x: %d	", vec->x);
	printf("y: %d	", vec->y);
}

void print_vec3_int(const vec3_int *vec) {
	printf("x: %d	", vec->x);
	printf("y: %d	", vec->y);
	printf("z: %d	", vec->z);
}

void print_vec4_int(const vec4_int *vec) {
	printf("x: %d	", vec->x);
	printf("y: %d	", vec->y);
	printf("z: %d	", vec->z);
	printf("w: %d	", vec->w);
}

void print_vec2_float(const vec2_float *vec) {
	printf("x: %f	", vec->x);
	printf("y: %f	", vec->y);
}

void print_vec3_float(const vec3_float *vec) {
	printf("x: %f	", vec->x);
	printf("y: %f	", vec->y);
	printf("z: %f	", vec->z);
}

void print_vec4_float(const vec4_float *vec) {
	printf("x: %f	", vec->x);
	printf("y: %f	", vec->y);
	printf("z: %f	", vec->z);
	printf("w: %f	", vec->w);
}

void print_vec2_double(const vec2_double *vec) {
	printf("x: %lf	", vec->x);
	printf("y: %lf	", vec->y);
}

void print_vec3_double(const vec3_double *vec) {
	printf("x: %lf	", vec->x);
	printf("y: %lf	", vec->y);
	printf("z: %lf	", vec->z);
}

void print_vec4_double(const vec4_double *vec) {
	printf("x: %lf	", vec->x);
	printf("y: %lf	", vec->y);
	printf("z: %lf	", vec->z);
	printf("w: %lf	", vec->w);
}

