#include <iostream>
#include "Filter.h"
#include "Parse.h"
#include "Shift.h"
#include "Sort.h"

using namespace std;

int main() {

    vector<TokenBag> v;
    TokenBag t;

    //t.setTokens((char *) "big flood\napple pie\nApple , Fiona\nbanana bunch\ncherry pie\n123 pilots Pilots\ngoat herder\ndog trainer's coat");
    //t.setTokens((char *) "a\nA\nb\nB\nC\nD\nc\nd");
    t.setTokens((char *) "aAa AaA\nAAA aaa\nAaA aAa\naaa AAA\nC\nD\nc\nd");
    v.push_back(t);

    Filter *p = new Parse;
    Filter *s = new Shift;
    Filter *a = new Sort;

    vector<TokenBag> out = a->Process(s->Process(p->Process(v)));

    for (vector<TokenBag>::iterator it = out.begin(); it != out.end(); ++it) {
        cout << "Tokens (" << it->getTokenCount() << " of " << \
        it->getTokenTotal() << "): \"" << it->getTokens() << "\"" << endl;
    }

    return 0;
}