/*
MIT License

https://github.com/therealdreg/dregs-flex-bison-example

Copyright (c) [2023] by David Reguera Garcia aka Dreg 
dreg@fr33project.org
https://www.fr33project.org 
https://github.com/therealdreg
TW @therealdreg

Credits:
- Original repo by Gergely Dévai ( @devaigergely81 ): 
https://github.com/devaigergely81/flex-bison-example
- Fork by Kókai Péter ( @Kokan ): 
https://github.com/Kokan/flex-bison-example


Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <list>
#include "FlexLexer.h"
#include "implementation.hh"
#include "while.tab.hh"

yyFlexLexer *lexer;

int yylex(yy::parser::semantic_type* yylval, yy::parser::location_type* yylloc) {
    yylloc->begin.line = lexer->lineno();
    int token = lexer->yylex();
    if(token == yy::parser::token::ID || token == yy::parser::token::NUM) {
        yylval->build(std::string(lexer->YYText()));
    }
    return token;
}

void yy::parser::error(const location_type& loc, const std::string& msg) {
    std::cerr << "Line " << loc.begin.line << ": " << msg << std::endl;
    exit(1);
}

int main(int argc, char *argv[]) {
    if(argc < 2) {
        std::cerr << "Usage (without inputfile = stdin): " << argv[0] << " (-c|-i) [inputfile]" << std::endl;
        exit(1);
    }

    if(std::string(argv[1]) == "-c") {
        current_mode = compiler;
    } else if(std::string(argv[1]) == "-i") {
        current_mode = interpreter;
    } else {
        std::cerr << "Usage (without inputfile = stdin): " << argv[0] << "(-c|-i) [inputfile]" << std::endl;
        exit(1);
    }

    std::ifstream inFile;

    if (argc > 2)
    {
        inFile = std::ifstream(argv[2]);
        if(!inFile)
        {
            std::cerr << "Cannot open input file: " << argv[2] << std::endl;
            exit(1);
        }
    }

    lexer = new yyFlexLexer(inFile.is_open() ? &inFile : &std::cin);
    yy::parser parser;
    parser.parse();
    delete lexer;
    return 0;
}