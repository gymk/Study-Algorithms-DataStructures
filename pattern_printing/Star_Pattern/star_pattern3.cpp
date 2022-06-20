/*
g++ star_pattern3.cpp

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
|   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |
|---|---|---|---|---|---|---|---|---|---|----|
| 1 | * | * | * | * | * | * | * | * | * | *  |
| 2 | * | * | * | * |   |   | * | * | * | *  |
| 3 | * | * | * |   |   |   |   | * | * | *  |
| 4 | * | * |   |   |   |   |   |   | * | *  |
| 5 | * |   |   |   |   |   |   |   |   | *  |
| 6 | * | * |   |   |   |   |   |   | * | *  |
| 7 | * | * | * |   |   |   |   | * | * | *  |
| 8 | * | * | * | * |   |   | * | * | * | *  |
| 9 | * | * | * | * | * | * | * | * | * | *  |

Stars in each Row:
  10
  8
  6
  4
  2
  4
  6
  8
  10

Spaces in eahc Row:
  0
  2
  4
  6
  8

No. of Starts to print
*/


#include <iostream>

using namespace std;

int main(void)
{
  int N;
  cout << "Enter no. of rows: ";
  cin >> N;
  int r, v, s;

  // top half
  for(r = 1; r <= N; r++)
  {
    // print left stars
    for(v = 1; v <= (N-r)+1; v++)
    {
      cout << '*';
    }
    // print spaces
    for(s = 1; s < r; s++)
    {
      cout << "  "; // double spaces
    }
    // print right stars
    for(v = 1; v <= (N-r)+1; v++)
    {
      cout << '*';
    }
    cout << '\n';
  }
  // bottom half
  for(r = 2; r <= N; r++)
  {
    // print left stars
    for(v = 1; v <= r; v++)
    {
      cout << '*';
    }
    // print spaces
    for(s = 1; s <= N - r; s++)
    {
      cout << "  "; // double spaces
    }
    // print right stars
    for(v = 1; v <= r; v++)
    {
      cout << '*';
    }
    cout << '\n';
  }
  return 0;
}

/*
Output:

Enter no. of rows: 12
************************
***********  ***********
**********    **********
*********      *********
********        ********
*******          *******
******            ******
*****              *****
****                ****
***                  ***
**                    **
*                      *
**                    **
***                  ***
****                ****
*****              *****
******            ******
*******          *******
********        ********
*********      *********
**********    **********
***********  ***********
************************
*/