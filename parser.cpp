#include "parser.h"


NODE parser::parsecall(std::vector<Token>& token, int& i)
{
    NODE call;
    call.nodetype = NODETYPE::CALL_EXPR;
    if(i >= static_cast<int>(token.size()))
    {
        return call;
    }

    // Must start with an identifier (function name).
    if (token[i].type != TOKENTYPE::IDENT)
    {
        return call;
    }

    // calling name
    call.value = token[i++].value;

    // skiping LPAREN if it was present
    if(i < static_cast<int>(token.size()) && token[i].type == TOKENTYPE::LPAREN)
    {
        i++;
    }

    // parse the  arguments

    while (i < static_cast<int>(token.size()) && token[i].type != TOKENTYPE::RPAREN)
    {
        if(token[i].type == TOKENTYPE::NUMBER)
        {
            NODE arg;
            arg.nodetype = NODETYPE::NUMBER_LITERAL;
            arg.value   = token[i].value;
            call.child.push_back(arg);
            i++;
            continue;
        }

        if(token[i].type == TOKENTYPE::IDENT)
        {
            NODE arg;
            arg.nodetype = NODETYPE::IDENT;
            arg.value   = token[i].value;
            call.child.push_back(arg);
            i++;
            continue;
        }
        i++;
    }

    if(i < static_cast<int>(token.size()) && token[i].type == TOKENTYPE::RPAREN)
    {
        i++;  // skip RPAREN i.e :  ')'
    }

    if(i < static_cast<int>(token.size()) && token[i].type == TOKENTYPE::SEMI)
    {
        i++;  // skip the  SEMI colen
    }

    return call;
}
