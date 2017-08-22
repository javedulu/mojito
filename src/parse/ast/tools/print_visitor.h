#ifndef UMOD_AST_TOOLS_PRINT_VISITOR_H_
#define UMOD_AST_TOOLS_PRINT_VISITOR_H_

#include <iostream>
#include <sstream>
#include <string>

#include "StoredDefinition.h"
namespace umod
{
    namespace ast
    {
        namespace tools 
        {
            class PrintVisitor: public ast::tools::Visitor
            {
                public:
                    PrintVisitor() : depth(0) { }
                    inline void visit(ast::StoredDefinition &StoredDefinition)
                    {
                        std::cout<< spaces()<<"Program : "<< std::endl;
                        for (ast::ClassDefn *classdefn: StoredDefinition.classDefns())
                        {
                            depth++;
                            classDefn->accept(*this);
                            depth--;
                        }
                    }
                    inline ~Visitor() {}
                private:
                    inline std::string spaces()
                    {
                        std::stringstream stream;
                        for (int i=0; i<depth; i++) {
                            stream << " ";
                        }
                        return stream.str();
                    }
                    int depth;
            };
        }
    }
}
#endif /* UMOD_AST_TOOLS_PRINT_VISITOR_H_ */
