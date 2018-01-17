#pragma once

#include <cmath>

//基础数据类型
//向量和矩阵

namespace gra
{
	//四维向量
	class Vector4D
	{
	public:

		float Length(void); //返回向量长度

		Vector4D operator + (const float& val) const; //向量加浮点数
		Vector4D operator - (const float& val) const; //向量减浮点数
		Vector4D operator * (const float& val) const; //向量乘浮点数
		Vector4D operator / (const float& val) const; //向量除以浮点数

		Vector4D operator + (const Vector4D& vec) const; //向量加向量
		Vector4D operator - (const Vector4D& vec) const; //向量减向量
		float operator * (const Vector4D& vec) const;    //向量点乘向量

		Vector4D operator += (const float& val); //向量自身加浮点数
		Vector4D operator -= (const float& val); //向量自身减浮点数
		Vector4D operator *= (const float& val); //向量自身乘浮点数
		Vector4D operator /= (const float& val); //向量自身除以浮点数

		Vector4D operator += (const Vector4D& vec); //向量自身加向量
		Vector4D operator -= (const Vector4D& vec); //向量自身减向量


	private:
		float arr[4]; //保存数据
	};

	//4*4矩阵
	class Matrix4D
	{
	public:

		float& At(int x, int y) //通过下标获取值，不进行越界检查
		{
			return arr[x][y];
		}

		Matrix4D operator *= (const float& val); //矩阵本身乘浮点数
		Matrix4D operator += (const float& val); //矩阵本身加浮点数
		Matrix4D operator /= (const float& val); //矩阵本身除以浮点数
		Matrix4D operator -= (const float& val); //矩阵本身减浮点数

		Matrix4D operator + (const float& val) const; //矩阵加浮点数
		Matrix4D operator - (const float& val) const; //矩阵减浮点数
		Matrix4D operator * (const float& val) const; //矩阵乘浮点数
		Matrix4D operator / (const float& val) const; //矩阵除以浮点数

		Matrix4D operator + (const Matrix4D& val) const; //矩阵加矩阵
		Matrix4D operator - (const Matrix4D& val) const; //矩阵减矩阵
		Matrix4D operator * (const Matrix4D& val) const; //矩阵乘矩阵


	private:

		float arr[4][4]; //数据保存数组
	};

}