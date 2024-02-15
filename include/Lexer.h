#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <vector>
#include <string>

class Lexer
{
    public:
        Lexer(std::istream&);
        virtual ~Lexer();
        std::pair<std::string, std::string> getNextLexem();

    protected:

    private:
        char cache;
        int state;
        std::istream& stream;
};

#endif // LEXER_H
