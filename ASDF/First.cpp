#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Sum(int*, int const);
void Avarage(int*, int const);

int main()
{
	int const maxNum = 5;

	int arr[maxNum];

	cout << "숫자 "<< maxNum <<"개를 입력해 주세요" << endl;
	for (int i = 0; i < maxNum; i++)
	{
		cout << i + 1 << "번째 숫자 :";
		cin >> arr[i];
	}

	Sum(arr, maxNum);
	Avarage(arr, maxNum);
}

void Sum(int* arr, int const _max)
{
	int Sum = 0;
	for (int i = 0; i < _max; i++)
	{
		Sum += arr[i];
	}

	cout << "배열 원소들의 합 : " << Sum << endl;
}

void Avarage(int* arr, int const _max)
{
	int Ava = 0;
	for (int i = 0; i < _max; i++)
	{
		Ava += arr[i];
	}
	Ava /= _max;

	cout << "배열 원소들의 평균 : " << Ava << endl;
}


