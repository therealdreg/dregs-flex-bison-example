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

std::string number_expression::get_code() const {
    std::stringstream ss;
    ss << "mov eax," << value << std::endl;
    return ss.str();
}

std::string boolean_expression::get_code() const {
    std::stringstream ss;
    ss << "mov al," << (value ? 1 : 0) << std::endl;
    return ss.str();
}

std::string next_label() {
    std::stringstream ss;
    ss << "label" << id++;
    return ss.str();
}

std::string symbol::get_code() {
    std::stringstream ss;
    ss << label << ": resb " << get_size() << "\t; variable: " << name << std::endl;
    return ss.str();
}

int symbol::get_size() {
    if(symbol_type == boolean) {
        return 1;
    } else {
        return 4;
    }
}

std::string get_register(type t) {
    if(t == boolean) {
        return "al";
    } else {
    return "eax";
    }
}

std::string id_expression::get_code() const {
    if(symbol_table.count(name) == 0) {
        error(line, std::string("Undefined variable: ") + name);
    }
    return std::string("mov eax,[") + symbol_table[name].label + "]\n";
}

std::string operator_code(std::string op) {
    std::stringstream ss;
    if(op == "+") {
        ss << "add eax,ecx" << std::endl;
    } else if(op == "-") {
        ss << "sub eax,ecx" << std::endl;
    } else if(op == "*") {
        ss << "xor edx,edx" << std::endl;
        ss << "mul ecx" << std::endl;
    } else if(op == "/") {
        ss << "xor edx,edx" << std::endl;
        ss << "div ecx" << std::endl;   
    } else if(op == "%") {
        ss << "xor edx,edx" << std::endl;
        ss << "div ecx" << std::endl;
        ss << "mov eax,edx" << std::endl;
    } else if(op == "<") {
        ss << "cmp eax,ecx" << std::endl;
        ss << "mov al,0" << std::endl;
        ss << "mov cx,1" << std::endl;
        ss << "cmovb ax,cx" << std::endl;
    } else if(op == "<=") {
        ss << "cmp eax,ecx" << std::endl;
        ss << "mov al,0" << std::endl;
        ss << "mov cx,1" << std::endl;
        ss << "cmovbe ax,cx" << std::endl;
    } else if(op == ">") {
        ss << "cmp eax,ecx" << std::endl;
        ss << "mov al,0" << std::endl;
        ss << "mov cx,1" << std::endl;
        ss << "cmova ax,cx" << std::endl;
    } else if(op == ">=") {
        ss << "cmp eax,ecx" << std::endl;
        ss << "mov al,0" << std::endl;
        ss << "mov cx,1" << std::endl;
        ss << "cmovae ax,cx" << std::endl;
    } else if(op == "and") {
        ss << "cmp al,1" << std::endl;
        ss << "cmove ax,cx" << std::endl;
    } else if(op == "or") {
        ss << "cmp al,0" << std::endl;
        ss << "cmove ax,cx" << std::endl;
    } else {
        error(-1, std::string("Bug: Unsupported binary operator: ") + op);
    }
    return ss.str();
}

std::string eq_code(type t) {
    std::stringstream ss;
    if(t == natural) {
        ss << "cmp eax,ecx" << std::endl;
    } else {
        ss << "cmp al,cl" << std::endl;
    }
    ss << "mov al,0" << std::endl;
    ss << "mov cx,1" << std::endl;
    ss << "cmove ax,cx" << std::endl;
    return ss.str();
}

std::string binop_expression::get_code() const {
    std::stringstream ss;
    if (left->is_const_expr()) {
    ss << "mov eax, " << left->get_value() << std::endl;
    } else {
    ss << left->get_code();
    }
    ss << "push eax" << std::endl;
    if (right->is_const_expr()) {
    ss << "mov ecx, " << right->get_value() << std::endl;
    } else {
    ss << right->get_code();
    ss << "mov ecx,eax" << std::endl;
    }
    ss << "pop eax" << std::endl;
    ss << (op == "=" ? eq_code(left->get_type()) : operator_code(op));
    return ss.str();
}

std::string trinaryop_expression::get_code() const {
    std::string else_label = next_label();
    std::string end_label = next_label();
    std::stringstream ss;
    if (cond->is_const_expr()) {
    ss << "mov al, " << cond->get_value() << std::endl;
    } else {
    ss << cond->get_code();
    }
    ss << "cmp al,1" << std::endl;
    ss << "jne near " << else_label << std::endl;
    if (left->is_const_expr()) {
    ss << "mov eax, " << left->get_value() << std::endl;
    } else {
    ss << left->get_code();
    }
    ss << "jmp " << end_label << std::endl;
    ss << else_label << ":" << std::endl;
    if (right->is_const_expr()) {
    ss << "mov eax, " << right->get_value() << std::endl;
    } else {
    ss << right->get_code();
    }
    ss << end_label << ":" << std::endl;
    return ss.str();
}

std::string not_expression::get_code() const {
    std::stringstream ss;
    if (operand->is_const_expr()) {
    ss << "mov al, " << operand->get_value() << std::endl;
    } else {
    ss << operand->get_code();
    }
    ss << "xor al,1" << std::endl;
    return ss.str();
}

std::string assign_instructions::get_code() {
    std::stringstream ss;
    auto right_it = right->begin();
    for (auto left_it = left->begin(); left_it != left->end(); ++left_it, ++right_it) {
        if ((*right_it)->is_const_expr()) {
            //do not consume stack space
        } else {
            ss << (*right_it)->get_code();
            ss << "push eax" << std::endl;
        }
    }

    auto rright_it = right->rbegin();
    for (auto left_it = left->rbegin(); left_it != left->rend(); ++left_it, ++rright_it) {
        if ((*rright_it)->is_const_expr()) {
            ss << "mov " << get_register(symbol_table[*left_it].symbol_type) << ", " << (*rright_it)->get_value() << std::endl;
        } else {
            ss << "pop eax" << std::endl;
        }
        ss << "mov [" + symbol_table[*left_it].label + "]," << get_register(symbol_table[*left_it].symbol_type) << std::endl;
    }
    return ss.str();
}

std::string get_type_name(type t) {
    if(t == boolean) {
        return "boolean";
    } else {
        return "natural";
    }
}

std::string read_instruction::get_code() {
    type t = symbol_table[id].symbol_type;
    std::stringstream ss;
    ss << "call read_" << get_type_name(t) << std::endl;
    ss << "mov [" << symbol_table[id].label << "]," << get_register(t) << std::endl;
    return ss.str();
}

std::string write_instruction::get_code() {
    std::stringstream ss;
    ss << exp->get_code();
    if(exp_type == boolean) {
        ss << "and eax,1" << std::endl;
    }
    ss << "push eax" << std::endl;
    ss << "call write_" << get_type_name(exp_type) << std::endl;
    ss << "add esp,4" << std::endl;
    return ss.str();
}

std::string if_instruction::get_code() {
    std::string else_label = next_label();
    std::string end_label = next_label();
    std::stringstream ss;
    ss << condition->get_code();
    ss << "cmp al,1" << std::endl;
    ss << "jne near " << else_label << std::endl;
    generate_code_of_commands(ss, true_branch);
    ss << "jmp " << end_label << std::endl;
    ss << else_label << ":" << std::endl;
    generate_code_of_commands(ss, false_branch);
    ss << end_label << ":" << std::endl;
    return ss.str();
}

std::string while_instruction::get_code() {
    std::string begin_label = next_label();
    std::string end_label = next_label();
    std::stringstream ss;
    ss << begin_label << ":" << std::endl;
    ss << condition->get_code();
    ss << "cmp al,1" << std::endl;
    ss << "jne near " << end_label << std::endl;
    generate_code_of_commands(ss, body);
    ss << "jmp " << begin_label << std::endl;
    ss << end_label << ":" << std::endl;
    return ss.str();
}

std::string for_instruction::get_code() {
    std::string begin_label = next_label();
    std::string end_label = next_label();
    std::stringstream ss;

    //loop unroll
    if (lowerlimit->is_const_expr() && upperlimit->is_const_expr()) {
       for (unsigned i = lowerlimit->get_value(); i < upperlimit->get_value(); ++i) {
           ss << "mov eax, " << i << std::endl;
           ss << "mov [" + symbol_table[id].label + "], eax" << std::endl;

           generate_code_of_commands(ss, body);
           ss << std::endl;
       }

       return ss.str();
    }

    if (lowerlimit->is_const_expr()) {
    ss << "mov eax, " << lowerlimit->get_value() << std::endl;
    } else {
    ss << lowerlimit->get_code();
    }
    ss << "mov [" + symbol_table[id].label + "]," << get_register(symbol_table[id].symbol_type) << std::endl;

    ss << begin_label << ":" << std::endl;
    ss << "mov " << get_register(symbol_table[id].symbol_type) << ", [" + symbol_table[id].label + "]"  << std::endl;
    ss << "push eax" << std::endl;
    if (upperlimit->is_const_expr()) {
    ss << "mov ecx, " << upperlimit->get_value() << std::endl;
    } else {
    ss << upperlimit->get_code();
    }
    ss << "mov ecx,eax" << std::endl;
    ss << "pop eax" << std::endl;

    // i < upperlimit
    ss << "cmp eax,ecx" << std::endl;
    ss << "mov al,0" << std::endl;
    ss << "mov cx,1" << std::endl;
    ss << "cmovb ax,cx" << std::endl;

    ss << "cmp al,1" << std::endl;
    ss << "jne near " << end_label << std::endl;

    generate_code_of_commands(ss, body);

    ss << "mov " << get_register(symbol_table[id].symbol_type) << ", [" + symbol_table[id].label + "]"  << std::endl;
    ss << "inc " << get_register(symbol_table[id].symbol_type) << std::endl;
    ss << "mov [" + symbol_table[id].label + "]," << get_register(symbol_table[id].symbol_type) << std::endl;

    ss << "jmp " << begin_label << std::endl;

    ss << end_label << ":" << std::endl;

    return ss.str();
}

void generate_code_of_commands(std::ostream& out, std::list<instruction*>* commands) {
    if(!commands) {
        return;
    }

    std::list<instruction*>::iterator it;
    for(it = commands->begin(); it != commands->end(); ++it) {
        out << (*it)->get_code();
    }
}

void generate_code(std::list<instruction*>* commands) {
    std::cout << "global main" << std::endl;
    std::cout << "extern write_natural" << std::endl;
    std::cout << "extern read_natural" << std::endl;
    std::cout << "extern write_boolean" << std::endl;
    std::cout << "extern read_boolean" << std::endl;
    std::cout << std::endl;
    std::cout << "section .bss" << std::endl;
    std::unordered_map<std::string,symbol>::iterator it;
    for(it = symbol_table.begin(); it != symbol_table.end(); ++it) {
        std::cout << it->second.get_code();
    }
    std::cout << std::endl;
    std::cout << "section .text" << std::endl;
    std::cout << "main:" << std::endl;
    generate_code_of_commands(std::cout, commands);
    std::cout << "xor eax,eax" << std::endl;
    std::cout << "ret" << std::endl;
}
