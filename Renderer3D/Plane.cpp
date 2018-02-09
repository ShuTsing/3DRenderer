#include "Plane.h"

namespace gra
{
	float Plane::IsInPlane(Point4D& po)
	{
		float re = 0.0f; //���ظ�����
		re += vecNormal.x()*(po.x() - point.x());
		re += vecNormal.y()*(po.y() - point.y());
		re += vecNormal.z()*(po.z() - point.z());
		return re;
	}

	int Plane::IsLineIntersect(Line line)
	{
		float t;
		Point4D pt;
		return IsLineIntersect(line, t, pt);
	}

	int Plane::IsLineIntersect(Line line, float& t, Point4D& pt)
	{
		float dot = line.GetVecDirect() * vecNormal; //����������ƽ�淨�������
		if (Fabs(dot) <= EPSILON) //�߶κ�ƽ���Ƿ�ƽ��
			if (IsInPlane(line.GetBeginPoint()) <= EPSILON) //�߶��Ƿ���ƽ����
				return ON_PLANE;
			else
				return NON_INTERSECT;
		//����tֵ
		t = vecNormal.x() * line.GetBeginPoint().x();
		t += vecNormal.y() * line.GetBeginPoint().y();
		t += vecNormal.z() * line.GetBeginPoint().z();
		t -= vecNormal.x() * point.x();
		t -= vecNormal.y() * point.y();
		t -= vecNormal.z() * point.z();
		t /= -dot;
		//����ptֵ
		pt.x() = line.GetBeginPoint().x() + line.GetVecDirect().x() * t;
		pt.y() = line.GetBeginPoint().y() + line.GetVecDirect().y() * t;
		pt.z() = line.GetBeginPoint().z() + line.GetVecDirect().z() * t;
		pt.w() = POINT;

		if (t >= 0.0f&&t <= 1.0f) //�����Ƿ����߶���
			return IN_LINE;
		else
			return OUT_LINE;

		return 0;
	}
}