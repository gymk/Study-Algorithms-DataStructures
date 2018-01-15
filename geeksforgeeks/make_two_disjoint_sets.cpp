/*
 * http://www.geeksforgeeks.org/make-two-sets-disjoint-removing-minimum-elements/
 */

#include <iostream>

using namespace std;

namespace make_disjoint_sets
{

int make_disjoint_get_count(int * set1, int * set2, int m, int n)
{
	int max = 0; int loop;

	for(loop = 0; loop < m; loop++)
		if(set1[loop] > max) max = set1[loop];

	for(loop = 0; loop < n; loop++)
		if(set2[loop] > max) max = set2[loop];

	int pA[max];

	for(loop = 0; loop < max; ++loop)
		pA[loop] = 0;

	for(loop = 0; loop < m; loop++)
		pA[set1[loop]]++;

	for(loop = 0; loop < n; loop++)
		pA[set2[loop]]++;

	int count = 0;

	for(loop = 0; loop < max; ++loop)
		if(pA[loop] > 1 )	count += (pA[loop] - 1);

	return count;
}

void test1()
{
	int set1[] = {20, 21, 22};
	int set2[] = {22, 23, 24, 25};

	int m = sizeof(set1)/sizeof(set1[0]);
	int n = sizeof(set2)/sizeof(set2[0]);

	cout << "count - " << make_disjoint_get_count(set1, set2, m, n) << endl;
}

void test2()
{
	int set1[] = {20, 21, 22};
	int set2[] = {22, 23, 24, 25, 20};

	int m = sizeof(set1)/sizeof(set1[0]);
	int n = sizeof(set2)/sizeof(set2[0]);

	cout << "count - " << make_disjoint_get_count(set1, set2, m, n) << endl;
}


void test3()
{
	int set1[] = {6, 7};
	int set2[] = {12, 13, 14, 15};

	int m = sizeof(set1)/sizeof(set1[0]);
	int n = sizeof(set2)/sizeof(set2[0]);

	cout << "count - " << make_disjoint_get_count(set1, set2, m, n) << endl;
}


}	// namespace make_disjoing_sets

void test_make_two_disjoint_sets(void)
{
	make_disjoint_sets::test1();
	make_disjoint_sets::test2();
	make_disjoint_sets::test3();
}

