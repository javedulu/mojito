
#line 1 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
#include <stddef.h>
#include <string>
#include <utility>
#include "lexer.h"
#include "lexeme.h"


#line 8 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"

#line 13 "lexer.cc"
static const char _umodLexer_actions[] = {
	0, 1, 0, 1, 1, 1, 15, 1, 
	16, 1, 17, 1, 18, 1, 19, 1, 
	20, 1, 21, 1, 22, 1, 23, 1, 
	24, 1, 25, 1, 26, 1, 27, 1, 
	28, 1, 29, 1, 30, 1, 31, 1, 
	32, 1, 33, 1, 34, 1, 35, 1, 
	36, 1, 37, 1, 38, 1, 39, 1, 
	40, 1, 41, 1, 42, 1, 43, 1, 
	44, 1, 45, 1, 46, 1, 47, 1, 
	48, 1, 49, 1, 50, 1, 51, 1, 
	52, 1, 53, 1, 54, 2, 2, 3, 
	2, 2, 4, 2, 2, 5, 2, 2, 
	6, 2, 2, 7, 2, 2, 8, 2, 
	2, 9, 2, 2, 10, 2, 2, 11, 
	2, 2, 12, 2, 2, 13, 2, 2, 
	14
};

static const short _umodLexer_key_offsets[] = {
	0, 2, 4, 6, 8, 50, 52, 53, 
	55, 63, 64, 66, 67, 69, 71, 73, 
	74, 76, 77, 78, 79, 88, 97, 106, 
	116, 125, 134, 143, 152, 161, 170, 179, 
	188, 197, 206, 215, 224, 233, 242, 251, 
	260, 269, 278, 287, 296, 305, 314, 323, 
	332, 341, 350, 359, 368, 377, 386
};

static const char _umodLexer_trans_keys[] = {
	34, 92, 34, 92, 39, 92, 39, 92, 
	9, 10, 32, 33, 34, 36, 37, 39, 
	40, 41, 42, 43, 44, 45, 46, 47, 
	58, 59, 60, 61, 62, 63, 91, 93, 
	95, 101, 102, 105, 110, 114, 116, 117, 
	118, 123, 125, 126, 48, 57, 65, 90, 
	97, 122, 9, 32, 61, 34, 92, 36, 
	95, 48, 57, 65, 90, 97, 122, 61, 
	39, 92, 61, 43, 61, 45, 61, 47, 
	61, 10, 48, 57, 61, 61, 61, 36, 
	95, 108, 48, 57, 65, 90, 97, 122, 
	36, 95, 115, 48, 57, 65, 90, 97, 
	122, 36, 95, 101, 48, 57, 65, 90, 
	97, 122, 36, 95, 97, 117, 48, 57, 
	65, 90, 98, 122, 36, 95, 108, 48, 
	57, 65, 90, 97, 122, 36, 95, 115, 
	48, 57, 65, 90, 97, 122, 36, 95, 
	101, 48, 57, 65, 90, 97, 122, 36, 
	95, 110, 48, 57, 65, 90, 97, 122, 
	36, 95, 99, 48, 57, 65, 90, 97, 
	122, 36, 95, 116, 48, 57, 65, 90, 
	97, 122, 36, 95, 105, 48, 57, 65, 
	90, 97, 122, 36, 95, 111, 48, 57, 
	65, 90, 97, 122, 36, 95, 110, 48, 
	57, 65, 90, 97, 122, 36, 95, 102, 
	48, 57, 65, 90, 97, 122, 36, 95, 
	117, 48, 57, 65, 90, 97, 122, 36, 
	95, 108, 48, 57, 65, 90, 97, 122, 
	36, 95, 108, 48, 57, 65, 90, 97, 
	122, 36, 95, 101, 48, 57, 65, 90, 
	97, 122, 36, 95, 116, 48, 57, 65, 
	90, 97, 122, 36, 95, 117, 48, 57, 
	65, 90, 97, 122, 36, 95, 114, 48, 
	57, 65, 90, 97, 122, 36, 95, 110, 
	48, 57, 65, 90, 97, 122, 36, 95, 
	114, 48, 57, 65, 90, 97, 122, 36, 
	95, 117, 48, 57, 65, 90, 97, 122, 
	36, 95, 101, 48, 57, 65, 90, 97, 
	122, 36, 95, 110, 48, 57, 65, 90, 
	97, 122, 36, 95, 100, 48, 57, 65, 
	90, 97, 122, 36, 95, 101, 48, 57, 
	65, 90, 97, 122, 36, 95, 102, 48, 
	57, 65, 90, 97, 122, 36, 95, 105, 
	48, 57, 65, 90, 97, 122, 36, 95, 
	110, 48, 57, 65, 90, 97, 122, 36, 
	95, 101, 48, 57, 65, 90, 97, 122, 
	36, 95, 100, 48, 57, 65, 90, 97, 
	122, 36, 95, 97, 48, 57, 65, 90, 
	98, 122, 36, 95, 114, 48, 57, 65, 
	90, 97, 122, 0
};

static const char _umodLexer_single_lengths[] = {
	2, 2, 2, 2, 36, 2, 1, 2, 
	2, 1, 2, 1, 2, 2, 2, 1, 
	0, 1, 1, 1, 3, 3, 3, 4, 
	3, 3, 3, 3, 3, 3, 3, 3, 
	3, 3, 3, 3, 3, 3, 3, 3, 
	3, 3, 3, 3, 3, 3, 3, 3, 
	3, 3, 3, 3, 3, 3, 3
};

static const char _umodLexer_range_lengths[] = {
	0, 0, 0, 0, 3, 0, 0, 0, 
	3, 0, 0, 0, 0, 0, 0, 0, 
	1, 0, 0, 0, 3, 3, 3, 3, 
	3, 3, 3, 3, 3, 3, 3, 3, 
	3, 3, 3, 3, 3, 3, 3, 3, 
	3, 3, 3, 3, 3, 3, 3, 3, 
	3, 3, 3, 3, 3, 3, 3
};

static const short _umodLexer_index_offsets[] = {
	0, 3, 6, 9, 12, 52, 55, 57, 
	60, 66, 68, 71, 73, 76, 79, 82, 
	84, 86, 88, 90, 92, 99, 106, 113, 
	121, 128, 135, 142, 149, 156, 163, 170, 
	177, 184, 191, 198, 205, 212, 219, 226, 
	233, 240, 247, 254, 261, 268, 275, 282, 
	289, 296, 303, 310, 317, 324, 331
};

static const char _umodLexer_indicies[] = {
	2, 3, 1, 4, 3, 1, 2, 6, 
	5, 7, 6, 5, 9, 10, 9, 11, 
	12, 13, 14, 15, 16, 17, 18, 19, 
	20, 21, 22, 23, 25, 26, 27, 28, 
	29, 30, 31, 32, 13, 33, 34, 35, 
	36, 37, 38, 39, 40, 41, 42, 43, 
	24, 13, 13, 8, 9, 9, 44, 46, 
	45, 2, 3, 1, 13, 13, 13, 13, 
	13, 0, 48, 47, 2, 6, 5, 50, 
	49, 52, 53, 51, 55, 56, 54, 58, 
	59, 57, 60, 58, 24, 61, 63, 62, 
	65, 64, 67, 66, 13, 13, 69, 13, 
	13, 13, 68, 13, 13, 70, 13, 13, 
	13, 68, 13, 13, 71, 13, 13, 13, 
	68, 13, 13, 72, 73, 13, 13, 13, 
	68, 13, 13, 74, 13, 13, 13, 68, 
	13, 13, 75, 13, 13, 13, 68, 13, 
	13, 76, 13, 13, 13, 68, 13, 13, 
	77, 13, 13, 13, 68, 13, 13, 78, 
	13, 13, 13, 68, 13, 13, 79, 13, 
	13, 13, 68, 13, 13, 80, 13, 13, 
	13, 68, 13, 13, 81, 13, 13, 13, 
	68, 13, 13, 82, 13, 13, 13, 68, 
	13, 13, 83, 13, 13, 13, 68, 13, 
	13, 84, 13, 13, 13, 68, 13, 13, 
	85, 13, 13, 13, 68, 13, 13, 86, 
	13, 13, 13, 68, 13, 13, 87, 13, 
	13, 13, 68, 13, 13, 88, 13, 13, 
	13, 68, 13, 13, 89, 13, 13, 13, 
	68, 13, 13, 90, 13, 13, 13, 68, 
	13, 13, 91, 13, 13, 13, 68, 13, 
	13, 92, 13, 13, 13, 68, 13, 13, 
	93, 13, 13, 13, 68, 13, 13, 94, 
	13, 13, 13, 68, 13, 13, 95, 13, 
	13, 13, 68, 13, 13, 96, 13, 13, 
	13, 68, 13, 13, 97, 13, 13, 13, 
	68, 13, 13, 98, 13, 13, 13, 68, 
	13, 13, 99, 13, 13, 13, 68, 13, 
	13, 100, 13, 13, 13, 68, 13, 13, 
	101, 13, 13, 13, 68, 13, 13, 102, 
	13, 13, 13, 68, 13, 13, 103, 13, 
	13, 13, 68, 13, 13, 104, 13, 13, 
	13, 68, 0
};

static const char _umodLexer_trans_targs[] = {
	4, 0, 4, 1, 7, 2, 3, 10, 
	4, 5, 4, 6, 7, 8, 9, 10, 
	4, 4, 11, 12, 4, 13, 4, 14, 
	16, 4, 4, 17, 18, 19, 4, 4, 
	4, 20, 23, 33, 34, 37, 42, 45, 
	53, 4, 4, 4, 4, 4, 4, 4, 
	4, 4, 4, 4, 4, 4, 4, 4, 
	4, 4, 15, 4, 4, 4, 4, 4, 
	4, 4, 4, 4, 4, 21, 22, 8, 
	24, 27, 25, 26, 8, 28, 29, 30, 
	31, 32, 8, 8, 35, 36, 8, 38, 
	39, 40, 41, 8, 43, 44, 8, 46, 
	47, 48, 49, 50, 51, 52, 8, 54, 
	8
};

static const char _umodLexer_trans_actions[] = {
	83, 0, 51, 0, 115, 0, 0, 115, 
	55, 0, 53, 0, 118, 112, 0, 118, 
	29, 31, 0, 0, 49, 0, 43, 0, 
	0, 47, 45, 0, 0, 0, 41, 33, 
	35, 0, 0, 0, 0, 0, 0, 0, 
	0, 37, 39, 23, 79, 73, 21, 65, 
	13, 61, 9, 57, 25, 5, 59, 27, 
	7, 63, 0, 11, 81, 77, 71, 17, 
	67, 19, 69, 15, 75, 0, 0, 91, 
	0, 0, 0, 0, 100, 0, 0, 0, 
	0, 0, 106, 85, 0, 0, 94, 0, 
	0, 0, 0, 103, 0, 0, 97, 0, 
	0, 0, 0, 0, 0, 0, 109, 0, 
	88
};

static const char _umodLexer_to_state_actions[] = {
	0, 0, 0, 0, 1, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0
};

static const char _umodLexer_from_state_actions[] = {
	0, 0, 0, 0, 3, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0
};

static const short _umodLexer_eof_trans[] = {
	1, 1, 1, 1, 0, 45, 46, 1, 
	1, 48, 1, 50, 52, 55, 58, 61, 
	62, 63, 65, 67, 69, 69, 69, 69, 
	69, 69, 69, 69, 69, 69, 69, 69, 
	69, 69, 69, 69, 69, 69, 69, 69, 
	69, 69, 69, 69, 69, 69, 69, 69, 
	69, 69, 69, 69, 69, 69, 69
};

static const int umodLexer_start = 4;
static const int umodLexer_first_final = 4;
static const int umodLexer_error = -1;

static const int umodLexer_en_main = 4;


#line 9 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"

using namespace umod::lex;

Lexer::Lexer(const char *source, unsigned int length)
    : m_source(source)
    , m_source_end(source + length)
    , m_source_eof(m_source_end)
    , m_ts(nullptr), m_te(nullptr)
    , m_current_state(0), m_act(0)
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
    
#line 105 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"


    Lexeme::Type type;

    if (m_source == m_source_end)
    {
        m_ts = m_te = m_source;
        type = Lexeme::Type::End;
    }
    else
    {
        
#line 117 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
        
#line 118 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
        
#line 119 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
        
#line 120 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
        
#line 121 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
        
#line 122 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
        
#line 123 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"

        
#line 299 "lexer.cc"
	{
	(  m_current_state) = umodLexer_start;
	(  m_ts) = 0;
	(  m_te) = 0;
	( m_act) = 0;
	}

#line 125 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
        
#line 309 "lexer.cc"
	{
	int _klen;
	unsigned int _trans;
	const char *_acts;
	unsigned int _nacts;
	const char *_keys;

	if ( (   m_source) == (  m_source_end) )
		goto _test_eof;
_resume:
	_acts = _umodLexer_actions + _umodLexer_from_state_actions[(  m_current_state)];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 ) {
		switch ( *_acts++ ) {
	case 1:
#line 1 "NONE"
	{(  m_ts) = (   m_source);}
	break;
#line 328 "lexer.cc"
		}
	}

	_keys = _umodLexer_trans_keys + _umodLexer_key_offsets[(  m_current_state)];
	_trans = _umodLexer_index_offsets[(  m_current_state)];

	_klen = _umodLexer_single_lengths[(  m_current_state)];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + _klen - 1;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + ((_upper-_lower) >> 1);
			if ( (*(   m_source)) < *_mid )
				_upper = _mid - 1;
			else if ( (*(   m_source)) > *_mid )
				_lower = _mid + 1;
			else {
				_trans += (unsigned int)(_mid - _keys);
				goto _match;
			}
		}
		_keys += _klen;
		_trans += _klen;
	}

	_klen = _umodLexer_range_lengths[(  m_current_state)];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + (_klen<<1) - 2;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + (((_upper-_lower) >> 1) & ~1);
			if ( (*(   m_source)) < _mid[0] )
				_upper = _mid - 2;
			else if ( (*(   m_source)) > _mid[1] )
				_lower = _mid + 2;
			else {
				_trans += (unsigned int)((_mid - _keys)>>1);
				goto _match;
			}
		}
		_trans += _klen;
	}

_match:
	_trans = _umodLexer_indicies[_trans];
_eof_trans:
	(  m_current_state) = _umodLexer_trans_targs[_trans];

	if ( _umodLexer_trans_actions[_trans] == 0 )
		goto _again;

	_acts = _umodLexer_actions + _umodLexer_trans_actions[_trans];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 )
	{
		switch ( *_acts++ )
		{
	case 2:
#line 1 "NONE"
	{(  m_te) = (   m_source)+1;}
	break;
	case 3:
#line 46 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
	{( m_act) = 1;}
	break;
	case 4:
#line 47 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
	{( m_act) = 2;}
	break;
	case 5:
#line 48 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
	{( m_act) = 3;}
	break;
	case 6:
#line 49 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
	{( m_act) = 4;}
	break;
	case 7:
#line 50 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
	{( m_act) = 5;}
	break;
	case 8:
#line 51 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
	{( m_act) = 6;}
	break;
	case 9:
#line 52 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
	{( m_act) = 7;}
	break;
	case 10:
#line 53 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
	{( m_act) = 8;}
	break;
	case 11:
#line 54 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
	{( m_act) = 9;}
	break;
	case 12:
#line 95 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
	{( m_act) = 42;}
	break;
	case 13:
#line 97 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
	{( m_act) = 44;}
	break;
	case 14:
#line 103 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
	{( m_act) = 48;}
	break;
	case 15:
#line 63 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
	{(  m_te) = (   m_source)+1;{ type = Lexeme::Type::PlusAssign; {(   m_source)++; goto _out; } }}
	break;
	case 16:
#line 64 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
	{(  m_te) = (   m_source)+1;{ type = Lexeme::Type::MinusAssign; {(   m_source)++; goto _out; } }}
	break;
	case 17:
#line 65 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
	{(  m_te) = (   m_source)+1;{ type = Lexeme::Type::MulAssign; {(   m_source)++; goto _out; } }}
	break;
	case 18:
#line 66 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
	{(  m_te) = (   m_source)+1;{ type = Lexeme::Type::DivAssign; {(   m_source)++; goto _out; } }}
	break;
	case 19:
#line 67 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
	{(  m_te) = (   m_source)+1;{ type = Lexeme::Type::ModAssign; {(   m_source)++; goto _out; } }}
	break;
	case 20:
#line 70 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
	{(  m_te) = (   m_source)+1;{ type = Lexeme::Type::GreaterOrEqual; {(   m_source)++; goto _out; } }}
	break;
	case 21:
#line 72 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
	{(  m_te) = (   m_source)+1;{ type = Lexeme::Type::LesserOrEqual; {(   m_source)++; goto _out; } }}
	break;
	case 22:
#line 73 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
	{(  m_te) = (   m_source)+1;{ type = Lexeme::Type::Equal; {(   m_source)++; goto _out; } }}
	break;
	case 23:
#line 74 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
	{(  m_te) = (   m_source)+1;{ type = Lexeme::Type::NotEqual; {(   m_source)++; goto _out; } }}
	break;
	case 24:
#line 77 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
	{(  m_te) = (   m_source)+1;{ type = Lexeme::Type::Inv; {(   m_source)++; goto _out; } }}
	break;
	case 25:
#line 78 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
	{(  m_te) = (   m_source)+1;{ type = Lexeme::Type::Incrementation; {(   m_source)++; goto _out; } }}
	break;
	case 26:
#line 79 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
	{(  m_te) = (   m_source)+1;{ type = Lexeme::Type::Decrementation; {(   m_source)++; goto _out; } }}
	break;
	case 27:
#line 81 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
	{(  m_te) = (   m_source)+1;{ type = Lexeme::Type::LParen; {(   m_source)++; goto _out; } }}
	break;
	case 28:
#line 82 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
	{(  m_te) = (   m_source)+1;{ type = Lexeme::Type::RParen; {(   m_source)++; goto _out; } }}
	break;
	case 29:
#line 83 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
	{(  m_te) = (   m_source)+1;{ type = Lexeme::Type::LBracket; {(   m_source)++; goto _out; } }}
	break;
	case 30:
#line 84 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
	{(  m_te) = (   m_source)+1;{ type = Lexeme::Type::RBracket; {(   m_source)++; goto _out; } }}
	break;
	case 31:
#line 85 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
	{(  m_te) = (   m_source)+1;{ type = Lexeme::Type::LBrace; {(   m_source)++; goto _out; } }}
	break;
	case 32:
#line 86 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
	{(  m_te) = (   m_source)+1;{ type = Lexeme::Type::RBrace; {(   m_source)++; goto _out; } }}
	break;
	case 33:
#line 88 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
	{(  m_te) = (   m_source)+1;{ type = Lexeme::Type::QuestionMark; {(   m_source)++; goto _out; } }}
	break;
	case 34:
#line 89 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
	{(  m_te) = (   m_source)+1;{ type = Lexeme::Type::Dot; {(   m_source)++; goto _out; } }}
	break;
	case 35:
#line 91 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
	{(  m_te) = (   m_source)+1;{ type = Lexeme::Type::Semicolon; {(   m_source)++; goto _out; } }}
	break;
	case 36:
#line 92 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
	{(  m_te) = (   m_source)+1;{ type = Lexeme::Type::Colon; {(   m_source)++; goto _out; } }}
	break;
	case 37:
#line 93 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
	{(  m_te) = (   m_source)+1;{ type = Lexeme::Type::Comma; {(   m_source)++; goto _out; } }}
	break;
	case 38:
#line 97 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
	{(  m_te) = (   m_source)+1;{ type = Lexeme::Type::String; {(   m_source)++; goto _out; } }}
	break;
	case 39:
#line 100 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
	{(  m_te) = (   m_source)+1;{ type = Lexeme::Type::Newline; {(   m_source)++; goto _out; } }}
	break;
	case 40:
#line 103 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
	{(  m_te) = (   m_source)+1;{ {(   m_source)++; goto _out; } }}
	break;
	case 41:
#line 56 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
	{(  m_te) = (   m_source);(   m_source)--;{ type = Lexeme::Type::Plus; {(   m_source)++; goto _out; } }}
	break;
	case 42:
#line 57 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
	{(  m_te) = (   m_source);(   m_source)--;{ type = Lexeme::Type::Minus; {(   m_source)++; goto _out; } }}
	break;
	case 43:
#line 58 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
	{(  m_te) = (   m_source);(   m_source)--;{ type = Lexeme::Type::Mul; {(   m_source)++; goto _out; } }}
	break;
	case 44:
#line 59 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
	{(  m_te) = (   m_source);(   m_source)--;{ type = Lexeme::Type::Div; {(   m_source)++; goto _out; } }}
	break;
	case 45:
#line 60 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
	{(  m_te) = (   m_source);(   m_source)--;{ type = Lexeme::Type::Mod; {(   m_source)++; goto _out; } }}
	break;
	case 46:
#line 62 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
	{(  m_te) = (   m_source);(   m_source)--;{ type = Lexeme::Type::Assign; {(   m_source)++; goto _out; } }}
	break;
	case 47:
#line 69 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
	{(  m_te) = (   m_source);(   m_source)--;{ type = Lexeme::Type::Greater; {(   m_source)++; goto _out; } }}
	break;
	case 48:
#line 71 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
	{(  m_te) = (   m_source);(   m_source)--;{ type = Lexeme::Type::Lesser; {(   m_source)++; goto _out; } }}
	break;
	case 49:
#line 76 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
	{(  m_te) = (   m_source);(   m_source)--;{ type = Lexeme::Type::Not; {(   m_source)++; goto _out; } }}
	break;
	case 50:
#line 95 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
	{(  m_te) = (   m_source);(   m_source)--;{ type = Lexeme::Type::Identifier; {(   m_source)++; goto _out; } }}
	break;
	case 51:
#line 96 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
	{(  m_te) = (   m_source);(   m_source)--;{ type = Lexeme::Type::Number; {(   m_source)++; goto _out; } }}
	break;
	case 52:
#line 99 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
	{(  m_te) = (   m_source);(   m_source)--;{ type = Lexeme::Type::Spaces; {(   m_source)++; goto _out; } }}
	break;
	case 53:
#line 102 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
	{(  m_te) = (   m_source);(   m_source)--;{ {(   m_source)++; goto _out; } }}
	break;
	case 54:
#line 1 "NONE"
	{	switch( ( m_act) ) {
	case 1:
	{{(   m_source) = (((  m_te)))-1;} type = Lexeme::Type::If; {(   m_source)++; goto _out; } }
	break;
	case 2:
	{{(   m_source) = (((  m_te)))-1;} type = Lexeme::Type::Var; {(   m_source)++; goto _out; } }
	break;
	case 3:
	{{(   m_source) = (((  m_te)))-1;} type = Lexeme::Type::Else; {(   m_source)++; goto _out; } }
	break;
	case 4:
	{{(   m_source) = (((  m_te)))-1;} type = Lexeme::Type::Null; {(   m_source)++; goto _out; } }
	break;
	case 5:
	{{(   m_source) = (((  m_te)))-1;} type = Lexeme::Type::True; {(   m_source)++; goto _out; } }
	break;
	case 6:
	{{(   m_source) = (((  m_te)))-1;} type = Lexeme::Type::False; {(   m_source)++; goto _out; } }
	break;
	case 7:
	{{(   m_source) = (((  m_te)))-1;} type = Lexeme::Type::Return; {(   m_source)++; goto _out; } }
	break;
	case 8:
	{{(   m_source) = (((  m_te)))-1;} type = Lexeme::Type::Function; {(   m_source)++; goto _out; } }
	break;
	case 9:
	{{(   m_source) = (((  m_te)))-1;} type = Lexeme::Type::Undefined; {(   m_source)++; goto _out; } }
	break;
	case 42:
	{{(   m_source) = (((  m_te)))-1;} type = Lexeme::Type::Identifier; {(   m_source)++; goto _out; } }
	break;
	case 44:
	{{(   m_source) = (((  m_te)))-1;} type = Lexeme::Type::String; {(   m_source)++; goto _out; } }
	break;
	case 48:
	{{(   m_source) = (((  m_te)))-1;} {(   m_source)++; goto _out; } }
	break;
	}
	}
	break;
#line 644 "lexer.cc"
		}
	}

_again:
	_acts = _umodLexer_actions + _umodLexer_to_state_actions[(  m_current_state)];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 ) {
		switch ( *_acts++ ) {
	case 0:
#line 1 "NONE"
	{(  m_ts) = 0;}
	break;
#line 657 "lexer.cc"
		}
	}

	if ( ++(   m_source) != (  m_source_end) )
		goto _resume;
	_test_eof: {}
	if ( (   m_source) == ( m_source_eof) )
	{
	if ( _umodLexer_eof_trans[(  m_current_state)] > 0 ) {
		_trans = _umodLexer_eof_trans[(  m_current_state)] - 1;
		goto _eof_trans;
	}
	}

	_out: {}
	}

#line 126 "/Users/javedulu/Documents/uMod/src/lex/lexer.rl"
    }

    unsigned int size = m_te - m_ts;
    Lexeme::pos_t position = m_position;

    if (type == Lexeme::Type::Newline)
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
