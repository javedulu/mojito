#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "lexer.h"
#include "parser.h"

using namespace umod::lex;

int main(int argc, char **argv)
{
    
    //std::string filename = (argc > 1 ? argv[1]:"/Users/phryne/Desktop/modelica-3.2.1.mo");
    std::string filename = (argc > 1 ? argv[1]:"/Users/phryne/Desktop/aide/stage/a.mo");
    
    std::ifstream ifs(filename, std::ifstream::in);
    std::string istr((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>()); //
    
    Lexer lexr(istr);
    umod::parser::Parser parser(lexr);
    parser.exec();
    parser.program();
    
    return 0;
}

