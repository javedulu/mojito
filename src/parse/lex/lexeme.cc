#include "lexeme.h"

using namespace umod::lex;

/**
 *  @author javedulu, 16-05-31 00:05:40
 *
 *  <#Description#>
 *
 *  @param type <#type description#>
 *
 *  @return <#return value description#>
 *
 *  @since <#version number#>
 */
const char *Lexeme::typeString(Lexeme::Type type)
{
    switch (type)
    {
        #define UMOD_LEXEME_NAME(name) #name
        #define UMOD_LEXEME(name) case Lexeme::Type::name: return UMOD_LEXEME_NAME(name);
        #define UMOD_AUTO_LEXEME(name) UMOD_LEXEME(name)
        #define UMOD_DEFINE_LEXEME(name, value) UMOD_LEXEME(name)

        #include "types.h"

        #undef UMOD_LEXEME_NAME
        #undef UMOD_LEXEME
        #undef UMOD_AUTO_LEXEME
        #undef UMOD_DEFINE_LEXEME
    }
    return nullptr;
}
