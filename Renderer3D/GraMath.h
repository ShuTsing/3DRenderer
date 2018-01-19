#pragma once
#include "BaseType.h"


//数学库
//向量和矩阵运算所需函数
namespace gra
{
	Vector4D Interpolate(Vector4D vec1, Vector4D vec2, float t); //计算向量插值
	void Normalize(Vector4D& vec);                               //向量标准化（归一化），不可逆
}