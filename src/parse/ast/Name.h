//
//  Name.h
//  mojito
//
//  Created by Javed Shaik on 21/10/15.
//
//

#ifndef UMOD_AST_NAME_H_
#define UMOD_AST_NAME_H_

namespace umod{ {
    namespace ast {
        class Name : public ast::node
        {
        public:
            inline Name(void){}
            inline ~Name(void)
            {
                for (std::string *str : m_strs)
                {
                    delete str;
                }
            }
            inline std::vector<std::string *> &strs(void)
            {
                return m_strs;
            }
            void accept(ast::tools::Visitor &visitor)
            {
                visitor.visit(*this);
            }
        private:
            std::vector<std::string *>m_strs;
        }
    }
}

#endif /*  UMOD_AST_NAME_H_ */
