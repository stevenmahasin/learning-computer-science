#include <iostream>
#include <vector>
using std::vector;

class Solution {
public:
    struct Node {
        char value;
        int priority;
        Node * parent;
        Node * right_child;
        Node * left_child;
    };

    struct PriorityQueue {
        Node * root;
        int no_of_nodes = 0;
    };
    PriorityQueue queue;

    // returns lowest node function
    Node * findTargetNode(Node * root, int no_of_nodes) {
        if (root) {
            int n = no_of_nodes;
            vector<int> bits;
            for(int i = 0; n != 0; i++){
                bits.push_back(n % 2);
                n >>= 1;
            }
            Node * current_node = root;
            for(auto b = bits.rbegin() + 1; b != bits.rend() - 1; b++) {
                if (*b) {
                    current_node = current_node->right_child;
                }
                else {
                    current_node = current_node->left_child;
                }
            }
            return current_node;
        }
        else {
            return root;
        }
    }

    // insert function
    void insert_tasks(vector <char>& tasks) {
        generatePriority(tasks);
        for (char& task : tasks) {
            insert(task, _priority[task]);
        }
    }

    void insert(char value, int priority) {
        Node * target_node = findTargetNode(queue.root, queue.no_of_nodes);
        Node * new_node = new Node;
        new_node->priority = priority;
        new_node->value = value;
        queue.no_of_nodes++;
        
        if (target_node->left_child) {
            target_node->right_child = new_node;
            new_node->parent = target_node;
        }
        else {
            target_node->left_child = new_node;
            new_node->parent = target_node;
        }

        while (new_node->priority > new_node->parent->priority) {
            new_node->priority = new_node->parent->priority;
            new_node->value = new_node->parent->value;

            new_node = new_node->parent;
            new_node->priority = priority;
            new_node->value = value;
        }
    }
    // remove function


    int _priority[26] = {};

    void generatePriority(vector<char>& tasks) {
        for (char &instruction : tasks) {
            _priority[instruction-'A']++;
        }
    }

    int leastInterval(vector<char>& tasks, int n) {
        insert_tasks(tasks);
        
    }
    
};
int main() {
    Solution solution;
    vector<char, int> tasks = {'A','A','A','B','B','B'};
    int n = 2;
    for (char &task : tasks) {
        solution.insert(task, solution.priority(task));
    }
    std::cout << solution.leastInterval(tasks, n);
    return 0;
}