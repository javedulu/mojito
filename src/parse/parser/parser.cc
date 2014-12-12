#include <cstdlib>
#include <cstdio>
#include <memory>

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
    std::unique_ptr<lex::Lexeme> lexeme;
    bool parsing = true;

    while (parsing && !error())
    {
        lexeme.reset(m_lexer.consume());
        if ((lexeme->type() != lex::Lexeme::Type::Spaces) &&
            (lexeme->type()!=lex::Lexeme::Type::Newline))
        {
            umodParse(m_yyp, static_cast<int>(lexeme->type()), lexeme.get(), this);
            if (lexeme->type() == lex::Lexeme::Type::End)
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
        throw Exception("Unexpected token", *lexeme, errors());
    }
}
