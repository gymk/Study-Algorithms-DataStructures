/*
g++ star_pattern9.cpp

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
   * *
  *   *
 *     *
*       *
 *     *
  *   *
   * *
    * 
*/

#include <iostream>

using namespace std;

int main(void)
{
  int N;
  
  cout << "Enter no. of rows: ";
  cin >> N;
  
  int r, s, v;
  
// print first row
    // print left spaces
    for(s = 1; s <= N-1; s++)
    {
      cout << ' ';
    }
    cout << '*' << '\n';

//  print last row

  // print first half of the diamond
  for( r = 2; r <= N; r++)
  {
    // print left spaces
    for(s = 1; s <= N-r; s++)
    {
      cout << ' ';
    }
    // print star
    cout << '*';
    // print hollow spaces
    for(s = 2; s <= 2*(r-1); s++)
    {
      cout << ' ';
    }
    // print right star
    cout << '*';

    cout << '\n';
  }

  // print second half of the diamond
  for(r = 2; r < N; r++)
  {
    // print left spaces
    for(s = 1; s < r; s++)
    {
      cout << ' ';
    }
    // print star
    cout << '*';
    // print hollow spaces
    for(s = 2; s <= (2*N) - (2 * r); s++)
    {
      cout << ' ';
    }
    // print right star
    cout << '*';
    cout << '\n';
  }

// print last row
    // print left spaces
    for(s = 1; s <= N-1; s++)
    {
      cout << ' ';
    }
    cout << '*' << '\n';

  return 0;
}

/*

Output:

Enter no. of rows: 10
         *
        * *
       *   *
      *     *
     *       *
    *         *
   *           *
  *             *
 *               *
*                 *
 *               *
  *             *
   *           *
    *         *
     *       *
      *     *
       *   *
        * *
         *

*/