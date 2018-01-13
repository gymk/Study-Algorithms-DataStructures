#include <stdio.h>
#include <stdlib.h>

int power_of_x(int x, int power)
{
  int loop;
  int result = 1;

  for(loop = 0; loop < power; ++loop)
  {
    result *= x;
  }

  return result;
}

int get_summation(int set_index, int *pArr, int len)
{
  int arr_index = 0;
  int sum = 0;
  int num_bits = 0;

  if(set_index < len)
  {
    while(set_index != 0)
    {
      if(set_index & 1)
      {
        sum += pArr[arr_index];
        ++num_bits;
      }
      ++arr_index;
      set_index >>= 1;
    }
    
    if(num_bits == 1)
    {
      sum = 0;
    }
  }

  return sum;
}

int is_it_weird_numer(int i32Number)
{
  int *pi32DivisorList;
  int i32Loop;
  int i32DivIndex;
  int i32SumL1, i32SumL2, i32SumL3, i32SumL4;
  int itr_count;

  int i32Sum;

  int result = 0;

  pi32DivisorList = (int*) malloc(((i32Number >> 1)+1) * sizeof(int));

  i32DivIndex = i32Sum = 0;
  for(i32Loop = 1; i32Loop <= (i32Number >> 1); ++i32Loop)
  {
    if((i32Number % i32Loop) == 0)
    {
      pi32DivisorList[i32DivIndex++] = i32Loop;
      i32Sum += i32Loop;
    }
  }

  if(i32Sum <= i32Number)
  {
    result = 1;
    goto out;
  }
  else
  {
    itr_count = power_of_x(2, i32DivIndex);
    itr_count /= 4;
    i32SumL1 = 0;
    i32SumL2 = itr_count;
    i32SumL3 = (i32SumL2 * 2);
    i32SumL4 = (i32SumL2 * 3);
    for( ; i32SumL1 < itr_count; ++i32SumL1, ++i32SumL2, ++i32SumL3, ++i32SumL4)
    {
      if(get_summation(i32SumL1, pi32DivisorList, i32DivIndex) == i32Number)
      {
        result = 1;
        goto out;
      }
      if(get_summation(i32SumL2, pi32DivisorList, i32DivIndex) == i32Number)
      {
        result = 1;
        goto out;
      }
      if(get_summation(i32SumL3, pi32DivisorList, i32DivIndex) == i32Number)
      {
        result = 1;
        goto out;
      }
      if(get_summation(i32SumL4, pi32DivisorList, i32DivIndex) == i32Number)
      {
        result = 1;
        goto out;
      }
    }
  }


out:
  free(pi32DivisorList);

  return result;
}

int main(int argc, char * argv[])
{
  int i32TestCount;
  int *pi32TestCases;
  int i32CaseLoop;

  scanf("%d", &i32TestCount);
  pi32TestCases = (int*) malloc(i32TestCount * sizeof(int));

  for(i32CaseLoop = 0; i32CaseLoop < i32TestCount; ++i32CaseLoop)
  {
    scanf("%d", &pi32TestCases[i32CaseLoop]);
  }

  for(i32CaseLoop = 0; i32CaseLoop < i32TestCount; ++i32CaseLoop)
  {
    if(is_it_weird_numer(pi32TestCases[i32CaseLoop]))
    {
      printf("not weird\n");
    }
    else
    {
      printf("weird\n");
    }
  }

  return(0);
}

