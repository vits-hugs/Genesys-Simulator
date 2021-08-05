// A Bison parser, made by GNU Bison 3.7.5.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

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

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "GenesysParser.h"


// Unqualified %code blocks.
#line 50 "bisonparser.yy"

# include "Genesys++-driver.h"


#line 51 "../GenesysParser.cpp"


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
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
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
#line 143 "../GenesysParser.cpp"

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
  | symbol kinds.  |
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

  genesyspp_parser::symbol_kind_type
  genesyspp_parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  genesyspp_parser::stack_symbol_type::stack_symbol_type ()
  {}

  genesyspp_parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_NUMD: // NUMD
      case symbol_kind::S_NUMH: // NUMH
      case symbol_kind::S_CTEZERO: // CTEZERO
      case symbol_kind::S_oLE: // oLE
      case symbol_kind::S_oGE: // oGE
      case symbol_kind::S_oEQ: // oEQ
      case symbol_kind::S_oNE: // oNE
      case symbol_kind::S_oAND: // oAND
      case symbol_kind::S_oOR: // oOR
      case symbol_kind::S_oNOT: // oNOT
      case symbol_kind::S_fSIN: // fSIN
      case symbol_kind::S_fCOS: // fCOS
      case symbol_kind::S_fROUND: // fROUND
      case symbol_kind::S_fMOD: // fMOD
      case symbol_kind::S_fTRUNC: // fTRUNC
      case symbol_kind::S_fFRAC: // fFRAC
      case symbol_kind::S_fEXP: // fEXP
      case symbol_kind::S_fRND1: // fRND1
      case symbol_kind::S_fEXPO: // fEXPO
      case symbol_kind::S_fNORM: // fNORM
      case symbol_kind::S_fUNIF: // fUNIF
      case symbol_kind::S_fWEIB: // fWEIB
      case symbol_kind::S_fLOGN: // fLOGN
      case symbol_kind::S_fGAMM: // fGAMM
      case symbol_kind::S_fERLA: // fERLA
      case symbol_kind::S_fTRIA: // fTRIA
      case symbol_kind::S_fBETA: // fBETA
      case symbol_kind::S_fDISC: // fDISC
      case symbol_kind::S_fTNOW: // fTNOW
      case symbol_kind::S_fTFIN: // fTFIN
      case symbol_kind::S_cIF: // cIF
      case symbol_kind::S_cELSE: // cELSE
      case symbol_kind::S_cFOR: // cFOR
      case symbol_kind::S_cTO: // cTO
      case symbol_kind::S_cDO: // cDO
      case symbol_kind::S_ATRIB: // ATRIB
      case symbol_kind::S_CSTAT: // CSTAT
      case symbol_kind::S_fTAVG: // fTAVG
      case symbol_kind::S_ILLEGAL: // ILLEGAL
      case symbol_kind::S_RESOURCE: // RESOURCE
      case symbol_kind::S_fNR: // fNR
      case symbol_kind::S_fMR: // fMR
      case symbol_kind::S_fIRF: // fIRF
      case symbol_kind::S_fRESSEIZES: // fRESSEIZES
      case symbol_kind::S_fSTATE: // fSTATE
      case symbol_kind::S_fSETSUM: // fSETSUM
      case symbol_kind::S_QUEUE: // QUEUE
      case symbol_kind::S_fNQ: // fNQ
      case symbol_kind::S_fFIRSTINQ: // fFIRSTINQ
      case symbol_kind::S_fLASTINQ: // fLASTINQ
      case symbol_kind::S_fSAQUE: // fSAQUE
      case symbol_kind::S_fAQUE: // fAQUE
      case symbol_kind::S_SET: // SET
      case symbol_kind::S_fNUMSET: // fNUMSET
      case symbol_kind::S_VARI: // VARI
      case symbol_kind::S_FORM: // FORM
      case symbol_kind::S_input: // input
      case symbol_kind::S_programa: // programa
      case symbol_kind::S_expressao: // expressao
      case symbol_kind::S_numero: // numero
      case symbol_kind::S_aritmetica: // aritmetica
      case symbol_kind::S_relacional: // relacional
      case symbol_kind::S_comando: // comando
      case symbol_kind::S_comandoIF: // comandoIF
      case symbol_kind::S_comandoFOR: // comandoFOR
      case symbol_kind::S_funcao: // funcao
      case symbol_kind::S_funcaoKernel: // funcaoKernel
      case symbol_kind::S_funcaoTrig: // funcaoTrig
      case symbol_kind::S_funcaoArit: // funcaoArit
      case symbol_kind::S_funcaoProb: // funcaoProb
      case symbol_kind::S_funcaoUser: // funcaoUser
      case symbol_kind::S_listaparm: // listaparm
      case symbol_kind::S_illegal: // illegal
      case symbol_kind::S_atributo: // atributo
      case symbol_kind::S_variavel: // variavel
      case symbol_kind::S_formula: // formula
      case symbol_kind::S_atribuicao: // atribuicao
      case symbol_kind::S_funcaoPlugin: // funcaoPlugin
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
    switch (that.kind ())
    {
      case symbol_kind::S_NUMD: // NUMD
      case symbol_kind::S_NUMH: // NUMH
      case symbol_kind::S_CTEZERO: // CTEZERO
      case symbol_kind::S_oLE: // oLE
      case symbol_kind::S_oGE: // oGE
      case symbol_kind::S_oEQ: // oEQ
      case symbol_kind::S_oNE: // oNE
      case symbol_kind::S_oAND: // oAND
      case symbol_kind::S_oOR: // oOR
      case symbol_kind::S_oNOT: // oNOT
      case symbol_kind::S_fSIN: // fSIN
      case symbol_kind::S_fCOS: // fCOS
      case symbol_kind::S_fROUND: // fROUND
      case symbol_kind::S_fMOD: // fMOD
      case symbol_kind::S_fTRUNC: // fTRUNC
      case symbol_kind::S_fFRAC: // fFRAC
      case symbol_kind::S_fEXP: // fEXP
      case symbol_kind::S_fRND1: // fRND1
      case symbol_kind::S_fEXPO: // fEXPO
      case symbol_kind::S_fNORM: // fNORM
      case symbol_kind::S_fUNIF: // fUNIF
      case symbol_kind::S_fWEIB: // fWEIB
      case symbol_kind::S_fLOGN: // fLOGN
      case symbol_kind::S_fGAMM: // fGAMM
      case symbol_kind::S_fERLA: // fERLA
      case symbol_kind::S_fTRIA: // fTRIA
      case symbol_kind::S_fBETA: // fBETA
      case symbol_kind::S_fDISC: // fDISC
      case symbol_kind::S_fTNOW: // fTNOW
      case symbol_kind::S_fTFIN: // fTFIN
      case symbol_kind::S_cIF: // cIF
      case symbol_kind::S_cELSE: // cELSE
      case symbol_kind::S_cFOR: // cFOR
      case symbol_kind::S_cTO: // cTO
      case symbol_kind::S_cDO: // cDO
      case symbol_kind::S_ATRIB: // ATRIB
      case symbol_kind::S_CSTAT: // CSTAT
      case symbol_kind::S_fTAVG: // fTAVG
      case symbol_kind::S_ILLEGAL: // ILLEGAL
      case symbol_kind::S_RESOURCE: // RESOURCE
      case symbol_kind::S_fNR: // fNR
      case symbol_kind::S_fMR: // fMR
      case symbol_kind::S_fIRF: // fIRF
      case symbol_kind::S_fRESSEIZES: // fRESSEIZES
      case symbol_kind::S_fSTATE: // fSTATE
      case symbol_kind::S_fSETSUM: // fSETSUM
      case symbol_kind::S_QUEUE: // QUEUE
      case symbol_kind::S_fNQ: // fNQ
      case symbol_kind::S_fFIRSTINQ: // fFIRSTINQ
      case symbol_kind::S_fLASTINQ: // fLASTINQ
      case symbol_kind::S_fSAQUE: // fSAQUE
      case symbol_kind::S_fAQUE: // fAQUE
      case symbol_kind::S_SET: // SET
      case symbol_kind::S_fNUMSET: // fNUMSET
      case symbol_kind::S_VARI: // VARI
      case symbol_kind::S_FORM: // FORM
      case symbol_kind::S_input: // input
      case symbol_kind::S_programa: // programa
      case symbol_kind::S_expressao: // expressao
      case symbol_kind::S_numero: // numero
      case symbol_kind::S_aritmetica: // aritmetica
      case symbol_kind::S_relacional: // relacional
      case symbol_kind::S_comando: // comando
      case symbol_kind::S_comandoIF: // comandoIF
      case symbol_kind::S_comandoFOR: // comandoFOR
      case symbol_kind::S_funcao: // funcao
      case symbol_kind::S_funcaoKernel: // funcaoKernel
      case symbol_kind::S_funcaoTrig: // funcaoTrig
      case symbol_kind::S_funcaoArit: // funcaoArit
      case symbol_kind::S_funcaoProb: // funcaoProb
      case symbol_kind::S_funcaoUser: // funcaoUser
      case symbol_kind::S_listaparm: // listaparm
      case symbol_kind::S_illegal: // illegal
      case symbol_kind::S_atributo: // atributo
      case symbol_kind::S_variavel: // variavel
      case symbol_kind::S_formula: // formula
      case symbol_kind::S_atribuicao: // atribuicao
      case symbol_kind::S_funcaoPlugin: // funcaoPlugin
        value.move< obj_t > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  genesyspp_parser::stack_symbol_type&
  genesyspp_parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_NUMD: // NUMD
      case symbol_kind::S_NUMH: // NUMH
      case symbol_kind::S_CTEZERO: // CTEZERO
      case symbol_kind::S_oLE: // oLE
      case symbol_kind::S_oGE: // oGE
      case symbol_kind::S_oEQ: // oEQ
      case symbol_kind::S_oNE: // oNE
      case symbol_kind::S_oAND: // oAND
      case symbol_kind::S_oOR: // oOR
      case symbol_kind::S_oNOT: // oNOT
      case symbol_kind::S_fSIN: // fSIN
      case symbol_kind::S_fCOS: // fCOS
      case symbol_kind::S_fROUND: // fROUND
      case symbol_kind::S_fMOD: // fMOD
      case symbol_kind::S_fTRUNC: // fTRUNC
      case symbol_kind::S_fFRAC: // fFRAC
      case symbol_kind::S_fEXP: // fEXP
      case symbol_kind::S_fRND1: // fRND1
      case symbol_kind::S_fEXPO: // fEXPO
      case symbol_kind::S_fNORM: // fNORM
      case symbol_kind::S_fUNIF: // fUNIF
      case symbol_kind::S_fWEIB: // fWEIB
      case symbol_kind::S_fLOGN: // fLOGN
      case symbol_kind::S_fGAMM: // fGAMM
      case symbol_kind::S_fERLA: // fERLA
      case symbol_kind::S_fTRIA: // fTRIA
      case symbol_kind::S_fBETA: // fBETA
      case symbol_kind::S_fDISC: // fDISC
      case symbol_kind::S_fTNOW: // fTNOW
      case symbol_kind::S_fTFIN: // fTFIN
      case symbol_kind::S_cIF: // cIF
      case symbol_kind::S_cELSE: // cELSE
      case symbol_kind::S_cFOR: // cFOR
      case symbol_kind::S_cTO: // cTO
      case symbol_kind::S_cDO: // cDO
      case symbol_kind::S_ATRIB: // ATRIB
      case symbol_kind::S_CSTAT: // CSTAT
      case symbol_kind::S_fTAVG: // fTAVG
      case symbol_kind::S_ILLEGAL: // ILLEGAL
      case symbol_kind::S_RESOURCE: // RESOURCE
      case symbol_kind::S_fNR: // fNR
      case symbol_kind::S_fMR: // fMR
      case symbol_kind::S_fIRF: // fIRF
      case symbol_kind::S_fRESSEIZES: // fRESSEIZES
      case symbol_kind::S_fSTATE: // fSTATE
      case symbol_kind::S_fSETSUM: // fSETSUM
      case symbol_kind::S_QUEUE: // QUEUE
      case symbol_kind::S_fNQ: // fNQ
      case symbol_kind::S_fFIRSTINQ: // fFIRSTINQ
      case symbol_kind::S_fLASTINQ: // fLASTINQ
      case symbol_kind::S_fSAQUE: // fSAQUE
      case symbol_kind::S_fAQUE: // fAQUE
      case symbol_kind::S_SET: // SET
      case symbol_kind::S_fNUMSET: // fNUMSET
      case symbol_kind::S_VARI: // VARI
      case symbol_kind::S_FORM: // FORM
      case symbol_kind::S_input: // input
      case symbol_kind::S_programa: // programa
      case symbol_kind::S_expressao: // expressao
      case symbol_kind::S_numero: // numero
      case symbol_kind::S_aritmetica: // aritmetica
      case symbol_kind::S_relacional: // relacional
      case symbol_kind::S_comando: // comando
      case symbol_kind::S_comandoIF: // comandoIF
      case symbol_kind::S_comandoFOR: // comandoFOR
      case symbol_kind::S_funcao: // funcao
      case symbol_kind::S_funcaoKernel: // funcaoKernel
      case symbol_kind::S_funcaoTrig: // funcaoTrig
      case symbol_kind::S_funcaoArit: // funcaoArit
      case symbol_kind::S_funcaoProb: // funcaoProb
      case symbol_kind::S_funcaoUser: // funcaoUser
      case symbol_kind::S_listaparm: // listaparm
      case symbol_kind::S_illegal: // illegal
      case symbol_kind::S_atributo: // atributo
      case symbol_kind::S_variavel: // variavel
      case symbol_kind::S_formula: // formula
      case symbol_kind::S_atribuicao: // atribuicao
      case symbol_kind::S_funcaoPlugin: // funcaoPlugin
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
    switch (that.kind ())
    {
      case symbol_kind::S_NUMD: // NUMD
      case symbol_kind::S_NUMH: // NUMH
      case symbol_kind::S_CTEZERO: // CTEZERO
      case symbol_kind::S_oLE: // oLE
      case symbol_kind::S_oGE: // oGE
      case symbol_kind::S_oEQ: // oEQ
      case symbol_kind::S_oNE: // oNE
      case symbol_kind::S_oAND: // oAND
      case symbol_kind::S_oOR: // oOR
      case symbol_kind::S_oNOT: // oNOT
      case symbol_kind::S_fSIN: // fSIN
      case symbol_kind::S_fCOS: // fCOS
      case symbol_kind::S_fROUND: // fROUND
      case symbol_kind::S_fMOD: // fMOD
      case symbol_kind::S_fTRUNC: // fTRUNC
      case symbol_kind::S_fFRAC: // fFRAC
      case symbol_kind::S_fEXP: // fEXP
      case symbol_kind::S_fRND1: // fRND1
      case symbol_kind::S_fEXPO: // fEXPO
      case symbol_kind::S_fNORM: // fNORM
      case symbol_kind::S_fUNIF: // fUNIF
      case symbol_kind::S_fWEIB: // fWEIB
      case symbol_kind::S_fLOGN: // fLOGN
      case symbol_kind::S_fGAMM: // fGAMM
      case symbol_kind::S_fERLA: // fERLA
      case symbol_kind::S_fTRIA: // fTRIA
      case symbol_kind::S_fBETA: // fBETA
      case symbol_kind::S_fDISC: // fDISC
      case symbol_kind::S_fTNOW: // fTNOW
      case symbol_kind::S_fTFIN: // fTFIN
      case symbol_kind::S_cIF: // cIF
      case symbol_kind::S_cELSE: // cELSE
      case symbol_kind::S_cFOR: // cFOR
      case symbol_kind::S_cTO: // cTO
      case symbol_kind::S_cDO: // cDO
      case symbol_kind::S_ATRIB: // ATRIB
      case symbol_kind::S_CSTAT: // CSTAT
      case symbol_kind::S_fTAVG: // fTAVG
      case symbol_kind::S_ILLEGAL: // ILLEGAL
      case symbol_kind::S_RESOURCE: // RESOURCE
      case symbol_kind::S_fNR: // fNR
      case symbol_kind::S_fMR: // fMR
      case symbol_kind::S_fIRF: // fIRF
      case symbol_kind::S_fRESSEIZES: // fRESSEIZES
      case symbol_kind::S_fSTATE: // fSTATE
      case symbol_kind::S_fSETSUM: // fSETSUM
      case symbol_kind::S_QUEUE: // QUEUE
      case symbol_kind::S_fNQ: // fNQ
      case symbol_kind::S_fFIRSTINQ: // fFIRSTINQ
      case symbol_kind::S_fLASTINQ: // fLASTINQ
      case symbol_kind::S_fSAQUE: // fSAQUE
      case symbol_kind::S_fAQUE: // fAQUE
      case symbol_kind::S_SET: // SET
      case symbol_kind::S_fNUMSET: // fNUMSET
      case symbol_kind::S_VARI: // VARI
      case symbol_kind::S_FORM: // FORM
      case symbol_kind::S_input: // input
      case symbol_kind::S_programa: // programa
      case symbol_kind::S_expressao: // expressao
      case symbol_kind::S_numero: // numero
      case symbol_kind::S_aritmetica: // aritmetica
      case symbol_kind::S_relacional: // relacional
      case symbol_kind::S_comando: // comando
      case symbol_kind::S_comandoIF: // comandoIF
      case symbol_kind::S_comandoFOR: // comandoFOR
      case symbol_kind::S_funcao: // funcao
      case symbol_kind::S_funcaoKernel: // funcaoKernel
      case symbol_kind::S_funcaoTrig: // funcaoTrig
      case symbol_kind::S_funcaoArit: // funcaoArit
      case symbol_kind::S_funcaoProb: // funcaoProb
      case symbol_kind::S_funcaoUser: // funcaoUser
      case symbol_kind::S_listaparm: // listaparm
      case symbol_kind::S_illegal: // illegal
      case symbol_kind::S_atributo: // atributo
      case symbol_kind::S_variavel: // variavel
      case symbol_kind::S_formula: // formula
      case symbol_kind::S_atribuicao: // atribuicao
      case symbol_kind::S_funcaoPlugin: // funcaoPlugin
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
  genesyspp_parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
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
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
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
#line 43 "bisonparser.yy"
{
  // Initialize the initial location.
  //@$.begin.filename = @$.end.filename = &driver.getFile();
}

#line 733 "../GenesysParser.cpp"


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
    YY_STACK_PRINT ();

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
        YYCDEBUG << "Reading a token\n";
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

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
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
      case symbol_kind::S_NUMD: // NUMD
      case symbol_kind::S_NUMH: // NUMH
      case symbol_kind::S_CTEZERO: // CTEZERO
      case symbol_kind::S_oLE: // oLE
      case symbol_kind::S_oGE: // oGE
      case symbol_kind::S_oEQ: // oEQ
      case symbol_kind::S_oNE: // oNE
      case symbol_kind::S_oAND: // oAND
      case symbol_kind::S_oOR: // oOR
      case symbol_kind::S_oNOT: // oNOT
      case symbol_kind::S_fSIN: // fSIN
      case symbol_kind::S_fCOS: // fCOS
      case symbol_kind::S_fROUND: // fROUND
      case symbol_kind::S_fMOD: // fMOD
      case symbol_kind::S_fTRUNC: // fTRUNC
      case symbol_kind::S_fFRAC: // fFRAC
      case symbol_kind::S_fEXP: // fEXP
      case symbol_kind::S_fRND1: // fRND1
      case symbol_kind::S_fEXPO: // fEXPO
      case symbol_kind::S_fNORM: // fNORM
      case symbol_kind::S_fUNIF: // fUNIF
      case symbol_kind::S_fWEIB: // fWEIB
      case symbol_kind::S_fLOGN: // fLOGN
      case symbol_kind::S_fGAMM: // fGAMM
      case symbol_kind::S_fERLA: // fERLA
      case symbol_kind::S_fTRIA: // fTRIA
      case symbol_kind::S_fBETA: // fBETA
      case symbol_kind::S_fDISC: // fDISC
      case symbol_kind::S_fTNOW: // fTNOW
      case symbol_kind::S_fTFIN: // fTFIN
      case symbol_kind::S_cIF: // cIF
      case symbol_kind::S_cELSE: // cELSE
      case symbol_kind::S_cFOR: // cFOR
      case symbol_kind::S_cTO: // cTO
      case symbol_kind::S_cDO: // cDO
      case symbol_kind::S_ATRIB: // ATRIB
      case symbol_kind::S_CSTAT: // CSTAT
      case symbol_kind::S_fTAVG: // fTAVG
      case symbol_kind::S_ILLEGAL: // ILLEGAL
      case symbol_kind::S_RESOURCE: // RESOURCE
      case symbol_kind::S_fNR: // fNR
      case symbol_kind::S_fMR: // fMR
      case symbol_kind::S_fIRF: // fIRF
      case symbol_kind::S_fRESSEIZES: // fRESSEIZES
      case symbol_kind::S_fSTATE: // fSTATE
      case symbol_kind::S_fSETSUM: // fSETSUM
      case symbol_kind::S_QUEUE: // QUEUE
      case symbol_kind::S_fNQ: // fNQ
      case symbol_kind::S_fFIRSTINQ: // fFIRSTINQ
      case symbol_kind::S_fLASTINQ: // fLASTINQ
      case symbol_kind::S_fSAQUE: // fSAQUE
      case symbol_kind::S_fAQUE: // fAQUE
      case symbol_kind::S_SET: // SET
      case symbol_kind::S_fNUMSET: // fNUMSET
      case symbol_kind::S_VARI: // VARI
      case symbol_kind::S_FORM: // FORM
      case symbol_kind::S_input: // input
      case symbol_kind::S_programa: // programa
      case symbol_kind::S_expressao: // expressao
      case symbol_kind::S_numero: // numero
      case symbol_kind::S_aritmetica: // aritmetica
      case symbol_kind::S_relacional: // relacional
      case symbol_kind::S_comando: // comando
      case symbol_kind::S_comandoIF: // comandoIF
      case symbol_kind::S_comandoFOR: // comandoFOR
      case symbol_kind::S_funcao: // funcao
      case symbol_kind::S_funcaoKernel: // funcaoKernel
      case symbol_kind::S_funcaoTrig: // funcaoTrig
      case symbol_kind::S_funcaoArit: // funcaoArit
      case symbol_kind::S_funcaoProb: // funcaoProb
      case symbol_kind::S_funcaoUser: // funcaoUser
      case symbol_kind::S_listaparm: // listaparm
      case symbol_kind::S_illegal: // illegal
      case symbol_kind::S_atributo: // atributo
      case symbol_kind::S_variavel: // variavel
      case symbol_kind::S_formula: // formula
      case symbol_kind::S_atribuicao: // atribuicao
      case symbol_kind::S_funcaoPlugin: // funcaoPlugin
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
  case 3: // input: input '\n'
#line 197 "bisonparser.yy"
                         {YYACCEPT;}
#line 952 "../GenesysParser.cpp"
    break;

  case 4: // input: input programa
#line 198 "bisonparser.yy"
                                                { driver.setResult(yystack_[0].value.as < obj_t > ().valor);}
#line 958 "../GenesysParser.cpp"
    break;

  case 5: // input: illegal
#line 199 "bisonparser.yy"
              { yylhs.value.as < obj_t > () = yystack_[0].value.as < obj_t > (); }
#line 964 "../GenesysParser.cpp"
    break;

  case 6: // input: error '\n'
#line 200 "bisonparser.yy"
                                                { yyerrok; }
#line 970 "../GenesysParser.cpp"
    break;

  case 7: // programa: expressao
#line 203 "bisonparser.yy"
                                                { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 976 "../GenesysParser.cpp"
    break;

  case 8: // expressao: numero
#line 206 "bisonparser.yy"
                                               {yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 982 "../GenesysParser.cpp"
    break;

  case 9: // expressao: funcao
#line 207 "bisonparser.yy"
                                               {yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 988 "../GenesysParser.cpp"
    break;

  case 10: // expressao: comando
#line 208 "bisonparser.yy"
                                               {yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 994 "../GenesysParser.cpp"
    break;

  case 11: // expressao: atribuicao
#line 209 "bisonparser.yy"
                                               {yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1000 "../GenesysParser.cpp"
    break;

  case 12: // expressao: aritmetica
#line 210 "bisonparser.yy"
                                                           {yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1006 "../GenesysParser.cpp"
    break;

  case 13: // expressao: relacional
#line 211 "bisonparser.yy"
                                               {yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1012 "../GenesysParser.cpp"
    break;

  case 14: // expressao: "(" expressao ")"
#line 212 "bisonparser.yy"
                                               {yylhs.value.as < obj_t > ().valor = yystack_[1].value.as < obj_t > ().valor;}
#line 1018 "../GenesysParser.cpp"
    break;

  case 15: // expressao: atributo
#line 213 "bisonparser.yy"
                                               {yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1024 "../GenesysParser.cpp"
    break;

  case 16: // expressao: variavel
#line 216 "bisonparser.yy"
                                               {yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1030 "../GenesysParser.cpp"
    break;

  case 17: // expressao: formula
#line 219 "bisonparser.yy"
                                               {yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1036 "../GenesysParser.cpp"
    break;

  case 18: // numero: NUMD
#line 224 "bisonparser.yy"
                                               { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1042 "../GenesysParser.cpp"
    break;

  case 19: // numero: NUMH
#line 225 "bisonparser.yy"
                                               { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1048 "../GenesysParser.cpp"
    break;

  case 20: // aritmetica: expressao "+" expressao
#line 228 "bisonparser.yy"
                                               { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor + yystack_[0].value.as < obj_t > ().valor;}
#line 1054 "../GenesysParser.cpp"
    break;

  case 21: // aritmetica: expressao "-" expressao
#line 229 "bisonparser.yy"
                                               { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor - yystack_[0].value.as < obj_t > ().valor;}
#line 1060 "../GenesysParser.cpp"
    break;

  case 22: // aritmetica: expressao "/" expressao
#line 230 "bisonparser.yy"
                                               { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor / yystack_[0].value.as < obj_t > ().valor;}
#line 1066 "../GenesysParser.cpp"
    break;

  case 23: // aritmetica: expressao "*" expressao
#line 231 "bisonparser.yy"
                                               { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor * yystack_[0].value.as < obj_t > ().valor;}
#line 1072 "../GenesysParser.cpp"
    break;

  case 24: // aritmetica: expressao "^" expressao
#line 232 "bisonparser.yy"
                                               { yylhs.value.as < obj_t > ().valor = pow(yystack_[2].value.as < obj_t > ().valor,yystack_[0].value.as < obj_t > ().valor);}
#line 1078 "../GenesysParser.cpp"
    break;

  case 25: // aritmetica: fEXP "(" expressao ")"
#line 233 "bisonparser.yy"
                                               { yylhs.value.as < obj_t > ().valor = exp(yystack_[1].value.as < obj_t > ().valor);}
#line 1084 "../GenesysParser.cpp"
    break;

  case 26: // aritmetica: "-" expressao
#line 234 "bisonparser.yy"
                                               { yylhs.value.as < obj_t > ().valor = -yystack_[0].value.as < obj_t > ().valor;}
#line 1090 "../GenesysParser.cpp"
    break;

  case 27: // relacional: expressao oAND expressao
#line 237 "bisonparser.yy"
                                               { yylhs.value.as < obj_t > ().valor = (int) yystack_[2].value.as < obj_t > ().valor && (int) yystack_[0].value.as < obj_t > ().valor;}
#line 1096 "../GenesysParser.cpp"
    break;

  case 28: // relacional: expressao oOR expressao
#line 238 "bisonparser.yy"
                                               { yylhs.value.as < obj_t > ().valor = (int) yystack_[2].value.as < obj_t > ().valor || (int) yystack_[0].value.as < obj_t > ().valor;}
#line 1102 "../GenesysParser.cpp"
    break;

  case 29: // relacional: expressao "<" expressao
#line 239 "bisonparser.yy"
                                               { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor < yystack_[0].value.as < obj_t > ().valor ? 1 : 0;}
#line 1108 "../GenesysParser.cpp"
    break;

  case 30: // relacional: expressao oLE expressao
#line 240 "bisonparser.yy"
                                               { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor <= yystack_[0].value.as < obj_t > ().valor ? 1 : 0;}
#line 1114 "../GenesysParser.cpp"
    break;

  case 31: // relacional: expressao ">" expressao
#line 241 "bisonparser.yy"
                                               { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor > yystack_[0].value.as < obj_t > ().valor ? 1 : 0;}
#line 1120 "../GenesysParser.cpp"
    break;

  case 32: // relacional: expressao oGE expressao
#line 242 "bisonparser.yy"
                                               { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor >= yystack_[0].value.as < obj_t > ().valor ? 1 : 0;}
#line 1126 "../GenesysParser.cpp"
    break;

  case 33: // relacional: expressao oEQ expressao
#line 243 "bisonparser.yy"
                                               { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor == yystack_[0].value.as < obj_t > ().valor ? 1 : 0;}
#line 1132 "../GenesysParser.cpp"
    break;

  case 34: // relacional: expressao oNE expressao
#line 244 "bisonparser.yy"
                                               { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor != yystack_[0].value.as < obj_t > ().valor ? 1 : 0;}
#line 1138 "../GenesysParser.cpp"
    break;

  case 35: // comando: comandoIF
#line 247 "bisonparser.yy"
                            { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1144 "../GenesysParser.cpp"
    break;

  case 36: // comando: comandoFOR
#line 248 "bisonparser.yy"
                            { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1150 "../GenesysParser.cpp"
    break;

  case 37: // comandoIF: cIF "(" expressao ")" expressao cELSE expressao
#line 251 "bisonparser.yy"
                                                                { yylhs.value.as < obj_t > ().valor = yystack_[4].value.as < obj_t > ().valor != 0 ? yystack_[2].value.as < obj_t > ().valor : yystack_[0].value.as < obj_t > ().valor; }
#line 1156 "../GenesysParser.cpp"
    break;

  case 38: // comandoIF: cIF "(" expressao ")" expressao
#line 252 "bisonparser.yy"
                                                                { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor != 0 ? yystack_[0].value.as < obj_t > ().valor : 0;}
#line 1162 "../GenesysParser.cpp"
    break;

  case 39: // comandoFOR: cFOR variavel "=" expressao cTO expressao cDO atribuicao
#line 255 "bisonparser.yy"
                                                                        {yylhs.value.as < obj_t > ().valor = 0; }
#line 1168 "../GenesysParser.cpp"
    break;

  case 40: // comandoFOR: cFOR atributo "=" expressao cTO expressao cDO atribuicao
#line 256 "bisonparser.yy"
                                                                        {yylhs.value.as < obj_t > ().valor = 0; }
#line 1174 "../GenesysParser.cpp"
    break;

  case 41: // funcao: funcaoArit
#line 259 "bisonparser.yy"
                                               { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1180 "../GenesysParser.cpp"
    break;

  case 42: // funcao: funcaoTrig
#line 260 "bisonparser.yy"
                                               { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1186 "../GenesysParser.cpp"
    break;

  case 43: // funcao: funcaoProb
#line 261 "bisonparser.yy"
                                               { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1192 "../GenesysParser.cpp"
    break;

  case 44: // funcao: funcaoKernel
#line 262 "bisonparser.yy"
                                               { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1198 "../GenesysParser.cpp"
    break;

  case 45: // funcao: funcaoPlugin
#line 263 "bisonparser.yy"
                                               { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1204 "../GenesysParser.cpp"
    break;

  case 46: // funcao: funcaoUser
#line 264 "bisonparser.yy"
                                               { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1210 "../GenesysParser.cpp"
    break;

  case 47: // funcaoKernel: fTNOW
#line 267 "bisonparser.yy"
                             { yylhs.value.as < obj_t > ().valor = driver.getModel()->getSimulation()->getSimulatedTime();}
#line 1216 "../GenesysParser.cpp"
    break;

  case 48: // funcaoKernel: fTFIN
#line 268 "bisonparser.yy"
                             { yylhs.value.as < obj_t > ().valor = driver.getModel()->getSimulation()->getReplicationLength();}
#line 1222 "../GenesysParser.cpp"
    break;

  case 49: // funcaoKernel: CSTAT
#line 269 "bisonparser.yy"
                                 { yylhs.value.as < obj_t > ().valor = 0; }
#line 1228 "../GenesysParser.cpp"
    break;

  case 50: // funcaoKernel: fTAVG "(" CSTAT ")"
#line 270 "bisonparser.yy"
                                           {
                    StatisticsCollector* cstat = ((StatisticsCollector*)(driver.getModel()->getElements()->getElement(Util::TypeOf<StatisticsCollector>(), yystack_[1].value.as < obj_t > ().id)));
                    double value = cstat->getStatistics()->average();
                    yylhs.value.as < obj_t > ().valor = value; }
#line 1237 "../GenesysParser.cpp"
    break;

  case 51: // funcaoTrig: fSIN "(" expressao ")"
#line 276 "bisonparser.yy"
                                               { yylhs.value.as < obj_t > ().valor = sin(yystack_[1].value.as < obj_t > ().valor); }
#line 1243 "../GenesysParser.cpp"
    break;

  case 52: // funcaoTrig: fCOS "(" expressao ")"
#line 277 "bisonparser.yy"
                                               { yylhs.value.as < obj_t > ().valor = cos(yystack_[1].value.as < obj_t > ().valor); }
#line 1249 "../GenesysParser.cpp"
    break;

  case 53: // funcaoArit: fROUND "(" expressao ")"
#line 280 "bisonparser.yy"
                                                            { yylhs.value.as < obj_t > ().valor = round(yystack_[1].value.as < obj_t > ().valor);}
#line 1255 "../GenesysParser.cpp"
    break;

  case 54: // funcaoArit: fFRAC "(" expressao ")"
#line 281 "bisonparser.yy"
                                                            { yylhs.value.as < obj_t > ().valor = yystack_[1].value.as < obj_t > ().valor - (int) yystack_[1].value.as < obj_t > ().valor;}
#line 1261 "../GenesysParser.cpp"
    break;

  case 55: // funcaoArit: fTRUNC "(" expressao ")"
#line 282 "bisonparser.yy"
                                                            { yylhs.value.as < obj_t > ().valor = trunc(yystack_[1].value.as < obj_t > ().valor);}
#line 1267 "../GenesysParser.cpp"
    break;

  case 56: // funcaoArit: fMOD "(" expressao "," expressao ")"
#line 283 "bisonparser.yy"
                                                            { yylhs.value.as < obj_t > ().valor = (int) yystack_[3].value.as < obj_t > ().valor % (int) yystack_[1].value.as < obj_t > ().valor; }
#line 1273 "../GenesysParser.cpp"
    break;

  case 57: // funcaoProb: fRND1
#line 286 "bisonparser.yy"
                                                            { yylhs.value.as < obj_t > ().valor = driver.sampler()->sampleUniform(0.0,1.0); yylhs.value.as < obj_t > ().tipo = "Uniforme"; }
#line 1279 "../GenesysParser.cpp"
    break;

  case 58: // funcaoProb: fEXPO "(" expressao ")"
#line 287 "bisonparser.yy"
                                                                        { yylhs.value.as < obj_t > ().valor = driver.sampler()->sampleExponential(yystack_[1].value.as < obj_t > ().valor); yylhs.value.as < obj_t > ().tipo = "Exponencial";}
#line 1285 "../GenesysParser.cpp"
    break;

  case 59: // funcaoProb: fNORM "(" expressao "," expressao ")"
#line 288 "bisonparser.yy"
                                                            { yylhs.value.as < obj_t > ().valor = driver.sampler()->sampleNormal(yystack_[3].value.as < obj_t > ().valor,yystack_[1].value.as < obj_t > ().valor); yylhs.value.as < obj_t > ().tipo = "Normal"; }
#line 1291 "../GenesysParser.cpp"
    break;

  case 60: // funcaoProb: fUNIF "(" expressao "," expressao ")"
#line 289 "bisonparser.yy"
                                                            { yylhs.value.as < obj_t > ().valor = driver.sampler()->sampleUniform(yystack_[3].value.as < obj_t > ().valor,yystack_[1].value.as < obj_t > ().valor); yylhs.value.as < obj_t > ().tipo = "Uniforme"; }
#line 1297 "../GenesysParser.cpp"
    break;

  case 61: // funcaoProb: fWEIB "(" expressao "," expressao ")"
#line 290 "bisonparser.yy"
                                                            { yylhs.value.as < obj_t > ().valor = driver.sampler()->sampleWeibull(yystack_[3].value.as < obj_t > ().valor,yystack_[1].value.as < obj_t > ().valor); yylhs.value.as < obj_t > ().tipo = "Weibull"; }
#line 1303 "../GenesysParser.cpp"
    break;

  case 62: // funcaoProb: fLOGN "(" expressao "," expressao ")"
#line 291 "bisonparser.yy"
                                                            { yylhs.value.as < obj_t > ().valor = driver.sampler()->sampleLogNormal(yystack_[3].value.as < obj_t > ().valor,yystack_[1].value.as < obj_t > ().valor); yylhs.value.as < obj_t > ().tipo = "LOGNormal"; }
#line 1309 "../GenesysParser.cpp"
    break;

  case 63: // funcaoProb: fGAMM "(" expressao "," expressao ")"
#line 292 "bisonparser.yy"
                                                            { yylhs.value.as < obj_t > ().valor = driver.sampler()->sampleGamma(yystack_[3].value.as < obj_t > ().valor,yystack_[1].value.as < obj_t > ().valor); yylhs.value.as < obj_t > ().tipo = "Gamma"; }
#line 1315 "../GenesysParser.cpp"
    break;

  case 64: // funcaoProb: fERLA "(" expressao "," expressao ")"
#line 293 "bisonparser.yy"
                                                            { yylhs.value.as < obj_t > ().valor = driver.sampler()->sampleErlang(yystack_[3].value.as < obj_t > ().valor,yystack_[1].value.as < obj_t > ().valor); yylhs.value.as < obj_t > ().tipo = "Erlang"; }
#line 1321 "../GenesysParser.cpp"
    break;

  case 65: // funcaoProb: fTRIA "(" expressao "," expressao "," expressao ")"
#line 294 "bisonparser.yy"
                                                                    { yylhs.value.as < obj_t > ().valor = driver.sampler()->sampleTriangular(yystack_[5].value.as < obj_t > ().valor,yystack_[3].value.as < obj_t > ().valor,yystack_[1].value.as < obj_t > ().valor); yylhs.value.as < obj_t > ().tipo = "Triangular"; }
#line 1327 "../GenesysParser.cpp"
    break;

  case 66: // funcaoProb: fBETA "(" expressao "," expressao "," expressao "," expressao ")"
#line 295 "bisonparser.yy"
                                                                                  { yylhs.value.as < obj_t > ().valor = driver.sampler()->sampleBeta(yystack_[7].value.as < obj_t > ().valor,yystack_[5].value.as < obj_t > ().valor,yystack_[3].value.as < obj_t > ().valor,yystack_[1].value.as < obj_t > ().valor); yylhs.value.as < obj_t > ().tipo = "Beta"; }
#line 1333 "../GenesysParser.cpp"
    break;

  case 67: // funcaoProb: fDISC "(" listaparm ")"
#line 296 "bisonparser.yy"
              { yylhs.value.as < obj_t > () = yystack_[3].value.as < obj_t > (); }
#line 1339 "../GenesysParser.cpp"
    break;

  case 68: // funcaoUser: "USER" "(" expressao ")"
#line 301 "bisonparser.yy"
                                               { yylhs.value.as < obj_t > ().valor = yystack_[1].value.as < obj_t > ().valor; }
#line 1345 "../GenesysParser.cpp"
    break;

  case 69: // listaparm: listaparm "," expressao "," expressao
#line 305 "bisonparser.yy"
              { yylhs.value.as < obj_t > () = yystack_[4].value.as < obj_t > (); }
#line 1351 "../GenesysParser.cpp"
    break;

  case 70: // listaparm: expressao "," expressao
#line 306 "bisonparser.yy"
              { yylhs.value.as < obj_t > () = yystack_[2].value.as < obj_t > (); }
#line 1357 "../GenesysParser.cpp"
    break;

  case 71: // illegal: ILLEGAL
#line 309 "bisonparser.yy"
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
#line 1378 "../GenesysParser.cpp"
    break;

  case 72: // atributo: ATRIB
#line 329 "bisonparser.yy"
                         {  
		    double attributeValue = 0.0;
		    if (driver.getModel()->getSimulation()->getCurrentEntity() != nullptr) {
			// it could crach because there may be no current entity, if the parse is running before simulation and therefore there is no CurrentEntity
			attributeValue = driver.getModel()->getSimulation()->getCurrentEntity()->getAttributeValue(yystack_[0].value.as < obj_t > ().id);
		    }
			//std::cout << "Passei" << std::endl;
		    yylhs.value.as < obj_t > ().valor = attributeValue; 
		}
#line 1392 "../GenesysParser.cpp"
    break;

  case 73: // atributo: ATRIB "[" expressao "]"
#line 338 "bisonparser.yy"
                                                 {  
		    double attributeValue = 0.0;
		    std::string index = std::to_string(static_cast<unsigned int>(yystack_[1].value.as < obj_t > ().valor));
		    if (driver.getModel()->getSimulation()->getCurrentEntity() != nullptr) {
			// it could crach because there may be no current entity, if the parse is running before simulation and therefore there is no CurrentEntity
			attributeValue = driver.getModel()->getSimulation()->getCurrentEntity()->getAttributeValue(index, yystack_[3].value.as < obj_t > ().id);
		    }
		    yylhs.value.as < obj_t > ().valor = attributeValue; 
		}
#line 1406 "../GenesysParser.cpp"
    break;

  case 74: // atributo: ATRIB "[" expressao "," expressao "]"
#line 347 "bisonparser.yy"
                                                               {  
		    double attributeValue = 0.0;
		    std::string index = std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[1].value.as < obj_t > ().valor));
		    if (driver.getModel()->getSimulation()->getCurrentEntity() != nullptr) {
			// it could crach because there may be no current entity, if the parse is running before simulation and therefore there is no CurrentEntity
			attributeValue = driver.getModel()->getSimulation()->getCurrentEntity()->getAttributeValue(index, yystack_[5].value.as < obj_t > ().id);
		    }
		    yylhs.value.as < obj_t > ().valor = attributeValue; 
		}
#line 1420 "../GenesysParser.cpp"
    break;

  case 75: // atributo: ATRIB "[" expressao "," expressao "," expressao "]"
#line 356 "bisonparser.yy"
                                                                             {  
		    double attributeValue = 0.0;
		    std::string index = std::to_string(static_cast<unsigned int>(yystack_[5].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[1].value.as < obj_t > ().valor));
		    if (driver.getModel()->getSimulation()->getCurrentEntity() != nullptr) {
			// it could crach because there may be no current entity, if the parse is running before simulation and therefore there is no CurrentEntity
			attributeValue = driver.getModel()->getSimulation()->getCurrentEntity()->getAttributeValue(index, yystack_[7].value.as < obj_t > ().id);
		    }
		    yylhs.value.as < obj_t > ().valor = attributeValue; 
		}
#line 1434 "../GenesysParser.cpp"
    break;

  case 76: // variavel: VARI
#line 369 "bisonparser.yy"
                    {yylhs.value.as < obj_t > ().valor = ((Variable*)(driver.getModel()->getElements()->getElement(Util::TypeOf<Variable>(), yystack_[0].value.as < obj_t > ().id)))->value();}
#line 1440 "../GenesysParser.cpp"
    break;

  case 77: // variavel: VARI "[" expressao "]"
#line 370 "bisonparser.yy"
                                                    { 
                std::string index = std::to_string(static_cast<unsigned int>(yystack_[1].value.as < obj_t > ().valor));
                yylhs.value.as < obj_t > ().valor = ((Variable*)(driver.getModel()->getElements()->getElement(Util::TypeOf<Variable>(), yystack_[3].value.as < obj_t > ().id)))->value(index); }
#line 1448 "../GenesysParser.cpp"
    break;

  case 78: // variavel: VARI "[" expressao "," expressao "]"
#line 373 "bisonparser.yy"
                                                                    { 
                std::string index = std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[1].value.as < obj_t > ().valor)); 
                yylhs.value.as < obj_t > ().valor = ((Variable*)(driver.getModel()->getElements()->getElement(Util::TypeOf<Variable>(), yystack_[5].value.as < obj_t > ().id)))->value(index);}
#line 1456 "../GenesysParser.cpp"
    break;

  case 79: // variavel: VARI "[" expressao "," expressao "," expressao "]"
#line 376 "bisonparser.yy"
                                                                              { 
                std::string index = std::to_string(static_cast<unsigned int>(yystack_[5].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[1].value.as < obj_t > ().valor));
                yylhs.value.as < obj_t > ().valor = ((Variable*)(driver.getModel()->getElements()->getElement(Util::TypeOf<Variable>(), yystack_[7].value.as < obj_t > ().id)))->value(index);}
#line 1464 "../GenesysParser.cpp"
    break;

  case 80: // formula: FORM
#line 384 "bisonparser.yy"
                            { 
                yylhs.value.as < obj_t > ().valor = ((Formula*)(driver.getModel()->getElements()->getElement(Util::TypeOf<Formula>(), yystack_[0].value.as < obj_t > ().id)))->value();}
#line 1471 "../GenesysParser.cpp"
    break;

  case 81: // formula: FORM "[" expressao "]"
#line 386 "bisonparser.yy"
                                               {
                std::string index = std::to_string(static_cast<unsigned int>(yystack_[1].value.as < obj_t > ().valor));
                yylhs.value.as < obj_t > ().valor = ((Formula*)(driver.getModel()->getElements()->getElement(Util::TypeOf<Formula>(), yystack_[3].value.as < obj_t > ().id)))->value(index);}
#line 1479 "../GenesysParser.cpp"
    break;

  case 82: // formula: FORM "[" expressao "," expressao "]"
#line 389 "bisonparser.yy"
                                                             {
                std::string index = std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor)) +","+std::to_string(static_cast<unsigned int>(yystack_[1].value.as < obj_t > ().valor));
                yylhs.value.as < obj_t > ().valor = ((Formula*)(driver.getModel()->getElements()->getElement(Util::TypeOf<Formula>(), yystack_[5].value.as < obj_t > ().id)))->value(index);}
#line 1487 "../GenesysParser.cpp"
    break;

  case 83: // formula: FORM "[" expressao "," expressao "," expressao "]"
#line 392 "bisonparser.yy"
                                                                           {
                std::string index = std::to_string(static_cast<unsigned int>(yystack_[5].value.as < obj_t > ().valor)) +","+std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[1].value.as < obj_t > ().valor));
                yylhs.value.as < obj_t > ().valor = ((Formula*)(driver.getModel()->getElements()->getElement(Util::TypeOf<Formula>(), yystack_[7].value.as < obj_t > ().id)))->value(index);}
#line 1495 "../GenesysParser.cpp"
    break;

  case 84: // atribuicao: ATRIB "=" expressao
#line 400 "bisonparser.yy"
                                        { 
                driver.getModel()->getSimulation()->getCurrentEntity()->setAttributeValue("", yystack_[2].value.as < obj_t > ().id, yystack_[0].value.as < obj_t > ().valor);
                yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1503 "../GenesysParser.cpp"
    break;

  case 85: // atribuicao: ATRIB "[" expressao "]" "=" expressao
#line 403 "bisonparser.yy"
                                                                    { 
                std::string index = std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor));
                driver.getModel()->getSimulation()->getCurrentEntity()->setAttributeValue(index, yystack_[5].value.as < obj_t > ().id, yystack_[0].value.as < obj_t > ().valor);
                yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1512 "../GenesysParser.cpp"
    break;

  case 86: // atribuicao: ATRIB "[" expressao "," expressao "]" "=" expressao
#line 407 "bisonparser.yy"
                                                                                 {
                std::string index = std::to_string(static_cast<unsigned int>(yystack_[5].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor)); 
                driver.getModel()->getSimulation()->getCurrentEntity()->setAttributeValue(index, yystack_[7].value.as < obj_t > ().id, yystack_[0].value.as < obj_t > ().valor); 
                yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1521 "../GenesysParser.cpp"
    break;

  case 87: // atribuicao: ATRIB "[" expressao "," expressao "," expressao "]" "=" expressao
#line 411 "bisonparser.yy"
                                                                                                  {
                std::string index = std::to_string(static_cast<unsigned int>(yystack_[7].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[5].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor));
                driver.getModel()->getSimulation()->getCurrentEntity()->setAttributeValue(index, yystack_[9].value.as < obj_t > ().id, yystack_[0].value.as < obj_t > ().valor);
                yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1530 "../GenesysParser.cpp"
    break;

  case 88: // atribuicao: VARI "=" expressao
#line 417 "bisonparser.yy"
                                           {
                ((Variable*)(driver.getModel()->getElements()->getElement(Util::TypeOf<Variable>(), yystack_[2].value.as < obj_t > ().id)))->setValue(yystack_[0].value.as < obj_t > ().valor);
                yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1538 "../GenesysParser.cpp"
    break;

  case 89: // atribuicao: VARI "[" expressao "]" "=" expressao
#line 420 "bisonparser.yy"
                                                                   { 
                std::string index = std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor));
                ((Variable*)(driver.getModel()->getElements()->getElement(Util::TypeOf<Variable>(), yystack_[5].value.as < obj_t > ().id)))->setValue(index, yystack_[0].value.as < obj_t > ().valor); 
                yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1547 "../GenesysParser.cpp"
    break;

  case 90: // atribuicao: VARI "[" expressao "," expressao "]" "=" expressao
#line 424 "bisonparser.yy"
                                                                                {
                std::string index = std::to_string(static_cast<unsigned int>(yystack_[5].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor)); 
                ((Variable*)(driver.getModel()->getElements()->getElement(Util::TypeOf<Variable>(), yystack_[7].value.as < obj_t > ().id)))->setValue(index, yystack_[0].value.as < obj_t > ().valor);
                yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1556 "../GenesysParser.cpp"
    break;

  case 91: // atribuicao: VARI "[" expressao "," expressao "," expressao "]" "=" expressao
#line 428 "bisonparser.yy"
                                                                                                 {
                std::string index = std::to_string(static_cast<unsigned int>(yystack_[7].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[5].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor));
                ((Variable*)(driver.getModel()->getElements()->getElement(Util::TypeOf<Variable>(), yystack_[9].value.as < obj_t > ().id)))->setValue(index, yystack_[0].value.as < obj_t > ().valor); 
                yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1565 "../GenesysParser.cpp"
    break;

  case 92: // funcaoPlugin: CTEZERO
#line 437 "bisonparser.yy"
                                                               { yylhs.value.as < obj_t > ().valor = 0; }
#line 1571 "../GenesysParser.cpp"
    break;

  case 93: // funcaoPlugin: fNQ "(" QUEUE ")"
#line 440 "bisonparser.yy"
                                            { yylhs.value.as < obj_t > ().valor = ((Queue*)(driver.getModel()->getElements()->getElement(Util::TypeOf<Queue>(), yystack_[1].value.as < obj_t > ().id)))->size();}
#line 1577 "../GenesysParser.cpp"
    break;

  case 94: // funcaoPlugin: fLASTINQ "(" QUEUE ")"
#line 441 "bisonparser.yy"
                                            {/*For now does nothing because need acces to list of QUEUE, or at least the last element*/ }
#line 1583 "../GenesysParser.cpp"
    break;

  case 95: // funcaoPlugin: fFIRSTINQ "(" QUEUE ")"
#line 442 "bisonparser.yy"
                                            { 
                if (((Queue*)(driver.getModel()->getElements()->getElement(Util::TypeOf<Queue>(), yystack_[1].value.as < obj_t > ().id)))->size() > 0){
                    //id da 1a entidade da fila, talvez pegar nome
                    yylhs.value.as < obj_t > ().valor = ((Queue*)(driver.getModel()->getElements()->getElement(Util::TypeOf<Queue>(), yystack_[1].value.as < obj_t > ().id)))->first()->getEntity()->getId();
                }else{
                    yylhs.value.as < obj_t > ().valor = 0;
                } }
#line 1595 "../GenesysParser.cpp"
    break;

  case 96: // funcaoPlugin: fSAQUE "(" QUEUE "," ATRIB ")"
#line 449 "bisonparser.yy"
                                               {   
                Util::identification queueID = yystack_[3].value.as < obj_t > ().id;
                Util::identification attrID = yystack_[1].value.as < obj_t > ().id;
                double sum = ((Queue*)(driver.getModel()->getElements()->getElement(Util::TypeOf<Queue>(), yystack_[3].value.as < obj_t > ().id)))->sumAttributesFromWaiting(attrID);
                yylhs.value.as < obj_t > ().valor = sum; }
#line 1605 "../GenesysParser.cpp"
    break;

  case 97: // funcaoPlugin: fAQUE "(" QUEUE "," NUMD "," ATRIB ")"
#line 454 "bisonparser.yy"
                                                     {
                Util::identification queueID = yystack_[5].value.as < obj_t > ().id;
                Util::identification attrID = yystack_[1].value.as < obj_t > ().id;
                double value = ((Queue*)(driver.getModel()->getElements()->getElement(Util::TypeOf<Queue>(), yystack_[5].value.as < obj_t > ().id)))->getAttributeFromWaitingRank(yystack_[3].value.as < obj_t > ().valor-1, attrID); // rank starts on 0 in genesys
                yylhs.value.as < obj_t > ().valor = value; }
#line 1615 "../GenesysParser.cpp"
    break;

  case 98: // funcaoPlugin: fMR "(" RESOURCE ")"
#line 462 "bisonparser.yy"
                                                { yylhs.value.as < obj_t > ().valor = ((Resource*)driver.getModel()->getElements()->getElement(Util::TypeOf<Resource>(), yystack_[1].value.as < obj_t > ().id))->getCapacity();}
#line 1621 "../GenesysParser.cpp"
    break;

  case 99: // funcaoPlugin: fNR "(" RESOURCE ")"
#line 463 "bisonparser.yy"
                                                { yylhs.value.as < obj_t > ().valor = ((Resource*)driver.getModel()->getElements()->getElement(Util::TypeOf<Resource>(), yystack_[1].value.as < obj_t > ().id))->getNumberBusy();}
#line 1627 "../GenesysParser.cpp"
    break;

  case 100: // funcaoPlugin: fRESSEIZES "(" RESOURCE ")"
#line 464 "bisonparser.yy"
                                                { /*For now does nothing because needs get Seizes, check with teacher*/}
#line 1633 "../GenesysParser.cpp"
    break;

  case 101: // funcaoPlugin: fSTATE "(" RESOURCE ")"
#line 465 "bisonparser.yy"
                                                {  yylhs.value.as < obj_t > ().valor = static_cast<int>(((Resource*)driver.getModel()->getElements()->getElement(Util::TypeOf<Resource>(), yystack_[1].value.as < obj_t > ().id))->getResourceState()); }
#line 1639 "../GenesysParser.cpp"
    break;

  case 102: // funcaoPlugin: fIRF "(" RESOURCE ")"
#line 466 "bisonparser.yy"
                                                 { yylhs.value.as < obj_t > ().valor = ((Resource*)driver.getModel()->getElements()->getElement(Util::TypeOf<Resource>(), yystack_[1].value.as < obj_t > ().id))->getResourceState() == Resource::ResourceState::FAILED ? 1 : 0; }
#line 1645 "../GenesysParser.cpp"
    break;

  case 103: // funcaoPlugin: fSETSUM "(" SET ")"
#line 467 "bisonparser.yy"
                                     {
                unsigned int count=0;
                Resource* res;
                List<ModelElement*>* setList = ((Set*)driver.getModel()->getElements()->getElement(Util::TypeOf<Set>(),yystack_[1].value.as < obj_t > ().id))->getElementSet(); 
                for (std::list<ModelElement*>::iterator it = setList->list()->begin(); it!=setList->list()->end(); it++) {
                    res = dynamic_cast<Resource*>(*it);
                    if (res != nullptr) {
                        if (res->getResourceState()==Resource::ResourceState::BUSY) {
                            count++;
                        }
                    }
                }
                yylhs.value.as < obj_t > ().valor = count; }
#line 1663 "../GenesysParser.cpp"
    break;

  case 104: // funcaoPlugin: fNUMSET "(" SET ")"
#line 483 "bisonparser.yy"
                                        { yylhs.value.as < obj_t > ().valor = ((Set*)driver.getModel()->getElements()->getElement(Util::TypeOf<Set>(),yystack_[1].value.as < obj_t > ().id))->getElementSet()->size(); }
#line 1669 "../GenesysParser.cpp"
    break;


#line 1673 "../GenesysParser.cpp"

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
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
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
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
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
    {
      stack_symbol_type error_token;

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
    YY_STACK_PRINT ();
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

  std::string
  genesyspp_parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // genesyspp_parser::context.
  genesyspp_parser::context::context (const genesyspp_parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  genesyspp_parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        int yychecklim = yylast_ - yyn + 1;
        int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }



  int
  genesyspp_parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
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

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  genesyspp_parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

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
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const short genesyspp_parser::yypact_ninf_ = -282;

  const signed char genesyspp_parser::yytable_ninf_ = -3;

  const short
  genesyspp_parser::yypact_[] =
  {
     281,   -62,  -282,   343,  -282,  -282,  -282,  -282,  -282,  -282,
     -47,   -46,   -45,   -39,   -18,   -17,   -16,  -282,   -15,    -6,
      -5,    -4,    -3,    -2,    -1,     0,     4,     5,  -282,  -282,
      20,   -36,   -54,  -282,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,   -53,    34,   405,
     405,  -282,    35,  -282,  1501,  -282,  -282,  -282,  -282,  -282,
    -282,  -282,  -282,  -282,  -282,  -282,  -282,  -282,  -282,  -282,
    -282,  -282,   405,   405,   405,   405,   405,   405,   405,   405,
     405,   405,   405,   405,   405,   405,   405,   405,   405,   405,
      36,    50,    43,    44,   405,   405,    54,    60,    73,    74,
      75,    76,    64,    47,    71,    72,    79,    80,    77,   405,
     405,   405,   937,  1501,   405,   405,   405,   405,   405,   405,
     405,   405,   405,   405,   405,   405,   405,   405,   947,   957,
     967,   696,  1031,  1041,  1051,  1061,   705,   714,   723,   732,
     741,   807,   816,   825,   834,   -56,  1071,   405,   405,   405,
     405,    41,  1501,    70,    81,    82,    92,    95,    96,    97,
      98,    99,   101,    62,    63,   102,   116,  1501,   464,  -282,
    1135,  1501,  1501,  1501,  1501,  1501,  1501,  1501,  1501,  1501,
    1501,  1501,  1501,  1501,  -282,  -282,  -282,   405,  -282,  -282,
    -282,  -282,   405,   405,   405,   405,   405,   405,   405,   405,
     405,  -282,   405,   405,   474,   484,  1142,  1149,    61,   405,
    -282,  -282,  -282,  -282,  -282,  -282,  -282,  -282,  -282,  -282,
     125,   132,  -282,    66,   405,  -282,   405,  -282,  1159,  1173,
    1183,  1247,  1257,  1267,  1277,   843,   852,  1501,   918,  1284,
    -282,   405,  -282,   405,   405,   405,   405,   494,   104,    68,
     405,   504,   514,  -282,  -282,  -282,  -282,  -282,  -282,  -282,
     405,   405,   405,   405,   580,   590,  1291,  1355,  1501,    67,
     405,  -282,   127,  1501,   100,   405,  -282,   405,  1365,   927,
    1501,  1501,  -282,   405,  -282,   405,   -35,   -35,   405,  1373,
     106,   405,  1387,  1395,  -282,   405,  1403,  1437,   -52,   -51,
    -282,  -282,  1501,   103,  -282,  1501,   118,  -282,  1467,  -282,
    -282,   405,   405,   405,   405,  -282,   600,   610,  1501,  1501,
      61,   405,    66,   405,   620,   630,    67,   405,   100,   405,
    1475,  1483,   103,   118
  };

  const signed char
  genesyspp_parser::yydefact_[] =
  {
       0,     0,    71,     0,     5,     6,     1,    18,    19,    92,
       0,     0,     0,     0,     0,     0,     0,    57,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    47,    48,
       0,     0,    72,    49,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    76,    80,     0,
       0,     3,     0,     4,     7,     8,    12,    13,    10,    35,
      36,     9,    44,    42,    41,    43,    46,    15,    16,    17,
      11,    45,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      72,    76,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    26,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    84,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    88,     0,    14,
       0,    30,    32,    33,    34,    27,    28,    20,    21,    23,
      24,    22,    29,    31,    51,    52,    53,     0,    55,    54,
      25,    58,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    67,     0,     0,     0,     0,     0,     0,    73,     0,
      50,    99,    98,   102,   100,   101,   103,    93,    95,    94,
       0,     0,   104,    77,     0,    81,     0,    68,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    70,     0,    38,
      73,     0,    77,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    56,    59,    60,    61,    62,    63,    64,
       0,     0,     0,     0,     0,     0,     0,     0,    85,    74,
       0,    96,     0,    89,    78,     0,    82,     0,     0,     0,
      69,    37,    74,     0,    78,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    65,     0,     0,     0,     0,     0,
      40,    39,    86,    75,    97,    90,    79,    83,     0,    75,
      79,     0,     0,     0,     0,    66,     0,     0,    87,    91,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0
  };

  const short
  genesyspp_parser::yypgoto_[] =
  {
    -282,  -282,  -282,   -49,  -282,  -282,  -282,  -282,  -282,  -282,
    -282,  -282,  -282,  -282,  -282,  -282,  -282,  -282,   109,   136,
    -282,  -281,  -282
  };

  const unsigned char
  genesyspp_parser::yydefgoto_[] =
  {
       0,     3,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,   145,     4,    67,    68,
      69,    70,    71
  };

  const short
  genesyspp_parser::yytable_[] =
  {
     112,   113,    90,   298,   201,   300,   301,    94,   109,   311,
     312,     5,    72,    73,    74,   202,    95,   110,    95,   110,
      75,    91,   299,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     146,    76,    77,    78,    79,   151,   152,   115,   116,   117,
     118,   119,   120,    80,    81,    82,    83,    84,    85,    86,
     166,   167,   168,    87,    88,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,    89,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   153,   114,   111,   160,   147,   204,   205,
     206,   207,   154,   208,   121,   122,   123,   124,   125,   126,
     127,   148,   209,   149,   150,   155,   156,   157,   158,   159,
     161,   162,   115,   116,   117,   118,   119,   120,   163,   164,
     210,   246,   165,   220,   221,   249,   250,   288,   228,   272,
      92,   211,   212,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   213,   238,   239,   214,   215,   216,   217,   218,
     247,   219,   222,   248,   271,   290,   304,    93,     0,     0,
     291,     0,     0,   313,     0,   251,     0,   252,   223,   121,
     122,   123,   124,   125,   126,   127,     0,   224,   314,     0,
       0,     0,   264,     0,   265,   266,   267,   268,     0,     0,
       0,   273,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   278,   279,   280,   281,     0,     0,     0,     0,     0,
       0,   289,     0,     0,     0,     0,   292,     0,   293,     0,
       0,     0,     0,     0,   296,     0,   297,     0,     0,   302,
       0,     0,   305,     0,     0,     0,   308,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   316,   317,   318,   319,     0,     0,     0,     0,
       0,     0,   324,     0,   325,     0,     0,     0,   330,     0,
     331,    -2,     1,     0,    -2,    -2,    -2,     0,     0,     0,
       0,     0,     0,     0,    -2,    -2,    -2,    -2,    -2,    -2,
      -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,
      -2,    -2,    -2,    -2,    -2,     0,    -2,     0,     0,    -2,
      -2,    -2,     2,     0,    -2,    -2,    -2,    -2,    -2,    -2,
       0,    -2,    -2,    -2,    -2,    -2,     0,    -2,    -2,    -2,
      -2,     0,     0,     6,     0,    -2,     7,     8,     9,     0,
       0,     0,     0,     0,    -2,    -2,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,     0,    31,     0,
       0,    32,    33,    34,     0,     0,    35,    36,    37,    38,
      39,    40,     0,    41,    42,    43,    44,    45,     0,    46,
      47,    48,    49,     0,     0,     0,     0,    50,     7,     8,
       9,     0,     0,     0,     0,     0,    51,    52,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,     0,
      31,     0,     0,    32,    33,    34,     0,     0,    35,    36,
      37,    38,    39,    40,     0,    41,    42,    43,    44,    45,
       0,    46,    47,    48,    49,     0,     0,     0,     0,    50,
     115,   116,   117,   118,   119,   120,     0,     0,     0,    52,
     115,   116,   117,   118,   119,   120,     0,     0,     0,     0,
     115,   116,   117,   118,   119,   120,     0,     0,     0,     0,
     115,   116,   117,   118,   119,   120,     0,     0,     0,     0,
     115,   116,   117,   118,   119,   120,     0,     0,     0,     0,
     115,   116,   117,   118,   119,   120,   225,   121,   122,   123,
     124,   125,   126,   127,     0,   226,   240,   121,   122,   123,
     124,   125,   126,   127,     0,   241,   242,   121,   122,   123,
     124,   125,   126,   127,     0,   243,   269,   121,   122,   123,
     124,   125,   126,   127,     0,   270,   274,   121,   122,   123,
     124,   125,   126,   127,     0,   275,   276,   121,   122,   123,
     124,   125,   126,   127,     0,   277,   115,   116,   117,   118,
     119,   120,     0,     0,     0,     0,   115,   116,   117,   118,
     119,   120,     0,     0,     0,     0,   115,   116,   117,   118,
     119,   120,     0,     0,     0,     0,   115,   116,   117,   118,
     119,   120,     0,     0,     0,     0,   115,   116,   117,   118,
     119,   120,     0,     0,     0,     0,   115,   116,   117,   118,
     119,   120,   282,   121,   122,   123,   124,   125,   126,   127,
       0,   283,   284,   121,   122,   123,   124,   125,   126,   127,
       0,   285,   320,   121,   122,   123,   124,   125,   126,   127,
       0,   321,   322,   121,   122,   123,   124,   125,   126,   127,
       0,   323,   326,   121,   122,   123,   124,   125,   126,   127,
       0,   327,   328,   121,   122,   123,   124,   125,   126,   127,
       0,   329,   115,   116,   117,   118,   119,   120,     0,     0,
       0,   115,   116,   117,   118,   119,   120,     0,     0,     0,
     115,   116,   117,   118,   119,   120,     0,     0,     0,   115,
     116,   117,   118,   119,   120,     0,     0,     0,   115,   116,
     117,   118,   119,   120,     0,     0,     0,   115,   116,   117,
     118,   119,   120,     0,     0,     0,     0,     0,     0,   121,
     122,   123,   124,   125,   126,   127,     0,   187,   121,   122,
     123,   124,   125,   126,   127,     0,   192,   121,   122,   123,
     124,   125,   126,   127,     0,   193,   121,   122,   123,   124,
     125,   126,   127,     0,   194,   121,   122,   123,   124,   125,
     126,   127,     0,   195,   121,   122,   123,   124,   125,   126,
     127,     0,   196,   115,   116,   117,   118,   119,   120,     0,
       0,     0,   115,   116,   117,   118,   119,   120,     0,     0,
       0,   115,   116,   117,   118,   119,   120,     0,     0,     0,
     115,   116,   117,   118,   119,   120,     0,     0,     0,   115,
     116,   117,   118,   119,   120,     0,     0,     0,   115,   116,
     117,   118,   119,   120,     0,     0,     0,     0,     0,     0,
     121,   122,   123,   124,   125,   126,   127,     0,   197,   121,
     122,   123,   124,   125,   126,   127,     0,   198,   121,   122,
     123,   124,   125,   126,   127,     0,   199,   121,   122,   123,
     124,   125,   126,   127,     0,   200,   121,   122,   123,   124,
     125,   126,   127,     0,   260,   121,   122,   123,   124,   125,
     126,   127,     0,   261,   115,   116,   117,   118,   119,   120,
       0,     0,     0,   115,   116,   117,   118,   119,   120,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,     0,
       0,   121,   122,   123,   124,   125,   126,   127,     0,   262,
     121,   122,   123,   124,   125,   126,   127,   169,   295,     0,
     121,   122,   123,   124,   125,   126,   127,   184,     0,     0,
     121,   122,   123,   124,   125,   126,   127,   185,     0,     0,
     121,   122,   123,   124,   125,   126,   127,   186,     0,     0,
     121,   122,   123,   124,   125,   126,   127,   115,   116,   117,
     118,   119,   120,     0,     0,     0,     0,   115,   116,   117,
     118,   119,   120,     0,     0,     0,     0,   115,   116,   117,
     118,   119,   120,     0,     0,     0,     0,   115,   116,   117,
     118,   119,   120,     0,     0,     0,     0,   115,   116,   117,
     118,   119,   120,     0,     0,     0,     0,     0,     0,     0,
       0,   188,     0,     0,   121,   122,   123,   124,   125,   126,
     127,   189,     0,     0,   121,   122,   123,   124,   125,   126,
     127,   190,     0,     0,   121,   122,   123,   124,   125,   126,
     127,   191,     0,     0,   121,   122,   123,   124,   125,   126,
     127,   203,     0,     0,   121,   122,   123,   124,   125,   126,
     127,   115,   116,   117,   118,   119,   120,     0,   115,   116,
     117,   118,   119,   120,     0,   115,   116,   117,   118,   119,
     120,     0,     0,     0,     0,   115,   116,   117,   118,   119,
     120,     0,     0,     0,     0,     0,     0,     0,   244,   115,
     116,   117,   118,   119,   120,   245,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   227,     0,     0,   121,   122,
     123,   124,   125,   126,   127,   121,   122,   123,   124,   125,
     126,   127,   121,   122,   123,   124,   125,   126,   127,   253,
       0,     0,   121,   122,   123,   124,   125,   126,   127,     0,
       0,     0,     0,   254,     0,     0,   121,   122,   123,   124,
     125,   126,   127,   255,     0,     0,   121,   122,   123,   124,
     125,   126,   127,   115,   116,   117,   118,   119,   120,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,     0,
     115,   116,   117,   118,   119,   120,     0,   115,   116,   117,
     118,   119,   120,     0,     0,     0,     0,   256,     0,     0,
     121,   122,   123,   124,   125,   126,   127,   257,   263,     0,
     121,   122,   123,   124,   125,   126,   127,   258,   286,     0,
     121,   122,   123,   124,   125,   126,   127,   259,     0,     0,
     121,   122,   123,   124,   125,   126,   127,   121,   122,   123,
     124,   125,   126,   127,   121,   122,   123,   124,   125,   126,
     127,   115,   116,   117,   118,   119,   120,     0,     0,     0,
       0,   115,   116,   117,   118,   119,   120,     0,     0,   115,
     116,   117,   118,   119,   120,     0,     0,     0,     0,     0,
       0,     0,   287,   115,   116,   117,   118,   119,   120,     0,
       0,   115,   116,   117,   118,   119,   120,     0,     0,   115,
     116,   117,   118,   119,   120,     0,     0,     0,   121,   122,
     123,   124,   125,   126,   127,   294,     0,     0,   121,   122,
     123,   124,   125,   126,   127,   303,   121,   122,   123,   124,
     125,   126,   127,   115,   116,   117,   118,   119,   120,   306,
     121,   122,   123,   124,   125,   126,   127,   307,   121,   122,
     123,   124,   125,   126,   127,   309,   121,   122,   123,   124,
     125,   126,   127,   115,   116,   117,   118,   119,   120,     0,
       0,   115,   116,   117,   118,   119,   120,     0,     0,   115,
     116,   117,   118,   119,   120,     0,     0,     0,     0,   310,
     121,   122,   123,   124,   125,   126,   127,   115,   116,   117,
     118,   119,   120,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   315,     0,     0,
     121,   122,   123,   124,   125,   126,   127,   332,   121,   122,
     123,   124,   125,   126,   127,   333,   121,   122,   123,   124,
     125,   126,   127,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   121,   122,   123,   124,   125,   126,
     127
  };

  const short
  genesyspp_parser::yycheck_[] =
  {
      49,    50,    38,    38,    60,   286,   287,    61,    61,    61,
      61,    73,    59,    59,    59,    71,    70,    70,    70,    70,
      59,    57,    57,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    59,    59,    59,    59,    94,    95,     6,     7,     8,
       9,    10,    11,    59,    59,    59,    59,    59,    59,    59,
     109,   110,   111,    59,    59,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    39,    59,    61,    49,    61,   147,   148,
     149,   150,    42,    62,    63,    64,    65,    66,    67,    68,
      69,    61,    71,    70,    70,    42,    42,    42,    42,    55,
      49,    49,     6,     7,     8,     9,    10,    11,    49,    49,
      60,    70,    55,    71,    71,     3,    70,    70,   187,    71,
      31,    60,    60,   192,   193,   194,   195,   196,   197,   198,
     199,   200,    60,   202,   203,    60,    60,    60,    60,    60,
     209,    60,    60,    38,    60,    38,    60,    31,    -1,    -1,
      70,    -1,    -1,    70,    -1,   224,    -1,   226,    62,    63,
      64,    65,    66,    67,    68,    69,    -1,    71,    70,    -1,
      -1,    -1,   241,    -1,   243,   244,   245,   246,    -1,    -1,
      -1,   250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   260,   261,   262,   263,    -1,    -1,    -1,    -1,    -1,
      -1,   270,    -1,    -1,    -1,    -1,   275,    -1,   277,    -1,
      -1,    -1,    -1,    -1,   283,    -1,   285,    -1,    -1,   288,
      -1,    -1,   291,    -1,    -1,    -1,   295,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   311,   312,   313,   314,    -1,    -1,    -1,    -1,
      -1,    -1,   321,    -1,   323,    -1,    -1,    -1,   327,    -1,
     329,     0,     1,    -1,     3,     4,     5,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    35,    -1,    -1,    38,
      39,    40,    41,    -1,    43,    44,    45,    46,    47,    48,
      -1,    50,    51,    52,    53,    54,    -1,    56,    57,    58,
      59,    -1,    -1,     0,    -1,    64,     3,     4,     5,    -1,
      -1,    -1,    -1,    -1,    73,    74,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    35,    -1,
      -1,    38,    39,    40,    -1,    -1,    43,    44,    45,    46,
      47,    48,    -1,    50,    51,    52,    53,    54,    -1,    56,
      57,    58,    59,    -1,    -1,    -1,    -1,    64,     3,     4,
       5,    -1,    -1,    -1,    -1,    -1,    73,    74,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    -1,
      35,    -1,    -1,    38,    39,    40,    -1,    -1,    43,    44,
      45,    46,    47,    48,    -1,    50,    51,    52,    53,    54,
      -1,    56,    57,    58,    59,    -1,    -1,    -1,    -1,    64,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    74,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
       6,     7,     8,     9,    10,    11,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,     6,     7,     8,     9,
      10,    11,    62,    63,    64,    65,    66,    67,    68,    69,
      -1,    71,    62,    63,    64,    65,    66,    67,    68,    69,
      -1,    71,    62,    63,    64,    65,    66,    67,    68,    69,
      -1,    71,    62,    63,    64,    65,    66,    67,    68,    69,
      -1,    71,    62,    63,    64,    65,    66,    67,    68,    69,
      -1,    71,    62,    63,    64,    65,    66,    67,    68,    69,
      -1,    71,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    65,    66,    67,    68,    69,    -1,    71,    63,    64,
      65,    66,    67,    68,    69,    -1,    71,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    63,    64,    65,    66,
      67,    68,    69,    -1,    71,    63,    64,    65,    66,    67,
      68,    69,    -1,    71,    63,    64,    65,    66,    67,    68,
      69,    -1,    71,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    64,    65,    66,    67,    68,    69,    -1,    71,    63,
      64,    65,    66,    67,    68,    69,    -1,    71,    63,    64,
      65,    66,    67,    68,    69,    -1,    71,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    63,    64,    65,    66,
      67,    68,    69,    -1,    71,    63,    64,    65,    66,    67,
      68,    69,    -1,    71,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,     6,     7,     8,     9,    10,    11,    -1,
      -1,    63,    64,    65,    66,    67,    68,    69,    -1,    71,
      63,    64,    65,    66,    67,    68,    69,    60,    71,    -1,
      63,    64,    65,    66,    67,    68,    69,    60,    -1,    -1,
      63,    64,    65,    66,    67,    68,    69,    60,    -1,    -1,
      63,    64,    65,    66,    67,    68,    69,    60,    -1,    -1,
      63,    64,    65,    66,    67,    68,    69,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    -1,    -1,    63,    64,    65,    66,    67,    68,
      69,    60,    -1,    -1,    63,    64,    65,    66,    67,    68,
      69,    60,    -1,    -1,    63,    64,    65,    66,    67,    68,
      69,    60,    -1,    -1,    63,    64,    65,    66,    67,    68,
      69,    60,    -1,    -1,    63,    64,    65,    66,    67,    68,
      69,     6,     7,     8,     9,    10,    11,    -1,     6,     7,
       8,     9,    10,    11,    -1,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,     6,
       7,     8,     9,    10,    11,    36,    -1,    -1,    -1,     6,
       7,     8,     9,    10,    11,    60,    -1,    -1,    63,    64,
      65,    66,    67,    68,    69,    63,    64,    65,    66,    67,
      68,    69,    63,    64,    65,    66,    67,    68,    69,    60,
      -1,    -1,    63,    64,    65,    66,    67,    68,    69,    -1,
      -1,    -1,    -1,    60,    -1,    -1,    63,    64,    65,    66,
      67,    68,    69,    60,    -1,    -1,    63,    64,    65,    66,
      67,    68,    69,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,     6,     7,     8,     9,    10,    11,    -1,
       6,     7,     8,     9,    10,    11,    -1,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    60,    -1,    -1,
      63,    64,    65,    66,    67,    68,    69,    60,    34,    -1,
      63,    64,    65,    66,    67,    68,    69,    60,    37,    -1,
      63,    64,    65,    66,    67,    68,    69,    60,    -1,    -1,
      63,    64,    65,    66,    67,    68,    69,    63,    64,    65,
      66,    67,    68,    69,    63,    64,    65,    66,    67,    68,
      69,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,     6,     7,     8,     9,    10,    11,    -1,    -1,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    37,     6,     7,     8,     9,    10,    11,    -1,
      -1,     6,     7,     8,     9,    10,    11,    -1,    -1,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    63,    64,
      65,    66,    67,    68,    69,    60,    -1,    -1,    63,    64,
      65,    66,    67,    68,    69,    62,    63,    64,    65,    66,
      67,    68,    69,     6,     7,     8,     9,    10,    11,    62,
      63,    64,    65,    66,    67,    68,    69,    62,    63,    64,
      65,    66,    67,    68,    69,    62,    63,    64,    65,    66,
      67,    68,    69,     6,     7,     8,     9,    10,    11,    -1,
      -1,     6,     7,     8,     9,    10,    11,    -1,    -1,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    62,
      63,    64,    65,    66,    67,    68,    69,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,
      63,    64,    65,    66,    67,    68,    69,    62,    63,    64,
      65,    66,    67,    68,    69,    62,    63,    64,    65,    66,
      67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,    68,
      69
  };

  const signed char
  genesyspp_parser::yystos_[] =
  {
       0,     1,    41,    76,    92,    73,     0,     3,     4,     5,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    35,    38,    39,    40,    43,    44,    45,    46,    47,
      48,    50,    51,    52,    53,    54,    56,    57,    58,    59,
      64,    73,    74,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    93,    94,    95,
      96,    97,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      38,    57,    93,    94,    61,    70,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    61,
      70,    61,    78,    78,    59,     6,     7,     8,     9,    10,
      11,    63,    64,    65,    66,    67,    68,    69,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    91,    78,    61,    61,    70,
      70,    78,    78,    39,    42,    42,    42,    42,    42,    55,
      49,    49,    49,    49,    49,    55,    78,    78,    78,    60,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    60,    60,    60,    71,    60,    60,
      60,    60,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    60,    71,    60,    78,    78,    78,    78,    62,    71,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      71,    71,    60,    62,    71,    62,    71,    60,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      62,    71,    62,    71,    36,    36,    70,    78,    38,     3,
      70,    78,    78,    60,    60,    60,    60,    60,    60,    60,
      71,    71,    71,    34,    78,    78,    78,    78,    78,    62,
      71,    60,    71,    78,    62,    71,    62,    71,    78,    78,
      78,    78,    62,    71,    62,    71,    37,    37,    70,    78,
      38,    70,    78,    78,    60,    71,    78,    78,    38,    57,
      96,    96,    78,    62,    60,    78,    62,    62,    78,    62,
      62,    61,    61,    70,    70,    60,    78,    78,    78,    78,
      62,    71,    62,    71,    78,    78,    62,    71,    62,    71,
      78,    78,    62,    62
  };

  const signed char
  genesyspp_parser::yyr1_[] =
  {
       0,    75,    76,    76,    76,    76,    76,    77,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    79,    79,
      80,    80,    80,    80,    80,    80,    80,    81,    81,    81,
      81,    81,    81,    81,    81,    82,    82,    83,    83,    84,
      84,    85,    85,    85,    85,    85,    85,    86,    86,    86,
      86,    87,    87,    88,    88,    88,    88,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    90,    91,
      91,    92,    93,    93,    93,    93,    94,    94,    94,    94,
      95,    95,    95,    95,    96,    96,    96,    96,    96,    96,
      96,    96,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97
  };

  const signed char
  genesyspp_parser::yyr2_[] =
  {
       0,     2,     0,     2,     2,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     4,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     1,     7,     5,     8,
       8,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     4,     4,     4,     4,     6,     1,     4,     6,
       6,     6,     6,     6,     6,     8,    10,     4,     4,     5,
       3,     1,     1,     4,     6,     8,     1,     4,     6,     8,
       1,     4,     6,     8,     3,     6,     8,    10,     3,     6,
       8,    10,     1,     4,     4,     4,     6,     8,     4,     4,
       4,     4,     4,     4,     4
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const genesyspp_parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "NUMD", "NUMH",
  "CTEZERO", "oLE", "oGE", "oEQ", "oNE", "oAND", "oOR", "oNOT", "fSIN",
  "fCOS", "fROUND", "fMOD", "fTRUNC", "fFRAC", "fEXP", "fRND1", "fEXPO",
  "fNORM", "fUNIF", "fWEIB", "fLOGN", "fGAMM", "fERLA", "fTRIA", "fBETA",
  "fDISC", "fTNOW", "fTFIN", "cIF", "cELSE", "cFOR", "cTO", "cDO", "ATRIB",
  "CSTAT", "fTAVG", "ILLEGAL", "RESOURCE", "fNR", "fMR", "fIRF",
  "fRESSEIZES", "fSTATE", "fSETSUM", "QUEUE", "fNQ", "fFIRSTINQ",
  "fLASTINQ", "fSAQUE", "fAQUE", "SET", "fNUMSET", "VARI", "FORM", "\"(\"",
  "\")\"", "\"[\"", "\"]\"", "\"+\"", "\"-\"", "\"*\"", "\"^\"", "\"/\"",
  "\"<\"", "\">\"", "\"=\"", "\",\"", "NEG", "'\\n'", "\"USER\"",
  "$accept", "input", "programa", "expressao", "numero", "aritmetica",
  "relacional", "comando", "comandoIF", "comandoFOR", "funcao",
  "funcaoKernel", "funcaoTrig", "funcaoArit", "funcaoProb", "funcaoUser",
  "listaparm", "illegal", "atributo", "variavel", "formula", "atribuicao",
  "funcaoPlugin", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  genesyspp_parser::yyrline_[] =
  {
       0,   196,   196,   197,   198,   199,   200,   203,   206,   207,
     208,   209,   210,   211,   212,   213,   216,   219,   224,   225,
     228,   229,   230,   231,   232,   233,   234,   237,   238,   239,
     240,   241,   242,   243,   244,   247,   248,   251,   252,   255,
     256,   259,   260,   261,   262,   263,   264,   267,   268,   269,
     270,   276,   277,   280,   281,   282,   283,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   301,   305,
     306,   309,   329,   338,   347,   356,   369,   370,   373,   376,
     384,   386,   389,   392,   400,   403,   407,   411,   417,   420,
     424,   428,   437,   440,   441,   442,   449,   454,   462,   463,
     464,   465,   466,   467,   483
  };

  void
  genesyspp_parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  genesyspp_parser::yy_reduce_print_ (int yyrule) const
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
#line 2589 "../GenesysParser.cpp"

#line 490 "bisonparser.yy"

void
yy::genesyspp_parser::error (const location_type& l,
                          const std::string& m)
{
  driver.error (l, m);
}
