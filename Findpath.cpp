#include <iostream>
#include <vector>
#include <string>

using namespace std;

// matrix[][]    : 입력으로 받은 그래프의 인접 행렬
// newMatrix[][] : 경로의 유무를 판단하여 출력할 행렬
// seen          : 해당 정점을 이미 탐색했다면 1, 아니라면 0
const int MAX_SIZE = 100;
int matrix[MAX_SIZE][MAX_SIZE] = { 0 };
int newMatrix[MAX_SIZE][MAX_SIZE] = { 0 };
vector<int> seen;

// 깊이 우선 탐색
void DFS(int N, int start, int here, int end)
{
    for(int there=0; there<N; there++)
    {
        // 현재 정점(here)에서 다음 정점(there)로 가는 간선이 있고,
        // 다음 정점이 탐색의 끝점인 경우 newMatrix 값 지정 후 종료
        if(matrix[here][there] == 1 && there == end)
        {
            newMatrix[start][end] = 1;
            break;
        }
        // 현재 정점(here)에서 다음 정점(there)로 가는 간선이 있지만,
        // 다음 정점이 끝점이 아니고, 해당 정점을 아직 탐색한 적이 없다면 다시 DFS 호출
        if(matrix[here][there] == 1 && seen[there] == 0)
        {
            seen[there] = 1;
            DFS(N, start, there, end);
        }
    }
}

// 경로가 있는지 탐색
void Searching(int N, int start, int end)
{
    seen[start] = 1;

    // 시작점에서 끝점으로 바로 가는 간선이 있다면
    if(matrix[start][end] == 1)
    {
        newMatrix[start][end] = 1;
    }
    // 바로 가는 간선이 없다면 경로 탐색 (DFS)
    else
    {
        DFS(N, start, start, end);
    }
}

// newMatrix를 생성
void makeMatrix(int N)
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            seen = vector<int>(N, 0);
            Searching(N, i, j);
        }
    }
}

int main()
{
    int N = 0; // 1 <= N <= 100
    string input;

    std::cin >> N;

    // 그래프의 인접 행렬 값 입력 받아 생성
    for (int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            std::cin >> matrix[i][j];
        }
    }

    makeMatrix(N);

    // newMatrix 출력
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            std::cout << newMatrix[i][j] << " ";
        }
        std::cout << endl;
    }
}