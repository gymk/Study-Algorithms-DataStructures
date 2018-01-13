#include <stdio.h>
#include  <math.h>
 
// A1 = 9; a2 = 9 * a1; a3 = 8 * a2;
int Perm (int N, int r)
{
   if (r == 1)
   {
      return 9;
   }
 
   int an = 9, RN = 9;
 
   while (r> 1) {
        an *= RN;
        r--; RN--;
    }
    return an;
}
 
int cnt = 0;
 
int getNthNum (int * bit, int nth, int nthOfdec, int depth)
{
    int sum = 0;
    int I;
 
    // Last digit
    if (depth > nthOfdec) {
        cnt++;
        return 0;
    }
 
    // 1st: [1-9], remain: [0-9]
    for (I = (depth == 1? 1:00); I <10; I++)
    {
        if (! bit[I])
        {
            bit [I] = 1;
            sum = getNthNum (bit, nth, nthOfdec, depth +1);
            if (cnt == nth)
                return sum + I * (int) pow(10, nthOfdec-depth);
            bit [I] = 0;
        }
    }
 
    return 0;
}
 
int main (int argc, char *argv[])
{
    int nth;
 
    while (1)
    {
        scanf ("%d", & nth);
        if (nth == 0) break;
 
        int sum = 0;
        int I;
 
        // Part1: find nth-of-dec (10 <n <100? 100 <n <1000? ...)
        for (I = 1; I <10; I++)
        {
            int p = Perm (10, I);
 
            if ((sum + p)>= nth) break;
            sum = sum + p;
        }
 
        // Part2: get nth number
        if (I == 1) {
            sum = nth;
        } else {
            int bit [16] = {0,};
 
            cnt = sum;
            sum = getNthNum (bit, nth, I, 1);
        }
 
        printf ("%d\n", sum);
    }
    return 0;
}
