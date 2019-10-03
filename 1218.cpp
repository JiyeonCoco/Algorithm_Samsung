#include <iostream>
#include <stack>
#include <vector>

using namespace std;
char open[4] = { '(', '[', '{', '<' };
int ok = 0;

vector<pair<int, pair<int, int>>> ve;


void checkPair(int length, string input)
{
    stack<char> s;

    for(int i=0; i<length; i++)
    {
        for(int o=0; o<4; o++)
        {
            if(input[i] == open[o])
            {
                s.push(input[i]);
                continue;
            }
        }

        if (input[i] == ')')
        {
            if (s.top() == '(')
                s.pop();
            else
                return;
        }
        else if (input[i] == ']')
        {
            if (s.top() == '[')
                s.pop();
            else
                return;
        }
        else if (input[i] == '}')
        {
            if (s.top() == '{')
                s.pop();
            else
                return;
        }
        else if (input[i] == '>')
        {
            if (s.top() == '<')
                s.pop();
            else
                return;
        }


    }

    if(s.empty())
        ok = 1;
}

int main()
{
    for(int iter=0; iter<10; iter++)
    {
        int l = 0;
        ok = 0;
        string input;
        std::cin >> l;
        std::cin >> input;

        checkPair(l, input);

        std::cout << "#" << iter+1 << " " << ok << endl;
    }
}