#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <unordered_set>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    string input;
    // cin >> input;
    getline(cin, input);
    istringstream iss(input);
    vector<int>seq;
    int num;
    while(iss >> num){
        seq.push_back(num);
    }
    stack<int>stk;
    unordered_set<int>set;
    vector<int>ans;

    int n = seq.size();
    for(int i = 0; i < n; i++){
        if(set.find(seq[i]) != set.end()){
            while(!stk.empty() && stk.top() != seq[i]){
                int temp = stk.top();
                stk.pop();
                ans.push_back(temp);
                set.erase(temp);
            }
            ans.push_back(seq[i]);
        }
        else{
            set.insert(seq[i]);
            stk.push(seq[i]);
        }

    }

    while(!stk.empty()){
        ans.push_back(stk.top());
        stk.pop();
    }

    for(int num: ans){
        cout << num <<" ";
    }
    cout << endl;




    return 0;
}