#pragma once

#include "BaseType.h"

namespace gra
{
	class Line; //������ֱ��

	class Line
	{
		Line(Point4D beginPoint, Point4D endPoint, Vector4D dirVector)
			: pointBegin(beginPoint), pointEnd(endPoint), vecDirection(dirVector) {}
		Point4D pointBegin;    //������ֱ�����
		Point4D pointEnd;      //������ֱ���յ�
		Vector4D vecDirection; //�߶η�������
	};
}