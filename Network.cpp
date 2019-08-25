#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> computers;
vector<int> seen;

void DFS(int here)
{
    seen[here] = 1;

    for(int there=0; there<computers.size(); there++)
    {
        if(computers[here][there] == 1 && seen[there] == 0 && here != there)
        {
            DFS(there);
        }
    }
}

int main() {
    int answer = 0;
    seen = vector<int>(computers.size(), 0);

    for(int i=0; i<computers.size(); i++)
    {
        if(seen[i] == 0)
        {
            DFS(i);
            answer++;
        }
    }

    return answer;
}