#include <stdio.h>
#include <stdlib.h>

#define MAX_TEST_CASES (1000)

static int gai32TestCases[MAX_TEST_CASES];
static int gai32Result[MAX_TEST_CASES];

int GetSetCount(int max_width, int max_height, int *pCount, int width, int height, int level)
{
    int level_loop;

    printf("\n");
    for(level_loop = 0; level_loop < level; ++level_loop)
    {
      printf("     ");
    }
    printf(" (%d, %d) ", width, height);
    if((width != 0) && (height != 0))
    {
       if((width % 2) == 1)
       {
          /* ==> towards WIDTH */
          /* (1, 2) ==> Vertical Tile */
          if((width + 1) <= max_width)
          {
             GetSetCount(max_width, max_height, pCount, width + 1, height, level + 1);
          }
          /* (2, 1) ==> Horizontal Tile */
          if((width + 2) <= max_width) 
          {
             GetSetCount(max_width, max_height, pCount, width + 2, height, level + 1);
          }
       }
       else
       {
         /* ==> towards WIDTH */
         /* (1, 2) */
         if(((width + 1) <= max_width) && ((height + 2) <= max_height))
         {
            GetSetCount(max_width, max_height, pCount, width + 1, height + 2, level + 1);
         }
         /* (2, 1) */
         if(((width + 2) <= max_width) && ((height + 1) <= max_height)) 
         {
            GetSetCount(max_width, max_height, pCount, width + 2, height + 1, level + 1);
         }
       }
       if((height % 2) == 1)
       {
         /* towards HEIGHT */
         /* (2, 1 ) ==> Horizontal Tile */
         if((height + 1) <= max_height)
         {
            GetSetCount(max_width, max_height, pCount, width, height + 1, level + 1);
         }
         /* (1, 2) ==> Vertical Tile */
         if((height + 2) <= max_height)
         {
            GetSetCount(max_width, max_height, pCount, width, height + 2, level + 1);
         }
       }
       else
       {
         /* towards HEIGHT */
         /* (1, 2 ) */
         if(((height + 1) <= max_height) && ((width + 2) <= max_width))
         {
            GetSetCount(max_width, max_height, pCount, width + 2, height + 1, level + 1);
         }
         /* (2, 1) */
         if(((height + 2) <= max_height) && ((width + 1) <= max_width))
         {
            GetSetCount(max_width, max_height, pCount, width + 1, height + 2, level + 1);
         }
       }
    }
    else
    {
         /* ==> towards WIDTH */
         /* (1, 2) */
         if(((width + 1) <= max_width) && ((height + 2) <= max_height))
         {
            GetSetCount(max_width, max_height, pCount, width + 1, height + 2, level + 1);
         }
         /* (2, 1) */
         if(((width + 2) <= max_width) && ((height + 1) <= max_height)) 
         {
            GetSetCount(max_width, max_height, pCount, width + 2, height + 1, level + 1);
         }
         /* towards HEIGHT */
         /* (1, 2 ) */
         if(((height + 1) <= max_height) && ((width + 2) <= max_width))
         {
            GetSetCount(max_width, max_height, pCount, width + 2, height + 1, level + 1);
         }
         /* (2, 1) */
         if(((height + 2) <= max_height) && ((width + 1) <= max_width))
         {
            GetSetCount(max_width, max_height, pCount, width + 1, height + 2, level + 1);
         }
    }
    /* WIDTH full, still height */
    if((width == max_width) && ((height + 2) <= max_height))
    {
       GetSetCount(max_width, max_height, pCount, width, height + 2, level + 1);
    }
    /* HEIGHT full, still width */
    if((height == max_height) && ((width + 2) <= max_width))
    {
       GetSetCount(max_width, max_height, pCount, width + 2, height, level + 1);
    }
    /* WIDTH and HEIGHT are FULL - Increase count */
    if((width == max_width) && (height == max_height))
    {
       *pCount = *pCount + 1;
       printf("SET");
    }
}

int GetSetCount1(int max_width, int max_height, int *pCount, int width, int height)
{
    if(((width + 1) <= max_width) && ((height + 2) <= max_height))
    {
       GetSetCount1(max_width, max_height, pCount, width + 1, height + 2);
    }
    if(((width + 2) <= max_width) && ((height + 1) <= max_height))
    {
       GetSetCount1(max_width, max_height, pCount, width + 2, height + 1);
    }
    if((width == max_width) && (height == max_height))
    {
       *pCount = *pCount + 1;
    }
}

int main(int argc, char *argv[])
{
   int i32TestCount;
   int case_loop;

   scanf("%d", &i32TestCount);
   for(case_loop = 0; case_loop < i32TestCount; ++case_loop)
   {
      scanf("%d", &gai32TestCases[case_loop]);
      gai32Result[case_loop] = 0;
      GetSetCount(gai32TestCases[case_loop], 4, &gai32Result[case_loop], 0, 0, 0);
   }
   
   for(case_loop = 0; case_loop < i32TestCount; ++case_loop)
   {
      printf("%d %d\n", (case_loop + 1), gai32Result[case_loop]);
   }
   
   return 0;
}
