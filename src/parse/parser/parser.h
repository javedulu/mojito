#ifndef UMOD_PARSER_PARSE_H_
#define UMOD_PARSER_PARSE_H_

#include <stddef.h>
#include <vector>
#include <string>
#include "lexer.h"
#include "../ast/StoredDefinition.h"


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
                inline ast::StoredDefinition *program(void) const
                {
                    return m_program;
                }
                inline Parser &program(ast::StoredDefinition *program)
                {
                    m_program = program;
                    return *this;
                }
            private:
                void *m_yyp;
                lex::Lexer &m_lexer;
                bool m_error;
                std::vector<std::string> m_errors;
                ast::StoredDefinition *m_program;
        };
    }
}

void *umodParseAlloc(void *(*mallocProc)(size_t));
void umodParseFree(void *p, void (*freeProc)(void*));
void umodParse(void *yyp, int yymajor, umod::lex::Lexeme *yyminor,umod::parser::Parser *parser);
void umodParseTrace(FILE *TraceFILE, char *zTracePrompt);


#endif /* UMOD_PARSER_PARSE_H_ */
