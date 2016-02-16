#include "Sort.h"

using namespace std;

vector<TokenBag> Sort::Process(vector<TokenBag> tokens) {

    vector<TokenBag> ret;

    root->data = &tokens[0];

    for (int i = 1; i < tokens.size(); ++i) {
        FillBtree(root, &tokens[i]);
    }

    Traverse(root, ret);

    return ret;
}

void Sort::FillBtree(bNode *parent, TokenBag *tb) {

    if (*tb <= *parent->data) {
        if (!parent->left) {
            parent->left = new bNode;
            parent->left->data = tb;
        } else {
            FillBtree(parent->left, tb);
        }
    } else {
        if (!parent->right) {
            parent->right = new bNode;
            parent->right->data = tb;
        } else {
            FillBtree(parent->right, tb);
        }
    }
}

void Sort::Traverse(bNode *parent, vector<TokenBag> &ret) {
    if (parent->left) {
        Traverse(parent->left, ret);
    }

    ret.push_back(*parent->data);

    if (parent->right) {
        Traverse(parent->right, ret);
    }
}