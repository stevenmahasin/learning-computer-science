#include <iostream>
struct Node
{
    int data;
    struct Node *parent;
    struct Node *right_child;
    struct Node *left_child;
};

class BinaryTree
{
private:
    Node *head;
public:
    // Constructors
    BinaryTree()
    {
        head = nullptr;
    }
    // Functions
    Node * compare(int n, Node &node)
    {
        if (n > (node.data))
        {
            if (node.right_child == nullptr)
            {
                return &node;
            }
            else
            {
                return compare(n,*(node.right_child));
            }
        }
        else
        {
            if (node.left_child == nullptr)
            {
                return &node;
            }
            else
            {
                return compare(n,*(node.left_child));
            }
        }
        
    }
    void add_node(int n)
    {
        Node *tmp = new Node;
        tmp->data = n;
        tmp->parent = nullptr;
        tmp->right_child = nullptr;
        tmp->left_child = nullptr;

        if (head == nullptr)
        {
            head = tmp;
        }
        else
        {
            tmp->parent = compare(n, *head);
            if (n > tmp->parent->data)
            {
                tmp->parent->right_child = tmp;
            }
            else
            {
                tmp->parent->left_child = tmp;
            }
        }
    }
};

int main()
{
    int input;
    BinaryTree a;
    std::cout << "Please enter your inputs" << std::endl;
    while (1)
    {
        std::cin >> input;
        a.add_node(input);
    }
};