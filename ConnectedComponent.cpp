#include <iostream>
#include <vector>

using namespace std;

int matrix[1000][1000] = { 0 };
int cnt = 1;
vector<int> seen;

void DFS(int N, int here)
{
    seen[here] = 1;

    for(int there=0; there<N; there++)
    {
        if(matrix[here][there] == 1 && seen[there] == 0)
        {
            DFS(N, there);
        }
    }
}

void checkCnt(int N)
{
    for(int i=0; i<N; i++)
    {
        if(seen[i] == 0)
        {
            DFS(N, i);

            for(int check=0; check<N; check++)
            {
                // 탐색하지 않은 정점이 있다면 Cnt+1
                if(seen[check] == 0)
                {
                    cnt++;
                    break;
                }
            }
        }
    }
    std::cout << Cnt << endl;
}

int main()
{
    int N, M = 0; // N:정점 , M:간선
    int input[2];

    std::cin >> N >> M;
    seen = vector<int>(N, 0);

    for(int i=0; i<M; i++)
    {
        std::cin >> input[0] >> input[1];
        input[0]--;
        input[1]--;

        matrix[input[0]][input[1]] = 1;
        matrix[input[1]][input[0]] = 1;
    }

    checkCnt(N);
}