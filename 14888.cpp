#include <iostream>
#include <limits.h>

using namespace std;

int N = 0;
int A[11] = { 0 };
int operNum[4] = { 0 };
int maxVal = -1 * INT_MAX, minVal = INT_MAX;

void getNum(int pos, int result, int plus, int minus, int mult, int div)
{
    if(pos == N)
    {
        maxVal = max(maxVal, result);
        minVal = min(minVal, result);
        return;
    }

    if(plus > 0)
        getNum(pos+1, result + A[pos], plus-1, minus, mult, div);

    if(minus > 0)
        getNum(pos+1, result - A[pos], plus, minus-1, mult, div);

    if(mult > 0)
        getNum(pos+1, result * A[pos], plus, minus, mult-1, div);

    if(div > 0)
        getNum(pos+1, result / A[pos], plus, minus, mult, div-1);
}

int main()
{
    std::cin >> N;

    for(int i=0; i<N; i++)
        std::cin >> A[i];

    std::cin >> operNum[0] >> operNum[1] >> operNum[2] >> operNum[3];
    getNum(1, A[0], operNum[0], operNum[1], operNum[2], operNum[3]);

    std::cout << maxVal << endl << minVal << endl;
}