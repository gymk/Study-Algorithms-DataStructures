#include <stdio.h>
#include <stdlib.h>

int sme_validate(int *pArr, int i32Number, int sum, int start_index)
{
  char loop;

  if((sum + pArr[start_index]) == i32Number)
  {
    return 1;
  }
  if((sum + pArr[start_index+1]) == i32Number)
  {
    return 1;
  }
  if((sum + pArr[start_index+2]) == i32Number)
  {
    return 1;
  }
  if((sum + pArr[start_index] + pArr[start_index+1]) == i32Number)
  {
    return 1;
  }
  if((sum + pArr[start_index+1] + pArr[start_index+2]) == i32Number)
  {
    return 1;
  }
  if((sum + pArr[start_index] + pArr[start_index+1] + pArr[start_index+2]) == i32Number)
  {
    return 1;
  }
  return (0);
}

{
}

int is_it_weird_numer(int i32Number)
{
  int *pi32DivisorList;
  int i32DivLoop;
  int i32DivIndex;

  int i32Sum;

  int i32Result = 1;

  int set, j;
  int swap_loop, swap_post;

  pi32DivisorList = (int*) malloc(((i32Number >> 1)+1) * sizeof(int));

  i32DivIndex = i32Sum = 0;
  for(i32DivLoop = 0; i32DivLoop < i32Number >> 1); ++i32DivLoop)
  {
    if((i32Number % i32DivIndex) == 0)
    {
      pi32DivisorList[i32DivIndex++] = i32DivLoop;
      i32Sum += i32DivLoop;
    }
  }

  if(i32Sum <= i32Number)
  {
    i32Result = 0;
    goto out;
  }
  else
  {
    for(set = 1; set < i32DivIndex; ++set)
    {
      for(swap_loop = (set - 1); swap_loop < (i32DivIndex - 1); ++swap_loop)
      {
        i32Sum = pi32DivisorList[0];
        pi32DivisorList[0] = pi32DivisorList[swap_loop];
        pi32DivisorList[swap_loop] = i32Sum;
        i32Sum = 0;
        for(j = 0; j < set; j++)
        {
          i32Sum += pi32DivisorList[j];
        }
        for(j = (swap_loop+1); j < i32DivIndex; ++j)
        {
          if((i32Sum + pi32DivisorList[j]) == i32Number)
          {
            i32Result = 0;
            goto out;
          }
        }
      }
    }
  }


out:
  free(pi32DivisorList);

  return i32Result;
}

int main(int argc, char * argv[])
{
  int i32TestCount;
  int *pi32TestCases;
  int i32CaseLoop;
  int i32Result;

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
      printf("weird\n");
    }
    else
    {
      printf("not weird\n");
    }
  }

  return(0);
}

