#include "BaseType.h"

namespace gra
{
	//返回sqrt(x^2 + y^2 + z^2 + w^2);
	//XXX: 优化开方算法
	float Vector4D::Length(void)
	{
		float re = 0.f;
		for (auto i : arr)
			re += i * i;
		return std::sqrt(re);
	}

	/*向量四则运算部分*/
	/*向量和常数运算则各分量与常量运算*/
	/*向量和向量运算则向量的各分量分别进行运算*/

	//向量加常数
	Vector4D Vector4D::operator + (const float& val) const
	{
		Vector4D re; //用于返回
		for (int i = 0; i < size; i++)
			re.arr[i] = arr[i] + val;
		re.arr[3] = arr[3];
		return re;
	}

	Vector4D Vector4D::operator - (const float& val) const
	{
		Vector4D re;
		for (int i = 0; i < size; i++)
			re.arr[i] = arr[i] - val;
		re.arr[3] = arr[3];
		return re;
	}

	Vector4D Vector4D::operator * (const float& val) const
	{
		Vector4D re;
		for (int i = 0; i < size; i++)
			re.arr[i] = arr[i] * val;
		re.arr[3] = arr[3];
		return re;
	}

	Vector4D Vector4D::operator / (const float& val) const
	{
		Vector4D re;
		for (int i = 0; i < size; i++)
			re.arr[i] = arr[i] / val;
		re.arr[3] = arr[3];
		return re;
	}

	//向量加向量
	Vector4D Vector4D::operator + (const Vector4D& vec) const
	{
		Vector4D re; //用于返回
		for (int i = 0; i < size; i++)
			re.arr[i] = arr[i] + vec.arr[i];
		re.arr[3] = arr[3];
		return re;
	}

	Vector4D Vector4D::operator - (const Vector4D& vec) const
	{
		Vector4D re;
		for (int i = 0; i < size; i++)
			re.arr[i] = arr[i] - vec.arr[i];
		re.arr[3] = arr[3];
		return re;
	}

	float Vector4D::operator * (const Vector4D& vec) const
	{
		float re=0.0f;
		for (int i = 0; i < size; i++)
			re += arr[i] * vec.arr[i];
		return re;
	}

	Vector4D& Vector4D::operator += (const float& val)
	{
		for (int i = 0; i < size; i++)
			arr[i] += val;
		return *this;
	}

	Vector4D& Vector4D::operator -= (const float& val)
	{
		for (int i = 0; i < size; i++)
			arr[i] -= val;
		return *this;
	}

	Vector4D& Vector4D::operator *= (const float& val)
	{
		for (int i = 0; i < size; i++)
			arr[i] *= val;
		return *this;
	}

	Vector4D& Vector4D::operator /= (const float& val)
	{
		for (int i = 0; i < size; i++)
			arr[i] /= val;
		return *this;
	}

	Vector4D& Vector4D::operator += (const Vector4D& vec)
	{
		for (int i = 0; i < size; i++)
			arr[i] += vec.arr[i];
		return *this;
	}

	Vector4D& Vector4D::operator -= (const Vector4D& vec)
	{
		for (int i = 0; i < size; i++)
			arr[i] -= vec.arr[i];
		return *this;
	}

	//向量叉乘，返回外积
	Vector4D Vector4D::Cross(const Vector4D& vec) const
	{
		Vector4D re;
		re.arr[0] = arr[1] * vec.arr[2] - arr[2] * vec.arr[1];
		re.arr[1] = arr[2] * vec.arr[0] - arr[0] * vec.arr[2];
		re.arr[2] = arr[0] * vec.arr[1] - arr[1] * vec.arr[0];
		re.arr[3] = arr[3];
		return re;
	}

	//向量归一化（标准化），向量各分量相加之和为1
	void Vector4D::Normalize(void)
	{
		float len = Length();
		for (int i = 0; i < size; i++)
			arr[i] /= len;
		return;
	}






	Matrix4D& Matrix4D::operator *= (const float& val)
	{
		//将数组每个元素依次乘val
		for (float& i : arr)
			i *= val;
		return *this;
	}

	Matrix4D& Matrix4D::operator += (const float& val)
	{
		//将数组每个元素依次加val
		for (float& i : arr)
			i += val;
		return *this;
	}

	Matrix4D& Matrix4D::operator /= (const float& val)
	{
		//将数组每个元素依次除以val
		for (float& i : arr)
			i /= val;
		return *this;
	}

	Matrix4D& Matrix4D::operator -= (const float& val)
	{
		//将数组每个元素依次减val
		for (float& i : arr)
			i -= val;
		return *this;
	}

	Matrix4D Matrix4D::operator + (const float& val) const
	{
		Matrix4D re; //返回数据
		for (int i = 0; i < size; i++)
			re.arr[i] = arr[i] + val;
		return re;
	}

	Matrix4D Matrix4D::operator - (const float& val) const
	{
		Matrix4D re; //返回数据
		for (int i = 0; i < size; i++)
			re.arr[i] = arr[i] - val;
		return re;
	}

	Matrix4D Matrix4D::operator * (const float& val) const
	{
		Matrix4D re; //返回数据
		for (int i = 0; i < size; i++)
			re.arr[i] = arr[i] * val;
		return re;
	}

	Matrix4D Matrix4D::operator / (const float& val) const
	{
		Matrix4D re; //返回数据
		for (int i = 0; i < size; i++)
			re.arr[i] = arr[i] / val;
		return re;
	}

	Matrix4D& Matrix4D::operator += (const Matrix4D& mat)
	{
		for (int i = 0; i < size; i++)
			arr[i] += mat.arr[i];
		return *this;
	}

	Matrix4D& Matrix4D::operator -= (const Matrix4D& mat)
	{
		for (int i = 0; i < size; i++)
			arr[i] -= mat.arr[i];
		return *this;
	}

	Matrix4D Matrix4D::operator + (const Matrix4D& mat) const
	{
		Matrix4D re; //返回用数据
		for (int i = 0; i < size; i++)
			re[i] = arr[i] + mat.arr[i];
		return re;
	}

	Matrix4D Matrix4D::operator - (const Matrix4D& mat) const
	{
		Matrix4D re; //返回用数据
		for (int i = 0; i < size; i++)
			re[i] = arr[i] - mat.arr[i];
		return re;
	}

	//时间复杂度O(n^3)的朴素矩阵乘法
	//XXX: 优化算法，降低时间复杂度
	Matrix4D Matrix4D::operator * (const Matrix4D& mat) const
	{
		Matrix4D re; //返回用数据
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				for (int k = 0; k < 4; k++)
					re.At(i, j) = arr[i * 4 + k] * mat.arr[k * 4 + j];
		return re;
	}
}