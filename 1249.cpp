#include <iostream>
#include <climits>
#include <queue>

using namespace std;
int map[101][101] = { 0 };
int dist[101][101];
int coord[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

int findRoad(int N, int startX, int startY)
{
    priority_queue<pair<int, pair<int, int>>> pq;
    dist[startX][startY] = 0;
    pq.push( {-dist[startX][startY], {startX, startY}} );

    while(!pq.empty())
    {
        int hereD = -pq.top().first;
        int hereX = pq.top().second.first;
        int hereY = pq.top().second.second;
        pq.pop();

        // 만약 지금 꺼낸 것보다 더 짧은 경로를 알고 있다면 지금 꺼낸 것을 무시
        if(hereD > dist[hereX][hereY])
            continue;

        // 인접한 칸 모두 검사
        for(int i=0; i<4; i++)
        {
            int nextX = hereX + coord[i][0];
            int nextY = hereY + coord[i][1];
            int nextD = hereD + map[nextX][nextY];

            if(nextX >= 0 && nextX < N && nextY >= 0 && nextY < N)
            {
                // 더 짧은 경로를 발견하면, dist[][] 갱신하고 우선순위 큐에 삽입
                if(nextD < dist[nextX][nextY])
                {
                    dist[nextX][nextY] = nextD;
                    pq.push( {-dist[nextX][nextY], {nextX, nextY}});
                }
            }
        }
    }
    // 도착 지점의 distance 반환
    return dist[N-1][N-1];
}

int main()
{
    int T = 0, N = 0;
    std::cin >> T;

    for(int i=0; i<T; i++)
    {
        std::cin >> N;

        for(int x=0; x<N; x++)
        {
            string input;
            std::cin >> input;

            for(int y=0; y<N; y++)
            {
                map[x][y] = input[y]-'0';
                dist[x][y] = INT_MAX;
            }
        }

        int minD = findRoad(N, 0, 0);

        std::cout << "#" << i+1 << " " << minD << endl;

        for(int x=0; x<101; x++)
        {
            for(int y=0; y<101; y++)
            {
                map[x][y] = 0;
            }
        }
    }
}