#ifndef _SHIFT_H
#define _SHIFT_H

#include "Filter.h"

using namespace std;

class Shift : public Filter {

public:
    vector<TokenBag> Process(vector<TokenBag> tokens);

};

#endif //_SHIFT_H