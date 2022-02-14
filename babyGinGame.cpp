#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    bool babyGin(vector<int> &nums)
    {
        vector<int> freqArray(10, 0);

        for (int i = 0; i < nums.size(); i++)
            freqArray[nums[i]]++;

        int run = -1;
        int triplet = -1;

        for(int i = 0; i < 10; i++)
        {
            if(freqArray[i] >= 3)
            {
                freqArray[i] -= 3; 
                triplet = i;
            }

            if((i <= 7 ) && (freqArray[i] >= 1) && (freqArray[i + 1] >= 1) &&  (freqArray[i + 2] >= 1)){
                freqArray[i]--;
                freqArray[i+1]--;
                freqArray[i+2]--;
                run = i; 
            }
        }
 
        return (run != -1 && triplet != -1);    
    }

};

int main()
{
// 101123 
    vector<int> nums = {1,0,1,1,2,3};
    Solution sol;

    cout<<"is baby Gin: "<<sol.babyGin(nums);
    return 0;
}