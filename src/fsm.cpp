#include "fsm.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void read(char &cache, istream& stream) {
    if (stream) {
        stream.get(cache);
    }
    if (!stream) {
        cache = 0;
    }
}

pair<int, Lexem> tick(int state, istream &stream, char &cache) {
    switch (state) {
    case 0:
        switch (cache) {
        case '>':
            read(cache, stream);
            return {0, {"gt", ""}};
        case ' ':
        case '\t':
        case '\n':
            read(cache, stream);
            return {0, LEX_EMPTY};
        case 0:
            return {-1, LEX_EOF};
        default:
            return {-1, LEX_ERROR};
        }
    default:
        return {-1, LEX_EMPTY};
    }
}
