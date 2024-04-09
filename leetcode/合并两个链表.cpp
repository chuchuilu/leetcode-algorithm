#include<iostream>
#include<vector>

using namespace std;

class ListNode{
public:
    int val;
    ListNode * next;
    ListNode(int x): val(x), next(nullptr){ }

};

ListNode * createListNode(vector<int> &nums){
    ListNode* dummy = new ListNode(0);
    ListNode* tail = dummy;;
    for (size_t i = 0; i < nums.size(); i++)
    {
        ListNode * temp = new ListNode(nums[i]);
        tail -> next = temp;
        tail = tail -> next;

    }

    return dummy -> next;
        
}

ListNode * mergeTWOList(ListNode *list1, ListNode *list2){
    ListNode* res = new ListNode(0);
    ListNode *p1 = list1, *p2 = list2, *p = res;
    while (p1 != nullptr && p2 != nullptr)
    {
        if (p1 -> val < p2 -> val)
        {
            p -> next = p1;
            p1 = p1 -> next;
            p = p -> next;
        }
        else
        {
            p -> next = p2;
            p2 = p2 -> next;
            p = p -> next;
        }
    }
    p -> next = (p1 != nullptr) ? p1 : p2;
    return res -> next;
}
    
    


void print(ListNode *head)
{
    ListNode* cur = head;
    while (cur!= nullptr)
    {
        cout << cur -> val << " ";
        cur = cur -> next;
    }
    cout << endl;
}

int main(){

    vector<int> nums1{1, 6, 8};
    vector<int> nums2{2, 4, 7};
    ListNode* list1 = createListNode(nums1);
    ListNode* list2 = createListNode(nums2);
    print(list1);
    print(list2);

    ListNode *res = mergeTWOList(list1, list2);
    print(res);

    // 合并两个链表

    return 0;
}