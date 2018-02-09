#pragma once



namespace gra
{

#define EPSILON 1e-5f

	inline float Fabs(float val) { return val > 0.0f ? val : -val; }
	inline float Fmax(float x, float y) { return x > y ? x : y; }
	inline float Fmin(float x, float y) { return x < y ? x : y; }
}
