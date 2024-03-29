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
    //t.setTokens((char *) "aAa AaA\nAAA aaa\nAaA aAa\naaa AAA\nC\nD\nc\nd");
    //t.setTokens((char *)"my country 'tis of thee\nsweet land of liberty\nof thee I sing");
    t.setTokens((char *) "Software Architecture and Design\naA aaa\naa Aaa\nAa Aaa\nAA    aaa");
    v.push_back(t);

    Filter *p = new Parse;
    Filter *a = new Shift;
    Filter *s = new Sort;

    vector<TokenBag> out = p->Process(v);
    out = s->Process(out);
    out = a->Process(out);
//    out = a->Process(s->Process(p->Process(out)));
//    out = a->Process(s->Process(p->Process(out)));
//    out = a->Process(s->Process(p->Process(out)));
//    out = a->Process(s->Process(p->Process(out)));
//    out = a->Process(s->Process(p->Process(out)));

    for (vector<TokenBag>::iterator it = out.begin(); it != out.end(); ++it) {
        cout << "Tokens (" << it->getTokenCount() << " of " << \
        it->getTokenTotal() << "): \"" << it->getTokens() << "\"" << endl;
    }

    return 0;
}