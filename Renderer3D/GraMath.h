#pragma once
#include "BaseType.h"


//��ѧ��
//�����;����������躯��
namespace gra
{
	Vector4D SpherInterpolate(Vector4D vec1, Vector4D vec2, float t);  //���������������Բ�ֵ
	Vector4D LinearInterpolate(Vector4D vec1, Vector4D vec2, float t); //�����������Բ�ֵ
	void Normalize(Vector4D& vec);                                     //������׼������һ������������
}