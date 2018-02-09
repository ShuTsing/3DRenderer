#pragma once

#include "BaseType.h"
#include "Line.h"

namespace gra
{

#define NON_INTERSECT -1 //�߶κ�ƽ�治�ཻ
#define ON_PLANE 0       //�߶���ƽ���ϣ������ཻ��
#define IN_LINE 1        //�߶κ�ƽ�潻�����߶���
#define OUT_LINE 2       //�߶κ�ƽ�潻�����߶���

	//��-���� ƽ��
	class Plane
	{
	public:
		Plane(Point4D po, Vector4D normal, bool isNormalize = false)
			: point(po), vecNormal(normal), isNormalize(isNormalize) {}
		//��������һ��
		void Normalize() { vecNormal.Normalize(); isNormalize = true; }
		bool IsNormalize() { return isNormalize; }  //���ط������Ƿ��һ��
		//�жϵ��Ƿ���������ռ䣬�Ƿ����������ڸ��ռ䷵�ظ����������Ϸ���0
		float IsInPlane(Point4D& po);
		//�ж�ֱ�ߺ�ƽ���Ƿ��ཻ
		//���ཻ����-1 (NON_INTERSECT)
		//�߶���ƽ���Ϸ���0 (ON_PLANE)
		//�������߶��ڷ���1 (IN_LINE)
		//�������߶��ⷵ��2 (OUT_LINE)
		int IsLineIntersect(Line line);
		//�ж�ֱ�ߺ�ƽ���Ƿ��ཻ,����������߶��ϣ�����t��ֵ��[0, 1]�ڣ�����Ϊpt
		//���ཻ����-1 (NON_INTERSECT)
		//�߶���ƽ���Ϸ���0 (ON_PLANE)
		//�������߶��ڷ���1 (IN_LINE)
		//�������߶��ⷵ��2 (OUT_LINE)
		int IsLineIntersect(Line line, float& t, Point4D& pt);
	private:
		Point4D point;      //ƽ���ϵĵ�
		Vector4D vecNormal; //ƽ��ķ�������
		bool isNormalize;   //�������Ƿ��һ��
	};
}
