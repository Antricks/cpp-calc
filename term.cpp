#include <iostream>
#include <string>
#include <math.h>

#include "term.h"
#include "operators.h"

double Term::eval()
{
    if(oper.empty())
    {
        if(term.compare("e") == 0)
        {
            return 2.718281828459045;
        }
        else if(term.compare("pi") == 0)
        {
            return 3.141592653589793;
        }
        
        return atof(this->term.c_str());
    }

    if(oper.compare("+") == 0)
    {
        return this->a->eval() + this->b->eval();
    }
    else if(oper.compare("-") == 0)
    {
        return this->a->eval() - this->b->eval();
    }
    else if(oper.compare("*") == 0)
    {
        return this->a->eval() * this->b->eval();
    }
    else if(oper.compare("/") == 0)
    {
        return this->a->eval() / this->b->eval();
    }
    else if(oper.compare("^") == 0 || oper.compare("pow") == 0)
    {
        return pow(this->a->eval(), this->b->eval());
    }
    else if(oper.compare("%") == 0 || oper.compare("mod") == 0)
    {
        return fmod(this->a->eval(), this->b->eval());
    }

    return -1337420;
}

Term::Term(std::string term)
{
    this->term = term;

    for (int i = 0; i < OPERATORS_AMOUNT; i++)
    {
        int split = term.find(OPERATORS[i]);

        if(split != -1)
        {
            this->oper = OPERATORS[i];

            std::string aInput = term.substr(0, split);
            std::string bInput = term.substr(split+oper.length(), term.length()-1);

            this->a = new Term(aInput);
            this->b = new Term(bInput);

            return;
        }
    }
}