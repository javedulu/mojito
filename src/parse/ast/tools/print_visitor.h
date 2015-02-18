#ifndef UMOD_AST_TOOLS_PRINT_VISITOR_H_
#define UMOD_AST_TOOLS_PRINT_VISITOR_H_

#include <iostream>
#include <sstream>
#include <string>
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
                    inline ~Visitor() {}
            };
        }
    }
}
#endif /* UMOD_AST_TOOLS_VISITOR_H_ */
