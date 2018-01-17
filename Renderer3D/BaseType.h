#pragma once

#include <cmath>

//������������
//�����;���

namespace gra
{
	//��ά����
	class Vector4D
	{
	public:

		float Length(void); //������������

		Vector4D operator + (const float& val) const; //�����Ӹ�����
		Vector4D operator - (const float& val) const; //������������
		Vector4D operator * (const float& val) const; //�����˸�����
		Vector4D operator / (const float& val) const; //�������Ը�����

		Vector4D operator + (const Vector4D& vec) const; //����������
		Vector4D operator - (const Vector4D& vec) const; //����������
		float operator * (const Vector4D& vec) const;    //�����������

		Vector4D operator += (const float& val); //��������Ӹ�����
		Vector4D operator -= (const float& val); //���������������
		Vector4D operator *= (const float& val); //��������˸�����
		Vector4D operator /= (const float& val); //����������Ը�����

		Vector4D operator += (const Vector4D& vec); //�������������
		Vector4D operator -= (const Vector4D& vec); //�������������


	private:
		float arr[4]; //��������
	};

	//4*4����
	class Matrix4D
	{
	public:

		float& At(int x, int y) //ͨ���±��ȡֵ��������Խ����
		{
			return arr[x][y];
		}

		Matrix4D operator *= (const float& val); //������˸�����
		Matrix4D operator += (const float& val); //������Ӹ�����
		Matrix4D operator /= (const float& val); //��������Ը�����
		Matrix4D operator -= (const float& val); //�������������

		Matrix4D operator + (const float& val) const; //����Ӹ�����
		Matrix4D operator - (const float& val) const; //�����������
		Matrix4D operator * (const float& val) const; //����˸�����
		Matrix4D operator / (const float& val) const; //������Ը�����

		Matrix4D operator + (const Matrix4D& val) const; //����Ӿ���
		Matrix4D operator - (const Matrix4D& val) const; //���������
		Matrix4D operator * (const Matrix4D& val) const; //����˾���


	private:

		float arr[4][4]; //���ݱ�������
	};

}