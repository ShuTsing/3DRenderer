#include "BaseType.h"

namespace gra
{
	//����sqrt(x^2 + y^2 + z^2 + w^2);
	//XXX: �Ż������㷨
	float Vector4D::Length(void)
	{
		float re = 0.f;
		for (auto i : arr)
			re += i * i;
		return std::sqrt(re);
	}

	/*�����������㲿��*/
	/*�����ͳ���������������볣������*/
	/*���������������������ĸ������ֱ��������*/

	//�����ӳ���
	Vector4D Vector4D::operator + (const float& val) const
	{
		Vector4D re; //���ڷ���
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

	//����������
	Vector4D Vector4D::operator + (const Vector4D& vec) const
	{
		Vector4D re; //���ڷ���
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

	//������ˣ��������
	Vector4D Vector4D::Cross(const Vector4D& vec) const
	{
		Vector4D re;
		re.arr[0] = arr[1] * vec.arr[2] - arr[2] * vec.arr[1];
		re.arr[1] = arr[2] * vec.arr[0] - arr[0] * vec.arr[2];
		re.arr[2] = arr[0] * vec.arr[1] - arr[1] * vec.arr[0];
		re.arr[3] = arr[3];
		return re;
	}

	//������һ������׼�������������������֮��Ϊ1
	void Vector4D::Normalize(void)
	{
		float len = Length();
		for (int i = 0; i < size; i++)
			arr[i] /= len;
		return;
	}






	Matrix4D& Matrix4D::operator *= (const float& val)
	{
		//������ÿ��Ԫ�����γ�val
		for (float& i : arr)
			i *= val;
		return *this;
	}

	Matrix4D& Matrix4D::operator += (const float& val)
	{
		//������ÿ��Ԫ�����μ�val
		for (float& i : arr)
			i += val;
		return *this;
	}

	Matrix4D& Matrix4D::operator /= (const float& val)
	{
		//������ÿ��Ԫ�����γ���val
		for (float& i : arr)
			i /= val;
		return *this;
	}

	Matrix4D& Matrix4D::operator -= (const float& val)
	{
		//������ÿ��Ԫ�����μ�val
		for (float& i : arr)
			i -= val;
		return *this;
	}

	Matrix4D Matrix4D::operator + (const float& val) const
	{
		Matrix4D re; //��������
		for (int i = 0; i < size; i++)
			re.arr[i] = arr[i] + val;
		return re;
	}

	Matrix4D Matrix4D::operator - (const float& val) const
	{
		Matrix4D re; //��������
		for (int i = 0; i < size; i++)
			re.arr[i] = arr[i] - val;
		return re;
	}

	Matrix4D Matrix4D::operator * (const float& val) const
	{
		Matrix4D re; //��������
		for (int i = 0; i < size; i++)
			re.arr[i] = arr[i] * val;
		return re;
	}

	Matrix4D Matrix4D::operator / (const float& val) const
	{
		Matrix4D re; //��������
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
		Matrix4D re; //����������
		for (int i = 0; i < size; i++)
			re[i] = arr[i] + mat.arr[i];
		return re;
	}

	Matrix4D Matrix4D::operator - (const Matrix4D& mat) const
	{
		Matrix4D re; //����������
		for (int i = 0; i < size; i++)
			re[i] = arr[i] - mat.arr[i];
		return re;
	}

	//ʱ�临�Ӷ�O(n^3)�����ؾ���˷�
	//XXX: �Ż��㷨������ʱ�临�Ӷ�
	Matrix4D Matrix4D::operator * (const Matrix4D& mat) const
	{
		Matrix4D re; //����������
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				for (int k = 0; k < 4; k++)
					re.At(i, j) = arr[i * 4 + k] * mat.arr[k * 4 + j];
		return re;
	}
}