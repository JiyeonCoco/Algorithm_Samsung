#include <iostream>

using namespace std;
int table[15][2] = { 0 };
int maxCost = 0;
int N = 0;

void DFS(int day, int money)
{
    if(day > N + 1)
        return;
    if(day == N + 1)
    {
        maxCost = max(maxCost, money);
        return;
    }

    DFS(day + table[day][0], money + table[day][1]);
    DFS(day + 1, money);
}

int main()
{
    std::cin >> N;

    for(int i=1; i<=N; i++)
    {
        std::cin >> table[i][0] >> table[i][1];
    }

    DFS(1, 0);
    std::cout << maxCost << endl;
}