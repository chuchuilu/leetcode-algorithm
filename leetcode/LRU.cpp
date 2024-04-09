#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Node{
public:
    int key, value;
    Node *pre, *next;

    Node(int key = 0, int value = 0): key(key), value(value){}
};


class LRUCache{
private:
    int capacity;
    Node* dummy;
    unordered_map<int, Node*> key_to_node;

    // 把一本书放在最上边
    void push_front(Node *x){
        x -> pre = dummy;
        x -> next = dummy -> next;
        x -> pre -> next = x;
        x -> next -> pre = x; 
    }

    // 删除一本书
    void remove(Node *x){
        x -> pre -> next = x -> next;
        x -> next -> pre = x -> pre;
    }

    // 获取一本书
    Node* get_node(int key){
        auto it = key_to_node.find(key);
        if(it == key_to_node.end()){
            return nullptr;
        } //没有这本书
        // 这本书有
        auto node = it -> second;
        remove(node);
        push_front(node);
        return node;
    }


        

public:
    LRUCache(int capacity): capacity(capacity), dummy(new Node()){
        dummy -> pre = dummy;
        dummy -> next = dummy;
    }

    int get(int  key){
        auto node = get_node(key);
        return node? node -> value : -1;

    }

    void put(int key, int value){
        auto node = get_node(key);
        if(node){// 这本书有了 更新
            node -> value = value;
            return;
        }
        key_to_node[key] = node = new Node(key, value);
        push_front(node);
        if (key_to_node.size() > capacity){ // 容量超了
            auto back_node = dummy -> pre;
            
            key_to_node.erase(back_node -> key);
            remove(back_node);
            delete back_node;
        }

    }

        void print(){
        Node* cur = dummy -> next;
        cout << "now capacity is: "<<key_to_node.size() << endl;
        for(int i = 0; i < key_to_node.size(); i++){
            cout << " now LRU Cache is: " << "(" << cur -> key << " "<< cur -> value<< ")";
            cur = cur -> next;
        }
        cout << endl;

    }

    

};


int main(){
    LRUCache LRU(3);
    LRU.put(1,4);
    LRU.put(2,4);
    LRU.print();
    LRU.get(1);
    LRU.print();
    LRU.put(3,4);
    LRU.print();
    LRU.put(5,4);
    LRU.print();
    LRU.put(6,4);
    LRU.print();
    


}
