// A Bison parser, made by GNU Bison 3.5.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

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





#include "GenesysParser.h"


// Unqualified %code blocks.
#line 40 "bisonparser.yy"

# include "Genesys++-driver.h"


#line 50 "../GenesysParser.cpp"


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
#line 141 "../GenesysParser.cpp"


  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  genesyspp_parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  genesyspp_parser::genesyspp_parser (genesyspp_driver& driver_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      driver (driver_yyarg)
  {}

  genesyspp_parser::~genesyspp_parser ()
  {}

  genesyspp_parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  genesyspp_parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  genesyspp_parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  genesyspp_parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  genesyspp_parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  genesyspp_parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  genesyspp_parser::symbol_number_type
  genesyspp_parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[+state];
  }

  genesyspp_parser::stack_symbol_type::stack_symbol_type ()
  {}

  genesyspp_parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 3: // NUMD
      case 4: // NUMH
      case 5: // CTEZERO
      case 6: // oLE
      case 7: // oGE
      case 8: // oEQ
      case 9: // oNE
      case 10: // oAND
      case 11: // oOR
      case 12: // oNOT
      case 13: // fSIN
      case 14: // fCOS
      case 15: // fROUND
      case 16: // fMOD
      case 17: // fTRUNC
      case 18: // fFRAC
      case 19: // fEXP
      case 20: // fRND1
      case 21: // fEXPO
      case 22: // fNORM
      case 23: // fUNIF
      case 24: // fWEIB
      case 25: // fLOGN
      case 26: // fGAMM
      case 27: // fERLA
      case 28: // fTRIA
      case 29: // fBETA
      case 30: // fDISC
      case 31: // fTNOW
      case 32: // fTFIN
      case 33: // cIF
      case 34: // cELSE
      case 35: // cFOR
      case 36: // cTO
      case 37: // cDO
      case 38: // ATRIB
      case 39: // ILLEGAL
      case 40: // RESOURCE
      case 41: // fNR
      case 42: // fMR
      case 43: // fIRF
      case 44: // fRESSEIZES
      case 45: // fSTATE
      case 46: // fSETSUM
      case 47: // QUEUE
      case 48: // fNQ
      case 49: // fFIRSTINQ
      case 50: // fLASTINQ
      case 51: // fSAQUE
      case 52: // fAQUE
      case 53: // SET
      case 54: // fNUMSET
      case 55: // CSTAT
      case 56: // fTAVG
      case 57: // VARI
      case 58: // FORM
      case 76: // input
      case 77: // programa
      case 78: // expressao
      case 79: // numero
      case 80: // aritmetica
      case 81: // relacional
      case 82: // comando
      case 83: // comandoIF
      case 84: // comandoFOR
      case 85: // funcao
      case 86: // funcaoKernel
      case 87: // funcaoTrig
      case 88: // funcaoArit
      case 89: // funcaoProb
      case 90: // funcaoUser
      case 91: // listaparm
      case 92: // illegal
      case 93: // atributo
      case 94: // variavel
      case 95: // atribuicao
      case 96: // formula
      case 97: // funcaoPlugin
        value.YY_MOVE_OR_COPY< obj_t > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  genesyspp_parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 3: // NUMD
      case 4: // NUMH
      case 5: // CTEZERO
      case 6: // oLE
      case 7: // oGE
      case 8: // oEQ
      case 9: // oNE
      case 10: // oAND
      case 11: // oOR
      case 12: // oNOT
      case 13: // fSIN
      case 14: // fCOS
      case 15: // fROUND
      case 16: // fMOD
      case 17: // fTRUNC
      case 18: // fFRAC
      case 19: // fEXP
      case 20: // fRND1
      case 21: // fEXPO
      case 22: // fNORM
      case 23: // fUNIF
      case 24: // fWEIB
      case 25: // fLOGN
      case 26: // fGAMM
      case 27: // fERLA
      case 28: // fTRIA
      case 29: // fBETA
      case 30: // fDISC
      case 31: // fTNOW
      case 32: // fTFIN
      case 33: // cIF
      case 34: // cELSE
      case 35: // cFOR
      case 36: // cTO
      case 37: // cDO
      case 38: // ATRIB
      case 39: // ILLEGAL
      case 40: // RESOURCE
      case 41: // fNR
      case 42: // fMR
      case 43: // fIRF
      case 44: // fRESSEIZES
      case 45: // fSTATE
      case 46: // fSETSUM
      case 47: // QUEUE
      case 48: // fNQ
      case 49: // fFIRSTINQ
      case 50: // fLASTINQ
      case 51: // fSAQUE
      case 52: // fAQUE
      case 53: // SET
      case 54: // fNUMSET
      case 55: // CSTAT
      case 56: // fTAVG
      case 57: // VARI
      case 58: // FORM
      case 76: // input
      case 77: // programa
      case 78: // expressao
      case 79: // numero
      case 80: // aritmetica
      case 81: // relacional
      case 82: // comando
      case 83: // comandoIF
      case 84: // comandoFOR
      case 85: // funcao
      case 86: // funcaoKernel
      case 87: // funcaoTrig
      case 88: // funcaoArit
      case 89: // funcaoProb
      case 90: // funcaoUser
      case 91: // listaparm
      case 92: // illegal
      case 93: // atributo
      case 94: // variavel
      case 95: // atribuicao
      case 96: // formula
      case 97: // funcaoPlugin
        value.move< obj_t > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  genesyspp_parser::stack_symbol_type&
  genesyspp_parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 3: // NUMD
      case 4: // NUMH
      case 5: // CTEZERO
      case 6: // oLE
      case 7: // oGE
      case 8: // oEQ
      case 9: // oNE
      case 10: // oAND
      case 11: // oOR
      case 12: // oNOT
      case 13: // fSIN
      case 14: // fCOS
      case 15: // fROUND
      case 16: // fMOD
      case 17: // fTRUNC
      case 18: // fFRAC
      case 19: // fEXP
      case 20: // fRND1
      case 21: // fEXPO
      case 22: // fNORM
      case 23: // fUNIF
      case 24: // fWEIB
      case 25: // fLOGN
      case 26: // fGAMM
      case 27: // fERLA
      case 28: // fTRIA
      case 29: // fBETA
      case 30: // fDISC
      case 31: // fTNOW
      case 32: // fTFIN
      case 33: // cIF
      case 34: // cELSE
      case 35: // cFOR
      case 36: // cTO
      case 37: // cDO
      case 38: // ATRIB
      case 39: // ILLEGAL
      case 40: // RESOURCE
      case 41: // fNR
      case 42: // fMR
      case 43: // fIRF
      case 44: // fRESSEIZES
      case 45: // fSTATE
      case 46: // fSETSUM
      case 47: // QUEUE
      case 48: // fNQ
      case 49: // fFIRSTINQ
      case 50: // fLASTINQ
      case 51: // fSAQUE
      case 52: // fAQUE
      case 53: // SET
      case 54: // fNUMSET
      case 55: // CSTAT
      case 56: // fTAVG
      case 57: // VARI
      case 58: // FORM
      case 76: // input
      case 77: // programa
      case 78: // expressao
      case 79: // numero
      case 80: // aritmetica
      case 81: // relacional
      case 82: // comando
      case 83: // comandoIF
      case 84: // comandoFOR
      case 85: // funcao
      case 86: // funcaoKernel
      case 87: // funcaoTrig
      case 88: // funcaoArit
      case 89: // funcaoProb
      case 90: // funcaoUser
      case 91: // listaparm
      case 92: // illegal
      case 93: // atributo
      case 94: // variavel
      case 95: // atribuicao
      case 96: // formula
      case 97: // funcaoPlugin
        value.copy< obj_t > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  genesyspp_parser::stack_symbol_type&
  genesyspp_parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 3: // NUMD
      case 4: // NUMH
      case 5: // CTEZERO
      case 6: // oLE
      case 7: // oGE
      case 8: // oEQ
      case 9: // oNE
      case 10: // oAND
      case 11: // oOR
      case 12: // oNOT
      case 13: // fSIN
      case 14: // fCOS
      case 15: // fROUND
      case 16: // fMOD
      case 17: // fTRUNC
      case 18: // fFRAC
      case 19: // fEXP
      case 20: // fRND1
      case 21: // fEXPO
      case 22: // fNORM
      case 23: // fUNIF
      case 24: // fWEIB
      case 25: // fLOGN
      case 26: // fGAMM
      case 27: // fERLA
      case 28: // fTRIA
      case 29: // fBETA
      case 30: // fDISC
      case 31: // fTNOW
      case 32: // fTFIN
      case 33: // cIF
      case 34: // cELSE
      case 35: // cFOR
      case 36: // cTO
      case 37: // cDO
      case 38: // ATRIB
      case 39: // ILLEGAL
      case 40: // RESOURCE
      case 41: // fNR
      case 42: // fMR
      case 43: // fIRF
      case 44: // fRESSEIZES
      case 45: // fSTATE
      case 46: // fSETSUM
      case 47: // QUEUE
      case 48: // fNQ
      case 49: // fFIRSTINQ
      case 50: // fLASTINQ
      case 51: // fSAQUE
      case 52: // fAQUE
      case 53: // SET
      case 54: // fNUMSET
      case 55: // CSTAT
      case 56: // fTAVG
      case 57: // VARI
      case 58: // FORM
      case 76: // input
      case 77: // programa
      case 78: // expressao
      case 79: // numero
      case 80: // aritmetica
      case 81: // relacional
      case 82: // comando
      case 83: // comandoIF
      case 84: // comandoFOR
      case 85: // funcao
      case 86: // funcaoKernel
      case 87: // funcaoTrig
      case 88: // funcaoArit
      case 89: // funcaoProb
      case 90: // funcaoUser
      case 91: // listaparm
      case 92: // illegal
      case 93: // atributo
      case 94: // variavel
      case 95: // atribuicao
      case 96: // formula
      case 97: // funcaoPlugin
        value.move< obj_t > (that.value);
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
  genesyspp_parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  genesyspp_parser::yy_print_ (std::ostream& yyo,
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
  genesyspp_parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  genesyspp_parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  genesyspp_parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  genesyspp_parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  genesyspp_parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  genesyspp_parser::debug_level_type
  genesyspp_parser::debug_level () const
  {
    return yydebug_;
  }

  void
  genesyspp_parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  genesyspp_parser::state_type
  genesyspp_parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  genesyspp_parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  genesyspp_parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  genesyspp_parser::operator() ()
  {
    return parse ();
  }

  int
  genesyspp_parser::parse ()
  {
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


    // User initialization code.
#line 33 "bisonparser.yy"
{
  // Initialize the initial location.
  //@$.begin.filename = @$.end.filename = &driver.getFile();
}

#line 775 "../GenesysParser.cpp"


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
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
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
            symbol_type yylookahead (yylex (driver));
            yyla.move (yylookahead);
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
      {
        goto yydefault;
      }

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
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
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
      case 3: // NUMD
      case 4: // NUMH
      case 5: // CTEZERO
      case 6: // oLE
      case 7: // oGE
      case 8: // oEQ
      case 9: // oNE
      case 10: // oAND
      case 11: // oOR
      case 12: // oNOT
      case 13: // fSIN
      case 14: // fCOS
      case 15: // fROUND
      case 16: // fMOD
      case 17: // fTRUNC
      case 18: // fFRAC
      case 19: // fEXP
      case 20: // fRND1
      case 21: // fEXPO
      case 22: // fNORM
      case 23: // fUNIF
      case 24: // fWEIB
      case 25: // fLOGN
      case 26: // fGAMM
      case 27: // fERLA
      case 28: // fTRIA
      case 29: // fBETA
      case 30: // fDISC
      case 31: // fTNOW
      case 32: // fTFIN
      case 33: // cIF
      case 34: // cELSE
      case 35: // cFOR
      case 36: // cTO
      case 37: // cDO
      case 38: // ATRIB
      case 39: // ILLEGAL
      case 40: // RESOURCE
      case 41: // fNR
      case 42: // fMR
      case 43: // fIRF
      case 44: // fRESSEIZES
      case 45: // fSTATE
      case 46: // fSETSUM
      case 47: // QUEUE
      case 48: // fNQ
      case 49: // fFIRSTINQ
      case 50: // fLASTINQ
      case 51: // fSAQUE
      case 52: // fAQUE
      case 53: // SET
      case 54: // fNUMSET
      case 55: // CSTAT
      case 56: // fTAVG
      case 57: // VARI
      case 58: // FORM
      case 76: // input
      case 77: // programa
      case 78: // expressao
      case 79: // numero
      case 80: // aritmetica
      case 81: // relacional
      case 82: // comando
      case 83: // comandoIF
      case 84: // comandoFOR
      case 85: // funcao
      case 86: // funcaoKernel
      case 87: // funcaoTrig
      case 88: // funcaoArit
      case 89: // funcaoProb
      case 90: // funcaoUser
      case 91: // listaparm
      case 92: // illegal
      case 93: // atributo
      case 94: // variavel
      case 95: // atribuicao
      case 96: // formula
      case 97: // funcaoPlugin
        yylhs.value.emplace< obj_t > ();
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
  case 3:
#line 197 "bisonparser.yy"
                         {YYACCEPT;}
#line 983 "../GenesysParser.cpp"
    break;

  case 4:
#line 198 "bisonparser.yy"
                                                { driver.setResult(yystack_[0].value.as < obj_t > ().valor);}
#line 989 "../GenesysParser.cpp"
    break;

  case 5:
#line 199 "bisonparser.yy"
              { yylhs.value.as < obj_t > () = yystack_[0].value.as < obj_t > (); }
#line 995 "../GenesysParser.cpp"
    break;

  case 6:
#line 200 "bisonparser.yy"
                                                { yyerrok; }
#line 1001 "../GenesysParser.cpp"
    break;

  case 7:
#line 203 "bisonparser.yy"
                                                { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1007 "../GenesysParser.cpp"
    break;

  case 8:
#line 206 "bisonparser.yy"
                                               {yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1013 "../GenesysParser.cpp"
    break;

  case 9:
#line 207 "bisonparser.yy"
                                               {yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1019 "../GenesysParser.cpp"
    break;

  case 10:
#line 208 "bisonparser.yy"
                                               {yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1025 "../GenesysParser.cpp"
    break;

  case 11:
#line 209 "bisonparser.yy"
                                               {yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1031 "../GenesysParser.cpp"
    break;

  case 12:
#line 210 "bisonparser.yy"
                                                           {yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1037 "../GenesysParser.cpp"
    break;

  case 13:
#line 211 "bisonparser.yy"
                                               {yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1043 "../GenesysParser.cpp"
    break;

  case 14:
#line 212 "bisonparser.yy"
                                               {yylhs.value.as < obj_t > ().valor = yystack_[1].value.as < obj_t > ().valor;}
#line 1049 "../GenesysParser.cpp"
    break;

  case 15:
#line 213 "bisonparser.yy"
                                               {yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1055 "../GenesysParser.cpp"
    break;

  case 16:
#line 215 "bisonparser.yy"
                                               {yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1061 "../GenesysParser.cpp"
    break;

  case 17:
#line 217 "bisonparser.yy"
                                               {yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1067 "../GenesysParser.cpp"
    break;

  case 18:
#line 220 "bisonparser.yy"
                                               { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1073 "../GenesysParser.cpp"
    break;

  case 19:
#line 221 "bisonparser.yy"
                                               { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1079 "../GenesysParser.cpp"
    break;

  case 20:
#line 224 "bisonparser.yy"
                                               { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor + yystack_[0].value.as < obj_t > ().valor;}
#line 1085 "../GenesysParser.cpp"
    break;

  case 21:
#line 225 "bisonparser.yy"
                                               { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor - yystack_[0].value.as < obj_t > ().valor;}
#line 1091 "../GenesysParser.cpp"
    break;

  case 22:
#line 226 "bisonparser.yy"
                                               { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor / yystack_[0].value.as < obj_t > ().valor;}
#line 1097 "../GenesysParser.cpp"
    break;

  case 23:
#line 227 "bisonparser.yy"
                                               { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor * yystack_[0].value.as < obj_t > ().valor;}
#line 1103 "../GenesysParser.cpp"
    break;

  case 24:
#line 228 "bisonparser.yy"
                                               { yylhs.value.as < obj_t > ().valor = pow(yystack_[2].value.as < obj_t > ().valor,yystack_[0].value.as < obj_t > ().valor);}
#line 1109 "../GenesysParser.cpp"
    break;

  case 25:
#line 229 "bisonparser.yy"
                                               { yylhs.value.as < obj_t > ().valor = exp(yystack_[1].value.as < obj_t > ().valor);}
#line 1115 "../GenesysParser.cpp"
    break;

  case 26:
#line 230 "bisonparser.yy"
                                               { yylhs.value.as < obj_t > ().valor = -yystack_[0].value.as < obj_t > ().valor;}
#line 1121 "../GenesysParser.cpp"
    break;

  case 27:
#line 233 "bisonparser.yy"
                                               { yylhs.value.as < obj_t > ().valor = (int) yystack_[2].value.as < obj_t > ().valor && (int) yystack_[0].value.as < obj_t > ().valor;}
#line 1127 "../GenesysParser.cpp"
    break;

  case 28:
#line 234 "bisonparser.yy"
                                               { yylhs.value.as < obj_t > ().valor = (int) yystack_[2].value.as < obj_t > ().valor || (int) yystack_[0].value.as < obj_t > ().valor;}
#line 1133 "../GenesysParser.cpp"
    break;

  case 29:
#line 235 "bisonparser.yy"
                                               { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor < yystack_[0].value.as < obj_t > ().valor ? 1 : 0;}
#line 1139 "../GenesysParser.cpp"
    break;

  case 30:
#line 236 "bisonparser.yy"
                                               { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor <= yystack_[0].value.as < obj_t > ().valor ? 1 : 0;}
#line 1145 "../GenesysParser.cpp"
    break;

  case 31:
#line 237 "bisonparser.yy"
                                               { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor > yystack_[0].value.as < obj_t > ().valor ? 1 : 0;}
#line 1151 "../GenesysParser.cpp"
    break;

  case 32:
#line 238 "bisonparser.yy"
                                               { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor >= yystack_[0].value.as < obj_t > ().valor ? 1 : 0;}
#line 1157 "../GenesysParser.cpp"
    break;

  case 33:
#line 239 "bisonparser.yy"
                                               { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor == yystack_[0].value.as < obj_t > ().valor ? 1 : 0;}
#line 1163 "../GenesysParser.cpp"
    break;

  case 34:
#line 240 "bisonparser.yy"
                                               { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor != yystack_[0].value.as < obj_t > ().valor ? 1 : 0;}
#line 1169 "../GenesysParser.cpp"
    break;

  case 35:
#line 243 "bisonparser.yy"
                            { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1175 "../GenesysParser.cpp"
    break;

  case 36:
#line 244 "bisonparser.yy"
                            { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1181 "../GenesysParser.cpp"
    break;

  case 37:
#line 247 "bisonparser.yy"
                                                                { yylhs.value.as < obj_t > ().valor = yystack_[4].value.as < obj_t > ().valor != 0 ? yystack_[2].value.as < obj_t > ().valor : yystack_[0].value.as < obj_t > ().valor; }
#line 1187 "../GenesysParser.cpp"
    break;

  case 38:
#line 248 "bisonparser.yy"
                                                                { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor != 0 ? yystack_[0].value.as < obj_t > ().valor : 0;}
#line 1193 "../GenesysParser.cpp"
    break;

  case 39:
#line 251 "bisonparser.yy"
                                                                        {yylhs.value.as < obj_t > ().valor = 0; }
#line 1199 "../GenesysParser.cpp"
    break;

  case 40:
#line 252 "bisonparser.yy"
                                                                        {yylhs.value.as < obj_t > ().valor = 0; }
#line 1205 "../GenesysParser.cpp"
    break;

  case 41:
#line 255 "bisonparser.yy"
                                               { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1211 "../GenesysParser.cpp"
    break;

  case 42:
#line 256 "bisonparser.yy"
                                               { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1217 "../GenesysParser.cpp"
    break;

  case 43:
#line 257 "bisonparser.yy"
                                               { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1223 "../GenesysParser.cpp"
    break;

  case 44:
#line 258 "bisonparser.yy"
                                               { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1229 "../GenesysParser.cpp"
    break;

  case 45:
#line 259 "bisonparser.yy"
                                               { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1235 "../GenesysParser.cpp"
    break;

  case 46:
#line 260 "bisonparser.yy"
                                               { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1241 "../GenesysParser.cpp"
    break;

  case 47:
#line 263 "bisonparser.yy"
                          { yylhs.value.as < obj_t > ().valor = driver.getModel()->getSimulation()->getSimulatedTime();}
#line 1247 "../GenesysParser.cpp"
    break;

  case 48:
#line 264 "bisonparser.yy"
                          { yylhs.value.as < obj_t > ().valor = driver.getModel()->getSimulation()->getReplicationLength();}
#line 1253 "../GenesysParser.cpp"
    break;

  case 49:
#line 267 "bisonparser.yy"
                                               { yylhs.value.as < obj_t > ().valor = sin(yystack_[1].value.as < obj_t > ().valor); }
#line 1259 "../GenesysParser.cpp"
    break;

  case 50:
#line 268 "bisonparser.yy"
                                               { yylhs.value.as < obj_t > ().valor = cos(yystack_[1].value.as < obj_t > ().valor); }
#line 1265 "../GenesysParser.cpp"
    break;

  case 51:
#line 271 "bisonparser.yy"
                                                            { yylhs.value.as < obj_t > ().valor = round(yystack_[1].value.as < obj_t > ().valor);}
#line 1271 "../GenesysParser.cpp"
    break;

  case 52:
#line 272 "bisonparser.yy"
                                                            { yylhs.value.as < obj_t > ().valor = yystack_[1].value.as < obj_t > ().valor - (int) yystack_[1].value.as < obj_t > ().valor;}
#line 1277 "../GenesysParser.cpp"
    break;

  case 53:
#line 273 "bisonparser.yy"
                                                            { yylhs.value.as < obj_t > ().valor = trunc(yystack_[1].value.as < obj_t > ().valor);}
#line 1283 "../GenesysParser.cpp"
    break;

  case 54:
#line 274 "bisonparser.yy"
                                                            { yylhs.value.as < obj_t > ().valor = (int) yystack_[3].value.as < obj_t > ().valor % (int) yystack_[1].value.as < obj_t > ().valor; }
#line 1289 "../GenesysParser.cpp"
    break;

  case 55:
#line 277 "bisonparser.yy"
                                                            { yylhs.value.as < obj_t > ().valor = driver.sampler()->sampleUniform(0.0,1.0); yylhs.value.as < obj_t > ().tipo = "Uniforme"; }
#line 1295 "../GenesysParser.cpp"
    break;

  case 56:
#line 278 "bisonparser.yy"
                                                                        { yylhs.value.as < obj_t > ().valor = driver.sampler()->sampleExponential(yystack_[1].value.as < obj_t > ().valor); yylhs.value.as < obj_t > ().tipo = "Exponencial";}
#line 1301 "../GenesysParser.cpp"
    break;

  case 57:
#line 279 "bisonparser.yy"
                                                            { yylhs.value.as < obj_t > ().valor = driver.sampler()->sampleNormal(yystack_[3].value.as < obj_t > ().valor,yystack_[1].value.as < obj_t > ().valor); yylhs.value.as < obj_t > ().tipo = "Normal"; }
#line 1307 "../GenesysParser.cpp"
    break;

  case 58:
#line 280 "bisonparser.yy"
                                                            { yylhs.value.as < obj_t > ().valor = driver.sampler()->sampleUniform(yystack_[3].value.as < obj_t > ().valor,yystack_[1].value.as < obj_t > ().valor); yylhs.value.as < obj_t > ().tipo = "Uniforme"; }
#line 1313 "../GenesysParser.cpp"
    break;

  case 59:
#line 281 "bisonparser.yy"
                                                            { yylhs.value.as < obj_t > ().valor = driver.sampler()->sampleWeibull(yystack_[3].value.as < obj_t > ().valor,yystack_[1].value.as < obj_t > ().valor); yylhs.value.as < obj_t > ().tipo = "Weibull"; }
#line 1319 "../GenesysParser.cpp"
    break;

  case 60:
#line 282 "bisonparser.yy"
                                                            { yylhs.value.as < obj_t > ().valor = driver.sampler()->sampleLogNormal(yystack_[3].value.as < obj_t > ().valor,yystack_[1].value.as < obj_t > ().valor); yylhs.value.as < obj_t > ().tipo = "LOGNormal"; }
#line 1325 "../GenesysParser.cpp"
    break;

  case 61:
#line 283 "bisonparser.yy"
                                                            { yylhs.value.as < obj_t > ().valor = driver.sampler()->sampleGamma(yystack_[3].value.as < obj_t > ().valor,yystack_[1].value.as < obj_t > ().valor); yylhs.value.as < obj_t > ().tipo = "Gamma"; }
#line 1331 "../GenesysParser.cpp"
    break;

  case 62:
#line 284 "bisonparser.yy"
                                                            { yylhs.value.as < obj_t > ().valor = driver.sampler()->sampleErlang(yystack_[3].value.as < obj_t > ().valor,yystack_[1].value.as < obj_t > ().valor); yylhs.value.as < obj_t > ().tipo = "Erlang"; }
#line 1337 "../GenesysParser.cpp"
    break;

  case 63:
#line 285 "bisonparser.yy"
                                                                    { yylhs.value.as < obj_t > ().valor = driver.sampler()->sampleTriangular(yystack_[5].value.as < obj_t > ().valor,yystack_[3].value.as < obj_t > ().valor,yystack_[1].value.as < obj_t > ().valor); yylhs.value.as < obj_t > ().tipo = "Triangular"; }
#line 1343 "../GenesysParser.cpp"
    break;

  case 64:
#line 286 "bisonparser.yy"
                                                                                  { yylhs.value.as < obj_t > ().valor = driver.sampler()->sampleBeta(yystack_[7].value.as < obj_t > ().valor,yystack_[5].value.as < obj_t > ().valor,yystack_[3].value.as < obj_t > ().valor,yystack_[1].value.as < obj_t > ().valor); yylhs.value.as < obj_t > ().tipo = "Beta"; }
#line 1349 "../GenesysParser.cpp"
    break;

  case 65:
#line 287 "bisonparser.yy"
              { yylhs.value.as < obj_t > () = yystack_[3].value.as < obj_t > (); }
#line 1355 "../GenesysParser.cpp"
    break;

  case 66:
#line 292 "bisonparser.yy"
                                               { yylhs.value.as < obj_t > ().valor = yystack_[1].value.as < obj_t > ().valor; }
#line 1361 "../GenesysParser.cpp"
    break;

  case 67:
#line 296 "bisonparser.yy"
              { yylhs.value.as < obj_t > () = yystack_[4].value.as < obj_t > (); }
#line 1367 "../GenesysParser.cpp"
    break;

  case 68:
#line 297 "bisonparser.yy"
              { yylhs.value.as < obj_t > () = yystack_[2].value.as < obj_t > (); }
#line 1373 "../GenesysParser.cpp"
    break;

  case 69:
#line 300 "bisonparser.yy"
                                {
		      driver.setResult(-1);
		      if(driver.getThrowsException()){
			if(yystack_[0].value.as < obj_t > ().valor == 0){
			  throw std::string("Literal nao encontrado");
			}else if(yystack_[0].value.as < obj_t > ().valor == 1){
			  throw std::string("Caracter invalido encontrado");
			}
		      }else{
			if(yystack_[0].value.as < obj_t > ().valor == 0){
			  driver.setErrorMessage(std::string("Literal nao encontrado"));
			}else if(yystack_[0].value.as < obj_t > ().valor == 1){
			  driver.setErrorMessage(std::string("Caracter invalido encontrado"));
			}
		      }
		}
#line 1394 "../GenesysParser.cpp"
    break;

  case 70:
#line 320 "bisonparser.yy"
                         {  
		    double attributeValue = 0.0;
		    if (driver.getModel()->getSimulation()->getCurrentEntity() != nullptr) {
			// it could crach because there may be no current entity, if the parse is running before simulation and therefore there is no CurrentEntity
			attributeValue = driver.getModel()->getSimulation()->getCurrentEntity()->getAttributeValue(yystack_[0].value.as < obj_t > ().id);
		    }
			//std::cout << "Passei" << std::endl;
		    yylhs.value.as < obj_t > ().valor = attributeValue; 
		}
#line 1408 "../GenesysParser.cpp"
    break;

  case 71:
#line 329 "bisonparser.yy"
                                                 {  
		    double attributeValue = 0.0;
		    std::string index = std::to_string(static_cast<unsigned int>(yystack_[1].value.as < obj_t > ().valor));
		    if (driver.getModel()->getSimulation()->getCurrentEntity() != nullptr) {
			// it could crach because there may be no current entity, if the parse is running before simulation and therefore there is no CurrentEntity
			attributeValue = driver.getModel()->getSimulation()->getCurrentEntity()->getAttributeValue(index, yystack_[3].value.as < obj_t > ().id);
		    }
		    yylhs.value.as < obj_t > ().valor = attributeValue; 
		}
#line 1422 "../GenesysParser.cpp"
    break;

  case 72:
#line 338 "bisonparser.yy"
                                                               {  
		    double attributeValue = 0.0;
		    std::string index = std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[1].value.as < obj_t > ().valor));
		    if (driver.getModel()->getSimulation()->getCurrentEntity() != nullptr) {
			// it could crach because there may be no current entity, if the parse is running before simulation and therefore there is no CurrentEntity
			attributeValue = driver.getModel()->getSimulation()->getCurrentEntity()->getAttributeValue(index, yystack_[5].value.as < obj_t > ().id);
		    }
		    yylhs.value.as < obj_t > ().valor = attributeValue; 
		}
#line 1436 "../GenesysParser.cpp"
    break;

  case 73:
#line 347 "bisonparser.yy"
                                                                             {  
		    double attributeValue = 0.0;
		    std::string index = std::to_string(static_cast<unsigned int>(yystack_[5].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[1].value.as < obj_t > ().valor));
		    if (driver.getModel()->getSimulation()->getCurrentEntity() != nullptr) {
			// it could crach because there may be no current entity, if the parse is running before simulation and therefore there is no CurrentEntity
			attributeValue = driver.getModel()->getSimulation()->getCurrentEntity()->getAttributeValue(index, yystack_[7].value.as < obj_t > ().id);
		    }
		    yylhs.value.as < obj_t > ().valor = attributeValue; 
		}
#line 1450 "../GenesysParser.cpp"
    break;

  case 74:
#line 358 "bisonparser.yy"
                                                                { yylhs.value.as < obj_t > ().valor = 0; }
#line 1456 "../GenesysParser.cpp"
    break;

  case 75:
#line 373 "bisonparser.yy"
                                        { 
		    driver.getModel()->getSimulation()->getCurrentEntity()->setAttributeValue("", yystack_[2].value.as < obj_t > ().id, yystack_[0].value.as < obj_t > ().valor);
		    yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1464 "../GenesysParser.cpp"
    break;

  case 76:
#line 376 "bisonparser.yy"
                                                                    { 
		    std::string index = std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor));
		    driver.getModel()->getSimulation()->getCurrentEntity()->setAttributeValue(index, yystack_[5].value.as < obj_t > ().id, yystack_[0].value.as < obj_t > ().valor);
		    yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1473 "../GenesysParser.cpp"
    break;

  case 77:
#line 380 "bisonparser.yy"
                                                                                 {
		    std::string index = std::to_string(static_cast<unsigned int>(yystack_[5].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor)); 
		    driver.getModel()->getSimulation()->getCurrentEntity()->setAttributeValue(index, yystack_[7].value.as < obj_t > ().id, yystack_[0].value.as < obj_t > ().valor); 
		    yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1482 "../GenesysParser.cpp"
    break;

  case 78:
#line 384 "bisonparser.yy"
                                                                                                  {
		    std::string index = std::to_string(static_cast<unsigned int>(yystack_[7].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[5].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor));
		    driver.getModel()->getSimulation()->getCurrentEntity()->setAttributeValue(index, yystack_[9].value.as < obj_t > ().id, yystack_[0].value.as < obj_t > ().valor);
		    yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1491 "../GenesysParser.cpp"
    break;

  case 79:
#line 406 "bisonparser.yy"
                                                               { yylhs.value.as < obj_t > ().valor = 0; }
#line 1497 "../GenesysParser.cpp"
    break;

  case 80:
#line 421 "bisonparser.yy"
                                                               { yylhs.value.as < obj_t > ().valor = 0; }
#line 1503 "../GenesysParser.cpp"
    break;

  case 81:
#line 482 "bisonparser.yy"
                                        { yylhs.value.as < obj_t > ().valor = 0; }
#line 1509 "../GenesysParser.cpp"
    break;

  case 82:
#line 483 "bisonparser.yy"
                                        {
		    StatisticsCollector* cstat = ((StatisticsCollector*)(driver.getModel()->getElements()->getElement(Util::TypeOf<StatisticsCollector>(), yystack_[1].value.as < obj_t > ().id)));
		    double value = cstat->getStatistics()->average();
		    yylhs.value.as < obj_t > ().valor = value;
		}
#line 1519 "../GenesysParser.cpp"
    break;


#line 1523 "../GenesysParser.cpp"

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
          yyn = yypact_[+yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yy_error_token_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yy_error_token_)
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
      error_token.state = state_type (yyn);
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
  genesyspp_parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  // Generate an error message.
  std::string
  genesyspp_parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    std::ptrdiff_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */
    if (!yyla.empty ())
      {
        symbol_number_type yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];

        int yyn = yypact_[+yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yy_error_token_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const short genesyspp_parser::yypact_ninf_ = -206;

  const signed char genesyspp_parser::yytable_ninf_ = -3;

  const short
  genesyspp_parser::yypact_[] =
  {
     193,   -68,  -206,   255,  -206,  -206,  -206,  -206,  -206,  -206,
     -53,   -37,   -11,   -10,    23,    30,    31,  -206,    38,    46,
      47,    49,    50,    51,    52,    65,    66,    67,  -206,  -206,
      70,     9,   -54,  -206,    79,   317,   317,  -206,    81,  -206,
    1158,  -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,
    -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,  -206,    19,    57,    71,
     317,   317,    87,   630,    77,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   651,
     694,   715,   386,   725,   735,   758,   799,   395,   404,   426,
     470,   492,   501,   510,   519,   536,   -56,   822,   317,   317,
     317,     2,  1158,    95,  -206,   832,   -46,   -46,   -46,   -46,
      35,    35,    21,    21,    77,  1158,    77,   -46,   -46,  -206,
    -206,  -206,   317,  -206,  -206,  -206,  -206,   317,   317,   317,
     317,   317,   317,   317,   317,   317,  -206,   317,   317,    68,
      85,   839,    90,   317,  -206,  -206,   863,   903,   927,   937,
     947,   967,  1011,   585,   602,  1158,   611,   974,  -206,   317,
     317,   317,   317,   172,  -206,  -206,  -206,  -206,  -206,  -206,
    -206,   317,   317,   317,   317,   294,  1044,  1051,  1158,    91,
     317,  1076,   620,  1158,   -46,  -206,   317,   124,   124,   317,
    1059,  -206,   317,  1084,    11,  -206,  -206,  1158,    93,  1094,
    -206,   317,   317,  -206,   360,  1158,    90,   317,   376,    91,
     317,  1123,    93
  };

  const signed char
  genesyspp_parser::yydefact_[] =
  {
       0,     0,    69,     0,     5,     6,     1,    18,    19,    74,
       0,     0,     0,     0,     0,     0,     0,    55,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    47,    48,
       0,     0,    70,    81,     0,     0,     0,     3,     0,     4,
       7,     8,    12,    13,    10,    35,    36,     9,    44,    42,
      41,    43,    46,    15,    16,    11,    17,    45,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    74,    70,     0,     0,
       0,     0,     0,     0,    26,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    75,     0,    14,     0,    30,    32,    33,    34,
      27,    28,    20,    21,    23,    24,    22,    29,    31,    49,
      50,    51,     0,    53,    52,    25,    56,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    65,     0,     0,     0,
       0,     0,    71,     0,    82,    66,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    68,     0,    38,    71,     0,
       0,     0,     0,     0,    54,    57,    58,    59,    60,    61,
      62,     0,     0,     0,     0,     0,     0,     0,    76,    72,
       0,     0,     0,    67,    37,    72,     0,     0,     0,     0,
       0,    63,     0,     0,     0,    40,    39,    77,    73,     0,
      73,     0,     0,    64,     0,    78,     0,     0,     0,     0,
       0,     0,     0
  };

  const short
  genesyspp_parser::yypgoto_[] =
  {
    -206,  -206,  -206,   -35,  -206,  -206,  -206,  -206,  -206,  -206,
    -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,   133,   135,
    -205,  -206,  -206
  };

  const signed char
  genesyspp_parser::yydefgoto_[] =
  {
      -1,     3,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,   116,     4,    53,    54,
      55,    56,    57
  };

  const short
  genesyspp_parser::yytable_[] =
  {
      83,    84,   215,   216,   156,     5,    58,    80,    86,    87,
      88,    89,    90,    91,    76,   157,    81,    92,    93,    94,
      95,    96,    59,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     117,    86,    87,    88,    89,   121,   122,    77,    60,    61,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   162,    92,    93,    94,    95,    96,
      97,    98,   221,   163,    86,    87,    88,    89,    90,    91,
     118,    81,    62,   159,   160,   161,    94,    95,    96,    63,
      64,    86,    87,    88,    89,    90,    91,    65,    92,    93,
      94,    95,    96,    97,    98,    66,    67,   166,    68,    69,
      70,    71,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   180,   176,   177,    72,    73,    74,   119,   183,    75,
     178,    92,    93,    94,    95,    96,    97,    98,    82,   179,
      85,   120,   123,    95,   195,   196,   197,   198,    92,    93,
      94,    95,    96,    97,    98,   164,   201,   202,   203,   204,
     182,   209,   214,   222,    78,   210,    79,     0,     0,     0,
       0,   213,     0,     0,   217,     0,     0,   219,    86,    87,
      88,    89,    90,    91,     0,     0,   224,   225,     0,     0,
       0,     0,   228,    -2,     1,   231,    -2,    -2,    -2,     0,
       0,     0,     0,     0,     0,     0,    -2,    -2,    -2,    -2,
      -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,
      -2,    -2,    -2,    -2,    -2,    -2,    -2,     0,    -2,     0,
       0,    -2,     2,     0,   199,    92,    93,    94,    95,    96,
      97,    98,     0,   200,     0,     0,     0,     0,    -2,    -2,
       0,     0,    -2,     0,     0,     6,     0,    -2,     7,     8,
       9,     0,     0,     0,     0,     0,    -2,    -2,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,     0,
      31,     0,     0,    32,     0,     0,     0,     0,     0,     0,
      86,    87,    88,    89,    90,    91,     0,     0,     0,     0,
      33,    34,     0,     0,    35,     0,     0,     0,     0,    36,
       7,     8,     9,     0,     0,     0,     0,     0,    37,    38,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,     0,    31,     0,     0,    32,   205,    92,    93,    94,
      95,    96,    97,    98,     0,   206,    86,    87,    88,    89,
      90,    91,    33,    34,     0,     0,    35,     0,     0,     0,
       0,    36,    86,    87,    88,    89,    90,    91,     0,     0,
       0,    38,    86,    87,    88,    89,    90,    91,     0,     0,
       0,    86,    87,    88,    89,    90,    91,     0,     0,     0,
      86,    87,    88,    89,    90,    91,     0,     0,     0,     0,
       0,     0,   226,    92,    93,    94,    95,    96,    97,    98,
       0,   227,    86,    87,    88,    89,    90,    91,   229,    92,
      93,    94,    95,    96,    97,    98,     0,   230,     0,    92,
      93,    94,    95,    96,    97,    98,     0,   142,    92,    93,
      94,    95,    96,    97,    98,     0,   147,    92,    93,    94,
      95,    96,    97,    98,     0,   148,    86,    87,    88,    89,
      90,    91,     0,     0,     0,     0,     0,     0,     0,    92,
      93,    94,    95,    96,    97,    98,     0,   149,    86,    87,
      88,    89,    90,    91,     0,     0,     0,    86,    87,    88,
      89,    90,    91,     0,     0,     0,    86,    87,    88,    89,
      90,    91,     0,     0,     0,    86,    87,    88,    89,    90,
      91,     0,     0,    92,    93,    94,    95,    96,    97,    98,
       0,   150,    86,    87,    88,    89,    90,    91,     0,     0,
       0,     0,     0,     0,     0,    92,    93,    94,    95,    96,
      97,    98,     0,   151,    92,    93,    94,    95,    96,    97,
      98,     0,   152,    92,    93,    94,    95,    96,    97,    98,
       0,   153,    92,    93,    94,    95,    96,    97,    98,     0,
     154,    86,    87,    88,    89,    90,    91,     0,     0,    92,
      93,    94,    95,    96,    97,    98,     0,   155,    86,    87,
      88,    89,    90,    91,     0,     0,     0,    86,    87,    88,
      89,    90,    91,     0,     0,     0,    86,    87,    88,    89,
      90,    91,     0,     0,     0,     0,    86,    87,    88,    89,
      90,    91,     0,     0,     0,     0,     0,     0,    92,    93,
      94,    95,    96,    97,    98,     0,   191,    86,    87,    88,
      89,    90,    91,     0,     0,    92,    93,    94,    95,    96,
      97,    98,     0,   192,    92,    93,    94,    95,    96,    97,
      98,     0,   193,    92,    93,    94,    95,    96,    97,    98,
     124,   212,     0,    92,    93,    94,    95,    96,    97,    98,
      86,    87,    88,    89,    90,    91,     0,     0,     0,     0,
       0,   139,     0,     0,    92,    93,    94,    95,    96,    97,
      98,    86,    87,    88,    89,    90,    91,     0,     0,     0,
       0,    86,    87,    88,    89,    90,    91,     0,     0,     0,
       0,    86,    87,    88,    89,    90,    91,     0,     0,     0,
       0,     0,     0,     0,   140,     0,     0,    92,    93,    94,
      95,    96,    97,    98,    86,    87,    88,    89,    90,    91,
       0,     0,     0,     0,     0,   141,     0,     0,    92,    93,
      94,    95,    96,    97,    98,   143,     0,     0,    92,    93,
      94,    95,    96,    97,    98,   144,     0,     0,    92,    93,
      94,    95,    96,    97,    98,    86,    87,    88,    89,    90,
      91,     0,     0,     0,     0,     0,     0,     0,   145,     0,
       0,    92,    93,    94,    95,    96,    97,    98,    86,    87,
      88,    89,    90,    91,     0,     0,     0,     0,    86,    87,
      88,    89,    90,    91,     0,    86,    87,    88,    89,    90,
      91,     0,     0,     0,     0,     0,     0,     0,     0,   146,
       0,     0,    92,    93,    94,    95,    96,    97,    98,    86,
      87,    88,    89,    90,    91,   181,     0,     0,     0,     0,
       0,     0,   158,     0,     0,    92,    93,    94,    95,    96,
      97,    98,   165,     0,     0,    92,    93,    94,    95,    96,
      97,    98,    92,    93,    94,    95,    96,    97,    98,    86,
      87,    88,    89,    90,    91,     0,     0,     0,     0,     0,
       0,     0,     0,   184,     0,     0,    92,    93,    94,    95,
      96,    97,    98,    86,    87,    88,    89,    90,    91,     0,
       0,     0,     0,    86,    87,    88,    89,    90,    91,     0,
       0,     0,     0,    86,    87,    88,    89,    90,    91,     0,
       0,     0,     0,   185,     0,     0,    92,    93,    94,    95,
      96,    97,    98,    86,    87,    88,    89,    90,    91,     0,
      86,    87,    88,    89,    90,    91,     0,   186,     0,     0,
      92,    93,    94,    95,    96,    97,    98,   187,     0,     0,
      92,    93,    94,    95,    96,    97,    98,   188,   194,     0,
      92,    93,    94,    95,    96,    97,    98,    86,    87,    88,
      89,    90,    91,     0,     0,     0,     0,   189,     0,     0,
      92,    93,    94,    95,    96,    97,    98,    92,    93,    94,
      95,    96,    97,    98,     0,     0,     0,     0,     0,     0,
      86,    87,    88,    89,    90,    91,     0,    86,    87,    88,
      89,    90,    91,     0,     0,    86,    87,    88,    89,    90,
      91,   190,     0,     0,    92,    93,    94,    95,    96,    97,
      98,   207,    86,    87,    88,    89,    90,    91,   208,     0,
      86,    87,    88,    89,    90,    91,     0,     0,     0,     0,
      86,    87,    88,    89,    90,    91,     0,    92,    93,    94,
      95,    96,    97,    98,    92,    93,    94,    95,    96,    97,
      98,   218,    92,    93,    94,    95,    96,    97,    98,    86,
      87,    88,    89,    90,    91,     0,   211,     0,     0,    92,
      93,    94,    95,    96,    97,    98,   220,    92,    93,    94,
      95,    96,    97,    98,   223,     0,     0,    92,    93,    94,
      95,    96,    97,    98,    86,    87,    88,    89,    90,    91,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   232,    92,    93,    94,    95,
      96,    97,    98,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    92,    93,    94,    95,    96,    97,    98
  };

  const short
  genesyspp_parser::yycheck_[] =
  {
      35,    36,   207,   208,    60,    73,    59,    61,     6,     7,
       8,     9,    10,    11,     5,    71,    70,    63,    64,    65,
      66,    67,    59,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,     6,     7,     8,     9,    80,    81,    38,    59,    59,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    62,    63,    64,    65,    66,    67,
      68,    69,    61,    71,     6,     7,     8,     9,    10,    11,
      61,    70,    59,   118,   119,   120,    65,    66,    67,    59,
      59,     6,     7,     8,     9,    10,    11,    59,    63,    64,
      65,    66,    67,    68,    69,    59,    59,   142,    59,    59,
      59,    59,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    36,   157,   158,    59,    59,    59,    70,   163,    59,
      62,    63,    64,    65,    66,    67,    68,    69,    59,    71,
      59,    70,    55,    66,   179,   180,   181,   182,    63,    64,
      65,    66,    67,    68,    69,    60,   191,   192,   193,   194,
      70,    70,    38,    70,    31,   200,    31,    -1,    -1,    -1,
      -1,   206,    -1,    -1,   209,    -1,    -1,   212,     6,     7,
       8,     9,    10,    11,    -1,    -1,   221,   222,    -1,    -1,
      -1,    -1,   227,     0,     1,   230,     3,     4,     5,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    35,    -1,
      -1,    38,    39,    -1,    62,    63,    64,    65,    66,    67,
      68,    69,    -1,    71,    -1,    -1,    -1,    -1,    55,    56,
      -1,    -1,    59,    -1,    -1,     0,    -1,    64,     3,     4,
       5,    -1,    -1,    -1,    -1,    -1,    73,    74,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    -1,
      35,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
      55,    56,    -1,    -1,    59,    -1,    -1,    -1,    -1,    64,
       3,     4,     5,    -1,    -1,    -1,    -1,    -1,    73,    74,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    35,    -1,    -1,    38,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,     6,     7,     8,     9,
      10,    11,    55,    56,    -1,    -1,    59,    -1,    -1,    -1,
      -1,    64,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    74,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    62,    63,    64,    65,    66,    67,    68,    69,
      -1,    71,     6,     7,     8,     9,    10,    11,    62,    63,
      64,    65,    66,    67,    68,    69,    -1,    71,    -1,    63,
      64,    65,    66,    67,    68,    69,    -1,    71,    63,    64,
      65,    66,    67,    68,    69,    -1,    71,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    65,    66,    67,    68,    69,    -1,    71,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,     6,     7,     8,     9,    10,
      11,    -1,    -1,    63,    64,    65,    66,    67,    68,    69,
      -1,    71,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,
      68,    69,    -1,    71,    63,    64,    65,    66,    67,    68,
      69,    -1,    71,    63,    64,    65,    66,    67,    68,    69,
      -1,    71,    63,    64,    65,    66,    67,    68,    69,    -1,
      71,     6,     7,     8,     9,    10,    11,    -1,    -1,    63,
      64,    65,    66,    67,    68,    69,    -1,    71,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      65,    66,    67,    68,    69,    -1,    71,     6,     7,     8,
       9,    10,    11,    -1,    -1,    63,    64,    65,    66,    67,
      68,    69,    -1,    71,    63,    64,    65,    66,    67,    68,
      69,    -1,    71,    63,    64,    65,    66,    67,    68,    69,
      60,    71,    -1,    63,    64,    65,    66,    67,    68,    69,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    60,    -1,    -1,    63,    64,    65,    66,    67,    68,
      69,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    60,    -1,    -1,    63,    64,    65,
      66,    67,    68,    69,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,    63,    64,
      65,    66,    67,    68,    69,    60,    -1,    -1,    63,    64,
      65,    66,    67,    68,    69,    60,    -1,    -1,    63,    64,
      65,    66,    67,    68,    69,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,
      -1,    63,    64,    65,    66,    67,    68,    69,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,     6,     7,
       8,     9,    10,    11,    -1,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      -1,    -1,    63,    64,    65,    66,    67,    68,    69,     6,
       7,     8,     9,    10,    11,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    60,    -1,    -1,    63,    64,    65,    66,    67,
      68,    69,    60,    -1,    -1,    63,    64,    65,    66,    67,
      68,    69,    63,    64,    65,    66,    67,    68,    69,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    -1,    -1,    63,    64,    65,    66,
      67,    68,    69,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,    60,    -1,    -1,    63,    64,    65,    66,
      67,    68,    69,     6,     7,     8,     9,    10,    11,    -1,
       6,     7,     8,     9,    10,    11,    -1,    60,    -1,    -1,
      63,    64,    65,    66,    67,    68,    69,    60,    -1,    -1,
      63,    64,    65,    66,    67,    68,    69,    60,    34,    -1,
      63,    64,    65,    66,    67,    68,    69,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    60,    -1,    -1,
      63,    64,    65,    66,    67,    68,    69,    63,    64,    65,
      66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,
       6,     7,     8,     9,    10,    11,    -1,     6,     7,     8,
       9,    10,    11,    -1,    -1,     6,     7,     8,     9,    10,
      11,    60,    -1,    -1,    63,    64,    65,    66,    67,    68,
      69,    37,     6,     7,     8,     9,    10,    11,    37,    -1,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
       6,     7,     8,     9,    10,    11,    -1,    63,    64,    65,
      66,    67,    68,    69,    63,    64,    65,    66,    67,    68,
      69,    62,    63,    64,    65,    66,    67,    68,    69,     6,
       7,     8,     9,    10,    11,    -1,    60,    -1,    -1,    63,
      64,    65,    66,    67,    68,    69,    62,    63,    64,    65,
      66,    67,    68,    69,    60,    -1,    -1,    63,    64,    65,
      66,    67,    68,    69,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    63,    64,    65,    66,
      67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    65,    66,    67,    68,    69
  };

  const signed char
  genesyspp_parser::yystos_[] =
  {
       0,     1,    39,    76,    92,    73,     0,     3,     4,     5,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    35,    38,    55,    56,    59,    64,    73,    74,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    93,    94,    95,    96,    97,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,     5,    38,    93,    94,
      61,    70,    59,    78,    78,    59,     6,     7,     8,     9,
      10,    11,    63,    64,    65,    66,    67,    68,    69,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    91,    78,    61,    70,
      70,    78,    78,    55,    60,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    60,
      60,    60,    71,    60,    60,    60,    60,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    60,    71,    60,    78,
      78,    78,    62,    71,    60,    60,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    62,    71,
      36,    36,    70,    78,    60,    60,    60,    60,    60,    60,
      60,    71,    71,    71,    34,    78,    78,    78,    78,    62,
      71,    78,    78,    78,    78,    62,    71,    37,    37,    70,
      78,    60,    71,    78,    38,    95,    95,    78,    62,    78,
      62,    61,    70,    60,    78,    78,    62,    71,    78,    62,
      71,    78,    62
  };

  const signed char
  genesyspp_parser::yyr1_[] =
  {
       0,    75,    76,    76,    76,    76,    76,    77,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    79,    79,
      80,    80,    80,    80,    80,    80,    80,    81,    81,    81,
      81,    81,    81,    81,    81,    82,    82,    83,    83,    84,
      84,    85,    85,    85,    85,    85,    85,    86,    86,    87,
      87,    88,    88,    88,    88,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    90,    91,    91,    92,
      93,    93,    93,    93,    94,    95,    95,    95,    95,    96,
      97,    97,    97
  };

  const signed char
  genesyspp_parser::yyr2_[] =
  {
       0,     2,     0,     2,     2,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     4,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     1,     7,     5,     8,
       8,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     4,     4,     6,     1,     4,     6,     6,     6,
       6,     6,     6,     8,    10,     4,     4,     5,     3,     1,
       1,     4,     6,     8,     1,     3,     6,     8,    10,     1,
       1,     1,     4
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const genesyspp_parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "NUMD", "NUMH", "CTEZERO",
  "oLE", "oGE", "oEQ", "oNE", "oAND", "oOR", "oNOT", "fSIN", "fCOS",
  "fROUND", "fMOD", "fTRUNC", "fFRAC", "fEXP", "fRND1", "fEXPO", "fNORM",
  "fUNIF", "fWEIB", "fLOGN", "fGAMM", "fERLA", "fTRIA", "fBETA", "fDISC",
  "fTNOW", "fTFIN", "cIF", "cELSE", "cFOR", "cTO", "cDO", "ATRIB",
  "ILLEGAL", "RESOURCE", "fNR", "fMR", "fIRF", "fRESSEIZES", "fSTATE",
  "fSETSUM", "QUEUE", "fNQ", "fFIRSTINQ", "fLASTINQ", "fSAQUE", "fAQUE",
  "SET", "fNUMSET", "CSTAT", "fTAVG", "VARI", "FORM", "\"(\"", "\")\"",
  "\"[\"", "\"]\"", "\"+\"", "\"-\"", "\"*\"", "\"^\"", "\"/\"", "\"<\"",
  "\">\"", "\"=\"", "\",\"", "NEG", "'\\n'", "\"USER\"", "$accept",
  "input", "programa", "expressao", "numero", "aritmetica", "relacional",
  "comando", "comandoIF", "comandoFOR", "funcao", "funcaoKernel",
  "funcaoTrig", "funcaoArit", "funcaoProb", "funcaoUser", "listaparm",
  "illegal", "atributo", "variavel", "atribuicao", "formula",
  "funcaoPlugin", YY_NULLPTR
  };

#if YYDEBUG
  const short
  genesyspp_parser::yyrline_[] =
  {
       0,   196,   196,   197,   198,   199,   200,   203,   206,   207,
     208,   209,   210,   211,   212,   213,   215,   217,   220,   221,
     224,   225,   226,   227,   228,   229,   230,   233,   234,   235,
     236,   237,   238,   239,   240,   243,   244,   247,   248,   251,
     252,   255,   256,   257,   258,   259,   260,   263,   264,   267,
     268,   271,   272,   273,   274,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   292,   296,   297,   300,
     320,   329,   338,   347,   358,   373,   376,   380,   384,   406,
     421,   482,   483
  };

  // Print the state stack on the debug stream.
  void
  genesyspp_parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  genesyspp_parser::yy_reduce_print_ (int yyrule)
  {
    int yylno = yyrline_[yyrule];
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


} // yy
#line 2255 "../GenesysParser.cpp"

#line 497 "bisonparser.yy"

void
yy::genesyspp_parser::error (const location_type& l,
                          const std::string& m)
{
  driver.error (l, m);
}
