#include <iostream>
#include <vector>
using std::vector;

class Solution {
public:
    struct Node {
        char value;
        int priority;
        Node * right_child;
        Node * left_child;
    };

    struct PriorityQueue {
        Node * root;
        int no_of_nodes = 0;
    };
    PriorityQueue queue;

    // bfs function
    Node * findTargetNode(Node * root, int no_of_nodes) {
        int n = no_of_nodes;
        vector<int> bits;
        for(int i = 0; n != 0; i++){
            bits.push_back(n % 2);
            n >>= 1;
        }
        Node * current_node = root;
        for(auto b = bits.rbegin() + 1; b != bits.rend(); b++) {
            if (*b) {
                current_node = current_node->right_child;
            }
            else {
                current_node = current_node->left_child;
            }
        }
    }

    // insert function
    void insert(char value, int priority) {
        Node * target_node = findTargetNode(queue.root, queue.no_of_nodes);
        
        target_node = new Node;
        target_node->priority = priority;
        target_node->value = value;

        queue.no_of_nodes++;
    }
    // remove function


    int _priority[26] = {};

    void prioritySort(vector<char>& tasks) {
        for (char &instruction : tasks) {
            _priority[instruction-'A']++;
        }
    }

    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0) {
            return tasks.size();
        }
        prioritySort(tasks);
        return 1;
    }
    
};
int main() {
    Solution solution;
    vector<char, int> tasks = {'A','A','A','B','B','B'};
    int n = 2;
    for (char &value) {
        std::cin >> value >> priority;
        solution.insert(value, priority);
    }
    std::cout << solution.leastInterval(tasks, n);
    return 0;
}