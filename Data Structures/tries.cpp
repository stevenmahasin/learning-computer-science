#include <iostream>
#include <vector>
using std::vector;
using std::string;

class Trie {
private:
    struct Node {
        char data;
        vector <Node *> children;
        int num_of_children;
        bool end_of_word;
        
        // Constructor
        Node(char letter)
        {
            data = letter;
            children = vector <Node *> {};
            num_of_children = 0;
            end_of_word = false;
        }
    };
    Node * root = new Node(0);
public:
    /** Initialize your data structure here. */
    Trie() {
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node * currently = root;
        for (char &letter : word) {
            bool found = false;
            for (int i = 0; i < currently->num_of_children; i++) {
                if (currently->children[i]->data == letter) {
                    currently = currently->children[i];
                    found = true;
                    break;
                }
            }
            if (!found){
                // Init new node
                Node * tmp = new Node(letter);
                currently->num_of_children += 1;
                currently->children.push_back(tmp);
                currently = tmp;
            }
        }
        currently->end_of_word = true;
    }

     /** Returns if the word is in the trie. */
    bool search(string word) {
        Node * currently = root;
        for (char &letter : word) {
            bool found = false;
            for (int i = 0; i < currently->num_of_children; i++) {
                if (currently->children[i]->data == letter) {
                    currently = currently->children[i];
                    found = true;
                    break;
                }
            }
            if (!found) {
                return false;
            }
        }
        return currently->end_of_word;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node * currently = root;
        for (char &letter : prefix) {
            bool found = false;
            for (int i = 0; i < currently->num_of_children; i++) {
                if (currently->children[i]->data == letter) {
                    currently = currently->children[i];
                    found = true;
                    break;
                }
            }
            if (!found) {
                return false;
            }
        }
        return true;
    }
};

int main () {
    //Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool param_2 = obj->search(word);
    bool param_3 = obj->startsWith(prefix);
}