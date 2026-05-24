#pragma once

#include <iostream>
#include <string>
#include <map>
#include <variant>

#include "parser.h"

class interpreter
{
public:
    void interpret(const NODE &node);

private:
    std::map<std::string, std::variant<std::string, int, double>> variables;
};
