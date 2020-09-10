#include "implementation.hh"
#include <iostream>
#include <sstream>
#include <algorithm>

std::unordered_map<std::string, symbol> symbol_table;

type number_expression::get_type() const {
    return natural;
}

type boolean_expression::get_type() const {
    return boolean;
}

void symbol::declare() {
    if(symbol_table.count(name) > 0) {
        error(line, std::string("Re-declared variable: ") + name);
    }
    symbol_table[name] = *this;
}

type id_expression::get_type() const {
    if(symbol_table.count(name) == 0) {
        error(line, std::string("Undefined variable: ") + name);
    }
    return symbol_table[name].symbol_type;
}

type operand_type(std::string op) {
    if(op == "+" || op == "-" || op == "*" || op == "/" || op == "%" ||
       op == "<" || op == ">" || op == "<=" || op == ">=") {
           return natural;
    } else {
        return boolean;
    }
}

type return_type(std::string op) {
    if(op == "+" || op == "-" || op == "*" || op == "/" || op == "%") {
           return natural;
    } else {
        return boolean;
    }
}

type binop_expression::get_type() const {
    if(op == "=") {
        if(left->get_type() != right->get_type()) {
            error(line, "Left and right operands of '=' have different types.");
        }
    } else {
        if(left->get_type() != operand_type(op)) {
            error(line, std::string("Left operand of '") + op + "' has unexpected type.");
        }
        if(right->get_type() != operand_type(op)) {
            error(line, std::string("Right operand of '") + op + "' has unexpected type.");
        }
    }
    return return_type(op);
}

type trinaryop_expression::get_type() const {
    if(cond->get_type() != boolean) {
        error(line, "Condition part of ? : operator is not boolean type.");
    }
    if(left->get_type() != right->get_type()) {
        error(line, "Types of the ? : operator result are if different types.");
    }

    return left->get_type();
}

type not_expression::get_type() const {
    if(operand->get_type() != boolean) {
        error(line, "Operand of 'not' is not boolean.");
    }
    return boolean;
}

static type get_type_for_symbol(int line, std::string &id) {
    if (symbol_table.count(id) == 0) {
        error(line, std::string("Undefined variable: ") + id);
        return natural;//dead code
    }
    return symbol_table[id].symbol_type;
}

void assign_instructions::type_check() {
    if (left->size() != right->size()) {
        error(line, "Left and right hand sides number of assignment are of different.");
    }
    auto right_it = right->begin();
    for (auto left_it = left->begin(); left_it != left->end(); ++left_it, ++right_it) {
       if(get_type_for_symbol(line, *left_it) != (*right_it)->get_type()) {
           error(line, "Left and right hand sides of assignment are of different types.");
       }
    }
}

void read_instruction::type_check() {
    if(symbol_table.count(id) == 0) {
        error(line, std::string("Undefined variable: ") + id);
    }
}

void write_instruction::type_check() {
    exp_type = exp->get_type();
}

void if_instruction::type_check() {
    if(condition->get_type() != boolean) {
        error(line, "Condition of 'if' instruction is not boolean.");
    }
    type_check_commands(true_branch);
    type_check_commands(false_branch);
}

void while_instruction::type_check() {
    if(condition->get_type() != boolean) {
        error(line, "Condition of 'while' instruction is not boolean.");
    }
    type_check_commands(body);
}

void for_instruction::type_check() {
    type id_type = get_type_for_symbol(line, id); 
    if(id_type != lowerlimit->get_type()) {
        error(line, "FOR var and init value are of different types.");
    }
    if(id_type != upperlimit->get_type()) {
        error(line, "FOR var and limit value are of different types.");
    }
    type_check_commands(body);
}

void type_check_commands(std::list<instruction*>* commands) {
    if(!commands) {
        return;
    }

    std::list<instruction*>::iterator it;
    for(it = commands->begin(); it != commands->end(); ++it) {
        (*it)->type_check();
    }
}
