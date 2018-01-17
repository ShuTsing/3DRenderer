#pragma once
//基础数据类型
//向量和矩阵

namespace gra
{
	//四维向量
	class Vector4D
	{
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

		Matrix4D operator *= (const float val); //矩阵本身乘浮点数
		Matrix4D operator += (const float val); //矩阵本身加浮点数
		Matrix4D operator /= (const float val); //矩阵本身除以浮点数
		Matrix4D operator -= (const float val); //矩阵本身减浮点数

		Matrix4D operator + (const float val) const; //矩阵加浮点数
		Matrix4D operator - (const float val) const; //矩阵减浮点数
		Matrix4D operator * (const float val) const; //矩阵乘浮点数
		Matrix4D operator / (const float val) const; //矩阵除以浮点数


	private:

		float arr[4][4]; //数据保存数组
	};

	inline Matrix4D Matrix4D::operator *= (const float val)
	{
		//将数组每个元素依次乘val
		for (auto& i : arr)
			for (auto& j : i)
				j *= val;
		return *this;
	}

	inline Matrix4D Matrix4D::operator += (const float val)
	{
		//将数组每个元素依次加val
		for (auto& i : arr)
			for (auto& j : i)
				j += val;
		return *this;
	}

	inline Matrix4D Matrix4D::operator /= (const float val)
	{
		//将数组每个元素依次除以val
		for (auto& i : arr)
			for (auto& j : i)
				j /= val;
		return *this;
	}

	inline Matrix4D Matrix4D::operator -= (const float val)
	{
		//将数组每个元素依次减val
		for (auto& i : arr)
			for (auto& j : i)
				j -= val;
		return *this;
	}

	inline Matrix4D Matrix4D::operator + (const float val) const
	{
		Matrix4D re; //返回数据
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				re.At(i, j) = arr[i][j] + val;
		return re;
	}

	inline Matrix4D Matrix4D::operator - (const float val) const
	{
		Matrix4D re; //返回数据
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				re.At(i, j) = arr[i][j] - val;
		return re;
	}

	inline Matrix4D Matrix4D::operator * (const float val) const
	{
		Matrix4D re; //返回数据
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				re.At(i, j) = arr[i][j] * val;
		return re;
	}

	inline Matrix4D Matrix4D::operator / (const float val) const
	{
		Matrix4D re; //返回数据
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				re.At(i, j) = arr[i][j] / val;
		return re;
	}
}