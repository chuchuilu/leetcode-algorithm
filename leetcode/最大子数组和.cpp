#include<iostream>
#include <type_traits>
#include<vector>

using namespace std;

int max_subarray(vector<int>& nums){
    if (nums.empty()) return 0;
    int ans = nums[0], temp = nums[0];
    for(int i = 1; i < nums.size(); i++){
        temp = max(temp + nums[i], nums[i]);
        ans = max(ans, temp);
    }  
    return ans;
}


int main(){

int size = 0;
vector<int>nums;
int ans;
cin >> size;

for(int i = 0; i < size; i++){
    int num;
    cin >> num;
    nums.push_back(num);
}

ans = max_subarray(nums);
cout << "max subarray sum is : " << ans << endl;


return 0;
}