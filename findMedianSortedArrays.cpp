#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2);

int main()
{
    vector<int> v1({1, 2});
    vector<int> v2({3, 4});
    double m = findMedianSortedArrays(v1, v2);
    cout << "median is: " << m;

    return 0;
}

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> sortedVector;

    int num1Size = nums1.size();
    int num2Size = nums2.size();
    int i = 0, j = 0;

    while (i < num1Size && j < num2Size)
    {
        if (nums1[i] < nums2[j])
            sortedVector.push_back(nums1[i++]);

        else
            sortedVector.push_back(nums2[j++]);
    }

    while (i < num1Size)
        sortedVector.push_back(nums1[i++]);

    while (j < num2Size)
        sortedVector.push_back(nums2[j++]);

    int size = sortedVector.size();

    if (size % 2 == 0)
    {
        int n = (size / 2) - 1;
        return (double)(sortedVector[n] + sortedVector[n + 1]) / 2;
    }
    else
        return (double)sortedVector[size / 2];
}