#include <iostream>
#include <climits>
#include "TreeNode.h"

using namespace std;

bool isValidBSTHelper(TreeNode* node, long long minVal, long long maxVal) {
    if (node == nullptr) return true;

    if (node->data <= minVal || node->data >= maxVal) return false;

    return isValidBSTHelper(node->left, minVal, node->data) &&
           isValidBSTHelper(node->right, node->data, maxVal);
}

bool isValidBST(TreeNode* root) {
    return isValidBSTHelper(root, LLONG_MIN, LLONG_MAX);
}

int main() {

    TreeNode* validRoot = new TreeNode(50);
    validRoot->left = new TreeNode(30);
    validRoot->right = new TreeNode(70);
    validRoot->left->left = new TreeNode(20);
    validRoot->left->right = new TreeNode(40);

    TreeNode* invalidRoot = new TreeNode(10);
    invalidRoot->left = new TreeNode(5);
    invalidRoot->right = new TreeNode(15);
    invalidRoot->right->left = new TreeNode(6);
    invalidRoot->right->right = new TreeNode(20);

    cout << "Kiem tra cay hop le (Bai 1): " << (isValidBST(validRoot) ? "TRUE" : "FALSE") << endl;
    cout << "Kiem tra cay KHONG hop le: " << (isValidBST(invalidRoot) ? "TRUE" : "FALSE") << endl;

    return 0;
}
