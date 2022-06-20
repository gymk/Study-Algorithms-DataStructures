// https://www.geeksforgeeks.org/find-second-largest-element-array/

#include <iostream>
#include <limits.h>
using namespace std;

int main() {
	cout<<"GfG!";
// Input: arr[] = {12, 35, 1, 10, 34, 1}
// Output: The second largest element is 34.
// Explanation: The largest element of the 
// array is 35 and the second 
// largest element is 34

// Input: arr[] = {10, 5, 10}
// Output: The second largest element is 5.
// Explanation: The largest element of 
// the array is 10 and the second 
// largest element is 5

// Input: arr[] = {10, 10, 10}
// Output: The second largest does not exist.
// Explanation: Largest element of the array 
// is 10 there is no second largest element

//   int arr[] = {10, 12, 20, 4};  // ans '12'
//   int arr[] = {10, 10, 10}; // ans 'There is no 2nd largest...'
//   int arr[] = {10, 5, 10};    // ans '5'
    int arr[] = {12, 35, 1, 10, 34, 1}; // ans '34'
  int N = sizeof(arr) / sizeof(arr[0]);

  if(N < 2)
  {
    cout << "Less number of elements found";
    return 0;
  }

  int l1, l2;
  l1 = l2 = INT_MIN;
  for(int i = 0; i < N; i++)
  {
    if(arr[i] > l1)
    {
      l2 = l1;
      l1 = arr[i];
    }
    else if((arr[i] > l2) && (arr[i]) != l1)
    {
      l2 = arr[i];
    }
  }
  if(l2 == INT_MIN)
  {
    cout << "There is no 2nd largest...\n";
  }
  else
  {
    cout << "2nd largest is " << l2 << '\n';
  }
  return 0;

}