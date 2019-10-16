#include <iostream>
#include <queue>

using namespace std;
int N = 0, M = 0;
int board[10][10] = { 0 };
int coord[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int minD = INT_MAX;

struct ball
{
    int dist;
    int rX;
    int rY;
    int bX;
    int bY;
};

void move(int rX, int rY, int bX, int bY, int type)
{
    while(true)
    {
        int nextX = rX + coord[type][0];
        int nextY = rY = coord[type][1];

        if(board[nextX][nextY] == 2)
            break;
        else if(board[nextX][nextY] == 0)
            break;
    }
}

void BFS(int rX, int rY, int bX, int bY)
{
    queue<ball> q;
    q.push(ball{0, rX, rY, bX, bY});

    while(!q.empty())
    {
        ball hereB = q.front();
        q.pop();

        if(hereB.rX == rX && hereB.rY == rY)
        {
            minD = min(minD, hereB.dist);
            break;
        }

        for(int i=0; i<4; i++)
        {
            int nextX = hereX;
            int nextY = hereY;



            if(nextX >= 0 && nextX < M && nextY >= 0 && nextY < N)
            {
                if((board[nextX][nextY] == 1 || board[nextX][nextY] == 2) && boardD[nextX][nextY] == 0)
                {
                    boardD[nextX][nextY] = dist + 1;
                    q.push({nextX, nextY});
                }
            }
        }
    }

}

int main()
{

    std::cin >> N >> M;
    ball b;

    for(int i=0; i<N; i++)
    {
        string input;
        std::cin >> input;

        for(int j=0; j<M; j++)
        {
            if(input[j] == '.')
                board[i][j] = 1;
            else if(input[j] == '#')
                board[i][j] = 0;
            else if(input[j] == 'O')
                board[i][j] = 2;
            else if(input[j] == 'R')
            {
                b.rX = i;
                b.rY = j;
                board[i][j] = 3;
            }
            else if(input[j] == 'B')
            {
                b.bX = i;
                b.bY = j;
                board[i][j] = 3;
            }
        }
    }

    BFS(b.rX, b.rY, b.bX, b.bY);
    std::cout << minD << endl;
}