#ifndef _FILTER_H
#define _FILTER_H

#include <iostream>
#include <vector>
#include <string.h>
#include "TokenBag.h"

using namespace std;

class Filter {
public:

    virtual vector<TokenBag> Process(vector<TokenBag> tokens) = 0;

    virtual ~Filter() { };

    Filter() { };

};

#endif //_FILTER_H