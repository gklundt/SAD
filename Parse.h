#ifndef _PARSE_H
#define _PARSE_H

#include "Filter.h"

using namespace std;

class Parse : public Filter {

public:
    vector<TokenBag> Process(vector<TokenBag> tokens);

};

#endif //_PARSE_H