#pragma once
#include "BaseType.h"


//��ѧ��
//�����;����������躯��
namespace gra
{
	Vector4D Interpolate(Vector4D vec1, Vector4D vec2, float t); //����������ֵ
	void Normalize(Vector4D& vec);                               //������׼������һ������������
}