// A Bison parser, made by GNU Bison 3.3.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2019 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.

// //                    "%code top" blocks.
#line 5 "while.y" // lalr1.cc:423

#include "implementation.hh"
#include <list>

#line 43 "while.tab.cc" // lalr1.cc:423




#include "while.tab.hh"




#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
#line 145 "while.tab.cc" // lalr1.cc:510

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
     :yydebug_ (false),
      yycdebug_ (&std::cerr)
#endif
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/

  // basic_symbol.
#if 201103L <= YY_CPLUSPLUS
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (basic_symbol&& that)
    : Base (std::move (that))
    , value ()
    , location (std::move (that.location))
  {
    switch (this->type_get ())
    {
      case 50: // expression
        value.move< expression* > (std::move (that.value));
        break;

      case 49: // command
        value.move< instruction* > (std::move (that.value));
        break;

      case 48: // expressions
        value.move< std::list<expression*>*  > (std::move (that.value));
        break;

      case 46: // commands
        value.move< std::list<instruction*>*  > (std::move (that.value));
        break;

      case 47: // ids
        value.move< std::list<std::string>*  > (std::move (that.value));
        break;

      case 27: // ID
      case 28: // NUM
        value.move< std::string > (std::move (that.value));
        break;

      default:
        break;
    }

  }
#endif

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->type_get ())
    {
      case 50: // expression
        value.copy< expression* > (YY_MOVE (that.value));
        break;

      case 49: // command
        value.copy< instruction* > (YY_MOVE (that.value));
        break;

      case 48: // expressions
        value.copy< std::list<expression*>*  > (YY_MOVE (that.value));
        break;

      case 46: // commands
        value.copy< std::list<instruction*>*  > (YY_MOVE (that.value));
        break;

      case 47: // ids
        value.copy< std::list<std::string>*  > (YY_MOVE (that.value));
        break;

      case 27: // ID
      case 28: // NUM
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->type_get ())
    {
      case 50: // expression
        value.move< expression* > (YY_MOVE (s.value));
        break;

      case 49: // command
        value.move< instruction* > (YY_MOVE (s.value));
        break;

      case 48: // expressions
        value.move< std::list<expression*>*  > (YY_MOVE (s.value));
        break;

      case 46: // commands
        value.move< std::list<instruction*>*  > (YY_MOVE (s.value));
        break;

      case 47: // ids
        value.move< std::list<std::string>*  > (YY_MOVE (s.value));
        break;

      case 27: // ID
      case 28: // NUM
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_type.
  parser::by_type::by_type ()
    : type (empty_symbol)
  {}

#if 201103L <= YY_CPLUSPLUS
  parser::by_type::by_type (by_type&& that)
    : type (that.type)
  {
    that.clear ();
  }
#endif

  parser::by_type::by_type (const by_type& that)
    : type (that.type)
  {}

  parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  void
  parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  void
  parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  int
  parser::by_type::type_get () const YY_NOEXCEPT
  {
    return type;
  }


  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_number_type
  parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 50: // expression
        value.YY_MOVE_OR_COPY< expression* > (YY_MOVE (that.value));
        break;

      case 49: // command
        value.YY_MOVE_OR_COPY< instruction* > (YY_MOVE (that.value));
        break;

      case 48: // expressions
        value.YY_MOVE_OR_COPY< std::list<expression*>*  > (YY_MOVE (that.value));
        break;

      case 46: // commands
        value.YY_MOVE_OR_COPY< std::list<instruction*>*  > (YY_MOVE (that.value));
        break;

      case 47: // ids
        value.YY_MOVE_OR_COPY< std::list<std::string>*  > (YY_MOVE (that.value));
        break;

      case 27: // ID
      case 28: // NUM
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 50: // expression
        value.move< expression* > (YY_MOVE (that.value));
        break;

      case 49: // command
        value.move< instruction* > (YY_MOVE (that.value));
        break;

      case 48: // expressions
        value.move< std::list<expression*>*  > (YY_MOVE (that.value));
        break;

      case 46: // commands
        value.move< std::list<instruction*>*  > (YY_MOVE (that.value));
        break;

      case 47: // ids
        value.move< std::list<std::string>*  > (YY_MOVE (that.value));
        break;

      case 27: // ID
      case 28: // NUM
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 50: // expression
        value.move< expression* > (that.value);
        break;

      case 49: // command
        value.move< instruction* > (that.value);
        break;

      case 48: // expressions
        value.move< std::list<expression*>*  > (that.value);
        break;

      case 46: // commands
        value.move< std::list<instruction*>*  > (that.value);
        break;

      case 47: // ids
        value.move< std::list<std::string>*  > (that.value);
        break;

      case 27: // ID
      case 28: // NUM
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case 50: // expression
        yylhs.value.emplace< expression* > ();
        break;

      case 49: // command
        yylhs.value.emplace< instruction* > ();
        break;

      case 48: // expressions
        yylhs.value.emplace< std::list<expression*>*  > ();
        break;

      case 46: // commands
        yylhs.value.emplace< std::list<instruction*>*  > ();
        break;

      case 47: // ids
        yylhs.value.emplace< std::list<std::string>*  > ();
        break;

      case 27: // ID
      case 28: // NUM
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 59 "while.y" // lalr1.cc:919
    {
        type_check_commands(yystack_[1].value.as < std::list<instruction*>*  > ());
        if(current_mode == compiler) {
            generate_code(yystack_[1].value.as < std::list<instruction*>*  > ());
        } else {
            execute_commands(yystack_[1].value.as < std::list<instruction*>*  > ());
        }
        delete_commands(yystack_[1].value.as < std::list<instruction*>*  > ());
    }
#line 787 "while.tab.cc" // lalr1.cc:919
    break;

  case 5:
#line 78 "while.y" // lalr1.cc:919
    {
        symbol(yystack_[1].location.begin.line, yystack_[0].value.as < std::string > (), boolean).declare();
    }
#line 795 "while.tab.cc" // lalr1.cc:919
    break;

  case 6:
#line 83 "while.y" // lalr1.cc:919
    {
        symbol(yystack_[1].location.begin.line, yystack_[0].value.as < std::string > (), natural).declare();
    }
#line 803 "while.tab.cc" // lalr1.cc:919
    break;

  case 7:
#line 90 "while.y" // lalr1.cc:919
    {
        yylhs.value.as < std::list<instruction*>*  > () = new std::list<instruction*>();
    }
#line 811 "while.tab.cc" // lalr1.cc:919
    break;

  case 8:
#line 95 "while.y" // lalr1.cc:919
    {
        yystack_[1].value.as < std::list<instruction*>*  > ()->push_back(yystack_[0].value.as < instruction* > ());
        yylhs.value.as < std::list<instruction*>*  > () = yystack_[1].value.as < std::list<instruction*>*  > ();
    }
#line 820 "while.tab.cc" // lalr1.cc:919
    break;

  case 9:
#line 103 "while.y" // lalr1.cc:919
    {
         yylhs.value.as < std::list<std::string>*  > () = new std::list<std::string>();
         yylhs.value.as < std::list<std::string>*  > ()->push_back(yystack_[0].value.as < std::string > ());
    }
#line 829 "while.tab.cc" // lalr1.cc:919
    break;

  case 10:
#line 109 "while.y" // lalr1.cc:919
    {
          yystack_[2].value.as < std::list<std::string>*  > ()->push_back(yystack_[0].value.as < std::string > ());
          yylhs.value.as < std::list<std::string>*  > () = yystack_[2].value.as < std::list<std::string>*  > ();
    }
#line 838 "while.tab.cc" // lalr1.cc:919
    break;

  case 11:
#line 117 "while.y" // lalr1.cc:919
    {
         yylhs.value.as < std::list<expression*>*  > () = new std::list<expression*>();
         yylhs.value.as < std::list<expression*>*  > ()->push_back(yystack_[0].value.as < expression* > ());
    }
#line 847 "while.tab.cc" // lalr1.cc:919
    break;

  case 12:
#line 123 "while.y" // lalr1.cc:919
    {
          yystack_[2].value.as < std::list<expression*>*  > ()->push_back(yystack_[0].value.as < expression* > ());
          yylhs.value.as < std::list<expression*>*  > () = yystack_[2].value.as < std::list<expression*>*  > ();
    }
#line 856 "while.tab.cc" // lalr1.cc:919
    break;

  case 13:
#line 131 "while.y" // lalr1.cc:919
    {
        yylhs.value.as < instruction* > () = new read_instruction(yystack_[3].location.begin.line, yystack_[1].value.as < std::string > ());
    }
#line 864 "while.tab.cc" // lalr1.cc:919
    break;

  case 14:
#line 136 "while.y" // lalr1.cc:919
    {
        yylhs.value.as < instruction* > () = new write_instruction(yystack_[3].location.begin.line, yystack_[1].value.as < expression* > ());
    }
#line 872 "while.tab.cc" // lalr1.cc:919
    break;

  case 15:
#line 141 "while.y" // lalr1.cc:919
    {
        yylhs.value.as < instruction* > () = new assign_instructions(yystack_[1].location.begin.line, yystack_[2].value.as < std::list<std::string>*  > (), yystack_[0].value.as < std::list<expression*>*  > ());
    }
#line 880 "while.tab.cc" // lalr1.cc:919
    break;

  case 16:
#line 146 "while.y" // lalr1.cc:919
    {
        yylhs.value.as < instruction* > () = new if_instruction(yystack_[4].location.begin.line, yystack_[3].value.as < expression* > (), yystack_[1].value.as < std::list<instruction*>*  > (), 0);
    }
#line 888 "while.tab.cc" // lalr1.cc:919
    break;

  case 17:
#line 151 "while.y" // lalr1.cc:919
    {
        yylhs.value.as < instruction* > () = new if_instruction(yystack_[6].location.begin.line, yystack_[5].value.as < expression* > (), yystack_[3].value.as < std::list<instruction*>*  > (), yystack_[1].value.as < std::list<instruction*>*  > ());
    }
#line 896 "while.tab.cc" // lalr1.cc:919
    break;

  case 18:
#line 156 "while.y" // lalr1.cc:919
    {
        yylhs.value.as < instruction* > () = new while_instruction(yystack_[4].location.begin.line, yystack_[3].value.as < expression* > (), yystack_[1].value.as < std::list<instruction*>*  > ());
    }
#line 904 "while.tab.cc" // lalr1.cc:919
    break;

  case 19:
#line 161 "while.y" // lalr1.cc:919
    {
        yylhs.value.as < instruction* > () = new for_instruction(yystack_[8].location.begin.line, yystack_[7].value.as < std::string > (), yystack_[5].value.as < expression* > (), yystack_[3].value.as < expression* > (), yystack_[1].value.as < std::list<instruction*>*  > ());
    }
#line 912 "while.tab.cc" // lalr1.cc:919
    break;

  case 20:
#line 168 "while.y" // lalr1.cc:919
    {
        yylhs.value.as < expression* > () = new number_expression(yystack_[0].value.as < std::string > ());
    }
#line 920 "while.tab.cc" // lalr1.cc:919
    break;

  case 21:
#line 173 "while.y" // lalr1.cc:919
    {
        yylhs.value.as < expression* > () = new boolean_expression(true);
    }
#line 928 "while.tab.cc" // lalr1.cc:919
    break;

  case 22:
#line 178 "while.y" // lalr1.cc:919
    {
        yylhs.value.as < expression* > () = new boolean_expression(false);
    }
#line 936 "while.tab.cc" // lalr1.cc:919
    break;

  case 23:
#line 183 "while.y" // lalr1.cc:919
    {
        yylhs.value.as < expression* > () = new id_expression(yystack_[0].location.begin.line, yystack_[0].value.as < std::string > ());
    }
#line 944 "while.tab.cc" // lalr1.cc:919
    break;

  case 24:
#line 188 "while.y" // lalr1.cc:919
    {
        yylhs.value.as < expression* > () = new trinaryop_expression(yystack_[5].location.begin.line, yystack_[5].value.as < expression* > (), yystack_[3].value.as < expression* > (), yystack_[1].value.as < expression* > ());
    }
#line 952 "while.tab.cc" // lalr1.cc:919
    break;

  case 25:
#line 193 "while.y" // lalr1.cc:919
    {
        yylhs.value.as < expression* > () = new binop_expression(yystack_[1].location.begin.line, "+", yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > ());
    }
#line 960 "while.tab.cc" // lalr1.cc:919
    break;

  case 26:
#line 198 "while.y" // lalr1.cc:919
    {
        yylhs.value.as < expression* > () = new binop_expression(yystack_[1].location.begin.line, "-", yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > ());
    }
#line 968 "while.tab.cc" // lalr1.cc:919
    break;

  case 27:
#line 203 "while.y" // lalr1.cc:919
    {
        yylhs.value.as < expression* > () = new binop_expression(yystack_[1].location.begin.line, "*", yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > ());
    }
#line 976 "while.tab.cc" // lalr1.cc:919
    break;

  case 28:
#line 208 "while.y" // lalr1.cc:919
    {
        yylhs.value.as < expression* > () = new binop_expression(yystack_[1].location.begin.line, "/", yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > ());
    }
#line 984 "while.tab.cc" // lalr1.cc:919
    break;

  case 29:
#line 213 "while.y" // lalr1.cc:919
    {
        yylhs.value.as < expression* > () = new binop_expression(yystack_[1].location.begin.line, "%", yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > ());
    }
#line 992 "while.tab.cc" // lalr1.cc:919
    break;

  case 30:
#line 218 "while.y" // lalr1.cc:919
    {
        yylhs.value.as < expression* > () = new binop_expression(yystack_[1].location.begin.line, "<", yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > ());
    }
#line 1000 "while.tab.cc" // lalr1.cc:919
    break;

  case 31:
#line 223 "while.y" // lalr1.cc:919
    {
        yylhs.value.as < expression* > () = new binop_expression(yystack_[1].location.begin.line, ">", yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > ());
    }
#line 1008 "while.tab.cc" // lalr1.cc:919
    break;

  case 32:
#line 228 "while.y" // lalr1.cc:919
    {
        yylhs.value.as < expression* > () = new binop_expression(yystack_[1].location.begin.line, "<=", yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > ());
    }
#line 1016 "while.tab.cc" // lalr1.cc:919
    break;

  case 33:
#line 233 "while.y" // lalr1.cc:919
    {
        yylhs.value.as < expression* > () = new binop_expression(yystack_[1].location.begin.line, ">=", yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > ());
    }
#line 1024 "while.tab.cc" // lalr1.cc:919
    break;

  case 34:
#line 238 "while.y" // lalr1.cc:919
    {
        yylhs.value.as < expression* > () = new binop_expression(yystack_[1].location.begin.line, "and", yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > ());
    }
#line 1032 "while.tab.cc" // lalr1.cc:919
    break;

  case 35:
#line 243 "while.y" // lalr1.cc:919
    {
        yylhs.value.as < expression* > () = new binop_expression(yystack_[1].location.begin.line, "or", yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > ());
    }
#line 1040 "while.tab.cc" // lalr1.cc:919
    break;

  case 36:
#line 248 "while.y" // lalr1.cc:919
    {
        yylhs.value.as < expression* > () = new binop_expression(yystack_[1].location.begin.line, "=", yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > ());
    }
#line 1048 "while.tab.cc" // lalr1.cc:919
    break;

  case 37:
#line 253 "while.y" // lalr1.cc:919
    {
        yylhs.value.as < expression* > () = new not_expression(yystack_[1].location.begin.line, "not", yystack_[0].value.as < expression* > ());
    }
#line 1056 "while.tab.cc" // lalr1.cc:919
    break;

  case 38:
#line 258 "while.y" // lalr1.cc:919
    {
        yylhs.value.as < expression* > () = yystack_[1].value.as < expression* > ();
    }
#line 1064 "while.tab.cc" // lalr1.cc:919
    break;


#line 1068 "while.tab.cc" // lalr1.cc:919
            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


  const signed char parser::yypact_ninf_ = -39;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
       2,   -20,    11,   -39,   -39,    13,   -39,   -14,    14,   -39,
     116,   -39,   -39,   -39,    15,    22,   100,   100,    24,   -39,
      -4,   -39,    25,   100,   -39,   -39,   100,   -39,   -39,   100,
      38,    50,    34,   100,    27,    35,   135,   115,   -39,   -39,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   -39,   100,    29,    63,   -39,   -39,   -39,   -39,
     100,   188,   241,   251,   260,     8,     8,     8,     8,    -1,
      -1,   -39,   -39,   -39,    -6,   230,   100,   214,   -39,   -39,
     -39,   100,    63,   100,   195,    76,   155,   -39,   -39,   -39,
     215,   -39
  };

  const unsigned char
  parser::yydefact_[] =
  {
       0,     0,     0,     3,     1,     0,     7,     0,     0,     4,
       0,     5,     6,     2,     0,     0,     0,     0,     0,     9,
       0,     8,     0,     0,    21,    22,     0,    23,    20,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    37,     7,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     7,     0,    15,    11,    10,    13,    14,    38,
       0,     0,    35,    34,    36,    30,    31,    32,    33,    25,
      26,    27,    28,    29,     0,     0,     0,     0,     7,    16,
      18,     0,    12,     0,     0,     0,     0,    17,     7,    24,
       0,    19
  };

  const signed char
  parser::yypgoto_[] =
  {
     -39,   -39,   -39,   -39,   -38,   -39,   -39,   -39,   -17
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     2,     5,     9,    10,    20,    54,    21,    30
  };

  const unsigned char
  parser::yytable_[] =
  {
      31,    61,    14,    15,    16,     1,    36,     3,    17,    37,
      80,     4,    38,    11,    74,    33,    55,     6,    18,     7,
       8,    19,    34,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    22,    75,    49,    50,    51,
      84,    12,    23,    77,    47,    48,    49,    50,    51,    39,
      90,    32,    35,    53,    56,    76,    57,     0,     0,    82,
       0,     0,     0,     0,    85,    52,    86,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    88,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,     0,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    24,    25,     0,
      26,    13,     0,     0,    14,    15,    16,    27,    28,     0,
      17,     0,     0,     0,     0,     0,    59,     0,    60,     0,
      18,    29,     0,    19,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    58,     0,     0,     0,
       0,     0,     0,     0,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    89,     0,     0,     0,
       0,     0,     0,     0,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    14,    15,    16,     0,
      78,    79,    17,    14,    15,    16,     0,     0,    87,    17,
       0,     0,    18,     0,     0,    19,     0,     0,     0,    18,
       0,     0,    19,    14,    15,    16,     0,     0,     0,    17,
       0,    91,     0,     0,     0,     0,    83,     0,     0,    18,
       0,     0,    19,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    81,     0,     0,     0,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    43,    44,    45,    46,    47,    48,    49,    50,
      51
  };

  const signed char
  parser::yycheck_[] =
  {
      17,    39,     8,     9,    10,     3,    23,    27,    14,    26,
      16,     0,    29,    27,    52,    19,    33,     4,    24,     6,
       7,    27,    26,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    20,    53,    38,    39,    40,
      78,    27,    20,    60,    36,    37,    38,    39,    40,    11,
      88,    27,    27,    19,    27,    26,    21,    -1,    -1,    76,
      -1,    -1,    -1,    -1,    81,    15,    83,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    15,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    17,    18,    -1,
      20,     5,    -1,    -1,     8,     9,    10,    27,    28,    -1,
      14,    -1,    -1,    -1,    -1,    -1,    21,    -1,    23,    -1,
      24,    41,    -1,    27,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,     8,     9,    10,    -1,
      12,    13,    14,     8,     9,    10,    -1,    -1,    13,    14,
      -1,    -1,    24,    -1,    -1,    27,    -1,    -1,    -1,    24,
      -1,    -1,    27,     8,     9,    10,    -1,    -1,    -1,    14,
      -1,    16,    -1,    -1,    -1,    -1,    22,    -1,    -1,    24,
      -1,    -1,    27,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    25,    -1,    -1,    -1,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    32,    33,    34,    35,    36,    37,    38,    39,
      40
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     3,    43,    27,     0,    44,     4,     6,     7,    45,
      46,    27,    27,     5,     8,     9,    10,    14,    24,    27,
      47,    49,    20,    20,    17,    18,    20,    27,    28,    41,
      50,    50,    27,    19,    26,    27,    50,    50,    50,    11,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    15,    19,    48,    50,    27,    21,    21,    21,
      23,    46,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    46,    50,    26,    50,    12,    13,
      16,    25,    50,    22,    46,    50,    50,    13,    15,    21,
      46,    16
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    42,    43,    44,    44,    45,    45,    46,    46,    47,
      47,    48,    48,    49,    49,    49,    49,    49,    49,    49,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     6,     0,     2,     2,     2,     0,     2,     1,
       3,     1,     3,     4,     4,     3,     5,     7,     5,     9,
       1,     1,     1,     1,     7,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     3
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "$end", "error", "$undefined", "PRG", "BEG", "END", "BOO", "NAT", "REA",
  "WRI", "IF", "THE", "ELS", "EIF", "WHI", "DO", "DON", "TRU", "FAL",
  "ASN", "OP", "CL", "COL", "QUE", "FOR", "TO", "COM", "ID", "NUM", "OR",
  "AND", "EQ", "LS", "GR", "LSE", "GRE", "ADD", "SUB", "MUL", "DIV", "MOD",
  "NOT", "$accept", "start", "declarations", "declaration", "commands",
  "ids", "expressions", "command", "expression", YY_NULLPTR
  };


  const unsigned short
  parser::yyrline_[] =
  {
       0,    58,    58,    70,    73,    77,    82,    90,    94,   102,
     108,   116,   122,   130,   135,   140,   145,   150,   155,   160,
     167,   172,   177,   182,   187,   192,   197,   202,   207,   212,
     217,   222,   227,   232,   237,   242,   247,   252,   257
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  parser::token_number_type
  parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const token_number_type
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41
    };
    const unsigned user_token_number_max_ = 296;
    const token_number_type undef_token_ = 2;

    if (static_cast<int> (t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // yy
#line 1506 "while.tab.cc" // lalr1.cc:1242
#line 263 "while.y" // lalr1.cc:1243

