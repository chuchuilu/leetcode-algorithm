#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Node{
public:
    int key, value;
    Node *pre, *next;
    Node(int key = 0, int value = 0): key(key), value(value), pre(nullptr), next(nullptr){}
};

class LRUCache{
public:
    LRUCache(int capacity):capacity(capacity), dummy(new Node(0, 0)){
        dummy -> next = dummy;
        dummy -> pre = dummy;
    }

    int get(int key){
        Node* node = get_node(key);
        if (node)
        {
            return node -> value;
        }
        return -1;
    }


    void put(int key, int value){
        Node* node = get_node(key);
        if(node){
            node -> value = value;
            return;
        }
        key_to_node[key] = node = new Node(key, value);
        push_front(node);
        if(key_to_node.size() > capacity){
            auto back_node = dummy -> pre;
            remove(back_node);
            key_to_node.erase(back_node -> key);
            delete back_node;
        }

    }

private:
    int capacity;
    Node* dummy;
    unordered_map<int, Node*> key_to_node;

    void push_front(Node* x){
        x -> next = dummy -> next;
        x -> pre = dummy;
        x -> pre -> next = x;
        x -> next -> pre = x;
    }

    void remove(Node* x){
        x -> pre -> next = x -> next;
        x -> next -> pre = x -> pre;
    }

    Node* get_node(int key){
        auto it = key_to_node.find(key);
        if (it != key_to_node.end())
        {
            Node* node = it -> second;
            remove(node);
            push_front(node);
            return node;
        }
        return nullptr;
        
    }


};



int main(){
    LRUCache cache(2);
    
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl; // 返回 1
    cache.put(3, 3);              // 该操作会使得关键字 2 作废
    cout << cache.get(2) << endl; // 返回 -1 (未找到)
    cache.put(4, 4);              // 该操作会使得关键字 1 作废
    cout << cache.get(1) << endl; // 返回 -1 (未找到)
    cout << cache.get(3) << endl; // 返回 3
    cout << cache.get(4) << endl; // 返回 4




    return 0;
}