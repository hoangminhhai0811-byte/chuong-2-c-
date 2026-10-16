#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include "TreeNode.h"

using namespace std;
using namespace std::chrono;

TreeNode* insert(TreeNode* root, int key) {
    if (root == nullptr) return new TreeNode(key);
    if (key < root->data) root->left = insert(root->left, key);
    else if (key > root->data) root->right = insert(root->right, key);
    return root;
}
TreeNode* search(TreeNode* root, int key) {
    if (root == nullptr || root->data == key) return root;
    if (key < root->data) return search(root->left, key);
    return search(root->right, key);
}
int height(TreeNode* root) {
    if (root == nullptr) return -1;
    return 1 + max(height(root->left), height(root->right));
}

int main() {
    mt19937 rng(42);
    vector<int> sizes = {1000, 5000, 10000, 20000};

    cout << "n\tLoai_du_lieu\tChieu_cao\tChen(ms)\tTim_kiem_1000(ms)\n";
    cout << "-------------------------------------------------------------------------\n";

    for (int n : sizes) {

        vector<int> keys_random(n);
        for (int i = 0; i < n; i++) keys_random[i] = i;
        shuffle(keys_random.begin(), keys_random.end(), rng);

        TreeNode* root_random = nullptr;

        auto t1 = high_resolution_clock::now();
        for (int k : keys_random) root_random = insert(root_random, k);
        auto t2 = high_resolution_clock::now();
        double insert_time_random = duration<double, milli>(t2 - t1).count();

        int h_random = height(root_random);

        volatile int foundCount_random = 0;
        auto t3 = high_resolution_clock::now();
        for (int i = 0; i < 1000; i++) {
            if (search(root_random, keys_random[i % n])) foundCount_random++;
        }
        auto t4 = high_resolution_clock::now();
        double search_time_random = duration<double, milli>(t4 - t3).count();

        cout << n << "\tNgau nhien\t" << h_random << "\t\t" << insert_time_random << "\t\t" << search_time_random << "\n";


        vector<int> keys_sorted(n);
        for (int i = 0; i < n; i++) keys_sorted[i] = i;

        TreeNode* root_sorted = nullptr;

        t1 = high_resolution_clock::now();
        for (int k : keys_sorted) root_sorted = insert(root_sorted, k);
        t2 = high_resolution_clock::now();
        double insert_time_sorted = duration<double, milli>(t2 - t1).count();

        int h_sorted = height(root_sorted);

        volatile int foundCount_sorted = 0;
        t3 = high_resolution_clock::now();
        for (int i = 0; i < 1000; i++) {
            if (search(root_sorted, keys_sorted[i % n])) foundCount_sorted++;
        }
        t4 = high_resolution_clock::now();
        double search_time_sorted = duration<double, milli>(t4 - t3).count();

        cout << n << "\tDa sap xep\t" << h_sorted << "\t\t" << insert_time_sorted << "\t\t" << search_time_sorted << "\n";
    }

    return 0;
}
