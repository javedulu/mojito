#ifndef UMOD_AST_NODE_H_
#define UMOD_AST_NODE_H_
namespace umod
{
    namespace ast
    {
        namespace tools
        {
            class Visitor;
        }

        class Node 
        {
            public:
                virtual ~Node() {}
                virtual void accept(ast::tools::Visitor &visitor) = 0;
        };
    }
}
#endif /* UMOD_AST_NODE_H_ */
