#include <stdio.h>
#include <stdlib.h>

#define MAX_CANDIDATE   (5)
#define MAX_GROUP       (20)
#define MAX_POPULATION  (20)

static int gai8GroupMemCount[MAX_GROUP][MAX_CANDIDATE];
static int gai8Votes[MAX_CANDIDATE + 1];

void ReadValues(int *pArr, int len)
{
   char temp;
   while(len--)
   {
      scanf("%d%c", pArr++, &temp);
   }
}

void RemoveCandidate(int cand, int N, int G)
{
   int temp;
   int cand_loop;
   int *pG;

   while(G)
   {
      pG = &gai8GroupMemCount[G-1][0];
      for(cand_loop = 1; cand_loop <= N; ++cand_loop)
      {
         if(pG[cand_loop] == cand)
         {
            break;
         }
      }
      ++cand_loop;
      while(cand_loop <= N)
      {
         pG[cand_loop-1] = pG[cand_loop];
      }
      --G;
   }
}

int main(int argc, char *argv[])
{
   int G,N;
   int G_loop;
   int round;
   int cand_loop;
   int *pG;
   int looser, looser_vote;
   int max_round;
   
   do
   {
      scanf("%d %d", &G, &N);
      if(N == 0)
      {
         break;
      }
      for(G_loop = 0; G_loop < G; ++G_loop)
      {
         ReadValues(&gai8GroupMemCount[G_loop][0], (N + 1));
      }
      max_round = (N);
      for(round =0; round < max_round; ++round)
      {
         for(G_loop = 0; G_loop < G; ++G_loop)
         {
            pG = &gai8GroupMemCount[G_loop][0];
            memset(pG, 0, (sizeof(int) * N));
            for(cand_loop = 1; cand_loop <= (N - round); ++cand_loop)
            {
               gai8Votes[pG[cand_loop]] += ((pG[cand_loop] - round) * pG[0]);
            }
         }
         looser = -1; looser_vote = 0;
         for(cand_loop = 1; cand_loop <= N; ++cand_loop)
         {
            if(looser_vote <= gai8Votes[cand_loop])
            {
               looser = cand_loop;
               looser_vote = gai8Votes[cand_loop];
            }
         }
         RemoveCandidate(looser, N, G);
         --N;
      }
      printf("%d\n",pG[0]);
   } while(1);

   return 0;
}
