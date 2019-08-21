#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

vector<vector<int>> colorGrid;
vector<vector<int>> seen;
int groupCnt, specialGroupCnt = 0;

void padding(int N)
{
    vector<int> line;

    for(int i=0; i<N+2; i++)
    {
        line.push_back(10);
    }
    colorGrid.push_back(line);
}

void DFS(int N, int hereX, int hereY)
{
    seen[hereX][hereY] = 1;

    for(int i=0; i<4; i++)
    {
        if((colorGrid[hereX][hereY] == colorGrid[hereX-1][hereY]) && (seen[hereX-1][hereY] == 0))
            DFS(N, hereX-1, hereY);
        else if((colorGrid[hereX][hereY] == colorGrid[hereX+1][hereY]) && (seen[hereX+1][hereY] == 0))
            DFS(N, hereX+1, hereY);
        else if((colorGrid[hereX][hereY] == colorGrid[hereX][hereY-1]) && (seen[hereX][hereY-1] == 0))
            DFS(N, hereX, hereY-1);
        else if((colorGrid[hereX][hereY] == colorGrid[hereX][hereY+1]) && (seen[hereX][hereY+1] == 0))
            DFS(N, hereX, hereY+1);
    }
}

void specialDFS(int N, int hereX, int hereY)
{
    seen[hereX][hereY] = 1;

    for(int i=0; i<4; i++)
    {
        if((abs(colorGrid[hereX][hereY]-colorGrid[hereX-1][hereY]) <= 1) && (seen[hereX-1][hereY] == 0))
            specialDFS(N, hereX-1, hereY);
        else if((abs(colorGrid[hereX][hereY]-colorGrid[hereX+1][hereY]) <= 1) && (seen[hereX+1][hereY] == 0))
            specialDFS(N, hereX+1, hereY);
        else if((abs(colorGrid[hereX][hereY]-colorGrid[hereX][hereY-1]) <= 1) && (seen[hereX][hereY-1] == 0))
            specialDFS(N, hereX, hereY-1);
        else if((abs(colorGrid[hereX][hereY]-colorGrid[hereX][hereY+1]) <= 1) && (seen[hereX][hereY+1] == 0))
            specialDFS(N, hereX, hereY+1);
    }
}

void checkGroup(int N, int check)
{
    seen = vector<vector<int>>(N+2, vector<int>(N+2, 0));

    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            if(seen[i][j] == 0 && check == 0)
            {
                DFS(N, i, j);
                groupCnt++;
            }
            else if(seen[i][j] == 0 && check == 1)
            {
                specialDFS(N, i, j);
                specialGroupCnt++;
            }
        }
    }
}

int main()
{
    int N = 0;
    string input;

    std::cin >> N;

    padding(N);
    for(int i=0; i<N; i++)
    {
        std::cin >> input;
        vector<int> line;

        line.push_back(10);
        for(int j=0; j<N; j++)
        {
            if(input[j] == 'R')
                line.push_back(0);
            else if(input[j] == 'G')
                line.push_back(1);
            else if(input[j] == 'B')
                line.push_back(3);
        }
        line.push_back(10);
        colorGrid.push_back(line);
    }
    padding(N);

    checkGroup(N, 0);
    checkGroup(N, 1);

    std::cout << groupCnt << " " << specialGroupCnt << endl;
}