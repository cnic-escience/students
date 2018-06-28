/**
 * Author: xiaoran
 * Time: 2018-06-26
 * From: Web
 */ 

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

vector<int> maxInWindows(const vector<int> &num, unsigned int size) {
    vector<int> result;
    deque<int> Q;
//        int n = num.size();
    if(num.size()<size || size<=0)
        return result;
    for (int i = 0; i < size; i++) {
        while (!Q.empty() && num[i] > num[Q.back()]) Q.pop_back();
        Q.push_back(i);
    }
    for (int i = size; i < num.size(); i++) {
        result.push_back(num[Q.front()]);
        while (!Q.empty() && num[i] >= num[Q.back()]) Q.pop_back();
        while (!Q.empty() && Q.front() <= i - size) Q.pop_front();
        Q.push_back(i);
    }
    result.push_back(num[Q.front()]);
    return result;
}

int main()
{
    int a[] = {2,3,4,2,6,2,5,1};
    vector<int> nums(a,a+8);
    vector<int> ans = maxInWindows(nums, 3);
    for(int i=0;i<ans.size();i++){
        cout<< ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}