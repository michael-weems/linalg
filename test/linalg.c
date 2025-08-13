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
	Vector2_F32 vec = {v1, v2};
	mdwi_vector2_f32_scale(vec, scalar);
	assertf(vec[0] == e1, "%s: vec[0] = %f: expected %f", fname, e1, vec[0]);
	assertf(vec[1] == e2, "%s: vec[1] = %f: expected %f", fname, e2, vec[1]);
}

void test_vector2_f32_scale() {
	char fname[] = "test_vector_2_f32_scale";

	float v1 = 2.0, v2 = 2.0, scalar = 2.0, e1 = 4.0, e2 = 4.0;
	_test_vector2_f32_scale(fname, v1, v2, scalar, e1, e2);

	v1 = 16.0; v2 = 2.0; scalar = 1.0; e1 = 16.0; e2 = 2.0;
	_test_vector2_f32_scale(fname, v1, v2, scalar, e1, e2);

	v1 = -1.0; v2 = -2.0; scalar = 1.0; e1 = -1.0; e2 = -2.0;
	_test_vector2_f32_scale(fname, v1, v2, scalar, e1, e2);

	pass("%s", fname);
}

int main() {
	test_vector2_f32_scale();

	exit(failed_tests);
}
