#include<iostream>
#include<stack>

using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): val(val), left(nullptr), right(nullptr){}
    
};

// 前序遍历
void preorderTraversalRecursive(TreeNode* root){
    if(root == nullptr)     return;
    cout << root -> val << " ";
    preorderTraversalRecursive(root -> left);
    preorderTraversalRecursive(root -> right);
}

void preorderTraversalIterative(TreeNode* root){
    if (root == nullptr)    return;
    stack<TreeNode*>st;
    st.push(root);
    while (!st.empty())
    {
        TreeNode* temp = st.top();
        cout << temp -> val << " ";
        st.pop();
        if(temp -> right)   st.push(temp -> right);
        if(temp -> left)    st.push(temp -> left);
    }

}


//中序遍历
void inorderTraversalRecursive(TreeNode* root){
    if(root == nullptr)     return;
    inorderTraversalRecursive(root -> left);
    cout << root -> val << " ";
    inorderTraversalRecursive(root -> right);
}

void inorderTraversalIterative(TreeNode* root){
    if (root == nullptr)    return;
    stack<TreeNode*>stk;
    TreeNode* cur = root;
    while (cur != nullptr || !stk.empty())
    {
        while (cur != nullptr)
        {
            stk.push(cur);
            cur = cur -> left;
        }
        cur = stk.top();
        stk.pop();
        cout << cur -> val << " ";
        cur = cur -> right;
    }
}


//后序遍历
void postorderTraversalRecursive(TreeNode* root){
    if(root == nullptr)     return;
    postorderTraversalRecursive(root -> left);
    postorderTraversalRecursive(root -> right);
    cout << root -> val << " ";
}

void postorderTraversalIterative(TreeNode* root){
    if (root == nullptr) return;  // 如果树为空，直接返回空结果
    stack<TreeNode*> s1, s2;  // 使用两个栈来实现后序遍历
    s1.push(root);  // 将根节点压入栈s1

    while (!s1.empty()) {
        TreeNode* node = s1.top();  // 取栈顶节点
        s1.pop();  // 弹出栈顶节点
        s2.push(node);  // 将弹出的节点压入栈s2

        // 如果左子节点不为空，将其压入栈s1
        if (node->left) s1.push(node->left);
        // 如果右子节点不为空，将其压入栈s1
        if (node->right) s1.push(node->right);
    }

    // 将s2中的节点值依次加入结果向量
    while (!s2.empty()) {
        // result.push_back(s2.top()->val);  // 取s2栈顶节点的值加入结果向量
        cout << s2.top() -> val << " ";
        s2.pop();  // 弹出s2栈顶节点
    }
    
}


int main(){
    TreeNode* root = new TreeNode(1);
    root -> left = new TreeNode(2);
    root -> right = new TreeNode(3);
    root -> left -> left = new TreeNode(4);
    root -> left -> right = new TreeNode(5);
    // 前序
    cout << "前序遍历递归: ";
    preorderTraversalRecursive(root);
    cout << endl;
    cout << "前序遍历迭代: " ;
    preorderTraversalIterative(root);
    cout << endl;


    // 中序
    cout << "中序遍历递归: ";
    inorderTraversalRecursive(root);
    cout << endl;
    cout << "中序递归迭代: ";
    inorderTraversalIterative(root);
    cout << endl;


    // 后序遍历
    cout << "后序遍历递归：";
    postorderTraversalRecursive(root);
    cout << endl;
    cout << "后序遍历迭代：";
    postorderTraversalIterative(root);
    cout << endl; 

    

    return 0;

}