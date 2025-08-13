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

void test_vector2_f32_scale() {
	char fname[] = "test_vector_2_f32_scale";
	Vector2_F32 vec = {2.0,2.0};
	mdwi_vector2_f32_scale(vec, 2.0);
	assertf(vec[0] == 4.0, "%s: vec[0] = %f: expected %f", fname, 4.0, vec[0]);
	assertf(vec[1] == 4.0, "%s: vec[1] = %f: expected %f", fname, 4.0, vec[0]);

	vec[0] = 16.0; vec[1] = 2.0;
	mdwi_vector2_f32_scale(vec, 1);
	assertf(vec[0] == 16.0, "%s: vec[0] = %f: expected %f", fname, 16.0, vec[0]);
	assertf(vec[1] == 2.0,  "%s: vec[1] = %f: expected %f", fname, 2.0, vec[0]);

	pass("%s", fname);
}

int main() {
	test_vector2_f32_scale();

	exit(failed_tests);
}
