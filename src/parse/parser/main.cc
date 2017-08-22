#include <cstdlib>
#include <iostream>
#include "lemon-parser.h"

using namespace std;

void* umodParseAlloc(void *(allocProc)(size_t));
void* umodParse(void *, int , const char*);
void* umodParseFree(void *, void(*freeProc)(void*));

void checkWithin(void* neoparse)
{
    
    // Full qualified within defn
    umodParse(neoparse,UMOD_LEXEME_TYPE_WITHIN,"within");
    umodParse(neoparse,UMOD_LEXEME_TYPE_IDENT,"Modelica");
    umodParse(neoparse,UMOD_LEXEME_TYPE_DOT,".");
    umodParse(neoparse,UMOD_LEXEME_TYPE_IDENT,"Mechanics");
    umodParse(neoparse,UMOD_LEXEME_TYPE_DOT,".");
    umodParse(neoparse,UMOD_LEXEME_TYPE_IDENT,"Rotational");
    umodParse(neoparse,UMOD_LEXEME_TYPE_SEMICOLON,";");
    umodParse(neoparse,0,0);
    // within ;
    umodParse(neoparse,UMOD_LEXEME_TYPE_WITHIN,"within");
    umodParse(neoparse,UMOD_LEXEME_TYPE_SEMICOLON,";");
    umodParse(neoparse,0,0);
    // ;
    umodParse(neoparse,UMOD_LEXEME_TYPE_SEMICOLON,";");
    umodParse(neoparse,0,0);
    // within Modelica ;
    umodParse(neoparse,UMOD_LEXEME_TYPE_WITHIN,"within");
    umodParse(neoparse,UMOD_LEXEME_TYPE_IDENT,"Modelica");
    umodParse(neoparse,UMOD_LEXEME_TYPE_SEMICOLON,";");
    umodParse(neoparse,0,0);
    // within // SHould it be supported
    umodParse(neoparse,UMOD_LEXEME_TYPE_WITHIN,"within");
    umodParse(neoparse,UMOD_LEXEME_TYPE_WITHIN,";");
    umodParse(neoparse,0,0);
}

int main()
{
    void* neoparse = umodParseAlloc(malloc);
    
    
    umodParse(neoparse,0,0);
    umodParseFree(neoparse,free);
    return 0;
}
