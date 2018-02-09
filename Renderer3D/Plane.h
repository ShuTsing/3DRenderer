#pragma once

#include "BaseType.h"
#include "Line.h"

namespace gra
{

#define NON_INTERSECT -1 //线段和平面不相交
#define ON_PLANE 0       //线段在平面上（处处相交）
#define IN_LINE 1        //线段和平面交点在线段内
#define OUT_LINE 2       //线段和平面交点在线段外

	//点-法线 平面
	class Plane
	{
	public:
		Plane(Point4D po, Vector4D normal, bool isNormalize = false)
			: point(po), vecNormal(normal), isNormalize(isNormalize) {}
		//法向量归一化
		void Normalize() { vecNormal.Normalize(); isNormalize = true; }
		bool IsNormalize() { return isNormalize; }  //返回法向量是否归一化
		//判断点是否在面的正空间，是返回整数，在负空间返回负数，在面上返回0
		float IsInPlane(Point4D& po);
		//判断直线和平面是否相交
		//不相交返回-1 (NON_INTERSECT)
		//线段在平面上返回0 (ON_PLANE)
		//交点在线段内返回1 (IN_LINE)
		//交点在线段外返回2 (OUT_LINE)
		int IsLineIntersect(Line line);
		//判断直线和平面是否相交,如果交点在线段上，参数t的值在[0, 1]内，交点为pt
		//不相交返回-1 (NON_INTERSECT)
		//线段在平面上返回0 (ON_PLANE)
		//交点在线段内返回1 (IN_LINE)
		//交点在线段外返回2 (OUT_LINE)
		int IsLineIntersect(Line line, float& t, Point4D& pt);
	private:
		Point4D point;      //平面上的点
		Vector4D vecNormal; //平面的法线向量
		bool isNormalize;   //法向量是否归一化
	};
}
