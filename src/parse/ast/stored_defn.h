#ifndef UMOD_AST_STOREDDEFN_H_
#define UMOD_AST_STOREDDEFN_H_
#include <string>
#include <vector>
#include <memory>
#include "node.h"
#include "tools/visitor.h"

namespace umod {
    namespace ast{
        class storedefn: public ast::node
        {
            public:
                inline storedefn(const std::string &name, std::vector<std::string>* within): m_name(name), m_within(within){}
                inline const std::string &name(void) const
                {
                    return m_name;
                }
                inline storedefn &name(const std::string &name)
                {
                    m_name = name;
                    return *this;
                }
                inline std::vector<std::string> *within(void) const{
                    return m_within.get();
                }
                inline storedefn &within(std::vector<std::string>*within)
                {
                    m_within.reset(within); return *this;
                }
                inline std::vector<std::string>* takeArgs(void)
                {
                    return m_within.release();
                }
                void accept(ast::tools::Visitor &visitor)
                {
                    visitor.visit(*this);
                }
            private:
                std::string m_name;
                std::unique_ptr<std::vector<std::string>>m_within;
        };
    }
}
#endif// UMOD_AST_STOREDDEFN_H_
