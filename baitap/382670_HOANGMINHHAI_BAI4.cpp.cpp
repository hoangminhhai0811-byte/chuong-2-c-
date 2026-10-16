#include <iostream>
#include <algorithm>
#include "TreeNode.h"

using namespace std;

TreeNode* insert(TreeNode* root, int key) {
    if (root == nullptr) return new TreeNode(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    return root;
}

TreeNode* search(TreeNode* root, int key) {
    if (root == nullptr || root->data == key) return root;
    if (key < root->data) return search(root->left, key);
    return search(root->right, key);
}

TreeNode* findMin(TreeNode* root) {
    while (root->left != nullptr) root = root->left;
    return root;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr) return root;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }


        TreeNode* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int height(TreeNode* root) {
    if (root == nullptr) return -1;
    return 1 + max(height(root->left), height(root->right));
}

void printInorder(TreeNode* root) {
    if (root != nullptr) {
        printInorder(root->left);
        cout << root->data << " ";
        printInorder(root->right);
    }
}

void printMenu() {
    cout << "\n-----MENU QUAN LY BST-----\n";
    cout << "1. Chen khoa\n";
    cout << "2. Tim kiem khoa\n";
    cout << "3. Xoa khoa\n";
    cout << "4. In cay theo Inorder\n";
    cout << "5. In chieu cao cay\n";
    cout << "0. Thoat\n";
    cout << "Lua chon cua ban: ";
}

int main() {
    TreeNode* root = nullptr;
    int choice, key;
    do {
        printMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Nhap khoa can chen: "; cin >> key;
                root = insert(root, key);
                break;
            case 2:
                cout << "Nhap khoa can tim: "; cin >> key;
                cout << (search(root, key) ? "Tim thay!" : "Khong thay!") << endl;
                break;
            case 3:
                cout << "Nhap khoa can xoa: "; cin >> key;
                root = deleteNode(root, key);
                break;
            case 4:
                cout << "Inorder: ";
                printInorder(root);
                cout << endl;
                break;
            case 5:
                cout << "Chieu cao cay: " << height(root) << endl;
                break;
        }
    } while (choice != 0);
    return 0;
}
