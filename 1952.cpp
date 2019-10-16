#include <iostream>

using namespace std;
int pay[4] = { 0 };
int month[12] = { 0 };
int minCost = INT_MAX;

void calPay(int pos, int cost)
{
    if(pos > 12)
    {
        minCost = min(minCost, cost);
        return;
    }
    if(month[pos] == 0)
        calPay(pos+1, cost);

    calPay(pos+1, cost + pay[0] * month[pos]);
    calPay(pos+1, cost+pay[1]);
    calPay(pos+3, cost+pay[2]);
    calPay(pos+12, cost+pay[3]);
}

int main()
{
    int TC = 0;
    std::cin >> TC;

    for(int iter=0; iter<TC; iter++)
    {
        minCost = INT_MAX;
        std::cin >> pay[0] >> pay[1] >> pay[2] >> pay[3];

        for(int i=1; i<=12; i++)
            std::cin >> month[i];

        calPay(1, 0);

        std::cout << "#" << iter+1 << " " << minCost << endl;
    }
}