#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;
int field[100][100][2];

// Above, Bottom, Left, Right
const int dirType[4][2] =
        { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

struct group
{
    int gX;
    int gY
    int num;
    int dir;
} g[1000];

void moving(int N, int K)
{
    memset(field, 0, sizeof(field));

    for(int i=0; i<K; i++)
    {
        group &src = g[i];

        if(src.num == 0)
            continue;

        src.gX += dirType[src.dir-1][1];
        src.gY += dirType[src.dir-1][0];

        // 약품 셀에 닿은 경우
        if(src.gX == 0 || src.gX == N-1 || src.gY == 0 || src.gY == N-1)
        {
            src.num /= 2;

            if(src.dir % 2 == 0)
                src.dir -= 1;
            else
                src.dir += 1;
        }


        // 이동한 셀에 이미 다른 군집이 있을 경우
        if(field[src.gY][src.gX][0])
        {
            int idx = field[src.gY][src.gX][0];
            g[idx].num += src.num;

            if(src.num > field[src.gY][src.gX][1])
            {
                field[src.gY][src.gX][1] = src.num;
                g[idx].dir = src.dir;
            }

            src.num = 0;
        }
        else
        {
            field[src.gY][src.gX][0] = i;
            field[src.gY][src.gX][1] = src.num;
        }
    }
}

int main()
{
    int T, N, M, K = 0;

    std::cin >> T;

    for(int i=0; i<T; i++)
    {
        int answer = 0;
        memset(&g, 0, sizeof(g));
        int pX, pY, num, dir = 0;

        std::cin >> N >> M >> K;

        for(int j=0; j<K; j++)
        {
            std::cin >> pY >> pX >> num >> dir;
            g[j].gX = pX;
            g[j].gY = pY;
            g[j].num = num;
            g[j].dir = dir;
        }

        // M시간만큼 미생물 이동
        for(int t=0; t<M; t++)
        {
            moving(N, K);
        }

        for(int i=0; i<K; i++)
        {
            answer += g[i].num;
        }

        std::cout << "#" << i+1 << " " << answer << endl;
    }
}