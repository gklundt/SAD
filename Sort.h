#ifndef _SORT_H
#define _SORT_H

#include "Filter.h"

using namespace std;

class Sort : public Filter {

private:

    struct bNode {
        TokenBag *data = 0;
        bNode *left = 0;
        bNode *right = 0;
    };

    void FillBtree(bNode *, TokenBag *);

    void Traverse(bNode *parent, vector<TokenBag> &ret);

public:

    vector<TokenBag> Process(vector<TokenBag> tokens);

};

#endif //_SORT_H