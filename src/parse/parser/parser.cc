#include <cstdlib>
#include <cstdio>
#include <memory>
#include <iostream>

#include "parser.h"
#include "exception.h"

using namespace umod::parser;

Parser::Parser(lex::Lexer &lexer)
    : m_lexer(lexer)
    , m_error(false)
    //, m_program(nullptr)
{
    m_yyp = umodParseAlloc(&malloc);
}

Parser::~Parser()
{
    umodParseFree(m_yyp, &free);
}

void Parser::exec()
{
    std::string prompt= ">>>";
    //FILE *fp;
    
    //fp = fopen("/Users/phryne/Desktop/out.txt","w");
    //umodParseTrace(fp,(char *)prompt.c_str());
    std::unique_ptr<lex::Lexeme> lexeme;
    bool parsing = true;

    while (parsing && !error())
    {
        lexeme.reset(m_lexer.consume());
        if ((lexeme->type() != lex::Lexeme::Type::SPACES) &&
               (lexeme->type()!=lex::Lexeme::Type::NEWLINE))
        {
            
            //std::cout << lexeme->as<std::string>()
            //<< " @>>"
            //<< lexeme->position().first<< ":" <<  lexeme->position().second
            //<< " @type:"<< (int) lexeme->type()
            //<< std::endl;
            
            umodParse(m_yyp, static_cast<int>(lexeme->type()), lexeme.get(), this);
            if (lexeme->type() == lex::Lexeme::Type::EOI)
            {
                parsing=false;
            }
            if (!error())
            {
                lexeme.release();
            }
        }
    }
    if (error())
    {
        //throw Exception("Unexpected token", *lexeme, errors());
        Exception("Unexpected token", *lexeme, errors());
        exit(-1);
    }
    
}
