#pragma once

#include "BaseType.h"

namespace gra
{
	class Line; //������ֱ��

	class Line
	{
	public:
		Line(Point4D beginPoint, Point4D endPoint, Vector4D dirVector)
			: pointBegin(beginPoint), pointEnd(endPoint), vecDirection(dirVector) {}
		Vector4D GetVecDirect() { return vecDirection; }
		Point4D GetBeginPoint() { return pointBegin; }
	private:
		Point4D pointBegin;    //������ֱ�����
		Point4D pointEnd;      //������ֱ���յ�
		Vector4D vecDirection; //�߶η�������
	};
}