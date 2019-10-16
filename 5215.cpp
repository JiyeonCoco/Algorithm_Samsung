#include <iostream>

using namespace std;
int N = 0, L = 0;
int T[1000] = { 0 };
int K[1000] = { 0 };
int maxScore = 0;

void calCalorie(int num, int score, int cal)
{
    if(cal > L)
        return;

    if(num == N)
    {
        maxScore = max(maxScore, score);
        return;
    }

    calCalorie(num+1, score+T[num], cal + K[num]);
    calCalorie(num+1, score, cal);
}

int main()
{
    int TC = 0;
    std::cin >> TC;

    for(int iter = 0; iter < TC; iter++)
    {
        maxScore = 0;
        std::cin >> N >> L;

        for(int i=0; i<N; i++)
        {
            std::cin >> T[i] >> K[i];
        }

        calCalorie(0, 0, 0);
        std::cout << "#" << iter+1 << " " << maxScore << endl;
    }
}