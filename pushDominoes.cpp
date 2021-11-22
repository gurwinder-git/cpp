#include <iostream>
#include <string>

using namespace std;

string pushDominoes(string dominoes);
int main()
{
    cout << pushDominoes(".L.R.");
    return 0;
}

void updateString(string &str, int start, int end, char state)
{
    for (; start <= end; start++)
        str[start] = state;
}

string pushDominoes(string dominoes)
{
    dominoes = 'L' + dominoes + 'R';

    for (int start = 0, end = 1; end < dominoes.length(); ++end)
    {
        if (dominoes[end] == '.')
            continue;
        else if (dominoes[start] == 'L' && dominoes[end] == 'R')
        {
        }
        else if (dominoes[start] == 'R' && dominoes[end] == 'L')
        {
            int totalDominoes = end - start - 1;
            int mid = (start + end) / 2;
            // if even number of dominoes
            if (totalDominoes % 2 == 0)
            {
                updateString(dominoes, start + 1, mid, 'R');
                updateString(dominoes, mid + 1, end - 1, 'L');
            }
            // is odd number of dominoes
            else
            {
                updateString(dominoes, start + 1, mid - 1, 'R');
                updateString(dominoes, mid + 1, end - 1, 'L');
            }
        }
        else if (dominoes[start] == 'L' && dominoes[end] == 'L')
            updateString(dominoes, start + 1, end - 1, 'L');
        else // R....R
            updateString(dominoes, start + 1, end - 1, 'R');
        start = end;
    }

    string res = dominoes.substr(1, dominoes.length() - 2);

    return res;
}