#include <iostream>
struct Node
{
    int data;
    struct Node *next;
};

struct DoublyNode
{
    int data;
    struct DoublyNode *next;
    struct DoublyNode *prev;
};

class SinglyLinkedList
{
private:
    Node *head, *tail;

public:
    // Constructors
    SinglyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }
    // Functions
    void add_node(int n)
    {
        Node *tmp = new Node;
        tmp->data = n;
        tmp->next = NULL;

        if (head == NULL)   // if this is first node
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }
};

class DoublyLinkedList
{
private:
    DoublyNode *head, *tail;

public:
    // Constructors
    DoublyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }
    // Functions
    void add_node(int n)
    {
        DoublyNode *tmp = new DoublyNode;
        tmp->data = n;
        tmp->next = NULL;
        tmp->prev = NULL;

        if (head == NULL)   // if this is first node
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail->next->prev = tail;
            tail = tail->next;
        }
    }

    void add_node_backward(int n)
    {
        DoublyNode *tmp = new DoublyNode;
        tmp->data = n;
        tmp->next = NULL;
        tmp->prev = NULL;

        if (head == NULL)   // if this is first node
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            head->prev = tmp;
            tmp->next = head;
            head = head->prev;
        }
    }
};

int main()
{
    DoublyLinkedList a;
    a.add_node(5);
    a.add_node(10);
    a.add_node(15);
    a.add_node_backward(1);
};
