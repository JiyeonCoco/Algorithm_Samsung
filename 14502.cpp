#include <iostream>
#include <queue>

using namespace std;
int N = 0, M = 0;
int map[8][8] = { -1 };
int temp[8][8] = { -1 };
int spreadTemp[8][8]  = { -1 };
int maxSafe = 0;
int coord[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

void mapCopy(int (*a)[8], int (*b)[8])
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            a[i][j] = b[i][j];
        }
    }
}

void countSafe()
{
    int cnt = 0;

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(spreadTemp[i][j] == 0)
                cnt++;
        }
    }

    maxSafe = max(maxSafe, cnt);
}

void spreadVirus()
{
    mapCopy(spreadTemp, temp);
    queue<pair<int, int>> q;

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(temp[i][j] == 2)
            {
                q.push({i, j});
            }
        }
    }

    while(!q.empty())
    {
        int hereX = q.front().first;
        int hereY = q.front().second;
        q.pop();

        for(int i=0; i<4; i++)
        {
            int nextX = hereX + coord[i][0];
            int nextY = hereY + coord[i][1];

            if(nextX >= 0 && nextX < N && nextY >= 0 && nextY < M && spreadTemp[nextX][nextY] == 0)
            {
                q.push({nextX, nextY});
                spreadTemp[nextX][nextY] = 2;
            }
        }
    }
}

void DFS(int cnt)
{
    if(cnt == 3)
    {
        spreadVirus();
        countSafe();
        return;
    }

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(temp[i][j] == 0)
            {
                temp[i][j] = 1;
                DFS(cnt+1);
                temp[i][j] = 0;
            }
        }
    }
}

int main()
{
    std::cin >> N >> M;

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            std::cin >> map[i][j];
        }
    }

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(map[i][j] == 0)
            {
                mapCopy(temp, map);
                temp[i][j] = 1;
                DFS(1);
                temp[i][j] = 0;
            }
        }
    }

    std::cout << maxSafe << endl;

}