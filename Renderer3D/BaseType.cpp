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







	Matrix4D Matrix4D::operator *= (const float& val)
	{
		//将数组每个元素依次乘val
		//使用C++ AMP 进行GPU加速
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

	Matrix4D Matrix4D::operator += (const float& val)
	{
		//将数组每个元素依次加val
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

	Matrix4D Matrix4D::operator /= (const float& val)
	{
		//将数组每个元素依次除以val
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

	Matrix4D Matrix4D::operator -= (const float& val)
	{
		//将数组每个元素依次减val
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

	Matrix4D Matrix4D::operator + (const float& val) const
	{
		Matrix4D re; //返回数据
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

	Matrix4D Matrix4D::operator - (const float& val) const
	{
		Matrix4D re; //返回数据
		array_view <const float, 1> arrg(16, arr);
		array_view <float, 1> reg(16, re.arr);
		reg.discard_data();
		parallel_for_each
		(
			reg.extent,
			[=](index <1> idx) restrict(amp)
			{
				reg[idx] = arrg[idx] - val;
			}
		);
		reg.synchronize();
		return re;
	}

	Matrix4D Matrix4D::operator * (const float& val) const
	{
		Matrix4D re; //返回数据
		array_view <const float, 1> arrg(16, arr);
		array_view <float, 1> reg(16, re.arr);
		reg.discard_data();
		parallel_for_each
		(
			reg.extent,
			[=](index <1> idx) restrict(amp)
			{
				reg[idx] = arrg[idx] * val;
			}
		);
		reg.synchronize();
		return re;
	}

	Matrix4D Matrix4D::operator / (const float& val) const
	{
		Matrix4D re; //返回数据
		array_view <const float, 1> arrg(16, arr);
		array_view <float, 1> reg(16, re.arr);
		reg.discard_data();
		parallel_for_each
		(
			reg.extent,
			[=](index <1> idx) restrict(amp)
			{
				reg[idx] = arrg[idx] / val;
			}
		);
		reg.synchronize();
		return re;
	}

	Matrix4D Matrix4D::operator += (const Matrix4D& mat)
	{
		array_view <const float, 1> matg(16, mat.arr);
		array_view <float, 1> arrg(16, arr);
		arrg.discard_data();
		parallel_for_each
		(
			arrg.extent,
			[=](index <1> idx) restrict(amp)
			{
				arrg[idx] += matg[idx];
			}
		);
		arrg.synchronize();
		return *this;
	}

	Matrix4D Matrix4D::operator -= (const Matrix4D& mat)
	{
		array_view <const float, 1> matg(16, mat.arr);
		array_view <float, 1> arrg(16, arr);
		arrg.discard_data();
		parallel_for_each
		(
			arrg.extent,
			[=](index <1> idx) restrict(amp)
			{
				arrg[idx] -= matg[idx];
			}
		);
		arrg.synchronize();
		return *this;
	}

	Matrix4D Matrix4D::operator + (const Matrix4D& mat) const
	{
		Matrix4D re; //返回用数据
		array_view <const float, 1> matg(16, mat.arr);
		array_view <const float, 1> arrg(16, arr);
		array_view <float, 1> reg(16, re.arr);
		reg.discard_data();
		parallel_for_each
		(
			reg.extent,
			[=](index <1> idx) restrict(amp)
			{
				reg[idx] = matg[idx] + arrg[idx];
			}
		);
		reg.synchronize();
		return re;
	}

	Matrix4D Matrix4D::operator - (const Matrix4D& mat) const
	{
		Matrix4D re; //返回用数据
		array_view <const float, 1> matg(16, mat.arr);
		array_view <const float, 1> arrg(16, arr);
		array_view <float, 1> reg(16, re.arr);
		reg.discard_data();
		parallel_for_each
		(
			reg.extent,
			[=](index <1> idx) restrict(amp)
			{
				reg[idx] = matg[idx] - arrg[idx];
			}
		);
		reg.synchronize();
		return re;
	}

	//时间复杂度O(n^3)的朴素矩阵乘法
	//XXX: 优化算法，降低时间复杂度
	Matrix4D Matrix4D::operator * (const Matrix4D& mat) const
	{
		Matrix4D re; //返回用数据
		array_view <const float, 2> matg(4, 4, mat.arr);
		array_view <const float, 2> arrg(4, 4, arr);
		array_view <float, 2> reg(4, 4, re.arr);
		reg.discard_data();
		parallel_for_each
		(
			reg.extent,
			[=](index <2> idx) restrict(amp)
			{
				const unsigned int row = idx[0];
				const unsigned int col = idx[1];
				float r = 0.f;
				for (auto i = 0; i < 4; i++)
					r += arrg[row][i] + matg[i][col];
				reg[idx] = r;
			}
		);
		reg.synchronize();
		return re;
	}
}