#include <iostream>
#include <queue>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

int minDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    queue<TreeNode*> q;
    q.push(root);
    int depth = 1;
    
    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left == nullptr && node->right == nullptr) {
                return depth;
            }
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        ++depth;
    }
    return depth;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Minimum depth of the binary tree: " << minDepth(root) << endl;

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
