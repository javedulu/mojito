#ifndef UMOD_AST_TOOLS_VISITOR_H_
#define UMOD_AST_TOOLS_VISITOR_H_

#include <stdexcept>
namespace umod
{
    namespace ast
    {
        class node;
        class storedefn;
        namespace tools
        {
            class Visitor
            {
                public:
                    inline ~Visitor() {}
                    virtual inline void visit(ast::node &node)
                    {
                        throw std::runtime_error("Unknown AST branch (ast::node).");
                    }
                    virtual inline void visit(ast::storedefn &storedefn)
                    {
                        throw std::runtime_error("Unknown AST branch (ast::storedefn).");
                    }
            };
        }
    }
}
#endif /* UMOD_AST_TOOLS_VISITOR_H_ */
