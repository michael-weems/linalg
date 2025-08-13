#define MDW_LINALG_IMPLEMENTATION
#include "../linalg.h"
#include <stdarg.h>
#include <stdio.h>

int failed_tests = 0;

int assertf(int cond, const char *format, ...) {
		if (cond == 1) return 0;

    va_list args;
    va_start(args, format);
    printf("\x1B[31mfail >> \x1B[0m");
    vprintf(format, args);
    printf("\n");
    va_end(args);
		failed_tests += 1;
		return 1;
}
void pass(const char *format, ...) {
    va_list args;
    va_start(args, format);
    printf("\x1B[32mpass >> \x1B[0m");
    vprintf(format, args);
    printf("\n");
    va_end(args);
}
void fail(const char *format, ...) {
    va_list args;
    va_start(args, format);
    printf("\x1B[31m---- fail >> ");
    vprintf(format, args);
    printf(" ----\x1B[0m\n");
    va_end(args);
}

int _test_vector2_f32_scale(const char *fname, float v1, float v2, float scalar, float e1, float e2) {
	static int test_case = 1;
	int err = 0;
	Vector2_F32 vec = {v1, v2};
	mdwi_vector2_f32_scale(vec, scalar);
	err += assertf(vec[0] == e1, "%s: test case %d: vec[0] = %f: expected %f", fname, test_case, vec[0], e1);
	err += assertf(vec[1] == e2, "%s: test case %d: vec[1] = %f: expected %f", fname, test_case, vec[1], e2);
	++test_case;
	return err;
}
void test_vector2_f32_scale() {
	char fname[] = "mdwi_vector2_f32_scale";
	int err = 0;

	float v1 = 2.0, v2 = 2.0, scalar = 2.0, e1 = 4.0, e2 = 4.0;
	err += _test_vector2_f32_scale(fname, v1, v2, scalar, e1, e2);

	v1 = 16.0; v2 = 2.0; scalar = 1.0; e1 = 16.0; e2 = 2.0;
	err += _test_vector2_f32_scale(fname, v1, v2, scalar, e1, e2);

	v1 = -1.0; v2 = -2.0; scalar = 1.0; e1 = -1.0; e2 = -2.0;
	err += _test_vector2_f32_scale(fname, v1, v2, scalar, e1, e2);

	if (err == 0) pass("%s", fname);
	else fail("%s", fname);
}

int _test_vector3_f32_scale(const char *fname, float v1, float v2, float v3, float scalar, float e1, float e2, float e3) {
	static int test_case = 1;
	int err = 0;
	Vector3_F32 vec = {v1, v2, v3};
	mdwi_vector3_f32_scale(vec, scalar);
	err += assertf(vec[0] == e1, "%s: test case %d: vec[0] = %f: expected %f", fname, test_case, vec[0], e1);
	err += assertf(vec[1] == e2, "%s: test case %d: vec[1] = %f: expected %f", fname, test_case, vec[1], e2);
	err += assertf(vec[2] == e3, "%s: test case %d: vec[2] = %f: expected %f", fname, test_case, vec[2], e3);
	++test_case;
	return err;
}
void test_vector3_f32_scale() {
	char fname[] = "mdwi_vector3_f32_scale";
	int err = 0;

	float v1 = 2.0, v2 = 2.0, v3 = 1.5, scalar = 2.0, e1 = 4.0, e2 = 4.0, e3 = 3.0;
	err += _test_vector3_f32_scale(fname, v1, v2, v3, scalar, e1, e2, e3);

	v1 = 16.0; v2 = 2.0; v3 = 1.5; scalar = 1.0; e1 = 16.0; e2 = 2.0; e3 = 1.5; 
	err += _test_vector3_f32_scale(fname, v1, v2, v3, scalar, e1, e2, e3);

	v1 = -1.0; v2 = -2.0; v3 = -1.5; scalar = 1.0; e1 = -1.0; e2 = -2.0; e3 = -1.5;
	err += _test_vector3_f32_scale(fname, v1, v2, v3, scalar, e1, e2, e3);

	v1 = -1.0; v2 = -2.0; v3 = 1.5; scalar = -1.0; e1 = 1.0; e2 = 2.0; e3 = -1.5;
	err += _test_vector3_f32_scale(fname, v1, v2, v3, scalar, e1, e2, e3);

	if (err == 0) pass("%s", fname);
	else fail("%s", fname);
}

int _test_vector4_f32_scale(const char *fname, float v1, float v2, float v3, float v4, float scalar, float e1, float e2, float e3, float e4) {
	static int test_case = 1;
	int err = 0;
	Vector4_F32 vec = {v1, v2, v3, v4};
	mdwi_vector4_f32_scale(vec, scalar);
	err += assertf(vec[0] == e1, "%s: test case %d: vec[0] = %f: expected %f", fname, test_case, vec[0], e1);
	err += assertf(vec[1] == e2, "%s: test case %d: vec[1] = %f: expected %f", fname, test_case, vec[1], e2);
	err += assertf(vec[2] == e3, "%s: test case %d: vec[2] = %f: expected %f", fname, test_case, vec[2], e3);
	err += assertf(vec[3] == e4, "%s: test case %d: vec[3] = %f: expected %f", fname, test_case, vec[3], e4);
	++test_case;
	return err;
}
void test_vector4_f32_scale() {
	char fname[] = "mdwi_vector4_f32_scale";
	int err = 0;

	float v1 = 2.0, v2 = 2.0, v3 = 1.5, v4 = 2.3, scalar = 2.0, e1 = 4.0, e2 = 4.0, e3 = 3.0, e4 = 4.6;
	err += _test_vector4_f32_scale(fname, v1, v2, v3, v4, scalar, e1, e2, e3, e4);

	v1 = 16.0; v2 = 2.0; v3 = 1.5; v4 = 1.1; scalar = 1.0; e1 = 16.0; e2 = 2.0; e3 = 1.5, e4 = 1.1; 
	err += _test_vector4_f32_scale(fname, v1, v2, v3, v4, scalar, e1, e2, e3, e4);

	v1 = -1.0; v2 = -2.0; v3 = -1.5; v4 = -12.3; scalar = 1.0; e1 = -1.0; e2 = -2.0; e3 = -1.5; e4 = -12.3;
	err += _test_vector4_f32_scale(fname, v1, v2, v3, v4, scalar, e1, e2, e3, e4);

	v1 = -1.0; v2 = -2.0; v3 = 1.5; v4 = 0.2; scalar = -1.0; e1 = 1.0; e2 = 2.0; e3 = -1.5; e4 = -0.2;
	err += _test_vector4_f32_scale(fname, v1, v2, v3, v4, scalar, e1, e2, e3, e4);

	if (err == 0) pass("%s", fname);
	else fail("%s", fname);
}

int _test_vector2_f32_transform_matrix2_f32(const char *fname, Vector2_F32 in, Matrix2_F32 mat, Vector2_F32 ex) {
	static int test_case = 1;
	int err = 0;
	mdwi_vector2_f32_transform_matrix2_f32(in, mat);
	err += assertf(in[0] == ex[0], "%s: test case %d: vec[0] = %f: expected %f", fname, test_case, in[0], ex[0]);
	err += assertf(in[1] == ex[1], "%s: test case %d: vec[1] = %f: expected %f", fname, test_case, in[1], ex[1]);
	++test_case;
	return err;
}
void test_vector2_f32_transform_matrix2_f32() {
	char fname[] = "mdwi_vector2_f32_transform_matrix2_f32";
	int err = 0;

	Vector2_F32 vec = {  1.0,
											 2.0 };
	Matrix2_F32 mat = { {1.0, 0.0},
											{0.0, 1.0} };
	Vector2_F32 ex =  {  1.0,
											 2.0 };

	err += _test_vector2_f32_transform_matrix2_f32(fname, vec, mat, ex);

	mat[0][0] = 0.0; mat[1][0] = 1.0; vec[0] = 2.5; ex[0] = 3.1; 
	mat[0][1] = 1.0; mat[1][1] = 0.0; vec[1] = 3.1; ex[1] = 2.5;
	err += _test_vector2_f32_transform_matrix2_f32(fname, vec, mat, ex);

	if (err == 0) pass("%s", fname);
	else fail("%s", fname);
}

int _test_vector3_f32_transform_matrix3_f32(const char *fname, Vector3_F32 in, Matrix3_F32 mat, Vector3_F32 ex) {
	static int test_case = 1;
	int err = 0;
	mdwi_vector3_f32_transform_matrix3_f32(in, mat);
	err += assertf(in[0] == ex[0], "%s: test case %d: vec[0] = %f: expected %f", fname, test_case, in[0], ex[0]);
	err += assertf(in[1] == ex[1], "%s: test case %d: vec[1] = %f: expected %f", fname, test_case, in[1], ex[1]);
	err += assertf(in[2] == ex[2], "%s: test case %d: vec[2] = %f: expected %f", fname, test_case, in[2], ex[2]);
	++test_case;
	return err;
}
void test_vector3_f32_transform_matrix3_f32() {
	char fname[] = "mdwi_vector3_f32_transform_matrix3_f32";
	int err = 0;

	Vector3_F32 vec = {  1.0,
											 2.0,
											 3.0 };
	Matrix3_F32 mat = { {1.0, 0.0, 0.0},
											{0.0, 1.0, 0.0},
											{0.0, 0.0, 1.0} };
	Vector3_F32 ex =  {  1.0,
											 2.0,
	                     3.0 };

	err += _test_vector3_f32_transform_matrix3_f32(fname, vec, mat, ex);

	mat[0][0] = 0.0; mat[1][0] = 0.0; mat[2][0] = 1.0; vec[0] = 2.5; ex[0] = 7.5; 
	mat[0][1] = 0.0; mat[1][1] = 1.0; mat[2][1] = 0.0; vec[1] = 3.1; ex[1] = 3.1;
	mat[0][2] = 1.0; mat[1][2] = 0.0; mat[2][2] = 0.0; vec[2] = 7.5; ex[2] = 2.5;
	err += _test_vector3_f32_transform_matrix3_f32(fname, vec, mat, ex);

	if (err == 0) pass("%s", fname);
	else fail("%s", fname);
}

int _test_vector4_f32_transform_matrix4_f32(const char *fname, Vector4_F32 in, Matrix4_F32 mat, Vector4_F32 ex) {
	static int test_case = 1;
	int err = 0;
	mdwi_vector4_f32_transform_matrix4_f32(in, mat);
	err += assertf(in[0] == ex[0], "%s: test case %d: vec[0] = %f: expected %f", fname, test_case, in[0], ex[0]);
	err += assertf(in[1] == ex[1], "%s: test case %d: vec[1] = %f: expected %f", fname, test_case, in[1], ex[1]);
	err += assertf(in[2] == ex[2], "%s: test case %d: vec[2] = %f: expected %f", fname, test_case, in[2], ex[2]);
	err += assertf(in[3] == ex[3], "%s: test case %d: vec[3] = %f: expected %f", fname, test_case, in[3], ex[3]);
	++test_case;
	return err;
}
void test_vector4_f32_transform_matrix4_f32() {
	char fname[] = "mdwi_vector4_f32_transform_matrix4_f32";
	int err = 0;

	Vector4_F32 vec = {  1.0,
											 2.0,
											 3.0,
	                     4.0 };
	Matrix4_F32 mat = { {1.0, 0.0, 0.0, 0.0},
											{0.0, 1.0, 0.0, 0.0},
											{0.0, 0.0, 1.0, 0.0},
	                    {0.0, 0.0, 0.0, 1.0} };
	Vector4_F32 ex =  {  1.0,
											 2.0,
	                     3.0,
		                   4.0 };
	err += _test_vector4_f32_transform_matrix4_f32(fname, vec, mat, ex);

	mat[0][0] = 0.0; mat[1][0] = 0.0; mat[2][0] = 0.0; mat[3][0] = 1.0; vec[0] = 2.5; ex[0] = 9.3; 
	mat[0][1] = 0.0; mat[1][1] = 0.0; mat[2][1] = 1.0; mat[3][1] = 0.0; vec[1] = 3.1; ex[1] = 7.5;
	mat[0][2] = 0.0; mat[1][2] = 1.0; mat[2][2] = 0.0; mat[3][2] = 0.0; vec[2] = 7.5; ex[2] = 3.1;
	mat[0][3] = 1.0; mat[1][3] = 0.0; mat[2][3] = 0.0; mat[3][3] = 0.0; vec[3] = 9.3; ex[3] = 2.5;
	err += _test_vector4_f32_transform_matrix4_f32(fname, vec, mat, ex);

	if (err == 0) pass("%s", fname);
	else fail("%s", fname);
}

int _test_matrix3_f32_translate(const char *fname, Vector2_F32 v, Matrix3_F32 ex) {
	static int test_case = 1;
	int err = 0;
	Matrix3_F32 in;
	mdwi_matrix3_f32_translate(in, v);
	err += assertf(in[2][0] == ex[2][0], "%s: test case %d: mat[2][0] = %f: expected %f", fname, test_case, in[2][0], ex[2][0]);
	err += assertf(in[2][1] == ex[2][1], "%s: test case %d: mat[2][1] = %f: expected %f", fname, test_case, in[2][1], ex[2][1]);
	err += assertf(in[2][2] == ex[2][2], "%s: test case %d: mat[2][2] = %f: expected %f", fname, test_case, in[2][2], ex[2][2]);
	++test_case;
	return err;
}
void test_matrix3_f32_translate() {
	char fname[] = "mdwi_matrix3_f32_translate";
	int err = 0;

	Vector2_F32 vec = {  1.0,
	                     2.0 };
	Matrix3_F32 ex =  { {1.0, 0.0, 0.0},
											{0.0, 1.0, 0.0},
	                    {1.0, 2.0, 1.0} };
	err += _test_matrix3_f32_translate(fname, vec, ex);

	vec[0] = 2.5; ex[0][0] = 1.0; ex[1][0] = 0.0; ex[2][0] = 2.5; 
	vec[1] = 3.1; ex[0][1] = 0.0; ex[1][1] = 1.0; ex[2][1] = 3.1;
                ex[0][2] = 0.0; ex[1][2] = 0.0; ex[2][2] = 1.0;
	err += _test_matrix3_f32_translate(fname, vec, ex);

	if (err == 0) pass("%s", fname);
	else fail("%s", fname);
}

int _test_matrix4_f32_translate(const char *fname, Vector3_F32 v, Matrix4_F32 ex) {
	static int test_case = 1;
	int err = 0;
	Matrix4_F32 in;
	mdwi_matrix4_f32_translate(in, v);
	err += assertf(in[3][0] == ex[3][0], "%s: test case %d: mat[3][0] = %f: expected %f", fname, test_case, in[3][0], ex[3][0]);
	err += assertf(in[3][1] == ex[3][1], "%s: test case %d: mat[3][1] = %f: expected %f", fname, test_case, in[3][1], ex[3][1]);
	err += assertf(in[3][2] == ex[3][2], "%s: test case %d: mat[3][2] = %f: expected %f", fname, test_case, in[3][2], ex[3][2]);
	err += assertf(in[3][3] == ex[3][3], "%s: test case %d: mat[3][3] = %f: expected %f", fname, test_case, in[3][3], ex[3][3]);
	++test_case;
	return err;
}
void test_matrix4_f32_translate() {
	char fname[] = "mdwi_matrix4_f32_translate";
	int err = 0;

	Vector3_F32 vec = {  1.0,
	                     2.0,
	                     3.0 };
	Matrix4_F32 ex =  { {1.0, 0.0, 0.0, 0.0},
											{0.0, 1.0, 0.0, 0.0},
											{0.0, 0.0, 1.0, 0.0},
	                    {1.0, 2.0, 3.0, 1.0}, };
	err += _test_matrix4_f32_translate(fname, vec, ex);

	vec[0] = 2.5; ex[0][0] = 1.0; ex[1][0] = 0.0; ex[2][0] = 0.0; ex[3][0] = 2.5; 
	vec[1] = 3.1; ex[0][1] = 0.0; ex[1][1] = 1.0; ex[2][1] = 0.0; ex[3][1] = 3.1;
	vec[2] = 7.7; ex[0][2] = 0.0; ex[1][2] = 0.0; ex[2][2] = 1.0; ex[3][2] = 7.7;
                ex[0][3] = 0.0; ex[1][3] = 0.0; ex[2][3] = 0.0; ex[3][3] = 1.0;
	err += _test_matrix4_f32_translate(fname, vec, ex);

	if (err == 0) pass("%s", fname);
	else fail("%s", fname);
}

int main() {
	test_vector2_f32_scale();
	test_vector3_f32_scale();
	test_vector4_f32_scale();

	test_vector2_f32_transform_matrix2_f32();
	test_vector3_f32_transform_matrix3_f32();
	test_vector4_f32_transform_matrix4_f32();

	test_matrix3_f32_translate();
	test_matrix4_f32_translate();

	exit(failed_tests);
}
