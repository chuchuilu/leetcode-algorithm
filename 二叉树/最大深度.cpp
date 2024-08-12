#include<iostream>
#include<algorithm>

using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): val(val), left(nullptr), right(nullptr){}
    
};
int dfs(TreeNode*);

int maxDepth(TreeNode* root){
    return dfs(root);
}

int dfs(TreeNode* root){
    if(root == nullptr) return 0;
    return max(dfs(root -> left), dfs(root -> right)) + 1;
}

int main() {
    // 构建示例二叉树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // 计算并输出二叉树的最大深度
    cout << "Maximum depth of the binary tree: " << maxDepth(root) << endl;

    // 释放内存
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}