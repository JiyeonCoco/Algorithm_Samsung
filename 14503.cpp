#include <iostream>

using namespace std;
int N = 0, M = 0;
int cleanSize = 0;
int map[50][50] = { 0 };
void cleanHere();
void clean();

struct robot
{
    int rX;
    int rY;
    int rD;
    int rCnt;
}robot;

void clean()
{
    int hereX = robot.rX;
    int hereY = robot.rY;
    int hereD = robot.rD;

    if(robot.rCnt == 4)
    {
        // 북
        if(hereD == 0)
        {
            if(hereX+1 < N && map[hereX+1][hereY] != 1)
            {
                robot.rX = hereX + 1;
                robot.rCnt = 0;
                clean();
            }
            else
                return;
        }

        // 동
        if(hereD == 1)
        {
            if(hereY-1 >= 0 && map[hereX][hereY-1] != 1)
            {
                robot.rY = hereY - 1;
                robot.rCnt = 0;
                clean();
            }
            else
                return;
        }

        // 남
        if(hereD == 2)
        {
            if(hereX-1 >= 0 && map[hereX-1][hereY] != 1)
            {
                robot.rX = hereX - 1;
                robot.rCnt = 0;
                clean();
            }
            else
                return;
        }

        // 서
        if(hereD == 3)
        {
            if(hereY+1 < M && map[hereX][hereY+1] != 1)
            {
                robot.rY = hereY + 1;
                robot.rCnt = 0;
                clean();
            }
            else
                return;
        }
    }

    else {
        // 북
        if (hereD == 0) {
            if (hereY - 1 >= 0 && map[hereX][hereY - 1] == 0) {
                robot.rY = hereY - 1;
                robot.rD = 3;
                robot.rCnt = 0;
                cleanHere();
            } else {
                robot.rD = 3;
                robot.rCnt++;
                clean();
            }
        }

            // 동
        else if (hereD == 1) {
            if (hereX - 1 >= 0 && map[hereX - 1][hereY] == 0) {
                robot.rX = hereX - 1;
                robot.rD = 0;
                robot.rCnt = 0;
                cleanHere();
            } else {
                robot.rD = 0;
                robot.rCnt++;
                clean();
            }
        }

            // 남
        else if (hereD == 2) {
            if (hereY + 1 < M && map[hereX][hereY + 1] == 0) {
                robot.rY = hereY + 1;
                robot.rD = 1;
                robot.rCnt = 0;
                cleanHere();
            } else {
                robot.rD = 1;
                robot.rCnt++;
                clean();
            }
        }

            // 서
        else if (hereD == 3) {
            if (hereX + 1 < N && map[hereX + 1][hereY] == 0) {
                robot.rX = hereX + 1;
                robot.rD = 2;
                robot.rCnt = 0;
                cleanHere();
            } else {
                robot.rD = 2;
                robot.rCnt++;
                clean();
            }
        }
    }
}

void cleanHere()
{
    map[robot.rX][robot.rY] = 2;
    cleanSize++;
    clean();
}

int main()
{
    std::cin >> N >> M;
    std::cin >> robot.rX >> robot.rY >> robot.rD;
    robot.rCnt = 0;

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            std::cin >> map[i][j];
        }
    }

    cleanHere();
    std::cout << cleanSize << endl;
}