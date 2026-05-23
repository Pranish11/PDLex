#include "interpreter.h"

void interpreter::interpret(const NODE &node)
{
    if (node.nodetype == NODETYPE::VARIABLE_DECLARATION)
    {
        int value = 0;
        if (!node.child.empty())
        {
            const NODE &rhs = node.child[0];
            if (rhs.nodetype == NODETYPE::NUMBER_LITERAL)
            {
                value = std::stoi(rhs.value);
            }
            else if (rhs.nodetype == NODETYPE::IDENT)
            {
                if (variables.find(rhs.value) == variables.end())
                {
                    std::cerr << "Runtime Error: undefined variable " << rhs.value << "\n";
                    return;
                }
                value = variables[rhs.value];
            }
            else if (rhs.nodetype == NODETYPE::STRING_LITERAL)
            {
                std::cerr << "Runtime Error: cannot assign string to int " << node.value << "\n";
                return;
            }
        }

        variables[node.value] = value;
        return;
    }

    if (node.nodetype == NODETYPE::PRINT_STATEMENT)
    {
        for (size_t i = 0; i < node.child.size(); i++)
        {
            const NODE &arg = node.child[i];
            if (arg.nodetype == NODETYPE::IDENT)
            {
                if (variables.find(arg.value) == variables.end())
                {
                    std::cerr << "Runtime Error: undefined variable " << arg.value << "\n";
                    return;
                }
                std::cout << variables[arg.value];
            }
            else if (arg.nodetype == NODETYPE::STRING_LITERAL)
            {
                std::cout << arg.value;
            }
            else if (arg.nodetype == NODETYPE::NUMBER_LITERAL)
            {
                std::cout << arg.value;
            }
            else
            {
                std::cout << arg.value;
            }
            if (i + 1 < node.child.size())
            {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }
}
