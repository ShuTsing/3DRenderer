#pragma once

#include <cmath>
#include <cstring>
#include <amp.h> //GPU加速

#include "BaseDefine.h"


using concurrency::array_view;
using concurrency::parallel_for_each;
using concurrency::index;

//基础数据类型
//向量和矩阵

namespace gra
{
#define VECTOR 0
#define POINT 1

	class Vector4D;
	class Matrix4D;

	using Point4D = Vector4D; //本质上一样，方便区分

	//四维向量
	//四个维度分别为x, y, z, w，其中w=1表示为点，w=0表示为向量
	class Vector4D
	{
	public:

		//构造函数
		Vector4D(): size(3) { memset(arr, 0, sizeof(arr)); }
		Vector4D(float(&f)[4]): size(3) {for (int i = 0; i < 4; i++) arr[i] = f[i];}
		Vector4D(float x, float y, float z, float w): size(3)
		{
			arr[0] = x;
			arr[1] = y;
			arr[2] = z;
			arr[3] = w;
		}

		float& x() { return arr[0]; }                     //返回x分量
		float& y() { return arr[1]; }                     //返回y分量
		float& z() { return arr[2]; }                     //返回z分量
		float& w() { return arr[3]; }                     //返回w分量

		float Length(void);                               //返回向量长度

		void Normalize();                                 //向量标准化，不可逆


		Vector4D operator + (const float& val) const;     //向量加浮点数
		Vector4D operator - (const float& val) const;     //向量减浮点数
		Vector4D operator * (const float& val) const;     //向量乘浮点数
		Vector4D operator / (const float& val) const;     //向量除以浮点数

		Vector4D operator + (const Vector4D& vec) const;  //向量加向量
		Vector4D operator - (const Vector4D& vec) const;  //向量减向量
		float operator * (const Vector4D& vec) const;     //向量点乘向量

		Vector4D& operator += (const float& val);         //向量自身加浮点数
		Vector4D& operator -= (const float& val);         //向量自身减浮点数
		Vector4D& operator *= (const float& val);         //向量自身乘浮点数
		Vector4D& operator /= (const float& val);         //向量自身除以浮点数

		Vector4D& operator += (const Vector4D& vec);      //向量自身加向量
		Vector4D& operator -= (const Vector4D& vec);      //向量自身减向量

		Vector4D Cross(const Vector4D& vec) const;        //向量叉乘向量

	private:
		float arr[4]; //保存数据
		int size;
	};

	//4*4矩阵
	class Matrix4D
	{
	public:

		Matrix4D(): size(16) { memset(arr, 0, sizeof(arr)); }

		Matrix4D(const float (&initArray)[16]) : size(16)
		{
			for (int i = 0; i < 16; i++)
				arr[i] = initArray[i];
		}

		float& At(const int& x, const int& y) {return arr[x * 4 + y];} //通过二维下标获取值，不进行越界检查
		float& At(const int& idx) {return arr[idx];}                   //通过一维下标获取值，不进行越界检查

		float& operator [] (const int& idx) {return arr[idx];}         //通过一维下标获取值，不进行越界检查

		void SetTranslate(float x, float y, float z);           //矩阵平移变换
		void SetScale(float x, float y, float z);               //矩阵放缩变换
		void SetRotate(float x, float y, float z, float theta); //矩阵旋转变换

		Matrix4D& operator *= (const float& val);         //矩阵本身乘浮点数
		Matrix4D& operator += (const float& val);         //矩阵本身加浮点数
		Matrix4D& operator /= (const float& val);         //矩阵本身除以浮点数
		Matrix4D& operator -= (const float& val);         //矩阵本身减浮点数

		Matrix4D operator + (const float& val) const;     //矩阵加浮点数
		Matrix4D operator - (const float& val) const;     //矩阵减浮点数
		Matrix4D operator * (const float& val) const;     //矩阵乘浮点数
		Matrix4D operator / (const float& val) const;     //矩阵除以浮点数

		Matrix4D& operator += (const Matrix4D& mat);      //矩阵自身加矩阵
		Matrix4D& operator -= (const Matrix4D& mat);      //矩阵本身减矩阵

		Matrix4D operator + (const Matrix4D& mat) const;  //矩阵加矩阵
		Matrix4D operator - (const Matrix4D& mat) const;  //矩阵减矩阵
		Matrix4D operator * (const Matrix4D& mat) const;  //矩阵乘矩阵

	private:

		float arr[16];    //数据保存数组

		int size;
		//friend Matrix4D;  //GPU加速需要调用数组
	};

	//单位矩阵
	const Matrix4D identityMatrix = Matrix4D({
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f,
		});
}