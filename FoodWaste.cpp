#include <iostream>
#include <vector>

using namespace std;

// aisle : 통로 , coordinate : 통로 상에서의 음식물 쓰레기 위치 좌표
// matrix : 음식물 쓰레기들에 대한 인접 그래프
// maxvalue : 최대 음식물 쓰레기 크기
// cnt : 깊이 우선 탐색 시 탐색한 정점의 개수
int aisle[100][100] = { 0 };
vector<vector<int>> coordinate;
vector<vector<int>> matrix;
vector<int> seen;
int maxvalue, cnt = 0;

// matrix 행렬 생성
void makeGraph(int K)
{
    matrix = vector<vector<int>>(K, vector<int>(K, 0));

    for(int i=0; i<K; i++)
    {
        for (int j=0; j<K; j++)
        {
            // 현재 정점과 좌표 상으로 인접하다면 1. 아니면 0
            if((coordinate[i][0]-1 == coordinate[j][0] && coordinate[i][1] == coordinate[j][1]) ||
                (coordinate[i][0]+1 == coordinate[j][0] && coordinate[i][1] == coordinate[j][1]) ||
                (coordinate[i][0] == coordinate[j][0] && coordinate[i][1]-1 == coordinate[j][1]) ||
                (coordinate[i][0] == coordinate[j][0] && coordinate[i][1]+1 == coordinate[j][1])
            )
            {
                matrix[j][i] = 1;
            }
        }
    }
}

// 깊이 우선 탐색
void DFS(int K, int here)
{
    seen[here] = 1;
    cnt++;

    for(int there=0; there<K; there++)
    {
        if(matrix[here][there] == 1 && seen[there] == 0)
        {
            DFS(K, there);
        }
    }
}

// 가장 큰 음식물 쓰레기 크기 탐색
void findBiggest(int K)
{
    seen = vector<int>(K, 0);

    for(int i=0; i<K; i++)
    {
        if(seen[i] == 0)
        {
            cnt = 0;
            DFS(K, i);

            // DFS 시 탐색한 정점의 개수(=음식물 쓰레기 크기)가 기존의 최대 음식물 쓰레기 보다 크다면 값 교체
            if(cnt >= maxvalue)
                maxvalue = cnt;
        }
    }

    std::cout << maxvalue << endl;
}

int main()
{
    int N, M, K = 0;
    int x, y = 0;

    std::cin >> N >> M >> K;

    coordinate = vector<vector<int>>(K, vector<int>(2, 0));

    for(int i=0; i<K; i++)
    {
        std::cin >> x >> y;
        aisle[y-1][x-1] = 1;

        coordinate[i][0] = x;
        coordinate[i][1] = y;
    }

    makeGraph(K);
    findBiggest(K);
}