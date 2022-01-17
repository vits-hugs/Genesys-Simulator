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
#line 56 "bisonparser.yy"

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
      case symbol_kind::S_oNAND: // oNAND
      case symbol_kind::S_oXOR: // oXOR
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
      case symbol_kind::S_logica: // logica
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
      case symbol_kind::S_oNAND: // oNAND
      case symbol_kind::S_oXOR: // oXOR
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
      case symbol_kind::S_logica: // logica
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
      case symbol_kind::S_oNAND: // oNAND
      case symbol_kind::S_oXOR: // oXOR
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
      case symbol_kind::S_logica: // logica
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
      case symbol_kind::S_oNAND: // oNAND
      case symbol_kind::S_oXOR: // oXOR
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
      case symbol_kind::S_logica: // logica
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
#line 49 "bisonparser.yy"
{
  // Initialize the initial location.
  //@$.begin.filename = @$.end.filename = &driver.getFile();
}

#line 789 "../GenesysParser.cpp"


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
      case symbol_kind::S_oNAND: // oNAND
      case symbol_kind::S_oXOR: // oXOR
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
      case symbol_kind::S_logica: // logica
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
#line 225 "bisonparser.yy"
                    { driver.setResult(yystack_[0].value.as < obj_t > ().valor);}
#line 1022 "../GenesysParser.cpp"
    break;

  case 3: // input: error '\n'
#line 226 "bisonparser.yy"
                        { yyerrok; }
#line 1028 "../GenesysParser.cpp"
    break;

  case 4: // expression: numero
#line 230 "bisonparser.yy"
                                       {yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1034 "../GenesysParser.cpp"
    break;

  case 5: // expression: function
#line 231 "bisonparser.yy"
                                       {yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1040 "../GenesysParser.cpp"
    break;

  case 6: // expression: comando
#line 232 "bisonparser.yy"
                                       {yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1046 "../GenesysParser.cpp"
    break;

  case 7: // expression: atribuicao
#line 233 "bisonparser.yy"
                                       {yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1052 "../GenesysParser.cpp"
    break;

  case 8: // expression: aritmetica
#line 234 "bisonparser.yy"
                                           {yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1058 "../GenesysParser.cpp"
    break;

  case 9: // expression: logica
#line 235 "bisonparser.yy"
                                       {yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1064 "../GenesysParser.cpp"
    break;

  case 10: // expression: relacional
#line 236 "bisonparser.yy"
                                       {yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1070 "../GenesysParser.cpp"
    break;

  case 11: // expression: "(" expression ")"
#line 237 "bisonparser.yy"
                                       {yylhs.value.as < obj_t > ().valor = yystack_[1].value.as < obj_t > ().valor;}
#line 1076 "../GenesysParser.cpp"
    break;

  case 12: // expression: atributo
#line 238 "bisonparser.yy"
                                       {yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1082 "../GenesysParser.cpp"
    break;

  case 13: // expression: variavel
#line 243 "bisonparser.yy"
                                                   {yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1088 "../GenesysParser.cpp"
    break;

  case 14: // expression: formula
#line 247 "bisonparser.yy"
                                                   {yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1094 "../GenesysParser.cpp"
    break;

  case 15: // numero: NUMD
#line 254 "bisonparser.yy"
              { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1100 "../GenesysParser.cpp"
    break;

  case 16: // numero: NUMH
#line 255 "bisonparser.yy"
              { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1106 "../GenesysParser.cpp"
    break;

  case 17: // aritmetica: expression "+" expression
#line 259 "bisonparser.yy"
                                     { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor + yystack_[0].value.as < obj_t > ().valor;}
#line 1112 "../GenesysParser.cpp"
    break;

  case 18: // aritmetica: expression "-" expression
#line 260 "bisonparser.yy"
                                     { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor - yystack_[0].value.as < obj_t > ().valor;}
#line 1118 "../GenesysParser.cpp"
    break;

  case 19: // aritmetica: expression "/" expression
#line 261 "bisonparser.yy"
                                     { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor / yystack_[0].value.as < obj_t > ().valor;}
#line 1124 "../GenesysParser.cpp"
    break;

  case 20: // aritmetica: expression "*" expression
#line 262 "bisonparser.yy"
                                     { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor * yystack_[0].value.as < obj_t > ().valor;}
#line 1130 "../GenesysParser.cpp"
    break;

  case 21: // aritmetica: expression "^" expression
#line 263 "bisonparser.yy"
                                     { yylhs.value.as < obj_t > ().valor = pow(yystack_[2].value.as < obj_t > ().valor,yystack_[0].value.as < obj_t > ().valor);}
#line 1136 "../GenesysParser.cpp"
    break;

  case 22: // aritmetica: "-" expression
#line 264 "bisonparser.yy"
                                     { yylhs.value.as < obj_t > ().valor = -yystack_[0].value.as < obj_t > ().valor;}
#line 1142 "../GenesysParser.cpp"
    break;

  case 23: // logica: expression oAND expression
#line 268 "bisonparser.yy"
                                    { yylhs.value.as < obj_t > ().valor = (int) yystack_[2].value.as < obj_t > ().valor && (int) yystack_[0].value.as < obj_t > ().valor;}
#line 1148 "../GenesysParser.cpp"
    break;

  case 24: // logica: expression oOR expression
#line 269 "bisonparser.yy"
                                    { yylhs.value.as < obj_t > ().valor = (int) yystack_[2].value.as < obj_t > ().valor || (int) yystack_[0].value.as < obj_t > ().valor;}
#line 1154 "../GenesysParser.cpp"
    break;

  case 25: // logica: expression oNAND expression
#line 270 "bisonparser.yy"
                                    { yylhs.value.as < obj_t > ().valor = !((int) yystack_[2].value.as < obj_t > ().valor && (int) yystack_[0].value.as < obj_t > ().valor);}
#line 1160 "../GenesysParser.cpp"
    break;

  case 26: // logica: expression oXOR expression
#line 271 "bisonparser.yy"
                                    { yylhs.value.as < obj_t > ().valor = (!(int) yystack_[2].value.as < obj_t > ().valor && (int) yystack_[0].value.as < obj_t > ().valor) || ((int) yystack_[2].value.as < obj_t > ().valor && !(int) yystack_[0].value.as < obj_t > ().valor);}
#line 1166 "../GenesysParser.cpp"
    break;

  case 27: // logica: oNOT expression
#line 272 "bisonparser.yy"
                                    { yylhs.value.as < obj_t > ().valor = !(int) yystack_[0].value.as < obj_t > ().valor;}
#line 1172 "../GenesysParser.cpp"
    break;

  case 28: // relacional: expression "<" expression
#line 276 "bisonparser.yy"
                                         { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor < yystack_[0].value.as < obj_t > ().valor ? 1 : 0;}
#line 1178 "../GenesysParser.cpp"
    break;

  case 29: // relacional: expression ">" expression
#line 277 "bisonparser.yy"
                                         { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor > yystack_[0].value.as < obj_t > ().valor ? 1 : 0;}
#line 1184 "../GenesysParser.cpp"
    break;

  case 30: // relacional: expression oLE expression
#line 278 "bisonparser.yy"
                                         { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor <= yystack_[0].value.as < obj_t > ().valor ? 1 : 0;}
#line 1190 "../GenesysParser.cpp"
    break;

  case 31: // relacional: expression oGE expression
#line 279 "bisonparser.yy"
                                         { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor >= yystack_[0].value.as < obj_t > ().valor ? 1 : 0;}
#line 1196 "../GenesysParser.cpp"
    break;

  case 32: // relacional: expression oEQ expression
#line 280 "bisonparser.yy"
                                         { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor == yystack_[0].value.as < obj_t > ().valor ? 1 : 0;}
#line 1202 "../GenesysParser.cpp"
    break;

  case 33: // relacional: expression oNE expression
#line 281 "bisonparser.yy"
                                         { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor != yystack_[0].value.as < obj_t > ().valor ? 1 : 0;}
#line 1208 "../GenesysParser.cpp"
    break;

  case 34: // comando: comandoIF
#line 285 "bisonparser.yy"
                    { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1214 "../GenesysParser.cpp"
    break;

  case 35: // comando: comandoFOR
#line 286 "bisonparser.yy"
                    { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1220 "../GenesysParser.cpp"
    break;

  case 36: // comandoIF: cIF expression expression cELSE expression
#line 290 "bisonparser.yy"
                                                   { yylhs.value.as < obj_t > ().valor = yystack_[3].value.as < obj_t > ().valor != 0 ? yystack_[2].value.as < obj_t > ().valor : yystack_[0].value.as < obj_t > ().valor; }
#line 1226 "../GenesysParser.cpp"
    break;

  case 37: // comandoIF: cIF expression expression
#line 291 "bisonparser.yy"
                                                  { yylhs.value.as < obj_t > ().valor = yystack_[1].value.as < obj_t > ().valor != 0 ? yystack_[0].value.as < obj_t > ().valor : 0;}
#line 1232 "../GenesysParser.cpp"
    break;

  case 38: // comandoFOR: cFOR variavel "=" expression cTO expression cDO atribuicao
#line 296 "bisonparser.yy"
                                                                 {yylhs.value.as < obj_t > ().valor = 0; }
#line 1238 "../GenesysParser.cpp"
    break;

  case 39: // comandoFOR: cFOR atributo "=" expression cTO expression cDO atribuicao
#line 297 "bisonparser.yy"
                                                                  {yylhs.value.as < obj_t > ().valor = 0; }
#line 1244 "../GenesysParser.cpp"
    break;

  case 40: // function: mathFunction
#line 301 "bisonparser.yy"
                         { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1250 "../GenesysParser.cpp"
    break;

  case 41: // function: trigonFunction
#line 302 "bisonparser.yy"
                         { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1256 "../GenesysParser.cpp"
    break;

  case 42: // function: probFunction
#line 303 "bisonparser.yy"
                         { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1262 "../GenesysParser.cpp"
    break;

  case 43: // function: kernelFunction
#line 304 "bisonparser.yy"
                         { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1268 "../GenesysParser.cpp"
    break;

  case 44: // function: pluginFunction
#line 305 "bisonparser.yy"
                         { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1274 "../GenesysParser.cpp"
    break;

  case 45: // function: userFunction
#line 306 "bisonparser.yy"
                         { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1280 "../GenesysParser.cpp"
    break;

  case 46: // kernelFunction: fTNOW
#line 310 "bisonparser.yy"
                 { yylhs.value.as < obj_t > ().valor = driver.getModel()->getSimulation()->getSimulatedTime();}
#line 1286 "../GenesysParser.cpp"
    break;

  case 47: // kernelFunction: fTFIN
#line 311 "bisonparser.yy"
                 { yylhs.value.as < obj_t > ().valor = driver.getModel()->getSimulation()->getReplicationLength();}
#line 1292 "../GenesysParser.cpp"
    break;

  case 48: // kernelFunction: fMAXREP
#line 312 "bisonparser.yy"
                 { yylhs.value.as < obj_t > ().valor = driver.getModel()->getSimulation()->getNumberOfReplications();}
#line 1298 "../GenesysParser.cpp"
    break;

  case 49: // kernelFunction: fNUMREP
#line 313 "bisonparser.yy"
                 { yylhs.value.as < obj_t > ().valor = driver.getModel()->getSimulation()->getCurrentReplicationNumber();}
#line 1304 "../GenesysParser.cpp"
    break;

  case 50: // kernelFunction: fIDENT
#line 314 "bisonparser.yy"
                 { yylhs.value.as < obj_t > ().valor = driver.getModel()->getSimulation()->getCurrentEntity()->getId();}
#line 1310 "../GenesysParser.cpp"
    break;

  case 51: // kernelFunction: CSTAT
#line 315 "bisonparser.yy"
                         { yylhs.value.as < obj_t > ().valor = 0; }
#line 1316 "../GenesysParser.cpp"
    break;

  case 52: // kernelFunction: fTAVG "(" CSTAT ")"
#line 316 "bisonparser.yy"
                               {
                    StatisticsCollector* cstat = ((StatisticsCollector*)(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<StatisticsCollector>(), yystack_[1].value.as < obj_t > ().id)));
                    double value = cstat->getStatistics()->average();
                    yylhs.value.as < obj_t > ().valor = value; }
#line 1325 "../GenesysParser.cpp"
    break;

  case 53: // trigonFunction: fSIN "(" expression ")"
#line 323 "bisonparser.yy"
                                  { yylhs.value.as < obj_t > ().valor = sin(yystack_[1].value.as < obj_t > ().valor); }
#line 1331 "../GenesysParser.cpp"
    break;

  case 54: // trigonFunction: fCOS "(" expression ")"
#line 324 "bisonparser.yy"
                                  { yylhs.value.as < obj_t > ().valor = cos(yystack_[1].value.as < obj_t > ().valor); }
#line 1337 "../GenesysParser.cpp"
    break;

  case 55: // mathFunction: fROUND "(" expression ")"
#line 328 "bisonparser.yy"
                                        { yylhs.value.as < obj_t > ().valor = round(yystack_[1].value.as < obj_t > ().valor);}
#line 1343 "../GenesysParser.cpp"
    break;

  case 56: // mathFunction: fFRAC "(" expression ")"
#line 329 "bisonparser.yy"
                                        { yylhs.value.as < obj_t > ().valor = yystack_[1].value.as < obj_t > ().valor - (int) yystack_[1].value.as < obj_t > ().valor;}
#line 1349 "../GenesysParser.cpp"
    break;

  case 57: // mathFunction: fTRUNC "(" expression ")"
#line 330 "bisonparser.yy"
                                        { yylhs.value.as < obj_t > ().valor = trunc(yystack_[1].value.as < obj_t > ().valor);}
#line 1355 "../GenesysParser.cpp"
    break;

  case 58: // mathFunction: fEXP "(" expression ")"
#line 331 "bisonparser.yy"
                                    { yylhs.value.as < obj_t > ().valor = exp(yystack_[1].value.as < obj_t > ().valor);}
#line 1361 "../GenesysParser.cpp"
    break;

  case 59: // mathFunction: fSQRT "(" expression ")"
#line 332 "bisonparser.yy"
                                    { yylhs.value.as < obj_t > ().valor = sqrt(yystack_[1].value.as < obj_t > ().valor);}
#line 1367 "../GenesysParser.cpp"
    break;

  case 60: // mathFunction: fLOG "(" expression ")"
#line 333 "bisonparser.yy"
                                    { yylhs.value.as < obj_t > ().valor = log10(yystack_[1].value.as < obj_t > ().valor);}
#line 1373 "../GenesysParser.cpp"
    break;

  case 61: // mathFunction: fLN "(" expression ")"
#line 334 "bisonparser.yy"
                                    { yylhs.value.as < obj_t > ().valor = log(yystack_[1].value.as < obj_t > ().valor);}
#line 1379 "../GenesysParser.cpp"
    break;

  case 62: // mathFunction: fMOD "(" expression "," expression ")"
#line 335 "bisonparser.yy"
                                               { yylhs.value.as < obj_t > ().valor = (int) yystack_[3].value.as < obj_t > ().valor % (int) yystack_[1].value.as < obj_t > ().valor; }
#line 1385 "../GenesysParser.cpp"
    break;

  case 63: // probFunction: fRND1
#line 339 "bisonparser.yy"
                                                     { yylhs.value.as < obj_t > ().valor = driver.sampler()->sampleUniform(0.0,1.0);}
#line 1391 "../GenesysParser.cpp"
    break;

  case 64: // probFunction: fEXPO "(" expression ")"
#line 340 "bisonparser.yy"
                                     { yylhs.value.as < obj_t > ().valor = driver.sampler()->sampleExponential(yystack_[1].value.as < obj_t > ().valor);}
#line 1397 "../GenesysParser.cpp"
    break;

  case 65: // probFunction: fNORM "(" expression "," expression ")"
#line 341 "bisonparser.yy"
                                                { yylhs.value.as < obj_t > ().valor = driver.sampler()->sampleNormal(yystack_[3].value.as < obj_t > ().valor,yystack_[1].value.as < obj_t > ().valor);}
#line 1403 "../GenesysParser.cpp"
    break;

  case 66: // probFunction: fUNIF "(" expression "," expression ")"
#line 342 "bisonparser.yy"
                                                { yylhs.value.as < obj_t > ().valor = driver.sampler()->sampleUniform(yystack_[3].value.as < obj_t > ().valor,yystack_[1].value.as < obj_t > ().valor);}
#line 1409 "../GenesysParser.cpp"
    break;

  case 67: // probFunction: fWEIB "(" expression "," expression ")"
#line 343 "bisonparser.yy"
                                                { yylhs.value.as < obj_t > ().valor = driver.sampler()->sampleWeibull(yystack_[3].value.as < obj_t > ().valor,yystack_[1].value.as < obj_t > ().valor);}
#line 1415 "../GenesysParser.cpp"
    break;

  case 68: // probFunction: fLOGN "(" expression "," expression ")"
#line 344 "bisonparser.yy"
                                                { yylhs.value.as < obj_t > ().valor = driver.sampler()->sampleLogNormal(yystack_[3].value.as < obj_t > ().valor,yystack_[1].value.as < obj_t > ().valor);}
#line 1421 "../GenesysParser.cpp"
    break;

  case 69: // probFunction: fGAMM "(" expression "," expression ")"
#line 345 "bisonparser.yy"
                                                { yylhs.value.as < obj_t > ().valor = driver.sampler()->sampleGamma(yystack_[3].value.as < obj_t > ().valor,yystack_[1].value.as < obj_t > ().valor);}
#line 1427 "../GenesysParser.cpp"
    break;

  case 70: // probFunction: fERLA "(" expression "," expression ")"
#line 346 "bisonparser.yy"
                                                { yylhs.value.as < obj_t > ().valor = driver.sampler()->sampleErlang(yystack_[3].value.as < obj_t > ().valor,yystack_[1].value.as < obj_t > ().valor);}
#line 1433 "../GenesysParser.cpp"
    break;

  case 71: // probFunction: fTRIA "(" expression "," expression "," expression ")"
#line 347 "bisonparser.yy"
                                                                { yylhs.value.as < obj_t > ().valor = driver.sampler()->sampleTriangular(yystack_[5].value.as < obj_t > ().valor,yystack_[3].value.as < obj_t > ().valor,yystack_[1].value.as < obj_t > ().valor);}
#line 1439 "../GenesysParser.cpp"
    break;

  case 72: // probFunction: fBETA "(" expression "," expression "," expression "," expression ")"
#line 348 "bisonparser.yy"
                                                                              { yylhs.value.as < obj_t > ().valor = driver.sampler()->sampleBeta(yystack_[7].value.as < obj_t > ().valor,yystack_[5].value.as < obj_t > ().valor,yystack_[3].value.as < obj_t > ().valor,yystack_[1].value.as < obj_t > ().valor);}
#line 1445 "../GenesysParser.cpp"
    break;

  case 73: // probFunction: fDISC "(" listaparm ")"
#line 349 "bisonparser.yy"
                                                { yylhs.value.as < obj_t > ().valor = driver.sampler()->sampleDiscrete(0,0); /*@TODO: NOT IMPLEMENTED YET*/ }
#line 1451 "../GenesysParser.cpp"
    break;

  case 74: // userFunction: "USER" "(" expression ")"
#line 355 "bisonparser.yy"
                                        { yylhs.value.as < obj_t > ().valor = yystack_[1].value.as < obj_t > ().valor; }
#line 1457 "../GenesysParser.cpp"
    break;

  case 75: // listaparm: listaparm "," expression "," expression
#line 360 "bisonparser.yy"
                                                 {/*@TODO: NOT IMPLEMENTED YET*/}
#line 1463 "../GenesysParser.cpp"
    break;

  case 76: // listaparm: expression "," expression
#line 361 "bisonparser.yy"
                                                 {/*@TODO: NOT IMPLEMENTED YET*/}
#line 1469 "../GenesysParser.cpp"
    break;

  case 77: // atributo: ATRIB
#line 387 "bisonparser.yy"
                   {  
		double attributeValue = 0.0;
		if (driver.getModel()->getSimulation()->getCurrentEntity() != nullptr) {
			// it could crach because there may be no current entity, if the parse is running before simulation and therefore there is no CurrentEntity
			attributeValue = driver.getModel()->getSimulation()->getCurrentEntity()->getAttributeValue(yystack_[0].value.as < obj_t > ().id);
		}
		//std::cout << "Passei" << std::endl;
		yylhs.value.as < obj_t > ().valor = attributeValue; 
	}
#line 1483 "../GenesysParser.cpp"
    break;

  case 78: // atributo: ATRIB "[" expression "]"
#line 396 "bisonparser.yy"
                                              {  
		double attributeValue = 0.0;
		std::string index = std::to_string(static_cast<unsigned int>(yystack_[1].value.as < obj_t > ().valor));
		if (driver.getModel()->getSimulation()->getCurrentEntity() != nullptr) {
			// it could crach because there may be no current entity, if the parse is running before simulation and therefore there is no CurrentEntity
			attributeValue = driver.getModel()->getSimulation()->getCurrentEntity()->getAttributeValue(index, yystack_[3].value.as < obj_t > ().id);
		}
		yylhs.value.as < obj_t > ().valor = attributeValue; 
	}
#line 1497 "../GenesysParser.cpp"
    break;

  case 79: // atributo: ATRIB "[" expression "," expression "]"
#line 405 "bisonparser.yy"
                                                             {  
		double attributeValue = 0.0;
		std::string index = std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[1].value.as < obj_t > ().valor));
		if (driver.getModel()->getSimulation()->getCurrentEntity() != nullptr) {
			// it could crach because there may be no current entity, if the parse is running before simulation and therefore there is no CurrentEntity
			attributeValue = driver.getModel()->getSimulation()->getCurrentEntity()->getAttributeValue(index, yystack_[5].value.as < obj_t > ().id);
		}
		yylhs.value.as < obj_t > ().valor = attributeValue; 
	}
#line 1511 "../GenesysParser.cpp"
    break;

  case 80: // atributo: ATRIB "[" expression "," expression "," expression "]"
#line 414 "bisonparser.yy"
                                                                            {  
		double attributeValue = 0.0;
		std::string index = std::to_string(static_cast<unsigned int>(yystack_[5].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[1].value.as < obj_t > ().valor));
		if (driver.getModel()->getSimulation()->getCurrentEntity() != nullptr) {
			// it could crach because there may be no current entity, if the parse is running before simulation and therefore there is no CurrentEntity
			attributeValue = driver.getModel()->getSimulation()->getCurrentEntity()->getAttributeValue(index, yystack_[7].value.as < obj_t > ().id);
		}
		yylhs.value.as < obj_t > ().valor = attributeValue; 
	}
#line 1525 "../GenesysParser.cpp"
    break;

  case 81: // variavel: VARI
#line 428 "bisonparser.yy"
                            {yylhs.value.as < obj_t > ().valor = ((Variable*)(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Variable>(), yystack_[0].value.as < obj_t > ().id)))->getValue();}
#line 1531 "../GenesysParser.cpp"
    break;

  case 82: // variavel: VARI "[" expression "]"
#line 429 "bisonparser.yy"
                                                                            { 
					std::string index = std::to_string(static_cast<unsigned int>(yystack_[1].value.as < obj_t > ().valor));
					yylhs.value.as < obj_t > ().valor = ((Variable*)(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Variable>(), yystack_[3].value.as < obj_t > ().id)))->getValue(index); }
#line 1539 "../GenesysParser.cpp"
    break;

  case 83: // variavel: VARI "[" expression "," expression "]"
#line 432 "bisonparser.yy"
                                                                                            { 
					std::string index = std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[1].value.as < obj_t > ().valor)); 
					yylhs.value.as < obj_t > ().valor = ((Variable*)(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Variable>(), yystack_[5].value.as < obj_t > ().id)))->getValue(index);}
#line 1547 "../GenesysParser.cpp"
    break;

  case 84: // variavel: VARI "[" expression "," expression "," expression "]"
#line 435 "bisonparser.yy"
                                                                                                     { 
					std::string index = std::to_string(static_cast<unsigned int>(yystack_[5].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[1].value.as < obj_t > ().valor));
					yylhs.value.as < obj_t > ().valor = ((Variable*)(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Variable>(), yystack_[7].value.as < obj_t > ().id)))->getValue(index);}
#line 1555 "../GenesysParser.cpp"
    break;

  case 85: // formula: FORM
#line 443 "bisonparser.yy"
                                    { 
					yylhs.value.as < obj_t > ().valor = ((Formula*)(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Formula>(), yystack_[0].value.as < obj_t > ().id)))->value();}
#line 1562 "../GenesysParser.cpp"
    break;

  case 86: // formula: FORM "[" expression "]"
#line 445 "bisonparser.yy"
                                                                    {
					std::string index = std::to_string(static_cast<unsigned int>(yystack_[1].value.as < obj_t > ().valor));
					yylhs.value.as < obj_t > ().valor = ((Formula*)(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Formula>(), yystack_[3].value.as < obj_t > ().id)))->value(index);}
#line 1570 "../GenesysParser.cpp"
    break;

  case 87: // formula: FORM "[" expression "," expression "]"
#line 448 "bisonparser.yy"
                                                                                   {
					std::string index = std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor)) +","+std::to_string(static_cast<unsigned int>(yystack_[1].value.as < obj_t > ().valor));
					yylhs.value.as < obj_t > ().valor = ((Formula*)(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Formula>(), yystack_[5].value.as < obj_t > ().id)))->value(index);}
#line 1578 "../GenesysParser.cpp"
    break;

  case 88: // formula: FORM "[" expression "," expression "," expression "]"
#line 451 "bisonparser.yy"
                                                                                                  {
					std::string index = std::to_string(static_cast<unsigned int>(yystack_[5].value.as < obj_t > ().valor)) +","+std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[1].value.as < obj_t > ().valor));
					yylhs.value.as < obj_t > ().valor = ((Formula*)(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Formula>(), yystack_[7].value.as < obj_t > ().id)))->value(index);}
#line 1586 "../GenesysParser.cpp"
    break;

  case 89: // atribuicao: ATRIB "=" expression
#line 459 "bisonparser.yy"
                                                 { 
					driver.getModel()->getSimulation()->getCurrentEntity()->setAttributeValue("", yystack_[2].value.as < obj_t > ().id, yystack_[0].value.as < obj_t > ().valor);
					yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1594 "../GenesysParser.cpp"
    break;

  case 90: // atribuicao: ATRIB "[" expression "]" "=" expression
#line 462 "bisonparser.yy"
                                                                                          { 
					std::string index = std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor));
					driver.getModel()->getSimulation()->getCurrentEntity()->setAttributeValue(index, yystack_[5].value.as < obj_t > ().id, yystack_[0].value.as < obj_t > ().valor);
					yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1603 "../GenesysParser.cpp"
    break;

  case 91: // atribuicao: ATRIB "[" expression "," expression "]" "=" expression
#line 466 "bisonparser.yy"
                                                                                                        {
					std::string index = std::to_string(static_cast<unsigned int>(yystack_[5].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor)); 
					driver.getModel()->getSimulation()->getCurrentEntity()->setAttributeValue(index, yystack_[7].value.as < obj_t > ().id, yystack_[0].value.as < obj_t > ().valor); 
					yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1612 "../GenesysParser.cpp"
    break;

  case 92: // atribuicao: ATRIB "[" expression "," expression "," expression "]" "=" expression
#line 470 "bisonparser.yy"
                                                                                                                          {
					std::string index = std::to_string(static_cast<unsigned int>(yystack_[7].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[5].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor));
					driver.getModel()->getSimulation()->getCurrentEntity()->setAttributeValue(index, yystack_[9].value.as < obj_t > ().id, yystack_[0].value.as < obj_t > ().valor);
					yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1621 "../GenesysParser.cpp"
    break;

  case 93: // atribuicao: VARI "=" expression
#line 476 "bisonparser.yy"
                                                                {
					((Variable*)(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Variable>(), yystack_[2].value.as < obj_t > ().id)))->setValue(yystack_[0].value.as < obj_t > ().valor);
					yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1629 "../GenesysParser.cpp"
    break;

  case 94: // atribuicao: VARI "[" expression "]" "=" expression
#line 479 "bisonparser.yy"
                                                                                         { 
					std::string index = std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor));
					((Variable*)(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Variable>(), yystack_[5].value.as < obj_t > ().id)))->setValue(index, yystack_[0].value.as < obj_t > ().valor); 
					yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1638 "../GenesysParser.cpp"
    break;

  case 95: // atribuicao: VARI "[" expression "," expression "]" "=" expression
#line 483 "bisonparser.yy"
                                                                                                       {
					std::string index = std::to_string(static_cast<unsigned int>(yystack_[5].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor)); 
					((Variable*)(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Variable>(), yystack_[7].value.as < obj_t > ().id)))->setValue(index, yystack_[0].value.as < obj_t > ().valor);
					yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1647 "../GenesysParser.cpp"
    break;

  case 96: // atribuicao: VARI "[" expression "," expression "," expression "]" "=" expression
#line 487 "bisonparser.yy"
                                                                                                                         {
					std::string index = std::to_string(static_cast<unsigned int>(yystack_[7].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[5].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor));
					((Variable*)(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Variable>(), yystack_[9].value.as < obj_t > ().id)))->setValue(index, yystack_[0].value.as < obj_t > ().valor); 
					yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1656 "../GenesysParser.cpp"
    break;

  case 97: // pluginFunction: CTEZERO
#line 498 "bisonparser.yy"
                                                     { yylhs.value.as < obj_t > ().valor = 0; }
#line 1662 "../GenesysParser.cpp"
    break;

  case 98: // pluginFunction: fNQ "(" QUEUE ")"
#line 501 "bisonparser.yy"
                                    {   //std::cout << "Queue ID: " << $3.id << ", Size: " << ((Queue*)(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Queue>(), $3.id)))->size() << std::endl; 
                                        yylhs.value.as < obj_t > ().valor = ((Queue*)(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Queue>(), yystack_[1].value.as < obj_t > ().id)))->size();}
#line 1669 "../GenesysParser.cpp"
    break;

  case 99: // pluginFunction: fLASTINQ "(" QUEUE ")"
#line 503 "bisonparser.yy"
                                    {/*For now does nothing because need acces to list of QUEUE, or at least the last element*/ }
#line 1675 "../GenesysParser.cpp"
    break;

  case 100: // pluginFunction: fFIRSTINQ "(" QUEUE ")"
#line 504 "bisonparser.yy"
                                    { 
                if (((Queue*)(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Queue>(), yystack_[1].value.as < obj_t > ().id)))->size() > 0){
                    //id da 1a entidade da fila, talvez pegar nome
                    yylhs.value.as < obj_t > ().valor = ((Queue*)(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Queue>(), yystack_[1].value.as < obj_t > ().id)))->first()->getEntity()->getId();
                }else{
                    yylhs.value.as < obj_t > ().valor = 0;
                } }
#line 1687 "../GenesysParser.cpp"
    break;

  case 101: // pluginFunction: fSAQUE "(" QUEUE "," ATRIB ")"
#line 511 "bisonparser.yy"
                                       {   
                Util::identification queueID = yystack_[3].value.as < obj_t > ().id;
                Util::identification attrID = yystack_[1].value.as < obj_t > ().id;
                double sum = ((Queue*)(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Queue>(), yystack_[3].value.as < obj_t > ().id)))->sumAttributesFromWaiting(attrID);
                yylhs.value.as < obj_t > ().valor = sum; }
#line 1697 "../GenesysParser.cpp"
    break;

  case 102: // pluginFunction: fAQUE "(" QUEUE "," NUMD "," ATRIB ")"
#line 516 "bisonparser.yy"
                                             {
                Util::identification queueID = yystack_[5].value.as < obj_t > ().id;
                Util::identification attrID = yystack_[1].value.as < obj_t > ().id;
                double value = ((Queue*)(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Queue>(), yystack_[5].value.as < obj_t > ().id)))->getAttributeFromWaitingRank(yystack_[3].value.as < obj_t > ().valor-1, attrID); // rank starts on 0 in genesys
                yylhs.value.as < obj_t > ().valor = value; }
#line 1707 "../GenesysParser.cpp"
    break;

  case 103: // pluginFunction: fMR "(" RESOURCE ")"
#line 524 "bisonparser.yy"
                                        { yylhs.value.as < obj_t > ().valor = ((Resource*)driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Resource>(), yystack_[1].value.as < obj_t > ().id))->getCapacity();}
#line 1713 "../GenesysParser.cpp"
    break;

  case 104: // pluginFunction: fNR "(" RESOURCE ")"
#line 525 "bisonparser.yy"
                                         { yylhs.value.as < obj_t > ().valor = ((Resource*)driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Resource>(), yystack_[1].value.as < obj_t > ().id))->getNumberBusy();}
#line 1719 "../GenesysParser.cpp"
    break;

  case 105: // pluginFunction: fRESSEIZES "(" RESOURCE ")"
#line 526 "bisonparser.yy"
                                         { /*\TODO: For now does nothing because needs get Seizes, check with teacher*/}
#line 1725 "../GenesysParser.cpp"
    break;

  case 106: // pluginFunction: fSTATE "(" RESOURCE ")"
#line 527 "bisonparser.yy"
                                         {  yylhs.value.as < obj_t > ().valor = static_cast<int>(((Resource*)driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Resource>(), yystack_[1].value.as < obj_t > ().id))->getResourceState()); }
#line 1731 "../GenesysParser.cpp"
    break;

  case 107: // pluginFunction: fIRF "(" RESOURCE ")"
#line 528 "bisonparser.yy"
                                         { yylhs.value.as < obj_t > ().valor = ((Resource*)driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Resource>(), yystack_[1].value.as < obj_t > ().id))->getResourceState() == Resource::ResourceState::FAILED ? 1 : 0; }
#line 1737 "../GenesysParser.cpp"
    break;

  case 108: // pluginFunction: fSETSUM "(" SET ")"
#line 529 "bisonparser.yy"
                              {
                unsigned int count=0;
                Resource* res;
                List<ModelDataDefinition*>* setList = ((Set*)driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Set>(),yystack_[1].value.as < obj_t > ().id))->getElementSet(); 
                for (std::list<ModelDataDefinition*>::iterator it = setList->list()->begin(); it!=setList->list()->end(); it++) {
                    res = dynamic_cast<Resource*>(*it);
                    if (res != nullptr) {
                        if (res->getResourceState()==Resource::ResourceState::BUSY) {
                            count++;
                        }
                    }
                }
                yylhs.value.as < obj_t > ().valor = count; }
#line 1755 "../GenesysParser.cpp"
    break;

  case 109: // pluginFunction: fNUMSET "(" SET ")"
#line 545 "bisonparser.yy"
                                { yylhs.value.as < obj_t > ().valor = ((Set*)driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Set>(),yystack_[1].value.as < obj_t > ().id))->getElementSet()->size(); }
#line 1761 "../GenesysParser.cpp"
    break;


#line 1765 "../GenesysParser.cpp"

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


  const short genesyspp_parser::yypact_ninf_ = -299;

  const signed char genesyspp_parser::yytable_ninf_ = -23;

  const short
  genesyspp_parser::yypact_[] =
  {
     334,   -79,  -299,  -299,  -299,   503,   -61,   -60,   -59,   -52,
     -51,   -48,   -42,   -39,   -38,   -37,  -299,   -36,   -33,   -32,
     -31,   -30,   -29,   -26,   -25,   -24,   -23,  -299,  -299,  -299,
    -299,  -299,   503,   -46,   -68,  -299,   -22,   -21,   -20,   -19,
     -18,   -17,   -16,   -15,   -14,   -13,   -12,   -10,    -7,   -66,
     -47,   503,   503,    -6,    28,  1695,  -299,  -299,  -299,  -299,
    -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,
    -299,  -299,  -299,  -299,  -299,   188,   503,   503,   503,   503,
     503,   503,   503,   503,   503,   503,   503,   503,   503,   503,
     503,   503,   503,   503,   503,   503,   421,    16,    34,     9,
      29,   503,   503,    19,    62,    64,    80,    81,    82,    68,
      76,    77,    78,    79,    83,    73,   503,   503,   503,  1038,
     -11,   503,  -299,   503,   503,   503,   503,   503,   503,   503,
     503,   503,   503,   503,   503,   503,   503,   503,  1048,  1058,
    1137,   767,  1147,  1157,  1167,  1177,  1187,  1197,  1276,   776,
     857,   866,   875,   884,   893,   902,   911,   920,   -70,   503,
    1284,   503,   503,   503,   503,   154,  1695,    67,    70,    71,
      72,    74,    75,    93,    94,    95,   104,    57,    65,   105,
     165,  1695,   577,  -299,  1294,    27,    27,    27,    27,   188,
     188,  1695,  1695,    21,    21,   -11,  1695,   -11,    27,    27,
    -299,  -299,  -299,   503,  -299,  -299,  -299,  -299,  -299,  -299,
    -299,   503,   503,   503,   503,   503,   503,   503,   503,   503,
    -299,   503,    18,   503,   587,   597,  1302,  1314,    63,   503,
    -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,
     103,   150,  -299,    96,   503,  -299,   503,  -299,  1324,  1334,
    1413,  1423,  1433,  1443,  1453,  1001,  1010,  1695,  1019,    27,
    -299,   503,  -299,   503,   503,   503,   503,   607,   107,    69,
     503,   617,   627,  -299,  -299,  -299,  -299,  -299,  -299,  -299,
     503,   503,   503,   637,   718,  1461,  1471,  1695,    98,   503,
    -299,   135,  1695,   100,   503,  -299,   503,  1550,  1028,  1695,
    -299,   503,  -299,   503,   -45,   -45,   503,  1558,   111,   503,
    1566,  1574,  -299,   503,  1582,  1590,   -65,   -64,  -299,  -299,
    1695,   102,  -299,  1695,   106,  -299,  1600,  -299,  -299,   503,
     503,   503,   503,  -299,   728,   738,  1695,  1695,    63,   503,
      96,   503,   748,   758,    98,   503,   100,   503,  1608,  1687,
     102,   106
  };

  const signed char
  genesyspp_parser::yydefact_[] =
  {
       0,     0,    15,    16,    97,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    63,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    46,    47,    48,
      49,    50,     0,     0,    77,    51,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    81,
      85,     0,     0,     0,     0,     2,     4,     8,     9,    10,
       6,    34,    35,     5,    43,    41,    40,    42,    45,    12,
      13,    14,     7,    44,     3,    27,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    77,    81,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      22,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      37,     0,     0,     0,     0,     0,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    93,     0,    11,     0,    30,    31,    32,    33,    23,
      24,    25,    26,    17,    18,    20,    21,    19,    28,    29,
      53,    54,    55,     0,    57,    56,    58,    59,    60,    61,
      64,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      73,     0,    18,     0,     0,     0,     0,     0,    78,     0,
      52,   104,   103,   107,   105,   106,   108,    98,   100,    99,
       0,     0,   109,    82,     0,    86,     0,    74,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    76,     0,    36,
      78,     0,    82,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    62,    65,    66,    67,    68,    69,    70,
       0,     0,     0,     0,     0,     0,     0,    90,    79,     0,
     101,     0,    94,    83,     0,    87,     0,     0,     0,    75,
      79,     0,    83,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    71,     0,     0,     0,     0,     0,    39,    38,
      91,    80,   102,    95,    84,    88,     0,    80,    84,     0,
       0,     0,     0,    72,     0,     0,    92,    96,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0
  };

  const short
  genesyspp_parser::yypgoto_[] =
  {
    -299,  -299,    -5,  -299,  -299,  -299,  -299,  -299,  -299,  -299,
    -299,  -299,  -299,  -299,  -299,  -299,  -299,   155,   156,  -299,
    -298,  -299
  };

  const unsigned char
  genesyspp_parser::yydefgoto_[] =
  {
       0,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,   158,    69,    70,    71,
      72,    73
  };

  const short
  genesyspp_parser::yytable_[] =
  {
      75,   129,   130,    97,   316,   220,   318,   319,   101,    74,
     116,   329,   330,    76,    77,    78,   221,   102,   -22,   117,
     102,   117,    79,    80,    98,   317,    81,    96,   122,   118,
     129,   130,    82,   129,   130,    83,    84,    85,    86,   129,
     130,    87,    88,    89,    90,    91,   119,   120,    92,    93,
      94,    95,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   -22,   114,   -22,   -22,   115,   121,   167,
     134,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   160,   161,   -22,   163,   -22,   165,   166,   -22,   134,
     -22,   133,   134,   135,   -22,   131,   132,   133,   134,   135,
     162,   180,   181,   182,   164,   168,   184,   169,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   170,   171,   172,   173,   174,   175,   176,
     177,   179,   230,   240,   178,   231,   232,   233,   266,   234,
     235,   241,   268,   269,   222,   291,   224,   225,   226,   227,
     123,   124,   125,   126,   127,   128,   129,   130,   236,   237,
     238,   123,   124,   125,   126,   127,   128,   129,   130,   239,
     242,   270,   290,   306,   308,   309,   322,   331,    99,   100,
       0,   332,     0,     0,   123,   124,   125,   126,   248,     0,
     129,   130,     0,     0,     0,     0,   249,   250,   251,   252,
     253,   254,   255,   256,   257,     0,   258,     0,   259,     0,
       0,     0,     0,     0,   267,     0,     0,     0,     0,     0,
       0,   228,   131,   132,   133,   134,   135,   136,   137,   271,
     229,   272,   243,   131,   132,   133,   134,   135,   136,   137,
       0,   244,     0,     0,     0,     0,   283,     0,   284,   285,
     286,   287,     0,     0,     0,   292,   131,   132,   133,   134,
     135,   136,   137,     0,     0,   297,   298,   299,     0,     0,
       0,     0,     0,     0,   307,     0,     0,     0,     0,   310,
       0,   311,     0,     0,     0,     0,   314,     0,   315,     0,
       0,   320,     0,     0,   323,     0,     0,     0,   326,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   334,   335,   336,   337,     0,     0,
       0,     0,     0,     0,   342,     1,   343,     2,     3,     4,
     348,     0,   349,     0,     0,     0,     0,     0,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,     0,
       0,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,     0,
      33,     0,     0,    34,    35,    36,     0,     0,    37,    38,
      39,    40,    41,    42,     0,     0,    43,    44,    45,    46,
      47,     0,     0,    48,    49,    50,     0,     0,    51,     0,
       0,     0,     0,    52,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,     2,     3,     4,   123,   124,   125,
     126,   127,   128,   129,   130,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,     0,     0,     0,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,     0,    33,     0,     0,
      34,    35,    36,     0,     0,    37,    38,    39,    40,    41,
      42,     0,     0,    43,    44,    45,    46,    47,     0,     0,
      48,    49,    50,     0,     0,    51,     0,     0,     0,   131,
     159,   133,   134,   135,   136,   137,     2,     3,     4,     0,
      53,     0,     0,     0,     0,     0,     0,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,     0,     0,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,     0,    33,
       0,     0,    34,    35,    36,     0,     0,    37,    38,    39,
      40,    41,    42,     0,     0,    43,    44,    45,    46,    47,
       0,     0,    48,    49,    50,     0,     0,    51,     0,     0,
       0,     0,    52,   123,   124,   125,   126,   127,   128,   129,
     130,     0,    53,   123,   124,   125,   126,   127,   128,   129,
     130,     0,     0,   123,   124,   125,   126,   127,   128,   129,
     130,     0,     0,   123,   124,   125,   126,   127,   128,   129,
     130,     0,     0,   123,   124,   125,   126,   127,   128,   129,
     130,     0,     0,   123,   124,   125,   126,   127,   128,   129,
     130,     0,     0,   123,   124,   125,   126,   127,   128,   129,
     130,     0,     0,     0,   245,   131,   132,   133,   134,   135,
     136,   137,     0,   246,   260,   131,   132,   133,   134,   135,
     136,   137,     0,   261,   262,   131,   132,   133,   134,   135,
     136,   137,     0,   263,   288,   131,   132,   133,   134,   135,
     136,   137,     0,   289,   293,   131,   132,   133,   134,   135,
     136,   137,     0,   294,   295,   131,   132,   133,   134,   135,
     136,   137,     0,   296,   300,   131,   132,   133,   134,   135,
     136,   137,     0,   301,   123,   124,   125,   126,   127,   128,
     129,   130,     0,     0,   123,   124,   125,   126,   127,   128,
     129,   130,     0,     0,   123,   124,   125,   126,   127,   128,
     129,   130,     0,     0,   123,   124,   125,   126,   127,   128,
     129,   130,     0,     0,   123,   124,   125,   126,   127,   128,
     129,   130,     0,   123,   124,   125,   126,   127,   128,   129,
     130,     0,   123,   124,   125,   126,   127,   128,   129,   130,
       0,     0,     0,     0,     0,   302,   131,   132,   133,   134,
     135,   136,   137,     0,   303,   338,   131,   132,   133,   134,
     135,   136,   137,     0,   339,   340,   131,   132,   133,   134,
     135,   136,   137,     0,   341,   344,   131,   132,   133,   134,
     135,   136,   137,     0,   345,   346,   131,   132,   133,   134,
     135,   136,   137,     0,   347,   131,   132,   133,   134,   135,
     136,   137,     0,   203,   131,   132,   133,   134,   135,   136,
     137,     0,   211,   123,   124,   125,   126,   127,   128,   129,
     130,     0,   123,   124,   125,   126,   127,   128,   129,   130,
       0,   123,   124,   125,   126,   127,   128,   129,   130,     0,
     123,   124,   125,   126,   127,   128,   129,   130,     0,   123,
     124,   125,   126,   127,   128,   129,   130,     0,   123,   124,
     125,   126,   127,   128,   129,   130,     0,   123,   124,   125,
     126,   127,   128,   129,   130,     0,   123,   124,   125,   126,
     127,   128,   129,   130,     0,   131,   132,   133,   134,   135,
     136,   137,     0,   212,   131,   132,   133,   134,   135,   136,
     137,     0,   213,   131,   132,   133,   134,   135,   136,   137,
       0,   214,   131,   132,   133,   134,   135,   136,   137,     0,
     215,   131,   132,   133,   134,   135,   136,   137,     0,   216,
     131,   132,   133,   134,   135,   136,   137,     0,   217,   131,
     132,   133,   134,   135,   136,   137,     0,   218,   131,   132,
     133,   134,   135,   136,   137,     0,   219,   123,   124,   125,
     126,   127,   128,   129,   130,     0,   123,   124,   125,   126,
     127,   128,   129,   130,     0,   123,   124,   125,   126,   127,
     128,   129,   130,     0,   123,   124,   125,   126,   127,   128,
     129,   130,     0,     0,   123,   124,   125,   126,   127,   128,
     129,   130,     0,     0,   123,   124,   125,   126,   127,   128,
     129,   130,     0,     0,   123,   124,   125,   126,   127,   128,
     129,   130,     0,     0,     0,     0,     0,     0,     0,   131,
     132,   133,   134,   135,   136,   137,     0,   280,   131,   132,
     133,   134,   135,   136,   137,     0,   281,   131,   132,   133,
     134,   135,   136,   137,     0,   282,   131,   132,   133,   134,
     135,   136,   137,   183,   313,     0,   131,   132,   133,   134,
     135,   136,   137,   200,     0,     0,   131,   132,   133,   134,
     135,   136,   137,   201,     0,     0,   131,   132,   133,   134,
     135,   136,   137,   123,   124,   125,   126,   127,   128,   129,
     130,     0,     0,   123,   124,   125,   126,   127,   128,   129,
     130,     0,     0,   123,   124,   125,   126,   127,   128,   129,
     130,     0,     0,   123,   124,   125,   126,   127,   128,   129,
     130,     0,     0,   123,   124,   125,   126,   127,   128,   129,
     130,     0,     0,   123,   124,   125,   126,   127,   128,   129,
     130,     0,     0,   123,   124,   125,   126,   127,   128,   129,
     130,     0,   202,     0,     0,   131,   132,   133,   134,   135,
     136,   137,   204,     0,     0,   131,   132,   133,   134,   135,
     136,   137,   205,     0,     0,   131,   132,   133,   134,   135,
     136,   137,   206,     0,     0,   131,   132,   133,   134,   135,
     136,   137,   207,     0,     0,   131,   132,   133,   134,   135,
     136,   137,   208,     0,     0,   131,   132,   133,   134,   135,
     136,   137,   209,     0,     0,   131,   132,   133,   134,   135,
     136,   137,   123,   124,   125,   126,   127,   128,   129,   130,
     123,   124,   125,   126,   127,   128,   129,   130,     0,     0,
     123,   124,   125,   126,   127,   128,   129,   130,   123,   124,
     125,   126,   127,   128,   129,   130,     0,     0,     0,     0,
     123,   124,   125,   126,   127,   128,   129,   130,     0,   223,
     123,   124,   125,   126,   127,   128,   129,   130,     0,     0,
     123,   124,   125,   126,   127,   128,   129,   130,     0,   264,
       0,   210,     0,     0,   131,   132,   133,   134,   135,   136,
     137,   265,   131,   132,   133,   134,   135,   136,   137,   247,
       0,     0,   131,   132,   133,   134,   135,   136,   137,     0,
     131,   132,   133,   134,   135,   136,   137,     0,     0,     0,
       0,     0,   131,   132,   133,   134,   135,   136,   137,   273,
       0,     0,   131,   132,   133,   134,   135,   136,   137,   274,
       0,     0,   131,   132,   133,   134,   135,   136,   137,   123,
     124,   125,   126,   127,   128,   129,   130,     0,     0,   123,
     124,   125,   126,   127,   128,   129,   130,     0,     0,   123,
     124,   125,   126,   127,   128,   129,   130,     0,     0,   123,
     124,   125,   126,   127,   128,   129,   130,     0,     0,   123,
     124,   125,   126,   127,   128,   129,   130,   123,   124,   125,
     126,   127,   128,   129,   130,     0,     0,   123,   124,   125,
     126,   127,   128,   129,   130,     0,     0,     0,   275,     0,
       0,   131,   132,   133,   134,   135,   136,   137,   276,     0,
       0,   131,   132,   133,   134,   135,   136,   137,   277,   304,
       0,   131,   132,   133,   134,   135,   136,   137,   278,   305,
       0,   131,   132,   133,   134,   135,   136,   137,   279,     0,
       0,   131,   132,   133,   134,   135,   136,   137,     0,   131,
     132,   133,   134,   135,   136,   137,     0,     0,     0,   131,
     132,   133,   134,   135,   136,   137,   123,   124,   125,   126,
     127,   128,   129,   130,   123,   124,   125,   126,   127,   128,
     129,   130,   123,   124,   125,   126,   127,   128,   129,   130,
     123,   124,   125,   126,   127,   128,   129,   130,   123,   124,
     125,   126,   127,   128,   129,   130,   123,   124,   125,   126,
     127,   128,   129,   130,     0,     0,   123,   124,   125,   126,
     127,   128,   129,   130,   123,   124,   125,   126,   127,   128,
     129,   130,     0,     0,     0,   312,     0,     0,   131,   132,
     133,   134,   135,   136,   137,   321,   131,   132,   133,   134,
     135,   136,   137,   324,   131,   132,   133,   134,   135,   136,
     137,   325,   131,   132,   133,   134,   135,   136,   137,   327,
     131,   132,   133,   134,   135,   136,   137,   328,   131,   132,
     133,   134,   135,   136,   137,   333,     0,     0,   131,   132,
     133,   134,   135,   136,   137,   350,   131,   132,   133,   134,
     135,   136,   137,   123,   124,   125,   126,   127,   128,   129,
     130,   123,   124,   125,   126,   127,   128,   129,   130,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   351,   131,   132,   133,   134,   135,
     136,   137,     0,   131,   132,   133,   134,   135,   136,   137
  };

  const short
  genesyspp_parser::yycheck_[] =
  {
       5,    12,    13,    49,    49,    75,   304,   305,    76,    88,
      76,    76,    76,    74,    74,    74,    86,    85,     0,    85,
      85,    85,    74,    74,    70,    70,    74,    32,     0,    76,
      12,    13,    74,    12,    13,    74,    74,    74,    74,    12,
      13,    74,    74,    74,    74,    74,    51,    52,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    45,    74,    47,    48,    74,    74,    50,
      81,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    76,    75,    85,    77,   101,   102,    80,    81,
      82,    80,    81,    82,    86,    78,    79,    80,    81,    82,
      76,   116,   117,   118,    85,    53,   121,    53,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,    53,    53,    53,    68,    61,    61,    61,
      61,    68,    75,    86,    61,    75,    75,    75,    85,    75,
      75,    86,    49,     3,   159,    86,   161,   162,   163,   164,
       6,     7,     8,     9,    10,    11,    12,    13,    75,    75,
      75,     6,     7,     8,     9,    10,    11,    12,    13,    75,
      75,    85,    75,    85,    49,    85,    75,    85,    33,    33,
      -1,    85,    -1,    -1,     6,     7,     8,     9,   203,    -1,
      12,    13,    -1,    -1,    -1,    -1,   211,   212,   213,   214,
     215,   216,   217,   218,   219,    -1,   221,    -1,   223,    -1,
      -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,
      -1,    77,    78,    79,    80,    81,    82,    83,    84,   244,
      86,   246,    77,    78,    79,    80,    81,    82,    83,    84,
      -1,    86,    -1,    -1,    -1,    -1,   261,    -1,   263,   264,
     265,   266,    -1,    -1,    -1,   270,    78,    79,    80,    81,
      82,    83,    84,    -1,    -1,   280,   281,   282,    -1,    -1,
      -1,    -1,    -1,    -1,   289,    -1,    -1,    -1,    -1,   294,
      -1,   296,    -1,    -1,    -1,    -1,   301,    -1,   303,    -1,
      -1,   306,    -1,    -1,   309,    -1,    -1,    -1,   313,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   329,   330,   331,   332,    -1,    -1,
      -1,    -1,    -1,    -1,   339,     1,   341,     3,     4,     5,
     345,    -1,   347,    -1,    -1,    -1,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
      46,    -1,    -1,    49,    50,    51,    -1,    -1,    54,    55,
      56,    57,    58,    59,    -1,    -1,    62,    63,    64,    65,
      66,    -1,    -1,    69,    70,    71,    -1,    -1,    74,    -1,
      -1,    -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    89,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    -1,    46,    -1,    -1,
      49,    50,    51,    -1,    -1,    54,    55,    56,    57,    58,
      59,    -1,    -1,    62,    63,    64,    65,    66,    -1,    -1,
      69,    70,    71,    -1,    -1,    74,    -1,    -1,    -1,    78,
      79,    80,    81,    82,    83,    84,     3,     4,     5,    -1,
      89,    -1,    -1,    -1,    -1,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    -1,    46,
      -1,    -1,    49,    50,    51,    -1,    -1,    54,    55,    56,
      57,    58,    59,    -1,    -1,    62,    63,    64,    65,    66,
      -1,    -1,    69,    70,    71,    -1,    -1,    74,    -1,    -1,
      -1,    -1,    79,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,    89,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,    -1,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,    -1,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,    -1,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,    -1,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,    -1,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,    -1,    -1,    77,    78,    79,    80,    81,    82,
      83,    84,    -1,    86,    77,    78,    79,    80,    81,    82,
      83,    84,    -1,    86,    77,    78,    79,    80,    81,    82,
      83,    84,    -1,    86,    77,    78,    79,    80,    81,    82,
      83,    84,    -1,    86,    77,    78,    79,    80,    81,    82,
      83,    84,    -1,    86,    77,    78,    79,    80,    81,    82,
      83,    84,    -1,    86,    77,    78,    79,    80,    81,    82,
      83,    84,    -1,    86,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,    -1,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,    -1,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,    -1,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,    -1,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,     6,     7,     8,     9,    10,    11,    12,    13,
      -1,    -1,    -1,    -1,    -1,    77,    78,    79,    80,    81,
      82,    83,    84,    -1,    86,    77,    78,    79,    80,    81,
      82,    83,    84,    -1,    86,    77,    78,    79,    80,    81,
      82,    83,    84,    -1,    86,    77,    78,    79,    80,    81,
      82,    83,    84,    -1,    86,    77,    78,    79,    80,    81,
      82,    83,    84,    -1,    86,    78,    79,    80,    81,    82,
      83,    84,    -1,    86,    78,    79,    80,    81,    82,    83,
      84,    -1,    86,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,     6,     7,     8,     9,    10,    11,    12,    13,
      -1,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
       6,     7,     8,     9,    10,    11,    12,    13,    -1,     6,
       7,     8,     9,    10,    11,    12,    13,    -1,     6,     7,
       8,     9,    10,    11,    12,    13,    -1,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,     6,     7,     8,     9,
      10,    11,    12,    13,    -1,    78,    79,    80,    81,    82,
      83,    84,    -1,    86,    78,    79,    80,    81,    82,    83,
      84,    -1,    86,    78,    79,    80,    81,    82,    83,    84,
      -1,    86,    78,    79,    80,    81,    82,    83,    84,    -1,
      86,    78,    79,    80,    81,    82,    83,    84,    -1,    86,
      78,    79,    80,    81,    82,    83,    84,    -1,    86,    78,
      79,    80,    81,    82,    83,    84,    -1,    86,    78,    79,
      80,    81,    82,    83,    84,    -1,    86,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,     6,     7,     8,     9,
      10,    11,    12,    13,    -1,     6,     7,     8,     9,    10,
      11,    12,    13,    -1,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,    -1,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,    -1,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,    -1,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      79,    80,    81,    82,    83,    84,    -1,    86,    78,    79,
      80,    81,    82,    83,    84,    -1,    86,    78,    79,    80,
      81,    82,    83,    84,    -1,    86,    78,    79,    80,    81,
      82,    83,    84,    75,    86,    -1,    78,    79,    80,    81,
      82,    83,    84,    75,    -1,    -1,    78,    79,    80,    81,
      82,    83,    84,    75,    -1,    -1,    78,    79,    80,    81,
      82,    83,    84,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,    -1,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,    -1,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,    -1,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,    -1,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,    -1,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,    -1,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,    75,    -1,    -1,    78,    79,    80,    81,    82,
      83,    84,    75,    -1,    -1,    78,    79,    80,    81,    82,
      83,    84,    75,    -1,    -1,    78,    79,    80,    81,    82,
      83,    84,    75,    -1,    -1,    78,    79,    80,    81,    82,
      83,    84,    75,    -1,    -1,    78,    79,    80,    81,    82,
      83,    84,    75,    -1,    -1,    78,    79,    80,    81,    82,
      83,    84,    75,    -1,    -1,    78,    79,    80,    81,    82,
      83,    84,     6,     7,     8,     9,    10,    11,    12,    13,
       6,     7,     8,     9,    10,    11,    12,    13,    -1,    -1,
       6,     7,     8,     9,    10,    11,    12,    13,     6,     7,
       8,     9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,
       6,     7,     8,     9,    10,    11,    12,    13,    -1,    45,
       6,     7,     8,     9,    10,    11,    12,    13,    -1,    -1,
       6,     7,     8,     9,    10,    11,    12,    13,    -1,    47,
      -1,    75,    -1,    -1,    78,    79,    80,    81,    82,    83,
      84,    47,    78,    79,    80,    81,    82,    83,    84,    75,
      -1,    -1,    78,    79,    80,    81,    82,    83,    84,    -1,
      78,    79,    80,    81,    82,    83,    84,    -1,    -1,    -1,
      -1,    -1,    78,    79,    80,    81,    82,    83,    84,    75,
      -1,    -1,    78,    79,    80,    81,    82,    83,    84,    75,
      -1,    -1,    78,    79,    80,    81,    82,    83,    84,     6,
       7,     8,     9,    10,    11,    12,    13,    -1,    -1,     6,
       7,     8,     9,    10,    11,    12,    13,    -1,    -1,     6,
       7,     8,     9,    10,    11,    12,    13,    -1,    -1,     6,
       7,     8,     9,    10,    11,    12,    13,    -1,    -1,     6,
       7,     8,     9,    10,    11,    12,    13,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    -1,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    -1,    -1,    75,    -1,
      -1,    78,    79,    80,    81,    82,    83,    84,    75,    -1,
      -1,    78,    79,    80,    81,    82,    83,    84,    75,    48,
      -1,    78,    79,    80,    81,    82,    83,    84,    75,    48,
      -1,    78,    79,    80,    81,    82,    83,    84,    75,    -1,
      -1,    78,    79,    80,    81,    82,    83,    84,    -1,    78,
      79,    80,    81,    82,    83,    84,    -1,    -1,    -1,    78,
      79,    80,    81,    82,    83,    84,     6,     7,     8,     9,
      10,    11,    12,    13,     6,     7,     8,     9,    10,    11,
      12,    13,     6,     7,     8,     9,    10,    11,    12,    13,
       6,     7,     8,     9,    10,    11,    12,    13,     6,     7,
       8,     9,    10,    11,    12,    13,     6,     7,     8,     9,
      10,    11,    12,    13,    -1,    -1,     6,     7,     8,     9,
      10,    11,    12,    13,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,    -1,    -1,    75,    -1,    -1,    78,    79,
      80,    81,    82,    83,    84,    77,    78,    79,    80,    81,
      82,    83,    84,    77,    78,    79,    80,    81,    82,    83,
      84,    77,    78,    79,    80,    81,    82,    83,    84,    77,
      78,    79,    80,    81,    82,    83,    84,    77,    78,    79,
      80,    81,    82,    83,    84,    75,    -1,    -1,    78,    79,
      80,    81,    82,    83,    84,    77,    78,    79,    80,    81,
      82,    83,    84,     6,     7,     8,     9,    10,    11,    12,
      13,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    77,    78,    79,    80,    81,    82,
      83,    84,    -1,    78,    79,    80,    81,    82,    83,    84
  };

  const signed char
  genesyspp_parser::yystos_[] =
  {
       0,     1,     3,     4,     5,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    46,    49,    50,    51,    54,    55,    56,
      57,    58,    59,    62,    63,    64,    65,    66,    69,    70,
      71,    74,    79,    89,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   107,
     108,   109,   110,   111,    88,    92,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    92,    49,    70,   107,
     108,    76,    85,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    76,    85,    76,    92,
      92,    74,     0,     6,     7,     8,     9,    10,    11,    12,
      13,    78,    79,    80,    81,    82,    83,    84,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,   106,    79,
      92,    76,    76,    85,    85,    92,    92,    50,    53,    53,
      53,    53,    53,    68,    61,    61,    61,    61,    61,    68,
      92,    92,    92,    75,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      75,    75,    75,    86,    75,    75,    75,    75,    75,    75,
      75,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      75,    86,    92,    45,    92,    92,    92,    92,    77,    86,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      86,    86,    75,    77,    86,    77,    86,    75,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      77,    86,    77,    86,    47,    47,    85,    92,    49,     3,
      85,    92,    92,    75,    75,    75,    75,    75,    75,    75,
      86,    86,    86,    92,    92,    92,    92,    92,    77,    86,
      75,    86,    92,    77,    86,    77,    86,    92,    92,    92,
      77,    86,    77,    86,    48,    48,    85,    92,    49,    85,
      92,    92,    75,    86,    92,    92,    49,    70,   110,   110,
      92,    77,    75,    92,    77,    77,    92,    77,    77,    76,
      76,    85,    85,    75,    92,    92,    92,    92,    77,    86,
      77,    86,    92,    92,    77,    86,    77,    86,    92,    92,
      77,    77
  };

  const signed char
  genesyspp_parser::yyr1_[] =
  {
       0,    90,    91,    91,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    93,    93,    94,    94,    94,
      94,    94,    94,    95,    95,    95,    95,    95,    96,    96,
      96,    96,    96,    96,    97,    97,    98,    98,    99,    99,
     100,   100,   100,   100,   100,   100,   101,   101,   101,   101,
     101,   101,   101,   102,   102,   103,   103,   103,   103,   103,
     103,   103,   103,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   105,   106,   106,   107,   107,   107,
     107,   108,   108,   108,   108,   109,   109,   109,   109,   110,
     110,   110,   110,   110,   110,   110,   110,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111
  };

  const signed char
  genesyspp_parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     2,     3,     3,     3,     3,     2,     3,     3,
       3,     3,     3,     3,     1,     1,     5,     3,     8,     8,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     6,     1,     4,     6,     6,     6,     6,     6,
       6,     8,    10,     4,     4,     5,     3,     1,     4,     6,
       8,     1,     4,     6,     8,     1,     4,     6,     8,     3,
       6,     8,    10,     3,     6,     8,    10,     1,     4,     4,
       4,     6,     8,     4,     4,     4,     4,     4,     4,     4
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const genesyspp_parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "NUMD", "NUMH",
  "CTEZERO", "oLE", "oGE", "oEQ", "oNE", "oAND", "oOR", "oNAND", "oXOR",
  "oNOT", "fSIN", "fCOS", "fROUND", "fMOD", "fTRUNC", "fFRAC", "fEXP",
  "fSQRT", "fLOG", "fLN", "fVAL", "fEVAL", "fLENG", "fRND1", "fEXPO",
  "fNORM", "fUNIF", "fWEIB", "fLOGN", "fGAMM", "fERLA", "fTRIA", "fBETA",
  "fDISC", "fTNOW", "fTFIN", "fMAXREP", "fNUMREP", "fIDENT", "cIF",
  "cELSE", "cFOR", "cTO", "cDO", "ATRIB", "CSTAT", "fTAVG", "ILLEGAL",
  "RESOURCE", "fNR", "fMR", "fIRF", "fRESSEIZES", "fSTATE", "fSETSUM",
  "fRESUTIL", "QUEUE", "fNQ", "fFIRSTINQ", "fLASTINQ", "fSAQUE", "fAQUE",
  "fENTATRANK", "SET", "fNUMSET", "VARI", "FORM", "fNUMGR", "fATRGR",
  "\"(\"", "\")\"", "\"[\"", "\"]\"", "\"+\"", "\"-\"", "\"*\"", "\"^\"",
  "\"/\"", "\"<\"", "\">\"", "\"=\"", "\",\"", "NEG", "'\\n'", "\"USER\"",
  "$accept", "input", "expression", "numero", "aritmetica", "logica",
  "relacional", "comando", "comandoIF", "comandoFOR", "function",
  "kernelFunction", "trigonFunction", "mathFunction", "probFunction",
  "userFunction", "listaparm", "atributo", "variavel", "formula",
  "atribuicao", "pluginFunction", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  genesyspp_parser::yyrline_[] =
  {
       0,   225,   225,   226,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   243,   247,   254,   255,   259,   260,   261,
     262,   263,   264,   268,   269,   270,   271,   272,   276,   277,
     278,   279,   280,   281,   285,   286,   290,   291,   296,   297,
     301,   302,   303,   304,   305,   306,   310,   311,   312,   313,
     314,   315,   316,   323,   324,   328,   329,   330,   331,   332,
     333,   334,   335,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   355,   360,   361,   387,   396,   405,
     414,   428,   429,   432,   435,   443,   445,   448,   451,   459,
     462,   466,   470,   476,   479,   483,   487,   498,   501,   503,
     504,   511,   516,   524,   525,   526,   527,   528,   529,   545
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
#line 2729 "../GenesysParser.cpp"

#line 552 "bisonparser.yy"

void
yy::genesyspp_parser::error (const location_type& l,
                          const std::string& m)
{
  driver.error (l, m);
}
