#include<iostream>

#define MAX 6
using namespace std;

int Arr[MAX];
int team1[3];
bool select[MAX];

void Print()
{
    for (int i = 0; i < 3; i++)
    {
//        if (select[i] == true)
//        {
            cout << team1[i] << " ";
        //}
    }
    cout << endl;
}

void DFS(int pos, int cnt)
{
    if (cnt == 3)
    {
        Print();
        return;
    }

    for(int i=pos; i<6; i++)
    {
        team1[cnt] = i+1;
        DFS(i+1, cnt+1);
    }
}

int main(void)
{
    Arr[0] = 1;
    Arr[1] = 2;
    Arr[2] = 3;
    Arr[3] = 4;
    Arr[4] = 5;
    Arr[5] = 6;


    for(int i=0; i<6; i++)
    {
        DFS(i, 0);
    }
}
