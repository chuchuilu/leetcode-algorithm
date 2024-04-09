#include <iostream>
#include <vector>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 创建链表
ListNode *creatNode(vector<int>& nums){
    ListNode* dummy = new ListNode(0);
    ListNode* tail = dummy;
    for (size_t i = 0; i < nums.size(); i++)
    {
        ListNode * newNode = new ListNode(nums[i]);
        tail -> next = newNode;
        tail = tail -> next; 
    }
    return dummy -> next;
}

// 打印链表
void print(ListNode* list){
    ListNode* cur = list;
    while (cur != nullptr)
    {
        cout << cur -> val << " ";
        cur = cur -> next;
    }
    cout << endl;
    
}

// 合并两个有序链表
ListNode* mergeList(ListNode* list1, ListNode* list2){
    ListNode* res = new ListNode(0);
    ListNode* p1 = list1, *p2 = list2, *p = res;
    while (p1 != nullptr && p2 != nullptr)
    {
        if (p1 -> val > p2 -> val)
        {
            p -> next = p2;
            p2 = p2 -> next; 
        }
        else{
            p -> next = p1;
            p1 = p1 -> next;
        }
        p = p -> next;
        
    }
    
    p -> next = (p1 == nullptr)? p2: p1;
    return res -> next;
}

// 删除第倒数k个节点
// 思路一：遍历一遍，然后拿到倒数第k个节点的前一个节点，然后删除，倒数第k， 正数 n - k + 1,那么找到 n - k 就是要删除的前一个节点
void deleteK(ListNode* list, int k){
    int n = 0;
    ListNode *cur = list;
    while (cur)
    {
        n += 1;
        cur = cur -> next;
    }
    cout << "总节点: " << n << endl;
    cur = list;
    // 这是找到第 n - k 个节点
    for (size_t i = 0; i < n - k -1; i++)
    {
        cur = cur -> next;
    }
    // 上一个节点
    cur -> next = cur -> next -> next;
    
}

// 删除倒数第k个，只遍历一次
// 找到倒数第k个，则找到倒数第k个的前一个，然后中间设置间隔，本来是k - 1间隔，前一个就是k间隔
void deleteK_1(ListNode* list, int k){
    ListNode* pre = list;
    ListNode* cur = list;
    for (size_t i = 0; i < k; i++) 
    {
        cur = cur -> next;
    }
    while (cur -> next != nullptr)
    {
        pre = pre -> next;
        cur = cur -> next;
    }
    pre -> next = pre -> next -> next;
    
}



int main(){

vector<int>nums1{1,2,3,7,8,9};
vector<int>nums2{1,3,8};

ListNode * list1 = creatNode(nums1);
ListNode * list2 = creatNode(nums2);
print(list1);
print(list2);

// ListNode* mergedList = mergeList(list1, list2);
// print(list1);
// print(list2);

// print(mergedList);

// deleteK(list1, 2);
deleteK_1(list1, 2);
print(list1);

return 0;
}