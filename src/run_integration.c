// This is a dummy-app, mad mainly for practising CMake. For now it will mainly contain testing functionality for the quadrature library. 
#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include "skallaquad.h"

float f(float x) {
    return x * x;
}

float g(float x) {
    return x;
}

bool assert_approx(float value, float target, float TOL) {
    return fabs(target-value) < TOL;
}

int main() {
    // Single step corresponds to a single triangle, indep of function
    assert_approx(trapezoid(g, 0, 1, 1.), 0.5, 1E-6);
    assert_approx(trapezoid(f, 0, 1, 1.), 0.5, 1E-6);

    // Change of interval is taken into account
    assert_approx(trapezoid(g, -1., 1, 0.1), 0., 1E-6);

    // Error should be smaller under refinement for simple functions.
    float last_err = 1E10;
    float dx;
    float err;
    for(int i=0; i<5; i++) {
        dx = 1. / pow(10, i);
        err = fabs(trapezoid(f, 0, 1, dx) - 1./3.);
        printf("%.5f\t%.8f\n", dx, err);
        assert(err <= last_err || err <= 1E-5);
        last_err = err;
    }
    assert_approx(last_err, 0., 1E-6);
    return 0;
}
