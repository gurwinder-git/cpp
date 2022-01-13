#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int invcount;

    void merge(vector<int> &nums, int start, int mid, int end)
    {
        int n1 = mid - start + 1;
        int n2 = end - mid;

        int left[n1];
        int right[n2];

        // coping elemets
        for (int i = 0; i < n1; i++)
        {
            left[i] = nums[start + i];
        }

        for (int i = 0; i < n2; i++)
        {
            right[i] = nums[mid + 1 + i];
        }

        int i = 0, j = 0;

        while (i < n1 && j < n2)
        {
            if (left[i] / (2.00) > right[j])
            {
                this->invcount += n1 - i;
                j++;
            }
            else
            {
                i++;
            }
        }

        // sorting
        i = 0, j = 0;
        int k = start;

        while (i < n1 && j < n2)
        {
            if (left[i] < right[j])
                nums[k] = left[i++];
            else
                nums[k] = right[j++];

            k++;
        }

        while (i < n1)
        {
            nums[k++] = left[i++];
        }

        while (j < n2)
        {
            nums[k++] = right[j++];
        }
    }

    void mergeSort(vector<int> &nums, int start, int end)
    {
        // atleast two elements have
        if (start < end)
        {
            int mid = (start + end) / 2;
            mergeSort(nums, start, mid);
            mergeSort(nums, mid + 1, end);
            merge(nums, start, mid, end);
        }
    }

    int reversePairs(vector<int> &nums)
    {
        this->invcount = 0;
        this->mergeSort(nums, 0, nums.size() - 1);

        return this->invcount;
    }
};
int main()
{
    vector<int> nums = {8, 5, 3, 4, 1, 6, 2};
    Solution sol;

    cout << sol.reversePairs(nums) << endl;

    return 0;
}