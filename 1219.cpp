#include <iostream>

using namespace std;
int size[101][2] = { 0 };
bool visited[100] = { false };
int ok = 0;

void DFS(int here)
{
    visited[here] = true;

    for(int i=0; i<2; i++)
    {
        int there = size[here][i];
        if(there != 0 && !visited[there])
        {
            if(there == 99)
            {
                ok = 1;
                return;
            }
            DFS(there);
        }
    }
}

int main()
{
    for(int iter=0; iter<10; iter++)
    {
        int T = 0, R = 0;
        ok = 0;
        std::cin >> T >> R;

        for(int i=0; i<R; i++)
        {
            int V1, V2;
            std::cin >> V1 >> V2;
            if(size[V1][0] != 0)
                size[V1][1] = V2;
            else
                size[V1][0] = V2;
        }

        DFS(0);
        std::cout << "#" << T << " " << ok << endl;

        for(int i=0; i<100; i++)
        {
            for(int j=0; j<2; j++)
            {
                size[i][j] = 0;
            }
            visited[i] = false;
        }
    }
}