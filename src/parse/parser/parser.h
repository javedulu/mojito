#ifndef UMOD_PARSER_PARSER_H_
#define UMOD_PARSER_PARSER_H_

#include <stddef.h>
#include <vector>
#include <string>
#include "lexer.h"

namespace umod
{
    namespace parser
    {
        class Parser
        {
            public:
                Parser(lex::Lexer &lexer);
                ~Parser();

                void exec(void);

                inline bool error(void) const
                {
                    return m_error;
                }

                inline Parser &error(bool error)
                {
                    m_error = error;
                    return *this;
                }
                inline std::vector<std::string> &errors(void)
                {
                    return m_errors;
                }

            private:
                void *m_yyp;
                lex::Lexer &m_lexer;
                bool m_error;
                std::vector<std::string> m_errors;
        };
    }
}

void *umodParseAlloc(void *(*mallocProc)(size_t));
void umodParseFree(void *p, void (*freeProc)(void*));
void umodParse(void *yyp, int yymajor, umod::lex::Lexeme *yyminor,umod::parser::Parser *parser);


#endif /* UMOD_PARSER_PARSER_H_ */
