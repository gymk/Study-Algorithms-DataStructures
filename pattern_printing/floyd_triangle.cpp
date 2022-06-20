/*
g++ floyd_triangle.cpp

g++ --version
g++ (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0
Copyright (C) 2019 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

lsb_release  -a
No LSB modules are available.
Distributor ID: Ubuntu
Description:    Ubuntu 20.04.4 LTS
Release:        20.04
Codename:       focal
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main(void)
{
  int v;
  int N;
  cout << "Enter no. of rows for Floyd's triagle: ";
  cin >> N;
  v = 1;
  for(int r = 1; r <= N; r++)
  {
    for(int c = 1; c <= r; c++, v++)
    {
      cout << std::right << std::setw(5) << v;
    }
    cout << endl;
  }
  return 0;
}

/*
Output:
  Enter no. of rows for Floyd's triagle: 10
     1
     2    3
     4    5    6
     7    8    9   10
    11   12   13   14   15
    16   17   18   19   20   21
    22   23   24   25   26   27   28
    29   30   31   32   33   34   35   36
    37   38   39   40   41   42   43   44   45
    46   47   48   49   50   51   52   53   54   55
*/