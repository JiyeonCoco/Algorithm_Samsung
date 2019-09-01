#include <iostream>
#include <vector>

using namespace std;

#define MAX_NUM 50
int field[MAX_NUM+2][MAX_NUM+2] = { 0 };
vector<vector<int>> seen;

void dfs(int hereX, int hereY)
{
    seen[hereX][hereY] = 1;

    for(int i=0; i<4; i++)
    {
        if(field[hereX-1][hereY] == 1 && seen[hereX-1][hereY] == 0)
            dfs(hereX-1, hereY);
        else if(field[hereX+1][hereY] == 1 && seen[hereX+1][hereY] == 0)
            dfs(hereX+1, hereY);
        else if(field[hereX][hereY-1] == 1 && seen[hereX][hereY-1] == 0)
            dfs(hereX, hereY-1);
        else if(field[hereX][hereY+1] == 1 && seen[hereX][hereY+1] == 0)
            dfs(hereX, hereY+1);
    }
}

void searching(int width, int height, int worm)
{
    seen = vector<vector<int>>(height+2, vector<int>(width+2, 0));

    for(int i=1; i<=height; i++)
    {
        for(int j=1; j<=width; j++)
        {
            if(seen[i][j] == 0 && field[i][j] == 1)
            {
                dfs(i, j);
                worm++;
            }
        }
    }
    std::cout << worm << endl;
}

int main()
{
    int T, M, N, K = 0;
    int cabbageX, cabbageY = 0;

    std::cin >> T;

    for(int i=0; i<T; i++)
    {
        std::cin >> M >> N >> K;

        int worm = 0;
        seen.clear();

        for(int j=0; j<K; j++)
        {
            std::cin >> cabbageX >> cabbageY;
            field[cabbageY+1][cabbageX+1] = 1;
        }

        searching(M+2, N+2, worm);

        for(int x=0; x<N+2; x++)
        {
            for(int y=0; y<M+2; y++)
            {
                field[x][y] = 0;
            }
        }
    }
}