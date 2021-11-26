#include <string>

#ifndef EQUATION_H
#define EQUATION_H

class Term
{
private:
    Term* a;
    Term* b;
    std::string term;
    std::string oper;

public:
    Term(std::string term);
    ~Term();
    double eval();
};

#endif