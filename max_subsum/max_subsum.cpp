#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class MaxSubSum
{
public:
	MaxSubSum()
	{
		seqStart = seqEnd = maxSeqVal = 0;
	}

	~MaxSubSum()
	{
		Reset();
	}

public:
	void PrintSet(void)
	{
		cout << "{";
		for(vector<int>::iterator it = set.begin(); it != set.end(); ++it)
		{
			cout << ' ' << *it;
		}
		cout << "}\n";
	}
	void PrintMaxSequence(void)
	{
		cout << "Max Val " << maxSeqVal << "{";
		for(int i = seqStart; i <= seqEnd; ++i)
		{
			cout << ' ' << set[i];
		}
		cout << "}\n";
	}

public:
	void Add(int val) { set.push_back(val); };
	void Reset(void)
	{
		set.erase(set.begin(), set.end());
		maxSeqVal = 0;
	}

public:
	bool DoExhaustiveSearch(void);
	bool DoImprovedExhaustiveSearch(void);
	bool DoLinearSearch(void);

private:
	vector<int>	set;
	int	seqStart;
	int	seqEnd;
	int maxSeqVal;
};

// Exhaustive Search
// Or Brute Force Method of search
// O(N^3)
// Cubic search algorthm
bool MaxSubSum::DoExhaustiveSearch(void)
{
	int i, j, k;
	int N = set.size();

	maxSeqVal = 0;
	for(i = 0; i < N; i++)
	{
		for(j = i; j < N; j++)
		{
			int thisSum = 0;

			for(k = i; k <= j; k++)
			{
				thisSum += set[k];
			}

			if(thisSum > maxSeqVal)
			{
				maxSeqVal = thisSum;
				seqStart = i;
				seqEnd = j;
			}
		}
	}

	return false;
}

// O(N^2)
// quadratic search algorithm
bool MaxSubSum::DoImprovedExhaustiveSearch(void)
{
	int i, j;
	int N = set.size();

	maxSeqVal = 0;
	for(i = 0; i < N; i++)
	{
		int thisSum = 0;
		for(j = i; j < N; j++)
		{
			thisSum += set[j];

			if(thisSum > maxSeqVal)
			{
				maxSeqVal = thisSum;
				seqStart = i;
				seqEnd = j;
			}
		}
	}

	return false;
}

// O(N)
// Linear Search
bool MaxSubSum::DoLinearSearch(void)
{
	int i, j;
	int N = set.size();
	int thisSum = 0;

	maxSeqVal = 0;
	for(i = 0, j = 0; j < N; j++)
	{
		thisSum += set[j];

		if(thisSum > maxSeqVal)
		{
			maxSeqVal = thisSum;
			seqStart = i;
			seqEnd = j;
		}
		else if (thisSum < 0)
		{
			i = j + 1;
			thisSum = 0;
		}
	}

	return false;
}


int main(int argc, char * argv[])
{
	MaxSubSum	mySum;

	mySum.Add(-2);
	mySum.Add(11);
	mySum.Add(-4);
	mySum.Add(13);
	mySum.Add(-5);
	mySum.Add(2);

	mySum.PrintSet();
	mySum.DoExhaustiveSearch();
	mySum.PrintMaxSequence();
	mySum.DoImprovedExhaustiveSearch();
	mySum.PrintMaxSequence();
	mySum.DoLinearSearch();
	mySum.PrintMaxSequence();

	mySum.Reset();

	mySum.PrintSet();

	mySum.Add(1);
	mySum.Add(-3);
	mySum.Add(4);
	mySum.Add(-2);
	mySum.Add(-1);
	mySum.Add(6);

	mySum.PrintSet();
	mySum.DoExhaustiveSearch();
	mySum.PrintMaxSequence();
	mySum.DoImprovedExhaustiveSearch();
	mySum.PrintMaxSequence();
	mySum.DoLinearSearch();
	mySum.PrintMaxSequence();

	return 0;
}