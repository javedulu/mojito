#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "lexer.h"

using namespace umod::lex;
int main(int argc, char **argv)
{
    
    std::string filename = (argc > 1 ? argv[1]:"/Users/phryne/Desktop/a.mo");
    
    std::ifstream ifs(filename, std::ifstream::in);
    std::string istr((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>()); //
    
    Lexer lexr(istr);
    std::unique_ptr<Lexeme> lexeme;
    bool parsing = true;
    while(parsing)
    {
        lexeme.reset(lexr.consume());
        if (lexeme->type() != Lexeme::Type::SPACES && lexeme->type() != Lexeme::Type::NEWLINE)
        {
            //EcmaParse(m_yyp, static_cast<int>(lexeme->type()), lexeme.get(), this);
            if (lexeme->type() == Lexeme::Type::EOI)
            {
                parsing = false;
            }
            else{
                std::cout << lexeme->as<std::string>()
                << " @>>"
                << lexeme->position().first<< ":" <<  lexeme->position().second
                << " @type:"<< (int) lexeme->type()
                << std::endl;

            }
        }
    }

    return 0;
}

