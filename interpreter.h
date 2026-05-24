#pragma once

#include <iostream>
<<<<<<< Updated upstream
=======
#include <string>
#include <map>
#include <variant>
>>>>>>> Stashed changes

#include "parser.h"

class interpreter
{
public:
    void interpret(const NODE &node);
<<<<<<< Updated upstream
};
=======

private:
    std::map<std::string, std::variant<std::string, int, double>> variables;
};
>>>>>>> Stashed changes
