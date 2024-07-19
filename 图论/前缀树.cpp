#include <iostream>
#include <cstring>
using namespace std;

class Trie{
public:
    Trie(): is_end(false){
        memset(next, 0, sizeof(next));
    }

    void insert(string word){
        Trie* node = this;
        for(char c: word){
            if(node -> next[c - 'a'] == nullptr){
                node -> next[c - 'a'] = new Trie();
            }
            node = node -> next[c - 'a'];
        }
        node -> is_end = true;
    }

    bool search(string word){
        Trie* node = this;
        for(char c: word){
            node = node -> next[c - 'a'];
            if(node == nullptr) return false;
        }
        return node -> is_end;

    }

    bool startsWith(string prefix){
        Trie* node = this;
        for(char c: prefix){
            node = node -> next[c - 'a'];
            if(node == nullptr) return false;
        }
        return true;
    }




private:
    bool is_end;
    Trie* next[26];

};


int main(){
    Trie trie;
    trie.insert("apple");
    cout << trie.search("apple") << endl;
    cout << trie.search("app") << endl;
    cout << trie.startsWith("app") << endl;

    return 0;
}