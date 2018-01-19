#pragma once

#include <cmath>
#include <amp.h> //GPU����


using concurrency::array_view;
using concurrency::parallel_for_each;
using concurrency::index;

//������������
//�����;���

namespace gra
{
	class Vector4D;
	class Matrix4D;

	using Point4D = Vector4D; //������һ������������

	//��ά����
	//�ĸ�ά�ȷֱ�Ϊx, y, z, w������w=1��ʾΪ�㣬w=0��ʾΪ����
	class Vector4D
	{
	public:

		//���캯��
		Vector4D() {for (auto& i : arr) i = 0.f;}
		Vector4D(float(&f)[4]) {for (int i = 0; i < 4; i++) arr[i] = f[i];}
		Vector4D(float x, float y, float z, float w)
		{
			arr[0] = x;
			arr[1] = y;
			arr[2] = z;
			arr[3] = w;
		}

		float Length(void);                              //������������

		void Normalize();                                //������׼����������


		Vector4D operator + (const float& val) const;    //�����Ӹ�����
		Vector4D operator - (const float& val) const;    //������������
		Vector4D operator * (const float& val) const;    //�����˸�����
		Vector4D operator / (const float& val) const;    //�������Ը�����

		Vector4D operator + (const Vector4D& vec) const; //����������
		Vector4D operator - (const Vector4D& vec) const; //����������
		float operator * (const Vector4D& vec) const;    //�����������

		Vector4D operator += (const float& val);         //��������Ӹ�����
		Vector4D operator -= (const float& val);         //���������������
		Vector4D operator *= (const float& val);         //��������˸�����
		Vector4D operator /= (const float& val);         //����������Ը�����

		Vector4D operator += (const Vector4D& vec);      //�������������
		Vector4D operator -= (const Vector4D& vec);      //�������������

		Vector4D Cross(const Vector4D& vec) const;       //�����������

	private:
		float arr[4]; //��������
	};

	//4*4����
	class Matrix4D
	{
	public:

		float& At(int x, int y) {return arr[x * 4 + y];} //ͨ����ά�±��ȡֵ��������Խ����
		float& At(int idx) {return arr[idx];}            //ͨ��һά�±��ȡֵ��������Խ����

		float& operator [] (int idx) {return arr[idx];}  //ͨ��һά�±��ȡֵ��������Խ����

		void SetTranslate(float x, float y, float z);           //����ƽ�Ʊ任
		void SetScale(float x, float y, float z);               //��������任
		void SetRotate(float x, float y, float z, float theta); //������ת�任

		Matrix4D operator *= (const float& val);         //������˸�����
		Matrix4D operator += (const float& val);         //������Ӹ�����
		Matrix4D operator /= (const float& val);         //��������Ը�����
		Matrix4D operator -= (const float& val);         //�������������

		Matrix4D operator + (const float& val) const;    //����Ӹ�����
		Matrix4D operator - (const float& val) const;    //�����������
		Matrix4D operator * (const float& val) const;    //����˸�����
		Matrix4D operator / (const float& val) const;    //������Ը�����

		Matrix4D operator += (const Matrix4D& mat);      //��������Ӿ���
		Matrix4D operator -= (const Matrix4D& mat);      //�����������

		Matrix4D operator + (const Matrix4D& mat) const; //����Ӿ���
		Matrix4D operator - (const Matrix4D& mat) const; //���������
		Matrix4D operator * (const Matrix4D& mat) const; //����˾���

	private:

		float arr[16];    //���ݱ�������

		friend Matrix4D;  //GPU������Ҫ��������
	};

}