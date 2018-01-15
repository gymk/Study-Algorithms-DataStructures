#include <iostream>

extern void PrintIntArray(const char * pStr, const int * pA, int n);

/**
 * [sort_bin_array description]
 * @param pA [description]
 * @param N  [description]
 */
void sort_bin_array(int * pA, int N)
{
	int i, j, tmp;

	i = 0; j = N-1;

	while(1)
	{
		while( i < N)
			if((pA[i] & 1) == 0)
				i++;
			else
				break;

		while( j >= 0)
			if(pA[j] & 1)
				j--;
			else
				break;

		if(i > j)
		{
			break;
		}

		tmp = pA[i];
		pA[i] = pA[j];
		pA[j] = tmp;
		i++;
		j--;
	}
}

/**
 * [test_sort_bin_array description]
 */
void test_sort_bin_array()
{
	int size;
	int A1[] = { 1, 0, 1, 1, 0, 0, 0, 1, 1, 1 };
	int A2[] = { 1, 1, 1, 1, 1 };
	int A3[] = { 0, 0, 0, 0, 0 };
	int A4[] = { 0, 0, 0, 1, 1 };

	size = sizeof(A1)/ sizeof(A1[0]);
	PrintIntArray("Before Sorting", A1, size);
	sort_bin_array(A1, size);
	PrintIntArray("After Sorting", A1, size);

	size = sizeof(A2)/ sizeof(A2[0]);
	PrintIntArray("Before Sorting", A2, size);
	sort_bin_array(A2, size);
	PrintIntArray("After Sorting", A2, size);

	size = sizeof(A3)/ sizeof(A3[0]);
	PrintIntArray("Before Sorting", A3, size);
	sort_bin_array(A3, size);
	PrintIntArray("After Sorting", A3, size);

	size = sizeof(A4)/ sizeof(A4[0]);
	PrintIntArray("Before Sorting", A4, size);
	sort_bin_array(A4, size);
	PrintIntArray("After Sorting", A4, size);
}
