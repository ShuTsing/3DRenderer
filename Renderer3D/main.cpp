#include <iostream>
#include <cstdlib>
#include "BaseType.h"

//#include <amp.h> //GPU加速
#include <ctime>

#define MATRIX_ORDER 1000



using namespace std;

void CppAmpMethod() {
	int aCPP[] = { 1, 2, 3, 4, 5 };
	int bCPP[] = { 6, 7, 8, 9, 10 };
	int sumCPP[5];

	// Create C++ AMP objects.  
	array_view<const int, 1> a(5, aCPP);
	array_view<const int, 1> b(5, bCPP);
	array_view<int, 1> sum(5, sumCPP);
	sum.discard_data();

	parallel_for_each(
		// Define the compute domain, which is the set of threads that are created.  
		sum.extent,
		// Define the code to run on each thread on the accelerator.  
		[=](index<1> idx) restrict(amp)
	{
		sum[idx] = a[idx] + b[idx];
	}
	);

	sum.synchronize();

	// Print the results. The expected output is "7, 9, 11, 13, 15".  
	for (int i = 0; i < 5; i++) {
		std::cout << sumCPP[i] << "\n";
	}
}

float Matrix_AMP()
{
	float score = .0f;

	int *a = new int[MATRIX_ORDER*MATRIX_ORDER];
	int *b = new int[MATRIX_ORDER*MATRIX_ORDER];
	int *r = new int[MATRIX_ORDER*MATRIX_ORDER];

	for (int row = 0; row < MATRIX_ORDER; row++)
	{
		for (int col = 0; col < MATRIX_ORDER; col++)
		{
			a[row*MATRIX_ORDER + col] = row * MATRIX_ORDER + col;
			b[row*MATRIX_ORDER + col] = row * MATRIX_ORDER + col;
			r[row*MATRIX_ORDER + col] = 0;
		}
	}

	auto s = clock();

	//amp.begin
	array_view<const int, 2> src(MATRIX_ORDER, MATRIX_ORDER, a);
	array_view<const int, 2> dst(MATRIX_ORDER, MATRIX_ORDER, b);
	array_view<int, 2> result(MATRIX_ORDER, MATRIX_ORDER, r);
	result.discard_data();

	parallel_for_each(
		result.extent,
		[=](index<2> idx) restrict(amp)
	{
		const unsigned int row = idx[0];
		const unsigned int col = idx[1];
		int r = 0;

		for (unsigned int i = 0; i < MATRIX_ORDER; i++)
		{
			r += src[row][i] * dst[i][col];
		}
		result[idx] = r;
	}
	);

	result.synchronize();
	//amp.end

	auto e = clock();

	delete a;
	delete b;
	delete r;

	cout << (double)(e - s) / CLOCKS_PER_SEC << endl;

	//以毫秒为单位，返回耗时。
	return score;
}


int main()
{
	//Matrix_AMP();
	gra::Matrix4D a = gra::Matrix4D(), b = gra::Matrix4D();
	a.At(1, 1) = 1;
	a = a * b;
	auto s = clock();
	a = a * b;
	a = a * b;
	a = a * b;
	a = a * b;
	a = a * b;
	a = a * b;
	a = a * b;
	a = a * b;
	a = a * b;
	a = a * b;
	a = a * b;
	a = a * b;
	a = a * b;
	a = a * b;
	a = a * b;
	a = a * b;
	a = a * b;
	a = a * b;
	a = a * b;
	a = a * b;
	a = a * b;
	a = a * b;
	a = a * b;
	a = a * b;
	a = a * b;
	a = a * b;
	a = a * b;
	a = a * b;
	auto e = clock();
	cout << (double)(e - s) / CLOCKS_PER_SEC << endl;
	system("pause");
	return 0;
}