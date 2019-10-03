#include <iostream>

using namespace std;
int maze[16][16];
int startX = 0, startY = 0;
bool isOk = false;
int coord[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

void findRoad(int hereX, int hereY)
{
    if(isOk == true)
        return;

    if(maze[hereX][hereY] == 3)
    {
        isOk = true;
        return;
    }

    maze[hereX][hereY] = 1;

    for(int i=0; i<4; i++)
    {
        int nextX = hereX + coord[i][0];
        int nextY = hereY + coord[i][1];

        if(nextX >= 0 && nextX < 16 && nextY >= 0 && nextY < 16)
        {
            if(maze[nextX][nextY] != 1)
            {
                findRoad(nextX, nextY);
            }
        }
    }
}

int main()
{
    int T = 0;

    for(int i=0; i<10; i++)
    {
        std::cin >> T;
        startX = startY = 0;
        isOk = false;

        for(int x=0; x<16; x++)
        {
            string input;
            std::cin >> input;

            for(int y=0; y<16; y++)
            {
                if(input[y]-'0' == 0)
                    maze[x][y] = 0;
                else if(input[y]-'0' == 1)
                    maze[x][y] = 1;
                else if(input[y]-'0' == 2)
                {
                    maze[x][y] = 2;
                    startX = x;
                    startY = y;
                }
                else if(input[y]-'0' == 3)
                    maze[x][y] = 3;
            }
        }

        findRoad(startX, startY);

        std::cout << "#" << T << " " << isOk << endl;
    }

}