#include <stdio.h>
#include <stdlib.h>

#define MAX_CASES    (50)
#define MAX_ENTRY    (500)

static int gai32FinalResults[MAX_CASES + 1];
static int gai32Entry[MAX_ENTRY + 1];
static int gai32IntermResults[MAX_ENTRY + 1];

int GetLIS(int *pList, int val, int index, int len)
{
   int loop;
   int result1, result2;

   if(index >= len)
   {
      return 0;
   }
   
   result1 = result2 = 0;
   for(loop = index; loop < len; ++loop)
   {
      if(val < pList[loop])
      {
         if(gai32IntermResults[loop] == -1)
         {
            result2 = 1 + GetLIS(pList, pList[loop], loop + 1, len);
            gai32IntermResults[loop] = result2;
         }
         else
         {
            result2 = 1 + gai32IntermResults[loop];
         }
      }
      else
      {
         result2 = GetLIS(pList, val, loop + 1, len);
      }
      if(result1 < result2)
      {
         result1 = result2;
      }
   }

   return result1;
}

int main(int argc, char *argv[])
{
   int i32NoOfCases;
   int i32NoOEntry;
   int case_loop;
   int entry_loop;
   char temp;
   int result;
   
   int *pEntry;
   
   scanf("%d",&i32NoOfCases);
   for(case_loop = 0; case_loop < i32NoOfCases; ++case_loop)
   {
      scanf("%d", &i32NoOEntry);
      for(entry_loop = 0; entry_loop < i32NoOEntry; ++entry_loop)
      {
         scanf("%d%c", &gai32Entry[entry_loop], &temp);
         gai32IntermResults[entry_loop]=-1;
      }
      result = 0;
      for(entry_loop = 0; entry_loop < i32NoOEntry; ++entry_loop)
      {
         if(gai32IntermResults[entry_loop] == -1)
         {
            gai32IntermResults[entry_loop] = GetLIS(gai32Entry, gai32Entry[entry_loop], entry_loop + 1, i32NoOEntry);
         }
         printf("\ngai32IntermResults[%d] - %d\n", gai32IntermResults[entry_loop]);

         if(result < gai32IntermResults[entry_loop])
         {
            result = gai32IntermResults[entry_loop];
         }
      }
      gai32FinalResults[case_loop] = result;
   }
   
   for(case_loop = 0; case_loop < i32NoOfCases; ++case_loop)
   {
      printf("%d\n", gai32FinalResults[case_loop] + 1);
   }
   
   getchar();
   return 0;
}
