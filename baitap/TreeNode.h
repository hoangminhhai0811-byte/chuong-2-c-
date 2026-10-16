#pragma once
#include <iostream>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode (int val): data(val), left (nullptr), right(nullptr) {}
};
//khi thay muon "run" thi hay tat "complier file "va"link file"cua nhung bai khac la dc(vd:run bai 5.cpp,an vaof cac file bai 1,2,3,4->properties->build->
