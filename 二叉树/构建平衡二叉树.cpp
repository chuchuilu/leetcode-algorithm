#include <iostream>
#include <vector>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return helper(nums, 0, nums.size() - 1);
}

TreeNode* helper(vector<int>& nums, int left, int right) {
    if (left > right) return nullptr;
    int mid = left + (right - left) / 2;
    TreeNode* node = new TreeNode(nums[mid]);
    node->left = helper(nums, left, mid - 1);
    node->right = helper(nums, mid + 1, right);
    return node;
}

void inorderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    vector<int> nums = {-10, -3, 0, 5, 9};
    TreeNode* root = sortedArrayToBST(nums);

    inorderTraversal(root); // Output: -10 -3 0 5 9

    // Memory cleanup
    // In a real application, you would implement a tree destructor to free memory.
    // For simplicity, we're omitting it here.

    return 0;
}
