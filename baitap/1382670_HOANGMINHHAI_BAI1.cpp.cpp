#include <iostream>
#include <algorithm>
#include "TreeNode.h"

using namespace std;

int countNodes(TreeNode* root) {
    if (root == nullptr) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int countLeaves(TreeNode* root) {
    if (root == nullptr) return 0;
    if (root->left == nullptr && root->right == nullptr) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

int height(TreeNode* root) {
    if (root == nullptr) return -1;
    return 1 + max(height(root->left), height(root->right));
}

int depth(TreeNode* root, int target) {
    if (root == nullptr) return -1;
    if (root->data == target) return 0;

    int d = (target < root->data) ? depth(root->left, target) : depth(root->right, target);
    return (d == -1) ? -1 : d + 1;
}

int maxValue(TreeNode* root) {
    if (root == nullptr) return -1;
    while (root->right != nullptr) {
        root = root->right;
    }
    return root->data;
}

int minValue(TreeNode* root) {
    if (root == nullptr) return -1;
    while (root->left != nullptr) {
        root = root->left;
    }
    return root->data;
}

int main() {
    TreeNode* root = new TreeNode(50);
    root->left = new TreeNode(30);
    root->right = new TreeNode(70);
    root->left->left = new TreeNode(20);
    root->left->right = new TreeNode(40);
    root->left->left->left = new TreeNode(10);
    root->right->right = new TreeNode(80);

    cout << "Tong so nut: " << countNodes(root) << endl;
    cout << "So nut la: " << countLeaves(root) << endl;
    cout << "Chieu cao: " << height(root) << endl;
    cout << "Do sau cua nut 40: " << depth(root, 40) << endl;
    cout << "Gia tri lon nhat: " << maxValue(root) << endl;
    cout << "Gia tri nho nhat: " << minValue(root) << endl;

    return 0;
}
