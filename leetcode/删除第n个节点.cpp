/*

#include<iostream>
#include<vector>

using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;
    ListNode(int n): val(n), next(nullptr){}
};

int main(){
    ListNode * dummy = new ListNode(-1);
    ListNode * cur = dummy;
    int num;
    cin >> num;
    for(int i = 0; i < num; i++){
        int node_num;
        cin >> node_num;
        auto node = new ListNode(node_num);
        cur -> next = node;
        cur = cur -> next;
        
    }
    cur = dummy -> next;
    while(cur){
        cout << cur -> val << endl;
        cur = cur -> next;
    }

*/


#include<iostream>
#include<vector>

using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;
    ListNode(int n): val(n), next(nullptr){}
};

int main(){
    ListNode * dummy = new ListNode(-1);
    ListNode * cur = dummy;
    int num;
    cin >> num;
    for(int i = 0; i < num; i++){
        int node_num;
        cin >> node_num;
        auto node = new ListNode(node_num);
        cur -> next = node;
        cur = cur -> next;
        
    }
    cur = dummy -> next;
    while(cur){
        cout << cur -> val << endl;
        cur = cur -> next;
    }

    // for(int i = 0; i < num; i++){
    //     cur = dummy;
    //     cur = cur -> next;
    //     cout << cur -> val << endl;
        
    // }

    int n = 2;
    ListNode * pre_n;
    for(int i = 0; i < n - 1; i++)
    {
        cur = dummy -> next;
    }
    pre_n = cur;
    ListNode *n_node = pre_n -> next;
    if(n_node -> next == nullptr){
        pre_n -> next = nullptr;
        delete n_node;
    }
    else{
        auto n_next = n_node -> next;
        pre_n -> next = n_next;
        delete n_node;
    }





    cur = dummy -> next;
    while(cur){
        cout << cur -> val << endl;
        cur = cur -> next;
    }


    return 0;
}