#define MDW_LINALG_IMPLEMENTATION
#include "../linalg.h"
#include <stdarg.h>
#include <stdio.h>

int failed_tests = 0;

void assertf(int cond, const char *format, ...) {
		if (cond == 1) return;

    va_list args;
    va_start(args, format);
    printf("\x1B[31mfail >> \x1B[0m");
    vprintf(format, args);
    printf("\n");
    va_end(args);
		failed_tests += 1;
}
void pass(const char *format, ...) {
    va_list args;
    va_start(args, format);
    printf("\x1B[32mpass >> \x1B[0m");
    vprintf(format, args);
    printf("\n");
    va_end(args);
}

void _test_vector2_f32_scale(const char *fname, float v1, float v2, float scalar, float e1, float e2) {
	static int test_case = 1;
	Vector2_F32 vec = {v1, v2};
	mdwi_vector2_f32_scale(vec, scalar);
	assertf(vec[0] == e1, "%s: test case %d: vec[0] = %f: expected %f", fname, test_case, vec[0], e1);
	assertf(vec[1] == e2, "%s: test case %d: vec[1] = %f: expected %f", fname, test_case, vec[1], e2);
	++test_case;
}
void test_vector2_f32_scale() {
	char fname[] = "mdwi_vector2_f32_scale";

	float v1 = 2.0, v2 = 2.0, scalar = 2.0, e1 = 4.0, e2 = 4.0;
	_test_vector2_f32_scale(fname, v1, v2, scalar, e1, e2);

	v1 = 16.0; v2 = 2.0; scalar = 1.0; e1 = 16.0; e2 = 2.0;
	_test_vector2_f32_scale(fname, v1, v2, scalar, e1, e2);

	v1 = -1.0; v2 = -2.0; scalar = 1.0; e1 = -1.0; e2 = -2.0;
	_test_vector2_f32_scale(fname, v1, v2, scalar, e1, e2);

	pass("%s", fname);
}

void _test_vector3_f32_scale(const char *fname, float v1, float v2, float v3, float scalar, float e1, float e2, float e3) {
	static int test_case = 1;
	Vector3_F32 vec = {v1, v2, v3};
	mdwi_vector3_f32_scale(vec, scalar);
	assertf(vec[0] == e1, "%s: test case %d: vec[0] = %f: expected %f", fname, test_case, vec[0], e1);
	assertf(vec[1] == e2, "%s: test case %d: vec[1] = %f: expected %f", fname, test_case, vec[1], e2);
	assertf(vec[2] == e3, "%s: test case %d: vec[2] = %f: expected %f", fname, test_case, vec[2], e3);
	++test_case;
}
void test_vector3_f32_scale() {
	char fname[] = "mdwi_vector3_f32_scale";

	float v1 = 2.0, v2 = 2.0, v3 = 1.5, scalar = 2.0, e1 = 4.0, e2 = 4.0, e3 = 3.0;
	_test_vector3_f32_scale(fname, v1, v2, v3, scalar, e1, e2, e3);

	v1 = 16.0; v2 = 2.0; v3 = 1.5; scalar = 1.0; e1 = 16.0; e2 = 2.0; e3 = 1.5; 
	_test_vector3_f32_scale(fname, v1, v2, v3, scalar, e1, e2, e3);

	v1 = -1.0; v2 = -2.0; v3 = -1.5; scalar = 1.0; e1 = -1.0; e2 = -2.0; e3 = -1.5;
	_test_vector3_f32_scale(fname, v1, v2, v3, scalar, e1, e2, e3);

	v1 = -1.0; v2 = -2.0; v3 = 1.5; scalar = -1.0; e1 = 1.0; e2 = 2.0; e3 = -1.5;
	_test_vector3_f32_scale(fname, v1, v2, v3, scalar, e1, e2, e3);

	pass("%s", fname);
}

void _test_vector4_f32_scale(const char *fname, float v1, float v2, float v3, float v4, float scalar, float e1, float e2, float e3, float e4) {
	static int test_case = 1;
	Vector4_F32 vec = {v1, v2, v3, v4};
	mdwi_vector4_f32_scale(vec, scalar);
	assertf(vec[0] == e1, "%s: test case %d: vec[0] = %f: expected %f", fname, test_case, vec[0], e1);
	assertf(vec[1] == e2, "%s: test case %d: vec[1] = %f: expected %f", fname, test_case, vec[1], e2);
	assertf(vec[2] == e3, "%s: test case %d: vec[2] = %f: expected %f", fname, test_case, vec[2], e3);
	assertf(vec[3] == e4, "%s: test case %d: vec[3] = %f: expected %f", fname, test_case, vec[3], e4);
	++test_case;
}
void test_vector4_f32_scale() {
	char fname[] = "mdwi_vector4_f32_scale";

	float v1 = 2.0, v2 = 2.0, v3 = 1.5, v4 = 2.3, scalar = 2.0, e1 = 4.0, e2 = 4.0, e3 = 3.0, e4 = 4.6;
	_test_vector4_f32_scale(fname, v1, v2, v3, v4, scalar, e1, e2, e3, e4);

	v1 = 16.0; v2 = 2.0; v3 = 1.5; v4 = 1.1; scalar = 1.0; e1 = 16.0; e2 = 2.0; e3 = 1.5, e4 = 1.1; 
	_test_vector4_f32_scale(fname, v1, v2, v3, v4, scalar, e1, e2, e3, e4);

	v1 = -1.0; v2 = -2.0; v3 = -1.5; v4 = -12.3; scalar = 1.0; e1 = -1.0; e2 = -2.0; e3 = -1.5; e4 = -12.3;
	_test_vector4_f32_scale(fname, v1, v2, v3, v4, scalar, e1, e2, e3, e4);

	v1 = -1.0; v2 = -2.0; v3 = 1.5; v4 = 0.2; scalar = -1.0; e1 = 1.0; e2 = 2.0; e3 = -1.5; e4 = -0.2;
	_test_vector4_f32_scale(fname, v1, v2, v3, v4, scalar, e1, e2, e3, e4);

	pass("%s", fname);
}

void _test_vector2_f32_transform_matrix2_f32(const char *fname, Vector2_F32 in, Matrix2_F32 mat, Vector2_F32 ex) {
	static int test_case = 1;
	mdwi_vector2_f32_transform_matrix2_f32(in, mat);
	assertf(in[0] == ex[0], "%s: test case %d: vec[0] = %f: expected %f", fname, test_case, in[0], ex[0]);
	assertf(in[1] == ex[1], "%s: test case %d: vec[1] = %f: expected %f", fname, test_case, in[1], ex[1]);
	++test_case;
}
void test_vector2_f32_transform_matrix2_f32() {
	char fname[] = "mdwi_vector2_f32_transform_matrix2_f32";

	Vector2_F32 vec = {  1.0,
											 2.0 };
	Matrix2_F32 mat = { {1.0, 0.0},
											{0.0, 1.0} };
	Vector2_F32 ex =  {  1.0,
											 2.0 };

	_test_vector2_f32_transform_matrix2_f32(fname, vec, mat, ex);

	mat[0][0] = 0.0; mat[1][0] = 1.0; vec[0] = 2.5; ex[0] = 3.1; 
	mat[0][1] = 1.0; mat[1][1] = 0.0; vec[1] = 3.1; ex[1] = 2.5;
	_test_vector2_f32_transform_matrix2_f32(fname, vec, mat, ex);

	pass("%s", fname);
}

void _test_vector3_f32_transform_matrix3_f32(const char *fname, Vector3_F32 in, Matrix3_F32 mat, Vector3_F32 ex) {
	static int test_case = 1;
	mdwi_vector3_f32_transform_matrix3_f32(in, mat);
	assertf(in[0] == ex[0], "%s: test case %d: vec[0] = %f: expected %f", fname, test_case, in[0], ex[0]);
	assertf(in[1] == ex[1], "%s: test case %d: vec[1] = %f: expected %f", fname, test_case, in[1], ex[1]);
	assertf(in[2] == ex[2], "%s: test case %d: vec[2] = %f: expected %f", fname, test_case, in[2], ex[2]);
	++test_case;
}
void test_vector3_f32_transform_matrix3_f32() {
	char fname[] = "mdwi_vector3_f32_transform_matrix3_f32";

	Vector3_F32 vec = {  1.0,
											 2.0,
											 3.0 };
	Matrix3_F32 mat = { {1.0, 0.0, 0.0},
											{0.0, 1.0, 0.0},
											{0.0, 0.0, 1.0} };
	Vector3_F32 ex =  {  1.0,
											 2.0,
	                     3.0 };

	_test_vector3_f32_transform_matrix3_f32(fname, vec, mat, ex);

	mat[0][0] = 0.0; mat[1][0] = 0.0; mat[2][0] = 1.0; vec[0] = 2.5; ex[0] = 7.5; 
	mat[0][1] = 0.0; mat[1][1] = 1.0; mat[2][1] = 0.0; vec[1] = 3.1; ex[1] = 3.1;
	mat[0][2] = 1.0; mat[1][2] = 0.0; mat[2][2] = 0.0; vec[2] = 7.5; ex[2] = 2.5;
	_test_vector3_f32_transform_matrix3_f32(fname, vec, mat, ex);

	pass("%s", fname);
}

void _test_vector4_f32_transform_matrix4_f32(const char *fname, Vector4_F32 in, Matrix4_F32 mat, Vector4_F32 ex) {
	static int test_case = 1;
	mdwi_vector4_f32_transform_matrix4_f32(in, mat);
	assertf(in[0] == ex[0], "%s: test case %d: vec[0] = %f: expected %f", fname, test_case, in[0], ex[0]);
	assertf(in[1] == ex[1], "%s: test case %d: vec[1] = %f: expected %f", fname, test_case, in[1], ex[1]);
	assertf(in[2] == ex[2], "%s: test case %d: vec[2] = %f: expected %f", fname, test_case, in[2], ex[2]);
	assertf(in[3] == ex[3], "%s: test case %d: vec[3] = %f: expected %f", fname, test_case, in[3], ex[3]);
	++test_case;
}
void test_vector4_f32_transform_matrix4_f32() {
	char fname[] = "mdwi_vector4_f32_transform_matrix4_f32";

	Vector4_F32 vec = {  1.0,
											 2.0,
											 3.0,
	                     4.0 };
	Matrix4_F32 mat = { {1.0, 0.0, 0,0, 0.0},
											{0.0, 1.0, 0.0, 0.0},
											{0.0, 0.0, 1.0, 0.0},
	                    {0.0, 0.0, 0.0, 1.0} };
	Vector4_F32 ex =  {  1.0,
											 2.0,
	                     3.0,
		                   4.0 };
	_test_vector4_f32_transform_matrix4_f32(fname, vec, mat, ex);

	mat[0][0] = 0.0; mat[1][0] = 0.0; mat[2][0] = 0.0; mat[3][0] = 1.0; vec[0] = 2.5; ex[0] = 9.3; 
	mat[0][1] = 0.0; mat[1][1] = 0.0; mat[2][1] = 1.0; mat[3][1] = 0.0; vec[1] = 3.1; ex[1] = 7.5;
	mat[0][2] = 0.0; mat[1][2] = 1.0; mat[2][2] = 0.0; mat[3][2] = 0.0; vec[2] = 7.5; ex[2] = 3.1;
	mat[0][3] = 1.0; mat[1][3] = 0.0; mat[2][3] = 0.0; mat[3][3] = 0.0; vec[3] = 9.3; ex[3] = 2.5;
	_test_vector4_f32_transform_matrix4_f32(fname, vec, mat, ex);

	pass("%s", fname);
}


int main() {
	test_vector2_f32_scale();
	test_vector3_f32_scale();
	test_vector4_f32_scale();

	test_vector2_f32_transform_matrix2_f32();
	test_vector3_f32_transform_matrix3_f32();
	test_vector4_f32_transform_matrix4_f32();

	exit(failed_tests);
}
