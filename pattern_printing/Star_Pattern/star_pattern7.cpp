/*
g++ star_pattern7.cpp

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
    *
   **
  ***
 ****
*****
*/

#include <iostream>

using namespace std;

int main(void)
{
  int N;

  cout << "Enter no. of rows: ";
  cin >> N;
  int r, s, v;

  for(r = 1; r <= N; r++)
  {
    // print spaces
    for(s = 1; s <= N-r; s++)
    {
      cout << ' ';
    }
    // print stars
    for(v = (N-r) + 1; v <= N; v++)
    {
      cout << '*';
    }
    cout << '\n';
  }

  return 0;
}

/*
Output:

Enter no. of rows: 7
      *
     **
    ***
   ****
  *****
 ******
*******

*/