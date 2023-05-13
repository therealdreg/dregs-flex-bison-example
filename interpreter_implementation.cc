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

#include "implementation.hh"
#include <iostream>
#include <sstream>
#include <algorithm>

std::unordered_map<std::string, unsigned> value_table;

unsigned number_expression::get_value() const {
    return value;
}

bool number_expression::is_const_expr() const {
    return true;
}

unsigned boolean_expression::get_value() const {
    return (unsigned)value;
}

bool boolean_expression::is_const_expr() const {
    return true;
}

unsigned id_expression::get_value() const {
    if(value_table.count(name) == 0) {
        error(line, std::string("Variable has not been initialized: ") + name);
    }
    return value_table[name];
}

bool id_expression::is_const_expr() const {
    return false;
}

unsigned binop_expression::get_value() const {
    int left_value = left->get_value();
    int right_value = right->get_value();
    if(op == "+") {
        return left_value + right_value;
    } else if(op == "-") {
        return left_value - right_value;
    } else if(op == "*") {
        return left_value * right_value;
    } else if(op == "/") {
        return left_value / right_value;
    } else if(op == "%") {
        return left_value % right_value;
    } else if(op == "<") {
        return left_value < right_value;
    } else if(op == ">") {
        return left_value > right_value;
    } else if(op == "<=") {
        return left_value <= right_value;
    } else if(op == ">=") {
        return left_value >= right_value;
    } else if(op == "and") {
        return left_value && right_value;
    } else if(op == "or") {
        return left_value || right_value;
    } else if(op == "=") {
        return left_value == right_value;
    }

    error(line, std::string("Unknown operator: ") + op);
    return 42;
}    

bool binop_expression::is_const_expr() const {
    return left->is_const_expr() && right->is_const_expr();
}

unsigned trinaryop_expression::get_value() const {
    if (cond->get_value()) {
       return left->get_value();
    } else {
       return right->get_value();
    }
}    

bool trinaryop_expression::is_const_expr() const {
    return cond->is_const_expr()
        && left->is_const_expr()
        && right->is_const_expr();
}


unsigned not_expression::get_value() const {
    return !(bool)(operand->get_value());
}

bool not_expression::is_const_expr() const {
    return operand->is_const_expr();
}

void assign_instructions::execute() {
    std::list<unsigned> results;
    std::for_each(right->begin(), right->end(), [&results](auto item) {
       results.push_back( item->get_value() );
    });

    auto result_it = results.begin();
    std::for_each(left->begin(), left->end(), [&result_it](auto item) {
       value_table[item] = *result_it;
       ++result_it;
    });
}

void read_instruction::execute() {
    std::string input_line;
    getline(std::cin, input_line);
    if(symbol_table[id].symbol_type == natural) {
        std::stringstream ss(input_line);
        unsigned input;
        ss >> input;
        value_table[id] = input;
    } else if(symbol_table[id].symbol_type == boolean) {
        if(input_line == "true") {
            value_table[id] = 1;
        } else {
            value_table[id] = 0;
        }
    }
}

void write_instruction::execute() {
    if(exp_type == natural) {
        std::cout << exp->get_value() << std::endl;
    } else if(exp_type == boolean) {
        if(exp->get_value()) {
            std::cout << "true" << std::endl;
        } else {
            std::cout << "false" << std::endl;
        }
    }
}

void if_instruction::execute() {
    if(condition->get_value()) {
        execute_commands(true_branch);
    } else {
        execute_commands(false_branch);
    }
}

void while_instruction::execute() {
    while(condition->get_value()) {
        execute_commands(body);
    }
}

void for_instruction::execute() {
    const unsigned from = lowerlimit->get_value();

    if (upperlimit->is_const_expr()) {
        const unsigned to = upperlimit->get_value();
        for (unsigned i = from; i < to; ++i) {
            value_table[id] = i;
            execute_commands(body);
        }
    } else {
        for (unsigned i = from; i < upperlimit->get_value(); ++i) {
            value_table[id] = i;
            execute_commands(body);
        }
    }

}

void execute_commands(std::list<instruction*>* commands) {
    if (!commands)
       return;

    std::for_each(commands->begin(), commands->end(), [](auto command) { command->execute(); });
}
