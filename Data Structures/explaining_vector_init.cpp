#include <vector>
#include <iostream>
using std::vector;
using std::cout;

struct Node {
    char data;
    vector <Node *> children = vector <Node *> ();
    int num_of_children;
    bool end_of_word = false;
};

int main () {
    Node * root = new Node;
    root->data = 'a';

    vector <Node *> tester;


    Node * child_1 = new Node;
    child_1->data = 'b';
    Node * child_2 = new Node;
    child_2->data = 'c';

    root->children.push_back(child_1);
    root->children.push_back(child_2);
    tester.push_back(child_2);

    cout << "Root data = " << root->data << std::endl;
    cout << "Child 1 data = " << root->children[0]->data << std::endl;
    cout << "Child 2 data = " << root->children[1]->data << std::endl;
    cout << "Tester's Child 2 data = " << tester[0]->data << std::endl;
    
};