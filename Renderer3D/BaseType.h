#pragma once

#include <cmath>
#include <cstring>
#include <amp.h> //GPU����

#include "BaseDefine.h"


using concurrency::array_view;
using concurrency::parallel_for_each;
using concurrency::index;

//������������
//�����;���

namespace gra
{
#define VECTOR 0
#define POINT 1

	class Vector4D;
	class Matrix4D;

	using Point4D = Vector4D; //������һ������������

	//��ά����
	//�ĸ�ά�ȷֱ�Ϊx, y, z, w������w=1��ʾΪ�㣬w=0��ʾΪ����
	class Vector4D
	{
	public:

		//���캯��
		Vector4D(): size(3) { memset(arr, 0, sizeof(arr)); }
		Vector4D(float(&f)[4]): size(3) {for (int i = 0; i < 4; i++) arr[i] = f[i];}
		Vector4D(float x, float y, float z, float w): size(3)
		{
			arr[0] = x;
			arr[1] = y;
			arr[2] = z;
			arr[3] = w;
		}

		float& x() { return arr[0]; }                     //����x����
		float& y() { return arr[1]; }                     //����y����
		float& z() { return arr[2]; }                     //����z����
		float& w() { return arr[3]; }                     //����w����

		float Length(void);                               //������������

		void Normalize();                                 //������׼����������


		Vector4D operator + (const float& val) const;     //�����Ӹ�����
		Vector4D operator - (const float& val) const;     //������������
		Vector4D operator * (const float& val) const;     //�����˸�����
		Vector4D operator / (const float& val) const;     //�������Ը�����

		Vector4D operator + (const Vector4D& vec) const;  //����������
		Vector4D operator - (const Vector4D& vec) const;  //����������
		float operator * (const Vector4D& vec) const;     //�����������

		Vector4D& operator += (const float& val);         //��������Ӹ�����
		Vector4D& operator -= (const float& val);         //���������������
		Vector4D& operator *= (const float& val);         //��������˸�����
		Vector4D& operator /= (const float& val);         //����������Ը�����

		Vector4D& operator += (const Vector4D& vec);      //�������������
		Vector4D& operator -= (const Vector4D& vec);      //�������������

		Vector4D Cross(const Vector4D& vec) const;        //�����������

	private:
		float arr[4]; //��������
		int size;
	};

	//4*4����
	class Matrix4D
	{
	public:

		Matrix4D(): size(16) { memset(arr, 0, sizeof(arr)); }

		Matrix4D(const float (&initArray)[16]) : size(16)
		{
			for (int i = 0; i < 16; i++)
				arr[i] = initArray[i];
		}

		float& At(const int& x, const int& y) {return arr[x * 4 + y];} //ͨ����ά�±��ȡֵ��������Խ����
		float& At(const int& idx) {return arr[idx];}                   //ͨ��һά�±��ȡֵ��������Խ����

		float& operator [] (const int& idx) {return arr[idx];}         //ͨ��һά�±��ȡֵ��������Խ����

		void SetTranslate(float x, float y, float z);           //����ƽ�Ʊ任
		void SetScale(float x, float y, float z);               //��������任
		void SetRotate(float x, float y, float z, float theta); //������ת�任

		Matrix4D& operator *= (const float& val);         //������˸�����
		Matrix4D& operator += (const float& val);         //������Ӹ�����
		Matrix4D& operator /= (const float& val);         //��������Ը�����
		Matrix4D& operator -= (const float& val);         //�������������

		Matrix4D operator + (const float& val) const;     //����Ӹ�����
		Matrix4D operator - (const float& val) const;     //�����������
		Matrix4D operator * (const float& val) const;     //����˸�����
		Matrix4D operator / (const float& val) const;     //������Ը�����

		Matrix4D& operator += (const Matrix4D& mat);      //��������Ӿ���
		Matrix4D& operator -= (const Matrix4D& mat);      //�����������

		Matrix4D operator + (const Matrix4D& mat) const;  //����Ӿ���
		Matrix4D operator - (const Matrix4D& mat) const;  //���������
		Matrix4D operator * (const Matrix4D& mat) const;  //����˾���

	private:

		float arr[16];    //���ݱ�������

		int size;
		//friend Matrix4D;  //GPU������Ҫ��������
	};

	//��λ����
	const Matrix4D identityMatrix = Matrix4D({
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f,
		});
}