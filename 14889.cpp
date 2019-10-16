#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;
int N = 0;
int power[20][20] = { 0 };
int team1[10] = { 0 };
int team2[10] = { 0 };
int visited[10] = {0};
int minScore = INT_MAX;

int getScore(int team)
{
    int score = 0;

    if(team == 1)
    {
        for(int i=0; i<N/2; i++)
        {
            for(int j=0; j<N/2; j++)
            {
                if(i != j)
                    score += power[team1[i]][team1[j]];
            }
        }
    }
    else if(team == 2)
    {
        for(int i=0; i<N/2; i++)
        {
            for(int j=0; j<N/2; j++)
            {
                if(i != j)
                    score += power[team2[i]][team2[j]];
            }
        }
    }
    return score;
}

void getTeam(int pos, int cnt)
{
    if (cnt == N/2)
    {
        int n1 = 0;
        int n2 = 0;

        for (int i = 0; i < N; i++)
        {
            if (visited[i] == 1)
                team1[n1++] = i;
            else
                team2[n2++] = i;
        }

        int score1 = getScore(1);
        int score2 = getScore(2);

        minScore = min(minScore, abs(score1-score2));
        return;
    }

    for (int i = pos; i < N; i++)
    {
        if (visited[i] == 1)
            continue;

        visited[i] = 1;
        getTeam(i, cnt + 1);
        visited[i] = 0;
    }
}

int main()
{
    std::cin >> N;

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            std::cin >> power[i][j];
        }
    }

    getTeam(0, 0);

    std::cout << minScore << endl;
}