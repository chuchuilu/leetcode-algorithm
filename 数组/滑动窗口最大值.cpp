#include <vector>
#include <iostream>
#include <deque>
using namespace std;



vector<int> maxSlidingWindows(vector<int>& nums. int k){
    vector<int>ans;
    deque<int>dq;
    int n = nums.size();
    for(int i = 0; i < n; i++){
        while(!dq.empty() && nums[i] >= nums[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
        while(i - dq.front() >= k)  dq.pop_front();
        if(i >= k - 1){
            ans.push_back(nums[dq.front()]);
        }
        
    }
}



int main(){





    return 0;
}