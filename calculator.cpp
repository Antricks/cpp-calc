#include <iostream>
#include <string>
#include <algorithm>

#include "term.h"

int main(int argc, char const *argv[])
{
    std::string in;

    while (true)
    {
        std::cout << ">>> ";
        std::getline(std::cin, in);

        in.erase(remove(in.begin(), in.end(), ' '), in.end()); // remove spaces from input

        Term term = Term(in);

        if(in.compare("exit") == 0) {
            break;
        } else {
            double result = term.eval();
            std::cout << result << std::endl;
        }
    }
    
    std::cout << "Bye bye!" << std::endl;

    return 0;
}
