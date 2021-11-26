#include <string>

#ifndef OPERATORS_H
#define OPERATORS_H

std::string OPERATORS[] = {
    "+",
    "-",
    "^",
    "pow",
    "*",
    "/",
    "%",
    "mod"
};

int OPERATORS_AMOUNT = sizeof(OPERATORS)/sizeof(std::string);

#endif