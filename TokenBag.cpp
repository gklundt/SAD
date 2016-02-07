#include "TokenBag.h"

TokenBag::TokenBag() {
    tokenCount = 0;
    tokenTotal = 0;
    tokens = 0;
}

int TokenBag::getTokenCount() {
    return tokenCount;
}

int TokenBag::getTokenTotal() {
    return tokenTotal;
}

char *TokenBag::getTokens() {
    return tokens;
}

void TokenBag::setTokenCount(int tokenCount) {
    TokenBag::tokenCount = tokenCount;
}

void TokenBag::setTokenTotal(int tokenTotal) {
    TokenBag::tokenTotal = tokenTotal;
}

void TokenBag::setTokens(char *tokens) {
    TokenBag::tokens = tokens;
}


bool operator<=(const TokenBag &lhs, const TokenBag &rhs) {
    int pos = 0;

    char *l = lhs.tokens;
    char *r = rhs.tokens;
    for (; ; ++pos) {


        int li = l[pos];
        int ri = r[pos];

        int lli = li, rri = ri;


        if (li >= 65 && li <= 90) { lli = (li + 33) + ((li + 33) - 98); }
        if (li >= 97 && li <= 122) { lli = li + (li - 97); }

        if (ri >= 65 && ri <= 90) { rri = (ri + 33) + ((ri + 33) - 98); }
        if (ri >= 97 && ri <= 122) { rri = ri + (ri - 97); }


        if (lli < rri) {
            return true;
        }
        if (lli > rri) {
            return false;
        }
        if (l[pos] == '\0') {
            return true;
        }
    }
}