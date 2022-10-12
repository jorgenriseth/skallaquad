#include <assert.h>
#include <math.h>

#include "skallaquad.h"

typedef float (*FloatFunction)(float x);

float trapezoid(FloatFunction f, float a, float b, float dx) {
    assert( a <= b && 0. < dx);
    float total = 0.;
    int N = ceilf((b - a) / dx);
    float h = (b - a) / N;

    total += 0.5 * (f(a) + f(b));
    float xi = a + h;
    for (int i=1; i < N; i++){
        total += f(xi);
        xi += h;
    }
    return total * h;
}
