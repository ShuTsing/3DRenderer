#include "BaseType.h"

namespace gra
{
	inline float Vector4D::Length(void)
	{
		//����sqrt(x^2 + y^2 + z^2 + w^2);
		float re = 0.f;
		for (auto i : arr)
			re += i * i;
		return std::sqrt(re);
	}

	inline Matrix4D Matrix4D::operator *= (const float& val)
	{
		//������ÿ��Ԫ�����γ�val
		for (auto& i : arr)
			for (auto& j : i)
				j *= val;
		return *this;
	}

	inline Matrix4D Matrix4D::operator += (const float& val)
	{
		//������ÿ��Ԫ�����μ�val
		for (auto& i : arr)
			for (auto& j : i)
				j += val;
		return *this;
	}

	inline Matrix4D Matrix4D::operator /= (const float& val)
	{
		//������ÿ��Ԫ�����γ���val
		for (auto& i : arr)
			for (auto& j : i)
				j /= val;
		return *this;
	}

	inline Matrix4D Matrix4D::operator -= (const float& val)
	{
		//������ÿ��Ԫ�����μ�val
		for (auto& i : arr)
			for (auto& j : i)
				j -= val;
		return *this;
	}

	inline Matrix4D Matrix4D::operator + (const float& val) const
	{
		Matrix4D re; //��������
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				re.At(i, j) = arr[i][j] + val;
		return re;
	}

	inline Matrix4D Matrix4D::operator - (const float& val) const
	{
		Matrix4D re; //��������
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				re.At(i, j) = arr[i][j] - val;
		return re;
	}

	inline Matrix4D Matrix4D::operator * (const float& val) const
	{
		Matrix4D re; //��������
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				re.At(i, j) = arr[i][j] * val;
		return re;
	}

	inline Matrix4D Matrix4D::operator / (const float& val) const
	{
		Matrix4D re; //��������
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				re.At(i, j) = arr[i][j] / val;
		return re;
	}
}