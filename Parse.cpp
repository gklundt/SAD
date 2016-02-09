#include "Parse.h"

using namespace std;

vector<TokenBag> Parse::Process(vector<TokenBag> tokens) {

    vector<TokenBag> ret;
    int token_count = 0;
    int total_tokens = 0;

    for (vector<TokenBag>::iterator it = tokens.begin(); it != tokens.end(); ++it) {
        char *n = it->getTokens();
        int pos = 0;
        int start_pos = 0;
        for (; ;) {
            token_count = n[pos] == ' ' ? token_count + 1 : token_count;
            if (n[pos] == '\n' || n[pos] == '\r' || n[pos] == '\0') {

                char *copy = new char[(pos - start_pos) + 1];
                memcpy(copy, &n[start_pos], (size_t) (pos - start_pos));
                copy[(pos - start_pos)] = '\0';

                TokenBag *tb = new TokenBag;
                tb->setTokens(copy);
                tb->setTokenCount(token_count + 1);
                ret.push_back(*tb);

                total_tokens += token_count + 1;
                start_pos = pos + 1;
                token_count = 0;

            }
            if (n[pos] == '\0') {
                break;
            }
            pos++;
        }
    }

    for (vector<TokenBag>::iterator it = ret.begin(); it != ret.end(); ++it) {
        it->setTokenTotal(total_tokens);
    }

    return ret;
}
