#include <iostream>
#include <vector>
#include <unordered_map>
// 用时33分，易犯错误
/*
Node不定义为public
注意put的key value
put的时候没调push_front
*/

using namespace std;


class Node{
public:
    int key, value;
    Node *pre, *next;
    Node(int key = 0, int value = 0):key(key),value(value){}
};

class LRUCache{
    int capacity;
    Node* dummy;
    unordered_map<int, Node*>key_to_node;

    void push_front(Node* node){
        node -> next = dummy -> next; 
        node -> pre = dummy;
        node -> pre -> next = node;
        node -> next -> pre = node;
    }

    void remove(Node *node){
        node -> pre -> next = node -> next;
        node -> next -> pre = node -> pre;
    }

    Node* getNode(int key){
        if (key_to_node.find(key) == key_to_node.end())  return nullptr; // 没有这本书
        Node* node = key_to_node[key];
        remove(node);
        push_front(node);
        return node;
    }


public:
    LRUCache(int capacity):capacity(capacity), dummy(new Node()){
        dummy -> next = dummy;
        dummy -> pre = dummy;
    }

    int get(int key){
        Node* node = getNode(key);
        return node ? node -> value : -1;

    }

    void put(int key, int value){
        Node *node = getNode(key);
        if (node)   // 有这本书
        {
            node -> value = value;
            return;
        }
        // 没有这本书
        key_to_node[key] = new Node(key, value);
        push_front(key_to_node[key]);
        // 超出容量
        if (key_to_node.size() > capacity)
        {
            Node* back_node = dummy -> pre;
            // 删除key_to_node
            key_to_node.erase(back_node -> key);
            // 删除节点
            remove(back_node);
            delete back_node;
        }
        
    }

    void print(){
        Node *cur = dummy -> next;
        for(int i = 0; i < key_to_node.size(); i++){
            cout << cur -> key << " ";
            cur = cur -> next;
        }
        cout << endl;
    }

};




int main(){

LRUCache cache(3);
cache.put(2,5);
cache.put(3,6);
cache.put(4,2);
cache.get(3);
cache.put(5,3);
cache.print();










    return 0;
}