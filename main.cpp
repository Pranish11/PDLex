#include "lexer.h"
#include "interpreter.h"
#include "parser.h"

#include <iostream>
#include <fstream>
#include <vector>

// to check if the file name has .pd
bool pdExtension(const std::string& filename)
{
    if(filename.size() < 3) 
    {
        return false;
    }
    return filename.substr(filename.size() -3 ) == ".pd";
}


int main(int argc, char **argv)
{
    lexer Lexer;
    parser parse;
    interpreter Interpert;

    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <filename>.pd\n";
        return 1;
    }

    std::ifstream file(argv[1]);

    std::string filename = argv[1];

    if(!pdExtension(filename))
    {
        std::cerr << "Error! .pd files are only supported" << "\n";
        return 1;
    }

    if (!file.is_open())
    {
        std::cerr << "Could not open file: " << argv[1] << "\n";
        return 1;
    }

    Token tok;
    std::vector<Token> tokens;
    do
    {
        tok = Lexer.getnextToken(file);
        tokens.push_back(tok);
        // Lexer.print(tok);

    } while (tok.type != TOKENTYPE::END);

    int i = 0;

    // for multile exection
    while (i < static_cast<int>(tokens.size()) && tokens[i].type != TOKENTYPE::END)
    {
        if (tokens[i].type == TOKENTYPE::PRINT)
        {
            NODE tree = parse.parseprint(tokens, i);
            Interpert.interpret(tree);
            continue;
        }

        if (tokens[i].type == TOKENTYPE::IDENT)
        {
            NODE tree = parse.parsecall(tokens, i);
            Interpert.interpret(tree);
            continue;
        }

        i++;
    }
    return 0;
}
