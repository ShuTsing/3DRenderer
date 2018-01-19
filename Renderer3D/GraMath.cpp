#include "GraMath.h"

namespace gra
{
	//q(t) = sin(theta * (1-t)) / sin(theta) * q1 + sin(theta * t) / sin(theta) * q2
	//theta = cos^(-1) * (q1 * q2)
	//sin(theta)可以为 sqrt(1 - (q1 * q2)^2)
	//应保证q1 * q2 >= 0
	Vector4D SpherInterpolate(Vector4D vec1, Vector4D vec2, float t)
	{}
}