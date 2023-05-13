#include "implementation.hh"
#include <iostream>
#include <sstream>
#include <cstdlib>

mode current_mode;

void error(int line, std::string text) {
    std::cerr << "Line " << line << ": Error: " << text << std::endl;
    std::exit(1);
}

expression::~expression() {
}

number_expression::number_expression(std::string text) {
    std::stringstream ss(text);
    ss >> value;
}

boolean_expression::boolean_expression(bool _value) {
    value = _value;
}

long id = 0;

symbol::symbol(int _line, std::string _name, type _type) : line(_line), name(_name), symbol_type(_type) {
    label = next_label();
}

id_expression::id_expression(int _line, std::string _name)
    : line(_line), name(_name)
{}

binop_expression::~binop_expression() {
    delete left;
    delete right;
}

binop_expression::binop_expression(int _line, std::string _op, expression* _left, expression* _right)
    : line(_line), op(_op), left(_left), right(_right)
{}

trinaryop_expression::trinaryop_expression(int _line, expression* _cond, expression* _left, expression* _right)
    : line(_line), cond(_cond), left(_left), right(_right)
{}

trinaryop_expression::~trinaryop_expression() {
    delete cond;
    delete left;
    delete right;
}

not_expression::~not_expression() {
    delete operand;
}

not_expression::not_expression(int _line, std::string _op, expression* _operand)
    : line(_line), op(_op), operand(_operand)
{}

instruction::instruction(int _line)
    : line(_line)
{}

instruction::~instruction() {
}

int instruction::get_line() {
    return line;
}

assign_instructions::assign_instructions(int _line, std::list<std::string>* _left, std::list<expression*>* _right)
    : instruction(_line), left(_left), right(_right)
{}

assign_instructions::~assign_instructions() {
    //TODO: proper free
    delete right;
}

read_instruction::read_instruction(int _line, std::string _id)
    : instruction(_line), id(_id)
{}

write_instruction::write_instruction(int _line, expression* _exp)
    : instruction(_line), exp(_exp)
{}

write_instruction::~write_instruction() {
    delete exp;
}

if_instruction::if_instruction(int _line, expression* _condition, std::list<instruction*>* _true_branch, std::list<instruction*>* _false_branch)
    : instruction(_line), condition(_condition), true_branch(_true_branch), false_branch(_false_branch)
{}

if_instruction::~if_instruction() {
    delete condition;
    delete_commands(true_branch);
    delete_commands(false_branch);
}
    
while_instruction::while_instruction(int _line, expression* _condition, std::list<instruction*>* _body)
    : instruction(_line), condition(_condition), body(_body)
{}

while_instruction::~while_instruction() {
    delete condition;
    delete_commands(body);
}
    
for_instruction::for_instruction(int _line, std::string _id, expression* _lowerlimit, expression* _upperlimit, std::list<instruction*>* _body)
    : instruction(_line), id(_id), lowerlimit(_lowerlimit), upperlimit(_upperlimit), body(_body)
{}

for_instruction::~for_instruction() {
    delete lowerlimit;
    delete upperlimit;
    delete_commands(body);
}

void delete_commands(std::list<instruction*>* commands) {
    if(!commands) {
        return;
    }
    
    std::list<instruction*>::iterator it;
    for(it = commands->begin(); it != commands->end(); ++it) {
        delete (*it);
    }
    delete commands;
}
