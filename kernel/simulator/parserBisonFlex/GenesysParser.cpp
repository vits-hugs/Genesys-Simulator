// A Bison parser, made by GNU Bison 3.7.6.

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
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

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
      case symbol_kind::S_fSQRT: // fSQRT
      case symbol_kind::S_fLOG: // fLOG
      case symbol_kind::S_fLN: // fLN
      case symbol_kind::S_fVAL: // fVAL
      case symbol_kind::S_fEVAL: // fEVAL
      case symbol_kind::S_fLENG: // fLENG
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
      case symbol_kind::S_fMAXREP: // fMAXREP
      case symbol_kind::S_fNUMREP: // fNUMREP
      case symbol_kind::S_fIDENT: // fIDENT
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
      case symbol_kind::S_fRESUTIL: // fRESUTIL
      case symbol_kind::S_QUEUE: // QUEUE
      case symbol_kind::S_fNQ: // fNQ
      case symbol_kind::S_fFIRSTINQ: // fFIRSTINQ
      case symbol_kind::S_fLASTINQ: // fLASTINQ
      case symbol_kind::S_fSAQUE: // fSAQUE
      case symbol_kind::S_fAQUE: // fAQUE
      case symbol_kind::S_fENTATRANK: // fENTATRANK
      case symbol_kind::S_SET: // SET
      case symbol_kind::S_fNUMSET: // fNUMSET
      case symbol_kind::S_VARI: // VARI
      case symbol_kind::S_FORM: // FORM
      case symbol_kind::S_fNUMGR: // fNUMGR
      case symbol_kind::S_fATRGR: // fATRGR
      case symbol_kind::S_input: // input
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_numero: // numero
      case symbol_kind::S_aritmetica: // aritmetica
      case symbol_kind::S_relacional: // relacional
      case symbol_kind::S_comando: // comando
      case symbol_kind::S_comandoIF: // comandoIF
      case symbol_kind::S_comandoFOR: // comandoFOR
      case symbol_kind::S_function: // function
      case symbol_kind::S_kernelFunction: // kernelFunction
      case symbol_kind::S_trigonFunction: // trigonFunction
      case symbol_kind::S_mathFunction: // mathFunction
      case symbol_kind::S_probFunction: // probFunction
      case symbol_kind::S_userFunction: // userFunction
      case symbol_kind::S_listaparm: // listaparm
      case symbol_kind::S_atributo: // atributo
      case symbol_kind::S_variavel: // variavel
      case symbol_kind::S_formula: // formula
      case symbol_kind::S_atribuicao: // atribuicao
      case symbol_kind::S_pluginFunction: // pluginFunction
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
      case symbol_kind::S_fSQRT: // fSQRT
      case symbol_kind::S_fLOG: // fLOG
      case symbol_kind::S_fLN: // fLN
      case symbol_kind::S_fVAL: // fVAL
      case symbol_kind::S_fEVAL: // fEVAL
      case symbol_kind::S_fLENG: // fLENG
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
      case symbol_kind::S_fMAXREP: // fMAXREP
      case symbol_kind::S_fNUMREP: // fNUMREP
      case symbol_kind::S_fIDENT: // fIDENT
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
      case symbol_kind::S_fRESUTIL: // fRESUTIL
      case symbol_kind::S_QUEUE: // QUEUE
      case symbol_kind::S_fNQ: // fNQ
      case symbol_kind::S_fFIRSTINQ: // fFIRSTINQ
      case symbol_kind::S_fLASTINQ: // fLASTINQ
      case symbol_kind::S_fSAQUE: // fSAQUE
      case symbol_kind::S_fAQUE: // fAQUE
      case symbol_kind::S_fENTATRANK: // fENTATRANK
      case symbol_kind::S_SET: // SET
      case symbol_kind::S_fNUMSET: // fNUMSET
      case symbol_kind::S_VARI: // VARI
      case symbol_kind::S_FORM: // FORM
      case symbol_kind::S_fNUMGR: // fNUMGR
      case symbol_kind::S_fATRGR: // fATRGR
      case symbol_kind::S_input: // input
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_numero: // numero
      case symbol_kind::S_aritmetica: // aritmetica
      case symbol_kind::S_relacional: // relacional
      case symbol_kind::S_comando: // comando
      case symbol_kind::S_comandoIF: // comandoIF
      case symbol_kind::S_comandoFOR: // comandoFOR
      case symbol_kind::S_function: // function
      case symbol_kind::S_kernelFunction: // kernelFunction
      case symbol_kind::S_trigonFunction: // trigonFunction
      case symbol_kind::S_mathFunction: // mathFunction
      case symbol_kind::S_probFunction: // probFunction
      case symbol_kind::S_userFunction: // userFunction
      case symbol_kind::S_listaparm: // listaparm
      case symbol_kind::S_atributo: // atributo
      case symbol_kind::S_variavel: // variavel
      case symbol_kind::S_formula: // formula
      case symbol_kind::S_atribuicao: // atribuicao
      case symbol_kind::S_pluginFunction: // pluginFunction
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
      case symbol_kind::S_fSQRT: // fSQRT
      case symbol_kind::S_fLOG: // fLOG
      case symbol_kind::S_fLN: // fLN
      case symbol_kind::S_fVAL: // fVAL
      case symbol_kind::S_fEVAL: // fEVAL
      case symbol_kind::S_fLENG: // fLENG
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
      case symbol_kind::S_fMAXREP: // fMAXREP
      case symbol_kind::S_fNUMREP: // fNUMREP
      case symbol_kind::S_fIDENT: // fIDENT
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
      case symbol_kind::S_fRESUTIL: // fRESUTIL
      case symbol_kind::S_QUEUE: // QUEUE
      case symbol_kind::S_fNQ: // fNQ
      case symbol_kind::S_fFIRSTINQ: // fFIRSTINQ
      case symbol_kind::S_fLASTINQ: // fLASTINQ
      case symbol_kind::S_fSAQUE: // fSAQUE
      case symbol_kind::S_fAQUE: // fAQUE
      case symbol_kind::S_fENTATRANK: // fENTATRANK
      case symbol_kind::S_SET: // SET
      case symbol_kind::S_fNUMSET: // fNUMSET
      case symbol_kind::S_VARI: // VARI
      case symbol_kind::S_FORM: // FORM
      case symbol_kind::S_fNUMGR: // fNUMGR
      case symbol_kind::S_fATRGR: // fATRGR
      case symbol_kind::S_input: // input
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_numero: // numero
      case symbol_kind::S_aritmetica: // aritmetica
      case symbol_kind::S_relacional: // relacional
      case symbol_kind::S_comando: // comando
      case symbol_kind::S_comandoIF: // comandoIF
      case symbol_kind::S_comandoFOR: // comandoFOR
      case symbol_kind::S_function: // function
      case symbol_kind::S_kernelFunction: // kernelFunction
      case symbol_kind::S_trigonFunction: // trigonFunction
      case symbol_kind::S_mathFunction: // mathFunction
      case symbol_kind::S_probFunction: // probFunction
      case symbol_kind::S_userFunction: // userFunction
      case symbol_kind::S_listaparm: // listaparm
      case symbol_kind::S_atributo: // atributo
      case symbol_kind::S_variavel: // variavel
      case symbol_kind::S_formula: // formula
      case symbol_kind::S_atribuicao: // atribuicao
      case symbol_kind::S_pluginFunction: // pluginFunction
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
      case symbol_kind::S_fSQRT: // fSQRT
      case symbol_kind::S_fLOG: // fLOG
      case symbol_kind::S_fLN: // fLN
      case symbol_kind::S_fVAL: // fVAL
      case symbol_kind::S_fEVAL: // fEVAL
      case symbol_kind::S_fLENG: // fLENG
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
      case symbol_kind::S_fMAXREP: // fMAXREP
      case symbol_kind::S_fNUMREP: // fNUMREP
      case symbol_kind::S_fIDENT: // fIDENT
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
      case symbol_kind::S_fRESUTIL: // fRESUTIL
      case symbol_kind::S_QUEUE: // QUEUE
      case symbol_kind::S_fNQ: // fNQ
      case symbol_kind::S_fFIRSTINQ: // fFIRSTINQ
      case symbol_kind::S_fLASTINQ: // fLASTINQ
      case symbol_kind::S_fSAQUE: // fSAQUE
      case symbol_kind::S_fAQUE: // fAQUE
      case symbol_kind::S_fENTATRANK: // fENTATRANK
      case symbol_kind::S_SET: // SET
      case symbol_kind::S_fNUMSET: // fNUMSET
      case symbol_kind::S_VARI: // VARI
      case symbol_kind::S_FORM: // FORM
      case symbol_kind::S_fNUMGR: // fNUMGR
      case symbol_kind::S_fATRGR: // fATRGR
      case symbol_kind::S_input: // input
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_numero: // numero
      case symbol_kind::S_aritmetica: // aritmetica
      case symbol_kind::S_relacional: // relacional
      case symbol_kind::S_comando: // comando
      case symbol_kind::S_comandoIF: // comandoIF
      case symbol_kind::S_comandoFOR: // comandoFOR
      case symbol_kind::S_function: // function
      case symbol_kind::S_kernelFunction: // kernelFunction
      case symbol_kind::S_trigonFunction: // trigonFunction
      case symbol_kind::S_mathFunction: // mathFunction
      case symbol_kind::S_probFunction: // probFunction
      case symbol_kind::S_userFunction: // userFunction
      case symbol_kind::S_listaparm: // listaparm
      case symbol_kind::S_atributo: // atributo
      case symbol_kind::S_variavel: // variavel
      case symbol_kind::S_formula: // formula
      case symbol_kind::S_atribuicao: // atribuicao
      case symbol_kind::S_pluginFunction: // pluginFunction
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

#line 777 "../GenesysParser.cpp"


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
      case symbol_kind::S_fSQRT: // fSQRT
      case symbol_kind::S_fLOG: // fLOG
      case symbol_kind::S_fLN: // fLN
      case symbol_kind::S_fVAL: // fVAL
      case symbol_kind::S_fEVAL: // fEVAL
      case symbol_kind::S_fLENG: // fLENG
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
      case symbol_kind::S_fMAXREP: // fMAXREP
      case symbol_kind::S_fNUMREP: // fNUMREP
      case symbol_kind::S_fIDENT: // fIDENT
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
      case symbol_kind::S_fRESUTIL: // fRESUTIL
      case symbol_kind::S_QUEUE: // QUEUE
      case symbol_kind::S_fNQ: // fNQ
      case symbol_kind::S_fFIRSTINQ: // fFIRSTINQ
      case symbol_kind::S_fLASTINQ: // fLASTINQ
      case symbol_kind::S_fSAQUE: // fSAQUE
      case symbol_kind::S_fAQUE: // fAQUE
      case symbol_kind::S_fENTATRANK: // fENTATRANK
      case symbol_kind::S_SET: // SET
      case symbol_kind::S_fNUMSET: // fNUMSET
      case symbol_kind::S_VARI: // VARI
      case symbol_kind::S_FORM: // FORM
      case symbol_kind::S_fNUMGR: // fNUMGR
      case symbol_kind::S_fATRGR: // fATRGR
      case symbol_kind::S_input: // input
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_numero: // numero
      case symbol_kind::S_aritmetica: // aritmetica
      case symbol_kind::S_relacional: // relacional
      case symbol_kind::S_comando: // comando
      case symbol_kind::S_comandoIF: // comandoIF
      case symbol_kind::S_comandoFOR: // comandoFOR
      case symbol_kind::S_function: // function
      case symbol_kind::S_kernelFunction: // kernelFunction
      case symbol_kind::S_trigonFunction: // trigonFunction
      case symbol_kind::S_mathFunction: // mathFunction
      case symbol_kind::S_probFunction: // probFunction
      case symbol_kind::S_userFunction: // userFunction
      case symbol_kind::S_listaparm: // listaparm
      case symbol_kind::S_atributo: // atributo
      case symbol_kind::S_variavel: // variavel
      case symbol_kind::S_formula: // formula
      case symbol_kind::S_atribuicao: // atribuicao
      case symbol_kind::S_pluginFunction: // pluginFunction
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
  case 2: // input: expression
#line 212 "bisonparser.yy"
                    { driver.setResult(yystack_[0].value.as < obj_t > ().valor);}
#line 1007 "../GenesysParser.cpp"
    break;

  case 3: // input: error '\n'
#line 213 "bisonparser.yy"
                        { yyerrok; }
#line 1013 "../GenesysParser.cpp"
    break;

  case 4: // expression: numero
#line 217 "bisonparser.yy"
                                       {yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1019 "../GenesysParser.cpp"
    break;

  case 5: // expression: function
#line 218 "bisonparser.yy"
                                       {yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1025 "../GenesysParser.cpp"
    break;

  case 6: // expression: comando
#line 219 "bisonparser.yy"
                                       {yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1031 "../GenesysParser.cpp"
    break;

  case 7: // expression: atribuicao
#line 220 "bisonparser.yy"
                                       {yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1037 "../GenesysParser.cpp"
    break;

  case 8: // expression: aritmetica
#line 221 "bisonparser.yy"
                                           {yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1043 "../GenesysParser.cpp"
    break;

  case 9: // expression: relacional
#line 222 "bisonparser.yy"
                                       {yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1049 "../GenesysParser.cpp"
    break;

  case 10: // expression: "(" expression ")"
#line 223 "bisonparser.yy"
                                       {yylhs.value.as < obj_t > ().valor = yystack_[1].value.as < obj_t > ().valor;}
#line 1055 "../GenesysParser.cpp"
    break;

  case 11: // expression: atributo
#line 224 "bisonparser.yy"
                                       {yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1061 "../GenesysParser.cpp"
    break;

  case 12: // expression: variavel
#line 227 "bisonparser.yy"
                                       {yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1067 "../GenesysParser.cpp"
    break;

  case 13: // expression: formula
#line 230 "bisonparser.yy"
                                       {yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1073 "../GenesysParser.cpp"
    break;

  case 14: // numero: NUMD
#line 236 "bisonparser.yy"
              { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1079 "../GenesysParser.cpp"
    break;

  case 15: // numero: NUMH
#line 237 "bisonparser.yy"
              { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1085 "../GenesysParser.cpp"
    break;

  case 16: // aritmetica: expression "+" expression
#line 241 "bisonparser.yy"
                                     { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor + yystack_[0].value.as < obj_t > ().valor;}
#line 1091 "../GenesysParser.cpp"
    break;

  case 17: // aritmetica: expression "-" expression
#line 242 "bisonparser.yy"
                                     { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor - yystack_[0].value.as < obj_t > ().valor;}
#line 1097 "../GenesysParser.cpp"
    break;

  case 18: // aritmetica: expression "/" expression
#line 243 "bisonparser.yy"
                                     { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor / yystack_[0].value.as < obj_t > ().valor;}
#line 1103 "../GenesysParser.cpp"
    break;

  case 19: // aritmetica: expression "*" expression
#line 244 "bisonparser.yy"
                                     { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor * yystack_[0].value.as < obj_t > ().valor;}
#line 1109 "../GenesysParser.cpp"
    break;

  case 20: // aritmetica: expression "^" expression
#line 245 "bisonparser.yy"
                                     { yylhs.value.as < obj_t > ().valor = pow(yystack_[2].value.as < obj_t > ().valor,yystack_[0].value.as < obj_t > ().valor);}
#line 1115 "../GenesysParser.cpp"
    break;

  case 21: // aritmetica: "-" expression
#line 246 "bisonparser.yy"
                                     { yylhs.value.as < obj_t > ().valor = -yystack_[0].value.as < obj_t > ().valor;}
#line 1121 "../GenesysParser.cpp"
    break;

  case 22: // relacional: expression oAND expression
#line 250 "bisonparser.yy"
                                         { yylhs.value.as < obj_t > ().valor = (int) yystack_[2].value.as < obj_t > ().valor && (int) yystack_[0].value.as < obj_t > ().valor;}
#line 1127 "../GenesysParser.cpp"
    break;

  case 23: // relacional: expression oOR expression
#line 251 "bisonparser.yy"
                                         { yylhs.value.as < obj_t > ().valor = (int) yystack_[2].value.as < obj_t > ().valor || (int) yystack_[0].value.as < obj_t > ().valor;}
#line 1133 "../GenesysParser.cpp"
    break;

  case 24: // relacional: expression "<" expression
#line 252 "bisonparser.yy"
                                         { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor < yystack_[0].value.as < obj_t > ().valor ? 1 : 0;}
#line 1139 "../GenesysParser.cpp"
    break;

  case 25: // relacional: expression ">" expression
#line 253 "bisonparser.yy"
                                         { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor > yystack_[0].value.as < obj_t > ().valor ? 1 : 0;}
#line 1145 "../GenesysParser.cpp"
    break;

  case 26: // relacional: expression oLE expression
#line 254 "bisonparser.yy"
                                         { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor <= yystack_[0].value.as < obj_t > ().valor ? 1 : 0;}
#line 1151 "../GenesysParser.cpp"
    break;

  case 27: // relacional: expression oGE expression
#line 255 "bisonparser.yy"
                                         { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor >= yystack_[0].value.as < obj_t > ().valor ? 1 : 0;}
#line 1157 "../GenesysParser.cpp"
    break;

  case 28: // relacional: expression oEQ expression
#line 256 "bisonparser.yy"
                                         { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor == yystack_[0].value.as < obj_t > ().valor ? 1 : 0;}
#line 1163 "../GenesysParser.cpp"
    break;

  case 29: // relacional: expression oNE expression
#line 257 "bisonparser.yy"
                                         { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor != yystack_[0].value.as < obj_t > ().valor ? 1 : 0;}
#line 1169 "../GenesysParser.cpp"
    break;

  case 30: // comando: comandoIF
#line 261 "bisonparser.yy"
                    { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1175 "../GenesysParser.cpp"
    break;

  case 31: // comando: comandoFOR
#line 262 "bisonparser.yy"
                    { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1181 "../GenesysParser.cpp"
    break;

  case 32: // comandoIF: cIF "(" expression ")" expression cELSE expression
#line 266 "bisonparser.yy"
                                                           { yylhs.value.as < obj_t > ().valor = yystack_[4].value.as < obj_t > ().valor != 0 ? yystack_[2].value.as < obj_t > ().valor : yystack_[0].value.as < obj_t > ().valor; }
#line 1187 "../GenesysParser.cpp"
    break;

  case 33: // comandoIF: cIF "(" expression ")" expression
#line 267 "bisonparser.yy"
                                                          { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor != 0 ? yystack_[0].value.as < obj_t > ().valor : 0;}
#line 1193 "../GenesysParser.cpp"
    break;

  case 34: // comandoFOR: cFOR variavel "=" expression cTO expression cDO atribuicao
#line 272 "bisonparser.yy"
                                                                 {yylhs.value.as < obj_t > ().valor = 0; }
#line 1199 "../GenesysParser.cpp"
    break;

  case 35: // comandoFOR: cFOR atributo "=" expression cTO expression cDO atribuicao
#line 273 "bisonparser.yy"
                                                                  {yylhs.value.as < obj_t > ().valor = 0; }
#line 1205 "../GenesysParser.cpp"
    break;

  case 36: // function: mathFunction
#line 277 "bisonparser.yy"
                         { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1211 "../GenesysParser.cpp"
    break;

  case 37: // function: trigonFunction
#line 278 "bisonparser.yy"
                         { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1217 "../GenesysParser.cpp"
    break;

  case 38: // function: probFunction
#line 279 "bisonparser.yy"
                         { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1223 "../GenesysParser.cpp"
    break;

  case 39: // function: kernelFunction
#line 280 "bisonparser.yy"
                         { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1229 "../GenesysParser.cpp"
    break;

  case 40: // function: pluginFunction
#line 281 "bisonparser.yy"
                         { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1235 "../GenesysParser.cpp"
    break;

  case 41: // function: userFunction
#line 282 "bisonparser.yy"
                         { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1241 "../GenesysParser.cpp"
    break;

  case 42: // kernelFunction: fTNOW
#line 286 "bisonparser.yy"
                 { yylhs.value.as < obj_t > ().valor = driver.getModel()->getSimulation()->getSimulatedTime();}
#line 1247 "../GenesysParser.cpp"
    break;

  case 43: // kernelFunction: fTFIN
#line 287 "bisonparser.yy"
                 { yylhs.value.as < obj_t > ().valor = driver.getModel()->getSimulation()->getReplicationLength();}
#line 1253 "../GenesysParser.cpp"
    break;

  case 44: // kernelFunction: CSTAT
#line 288 "bisonparser.yy"
                         { yylhs.value.as < obj_t > ().valor = 0; }
#line 1259 "../GenesysParser.cpp"
    break;

  case 45: // kernelFunction: fTAVG "(" CSTAT ")"
#line 289 "bisonparser.yy"
                               {
                    StatisticsCollector* cstat = ((StatisticsCollector*)(driver.getModel()->getElements()->getElement(Util::TypeOf<StatisticsCollector>(), yystack_[1].value.as < obj_t > ().id)));
                    double value = cstat->getStatistics()->average();
                    yylhs.value.as < obj_t > ().valor = value; }
#line 1268 "../GenesysParser.cpp"
    break;

  case 46: // trigonFunction: fSIN "(" expression ")"
#line 296 "bisonparser.yy"
                                  { yylhs.value.as < obj_t > ().valor = sin(yystack_[1].value.as < obj_t > ().valor); }
#line 1274 "../GenesysParser.cpp"
    break;

  case 47: // trigonFunction: fCOS "(" expression ")"
#line 297 "bisonparser.yy"
                                  { yylhs.value.as < obj_t > ().valor = cos(yystack_[1].value.as < obj_t > ().valor); }
#line 1280 "../GenesysParser.cpp"
    break;

  case 48: // mathFunction: fROUND "(" expression ")"
#line 301 "bisonparser.yy"
                                        { yylhs.value.as < obj_t > ().valor = round(yystack_[1].value.as < obj_t > ().valor);}
#line 1286 "../GenesysParser.cpp"
    break;

  case 49: // mathFunction: fFRAC "(" expression ")"
#line 302 "bisonparser.yy"
                                        { yylhs.value.as < obj_t > ().valor = yystack_[1].value.as < obj_t > ().valor - (int) yystack_[1].value.as < obj_t > ().valor;}
#line 1292 "../GenesysParser.cpp"
    break;

  case 50: // mathFunction: fTRUNC "(" expression ")"
#line 303 "bisonparser.yy"
                                        { yylhs.value.as < obj_t > ().valor = trunc(yystack_[1].value.as < obj_t > ().valor);}
#line 1298 "../GenesysParser.cpp"
    break;

  case 51: // mathFunction: fEXP "(" expression ")"
#line 304 "bisonparser.yy"
                                    { yylhs.value.as < obj_t > ().valor = exp(yystack_[1].value.as < obj_t > ().valor);}
#line 1304 "../GenesysParser.cpp"
    break;

  case 52: // mathFunction: fSQRT "(" expression ")"
#line 305 "bisonparser.yy"
                                    { yylhs.value.as < obj_t > ().valor = sqrt(yystack_[1].value.as < obj_t > ().valor);}
#line 1310 "../GenesysParser.cpp"
    break;

  case 53: // mathFunction: fLOG "(" expression ")"
#line 306 "bisonparser.yy"
                                    { yylhs.value.as < obj_t > ().valor = log10(yystack_[1].value.as < obj_t > ().valor);}
#line 1316 "../GenesysParser.cpp"
    break;

  case 54: // mathFunction: fLN "(" expression ")"
#line 307 "bisonparser.yy"
                                    { yylhs.value.as < obj_t > ().valor = log(yystack_[1].value.as < obj_t > ().valor);}
#line 1322 "../GenesysParser.cpp"
    break;

  case 55: // mathFunction: fMOD "(" expression "," expression ")"
#line 308 "bisonparser.yy"
                                               { yylhs.value.as < obj_t > ().valor = (int) yystack_[3].value.as < obj_t > ().valor % (int) yystack_[1].value.as < obj_t > ().valor; }
#line 1328 "../GenesysParser.cpp"
    break;

  case 56: // probFunction: fRND1
#line 312 "bisonparser.yy"
                                                    { yylhs.value.as < obj_t > ().valor = driver.sampler()->sampleUniform(0.0,1.0);}
#line 1334 "../GenesysParser.cpp"
    break;

  case 57: // probFunction: fEXPO "(" expression ")"
#line 313 "bisonparser.yy"
                                     { yylhs.value.as < obj_t > ().valor = driver.sampler()->sampleExponential(yystack_[1].value.as < obj_t > ().valor);}
#line 1340 "../GenesysParser.cpp"
    break;

  case 58: // probFunction: fNORM "(" expression "," expression ")"
#line 314 "bisonparser.yy"
                                                { yylhs.value.as < obj_t > ().valor = driver.sampler()->sampleNormal(yystack_[3].value.as < obj_t > ().valor,yystack_[1].value.as < obj_t > ().valor);}
#line 1346 "../GenesysParser.cpp"
    break;

  case 59: // probFunction: fUNIF "(" expression "," expression ")"
#line 315 "bisonparser.yy"
                                                { yylhs.value.as < obj_t > ().valor = driver.sampler()->sampleUniform(yystack_[3].value.as < obj_t > ().valor,yystack_[1].value.as < obj_t > ().valor);}
#line 1352 "../GenesysParser.cpp"
    break;

  case 60: // probFunction: fWEIB "(" expression "," expression ")"
#line 316 "bisonparser.yy"
                                                { yylhs.value.as < obj_t > ().valor = driver.sampler()->sampleWeibull(yystack_[3].value.as < obj_t > ().valor,yystack_[1].value.as < obj_t > ().valor);}
#line 1358 "../GenesysParser.cpp"
    break;

  case 61: // probFunction: fLOGN "(" expression "," expression ")"
#line 317 "bisonparser.yy"
                                                { yylhs.value.as < obj_t > ().valor = driver.sampler()->sampleLogNormal(yystack_[3].value.as < obj_t > ().valor,yystack_[1].value.as < obj_t > ().valor);}
#line 1364 "../GenesysParser.cpp"
    break;

  case 62: // probFunction: fGAMM "(" expression "," expression ")"
#line 318 "bisonparser.yy"
                                                { yylhs.value.as < obj_t > ().valor = driver.sampler()->sampleGamma(yystack_[3].value.as < obj_t > ().valor,yystack_[1].value.as < obj_t > ().valor);}
#line 1370 "../GenesysParser.cpp"
    break;

  case 63: // probFunction: fERLA "(" expression "," expression ")"
#line 319 "bisonparser.yy"
                                                { yylhs.value.as < obj_t > ().valor = driver.sampler()->sampleErlang(yystack_[3].value.as < obj_t > ().valor,yystack_[1].value.as < obj_t > ().valor);}
#line 1376 "../GenesysParser.cpp"
    break;

  case 64: // probFunction: fTRIA "(" expression "," expression "," expression ")"
#line 320 "bisonparser.yy"
                                                                { yylhs.value.as < obj_t > ().valor = driver.sampler()->sampleTriangular(yystack_[5].value.as < obj_t > ().valor,yystack_[3].value.as < obj_t > ().valor,yystack_[1].value.as < obj_t > ().valor);}
#line 1382 "../GenesysParser.cpp"
    break;

  case 65: // probFunction: fBETA "(" expression "," expression "," expression "," expression ")"
#line 321 "bisonparser.yy"
                                                                              { yylhs.value.as < obj_t > ().valor = driver.sampler()->sampleBeta(yystack_[7].value.as < obj_t > ().valor,yystack_[5].value.as < obj_t > ().valor,yystack_[3].value.as < obj_t > ().valor,yystack_[1].value.as < obj_t > ().valor);}
#line 1388 "../GenesysParser.cpp"
    break;

  case 66: // probFunction: fDISC "(" listaparm ")"
#line 322 "bisonparser.yy"
      { yylhs.value.as < obj_t > () = yystack_[3].value.as < obj_t > (); }
#line 1394 "../GenesysParser.cpp"
    break;

  case 67: // userFunction: "USER" "(" expression ")"
#line 328 "bisonparser.yy"
                                        { yylhs.value.as < obj_t > ().valor = yystack_[1].value.as < obj_t > ().valor; }
#line 1400 "../GenesysParser.cpp"
    break;

  case 68: // listaparm: listaparm "," expression "," expression
#line 333 "bisonparser.yy"
      { yylhs.value.as < obj_t > () = yystack_[4].value.as < obj_t > (); }
#line 1406 "../GenesysParser.cpp"
    break;

  case 69: // listaparm: expression "," expression
#line 334 "bisonparser.yy"
      { yylhs.value.as < obj_t > () = yystack_[2].value.as < obj_t > (); }
#line 1412 "../GenesysParser.cpp"
    break;

  case 70: // atributo: ATRIB
#line 359 "bisonparser.yy"
                 {  
		    double attributeValue = 0.0;
		    if (driver.getModel()->getSimulation()->getCurrentEntity() != nullptr) {
			// it could crach because there may be no current entity, if the parse is running before simulation and therefore there is no CurrentEntity
			attributeValue = driver.getModel()->getSimulation()->getCurrentEntity()->getAttributeValue(yystack_[0].value.as < obj_t > ().id);
		    }
			//std::cout << "Passei" << std::endl;
		    yylhs.value.as < obj_t > ().valor = attributeValue; 
		}
#line 1426 "../GenesysParser.cpp"
    break;

  case 71: // atributo: ATRIB "[" expression "]"
#line 368 "bisonparser.yy"
                                              {  
		    double attributeValue = 0.0;
		    std::string index = std::to_string(static_cast<unsigned int>(yystack_[1].value.as < obj_t > ().valor));
		    if (driver.getModel()->getSimulation()->getCurrentEntity() != nullptr) {
			// it could crach because there may be no current entity, if the parse is running before simulation and therefore there is no CurrentEntity
			attributeValue = driver.getModel()->getSimulation()->getCurrentEntity()->getAttributeValue(index, yystack_[3].value.as < obj_t > ().id);
		    }
		    yylhs.value.as < obj_t > ().valor = attributeValue; 
		}
#line 1440 "../GenesysParser.cpp"
    break;

  case 72: // atributo: ATRIB "[" expression "," expression "]"
#line 377 "bisonparser.yy"
                                                             {  
		    double attributeValue = 0.0;
		    std::string index = std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[1].value.as < obj_t > ().valor));
		    if (driver.getModel()->getSimulation()->getCurrentEntity() != nullptr) {
			// it could crach because there may be no current entity, if the parse is running before simulation and therefore there is no CurrentEntity
			attributeValue = driver.getModel()->getSimulation()->getCurrentEntity()->getAttributeValue(index, yystack_[5].value.as < obj_t > ().id);
		    }
		    yylhs.value.as < obj_t > ().valor = attributeValue; 
		}
#line 1454 "../GenesysParser.cpp"
    break;

  case 73: // atributo: ATRIB "[" expression "," expression "," expression "]"
#line 386 "bisonparser.yy"
                                                                            {  
		    double attributeValue = 0.0;
		    std::string index = std::to_string(static_cast<unsigned int>(yystack_[5].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[1].value.as < obj_t > ().valor));
		    if (driver.getModel()->getSimulation()->getCurrentEntity() != nullptr) {
			// it could crach because there may be no current entity, if the parse is running before simulation and therefore there is no CurrentEntity
			attributeValue = driver.getModel()->getSimulation()->getCurrentEntity()->getAttributeValue(index, yystack_[7].value.as < obj_t > ().id);
		    }
		    yylhs.value.as < obj_t > ().valor = attributeValue; 
		}
#line 1468 "../GenesysParser.cpp"
    break;

  case 74: // variavel: VARI
#line 399 "bisonparser.yy"
                    {yylhs.value.as < obj_t > ().valor = ((Variable*)(driver.getModel()->getElements()->getElement(Util::TypeOf<Variable>(), yystack_[0].value.as < obj_t > ().id)))->value();}
#line 1474 "../GenesysParser.cpp"
    break;

  case 75: // variavel: VARI "[" expression "]"
#line 400 "bisonparser.yy"
                                                    { 
                std::string index = std::to_string(static_cast<unsigned int>(yystack_[1].value.as < obj_t > ().valor));
                yylhs.value.as < obj_t > ().valor = ((Variable*)(driver.getModel()->getElements()->getElement(Util::TypeOf<Variable>(), yystack_[3].value.as < obj_t > ().id)))->value(index); }
#line 1482 "../GenesysParser.cpp"
    break;

  case 76: // variavel: VARI "[" expression "," expression "]"
#line 403 "bisonparser.yy"
                                                                    { 
                std::string index = std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[1].value.as < obj_t > ().valor)); 
                yylhs.value.as < obj_t > ().valor = ((Variable*)(driver.getModel()->getElements()->getElement(Util::TypeOf<Variable>(), yystack_[5].value.as < obj_t > ().id)))->value(index);}
#line 1490 "../GenesysParser.cpp"
    break;

  case 77: // variavel: VARI "[" expression "," expression "," expression "]"
#line 406 "bisonparser.yy"
                                                                                 { 
                std::string index = std::to_string(static_cast<unsigned int>(yystack_[5].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[1].value.as < obj_t > ().valor));
                yylhs.value.as < obj_t > ().valor = ((Variable*)(driver.getModel()->getElements()->getElement(Util::TypeOf<Variable>(), yystack_[7].value.as < obj_t > ().id)))->value(index);}
#line 1498 "../GenesysParser.cpp"
    break;

  case 78: // formula: FORM
#line 414 "bisonparser.yy"
                            { 
                yylhs.value.as < obj_t > ().valor = ((Formula*)(driver.getModel()->getElements()->getElement(Util::TypeOf<Formula>(), yystack_[0].value.as < obj_t > ().id)))->value();}
#line 1505 "../GenesysParser.cpp"
    break;

  case 79: // formula: FORM "[" expression "]"
#line 416 "bisonparser.yy"
                                                {
                std::string index = std::to_string(static_cast<unsigned int>(yystack_[1].value.as < obj_t > ().valor));
                yylhs.value.as < obj_t > ().valor = ((Formula*)(driver.getModel()->getElements()->getElement(Util::TypeOf<Formula>(), yystack_[3].value.as < obj_t > ().id)))->value(index);}
#line 1513 "../GenesysParser.cpp"
    break;

  case 80: // formula: FORM "[" expression "," expression "]"
#line 419 "bisonparser.yy"
                                                               {
                std::string index = std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor)) +","+std::to_string(static_cast<unsigned int>(yystack_[1].value.as < obj_t > ().valor));
                yylhs.value.as < obj_t > ().valor = ((Formula*)(driver.getModel()->getElements()->getElement(Util::TypeOf<Formula>(), yystack_[5].value.as < obj_t > ().id)))->value(index);}
#line 1521 "../GenesysParser.cpp"
    break;

  case 81: // formula: FORM "[" expression "," expression "," expression "]"
#line 422 "bisonparser.yy"
                                                                              {
                std::string index = std::to_string(static_cast<unsigned int>(yystack_[5].value.as < obj_t > ().valor)) +","+std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[1].value.as < obj_t > ().valor));
                yylhs.value.as < obj_t > ().valor = ((Formula*)(driver.getModel()->getElements()->getElement(Util::TypeOf<Formula>(), yystack_[7].value.as < obj_t > ().id)))->value(index);}
#line 1529 "../GenesysParser.cpp"
    break;

  case 82: // atribuicao: ATRIB "=" expression
#line 430 "bisonparser.yy"
                                         { 
                driver.getModel()->getSimulation()->getCurrentEntity()->setAttributeValue("", yystack_[2].value.as < obj_t > ().id, yystack_[0].value.as < obj_t > ().valor);
                yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1537 "../GenesysParser.cpp"
    break;

  case 83: // atribuicao: ATRIB "[" expression "]" "=" expression
#line 433 "bisonparser.yy"
                                                                      { 
                std::string index = std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor));
                driver.getModel()->getSimulation()->getCurrentEntity()->setAttributeValue(index, yystack_[5].value.as < obj_t > ().id, yystack_[0].value.as < obj_t > ().valor);
                yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1546 "../GenesysParser.cpp"
    break;

  case 84: // atribuicao: ATRIB "[" expression "," expression "]" "=" expression
#line 437 "bisonparser.yy"
                                                                                    {
                std::string index = std::to_string(static_cast<unsigned int>(yystack_[5].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor)); 
                driver.getModel()->getSimulation()->getCurrentEntity()->setAttributeValue(index, yystack_[7].value.as < obj_t > ().id, yystack_[0].value.as < obj_t > ().valor); 
                yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1555 "../GenesysParser.cpp"
    break;

  case 85: // atribuicao: ATRIB "[" expression "," expression "," expression "]" "=" expression
#line 441 "bisonparser.yy"
                                                                                                      {
                std::string index = std::to_string(static_cast<unsigned int>(yystack_[7].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[5].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor));
                driver.getModel()->getSimulation()->getCurrentEntity()->setAttributeValue(index, yystack_[9].value.as < obj_t > ().id, yystack_[0].value.as < obj_t > ().valor);
                yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1564 "../GenesysParser.cpp"
    break;

  case 86: // atribuicao: VARI "=" expression
#line 447 "bisonparser.yy"
                                            {
                ((Variable*)(driver.getModel()->getElements()->getElement(Util::TypeOf<Variable>(), yystack_[2].value.as < obj_t > ().id)))->setValue(yystack_[0].value.as < obj_t > ().valor);
                yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1572 "../GenesysParser.cpp"
    break;

  case 87: // atribuicao: VARI "[" expression "]" "=" expression
#line 450 "bisonparser.yy"
                                                                     { 
                std::string index = std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor));
                ((Variable*)(driver.getModel()->getElements()->getElement(Util::TypeOf<Variable>(), yystack_[5].value.as < obj_t > ().id)))->setValue(index, yystack_[0].value.as < obj_t > ().valor); 
                yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1581 "../GenesysParser.cpp"
    break;

  case 88: // atribuicao: VARI "[" expression "," expression "]" "=" expression
#line 454 "bisonparser.yy"
                                                                                   {
                std::string index = std::to_string(static_cast<unsigned int>(yystack_[5].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor)); 
                ((Variable*)(driver.getModel()->getElements()->getElement(Util::TypeOf<Variable>(), yystack_[7].value.as < obj_t > ().id)))->setValue(index, yystack_[0].value.as < obj_t > ().valor);
                yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1590 "../GenesysParser.cpp"
    break;

  case 89: // atribuicao: VARI "[" expression "," expression "," expression "]" "=" expression
#line 458 "bisonparser.yy"
                                                                                                     {
                std::string index = std::to_string(static_cast<unsigned int>(yystack_[7].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[5].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor));
                ((Variable*)(driver.getModel()->getElements()->getElement(Util::TypeOf<Variable>(), yystack_[9].value.as < obj_t > ().id)))->setValue(index, yystack_[0].value.as < obj_t > ().valor); 
                yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1599 "../GenesysParser.cpp"
    break;

  case 90: // pluginFunction: CTEZERO
#line 468 "bisonparser.yy"
                                                     { yylhs.value.as < obj_t > ().valor = 0; }
#line 1605 "../GenesysParser.cpp"
    break;

  case 91: // pluginFunction: fNQ "(" QUEUE ")"
#line 471 "bisonparser.yy"
                                    {   //std::cout << "Queue ID: " << $3.id << ", Size: " << ((Queue*)(driver.getModel()->getElements()->getElement(Util::TypeOf<Queue>(), $3.id)))->size() << std::endl; 
                                        yylhs.value.as < obj_t > ().valor = ((Queue*)(driver.getModel()->getElements()->getElement(Util::TypeOf<Queue>(), yystack_[1].value.as < obj_t > ().id)))->size();}
#line 1612 "../GenesysParser.cpp"
    break;

  case 92: // pluginFunction: fLASTINQ "(" QUEUE ")"
#line 473 "bisonparser.yy"
                                    {/*For now does nothing because need acces to list of QUEUE, or at least the last element*/ }
#line 1618 "../GenesysParser.cpp"
    break;

  case 93: // pluginFunction: fFIRSTINQ "(" QUEUE ")"
#line 474 "bisonparser.yy"
                                    { 
                if (((Queue*)(driver.getModel()->getElements()->getElement(Util::TypeOf<Queue>(), yystack_[1].value.as < obj_t > ().id)))->size() > 0){
                    //id da 1a entidade da fila, talvez pegar nome
                    yylhs.value.as < obj_t > ().valor = ((Queue*)(driver.getModel()->getElements()->getElement(Util::TypeOf<Queue>(), yystack_[1].value.as < obj_t > ().id)))->first()->getEntity()->getId();
                }else{
                    yylhs.value.as < obj_t > ().valor = 0;
                } }
#line 1630 "../GenesysParser.cpp"
    break;

  case 94: // pluginFunction: fSAQUE "(" QUEUE "," ATRIB ")"
#line 481 "bisonparser.yy"
                                       {   
                Util::identification queueID = yystack_[3].value.as < obj_t > ().id;
                Util::identification attrID = yystack_[1].value.as < obj_t > ().id;
                double sum = ((Queue*)(driver.getModel()->getElements()->getElement(Util::TypeOf<Queue>(), yystack_[3].value.as < obj_t > ().id)))->sumAttributesFromWaiting(attrID);
                yylhs.value.as < obj_t > ().valor = sum; }
#line 1640 "../GenesysParser.cpp"
    break;

  case 95: // pluginFunction: fAQUE "(" QUEUE "," NUMD "," ATRIB ")"
#line 486 "bisonparser.yy"
                                             {
                Util::identification queueID = yystack_[5].value.as < obj_t > ().id;
                Util::identification attrID = yystack_[1].value.as < obj_t > ().id;
                double value = ((Queue*)(driver.getModel()->getElements()->getElement(Util::TypeOf<Queue>(), yystack_[5].value.as < obj_t > ().id)))->getAttributeFromWaitingRank(yystack_[3].value.as < obj_t > ().valor-1, attrID); // rank starts on 0 in genesys
                yylhs.value.as < obj_t > ().valor = value; }
#line 1650 "../GenesysParser.cpp"
    break;

  case 96: // pluginFunction: fMR "(" RESOURCE ")"
#line 494 "bisonparser.yy"
                                        { yylhs.value.as < obj_t > ().valor = ((Resource*)driver.getModel()->getElements()->getElement(Util::TypeOf<Resource>(), yystack_[1].value.as < obj_t > ().id))->getCapacity();}
#line 1656 "../GenesysParser.cpp"
    break;

  case 97: // pluginFunction: fNR "(" RESOURCE ")"
#line 495 "bisonparser.yy"
                                         { yylhs.value.as < obj_t > ().valor = ((Resource*)driver.getModel()->getElements()->getElement(Util::TypeOf<Resource>(), yystack_[1].value.as < obj_t > ().id))->getNumberBusy();}
#line 1662 "../GenesysParser.cpp"
    break;

  case 98: // pluginFunction: fRESSEIZES "(" RESOURCE ")"
#line 496 "bisonparser.yy"
                                         { /*For now does nothing because needs get Seizes, check with teacher*/}
#line 1668 "../GenesysParser.cpp"
    break;

  case 99: // pluginFunction: fSTATE "(" RESOURCE ")"
#line 497 "bisonparser.yy"
                                         {  yylhs.value.as < obj_t > ().valor = static_cast<int>(((Resource*)driver.getModel()->getElements()->getElement(Util::TypeOf<Resource>(), yystack_[1].value.as < obj_t > ().id))->getResourceState()); }
#line 1674 "../GenesysParser.cpp"
    break;

  case 100: // pluginFunction: fIRF "(" RESOURCE ")"
#line 498 "bisonparser.yy"
                                         { yylhs.value.as < obj_t > ().valor = ((Resource*)driver.getModel()->getElements()->getElement(Util::TypeOf<Resource>(), yystack_[1].value.as < obj_t > ().id))->getResourceState() == Resource::ResourceState::FAILED ? 1 : 0; }
#line 1680 "../GenesysParser.cpp"
    break;

  case 101: // pluginFunction: fSETSUM "(" SET ")"
#line 499 "bisonparser.yy"
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
#line 1698 "../GenesysParser.cpp"
    break;

  case 102: // pluginFunction: fNUMSET "(" SET ")"
#line 515 "bisonparser.yy"
                                { yylhs.value.as < obj_t > ().valor = ((Set*)driver.getModel()->getElements()->getElement(Util::TypeOf<Set>(),yystack_[1].value.as < obj_t > ().id))->getElementSet()->size(); }
#line 1704 "../GenesysParser.cpp"
    break;


#line 1708 "../GenesysParser.cpp"

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


  const short genesyspp_parser::yypact_ninf_ = -238;

  const signed char genesyspp_parser::yytable_ninf_ = -1;

  const short
  genesyspp_parser::yypact_[] =
  {
     282,   -64,  -238,  -238,  -238,   -28,    -3,    21,    22,    23,
      24,    25,    26,    27,    29,  -238,    30,    31,    32,    37,
      38,    39,    40,    41,    42,    43,  -238,  -238,    45,    -2,
     -63,  -238,    46,    55,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    74,    75,   -62,    76,   357,   357,    77,
     116,  1529,  -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,
    -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,
     357,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     357,    78,    88,    82,    83,   357,   357,   100,   117,   118,
     120,   121,   122,    85,   108,   115,   119,   123,   124,   109,
     357,   357,   357,   874,    97,   357,  -238,   357,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     884,   894,   904,   607,   981,   991,  1001,  1011,  1021,  1031,
    1041,   616,   625,   704,   713,   722,   731,   740,   749,   758,
     -71,  1118,   357,   357,   357,   357,     8,  1529,   104,   106,
     107,   111,   113,   125,   126,   127,   128,   130,   110,   112,
     135,    44,  1529,   182,  -238,  1128,   -73,   -73,   -73,   -73,
      53,    53,   -70,   -70,    97,  1529,    97,   -73,   -73,  -238,
    -238,  -238,   357,  -238,  -238,  -238,  -238,  -238,  -238,  -238,
     357,   357,   357,   357,   357,   357,   357,   357,   357,  -238,
     357,   357,   429,   439,  1135,  1142,    98,   357,  -238,  -238,
    -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,   148,   194,
    -238,   129,   357,  -238,   357,  -238,  1152,  1162,  1175,  1252,
    1262,  1272,  1282,   767,   846,  1529,   855,  1293,  -238,   357,
    -238,   357,   357,   357,   357,   449,   136,   131,   357,   459,
     469,  -238,  -238,  -238,  -238,  -238,  -238,  -238,   357,   357,
     357,   357,   479,   489,  1300,  1310,  1529,   133,   357,  -238,
     163,  1529,   134,   357,  -238,   357,  1387,   864,  1529,   -73,
    -238,   357,  -238,   357,    -1,    -1,   357,  1395,   140,   357,
    1403,  1411,  -238,   357,  1419,  1427,   -27,    17,  -238,  -238,
    1529,   137,  -238,  1529,   142,  -238,  1437,  -238,  -238,   357,
     357,   357,   357,  -238,   568,   578,  1529,  1529,    98,   357,
     129,   357,   588,   598,   133,   357,   134,   357,  1445,  1522,
     137,   142
  };

  const signed char
  genesyspp_parser::yydefact_[] =
  {
       0,     0,    14,    15,    90,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    56,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    42,    43,     0,     0,
      70,    44,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    74,    78,     0,     0,     0,
       0,     2,     4,     8,     9,     6,    30,    31,     5,    39,
      37,    36,    38,    41,    11,    12,    13,     7,    40,     3,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    70,    74,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    21,     0,     1,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    82,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    86,     0,    10,     0,    26,    27,    28,    29,
      22,    23,    16,    17,    19,    20,    18,    24,    25,    46,
      47,    48,     0,    50,    49,    51,    52,    53,    54,    57,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    66,
       0,     0,     0,     0,     0,     0,    71,     0,    45,    97,
      96,   100,    98,    99,   101,    91,    93,    92,     0,     0,
     102,    75,     0,    79,     0,    67,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    69,     0,    33,    71,     0,
      75,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    55,    58,    59,    60,    61,    62,    63,     0,     0,
       0,     0,     0,     0,     0,     0,    83,    72,     0,    94,
       0,    87,    76,     0,    80,     0,     0,     0,    68,    32,
      72,     0,    76,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    64,     0,     0,     0,     0,     0,    35,    34,
      84,    73,    95,    88,    77,    81,     0,    73,    77,     0,
       0,     0,     0,    65,     0,     0,    85,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0
  };

  const short
  genesyspp_parser::yypgoto_[] =
  {
    -238,  -238,   -47,  -238,  -238,  -238,  -238,  -238,  -238,  -238,
    -238,  -238,  -238,  -238,  -238,  -238,   185,   189,  -238,  -237,
    -238
  };

  const unsigned char
  genesyspp_parser::yydefgoto_[] =
  {
       0,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,   150,    64,    65,    66,    67,
      68
  };

  const short
  genesyspp_parser::yytable_[] =
  {
     113,   114,   209,   123,   124,   125,   126,   127,   125,   126,
     127,    95,   110,   210,   117,   118,   119,   120,   121,   122,
      96,   111,    69,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   151,    70,    91,   306,   319,   156,   157,
     117,   118,   119,   120,   121,   122,    96,   308,   309,   117,
     118,   119,   120,   171,   172,   173,    92,   307,   175,    71,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   216,   123,   124,   125,   126,   127,   128,
     129,   320,   217,    72,    73,    74,    75,    76,    77,    78,
     111,    79,    80,    81,    82,   212,   213,   214,   215,    83,
      84,    85,    86,    87,    88,    89,   116,    90,    97,   231,
     123,   124,   125,   126,   127,   128,   129,    98,   232,   123,
     124,   125,   126,   127,   128,   129,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   236,   108,   109,   158,   115,
     112,   164,   152,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   153,   246,   247,   154,   155,   165,   159,   160,
     255,   161,   162,   163,   166,   170,   126,   218,   167,   219,
     220,   254,   168,   169,   221,   259,   222,   260,   117,   118,
     119,   120,   121,   122,   228,   256,   229,   257,   223,   224,
     225,   226,   272,   227,   273,   274,   275,   276,   230,   279,
     298,   281,   258,   312,    93,   280,   296,   299,    94,     0,
     321,   286,   287,   288,   289,   322,     0,     0,     0,     0,
       0,   297,     0,     0,     0,     0,   300,     0,   301,     0,
       0,     0,     0,     0,   304,     0,   305,     0,     0,   310,
       0,     0,   313,     0,     0,     0,   316,   233,   123,   124,
     125,   126,   127,   128,   129,     0,   234,     0,     0,     0,
       0,     0,   324,   325,   326,   327,     0,     0,     0,     0,
       0,     0,   332,     1,   333,     2,     3,     4,   338,     0,
     339,     0,     0,     0,     0,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,     0,     0,     0,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,     0,     0,     0,    28,     0,    29,     0,     0,    30,
      31,    32,     0,     0,    33,    34,    35,    36,    37,    38,
       0,     0,    39,    40,    41,    42,    43,     0,     0,    44,
      45,    46,     0,     0,    47,     0,     0,     0,     0,    48,
       2,     3,     4,     0,     0,     0,     0,     0,     0,    49,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
       0,     0,     0,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,     0,     0,     0,    28,
       0,    29,     0,     0,    30,    31,    32,     0,     0,    33,
      34,    35,    36,    37,    38,     0,     0,    39,    40,    41,
      42,    43,     0,     0,    44,    45,    46,     0,     0,    47,
       0,     0,     0,     0,    48,   117,   118,   119,   120,   121,
     122,     0,     0,     0,    49,   117,   118,   119,   120,   121,
     122,     0,     0,     0,     0,   117,   118,   119,   120,   121,
     122,     0,     0,     0,     0,   117,   118,   119,   120,   121,
     122,     0,     0,     0,     0,   117,   118,   119,   120,   121,
     122,     0,     0,     0,     0,   117,   118,   119,   120,   121,
     122,     0,     0,     0,     0,   117,   118,   119,   120,   121,
     122,     0,     0,     0,   248,   123,   124,   125,   126,   127,
     128,   129,     0,   249,   250,   123,   124,   125,   126,   127,
     128,   129,     0,   251,   277,   123,   124,   125,   126,   127,
     128,   129,     0,   278,   282,   123,   124,   125,   126,   127,
     128,   129,     0,   283,   284,   123,   124,   125,   126,   127,
     128,   129,     0,   285,   290,   123,   124,   125,   126,   127,
     128,   129,     0,   291,   292,   123,   124,   125,   126,   127,
     128,   129,     0,   293,   117,   118,   119,   120,   121,   122,
       0,     0,     0,     0,   117,   118,   119,   120,   121,   122,
       0,     0,     0,     0,   117,   118,   119,   120,   121,   122,
       0,     0,     0,     0,   117,   118,   119,   120,   121,   122,
       0,     0,     0,   117,   118,   119,   120,   121,   122,     0,
       0,     0,   117,   118,   119,   120,   121,   122,     0,     0,
       0,   117,   118,   119,   120,   121,   122,     0,     0,     0,
       0,     0,     0,   328,   123,   124,   125,   126,   127,   128,
     129,     0,   329,   330,   123,   124,   125,   126,   127,   128,
     129,     0,   331,   334,   123,   124,   125,   126,   127,   128,
     129,     0,   335,   336,   123,   124,   125,   126,   127,   128,
     129,     0,   337,   123,   124,   125,   126,   127,   128,   129,
       0,   192,   123,   124,   125,   126,   127,   128,   129,     0,
     200,   123,   124,   125,   126,   127,   128,   129,     0,   201,
     117,   118,   119,   120,   121,   122,     0,     0,     0,   117,
     118,   119,   120,   121,   122,     0,     0,     0,   117,   118,
     119,   120,   121,   122,     0,     0,     0,   117,   118,   119,
     120,   121,   122,     0,     0,     0,   117,   118,   119,   120,
     121,   122,     0,     0,     0,   117,   118,   119,   120,   121,
     122,     0,     0,     0,   117,   118,   119,   120,   121,   122,
       0,     0,     0,   117,   118,   119,   120,   121,   122,     0,
     123,   124,   125,   126,   127,   128,   129,     0,   202,   123,
     124,   125,   126,   127,   128,   129,     0,   203,   123,   124,
     125,   126,   127,   128,   129,     0,   204,   123,   124,   125,
     126,   127,   128,   129,     0,   205,   123,   124,   125,   126,
     127,   128,   129,     0,   206,   123,   124,   125,   126,   127,
     128,   129,     0,   207,   123,   124,   125,   126,   127,   128,
     129,     0,   208,   123,   124,   125,   126,   127,   128,   129,
       0,   268,   117,   118,   119,   120,   121,   122,     0,     0,
       0,   117,   118,   119,   120,   121,   122,     0,     0,     0,
     117,   118,   119,   120,   121,   122,     0,     0,     0,     0,
     117,   118,   119,   120,   121,   122,     0,     0,     0,     0,
     117,   118,   119,   120,   121,   122,     0,     0,     0,     0,
     117,   118,   119,   120,   121,   122,     0,     0,     0,     0,
     117,   118,   119,   120,   121,   122,     0,     0,     0,     0,
       0,     0,   123,   124,   125,   126,   127,   128,   129,     0,
     269,   123,   124,   125,   126,   127,   128,   129,     0,   270,
     123,   124,   125,   126,   127,   128,   129,   174,   303,     0,
     123,   124,   125,   126,   127,   128,   129,   189,     0,     0,
     123,   124,   125,   126,   127,   128,   129,   190,     0,     0,
     123,   124,   125,   126,   127,   128,   129,   191,     0,     0,
     123,   124,   125,   126,   127,   128,   129,   117,   118,   119,
     120,   121,   122,     0,     0,     0,     0,   117,   118,   119,
     120,   121,   122,     0,     0,     0,     0,   117,   118,   119,
     120,   121,   122,     0,     0,     0,     0,   117,   118,   119,
     120,   121,   122,     0,     0,     0,     0,   117,   118,   119,
     120,   121,   122,     0,     0,     0,     0,   117,   118,   119,
     120,   121,   122,     0,     0,     0,     0,   117,   118,   119,
     120,   121,   122,     0,   193,     0,     0,   123,   124,   125,
     126,   127,   128,   129,   194,     0,     0,   123,   124,   125,
     126,   127,   128,   129,   195,     0,     0,   123,   124,   125,
     126,   127,   128,   129,   196,     0,     0,   123,   124,   125,
     126,   127,   128,   129,   197,     0,     0,   123,   124,   125,
     126,   127,   128,   129,   198,     0,     0,   123,   124,   125,
     126,   127,   128,   129,   199,     0,     0,   123,   124,   125,
     126,   127,   128,   129,   117,   118,   119,   120,   121,   122,
       0,     0,     0,     0,   117,   118,   119,   120,   121,   122,
       0,   117,   118,   119,   120,   121,   122,     0,   117,   118,
     119,   120,   121,   122,     0,     0,     0,     0,   117,   118,
     119,   120,   121,   122,     0,     0,     0,     0,   117,   118,
     119,   120,   121,   122,     0,     0,     0,     0,     0,     0,
     252,   117,   118,   119,   120,   121,   122,   253,     0,     0,
       0,   211,     0,     0,   123,   124,   125,   126,   127,   128,
     129,   235,     0,     0,   123,   124,   125,   126,   127,   128,
     129,   123,   124,   125,   126,   127,   128,   129,   123,   124,
     125,   126,   127,   128,   129,   261,     0,     0,   123,   124,
     125,   126,   127,   128,   129,   262,     0,     0,   123,   124,
     125,   126,   127,   128,   129,     0,     0,     0,   263,     0,
       0,   123,   124,   125,   126,   127,   128,   129,   117,   118,
     119,   120,   121,   122,     0,     0,     0,     0,   117,   118,
     119,   120,   121,   122,     0,     0,     0,     0,   117,   118,
     119,   120,   121,   122,     0,     0,     0,     0,   117,   118,
     119,   120,   121,   122,     0,     0,     0,     0,     0,   117,
     118,   119,   120,   121,   122,     0,   117,   118,   119,   120,
     121,   122,     0,     0,     0,     0,   117,   118,   119,   120,
     121,   122,     0,     0,     0,   264,     0,     0,   123,   124,
     125,   126,   127,   128,   129,   265,   271,     0,   123,   124,
     125,   126,   127,   128,   129,   266,   294,     0,   123,   124,
     125,   126,   127,   128,   129,   267,   295,     0,   123,   124,
     125,   126,   127,   128,   129,     0,     0,     0,     0,   123,
     124,   125,   126,   127,   128,   129,   123,   124,   125,   126,
     127,   128,   129,     0,     0,     0,   123,   124,   125,   126,
     127,   128,   129,   117,   118,   119,   120,   121,   122,     0,
       0,   117,   118,   119,   120,   121,   122,     0,     0,   117,
     118,   119,   120,   121,   122,     0,     0,   117,   118,   119,
     120,   121,   122,     0,     0,   117,   118,   119,   120,   121,
     122,     0,     0,   117,   118,   119,   120,   121,   122,     0,
       0,     0,     0,   117,   118,   119,   120,   121,   122,     0,
       0,   117,   118,   119,   120,   121,   122,     0,     0,     0,
     302,     0,     0,   123,   124,   125,   126,   127,   128,   129,
     311,   123,   124,   125,   126,   127,   128,   129,   314,   123,
     124,   125,   126,   127,   128,   129,   315,   123,   124,   125,
     126,   127,   128,   129,   317,   123,   124,   125,   126,   127,
     128,   129,   318,   123,   124,   125,   126,   127,   128,   129,
     323,     0,     0,   123,   124,   125,   126,   127,   128,   129,
     340,   123,   124,   125,   126,   127,   128,   129,   117,   118,
     119,   120,   121,   122,     0,   117,   118,   119,   120,   121,
     122,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   341,   123,   124,
     125,   126,   127,   128,   129,   123,   124,   125,   126,   127,
     128,   129
  };

  const short
  genesyspp_parser::yycheck_[] =
  {
      47,    48,    73,    76,    77,    78,    79,    80,    78,    79,
      80,    74,    74,    84,     6,     7,     8,     9,    10,    11,
      83,    83,    86,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    72,    47,    47,    74,    95,    96,
       6,     7,     8,     9,    10,    11,    83,   294,   295,     6,
       7,     8,     9,   110,   111,   112,    68,    68,   115,    72,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,    75,    76,    77,    78,    79,    80,    81,
      82,    74,    84,    72,    72,    72,    72,    72,    72,    72,
      83,    72,    72,    72,    72,   152,   153,   154,   155,    72,
      72,    72,    72,    72,    72,    72,     0,    72,    72,    75,
      76,    77,    78,    79,    80,    81,    82,    72,    84,    76,
      77,    78,    79,    80,    81,    82,    72,    72,    72,    72,
      72,    72,    72,    72,    72,   192,    72,    72,    48,    72,
      74,    66,    74,   200,   201,   202,   203,   204,   205,   206,
     207,   208,    74,   210,   211,    83,    83,    59,    51,    51,
     217,    51,    51,    51,    59,    66,    79,    73,    59,    73,
      73,    83,    59,    59,    73,   232,    73,   234,     6,     7,
       8,     9,    10,    11,    84,    47,    84,     3,    73,    73,
      73,    73,   249,    73,   251,   252,   253,   254,    73,    73,
      47,   258,    83,    73,    29,    84,    83,    83,    29,    -1,
      83,   268,   269,   270,   271,    83,    -1,    -1,    -1,    -1,
      -1,   278,    -1,    -1,    -1,    -1,   283,    -1,   285,    -1,
      -1,    -1,    -1,    -1,   291,    -1,   293,    -1,    -1,   296,
      -1,    -1,   299,    -1,    -1,    -1,   303,    75,    76,    77,
      78,    79,    80,    81,    82,    -1,    84,    -1,    -1,    -1,
      -1,    -1,   319,   320,   321,   322,    -1,    -1,    -1,    -1,
      -1,    -1,   329,     1,   331,     3,     4,     5,   335,    -1,
     337,    -1,    -1,    -1,    -1,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    -1,    42,    -1,    44,    -1,    -1,    47,
      48,    49,    -1,    -1,    52,    53,    54,    55,    56,    57,
      -1,    -1,    60,    61,    62,    63,    64,    -1,    -1,    67,
      68,    69,    -1,    -1,    72,    -1,    -1,    -1,    -1,    77,
       3,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    87,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    42,
      -1,    44,    -1,    -1,    47,    48,    49,    -1,    -1,    52,
      53,    54,    55,    56,    57,    -1,    -1,    60,    61,    62,
      63,    64,    -1,    -1,    67,    68,    69,    -1,    -1,    72,
      -1,    -1,    -1,    -1,    77,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    87,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    75,    76,    77,    78,    79,    80,
      81,    82,    -1,    84,    75,    76,    77,    78,    79,    80,
      81,    82,    -1,    84,    75,    76,    77,    78,    79,    80,
      81,    82,    -1,    84,    75,    76,    77,    78,    79,    80,
      81,    82,    -1,    84,    75,    76,    77,    78,    79,    80,
      81,    82,    -1,    84,    75,    76,    77,    78,    79,    80,
      81,    82,    -1,    84,    75,    76,    77,    78,    79,    80,
      81,    82,    -1,    84,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    76,    77,    78,    79,    80,    81,
      82,    -1,    84,    75,    76,    77,    78,    79,    80,    81,
      82,    -1,    84,    75,    76,    77,    78,    79,    80,    81,
      82,    -1,    84,    75,    76,    77,    78,    79,    80,    81,
      82,    -1,    84,    76,    77,    78,    79,    80,    81,    82,
      -1,    84,    76,    77,    78,    79,    80,    81,    82,    -1,
      84,    76,    77,    78,    79,    80,    81,    82,    -1,    84,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,     6,     7,     8,     9,    10,    11,    -1,
      76,    77,    78,    79,    80,    81,    82,    -1,    84,    76,
      77,    78,    79,    80,    81,    82,    -1,    84,    76,    77,
      78,    79,    80,    81,    82,    -1,    84,    76,    77,    78,
      79,    80,    81,    82,    -1,    84,    76,    77,    78,    79,
      80,    81,    82,    -1,    84,    76,    77,    78,    79,    80,
      81,    82,    -1,    84,    76,    77,    78,    79,    80,    81,
      82,    -1,    84,    76,    77,    78,    79,    80,    81,    82,
      -1,    84,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    76,    77,    78,    79,    80,    81,    82,    -1,
      84,    76,    77,    78,    79,    80,    81,    82,    -1,    84,
      76,    77,    78,    79,    80,    81,    82,    73,    84,    -1,
      76,    77,    78,    79,    80,    81,    82,    73,    -1,    -1,
      76,    77,    78,    79,    80,    81,    82,    73,    -1,    -1,
      76,    77,    78,    79,    80,    81,    82,    73,    -1,    -1,
      76,    77,    78,    79,    80,    81,    82,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,     6,     7,     8,
       9,    10,    11,    -1,    73,    -1,    -1,    76,    77,    78,
      79,    80,    81,    82,    73,    -1,    -1,    76,    77,    78,
      79,    80,    81,    82,    73,    -1,    -1,    76,    77,    78,
      79,    80,    81,    82,    73,    -1,    -1,    76,    77,    78,
      79,    80,    81,    82,    73,    -1,    -1,    76,    77,    78,
      79,    80,    81,    82,    73,    -1,    -1,    76,    77,    78,
      79,    80,    81,    82,    73,    -1,    -1,    76,    77,    78,
      79,    80,    81,    82,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,     6,     7,     8,     9,    10,    11,
      -1,     6,     7,     8,     9,    10,    11,    -1,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      45,     6,     7,     8,     9,    10,    11,    45,    -1,    -1,
      -1,    73,    -1,    -1,    76,    77,    78,    79,    80,    81,
      82,    73,    -1,    -1,    76,    77,    78,    79,    80,    81,
      82,    76,    77,    78,    79,    80,    81,    82,    76,    77,
      78,    79,    80,    81,    82,    73,    -1,    -1,    76,    77,
      78,    79,    80,    81,    82,    73,    -1,    -1,    76,    77,
      78,    79,    80,    81,    82,    -1,    -1,    -1,    73,    -1,
      -1,    76,    77,    78,    79,    80,    81,    82,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,     6,
       7,     8,     9,    10,    11,    -1,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    73,    -1,    -1,    76,    77,
      78,    79,    80,    81,    82,    73,    43,    -1,    76,    77,
      78,    79,    80,    81,    82,    73,    46,    -1,    76,    77,
      78,    79,    80,    81,    82,    73,    46,    -1,    76,    77,
      78,    79,    80,    81,    82,    -1,    -1,    -1,    -1,    76,
      77,    78,    79,    80,    81,    82,    76,    77,    78,    79,
      80,    81,    82,    -1,    -1,    -1,    76,    77,    78,    79,
      80,    81,    82,     6,     7,     8,     9,    10,    11,    -1,
      -1,     6,     7,     8,     9,    10,    11,    -1,    -1,     6,
       7,     8,     9,    10,    11,    -1,    -1,     6,     7,     8,
       9,    10,    11,    -1,    -1,     6,     7,     8,     9,    10,
      11,    -1,    -1,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,     6,     7,     8,     9,    10,    11,    -1,
      -1,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      73,    -1,    -1,    76,    77,    78,    79,    80,    81,    82,
      75,    76,    77,    78,    79,    80,    81,    82,    75,    76,
      77,    78,    79,    80,    81,    82,    75,    76,    77,    78,
      79,    80,    81,    82,    75,    76,    77,    78,    79,    80,
      81,    82,    75,    76,    77,    78,    79,    80,    81,    82,
      73,    -1,    -1,    76,    77,    78,    79,    80,    81,    82,
      75,    76,    77,    78,    79,    80,    81,    82,     6,     7,
       8,     9,    10,    11,    -1,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
      78,    79,    80,    81,    82,    76,    77,    78,    79,    80,
      81,    82
  };

  const signed char
  genesyspp_parser::yystos_[] =
  {
       0,     1,     3,     4,     5,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    42,    44,
      47,    48,    49,    52,    53,    54,    55,    56,    57,    60,
      61,    62,    63,    64,    67,    68,    69,    72,    77,    87,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   104,   105,   106,   107,   108,    86,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    47,    68,   104,   105,    74,    83,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      74,    83,    74,    90,    90,    72,     0,     6,     7,     8,
       9,    10,    11,    76,    77,    78,    79,    80,    81,    82,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
     103,    90,    74,    74,    83,    83,    90,    90,    48,    51,
      51,    51,    51,    51,    66,    59,    59,    59,    59,    59,
      66,    90,    90,    90,    73,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    73,
      73,    73,    84,    73,    73,    73,    73,    73,    73,    73,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    73,
      84,    73,    90,    90,    90,    90,    75,    84,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    84,    84,
      73,    75,    84,    75,    84,    73,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    75,    84,
      75,    84,    45,    45,    83,    90,    47,     3,    83,    90,
      90,    73,    73,    73,    73,    73,    73,    73,    84,    84,
      84,    43,    90,    90,    90,    90,    90,    75,    84,    73,
      84,    90,    75,    84,    75,    84,    90,    90,    90,    90,
      75,    84,    75,    84,    46,    46,    83,    90,    47,    83,
      90,    90,    73,    84,    90,    90,    47,    68,   107,   107,
      90,    75,    73,    90,    75,    75,    90,    75,    75,    74,
      74,    83,    83,    73,    90,    90,    90,    90,    75,    84,
      75,    84,    90,    90,    75,    84,    75,    84,    90,    90,
      75,    75
  };

  const signed char
  genesyspp_parser::yyr1_[] =
  {
       0,    88,    89,    89,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    91,    91,    92,    92,    92,    92,
      92,    92,    93,    93,    93,    93,    93,    93,    93,    93,
      94,    94,    95,    95,    96,    96,    97,    97,    97,    97,
      97,    97,    98,    98,    98,    98,    99,    99,   100,   100,
     100,   100,   100,   100,   100,   100,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   102,   103,   103,
     104,   104,   104,   104,   105,   105,   105,   105,   106,   106,
     106,   106,   107,   107,   107,   107,   107,   107,   107,   107,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108
  };

  const signed char
  genesyspp_parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     7,     5,     8,     8,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     6,     1,     4,     6,     6,
       6,     6,     6,     6,     8,    10,     4,     4,     5,     3,
       1,     4,     6,     8,     1,     4,     6,     8,     1,     4,
       6,     8,     3,     6,     8,    10,     3,     6,     8,    10,
       1,     4,     4,     4,     6,     8,     4,     4,     4,     4,
       4,     4,     4
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const genesyspp_parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "NUMD", "NUMH",
  "CTEZERO", "oLE", "oGE", "oEQ", "oNE", "oAND", "oOR", "oNOT", "fSIN",
  "fCOS", "fROUND", "fMOD", "fTRUNC", "fFRAC", "fEXP", "fSQRT", "fLOG",
  "fLN", "fVAL", "fEVAL", "fLENG", "fRND1", "fEXPO", "fNORM", "fUNIF",
  "fWEIB", "fLOGN", "fGAMM", "fERLA", "fTRIA", "fBETA", "fDISC", "fTNOW",
  "fTFIN", "fMAXREP", "fNUMREP", "fIDENT", "cIF", "cELSE", "cFOR", "cTO",
  "cDO", "ATRIB", "CSTAT", "fTAVG", "ILLEGAL", "RESOURCE", "fNR", "fMR",
  "fIRF", "fRESSEIZES", "fSTATE", "fSETSUM", "fRESUTIL", "QUEUE", "fNQ",
  "fFIRSTINQ", "fLASTINQ", "fSAQUE", "fAQUE", "fENTATRANK", "SET",
  "fNUMSET", "VARI", "FORM", "fNUMGR", "fATRGR", "\"(\"", "\")\"", "\"[\"",
  "\"]\"", "\"+\"", "\"-\"", "\"*\"", "\"^\"", "\"/\"", "\"<\"", "\">\"",
  "\"=\"", "\",\"", "NEG", "'\\n'", "\"USER\"", "$accept", "input",
  "expression", "numero", "aritmetica", "relacional", "comando",
  "comandoIF", "comandoFOR", "function", "kernelFunction",
  "trigonFunction", "mathFunction", "probFunction", "userFunction",
  "listaparm", "atributo", "variavel", "formula", "atribuicao",
  "pluginFunction", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  genesyspp_parser::yyrline_[] =
  {
       0,   212,   212,   213,   217,   218,   219,   220,   221,   222,
     223,   224,   227,   230,   236,   237,   241,   242,   243,   244,
     245,   246,   250,   251,   252,   253,   254,   255,   256,   257,
     261,   262,   266,   267,   272,   273,   277,   278,   279,   280,
     281,   282,   286,   287,   288,   289,   296,   297,   301,   302,
     303,   304,   305,   306,   307,   308,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   328,   333,   334,
     359,   368,   377,   386,   399,   400,   403,   406,   414,   416,
     419,   422,   430,   433,   437,   441,   447,   450,   454,   458,
     468,   471,   473,   474,   481,   486,   494,   495,   496,   497,
     498,   499,   515
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
#line 2637 "../GenesysParser.cpp"

#line 522 "bisonparser.yy"

void
yy::genesyspp_parser::error (const location_type& l,
                          const std::string& m)
{
  driver.error (l, m);
}
