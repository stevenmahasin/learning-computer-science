#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
public:
    bool isSymmetric(TreeNode* root) {
        queue <TreeNode*> order;
        order.push(root);
        
        int children_layer_counter = 1;

        TreeNode* null_node = new TreeNode(0);

        bool flag = true;

        vector <int> half_symmetry = {};
        
        while (flag) {
            flag = false;
            for (int i = 0; i < children_layer_counter; i++) {
                TreeNode* curr = order.front();
                order.pop();
                if (curr->left) {
                    order.push(curr->left);
                    flag = true;
                } else {
                    order.push(null_node);
                }
                if (curr->right) {
                    order.push(curr->right);
                    flag = true;
                } else {
                    order.push(null_node);
                }
                
                if (i < children_layer_counter/2) {
                    half_symmetry.push_back(curr->val);
                } else {
                    if (half_symmetry[children_layer_counter-i-1] != curr->val) {
                        return false;
                    }
                }
            }
            half_symmetry.clear();
            children_layer_counter *= 2;
        }
        return true;
    }
};