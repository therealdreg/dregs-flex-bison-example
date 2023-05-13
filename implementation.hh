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

#ifndef IMPLEMENTATION_HH
#define IMPLEMENTATION_HH

#include <string>
#include <list>
#include <unordered_map>

enum mode {compiler, interpreter};

extern mode current_mode;

enum type {boolean, natural};

void error(int line, std::string text);

class expression {
  public:
    virtual type get_type() const = 0;
    virtual ~expression();
    virtual std::string get_code() const = 0;
    virtual unsigned get_value() const = 0;
    virtual bool is_const_expr() const = 0;
};

class number_expression : public expression {
  public:
    number_expression(std::string text);  
    type get_type() const;
    std::string get_code() const;
    unsigned get_value() const;    
    bool is_const_expr() const;
  private:
    unsigned value;
};

class boolean_expression : public expression {
  public:
    boolean_expression(bool _value);  
    type get_type() const;
    std::string get_code() const;
    unsigned get_value() const;    
    bool is_const_expr() const;
  private:
    bool value;
};

extern long id;

extern std::string next_label();

struct symbol {
    symbol() {}
    symbol(int _line, std::string _name, type _type);
    void declare();
    std::string get_code();
    int get_size();
    int line;
    std::string name;
    type symbol_type;
    std::string label;
};

extern std::unordered_map<std::string, symbol> symbol_table;
extern std::unordered_map<std::string, unsigned> value_table;

class id_expression : public expression {
  public:
    id_expression(int line, std::string _name);  
    type get_type() const;
    std::string get_code() const;
    unsigned get_value() const;    
    bool is_const_expr() const;
  private:
    int line;
    std::string name;
};

class binop_expression : public expression {
  public:
    binop_expression(int _line, std::string _op, expression* _left, expression* _right);
    ~binop_expression();
    type get_type() const;
    std::string get_code() const;
    unsigned get_value() const;    
    bool is_const_expr() const;
  private:
    int line;
    std::string op;
    expression* left;
    expression* right;
};

class trinaryop_expression : public expression {
  public:
    trinaryop_expression(int _line, expression *_cond, expression* _left, expression* _right);
    ~trinaryop_expression();
    type get_type() const;
    std::string get_code() const;
    unsigned get_value() const;
    bool is_const_expr() const;
  private:
    int line;
    expression* cond;
    expression* left;
    expression* right;
};

class not_expression : public expression {
  public:
    not_expression(int _line, std::string _op, expression* _operand);
    ~not_expression();
    type get_type() const;
    std::string get_code() const;
    unsigned get_value() const;    
    bool is_const_expr() const;
  private:
    int line;
    std::string op;
    expression* operand;
};

class instruction {
  public:
    instruction(int _line);
    virtual ~instruction();
    virtual void type_check() = 0;
    virtual std::string get_code() = 0;
    virtual void execute() = 0;
    int get_line();
  protected:
    int line;
};

class assign_instructions : public instruction {
  public:
    assign_instructions(int _line, std::list<std::string>* _left, std::list<expression*>* right);
    ~assign_instructions();
    void type_check();
    std::string get_code();
    void execute();
    bool is_const_expr() const;
  private:
    std::list<std::string>* left;
    std::list<expression*>* right;
};

class read_instruction : public instruction {
  public:
    read_instruction(int _line, std::string _id);
    void type_check();
    std::string get_code();
    void execute();
  private:
    std::string id;
};

class write_instruction : public instruction {
  public:
    write_instruction(int _line, expression* _exp);
    ~write_instruction();
    void type_check();
    std::string get_code();
    void execute();
  private:
    expression* exp;
    type exp_type;
};

class if_instruction : public instruction {
  public:
    if_instruction(int _line, expression* _condition, std::list<instruction*>* _true_branch, std::list<instruction*>* _false_branch);
    ~if_instruction();
    void type_check();
    std::string get_code();
    void execute();
  private:
    expression* condition;
    std::list<instruction*>* true_branch;
    std::list<instruction*>* false_branch;
};

class while_instruction : public instruction {
  public:
    while_instruction(int _line, expression* _condition, std::list<instruction*>* _body);
    ~while_instruction();
    void type_check();
    std::string get_code();
    void execute();
  private:
    expression* condition;
    std::list<instruction*>* body;
};

class for_instruction : public instruction {
  public:
    for_instruction(int _line, std::string _id, expression* _lowerlimit, expression* _upperlimit, std::list<instruction*>* _body);
    ~for_instruction();
    void type_check();
    std::string get_code();
    void execute();
  private:
    std::string id;
    expression* lowerlimit;
    expression* upperlimit;
    std::list<instruction*>* body;
};

void type_check_commands(std::list<instruction*>* commands);

void generate_code_of_commands(std::ostream& out, std::list<instruction*>* commands);

void execute_commands(std::list<instruction*>* commands);

void delete_commands(std::list<instruction*>* commands);

void generate_code(std::list<instruction*>* commands);

#endif // IMPLEMENTATION_HH
