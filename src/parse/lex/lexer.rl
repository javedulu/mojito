#include <stddef.h>
#include <string>
#include <utility>
#include "lexer.h"
#include "lexeme.h"

// NOTE : if the lemon-parser is properly done then all the #define in lemon-parser.h should be equal
//        to total no of tokens
//        lemon-parser.h is generated by lemon based on whats used in parser , so if all the cases are
//              considered then there should be no token not # defined failsafe
%% machine umodLexer;
%% write data;

// no idea about the origins of this value, ask Flori ;)
int EVIL=0x666;

using namespace umod::lex;

Lexer::Lexer(const char *source, unsigned int length)
    : m_source(source)
    , m_source_end(source + length)
    , m_source_eof(m_source_end)
    , m_ts(nullptr), m_te(nullptr)
    , m_current_state(EVIL), m_act(0)
    , m_position(std::make_pair(1, 1))
{

}

Lexer::Lexer(const std::string &source): Lexer(source.c_str(), source.length())
{

}

Lexer::~Lexer()
{

}

Lexeme *Lexer::consume(void)
{
    %%{
		NONDIGIT         = [_a-zA-Z];
        DIGIT            =[0-9];
        QCHAR           = (NONDIGIT)+ | (DIGIT)+ | [!#$%&()*+,\-./:;<>=?@[\]\^{}|~ ];
        SESCAPE         = '\\'[\'\"\?\\abfnrtv];
        QIDENT          = "'" ( (QCHAR)+ | (SESCAPE)+ )+ "'";
        IDENT            = (NONDIGIT)+ ( (DIGIT)+ | (NONDIGIT)+ )* | (QIDENT)+;
        SCHAR           = [^\"\\];
        STRING           = '"' ( (SCHAR)+ | (SESCAPE)+ )* '"';
        UNSIGNED_INTEGER =(DIGIT)+;
        UNSIGNED_NUMBER  =(UNSIGNED_INTEGER) ("." (UNSIGNED_INTEGER)? )? ([eE][+\-]? (UNSIGNED_INTEGER) )?;
				
        spaces              = (' '|'\t')+;
        newline             = ('\r'|'\n');
		
        exp_op              = ('.^'|'^');
        mul_op_partial      = ('./'|'/'|'*');
        add_op_partial      = ('.+'|'.-'|'-');
        rel_op              = ('=='|'<>'|'<='|'<'|'>='|'>');
        
        linecomment         =  '//'[^\n]*;
        blockcomment        = '/*' ( any* - (any* '*/' any* ) ) '*/';
        comment             = linecomment | blockcomment;
		
        end_ident           = 'end'(' '|'\t'|'\n')+IDENT;
        end_if              = 'end'(' '|'\t'|'\n')'if';
        end_for             = 'end'(' '|'\t'|'\n')'for';
        end_when            = 'end'(' '|'\t'|'\n')'when';
        end_while           = 'end'(' '|'\t'|'\n')'while';
        initial_equation    = 'initial'(' '|'\t'|'\n')'equation';
        initial_algorithm   = 'initial'(' '|'\t'|'\n')'algorithm';
        operator_function   = 'operator'(' '|'\t'|'\n')'function';

        main := |*
        
        end_if                  => { type = Lexeme::Type::END_IF; fbreak; };
        end_for                 => { type = Lexeme::Type::END_FOR; fbreak; };
        end_when                => { type = Lexeme::Type::END_WHEN; fbreak; };
        end_while               => { type = Lexeme::Type::END_WHILE; fbreak; };
        initial_equation        => { type = Lexeme::Type::INITIAL_EQUATION; fbreak; };
        initial_algorithm       => { type = Lexeme::Type::INITIAL_ALGORITHM; fbreak; };
        operator_function       => { type = Lexeme::Type::OPERATOR_FUNCTION; fbreak; };
        end_ident               => { type = Lexeme::Type::END_IDENT; fbreak; };
        
        "algorithm"             => { type = Lexeme::Type::ALGORITHM; fbreak;};
        "and"                   => { type = Lexeme::Type::AND; fbreak;};
        "annotation"            => { type = Lexeme::Type::ANNOTATION; fbreak;};
        "block"                 => { type = Lexeme::Type::BLOCK; fbreak;};
        "break"                 => { type = Lexeme::Type::BREAK; fbreak;};
        "class"                 => { type = Lexeme::Type::CLASS; fbreak;};
        "connector"             => { type = Lexeme::Type::CONNECTOR; fbreak;};
        "connect"               => { type = Lexeme::Type::CONNECT; fbreak;};
        "constant"              => { type = Lexeme::Type::CONSTANT; fbreak;};
        "constrainedby"         => { type = Lexeme::Type::CONSTRAINEDBY; fbreak;};
        "der"                   => { type = Lexeme::Type::DER; fbreak;};
        "discrete"              => { type = Lexeme::Type::DISCRETE; fbreak;};
        "each"                  => { type = Lexeme::Type::EACH; fbreak;};
        "else"                  => { type = Lexeme::Type::ELSE; fbreak;};
        "elseif"                => { type = Lexeme::Type::ELSEIF; fbreak;};
        "elsewhen"              => { type = Lexeme::Type::ELSEWHEN; fbreak;};
        "encapsulated"          => { type = Lexeme::Type::ENCAPSULATED; fbreak;};
        "end"                   => { type = Lexeme::Type::END; fbreak;};
        "enumeration"           => { type = Lexeme::Type::ENUMERATION; fbreak;};
        "equation"              => { type = Lexeme::Type::EQUATION; fbreak;};
        "expandable"            => { type = Lexeme::Type::EXPANDABLE; fbreak;};
        "extends"               => { type = Lexeme::Type::EXTENDS; fbreak;};
        "external"              => { type = Lexeme::Type::EXTERNAL; fbreak;};
        "false"                 => { type = Lexeme::Type::FALSE; fbreak;};
        "final"                 => { type = Lexeme::Type::FINAL; fbreak;};
        "flow"                  => { type = Lexeme::Type::FLOW; fbreak;};
        "for"                   => { type = Lexeme::Type::FOR; fbreak;};
        "function"              => { type = Lexeme::Type::FUNCTION; fbreak;};
        "if"                    => { type = Lexeme::Type::IF; fbreak;};
        "import"                => { type = Lexeme::Type::IMPORT; fbreak;};
        "impure"                => { type = Lexeme::Type::IMPURE; fbreak;};
        "in"                    => { type = Lexeme::Type::IN; fbreak;};
        "initial"               => { type = Lexeme::Type::INITIAL; fbreak;};
        "inner"                 => { type = Lexeme::Type::INNER; fbreak;};
        "input"                 => { type = Lexeme::Type::INPUT; fbreak;};
        "loop"                  => { type = Lexeme::Type::LOOP; fbreak;};
        "model"                 => { type = Lexeme::Type::MODEL; fbreak;};
        "not"                   => { type = Lexeme::Type::NOT; fbreak;};
        "operator"              => { type = Lexeme::Type::OPERATOR; fbreak;};
        "or"                    => { type = Lexeme::Type::OR; fbreak;};
        "outer"                 => { type = Lexeme::Type::OUTER; fbreak;};
        "output"                => { type = Lexeme::Type::OUTPUT; fbreak;};
        "package"               => { type = Lexeme::Type::PACKAGE; fbreak;};
        "parameter"             => { type = Lexeme::Type::PARAMETER; fbreak;};
        "partial"               => { type = Lexeme::Type::PARTIAL; fbreak;};
        "protected"             => { type = Lexeme::Type::PROTECTED; fbreak;};
        "public"                => { type = Lexeme::Type::PUBLIC; fbreak;};
        "pure"                  => { type = Lexeme::Type::PURE; fbreak;};
        "record"                => { type = Lexeme::Type::RECORD; fbreak;};
        "redeclare"             => { type = Lexeme::Type::REDECLARE; fbreak;};
        "replaceable"           => { type = Lexeme::Type::REPLACEABLE; fbreak;};
        "return"                => { type = Lexeme::Type::RETURN; fbreak;};
        "stream"                => { type = Lexeme::Type::STREAM; fbreak;};
        "then"                  => { type = Lexeme::Type::THEN; fbreak;};
        "true"                  => { type = Lexeme::Type::TRUE; fbreak;};
        "type"                  => { type = Lexeme::Type::TYPE; fbreak;};
        "when"                  => { type = Lexeme::Type::WHEN; fbreak;};
        "while"                 => { type = Lexeme::Type::WHILE; fbreak;};
        "within"                => { type = Lexeme::Type::WITHIN; fbreak;};
       
        IDENT                   => { type = Lexeme::Type::IDENT; fbreak; };
        STRING                  => { type = Lexeme::Type::STRING; fbreak; };
        UNSIGNED_NUMBER         => { type = Lexeme::Type::UNSIGNED_NUMBER; fbreak; };
        
        ".*"                    => { type = Lexeme::Type::DOT_STAR; fbreak;};
        ":="                    => { type = Lexeme::Type::ASSIGN_OP; fbreak;};
        rel_op                  => { type = Lexeme::Type::REL_OP; fbreak;};
        add_op_partial          => { type = Lexeme::Type::ADD_OP_PARTIAL; fbreak;};
        mul_op_partial          => { type = Lexeme::Type::MUL_OP_PARTIAL; fbreak;};
        exp_op                  => { type = Lexeme::Type::EXP_OP; fbreak;};
        
        "."                     => { type = Lexeme::Type::DOT; fbreak;};
        ","                     => { type = Lexeme::Type::COMMA; fbreak;};
        ";"                     => { type = Lexeme::Type::SEMICOLON; fbreak;};
        ":"                     => { type = Lexeme::Type::COLON; fbreak;};
        "("                     => { type = Lexeme::Type::OPAREN; fbreak;};
        ")"                     => { type = Lexeme::Type::CPAREN; fbreak;};
        "{"                     => { type = Lexeme::Type::OBRACE; fbreak;};
        "}"                     => { type = Lexeme::Type::CBRACE; fbreak;};
        "["                     => { type = Lexeme::Type::OBRACKET; fbreak;};
        "]"                     => { type = Lexeme::Type::CBRACKET; fbreak;};
        "="                     => { type = Lexeme::Type::EQUAL; fbreak;};
        "+"                     => { type = Lexeme::Type::PLUS; fbreak;};
        
        
        newline                 => { type = Lexeme::Type::NEWLINE; fbreak; };
        spaces                  => { type = Lexeme::Type::SPACES; fbreak; };
        comment                 => { fbreak; };
        any                     => { fbreak; };
        *|;
    }%%

    Lexeme::Type type = Lexeme::Type::SPACES;

    if (m_source == m_source_end)
    {
        m_ts = m_te = m_source;
        type = Lexeme::Type::EOI;
    }
    else
    {
        %% variable cs  m_current_state;
        %% variable p   m_source;
        %% variable pe  m_source_end;
        %% variable eof m_source_eof;
        %% variable ts  m_ts;
        %% variable te  m_te;
        %% variable act m_act;

        %% write init;
        %% write exec;
    }

    unsigned int size = m_te - m_ts;
    Lexeme::pos_t position = m_position;

    if (type == Lexeme::Type::NEWLINE)
    {
        m_position.first += 1;
        m_position.second = size;
    }
    else
    {
        m_position.second += size;
    }

    return new Lexeme(type, std::string(m_ts, size), position);
}
