#include <iostream>

using namespace std;

class FindMissingNumber1
{
public:
	FindMissingNumber1(int N, int dup, int dup_loc)
	{
		m_N = N;
		m_pA = new int[N];

		for(int i = 0; i < N; i++)
			m_pA[i] = i+1;

		m_pA[dup_loc] = dup;
	}
	~FindMissingNumber1()
	{
		if(m_pA != nullptr)
			delete [] m_pA;
	}

	int GetDup(void)
	{
		long long sum = 0;

		for(int i = 0; i < m_N; i++)
			sum += m_pA[i];

		cout << "sum - " << sum << endl;
		cout << "((m_N * (m_N+1)) / 2) - " << ((m_N * (m_N+1)) / 2) << endl;

		return (sum - ((m_N * (m_N+1)) / 2));
	}
	void Print(void)
	{
		cout << "N[" << m_N << "] ";
		cout << "Dup - " << GetDup();
		cout << endl;
	}
private:
	int * m_pA;
	int m_N;
};

void test_find_missing_number(void)
{
	FindMissingNumber1	f1(20, 1, 8);
	FindMissingNumber1	f2(5, 1, 1);

	f1.Print();
	f2.Print();
}
