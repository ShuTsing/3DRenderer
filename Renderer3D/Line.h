#pragma once

#include "BaseType.h"

namespace gra
{
	class Line; //参数化直线

	class Line
	{
	public:
		Line(Point4D beginPoint, Point4D endPoint, Vector4D dirVector)
			: pointBegin(beginPoint), pointEnd(endPoint), vecDirection(dirVector) {}
		Vector4D GetVecDirect() { return vecDirection; }
		Point4D GetBeginPoint() { return pointBegin; }
	private:
		Point4D pointBegin;    //参数化直线起点
		Point4D pointEnd;      //参数化直线终点
		Vector4D vecDirection; //线段方向向量
	};
}