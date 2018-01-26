#include <iostream>

using namespace std;

#define SWAP_INT(_X_,_Y_)   \
    {                       \
        int t = _X_;        \
        _X_ = _Y_;          \
        _Y_ = t;            \
    }

void PrintIntList(const int * pList, int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << pList[i] << ' ';
    }
    cout << "\n";
}

void DoQuickSort(int * pList, int low, int high)
{
    if(low >= high)
        return;

    int m = low + ((high - low) >> 1);
    
    if(pList[m] < pList[low])
    {
        SWAP_INT(pList[m], pList[low]);
    }
    if(pList[high] < pList[low])
    {
        SWAP_INT(pList[high], pList[low]);
    }
    if(pList[high] < pList[m])
    {
        SWAP_INT(pList[high], pList[m]);
    }

    int pivot = pList[m];
    int i, j;

    for(i = low, j = high - 1; i < j; )
    {
        while (pList[i] < pivot)
            i++;

        while(pivot < pList[j])
            j--;

        if(i < j)
        {
            SWAP_INT(pList[i], pList[j]);
            i++;
            j--;
        }
        else
        {
            break;
        }
    }
    SWAP_INT(pList[i], pList[high]);
    DoQuickSort(pList, low, i-1);
    DoQuickSort(pList, i+1, high);
}

void QuickSort(int * pList, int size)
{
    DoQuickSort(pList, 0, size-1);
}

int main()
{
    int ai32List[] = { 9,4,5,3,6,2,8,7,1, 0 };

    PrintIntList(ai32List, (sizeof(ai32List)/ sizeof(ai32List[0])));
    QuickSort(ai32List, (sizeof(ai32List)/ sizeof(ai32List[0])));
    PrintIntList(ai32List, (sizeof(ai32List)/ sizeof(ai32List[0])));
}