#include "Shift.h"

using namespace std;

vector<TokenBag> Shift::Process(vector<TokenBag> tokens) {

    vector<TokenBag> ret;
    int token_count = 0;
    int total_tokens = 0;

    for (vector<TokenBag>::iterator it = tokens.begin(); it != tokens.end(); ++it) {
        char *n = it->getTokens();
        vector<pair<int, int>> spaces;

        int pos = 0;
        pair<int, int> bounds;
        bounds.first = 0;
        bounds.second = 0;
        for (; ;) {
            if (n[pos] == ' ') {
                bounds.second = pos;
                spaces.push_back(bounds);
                bounds.first = pos + 1;
            }
            if (n[pos] == '\0') {
                bounds.second = pos;
                spaces.push_back(bounds);
                break;
            }
            pos++;
        }

        for (int i = 0; i < spaces.size(); ++i) {
            char *copy = new char[pos + 1];

            int copy_pos = 0;
            for (vector<pair<int, int>>::iterator iterator = spaces.begin(); iterator != spaces.end(); ++iterator) {
                for (int j = iterator->first; j <= iterator->second; ++j) {
                    copy[copy_pos] = n[j] == '\0' ? ' ' : n[j];
                    copy_pos++;
                }
                token_count++;
                copy[pos] = '\0';
            }

            TokenBag *tb = new TokenBag;
            tb->setTokens(copy);
            tb->setTokenCount(token_count);
            ret.push_back(*tb);

            total_tokens += token_count;
            token_count = 0;

            pair<int, int> temp;
            temp = spaces[0];
            spaces.erase(spaces.begin());
            spaces.push_back(temp);
        }

    }

    for (vector<TokenBag>::iterator it = ret.begin(); it != ret.end(); ++it) {
        it->setTokenTotal(total_tokens);
    }

    return ret;
}
