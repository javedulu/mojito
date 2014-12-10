#ifndef UMOD_LEX_LEXER_H_
#define UMOD_LEX_LEXER_H_

#include <utility>
#include "lexeme.h"

namespace umod 
{
    namespace lex
    {
        class Lexer
        {
        public:
            Lexer(const char *source, unsigned int length);
            Lexer(const std::string &source);
            ~Lexer();

            lex::Lexeme *consume(void);

        private:
            const char *m_source;
            const char *m_source_end;
            const char *m_source_eof;
            const char *m_ts;
            const char *m_te;
            int m_current_state;
            int m_act;

            Lexeme::pos_t m_position;
        };
    }
}

#endif /* UMOD_LEX_LEXER_H_ */
