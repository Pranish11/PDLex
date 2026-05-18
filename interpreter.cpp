#include "interpreter.h"


void interpreter::interpret(const NODE& node)
{
    if(node.nodetype == NODETYPE::CALL_EXPR &&  node.value == "print")
    {
        for (const auto& arg : node.child)
        {
            std::cout << arg.value << " " ;
        }
        std::cout << "\n";
    }

    if(node.nodetype == NODETYPE::CALL_EXPR && node.value == "printword")
    {
        for (const auto& arg : node.child)
        {
            std::cout << arg.value << "\n";
        }
    }
}
