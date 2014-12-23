#include <iostream>
#include <fstream>

#include "lexer.h"

using namespace umod::lex;
int main(int argc, char **argv)
{
    
    std::string filename = (argc > 1 ? argv[1]:"/Users/phryne/Desktop/Rotational.mo");
    
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
            if (lexeme->type() == Lexeme::Type::EOI)
            {
                parsing = false;
            }
            else{
                //umodParse(neoparse,TOK_WITHIN, "within");
                std::string typestr;
                switch((int)lexeme->type())
                {

                    case UMOD_LEXEME_TYPE_PLUS                           : typestr = "UMOD_LEXEME_TYPE_PLUS"; break;
                    case UMOD_LEXEME_TYPE_MINUS                          : typestr = "UMOD_LEXEME_TYPE_MINUS"; break;
                    case UMOD_LEXEME_TYPE_MUL                            : typestr = "UMOD_LEXEME_TYPE_MUL"; break;
                    case UMOD_LEXEME_TYPE_DIV                            : typestr = "UMOD_LEXEME_TYPE_DIV"; break;
                    case UMOD_LEXEME_TYPE_ASSIGN                         : typestr = "UMOD_LEXEME_TYPE_ASSIGN"; break;
                    case UMOD_LEXEME_TYPE_PLUSASSIGN                     : typestr = "UMOD_LEXEME_TYPE_PLUSASSIGN"; break;
                    case UMOD_LEXEME_TYPE_MINUSASSIGN                    : typestr = "UMOD_LEXEME_TYPE_MINUSASSIGN"; break;
                    case UMOD_LEXEME_TYPE_MULASSIGN                      : typestr = "UMOD_LEXEME_TYPE_MULASSIGN"; break;
                    case UMOD_LEXEME_TYPE_DIVASSIGN                      : typestr = "UMOD_LEXEME_TYPE_DIVASSIGN"; break;
                    case UMOD_LEXEME_TYPE_GREATER                        : typestr = "UMOD_LEXEME_TYPE_GREATER"; break;
                    case UMOD_LEXEME_TYPE_GREATEROREQUAL                 : typestr = "UMOD_LEXEME_TYPE_GREATEROREQUAL"; break;
                    case UMOD_LEXEME_TYPE_LESSER                         : typestr = "UMOD_LEXEME_TYPE_LESSER"; break;
                    case UMOD_LEXEME_TYPE_LESSEROREQUAL                  : typestr = "UMOD_LEXEME_TYPE_LESSEROREQUAL"; break;
                    case UMOD_LEXEME_TYPE_EQUAL                          : typestr = "UMOD_LEXEME_TYPE_EQUAL"; break;
                    case UMOD_LEXEME_TYPE_NOTEQUAL                       : typestr = "UMOD_LEXEME_TYPE_NOTEQUAL"; break;
                    case UMOD_LEXEME_TYPE_NOT                            : typestr = "UMOD_LEXEME_TYPE_NOT"; break;
                    case UMOD_LEXEME_TYPE_INV                            : typestr = "UMOD_LEXEME_TYPE_INV"; break;
                    case UMOD_LEXEME_TYPE_INCREMENTATION                 : typestr = "UMOD_LEXEME_TYPE_INCREMENTATION"; break;
                    case UMOD_LEXEME_TYPE_DECREMENTATION                 : typestr = "UMOD_LEXEME_TYPE_DECREMENTATION"; break;
                    case UMOD_LEXEME_TYPE_LPAREN                         : typestr = "UMOD_LEXEME_TYPE_LPAREN"; break;
                    case UMOD_LEXEME_TYPE_RPAREN                         : typestr = "UMOD_LEXEME_TYPE_RPAREN"; break;
                    case UMOD_LEXEME_TYPE_LBRACKET                       : typestr = "UMOD_LEXEME_TYPE_LBRACKET"; break;
                    case UMOD_LEXEME_TYPE_RBRACKET                       : typestr = "UMOD_LEXEME_TYPE_RBRACKET"; break;
                    case UMOD_LEXEME_TYPE_LBRACE                         : typestr = "UMOD_LEXEME_TYPE_LBRACE"; break;
                    case UMOD_LEXEME_TYPE_RBRACE                         : typestr = "UMOD_LEXEME_TYPE_RBRACE"; break;
                    case UMOD_LEXEME_TYPE_SEMICOLON                      : typestr = "UMOD_LEXEME_TYPE_SEMICOLON"; break;
                    case UMOD_LEXEME_TYPE_COLON                          : typestr = "UMOD_LEXEME_TYPE_COLON"; break;
                    case UMOD_LEXEME_TYPE_COMMA                          : typestr = "UMOD_LEXEME_TYPE_COMMA"; break;
                    case UMOD_LEXEME_TYPE_IDENT                          : typestr = "UMOD_LEXEME_TYPE_IDENT"; break;
                    case UMOD_LEXEME_TYPE_NUMBER                         : typestr = "UMOD_LEXEME_TYPE_NUMBER"; break;
                    case UMOD_LEXEME_TYPE_FLOAT                          : typestr = "UMOD_LEXEME_TYPE_FLOAT"; break;
                    case UMOD_LEXEME_TYPE_STRING                         : typestr = "UMOD_LEXEME_TYPE_STRING"; break;
                    case UMOD_LEXEME_TYPE_COMMENT                        : typestr = "UMOD_LEXEME_TYPE_COMMENT"; break;
                    case UMOD_LEXEME_TYPE_QUESTIONMARK                   : typestr = "UMOD_LEXEME_TYPE_QUESTIONMARK"; break;
                    case UMOD_LEXEME_TYPE_DOT                            : typestr = "UMOD_LEXEME_TYPE_DOT"; break;
                    case UMOD_LEXEME_TYPE_ALGORITHM                      : typestr = "UMOD_LEXEME_TYPE_ALGORITHM"; break;
                    case UMOD_LEXEME_TYPE_AND                            : typestr = "UMOD_LEXEME_TYPE_AND"; break;
                    case UMOD_LEXEME_TYPE_ANNOTATION                     : typestr = "UMOD_LEXEME_TYPE_ANNOTATION"; break;
                    case UMOD_LEXEME_TYPE_ASSERT                         : typestr = "UMOD_LEXEME_TYPE_ASSERT"; break;
                    case UMOD_LEXEME_TYPE_BLOCK                          : typestr = "UMOD_LEXEME_TYPE_BLOCK"; break;
                    case UMOD_LEXEME_TYPE_BREAK                          : typestr = "UMOD_LEXEME_TYPE_BREAK"; break;
                    case UMOD_LEXEME_TYPE_CLASS                          : typestr = "UMOD_LEXEME_TYPE_CLASS"; break;
                    case UMOD_LEXEME_TYPE_CONNECT                        : typestr = "UMOD_LEXEME_TYPE_CONNECT"; break;
                    case UMOD_LEXEME_TYPE_CONNECTOR                      : typestr = "UMOD_LEXEME_TYPE_CONNECTOR"; break;
                    case UMOD_LEXEME_TYPE_CONSTANT                       : typestr = "UMOD_LEXEME_TYPE_CONSTANT"; break;
                    case UMOD_LEXEME_TYPE_CONSTRAINEDBY                  : typestr = "UMOD_LEXEME_TYPE_CONSTRAINEDBY"; break;
                    case UMOD_LEXEME_TYPE_DER                            : typestr = "UMOD_LEXEME_TYPE_DER"; break;
                    case UMOD_LEXEME_TYPE_DISCRETE                       : typestr = "UMOD_LEXEME_TYPE_DISCRETE"; break;
                    case UMOD_LEXEME_TYPE_EACH                           : typestr = "UMOD_LEXEME_TYPE_EACH"; break;
                    case UMOD_LEXEME_TYPE_ELSE                           : typestr = "UMOD_LEXEME_TYPE_ELSE"; break;
                    case UMOD_LEXEME_TYPE_ELSEIF                         : typestr = "UMOD_LEXEME_TYPE_ELSEIF"; break;
                    case UMOD_LEXEME_TYPE_ELSEWHEN                       : typestr = "UMOD_LEXEME_TYPE_ELSEWHEN"; break;
                    case UMOD_LEXEME_TYPE_ENCAPSULATED                   : typestr = "UMOD_LEXEME_TYPE_ENCAPSULATED"; break;
                    case UMOD_LEXEME_TYPE_END                            : typestr = "UMOD_LEXEME_TYPE_END"; break;
                    case UMOD_LEXEME_TYPE_ENUMERATION                    : typestr = "UMOD_LEXEME_TYPE_ENUMERATION"; break;
                    case UMOD_LEXEME_TYPE_EQUATION                       : typestr = "UMOD_LEXEME_TYPE_EQUATION"; break;
                    case UMOD_LEXEME_TYPE_EXPANDABLE                     : typestr = "UMOD_LEXEME_TYPE_EXPANDABLE"; break;
                    case UMOD_LEXEME_TYPE_EXPONENT                       : typestr = "UMOD_LEXEME_TYPE_EXPONENT"; break;
                    case UMOD_LEXEME_TYPE_EXTENDS                        : typestr = "UMOD_LEXEME_TYPE_EXTENDS"; break;
                    case UMOD_LEXEME_TYPE_EXTERNAL                       : typestr = "UMOD_LEXEME_TYPE_EXTERNAL"; break;
                    case UMOD_LEXEME_TYPE_FALSE                          : typestr = "UMOD_LEXEME_TYPE_FALSE"; break;
                    case UMOD_LEXEME_TYPE_FINAL                          : typestr = "UMOD_LEXEME_TYPE_FINAL"; break;
                    case UMOD_LEXEME_TYPE_FLOW                           : typestr = "UMOD_LEXEME_TYPE_FLOW"; break;
                    case UMOD_LEXEME_TYPE_FOR                            : typestr = "UMOD_LEXEME_TYPE_FOR"; break;
                    case UMOD_LEXEME_TYPE_FUNCTION                       : typestr = "UMOD_LEXEME_TYPE_FUNCTION"; break;
                    case UMOD_LEXEME_TYPE_IF                             : typestr = "UMOD_LEXEME_TYPE_IF"; break;
                    case UMOD_LEXEME_TYPE_IMPORT                         : typestr = "UMOD_LEXEME_TYPE_IMPORT"; break;
                    case UMOD_LEXEME_TYPE_IMPURE                         : typestr = "UMOD_LEXEME_TYPE_IMPURE"; break;
                    case UMOD_LEXEME_TYPE_IN                             : typestr = "UMOD_LEXEME_TYPE_IN"; break;
                    case UMOD_LEXEME_TYPE_INITIAL                        : typestr = "UMOD_LEXEME_TYPE_INITIAL"; break;
                    case UMOD_LEXEME_TYPE_INNER                          : typestr = "UMOD_LEXEME_TYPE_INNER"; break;
                    case UMOD_LEXEME_TYPE_INPUT                          : typestr = "UMOD_LEXEME_TYPE_INPUT"; break;
                    case UMOD_LEXEME_TYPE_LOOP                           : typestr = "UMOD_LEXEME_TYPE_LOOP"; break;
                    case UMOD_LEXEME_TYPE_MODEL                          : typestr = "UMOD_LEXEME_TYPE_MODEL"; break;
                    case UMOD_LEXEME_TYPE_NEGATE                         : typestr = "UMOD_LEXEME_TYPE_NEGATE"; break;
                    case UMOD_LEXEME_TYPE_OPERATOR                       : typestr = "UMOD_LEXEME_TYPE_OPERATOR"; break;
                    case UMOD_LEXEME_TYPE_OR                             : typestr = "UMOD_LEXEME_TYPE_OR"; break;
                    case UMOD_LEXEME_TYPE_OUTER                          : typestr = "UMOD_LEXEME_TYPE_OUTER"; break;
                    case UMOD_LEXEME_TYPE_OUTPUT                         : typestr = "UMOD_LEXEME_TYPE_OUTPUT"; break;
                    case UMOD_LEXEME_TYPE_PACKAGE                        : typestr = "UMOD_LEXEME_TYPE_PACKAGE"; break;
                    case UMOD_LEXEME_TYPE_PARAMETER                      : typestr = "UMOD_LEXEME_TYPE_PARAMETER"; break;
                    case UMOD_LEXEME_TYPE_PARTIAL                        : typestr = "UMOD_LEXEME_TYPE_PARTIAL"; break;
                    case UMOD_LEXEME_TYPE_PROTECTED                      : typestr = "UMOD_LEXEME_TYPE_PROTECTED"; break;
                    case UMOD_LEXEME_TYPE_PUBLIC                         : typestr = "UMOD_LEXEME_TYPE_PUBLIC"; break;
                    case UMOD_LEXEME_TYPE_PURE                           : typestr = "UMOD_LEXEME_TYPE_PURE"; break;
                    case UMOD_LEXEME_TYPE_RECORD                         : typestr = "UMOD_LEXEME_TYPE_RECORD"; break;
                    case UMOD_LEXEME_TYPE_REDECLARE                      : typestr = "UMOD_LEXEME_TYPE_REDECLARE"; break;
                    case UMOD_LEXEME_TYPE_REPLACEABLE                    : typestr = "UMOD_LEXEME_TYPE_REPLACEABLE"; break;
                    case UMOD_LEXEME_TYPE_RETURN                         : typestr = "UMOD_LEXEME_TYPE_RETURN"; break;
                    case UMOD_LEXEME_TYPE_STREAM                         : typestr = "UMOD_LEXEME_TYPE_STREAM"; break;
                    case UMOD_LEXEME_TYPE_THEN                           : typestr = "UMOD_LEXEME_TYPE_THEN"; break;
                    case UMOD_LEXEME_TYPE_TRUE                           : typestr = "UMOD_LEXEME_TYPE_TRUE"; break;
                    case UMOD_LEXEME_TYPE_TYPE                           : typestr = "UMOD_LEXEME_TYPE_TYPE"; break;
                    case UMOD_LEXEME_TYPE_WHEN                           : typestr = "UMOD_LEXEME_TYPE_WHEN"; break;
                    case UMOD_LEXEME_TYPE_WHILE                          : typestr = "UMOD_LEXEME_TYPE_WHILE"; break;
                    case UMOD_LEXEME_TYPE_WITHIN                         : typestr = "UMOD_LEXEME_TYPE_WITHIN"; break;
                    case UMOD_LEXEME_TYPE_NEWLINE                        : typestr = "UMOD_LEXEME_TYPE_NEWLINE"; break;
                    default:
                        std::stringstream ss;
                        ss<<(int)lexeme->type();
                        typestr = ss.str();
                        break;
                }
                std::cout<<"umodParse(neoparse,"<<typestr <<",\""<<lexeme->as<std::string>()<<"\");"<<std::endl;
                //std::cout << lexeme->as<std::string>()<< " @>>"<< lexeme->position().first<< ":" <<  lexeme->position().second<<" @type:"<< (int) lexeme->type()<< std::endl;
            }
        }
    }

    return 0;
}
