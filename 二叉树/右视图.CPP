#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

vector<int> levelOrder(TreeNode* root) {
    vector<int> result;
    if (root == nullptr) return result;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* node = q.front();
            q.pop();
            if(i == levelSize - 1){
                result.push_back(node -> val);
            }
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    
    return result;
}

//////////////////////////////递归
void rightViewHelper(TreeNode* node, int level, vector<int>& result) {
    if (node == nullptr) return;

    // 如果当前层级等于结果向量的大小，说明这是该层第一次访问的节点
    if (level == result.size()) {
        result.push_back(node->val);
    }

    // 优先访问右子节点
    rightViewHelper(node->right, level + 1, result);
    rightViewHelper(node->left, level + 1, result);
}

vector<int> rightView(TreeNode* root) {
    vector<int> result;
    rightViewHelper(root, 0, result);
    return result;
}