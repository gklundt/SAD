#ifndef _TOKENBAG_H
#define _TOKENBAG_H

class TokenBag {
public:
    TokenBag();

    int getTokenCount();

    int getTokenTotal();

    char *getTokens();

    void setTokens(char *tokens);

    void setTokenTotal(int tokenTotal);

    void setTokenCount(int tokenCount);

    friend bool operator<=(const TokenBag &lhs, const TokenBag &rhs);

private:
    int tokenCount;
    int tokenTotal;
    char *tokens;

};

#endif //_TOKENBAG_H