#include <iostream>
#include <string>
#include <vector>

using namespace std;
int result;

void DFS(vector<int> &numbers, int target, int sum, int cnt)
{
    if(cnt == numbers.size())
    {
        if(sum == target)
        {
            result++;
        }
        return;
    }

    DFS(numbers, target, sum + numbers[cnt], cnt+1);
    DFS(numbers, target, sum - numbers[cnt], cnt+1);
}

int main() {
    vector<int> numbers;
    int target, answer = 0;

    // numbers, target 값 설정

    int sum = 0;

    DFS(numbers, target, sum + numbers[0], 1);
    DFS(numbers, target, sum - numbers[0], 1);

    answer = result;

    return answer;
}