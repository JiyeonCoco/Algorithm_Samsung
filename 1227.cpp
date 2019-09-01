#include <iostream>
#include <vector>
#include <string>

using namespace std;

int startX = 0, startY = 0, endX = 0, endY = 0;
vector<vector<int>> matrix;
vector<vector<int>> seen;
int check = 0;

void dfs(int hereX, int hereY)
{
    if(hereX == endX && hereY == endY)
    {
        check = 1;
        return;
    }
    seen[hereX][hereY] = 1;

    if((matrix[hereX-1][hereY] == 0 || matrix[hereX-1][hereY] == 3) && seen[hereX-1][hereY] == 0)
        dfs(hereX-1, hereY);
    if((matrix[hereX+1][hereY] == 0 || matrix[hereX+1][hereY] == 3) && seen[hereX+1][hereY] == 0)
        dfs(hereX+1, hereY);
    if((matrix[hereX][hereY-1] == 0 || matrix[hereX][hereY-1] == 3) && seen[hereX][hereY-1] == 0)
        dfs(hereX, hereY-1);
    if((matrix[hereX][hereY+1] == 0 || matrix[hereX][hereY+1] == 3) && seen[hereX][hereY+1] == 0)
        dfs(hereX, hereY+1);
}

int main()
{
    int T = 0, answer = 0;
    string input;

    for(int i=0; i<10; i++)
    {
        matrix.clear();
        seen.clear();
        check = 0;
        std::cin >> T;

        for(int y=0; y<100; y++)
        {
            vector<int> line;
            std::cin >> input;
            for(int x=0; x<100; x++)
            {
                if(input[x] == '2')
                {
                    startX = x;
                    startY = y;
                }
                if(input[x] == '3')
                {
                    endX = x;
                    endY = y;
                }

                line.push_back(input[x]-'0');
            }
            matrix.push_back(line);
        }
        seen = vector<vector<int>>(100, vector<int>(100, 0));
        dfs(startX, startY);

        if(check == 0)
            answer = 0;
        else if(check == 1)
            answer = 1;

        std::cout << "#" << T << " " << answer << endl;
    }
}