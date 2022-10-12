#ifndef __SKALLAQUAD_H__
#define __SKALLAQUAD_H__
#include <assert.h>

typedef float (*FloatFunction)(float x);

float trapezoid(FloatFunction, float a, float b, float dx);

#endif
