#pragma once

#include "BaseType.h"

namespace gra
{
	//点 - 法线 平面
	class Plane
	{
		Point4D point;      //平面上的点
		Vector4D vecNormal; //平面的法线向量
	};
}
