#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    void changeWord(string &title, int start, int end)
    {
        int stringLength = end - start;

        if (stringLength == 1)
        {
            title[start] = tolower(title[start]);
        }
        else if (stringLength == 2)
        {
            title[start] = tolower(title[start]);
            title[start + 1] = tolower(title[start + 1]);
        }
        else
        {

            title[start] = toupper(title[start]);
            start++;
            for (start; start < end; start++)
            {
                title[start] = tolower(title[start]);
            }
        }
    }
    string capitalizeTitle(string title)
    {
        int start = 0;
        int end = 0;

        for (end; end < title.length(); end++)
        {
            if (title[end] == ' ')
            {
                changeWord(title, start, end);
                start = end + 1;
            }
        }

        changeWord(title, start, end);
        return title;
    }
};

int main()
{

    string title = "capiTalIze tHe titLe GuRWinDEr SIngH";

    Solution sol;

    cout << sol.capitalizeTitle(title);

    return 0;
}