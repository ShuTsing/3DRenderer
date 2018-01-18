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

	inline float& Matrix4D::At(int x, int y)
	{
		return arr[x * 4 + y];
	}

	inline float& Matrix4D::At(int idx)
	{
		return arr[idx];
	}

	inline float& Matrix4D::operator [] (int idx)
	{
		return arr[idx];
	}

	inline Matrix4D Matrix4D::operator *= (const float& val)
	{
		//������ÿ��Ԫ�����γ�val
		//ʹ��C++ AMP ����GPU����
		array_view <float, 1> arrg(16, arr);
		arrg.discard_data();
		parallel_for_each
		(
			arrg.extent,
			[=](index <1> idx) restrict(amp)
			{
				arrg[idx] *= val;
			}
		);
		arrg.synchronize();
		return *this;
	}

	inline Matrix4D Matrix4D::operator += (const float& val)
	{
		//������ÿ��Ԫ�����μ�val
		array_view <float, 1> arrg(16, arr);
		arrg.discard_data();
		parallel_for_each
		(
			arrg.extent,
			[=](index <1> idx) restrict(amp)
			{
				arrg[idx] += val;
			}
		);
		arrg.synchronize();
		return *this;
	}

	inline Matrix4D Matrix4D::operator /= (const float& val)
	{
		//������ÿ��Ԫ�����γ���val
		array_view <float, 1> arrg(16, arr);
		arrg.discard_data();
		parallel_for_each
		(
			arrg.extent,
			[=](index <1> idx) restrict(amp)
			{
				arrg[idx] /= val;
			}
		);
		arrg.synchronize();
		return *this;
	}

	inline Matrix4D Matrix4D::operator -= (const float& val)
	{
		//������ÿ��Ԫ�����μ�val
		array_view <float, 1> arrg(16, arr);
		arrg.discard_data();
		parallel_for_each
		(
			arrg.extent,
			[=](index <1> idx) restrict(amp)
			{
				arrg[idx] -= val;
			}
		);
		arrg.synchronize();
		return *this;
	}

	inline Matrix4D Matrix4D::operator + (const float& val) const
	{
		Matrix4D re; //��������
		array_view <const float, 1> arrg(16, arr);
		array_view <float, 1> reg(16, re.arr);
		reg.discard_data();
		parallel_for_each
		(
			reg.extent,
			[=] (index <1> idx) restrict(amp)
			{
				reg[idx] = arrg[idx] + val;
			}
		);
		reg.synchronize();
		return re;
	}

	inline Matrix4D Matrix4D::operator - (const float& val) const
	{
		Matrix4D re; //��������

		return re;
	}

	inline Matrix4D Matrix4D::operator * (const float& val) const
	{
		Matrix4D re; //��������

		return re;
	}

	inline Matrix4D Matrix4D::operator / (const float& val) const
	{
		Matrix4D re; //��������

		return re;
	}
}