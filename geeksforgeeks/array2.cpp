// https://www.geeksforgeeks.org/to-find-smallest-and-second-smallest-element-in-an-array/?ref=gcse

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<int> minAnd2ndMin(int a[], int n);

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
      cin >> a[i];

    vector<int> ans = minAnd2ndMin(a, n);
    if (ans[0] == -1)
      cout << -1 << endl;
    else
      cout << ans[0] << " " << ans[1] << endl;
  }
  return 0;
} // } Driver Code Ends

vector<int> minAnd2ndMin(int a[], int n)
{
  int v1 = INT_MAX;
  int v2 = INT_MAX;

  for (int i = 0; i < n; i++)
  {
    if (a[i] < v1)
    {
      v2 = v1;
      v1 = a[i];
    }
    else if ((a[i] < v2) && (a[i] != v1))
    {
      v2 = a[i];
    }
  }
  vector<int> r{v1, v2};

  return r;
}