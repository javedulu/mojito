#ifndef UMOD_LEX_LEXEME_H_
#define UMOD_LEX_LEXEME_H_

#include <string>
#include <sstream>
#include <iostream>
#include <utility>
#include "lemon-parser.h"

namespace umod
{
    namespace lex
    {
        class Lexeme
        {
        public:
            typedef std::pair<int, int> pos_t;

            enum class AutoType: int;
            enum class Type: int;

            inline Lexeme(Type type, std::string const &text, pos_t const &position): m_type(type), m_text(text), m_position(position)
            {
                if ((int)m_type > 0)
                {
                    std::cout<<".."<<m_text<<" "<<(int)m_type<<std::endl;
                }
            }
            inline ~Lexeme() {}

            inline const Type type(void) const
            {
                return m_type;
            }

            inline pos_t const &position(void) const
            {
                return m_position;
            }

            inline operator std::string() const
            {
                return m_text;
            }

            inline operator const char *() const
            {
                return m_text.c_str();
            }

            inline operator int() const
            {
                return std::stoi(m_text);
            }

            inline operator long() const
            {
                return std::stol(m_text);
            }

            inline operator double() const
            {
                return std::stod(m_text);
            }

            inline operator float() const
            {
                return std::stof(m_text);
            }

            template<typename T>
            inline T as(void) const
            {
                T value;

                std::istringstream sstream(m_text);
                sstream >> value;

                return value;
            }

            static const char *typeString(Type type);

        private:
            Type m_type;
            std::string m_text;
            pos_t m_position;
        };

        enum class Lexeme::AutoType: int
        {
            #define UMOD_DEFINE_LEXEME(name, value)
            #define UMOD_AUTO_LEXEME(name) name,
            #define UMOD_LEXEME(name)

            #include "types.h"

            #undef UMOD_DEFINE_LEXEME
            #undef UMOD_AUTO_LEXEME
            #undef UMOD_LEXEME
        };

        enum class Lexeme::Type: int
        {
            #define UMOD_DEFINE_LEXEME(name, value) name = value,
            #define UMOD_AUTO_LEXEME(name)
            #define UMOD_LEXEME(name) UMOD_DEFINE_LEXEME(name, UMOD_LEXEME_TYPE_##name)

            #include "types.h"

            #undef UMOD_DEFINE_LEXEME
            #undef UMOD_AUTO_LEXEME
            #undef UMOD_LEXEME

            #define UMOD_DEFINE_LEXEME(name, value)
            #define UMOD_AUTO_LEXEME(name) name = -(static_cast<int>(Lexeme::AutoType::name) + 1),
            #define UMOD_LEXEME(name)

            #include "types.h"

            #undef UMOD_DEFINE_LEXEME
            #undef UMOD_AUTO_LEXEME
            #undef UMOD_LEXEME
        };

        template<>
        inline std::string Lexeme::as<std::string>(void) const
        {
            return m_text;
        }
    }
}

#endif /* UMOD_LEX_LEXEME_H_ */
