#ifndef UMOD_AST_TOOLS_VISITOR_H_
#define UMOD_AST_TOOLS_VISITOR_H_

#include <stdexcept>

namespace umod
{
    namespace ast
    {
        class Node;
    }

    namespace tools 
    {
        class Visitor
        {
            public:
                inline ~Visitor() {}
                virtual inline void visit(ast::Node &node)
                {
                    throw std::runtime_error("Unknown AST branch (ast::Node).");
                }
        };
    }
}

#endif /* UMOD_AST_TOOLS_VISITOR_H_ */
