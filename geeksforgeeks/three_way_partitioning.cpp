/*
 * http://www.geeksforgeeks.org/three-way-partitioning-of-an-array-around-a-given-range/
 */

#include <iostream>
#include <iomanip>

using namespace std;

namespace three_way_paritioning
{

void PrintIntArray(const char * pStr, const int * pA, int n)
{
	cout << pStr << ": ";
	cout << setw(2) << setfill('0');
	for(int i = 0; i < n; i++)
		cout << pA[i] << " ";
	cout << endl;
}

void Swap(int * pA, int x, int y)
{
	int temp = pA[x];
	pA[x] = pA[y];
	pA[y] = temp;
}

void Do3WayPartitioning(int * pA, int n, int lowVal, int highVal)
{
	int lowValIndex, highValIndex;

	lowValIndex = 0;
	while(lowValIndex < n)
	{
		if(pA[lowValIndex] < lowVal)
			lowValIndex++;
		else
			break;
	}
	highValIndex = n-1;
	while(highValIndex >= 0)
	{
		if(pA[highValIndex] > highVal)
			highValIndex--;
		else
			break;
	}

	//int i = 0; lowValIndex = 0; highValIndex = n-1;
	int i = lowValIndex;
	while(i < highValIndex)
	{
		cout << setw(2) << setfill('0');
		cout << i << " " << lowValIndex << " " << highValIndex << " ==> ";
		if(pA[i] > highVal)
		{
			Swap(pA, i, highValIndex);
			highValIndex--;

			if(pA[i] < lowVal)
			{
				Swap(pA, i, lowValIndex);
				lowValIndex++;
			}
		}
		else if(pA[i] < lowVal)
		{
			Swap(pA, i, lowValIndex);
			lowValIndex++;

			if(pA[i] > highVal)
			{
				Swap(pA, i, highValIndex);
				highValIndex--;
			}
		}
		else
			i++;

		PrintIntArray("InBet", pA, n);
	}

	return;
}

void test1()
{
	int arr[] = {1, 14, 5, 20, 4, 2, 54, 20, 87, 98, 3, 1, 32};
	int n = sizeof(arr) / sizeof(arr[0]);

	int lowVal = 14, highVal = 20;

	PrintIntArray("Input", arr, n);

	Do3WayPartitioning(arr, n, lowVal, highVal);

	PrintIntArray("Output", arr, n);
}


void test2()
{
	int arr[] = {1, 14, 5, 20, 4, 2, 54, 20, 87, 98, 3, 1, 32};
	int n = sizeof(arr) / sizeof(arr[0]);

	int lowVal = 20, highVal = 20;

	PrintIntArray("Input", arr, n);

	Do3WayPartitioning(arr, n, lowVal, highVal);

	PrintIntArray("Output", arr, n);
}


}	// namespace three_way_paritioning

void test_3_way_partitioning()
{
	three_way_paritioning::test1();
	three_way_paritioning::test2();
}
