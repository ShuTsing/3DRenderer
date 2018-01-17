#pragma once
//������������
//�����;���

namespace gra
{
	//��ά����
	class Vector4D
	{
	private:
		float arr[4]; //��������
	};

	//4*4����
	class Matrix4D
	{
	public:

		float& At(int x, int y) //ͨ���±��ȡֵ��������Խ����
		{
			return arr[x][y];
		}

		Matrix4D operator *= (const float val); //������˸�����
		Matrix4D operator += (const float val); //������Ӹ�����
		Matrix4D operator /= (const float val); //��������Ը�����
		Matrix4D operator -= (const float val); //�������������

		Matrix4D operator + (const float val) const; //����Ӹ�����
		Matrix4D operator - (const float val) const; //�����������
		Matrix4D operator * (const float val) const; //����˸�����
		Matrix4D operator / (const float val) const; //������Ը�����


	private:

		float arr[4][4]; //���ݱ�������
	};

	inline Matrix4D Matrix4D::operator *= (const float val)
	{
		//������ÿ��Ԫ�����γ�val
		for (auto& i : arr)
			for (auto& j : i)
				j *= val;
		return *this;
	}

	inline Matrix4D Matrix4D::operator += (const float val)
	{
		//������ÿ��Ԫ�����μ�val
		for (auto& i : arr)
			for (auto& j : i)
				j += val;
		return *this;
	}

	inline Matrix4D Matrix4D::operator /= (const float val)
	{
		//������ÿ��Ԫ�����γ���val
		for (auto& i : arr)
			for (auto& j : i)
				j /= val;
		return *this;
	}

	inline Matrix4D Matrix4D::operator -= (const float val)
	{
		//������ÿ��Ԫ�����μ�val
		for (auto& i : arr)
			for (auto& j : i)
				j -= val;
		return *this;
	}

	inline Matrix4D Matrix4D::operator + (const float val) const
	{
		Matrix4D re; //��������
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				re.At(i, j) = arr[i][j] + val;
		return re;
	}

	inline Matrix4D Matrix4D::operator - (const float val) const
	{
		Matrix4D re; //��������
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				re.At(i, j) = arr[i][j] - val;
		return re;
	}

	inline Matrix4D Matrix4D::operator * (const float val) const
	{
		Matrix4D re; //��������
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				re.At(i, j) = arr[i][j] * val;
		return re;
	}

	inline Matrix4D Matrix4D::operator / (const float val) const
	{
		Matrix4D re; //��������
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				re.At(i, j) = arr[i][j] / val;
		return re;
	}
}