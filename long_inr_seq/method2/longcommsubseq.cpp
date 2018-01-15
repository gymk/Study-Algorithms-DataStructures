/*
 * http://www.cs.umd.edu/~meesh/351/mount/lectures/lect25-longest-common-subseq.pdf
 *
 * t = ABRACADABRA
 * p = YABBADABBADOO
 * lcs = ABADABA
 *
 * t = BDCB
 * p = BACDB
 * lcs = BCB
 *
 * LCS Table
 *      B D C B
 *    0 0 0 0 0
 * B  0 1 1 1 1
 * A  0 1 1 1 1
 * C  0 1 1 2 2
 * D  0 1 2 2 2
 * B  0 1 2 2 3
 *
 * 1) t len can be less than p
 * 2) LCS is not always unique. For example, the LCS of <ABC> and <BAC> is either <AC> or <BC>
 * 3) LCS of 't and p' and LCS of 'p and t' will be differentI. So comparing with which is important
 *      Example:
 *          t = ABAZDC
 *          p = BACBAD
 *          LCS<t,p> ==> ABAD
 *          LCS<p,t> ==> BAC
 */

#include "stdio.h"
#include "stdlib.h"

#define MAX(_A_,_B_)    ((_A_ > _B_) ? _A_ : _B_)

int getstrlen(const char * s)
{
    int len = 0;

    printf("%s> %p %s\n", __FUNCTION__, s, s);

    while(*s)
    {
        s++;    len++;
    }

    return len;
}

int** Get2dArray(int r, int c)
{
    int ** pA = NULL;

    pA = (int**) malloc(sizeof(int*) * r);
    if(pA != NULL)
    {
        pA[0] = (int*) malloc(sizeof(int) * c * r);
        if(pA[0] == NULL)
        {
            printf("%s %d> Malloc Failed\n", __FUNCTION__, __LINE__ );
            free(pA);
            pA = NULL;
        }
        else
        {
            int i;
            for(i = 1; i < r; i++)
            {
                pA[i] = pA[0] + (i * c);
            }
        }
    }
    else
    {
        printf("%s %d> Malloc Failed\n", __FUNCTION__, __LINE__ );
    }

    return pA;
}

void Free2dArray(int ** ppi32A)
{
    if(ppi32A != NULL)
    {
        free(ppi32A[0]);
        free(ppi32A);
    }
}

enum tagDirection
{
        ADDXY = 1
    ,   SKIPX
    ,   SKIPY
};

//int main(int argc, char * argv[])
int test_dp_log_comm_subseq(void)
{
    //const char * s1 = argv[1];
    //const char * s2 = argv[2];
    //const char * s1 = "ABRACADABRA";
    //const char * s2 = "YABBADABBADOO";
    //const char * s1 = "BDCB";
    //const char * s2 = "BACDB";
    const char * s1 = "ABC";
    const char * s2 = "BAC";

    int s1len = getstrlen(s1);
    int s2len = getstrlen(s2);
    int max = MAX(s1len, s2len);
    int i, j;
    int ** pDp;
    char * pOutStr;
    int ** pTraceTable;

    pOutStr = (char*) malloc(sizeof(char) * max+1);
    if(pOutStr == NULL)
    {
        printf("No memory to allocate OutStr...\n");
        return -1;
    }

    pDp = Get2dArray(s2len+1, s1len+1);
    if(pDp == NULL)
    {
        printf("No memory to allocate DP Table...\n");
        return -1;
    }

    pTraceTable = Get2dArray(s2len+1, s1len+1);
    if(pTraceTable == NULL)
    {
        printf("No memory to allocate DP Table...\n");
        return -1;
    }

    for(i = 0; i <= s2len; i++)
    {
        pDp[i][0] = 0;   pTraceTable[i][0] = SKIPX;
    }
    for(j = 0; j <= s1len; j++)
    {
        pDp[0][j] = 0;   pTraceTable[0][j] = SKIPY;
    }

    for(i = 1; i <= s2len; i++)
    {
        for(j = 1; j <= s1len; j++)
        {
            if(s2[i-1] == s1[j-1])
            {
                pDp[i][j] = 1 + pDp[i-1][j-1];
                pTraceTable[i][j] = ADDXY;
            }
            else
            {
                if(pDp[i-1][j] > pDp[i][j-1])
                {
                    pDp[i][j] =  pDp[i-1][j];
                    pTraceTable[i][j] = SKIPX;
                }
                else
                {
                    pDp[i][j] =  pDp[i][j-1];
                    pTraceTable[i][j] = SKIPY;
                }
            }
        }
    }

    printf("DpTable:\n");
    for(i = 0; i <= s2len; i++)
    {
        for(j = 0; j <= s1len; j++)
        {
            printf("%d ", pDp[i][j]);
        }
        printf("\n");
    }

    printf("TraceTable:\n");
    for(i = 0; i <= s2len; i++)
    {
        for(j = 0; j <= s1len; j++)
        {
            printf("%d ", pTraceTable[i][j]);
        }
        printf("\n");
    }

    if(pDp[s2len][s1len])
    {
        int lcsIndex = pDp[s2len][s1len];
        pOutStr[lcsIndex--] = '\0';
        i = s2len;
        j = s1len;
        printf("LCS Size - %d\n", lcsIndex+1);
        while((i != 0) && (j != 0))
        {
            switch(pTraceTable[i][j])
            {
            case ADDXY:
                    pOutStr[lcsIndex--] = s2[i-1];
                    i--; j--;
                    break;
            case SKIPX:
                    i--;
                    break;
            case SKIPY:
                    j--;
                    break;
                default:
                    printf("%d %d %d\n", i, j, pTraceTable[i][j]);
                    i = 0;
                    break;
            }
        }
        printf("LCS - %s\n", pOutStr);
    }
    else
    {
        printf("No LCS found...\n");
    }

    Free2dArray(pDp);
    free(pOutStr);

    return 0;
}
