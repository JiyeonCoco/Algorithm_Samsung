#include <iostream>
#include <climits>
#include <queue>

using namespace std;
int map[101][101] = { 0 };
int minDist = INT_MAX, minIdx = -1;

void findRoad(int startX, int startY, bool (*visited)[101], int curD)
{
    visited[startX][startY] = true;

    if(curD > minDist)
        return;

    if(startX == 0)
    {
        minDist = min(minDist, curD);
        if(minDist == curD)
            minIdx = startY;
        return;
    }

    if(map[startX][startY-1] == 1 && startY-1 >= 0 && !visited[startX][startY-1])
        findRoad(startX, startY-1, visited, curD+1);
    else if(map[startX][startY+1] == 1 && startY+1 < 100 && !visited[startX][startY+1])
        findRoad(startX, startY+1, visited, curD+1);
    else if(map[startX-1][startY] == 1 && startX-1 >= 0 && !visited[startX-1][startY])
        findRoad(startX-1, startY, visited, curD+1);
}

int main()
{
    for(int iter=0; iter<10; iter++)
    {
        int T = 0;
        minDist = INT_MAX, minIdx = -1;
        std::cin >> T;

        for(int x=0; x<100; x++)
        {
            for(int y=0; y<100; y++)
            {
                std::cin >> map[x][y];
            }
        }

        for(int i=0; i<100; i++)
        {
            if(map[99][i] == 1)
            {
                bool visited[101][101] = { false };
                findRoad(99, i, visited, 0);
            }
        }

        std::cout << "#" << T << " " << minIdx << endl;
    }
}