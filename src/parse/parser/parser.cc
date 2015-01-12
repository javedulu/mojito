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
    FILE *fp;
    fp=fopen("/Users/phryne/Desktop/out.log", "w+");
    std::string prompt = ">>> ";
    umodParseTrace(fp, (char *)prompt.c_str());
    std::unique_ptr<lex::Lexeme> lexeme;
    bool parsing = true;

    while (parsing && !error())
    {
        lexeme.reset(m_lexer.consume());
        if ((lexeme->type() != lex::Lexeme::Type::SPACES) && (lexeme->type()!=lex::Lexeme::Type::NEWLINE))
        {
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
        for (auto err : errors())
        {
            std::cerr<<"error ..."<<err<<std::endl;
        }
        std::cout<<" "<< lex::Lexeme::typeString(lexeme->type())<<" at line " << lexeme->position().first << " , column "<< lexeme->position().second;
        //throw Exception("Unexpected token", *lexeme, errors());
    }
    
}
