#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Sum(int*, int const); // 배열내 원소 합산
void Avarage(int*, int const); // 배열 내 원소들의 평균
void Merge_Sort(int*, int, int); // 합병 정렬 중 분할역할
void merge(int*, int, int, int); // 합병 정렬 중 정렬역할
void Quick_Sort(int*, int, int); // 퀵정렬

int main()
{
	//값 입력 구간
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

	//정렬 하기 전
	cout << "정렬 전 : ";
	for (int i = 0; i < maxNum; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	//정렬 방식 선택
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
		Merge_Sort(arr, 0, maxNum - 1); // 오름차순 : 합병정렬로 구현

		cout << "오름차 정렬 : ";
		for (int i = 0; i < maxNum; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	else
	{
		Quick_Sort(arr, 0, maxNum - 1); // 내림차순 : 퀵 정렬로 구현

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

//합 함수
void Sum(int* arr, int const _max)
{
	int Sum = 0;
	for (int i = 0; i < _max; i++)
	{
		Sum += arr[i];
	}

	cout << "배열 원소들의 합 : " << Sum << endl;
}

//곱 함수
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

//합병 정렬 분할
//순서 1.더이상 분할 안될때 까지 파트를 좌우로 쪼갬(쪼개는 기준 = mid)
//순서 2.더이상 좌우로 쪼갤 수 없을때 합병 시작(최초:2개)
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

//합병 정렬 합병(정렬시작)
//순서 1.쪼갠 양쪽(mid기준) 배열들을 비교하여 새로운 리스트에 담기(list)
//순서 2.한쪽이 남아있는 경우, 남은 것들을 새로운 리스트에 담기
void merge(int* arr, int _left, int _mid, int _right)
{
	int size = _right - _left + 1;
	int* list = new int[size] {0};
	
	if (list == nullptr)
	{
		cout << "동적할당한 list배열이 NULL을 참조하고 있음." << endl;
		return;
	}

	int i = _left;
	int j = _mid + 1;
	int k = 0;

	// 둘다있을경우 : 비교 후 list에 집어넣기
	while (i <= _mid && j <= _right) 
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

	//한쪽만 있는경우 : list에 남은거 집어넣기
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

	//정렬된 리스트를 arr에 적용
	for (int i = _left; i <= _right; i++)
	{
		arr[i] = list[u];
		u++;
	}

	delete[] list;
}

//퀵 정렬 (내림차순)
//순서 1.각 파트의 피봇을 정함(피봇 = 첫번째 인덱스 값)(파트 = 재귀함수로 인해 정해진 배열의 범위)
//순서 2.피봇 왼쪽부터 피봇보다 값이 작은 값을 찾음(lowValIdx)
//순서 3.파트 오른쪽부터 피봇보다 값이 큰 값을 찾음(highValIdx)
//순서 4.low와 high가 교차됐는가 ? 피봇값과 highValIdx 원소의 값을 교환 후 5번 진행 : high와 low의 원소값을 서로 교환 후 2번부터 진행
//순서 5.파트가 2개 이상인 상태이면 피봇제외 좌우로 쪼개서 1번부터 다시 진행
void Quick_Sort(int* arr, int _left, int _right)
{
	if (_left >= _right)
		return;

	int pivot = _left; // 순서1번
	int lowValIdx = _left + 1;
	int highValIdx = _right;
	int tmp;

	//비교할 idx가 교차될때까지 진행
	while (1)
	{
		//순서2번
		while (arr[lowValIdx] > arr[pivot] && lowValIdx < _right)
		{
			lowValIdx++;
		}

		//순서3번
		while (arr[highValIdx] <= arr[pivot] && highValIdx > _left)
		{
			highValIdx--;
		}

		//순서4번 : 교차가 안됐을때
		if (highValIdx <= lowValIdx)
			break;
		else
		{
			tmp = arr[highValIdx];
			arr[highValIdx] = arr[lowValIdx];
			arr[lowValIdx] = tmp;
		}
	}
	
	//순서5번 : 교차가 됐을때
	tmp = arr[pivot];
	arr[pivot] = arr[highValIdx];
	arr[highValIdx] = tmp;
	
	//순서5번
	if (_left < _right)
	{
		Quick_Sort(arr, _left, highValIdx - 1);
		Quick_Sort(arr, highValIdx + 1, _right);
	}
}


