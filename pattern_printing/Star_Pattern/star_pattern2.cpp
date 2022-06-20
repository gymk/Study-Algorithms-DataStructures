/*
g++ star_pattern2.cpp

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

/*

|   | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|---|---|---|---|---|---|---|---|     ==> No need to print right side spoaces, only we are considering calc of left side spaces only
| 1 | * | * | * | * | * | * | * |     ==> 0 spaces
| 2 |   | * | * | * | * | * |   |     ==> 1 spaces
| 3 |   |   | * | * | * |   |   |     ==> 2 spaces
| 4 |   |   |   | * |   |   |   |     ==> 3 spaces

Stars in each Row
  7 stars 2 * (4-1) + 1
  5 stars 2 * (4-2) + 1
  3 stars 2 * (4-3) + 1
  1 stars 2 * (4-4) + 1

No. of spaces required ==> r - 1
Spaces formula ==> (2*(N-r)) + 1
*/

#include <iostream>

using namespace std;

int main(void)
{
  int N;
  cout << "Enter no. of required rows: ";
  cin >> N;
  int r, s, v;
  for(r = 1; r <= N; r++)
  {
    // print spaces
    for(s = 1; s <= (r-1); s++)
    {
      cout << ' ';
    }
    // print star's
    for(v = 1; v <= (2*(N-r)) + 1; v++)
    {
      cout << '*';
    }
    cout << '\n';
  }
  return 0;
}

/*
Output:

Enter no. of required rows: 10
*******************
 *****************
  ***************
   *************
    ***********
     *********
      *******
       *****
        ***
         *
*/