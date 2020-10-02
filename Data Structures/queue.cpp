// https://leetcode.com/problems/number-of-recent-calls/
class RecentCounter {
public:
    struct Node {
        int data;
        Node *next;
        Node(int value) {
            data = value;
        }
    };

    int no_of_nodes = 0;
    Node * head = nullptr;
    Node * tail = nullptr;

    RecentCounter() {    
    }
    
    int ping(int t) {
        Node * new_node = new Node(t);
        no_of_nodes++;
        if (head) {
            tail->next = new_node;
            tail = new_node;
        }
        else {
            head = tail = new_node;
        }

        while (head->data < t-3000) {
            no_of_nodes--;
            Node * previous_head = head;
            head = head->next;
            delete previous_head;
        }
        return no_of_nodes;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */