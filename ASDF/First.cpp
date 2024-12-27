#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Sum(int*, int const);
void Avarage(int*, int const);
void Merge_Sort(int*, int, int);
void merge(int*, int, int, int);
void Quick_Sort(int*, int, int);

int main()
{
	cout << "입력할 숫자 총 갯수 =";
	int maxNum;

	cin >> maxNum;

	int* arr = new int[maxNum];
	int sortNum;

	cout << "숫자 "<< maxNum <<"개를 입력해 주세요" << endl;
	for (int i = 0; i < maxNum; i++)
	{
		cout << i + 1 << "번째 숫자 :";
		cin >> arr[i];
	}

	cout << "정렬 전 : ";
	for (int i = 0; i < maxNum; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	cout << "정렬 방식을 선택해주세요. 1 - 오름차순, 2 - 내림차순 : ";
	while (1)
	{
		cin >> sortNum;
		if (sortNum == 1 || sortNum == 2)
			break;
		else
		{
			cout << "잘못된 숫자입력입니다. 다시 눌러주세요. 1 - 오름차순, 2 - 내림차순 : ";
		}
	}

	if (sortNum == 1)
	{
		Merge_Sort(arr, 0, maxNum - 1);

		cout << "오름차 정렬 : ";
		for (int i = 0; i < maxNum; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	else
	{
		Quick_Sort(arr, 0, maxNum - 1);

		cout << "내림차 정렬 : ";
		for (int i = 0; i < maxNum; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}



	Sum(arr, maxNum);
	Avarage(arr, maxNum);

	delete[] arr;
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

void Merge_Sort(int* arr, int _left, int _right)
{
	int mid;
	
	if (_left < _right) // 분할이 남아있음
	{
		mid = (_left + _right) / 2;
		Merge_Sort(arr, _left, mid); // 좌분할
		Merge_Sort(arr, mid + 1, _right); // 우분할
		merge(arr, _left, mid, _right); // 합병
	}
}

void merge(int* arr, int _left, int _mid, int _right)
{
	int size = _right - _left + 1;
	int* list = (int*)malloc(sizeof(int) * size);
	
	if (list == NULL)
	{
		cout << "동적할당한 list배열(in merge())이 NULL을 참조하고 있음." << endl;
		return;
	}

	int i = _left;
	int j = _mid + 1;
	int k = 0;

	while (i <= _mid && j <= _right) // 둘다있을경우 : 비교
	{
		if (arr[i] < arr[j])
		{
			list[k] = arr[i];
			k++;
			i++;
		}
		else
		{
			list[k] = arr[j];
			k++;
			j++;
		}
	}

	while (i <= _mid)
	{
		list[k] = arr[i];
		k++;
		i++;
	}

	while (j <= _right)
	{
		list[k] = arr[j];
		k++;
		j++;
	}

	int u = 0;
	for (int i = _left; i <= _right; i++)
	{
		arr[i] = list[u];
		u++;
	}

	free(list);
}

void Quick_Sort(int* arr, int _left, int _right)
{
	if (_left >= _right)
		return;

	int pivot = _left;
	int lowValIdx = _left + 1;
	int highValIdx = _right;
	int tmp;

	while (1)
	{
		while (arr[lowValIdx] > arr[pivot] && lowValIdx < _right)
		{
			lowValIdx++;
		}

		while (arr[highValIdx] <= arr[pivot] && highValIdx > _left)
		{
			highValIdx--;
		}

		if (highValIdx <= lowValIdx)
			break;
		else
		{
			tmp = arr[highValIdx];
			arr[highValIdx] = arr[lowValIdx];
			arr[lowValIdx] = tmp;
		}
	}

	tmp = arr[pivot];
	arr[pivot] = arr[highValIdx];
	arr[highValIdx] = tmp;
	

	if (_left < _right)
	{
		Quick_Sort(arr, _left, highValIdx - 1);
		Quick_Sort(arr, highValIdx + 1, _right);
	}
}


