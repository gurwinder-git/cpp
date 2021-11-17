#include <iostream>
#include <vector>

using namespace std;

vector<int> whereWillBallFall(vector<vector<int>> &grid);
int main()
{
    vector<vector<int>> grid({{1, 1, 1, -1, -1}, {1, 1, 1, -1, -1}, {-1, -1, -1, 1, 1}, {1, 1, 1, 1, -1}, {-1, -1, -1, -1, -1}});

    vector<int> res = whereWillBallFall(grid);

    for (int i : res)
        cout << i << " ";

    return 0;
}
vector<int> whereWillBallFall(vector<vector<int>> &grid)
{
    vector<int> answer(grid[0].size());

    for (int x = 0; x < grid[0].size(); x++)
    {

        int ballYPos = 0;
        int ballXPos = x;
        int totalRows = grid.size() - 1;
        int totalCols = grid[0].size() - 1;

        while (ballYPos <= totalRows && ballXPos >= 0 && ballXPos <= totalCols)
        {
            if ((grid[ballYPos][ballXPos] == 1 && ballXPos == totalCols) ||
                (grid[ballYPos][ballXPos] == -1 && ballXPos == 0))
                break;

            if (grid[ballYPos][ballXPos] == 1 && grid[ballYPos][ballXPos + 1] == 1 ||
                grid[ballYPos][ballXPos] == -1 && grid[ballYPos][ballXPos - 1] == -1)
            {

                if (grid[ballYPos][ballXPos] == 1 && grid[ballYPos][ballXPos + 1] == 1)
                {
                    ballYPos++;
                    ballXPos++;
                }
                else
                {
                    ballYPos++;
                    ballXPos--;
                }
            }
            else
                break;
        }

        if (ballYPos > totalRows)
            answer[x] = ballXPos;
        else
            answer[x] = -1;
    }

    return answer;
}