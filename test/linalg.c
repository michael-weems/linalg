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
	assertf(vec[0] == e1, "%s: test case %d: vec[0] = %f: expected %f", fname, test_case, e1, vec[0]);
	assertf(vec[1] == e2, "%s: test case %d: vec[1] = %f: expected %f", fname, test_case, e2, vec[1]);
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
	assertf(vec[0] == e1, "%s: test case %d: vec[0] = %f: expected %f", fname, test_case, e1, vec[0]);
	assertf(vec[1] == e2, "%s: test case %d: vec[1] = %f: expected %f", fname, test_case, e2, vec[1]);
	assertf(vec[2] == e3, "%s: test case %d: vec[2] = %f: expected %f", fname, test_case, e3, vec[2]);
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
	assertf(vec[0] == e1, "%s: test case %d: vec[0] = %f: expected %f", fname, test_case, e1, vec[0]);
	assertf(vec[1] == e2, "%s: test case %d: vec[1] = %f: expected %f", fname, test_case, e2, vec[1]);
	assertf(vec[2] == e3, "%s: test case %d: vec[2] = %f: expected %f", fname, test_case, e3, vec[2]);
	assertf(vec[3] == e4, "%s: test case %d: vec[3] = %f: expected %f", fname, test_case, e4, vec[3]);
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

int main() {
	test_vector2_f32_scale();
	test_vector3_f32_scale();
	test_vector4_f32_scale();

	exit(failed_tests);
}
