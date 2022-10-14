// This is a dummy-app, mad mainly for practising CMake. For now it will mainly contain testing functionality for the quadrature library. 
#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#include "unity.h"

#include "skallaquad.h"

void setUp(void) {}

void tearDown(void) {}

float f(float x) {
    return x * x;
}

float g(float x) {
    return x;
}


void test_function_single_step_integral(void) {
    // Single step corresponds to a single triangle, indep of function
    TEST_ASSERT_EQUAL_FLOAT(0.5, trapezoid(g, 0, 1, 1.));
    TEST_ASSERT_EQUAL_FLOAT(0.5, trapezoid(f, 0, 1, 1.));
}

void test_function_interval_is_taken_into_account(void) {
    // Change of interval is taken into account
    TEST_ASSERT_EQUAL_FLOAT(0.5, trapezoid(f, 0, 1, 1.));    
}


void test_function_refinement_reduce_error(void) {
    // Error should be smaller under refinement for simple functions.
    float last_err = 1E10;
    float dx = 1.;
    float err;
    for(int i=0; i<10; i++) {
        dx = dx / 2.;
        err = fabs(trapezoid(f, 0, 1, dx) - 1./3.);
        printf("%.5f\t%.8f\n", dx, err);
        TEST_ASSERT(err <= last_err || err <= 1E-5);
        last_err = err;
    }
    TEST_ASSERT_FLOAT_WITHIN(1e-6, 0.0, last_err);
}

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_function_single_step_integral);
    RUN_TEST(test_function_interval_is_taken_into_account);
    RUN_TEST(test_function_refinement_reduce_error);
    return UNITY_END();

    return 0;
}
