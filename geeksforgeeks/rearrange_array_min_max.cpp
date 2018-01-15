/*
 * http://www.geeksforgeeks.org/rearrange-array-maximum-minimum-form/
 */

#include <iostream>

#define MAX_ARR_SIZE	1000

using namespace std;

extern void PrintIntArray(const char * pStr, const int * pA, int n);

void ReArrangeSortedArray_MinMaxOrder_UsingAux(int * pA, int N)
{
	int i = 0, j = N-1;
	int k = 0;
	int B[N];

	while((k < N) && (i <= j))
	{
		B[k++] = pA[j--];
		if(k < N)
			B[k++] = pA[i++];
	}

	for(k = 0; k < N; k++)
		pA[k] = B[k];
}

void ReArrangeSortedArray_MinMaxOrder_NoAux(int * pA, int N)
{
	int k;
	int i;
	int temp, movVal;

	k = 0;
	i = 0;
	movVal = pA[i];
	while(1)
	{
		int j = (i < (N/2) ? ((i * 2)+1) : ((N-i-1) * 2) );

		if(k >= N)
			break;

		temp = pA[j];
		pA[j] = movVal;
		movVal = temp;
		i = j;
		k++;
	}
}

void test_rearrange_array_min_max()
//int main()
{
	int T, t_loop;
	int N, n_loop;
	int arr[MAX_ARR_SIZE];

	cin >> T;

	for(t_loop = 0; t_loop < T; t_loop++)
	{
		cin >> N;
		for(n_loop = 0; n_loop < N; n_loop++)
			cin >> arr[n_loop];

		//ReArrangeSortedArray_MinMaxOrder_UsingAux(arr, N);
		ReArrangeSortedArray_MinMaxOrder_NoAux(arr, N);
		PrintIntArray("", arr, N);
	}
}

/*
 * Input:
82
12 23 28 43 44 59 60 68 70 85 88 92 124 125 136 168 171 173 179 199 212 230 277 282 306 314 316 325 328 336 337 363 365 368 369 371 374 387 394 414 422 427 430 435 457 493 506 527 531 538 541 546 568 583 650 691 730 737 751 764 778 783 785 789 794 803 809 815 847 858 863 874 887 896 916 920 926 927 930 957 981 997

Its Correct output is:
997 12 981 23 957 28 930 43 927 44 926 59 920 60 916 68 896 70 887 85 874 88 863 92 858 124 847 125 815 136 809 168 803 171 794 173 789 179 785 199 783 212 778 230 764 277 751 282 737 306 730 314 691 316 650 325 583 328 568 336 546 337 541 363 538 365 531 368 527 369 506 371 493 374 457 387 435 394 430 414 427 422

And Your Code's Output is:
337 783 28 422 44 59 60 12 70 85 88 92 124 125 136 12 363 173 179 199 212 230 277 282 306 314 316 325 896 336 328 23 365 789 369 371 68 387 394 414 531 427 430 435 457 493 506 527 368 538 541 546 568 583 650 691 730 171 751 764 778 737 785 43 794 803 815 374 847 858 863 874 887 168 916 920 926 927 930 957 981 809
 */
