#include <iostream>

struct Node {
    int value;
    Node *below;
};

class Stack {
public:
    void push(int val) {
        if (_top) {
            Node * current = new Node;
            current->value = val;
            current->below = _top;
            _top = current;
        }
        else {
            _top = new Node;
            _top->value = val;
            _top->below = nullptr;
        }
    }

    int pop() {
        if (_top) {
            Node * current = _top;
            int result = current->value;
            _top = current->below;
            delete current;
            return result;
        }
        else {
            return 0;
        }
    }
    Node * _top = nullptr;
private:
    
};

int main() {
    Stack stack;
    int x;
    while (true) {
        std::cin >> x;
        if (x == 69) {
            break;
        }
        stack.push(x);
    }
    while (true) {
        if (!stack._top) {
            break;
        }
        std::cout << stack.pop() << std::endl;
    }

}