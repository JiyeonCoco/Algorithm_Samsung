#include <iostream>

using namespace std;
int N = 0, L = 0;
int roadCnt = 0;
int map[101][101] = { 0 };


void findRoadHor(int pos)
{
    bool visited[101][101] = { false };
    for(int i=0; i<N-1; i++)
    {
        // 둘의 차이가 1보다 클 때
        if(abs(map[pos][i] - map[pos][i+1]) > 1)
            return;

        if(abs(map[pos][i] - map[pos][i+1]) == 1)
        {
            // 왼쪽에 있는 칸이 더 높을 때
            if(map[pos][i] > map[pos][i+1])
            {
                for(int x=0; x<L; x++)
                {
                    if(visited[pos][i+1+x] == true)
                        return;
                    if(map[pos][i+1] != map[pos][i+1+x])
                        return;
                    if(i+1+x > N)
                        return;
                    visited[pos][i+1+x] = true;
                }

                if(i+1+L == N)
                {
                    roadCnt++;
                    return;
                }
            }

            // 오른쪽에 있는 칸이 더 높을 때
            else
            {
                for(int x=0; x<L; x++)
                {
                    if(visited[pos][i-x] == true)
                        return;
                    if(map[pos][i] != map[pos][i-x])
                        return;
                    if(i-x < 0)
                        return;
                    visited[pos][i-x] = true;
                }
                if(i+1 == N-1)
                {
                    roadCnt++;
                    return;
                }
            }

        }

        if(map[pos][i] == map[pos][i+1])
        {
            if(i == N-2)
            {
                roadCnt++;
                return;
            }
        }
    }
}

void findRoadVer(int pos)
{
    bool visited[101][101] = { false };
    for(int i=0; i<N-1; i++)
    {
        // 둘의 차이가 1보다 클 때
        if(abs(map[i][pos] - map[i+1][pos]) > 1)
            return;

        if(abs(map[i][pos] - map[i+1][pos]) == 1)
        {

            // 위에 있는 칸이 더 높을 때
            if(map[i][pos] > map[i+1][pos])
            {
                for(int x=0; x<L; x++)
                {
                    if(visited[i+1+x][pos] == true)
                        return;
                    if(map[i+1][pos] != map[i+1+x][pos])
                        return;
                    if(i+1+x > N)
                        return;
                    visited[i+1+x][pos] = true;
                }

                if(i+1+L == N)
                {
                    roadCnt++;
                    return;
                }
            }

            // 아래에 있는 칸이 더 높을 때
            else
            {
                for(int x=0; x<L; x++)
                {
                    if(visited[i-x][pos] == true)
                        return;
                    if(map[i][pos] != map[i-x][pos])
                        return;
                    if(i-x < 0)
                        return;
                    visited[i-x][pos] = true;
                }

                if(i+1 == N-1)
                {
                    roadCnt++;
                    return;
                }
            }

        }

        if(map[i][pos] == map[i+1][pos])
        {
            if(i == N-2)
            {
                roadCnt++;
                return;
            }
        }
    }
}

int main()
{
    std::cin >> N >> L;

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            std::cin >> map[i][j];
        }
    }

    for(int i=0; i<N; i++)
    {
        findRoadHor(i);
        findRoadVer(i);
    }

    std::cout << roadCnt << endl;

}