#include <iostream>

using namespace std;
#define MAX_VALUE 100
int ladder[MAX_VALUE][MAX_VALUE];
int x = -1;

void DFS(int hereX, int hereY)
{
    if(x != -1)
        return;

    if(hereX == 0)
    {
        x = hereY;
        return;
    }

    ladder[hereX][hereY] = 0;

    // Right
    if(hereY+1 < MAX_VALUE)
    {
        if(ladder[hereX][hereY+1] == 1)
        {
            DFS(hereX, hereY+1);
        }
    }
    // Left
    if(hereY-1 >= 0)
    {
        if(ladder[hereX][hereY-1] == 1)
        {
            DFS(hereX, hereY-1);
        }
    }
    // Up
    if(hereX-1 >= 0)
    {
        if(ladder[hereX-1][hereY] != 0)
        {
            DFS(hereX-1, hereY);
        }
    }
}

int main()
{
    int T = 0;

    for(int iter=0; iter<10; iter++)
    {
        int startX = 0, startY = 0;
        x = -1;
        std::cin >> T;

        for(int i=0; i<MAX_VALUE; i++)
        {
            for(int j=0; j<MAX_VALUE; j++)
            {
                std::cin >> ladder[i][j];

                if(ladder[i][j] == 2)
                {
                    startX = i;
                    startY = j;
                }
            }
        }
        DFS(startX, startY);
        std::cout << "#" << T << " " << x << endl;
    }
}