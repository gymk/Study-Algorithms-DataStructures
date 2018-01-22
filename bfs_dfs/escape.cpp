/* https://community.topcoder.com/stat?c=problem_statement&pm=1170&rd=4371 */

/* Yet to Complete */

#include <iostream>
#include <sstream> 
#include <string>
#include <vector>

#define MAX_SIZE        (501)

using namespace std;

typedef enum tagType{
    NORMAL,
    HARMFUL,
    DEADLY
} TYPE;

TYPE ui32Board[MAX_SIZE][MAX_SIZE];
int aai32Life[MAX_SIZE][MAX_SIZE];
bool aabVisited[MAX_SIZE][MAX_SIZE];

void Fill(int x1, int y1, int x2, int y2, TYPE eTypeToFill)
{
    int r, c, t;

    // swap
    if(x1 > x2)
    {
        t = x1;
        x1 = x2;
        x2 = t;
    }
    if(y1 > y2)
    {
        t = y1;
        y1 = y2;
        y2 = t;
    }
    
    for(r = y1; r < y2; r++)
    {
        for(c = x1; c < x2; c++)
        {
            ui32Board[r][c] = eTypeToFill;
        }
    }
}

int BFS(int x, int y)
{
    int right, top, bottom;
    
    if((x < 0) || (x >= MAX_SIZE)) return (MAX_SIZE * MAX_SIZE);
    if((y < 0) || (y >= MAX_SIZE)) return (MAX_SIZE * MAX_SIZE);

    if(aabVisited[x][y])
        return aai32Life[x][y];
    
    aabVisited[x][y] = true;

    right = BFS(x, y+1);
    top = BFS(x-1, y);
    bottom = BFS(x+1, y);

    aai32Life[x][y] = min(right, top);
    aai32Life[x][y] = min(aai32Life[x][y], bottom);
    
    return aai32Life[x][y];
}

int lowest(vector<string> harmful, vector<string> deadly)
{
    int x1, y1, x2, y2, r, c;

    Fill(0, 0, MAX_SIZE, MAX_SIZE, NORMAL);
    for(r = 0; r < MAX_SIZE; r++)
    {
        for(c = 0; c < MAX_SIZE; c++)
        {
            aabVisited[r][c] = false;
            aai32Life[r][c] = (MAX_SIZE * MAX_SIZE);
        }
    }
    
    for(int i = 0; i < harmful.size(); i++)
    {
        stringstream in(harmful[i].c_str());
        in >> x1;
        in >> y1;
        in >> x2;
        in >> y2;

        Fill(x1, y1, x2, y2, HARMFUL);
    }

    for(auto dead : deadly)
    {
        stringstream in(dead);
        in >> x1;
        in >> y1;
        in >> x2;
        in >> y2;

        Fill(x1, y1, x2, y2, DEADLY);
    }

    return BFS(0, 0);
}

int main()
{   
    cout << "Empty: " << lowest({""}, {""}) << endl;
    cout << "Empty: " << lowest({"500 0 0 500"}, {"0 0 0 0"}) << endl;
    
    return 0;
}
