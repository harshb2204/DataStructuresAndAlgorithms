#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int removeDuplicates(vector<int> &nums)
{

    int j = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] != nums[i - 1])
        {
            nums[j] = nums[i];
            j++;
        }
    }
    return j;
}
int main()
{

    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);
    v.push_back(3);
    v.push_back(3);
    v.push_back(3);

    int a = removeDuplicates(v);
    cout << a << endl;

    for (auto i : v)
    {
        cout << i << endl;
    }
}
