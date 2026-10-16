#include <iostream>
#include <vector>
#include <queue>
#include "TreeNode.h"

using namespace std;

void preorderHelper(TreeNode* root, vector<int>& result) {
    if (root != nullptr) {
        result.push_back(root->data);
        preorderHelper(root->left, result);
        preorderHelper(root->right, result);
    }
}
vector<int> preorder(TreeNode* root) {
    vector<int> result;
    preorderHelper(root, result);
    return result;
}

void inorderHelper(TreeNode* root, vector<int>& result) {
    if (root != nullptr) {
        inorderHelper(root->left, result);
        result.push_back(root->data);
        inorderHelper(root->right, result);
    }
}
vector<int> inorder(TreeNode* root) {
    vector<int> result;
    inorderHelper(root, result);
    return result;
}

void postorderHelper(TreeNode* root, vector<int>& result) {
    if (root != nullptr) {
        postorderHelper(root->left, result);
        postorderHelper(root->right, result);
        result.push_back(root->data);
    }
}
vector<int> postorder(TreeNode* root) {
    vector<int> result;
    postorderHelper(root, result);
    return result;
}

vector<int> levelOrder(TreeNode* root) {
    vector<int> result;
    if (root == nullptr) return result;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        result.push_back(current->data);

        if (current->left != nullptr) q.push(current->left);
        if (current->right != nullptr) q.push(current->right);
    }
    return result;
}

void printVector(const vector<int>& v) {
    for (int x : v) cout << x << " ";
    cout << endl;
}

int main() {
    TreeNode* root = new TreeNode(50);
    root->left = new TreeNode(30);
    root->right = new TreeNode(70);
    root->left->left = new TreeNode(20);
    root->left->right = new TreeNode(40);
    root->left->left->left = new TreeNode(10);
    root->right->right = new TreeNode(80);

    cout << "Preorder:    "; printVector(preorder(root));
    cout << "Inorder:     "; printVector(inorder(root));
    cout << "Postorder:   "; printVector(postorder(root));
    cout << "Level-order: "; printVector(levelOrder(root));

    return 0;
}
