// A Bison parser, made by GNU Bison 3.8.2.

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
#line 57 "bisonparser.yy"

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

  /*---------.
  | symbol.  |
  `---------*/



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
      case symbol_kind::S_COUNTER: // COUNTER
      case symbol_kind::S_fTAVG: // fTAVG
      case symbol_kind::S_fCOUNT: // fCOUNT
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
      case symbol_kind::S_elementFunction: // elementFunction
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
      case symbol_kind::S_COUNTER: // COUNTER
      case symbol_kind::S_fTAVG: // fTAVG
      case symbol_kind::S_fCOUNT: // fCOUNT
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
      case symbol_kind::S_elementFunction: // elementFunction
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
      case symbol_kind::S_COUNTER: // COUNTER
      case symbol_kind::S_fTAVG: // fTAVG
      case symbol_kind::S_fCOUNT: // fCOUNT
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
      case symbol_kind::S_elementFunction: // elementFunction
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
      case symbol_kind::S_COUNTER: // COUNTER
      case symbol_kind::S_fTAVG: // fTAVG
      case symbol_kind::S_fCOUNT: // fCOUNT
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
      case symbol_kind::S_elementFunction: // elementFunction
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
  genesyspp_parser::yypop_ (int n) YY_NOEXCEPT
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
  genesyspp_parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  genesyspp_parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
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
#line 50 "bisonparser.yy"
{
  // Initialize the initial location.
  //@$.begin.filename = @$.end.filename = &driver.getFile();
}

#line 801 "../GenesysParser.cpp"


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
      case symbol_kind::S_COUNTER: // COUNTER
      case symbol_kind::S_fTAVG: // fTAVG
      case symbol_kind::S_fCOUNT: // fCOUNT
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
      case symbol_kind::S_elementFunction: // elementFunction
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
#line 240 "bisonparser.yy"
                    { driver.setResult(yystack_[0].value.as < obj_t > ().valor);}
#line 1037 "../GenesysParser.cpp"
    break;

  case 3: // input: error '\n'
#line 241 "bisonparser.yy"
                        { yyerrok; }
#line 1043 "../GenesysParser.cpp"
    break;

  case 4: // expression: numero
#line 245 "bisonparser.yy"
                                       {yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1049 "../GenesysParser.cpp"
    break;

  case 5: // expression: function
#line 246 "bisonparser.yy"
                                       {yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1055 "../GenesysParser.cpp"
    break;

  case 6: // expression: comando
#line 247 "bisonparser.yy"
                                       {yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1061 "../GenesysParser.cpp"
    break;

  case 7: // expression: atribuicao
#line 248 "bisonparser.yy"
                                       {yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1067 "../GenesysParser.cpp"
    break;

  case 8: // expression: aritmetica
#line 249 "bisonparser.yy"
                                           {yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1073 "../GenesysParser.cpp"
    break;

  case 9: // expression: logica
#line 250 "bisonparser.yy"
                                       {yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1079 "../GenesysParser.cpp"
    break;

  case 10: // expression: relacional
#line 251 "bisonparser.yy"
                                       {yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1085 "../GenesysParser.cpp"
    break;

  case 11: // expression: "(" expression ")"
#line 252 "bisonparser.yy"
                                       {yylhs.value.as < obj_t > ().valor = yystack_[1].value.as < obj_t > ().valor;}
#line 1091 "../GenesysParser.cpp"
    break;

  case 12: // expression: atributo
#line 253 "bisonparser.yy"
                                       {yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1097 "../GenesysParser.cpp"
    break;

  case 13: // expression: variavel
#line 258 "bisonparser.yy"
                                                   {yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1103 "../GenesysParser.cpp"
    break;

  case 14: // expression: formula
#line 262 "bisonparser.yy"
                                                   {yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1109 "../GenesysParser.cpp"
    break;

  case 15: // numero: NUMD
#line 269 "bisonparser.yy"
              { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1115 "../GenesysParser.cpp"
    break;

  case 16: // numero: NUMH
#line 270 "bisonparser.yy"
              { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1121 "../GenesysParser.cpp"
    break;

  case 17: // aritmetica: expression "+" expression
#line 274 "bisonparser.yy"
                                     { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor + yystack_[0].value.as < obj_t > ().valor;}
#line 1127 "../GenesysParser.cpp"
    break;

  case 18: // aritmetica: expression "-" expression
#line 275 "bisonparser.yy"
                                     { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor - yystack_[0].value.as < obj_t > ().valor;}
#line 1133 "../GenesysParser.cpp"
    break;

  case 19: // aritmetica: expression "/" expression
#line 276 "bisonparser.yy"
                                     { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor / yystack_[0].value.as < obj_t > ().valor;}
#line 1139 "../GenesysParser.cpp"
    break;

  case 20: // aritmetica: expression "*" expression
#line 277 "bisonparser.yy"
                                     { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor * yystack_[0].value.as < obj_t > ().valor;}
#line 1145 "../GenesysParser.cpp"
    break;

  case 21: // aritmetica: expression "^" expression
#line 278 "bisonparser.yy"
                                     { yylhs.value.as < obj_t > ().valor = pow(yystack_[2].value.as < obj_t > ().valor,yystack_[0].value.as < obj_t > ().valor);}
#line 1151 "../GenesysParser.cpp"
    break;

  case 22: // aritmetica: "-" expression
#line 279 "bisonparser.yy"
                                     { yylhs.value.as < obj_t > ().valor = -yystack_[0].value.as < obj_t > ().valor;}
#line 1157 "../GenesysParser.cpp"
    break;

  case 23: // logica: expression oAND expression
#line 283 "bisonparser.yy"
                                    { yylhs.value.as < obj_t > ().valor = (int) yystack_[2].value.as < obj_t > ().valor && (int) yystack_[0].value.as < obj_t > ().valor;}
#line 1163 "../GenesysParser.cpp"
    break;

  case 24: // logica: expression oOR expression
#line 284 "bisonparser.yy"
                                    { yylhs.value.as < obj_t > ().valor = (int) yystack_[2].value.as < obj_t > ().valor || (int) yystack_[0].value.as < obj_t > ().valor;}
#line 1169 "../GenesysParser.cpp"
    break;

  case 25: // logica: expression oNAND expression
#line 285 "bisonparser.yy"
                                    { yylhs.value.as < obj_t > ().valor = !((int) yystack_[2].value.as < obj_t > ().valor && (int) yystack_[0].value.as < obj_t > ().valor);}
#line 1175 "../GenesysParser.cpp"
    break;

  case 26: // logica: expression oXOR expression
#line 286 "bisonparser.yy"
                                    { yylhs.value.as < obj_t > ().valor = (!(int) yystack_[2].value.as < obj_t > ().valor && (int) yystack_[0].value.as < obj_t > ().valor) || ((int) yystack_[2].value.as < obj_t > ().valor && !(int) yystack_[0].value.as < obj_t > ().valor);}
#line 1181 "../GenesysParser.cpp"
    break;

  case 27: // logica: oNOT expression
#line 287 "bisonparser.yy"
                                    { yylhs.value.as < obj_t > ().valor = !(int) yystack_[0].value.as < obj_t > ().valor;}
#line 1187 "../GenesysParser.cpp"
    break;

  case 28: // relacional: expression "<" expression
#line 291 "bisonparser.yy"
                                         { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor < yystack_[0].value.as < obj_t > ().valor ? 1 : 0;}
#line 1193 "../GenesysParser.cpp"
    break;

  case 29: // relacional: expression ">" expression
#line 292 "bisonparser.yy"
                                         { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor > yystack_[0].value.as < obj_t > ().valor ? 1 : 0;}
#line 1199 "../GenesysParser.cpp"
    break;

  case 30: // relacional: expression oLE expression
#line 293 "bisonparser.yy"
                                         { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor <= yystack_[0].value.as < obj_t > ().valor ? 1 : 0;}
#line 1205 "../GenesysParser.cpp"
    break;

  case 31: // relacional: expression oGE expression
#line 294 "bisonparser.yy"
                                         { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor >= yystack_[0].value.as < obj_t > ().valor ? 1 : 0;}
#line 1211 "../GenesysParser.cpp"
    break;

  case 32: // relacional: expression oEQ expression
#line 295 "bisonparser.yy"
                                         { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor == yystack_[0].value.as < obj_t > ().valor ? 1 : 0;}
#line 1217 "../GenesysParser.cpp"
    break;

  case 33: // relacional: expression oNE expression
#line 296 "bisonparser.yy"
                                         { yylhs.value.as < obj_t > ().valor = yystack_[2].value.as < obj_t > ().valor != yystack_[0].value.as < obj_t > ().valor ? 1 : 0;}
#line 1223 "../GenesysParser.cpp"
    break;

  case 34: // comando: comandoIF
#line 300 "bisonparser.yy"
                    { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1229 "../GenesysParser.cpp"
    break;

  case 35: // comando: comandoFOR
#line 301 "bisonparser.yy"
                    { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1235 "../GenesysParser.cpp"
    break;

  case 36: // comandoIF: cIF expression expression cELSE expression
#line 305 "bisonparser.yy"
                                                   { yylhs.value.as < obj_t > ().valor = yystack_[3].value.as < obj_t > ().valor != 0 ? yystack_[2].value.as < obj_t > ().valor : yystack_[0].value.as < obj_t > ().valor; }
#line 1241 "../GenesysParser.cpp"
    break;

  case 37: // comandoIF: cIF expression expression
#line 306 "bisonparser.yy"
                                                  { yylhs.value.as < obj_t > ().valor = yystack_[1].value.as < obj_t > ().valor != 0 ? yystack_[0].value.as < obj_t > ().valor : 0;}
#line 1247 "../GenesysParser.cpp"
    break;

  case 38: // comandoFOR: cFOR variavel "=" expression cTO expression cDO atribuicao
#line 311 "bisonparser.yy"
                                                                 {yylhs.value.as < obj_t > ().valor = 0; }
#line 1253 "../GenesysParser.cpp"
    break;

  case 39: // comandoFOR: cFOR atributo "=" expression cTO expression cDO atribuicao
#line 312 "bisonparser.yy"
                                                                  {yylhs.value.as < obj_t > ().valor = 0; }
#line 1259 "../GenesysParser.cpp"
    break;

  case 40: // function: mathFunction
#line 316 "bisonparser.yy"
                         { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1265 "../GenesysParser.cpp"
    break;

  case 41: // function: trigonFunction
#line 317 "bisonparser.yy"
                         { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1271 "../GenesysParser.cpp"
    break;

  case 42: // function: probFunction
#line 318 "bisonparser.yy"
                         { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1277 "../GenesysParser.cpp"
    break;

  case 43: // function: kernelFunction
#line 319 "bisonparser.yy"
                         { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1283 "../GenesysParser.cpp"
    break;

  case 44: // function: pluginFunction
#line 320 "bisonparser.yy"
                         { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1289 "../GenesysParser.cpp"
    break;

  case 45: // function: userFunction
#line 321 "bisonparser.yy"
                         { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1295 "../GenesysParser.cpp"
    break;

  case 46: // function: elementFunction
#line 322 "bisonparser.yy"
                         { yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1301 "../GenesysParser.cpp"
    break;

  case 47: // kernelFunction: fTNOW
#line 326 "bisonparser.yy"
                 { yylhs.value.as < obj_t > ().valor = driver.getModel()->getSimulation()->getSimulatedTime();}
#line 1307 "../GenesysParser.cpp"
    break;

  case 48: // kernelFunction: fTFIN
#line 327 "bisonparser.yy"
                 { yylhs.value.as < obj_t > ().valor = driver.getModel()->getSimulation()->getReplicationLength();}
#line 1313 "../GenesysParser.cpp"
    break;

  case 49: // kernelFunction: fMAXREP
#line 328 "bisonparser.yy"
                 { yylhs.value.as < obj_t > ().valor = driver.getModel()->getSimulation()->getNumberOfReplications();}
#line 1319 "../GenesysParser.cpp"
    break;

  case 50: // kernelFunction: fNUMREP
#line 329 "bisonparser.yy"
                 { yylhs.value.as < obj_t > ().valor = driver.getModel()->getSimulation()->getCurrentReplicationNumber();}
#line 1325 "../GenesysParser.cpp"
    break;

  case 51: // kernelFunction: fIDENT
#line 330 "bisonparser.yy"
                 { yylhs.value.as < obj_t > ().valor = driver.getModel()->getSimulation()->getCurrentEvent()->getEntity()->getId();}
#line 1331 "../GenesysParser.cpp"
    break;

  case 53: // elementFunction: fTAVG "(" CSTAT ")"
#line 335 "bisonparser.yy"
                               {
                    StatisticsCollector* cstat = ((StatisticsCollector*)(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<StatisticsCollector>(), yystack_[1].value.as < obj_t > ().id)));
                    double value = cstat->getStatistics()->average();
                    yylhs.value.as < obj_t > ().valor = value; }
#line 1340 "../GenesysParser.cpp"
    break;

  case 54: // elementFunction: fCOUNT "(" COUNTER ")"
#line 339 "bisonparser.yy"
                                 {
					Counter* counter = ((Counter*)(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Counter>(), yystack_[1].value.as < obj_t > ().id)));
                    double value = counter->getCountValue();
                    yylhs.value.as < obj_t > ().valor = value; }
#line 1349 "../GenesysParser.cpp"
    break;

  case 55: // trigonFunction: fSIN "(" expression ")"
#line 346 "bisonparser.yy"
                                  { yylhs.value.as < obj_t > ().valor = sin(yystack_[1].value.as < obj_t > ().valor); }
#line 1355 "../GenesysParser.cpp"
    break;

  case 56: // trigonFunction: fCOS "(" expression ")"
#line 347 "bisonparser.yy"
                                  { yylhs.value.as < obj_t > ().valor = cos(yystack_[1].value.as < obj_t > ().valor); }
#line 1361 "../GenesysParser.cpp"
    break;

  case 57: // mathFunction: fROUND "(" expression ")"
#line 351 "bisonparser.yy"
                                        { yylhs.value.as < obj_t > ().valor = round(yystack_[1].value.as < obj_t > ().valor);}
#line 1367 "../GenesysParser.cpp"
    break;

  case 58: // mathFunction: fFRAC "(" expression ")"
#line 352 "bisonparser.yy"
                                        { yylhs.value.as < obj_t > ().valor = yystack_[1].value.as < obj_t > ().valor - (int) yystack_[1].value.as < obj_t > ().valor;}
#line 1373 "../GenesysParser.cpp"
    break;

  case 59: // mathFunction: fTRUNC "(" expression ")"
#line 353 "bisonparser.yy"
                                        { yylhs.value.as < obj_t > ().valor = trunc(yystack_[1].value.as < obj_t > ().valor);}
#line 1379 "../GenesysParser.cpp"
    break;

  case 60: // mathFunction: fEXP "(" expression ")"
#line 354 "bisonparser.yy"
                                    { yylhs.value.as < obj_t > ().valor = exp(yystack_[1].value.as < obj_t > ().valor);}
#line 1385 "../GenesysParser.cpp"
    break;

  case 61: // mathFunction: fSQRT "(" expression ")"
#line 355 "bisonparser.yy"
                                    { yylhs.value.as < obj_t > ().valor = sqrt(yystack_[1].value.as < obj_t > ().valor);}
#line 1391 "../GenesysParser.cpp"
    break;

  case 62: // mathFunction: fLOG "(" expression ")"
#line 356 "bisonparser.yy"
                                    { yylhs.value.as < obj_t > ().valor = log10(yystack_[1].value.as < obj_t > ().valor);}
#line 1397 "../GenesysParser.cpp"
    break;

  case 63: // mathFunction: fLN "(" expression ")"
#line 357 "bisonparser.yy"
                                    { yylhs.value.as < obj_t > ().valor = log(yystack_[1].value.as < obj_t > ().valor);}
#line 1403 "../GenesysParser.cpp"
    break;

  case 64: // mathFunction: fMOD "(" expression "," expression ")"
#line 358 "bisonparser.yy"
                                               { yylhs.value.as < obj_t > ().valor = (int) yystack_[3].value.as < obj_t > ().valor % (int) yystack_[1].value.as < obj_t > ().valor; }
#line 1409 "../GenesysParser.cpp"
    break;

  case 65: // probFunction: fRND1
#line 362 "bisonparser.yy"
                                                     { yylhs.value.as < obj_t > ().valor = driver.sampler()->sampleUniform(0.0,1.0);}
#line 1415 "../GenesysParser.cpp"
    break;

  case 66: // probFunction: fEXPO "(" expression ")"
#line 363 "bisonparser.yy"
                                     { yylhs.value.as < obj_t > ().valor = driver.sampler()->sampleExponential(yystack_[1].value.as < obj_t > ().valor);}
#line 1421 "../GenesysParser.cpp"
    break;

  case 67: // probFunction: fNORM "(" expression "," expression ")"
#line 364 "bisonparser.yy"
                                                { yylhs.value.as < obj_t > ().valor = driver.sampler()->sampleNormal(yystack_[3].value.as < obj_t > ().valor,yystack_[1].value.as < obj_t > ().valor);}
#line 1427 "../GenesysParser.cpp"
    break;

  case 68: // probFunction: fUNIF "(" expression "," expression ")"
#line 365 "bisonparser.yy"
                                                { yylhs.value.as < obj_t > ().valor = driver.sampler()->sampleUniform(yystack_[3].value.as < obj_t > ().valor,yystack_[1].value.as < obj_t > ().valor);}
#line 1433 "../GenesysParser.cpp"
    break;

  case 69: // probFunction: fWEIB "(" expression "," expression ")"
#line 366 "bisonparser.yy"
                                                { yylhs.value.as < obj_t > ().valor = driver.sampler()->sampleWeibull(yystack_[3].value.as < obj_t > ().valor,yystack_[1].value.as < obj_t > ().valor);}
#line 1439 "../GenesysParser.cpp"
    break;

  case 70: // probFunction: fLOGN "(" expression "," expression ")"
#line 367 "bisonparser.yy"
                                                { yylhs.value.as < obj_t > ().valor = driver.sampler()->sampleLogNormal(yystack_[3].value.as < obj_t > ().valor,yystack_[1].value.as < obj_t > ().valor);}
#line 1445 "../GenesysParser.cpp"
    break;

  case 71: // probFunction: fGAMM "(" expression "," expression ")"
#line 368 "bisonparser.yy"
                                                { yylhs.value.as < obj_t > ().valor = driver.sampler()->sampleGamma(yystack_[3].value.as < obj_t > ().valor,yystack_[1].value.as < obj_t > ().valor);}
#line 1451 "../GenesysParser.cpp"
    break;

  case 72: // probFunction: fERLA "(" expression "," expression ")"
#line 369 "bisonparser.yy"
                                                { yylhs.value.as < obj_t > ().valor = driver.sampler()->sampleErlang(yystack_[3].value.as < obj_t > ().valor,yystack_[1].value.as < obj_t > ().valor);}
#line 1457 "../GenesysParser.cpp"
    break;

  case 73: // probFunction: fTRIA "(" expression "," expression "," expression ")"
#line 370 "bisonparser.yy"
                                                                { yylhs.value.as < obj_t > ().valor = driver.sampler()->sampleTriangular(yystack_[5].value.as < obj_t > ().valor,yystack_[3].value.as < obj_t > ().valor,yystack_[1].value.as < obj_t > ().valor);}
#line 1463 "../GenesysParser.cpp"
    break;

  case 74: // probFunction: fBETA "(" expression "," expression "," expression "," expression ")"
#line 371 "bisonparser.yy"
                                                                              { yylhs.value.as < obj_t > ().valor = driver.sampler()->sampleBeta(yystack_[7].value.as < obj_t > ().valor,yystack_[5].value.as < obj_t > ().valor,yystack_[3].value.as < obj_t > ().valor,yystack_[1].value.as < obj_t > ().valor);}
#line 1469 "../GenesysParser.cpp"
    break;

  case 75: // probFunction: fDISC "(" listaparm ")"
#line 372 "bisonparser.yy"
                                                { yylhs.value.as < obj_t > ().valor = driver.sampler()->sampleDiscrete(0,0); /*@TODO: NOT IMPLEMENTED YET*/ }
#line 1475 "../GenesysParser.cpp"
    break;

  case 76: // userFunction: "USER" "(" expression ")"
#line 378 "bisonparser.yy"
                                        { yylhs.value.as < obj_t > ().valor = yystack_[1].value.as < obj_t > ().valor; }
#line 1481 "../GenesysParser.cpp"
    break;

  case 77: // listaparm: listaparm "," expression "," expression
#line 383 "bisonparser.yy"
                                                 {/*@TODO: NOT IMPLEMENTED YET*/}
#line 1487 "../GenesysParser.cpp"
    break;

  case 78: // listaparm: expression "," expression
#line 384 "bisonparser.yy"
                                                 {/*@TODO: NOT IMPLEMENTED YET*/}
#line 1493 "../GenesysParser.cpp"
    break;

  case 79: // atributo: ATRIB
#line 410 "bisonparser.yy"
                   {  
		double attributeValue = 0.0;
		//std::cout << "Tentando..." << std::endl;
		if (driver.getModel()->getSimulation()->getCurrentEvent() != nullptr) {
			// it could crach because there may be no current entity, if the parse is running before simulation and therefore there is no CurrentEntity
			attributeValue = driver.getModel()->getSimulation()->getCurrentEvent()->getEntity()->getAttributeValue(yystack_[0].value.as < obj_t > ().id);
		}
		//std::cout << "Passei" << std::endl;
		yylhs.value.as < obj_t > ().valor = attributeValue; 
	}
#line 1508 "../GenesysParser.cpp"
    break;

  case 80: // atributo: ATRIB "[" expression "]"
#line 420 "bisonparser.yy"
                                              {  
		double attributeValue = 0.0;
		std::string index = std::to_string(static_cast<unsigned int>(yystack_[1].value.as < obj_t > ().valor));
		if (driver.getModel()->getSimulation()->getCurrentEvent() != nullptr) {
			// it could crach because there may be no current entity, if the parse is running before simulation and therefore there is no CurrentEntity
			attributeValue = driver.getModel()->getSimulation()->getCurrentEvent()->getEntity()->getAttributeValue(index, yystack_[3].value.as < obj_t > ().id);
		}
		yylhs.value.as < obj_t > ().valor = attributeValue; 
	}
#line 1522 "../GenesysParser.cpp"
    break;

  case 81: // atributo: ATRIB "[" expression "," expression "]"
#line 429 "bisonparser.yy"
                                                             {  
		double attributeValue = 0.0;
		std::string index = std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[1].value.as < obj_t > ().valor));
		if (driver.getModel()->getSimulation()->getCurrentEvent() != nullptr) {
			// it could crach because there may be no current entity, if the parse is running before simulation and therefore there is no CurrentEntity
			attributeValue = driver.getModel()->getSimulation()->getCurrentEvent()->getEntity()->getAttributeValue(index, yystack_[5].value.as < obj_t > ().id);
		}
		yylhs.value.as < obj_t > ().valor = attributeValue; 
	}
#line 1536 "../GenesysParser.cpp"
    break;

  case 82: // atributo: ATRIB "[" expression "," expression "," expression "]"
#line 438 "bisonparser.yy"
                                                                            {  
		double attributeValue = 0.0;
		std::string index = std::to_string(static_cast<unsigned int>(yystack_[5].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[1].value.as < obj_t > ().valor));
		if (driver.getModel()->getSimulation()->getCurrentEvent() != nullptr) {
			// it could crach because there may be no current entity, if the parse is running before simulation and therefore there is no CurrentEntity
			attributeValue = driver.getModel()->getSimulation()->getCurrentEvent()->getEntity()->getAttributeValue(index, yystack_[7].value.as < obj_t > ().id);
		}
		yylhs.value.as < obj_t > ().valor = attributeValue; 
	}
#line 1550 "../GenesysParser.cpp"
    break;

  case 83: // variavel: VARI
#line 452 "bisonparser.yy"
                            {yylhs.value.as < obj_t > ().valor = ((Variable*)(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Variable>(), yystack_[0].value.as < obj_t > ().id)))->getValue();}
#line 1556 "../GenesysParser.cpp"
    break;

  case 84: // variavel: VARI "[" expression "]"
#line 453 "bisonparser.yy"
                                                                            { 
					std::string index = std::to_string(static_cast<unsigned int>(yystack_[1].value.as < obj_t > ().valor));
					yylhs.value.as < obj_t > ().valor = ((Variable*)(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Variable>(), yystack_[3].value.as < obj_t > ().id)))->getValue(index); }
#line 1564 "../GenesysParser.cpp"
    break;

  case 85: // variavel: VARI "[" expression "," expression "]"
#line 456 "bisonparser.yy"
                                                                                            { 
					std::string index = std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[1].value.as < obj_t > ().valor)); 
					yylhs.value.as < obj_t > ().valor = ((Variable*)(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Variable>(), yystack_[5].value.as < obj_t > ().id)))->getValue(index);}
#line 1572 "../GenesysParser.cpp"
    break;

  case 86: // variavel: VARI "[" expression "," expression "," expression "]"
#line 459 "bisonparser.yy"
                                                                                                     { 
					std::string index = std::to_string(static_cast<unsigned int>(yystack_[5].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[1].value.as < obj_t > ().valor));
					yylhs.value.as < obj_t > ().valor = ((Variable*)(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Variable>(), yystack_[7].value.as < obj_t > ().id)))->getValue(index);}
#line 1580 "../GenesysParser.cpp"
    break;

  case 87: // formula: FORM
#line 467 "bisonparser.yy"
                                    { 
					yylhs.value.as < obj_t > ().valor = ((Formula*)(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Formula>(), yystack_[0].value.as < obj_t > ().id)))->value();}
#line 1587 "../GenesysParser.cpp"
    break;

  case 88: // formula: FORM "[" expression "]"
#line 469 "bisonparser.yy"
                                                                    {
					std::string index = std::to_string(static_cast<unsigned int>(yystack_[1].value.as < obj_t > ().valor));
					yylhs.value.as < obj_t > ().valor = ((Formula*)(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Formula>(), yystack_[3].value.as < obj_t > ().id)))->value(index);}
#line 1595 "../GenesysParser.cpp"
    break;

  case 89: // formula: FORM "[" expression "," expression "]"
#line 472 "bisonparser.yy"
                                                                                   {
					std::string index = std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor)) +","+std::to_string(static_cast<unsigned int>(yystack_[1].value.as < obj_t > ().valor));
					yylhs.value.as < obj_t > ().valor = ((Formula*)(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Formula>(), yystack_[5].value.as < obj_t > ().id)))->value(index);}
#line 1603 "../GenesysParser.cpp"
    break;

  case 90: // formula: FORM "[" expression "," expression "," expression "]"
#line 475 "bisonparser.yy"
                                                                                                  {
					std::string index = std::to_string(static_cast<unsigned int>(yystack_[5].value.as < obj_t > ().valor)) +","+std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[1].value.as < obj_t > ().valor));
					yylhs.value.as < obj_t > ().valor = ((Formula*)(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Formula>(), yystack_[7].value.as < obj_t > ().id)))->value(index);}
#line 1611 "../GenesysParser.cpp"
    break;

  case 91: // atribuicao: ATRIB "=" expression
#line 483 "bisonparser.yy"
                                                 { 
					// @TODO: getCurrentEvent()->getEntity() may be nullptr if simulation hasn't started yet
					driver.getModel()->getSimulation()->getCurrentEvent()->getEntity()->setAttributeValue("", yystack_[2].value.as < obj_t > ().id, yystack_[0].value.as < obj_t > ().valor);
					yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1620 "../GenesysParser.cpp"
    break;

  case 92: // atribuicao: ATRIB "[" expression "]" "=" expression
#line 487 "bisonparser.yy"
                                                                                          { 
					std::string index = std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor));
					driver.getModel()->getSimulation()->getCurrentEvent()->getEntity()->setAttributeValue(index, yystack_[5].value.as < obj_t > ().id, yystack_[0].value.as < obj_t > ().valor);
					yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1629 "../GenesysParser.cpp"
    break;

  case 93: // atribuicao: ATRIB "[" expression "," expression "]" "=" expression
#line 491 "bisonparser.yy"
                                                                                                        {
					std::string index = std::to_string(static_cast<unsigned int>(yystack_[5].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor)); 
					driver.getModel()->getSimulation()->getCurrentEvent()->getEntity()->setAttributeValue(index, yystack_[7].value.as < obj_t > ().id, yystack_[0].value.as < obj_t > ().valor); 
					yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor;}
#line 1638 "../GenesysParser.cpp"
    break;

  case 94: // atribuicao: ATRIB "[" expression "," expression "," expression "]" "=" expression
#line 495 "bisonparser.yy"
                                                                                                                          {
					std::string index = std::to_string(static_cast<unsigned int>(yystack_[7].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[5].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor));
					driver.getModel()->getSimulation()->getCurrentEvent()->getEntity()->setAttributeValue(index, yystack_[9].value.as < obj_t > ().id, yystack_[0].value.as < obj_t > ().valor);
					yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1647 "../GenesysParser.cpp"
    break;

  case 95: // atribuicao: VARI "=" expression
#line 501 "bisonparser.yy"
                                                                {
					((Variable*)(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Variable>(), yystack_[2].value.as < obj_t > ().id)))->setValue(yystack_[0].value.as < obj_t > ().valor);
					yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; 
					}
#line 1656 "../GenesysParser.cpp"
    break;

  case 96: // atribuicao: VARI "[" expression "]" "=" expression
#line 505 "bisonparser.yy"
                                                                                         { 
					std::string index = std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor));
					((Variable*)(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Variable>(), yystack_[5].value.as < obj_t > ().id)))->setValue(index, yystack_[0].value.as < obj_t > ().valor); 
					yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1665 "../GenesysParser.cpp"
    break;

  case 97: // atribuicao: VARI "[" expression "," expression "]" "=" expression
#line 509 "bisonparser.yy"
                                                                                                       {
					std::string index = std::to_string(static_cast<unsigned int>(yystack_[5].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor)); 
					((Variable*)(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Variable>(), yystack_[7].value.as < obj_t > ().id)))->setValue(index, yystack_[0].value.as < obj_t > ().valor);
					yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1674 "../GenesysParser.cpp"
    break;

  case 98: // atribuicao: VARI "[" expression "," expression "," expression "]" "=" expression
#line 513 "bisonparser.yy"
                                                                                                                         {
					std::string index = std::to_string(static_cast<unsigned int>(yystack_[7].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[5].value.as < obj_t > ().valor))+","+std::to_string(static_cast<unsigned int>(yystack_[3].value.as < obj_t > ().valor));
					((Variable*)(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Variable>(), yystack_[9].value.as < obj_t > ().id)))->setValue(index, yystack_[0].value.as < obj_t > ().valor); 
					yylhs.value.as < obj_t > ().valor = yystack_[0].value.as < obj_t > ().valor; }
#line 1683 "../GenesysParser.cpp"
    break;

  case 99: // pluginFunction: CTEZERO
#line 524 "bisonparser.yy"
                                                     { yylhs.value.as < obj_t > ().valor = 0; }
#line 1689 "../GenesysParser.cpp"
    break;

  case 100: // pluginFunction: fNQ "(" QUEUE ")"
#line 527 "bisonparser.yy"
                                    {   //std::cout << "Queue ID: " << $3.id << ", Size: " << ((Queue*)(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Queue>(), $3.id)))->size() << std::endl; 
                                        yylhs.value.as < obj_t > ().valor = ((Queue*)(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Queue>(), yystack_[1].value.as < obj_t > ().id)))->size();}
#line 1696 "../GenesysParser.cpp"
    break;

  case 101: // pluginFunction: fLASTINQ "(" QUEUE ")"
#line 529 "bisonparser.yy"
                                    {/*For now does nothing because need acces to list of QUEUE, or at least the last element*/ }
#line 1702 "../GenesysParser.cpp"
    break;

  case 102: // pluginFunction: fFIRSTINQ "(" QUEUE ")"
#line 530 "bisonparser.yy"
                                    { 
                if (((Queue*)(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Queue>(), yystack_[1].value.as < obj_t > ().id)))->size() > 0){
                    //id da 1a entidade da fila, talvez pegar nome
                    yylhs.value.as < obj_t > ().valor = ((Queue*)(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Queue>(), yystack_[1].value.as < obj_t > ().id)))->first()->getEntity()->getId();
                }else{
                    yylhs.value.as < obj_t > ().valor = 0;
                } }
#line 1714 "../GenesysParser.cpp"
    break;

  case 103: // pluginFunction: fSAQUE "(" QUEUE "," ATRIB ")"
#line 537 "bisonparser.yy"
                                       {   
                //Util::identification queueID = $3.id;
                Util::identification attrID = yystack_[1].value.as < obj_t > ().id;
                double sum = ((Queue*)(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Queue>(), yystack_[3].value.as < obj_t > ().id)))->sumAttributesFromWaiting(attrID);
                yylhs.value.as < obj_t > ().valor = sum; }
#line 1724 "../GenesysParser.cpp"
    break;

  case 104: // pluginFunction: fAQUE "(" QUEUE "," NUMD "," ATRIB ")"
#line 542 "bisonparser.yy"
                                             {
                //Util::identification queueID = $3.id;
                Util::identification attrID = yystack_[1].value.as < obj_t > ().id;
                double value = ((Queue*)(driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Queue>(), yystack_[5].value.as < obj_t > ().id)))->getAttributeFromWaitingRank(yystack_[3].value.as < obj_t > ().valor-1, attrID); // rank starts on 0 in genesys
                yylhs.value.as < obj_t > ().valor = value; }
#line 1734 "../GenesysParser.cpp"
    break;

  case 105: // pluginFunction: fMR "(" RESOURCE ")"
#line 550 "bisonparser.yy"
                                        { yylhs.value.as < obj_t > ().valor = ((Resource*)driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Resource>(), yystack_[1].value.as < obj_t > ().id))->getCapacity();}
#line 1740 "../GenesysParser.cpp"
    break;

  case 106: // pluginFunction: fNR "(" RESOURCE ")"
#line 551 "bisonparser.yy"
                                         { yylhs.value.as < obj_t > ().valor = ((Resource*)driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Resource>(), yystack_[1].value.as < obj_t > ().id))->getNumberBusy();}
#line 1746 "../GenesysParser.cpp"
    break;

  case 107: // pluginFunction: fRESSEIZES "(" RESOURCE ")"
#line 552 "bisonparser.yy"
                                         { /*\TODO: For now does nothing because needs get Seizes, check with teacher*/}
#line 1752 "../GenesysParser.cpp"
    break;

  case 108: // pluginFunction: fSTATE "(" RESOURCE ")"
#line 553 "bisonparser.yy"
                                         {  yylhs.value.as < obj_t > ().valor = static_cast<int>(((Resource*)driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Resource>(), yystack_[1].value.as < obj_t > ().id))->getResourceState()); }
#line 1758 "../GenesysParser.cpp"
    break;

  case 109: // pluginFunction: fIRF "(" RESOURCE ")"
#line 554 "bisonparser.yy"
                                         { yylhs.value.as < obj_t > ().valor = ((Resource*)driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Resource>(), yystack_[1].value.as < obj_t > ().id))->getResourceState() == Resource::ResourceState::FAILED ? 1 : 0; }
#line 1764 "../GenesysParser.cpp"
    break;

  case 110: // pluginFunction: fSETSUM "(" SET ")"
#line 555 "bisonparser.yy"
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
#line 1782 "../GenesysParser.cpp"
    break;

  case 111: // pluginFunction: fNUMSET "(" SET ")"
#line 571 "bisonparser.yy"
                                { yylhs.value.as < obj_t > ().valor = ((Set*)driver.getModel()->getDataManager()->getDataDefinition(Util::TypeOf<Set>(),yystack_[1].value.as < obj_t > ().id))->getElementSet()->size(); }
#line 1788 "../GenesysParser.cpp"
    break;


#line 1792 "../GenesysParser.cpp"

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

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
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


  const short genesyspp_parser::yypact_ninf_ = -307;

  const signed char genesyspp_parser::yytable_ninf_ = -53;

  const short
  genesyspp_parser::yypact_[] =
  {
     347,   -86,  -307,  -307,  -307,   520,   -66,   -65,   -57,   -56,
     -55,   -54,   -38,   -37,   -34,   -33,  -307,   -32,   -31,   -28,
     -27,   -26,   -25,   -24,   -23,   -22,   -21,  -307,  -307,  -307,
    -307,  -307,   520,   -36,   -72,   -20,   -19,   -18,   -17,   -16,
     -15,    -6,    23,    24,    33,    43,    67,    69,    70,   -71,
     -73,   520,   520,    71,    40,  1712,  -307,  -307,  -307,  -307,
    -307,  -307,  -307,  -307,  -307,  -307,  -307,  -307,  -307,  -307,
    -307,  -307,  -307,  -307,  -307,  -307,   190,   520,   520,   520,
     520,   520,   520,   520,   520,   520,   520,   520,   520,   520,
     520,   520,   520,   520,   520,   520,   520,   436,    -7,    72,
     -46,    61,   520,   520,   101,    98,    97,   100,   102,   115,
     116,    83,    91,   109,   126,   127,   128,   122,   520,   520,
     520,  1043,    13,   520,  -307,   520,   520,   520,   520,   520,
     520,   520,   520,   520,   520,   520,   520,   520,   520,   520,
    1053,  1063,  1073,   768,  1083,  1093,  1174,  1184,  1194,  1204,
    1214,   777,   786,   795,   804,   887,   896,   905,   914,   923,
     -76,   520,  1227,   520,   520,   520,   520,    22,  1712,   117,
     118,   123,   129,   130,   131,   141,   143,   145,   146,   147,
     105,   137,   149,    56,  1712,   156,  -307,  1237,   104,   104,
     104,   104,   190,   190,  1712,  1712,    11,    11,    13,  1712,
      13,   104,   104,  -307,  -307,  -307,   520,  -307,  -307,  -307,
    -307,  -307,  -307,  -307,   520,   520,   520,   520,   520,   520,
     520,   520,   520,  -307,   520,    99,   520,   167,   596,  1318,
    1326,   142,   520,  -307,  -307,  -307,  -307,  -307,  -307,  -307,
    -307,  -307,  -307,  -307,   155,   202,  -307,   144,   520,  -307,
     520,  -307,  1336,  1346,  1368,  1378,  1427,  1459,  1469,   932,
     941,  1712,   950,   104,  -307,   520,  -307,   520,   520,   520,
     520,   606,   151,   166,   520,   616,   626,  -307,  -307,  -307,
    -307,  -307,  -307,  -307,   520,   520,   520,   636,   646,  1477,
    1485,  1712,   169,   520,  -307,   181,  1712,   170,   520,  -307,
     520,  1508,  1033,  1712,  -307,   520,  -307,   520,   -35,   -35,
     520,  1566,   157,   520,  1589,  1597,  -307,   520,  1605,  1613,
     -70,   -69,  -307,  -307,  1712,   171,  -307,  1712,   172,  -307,
    1623,  -307,  -307,   520,   520,   520,   520,  -307,   656,   739,
    1712,  1712,   142,   520,   144,   520,   749,   759,   169,   520,
     170,   520,  1631,  1647,   171,   172
  };

  const signed char
  genesyspp_parser::yydefact_[] =
  {
       0,     0,    15,    16,    99,    52,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    65,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    47,    48,    49,
      50,    51,    52,     0,    79,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    83,
      87,    52,    52,     0,     0,     2,     4,     8,     9,    10,
       6,    34,    35,     5,    43,    46,    41,    40,    42,    45,
      12,    13,    14,     7,    44,     3,    27,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    79,    83,
       0,     0,    52,    52,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    52,    52,
      52,     0,    22,    52,     1,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    52,    37,    52,    52,    52,    52,     0,    91,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    95,     0,    11,     0,    30,    31,
      32,    33,    23,    24,    25,    26,    17,    18,    20,    21,
      19,    28,    29,    55,    56,    57,    52,    59,    58,    60,
      61,    62,    63,    66,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    75,    52,    18,    52,     0,     0,     0,
       0,    80,    52,    53,    54,   106,   105,   109,   107,   108,
     110,   100,   102,   101,     0,     0,   111,    84,    52,    88,
      52,    76,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    78,     0,    36,    80,    52,    84,    52,    52,    52,
      52,     0,     0,     0,    52,     0,     0,    64,    67,    68,
      69,    70,    71,    72,    52,    52,    52,     0,     0,     0,
       0,    92,    81,    52,   103,     0,    96,    85,    52,    89,
      52,     0,     0,    77,    81,    52,    85,    52,     0,     0,
      52,     0,     0,    52,     0,     0,    73,    52,     0,     0,
       0,     0,    39,    38,    93,    82,   104,    97,    86,    90,
       0,    82,    86,    52,    52,    52,    52,    74,     0,     0,
      94,    98,     0,    52,     0,    52,     0,     0,     0,    52,
       0,    52,     0,     0,     0,     0
  };

  const short
  genesyspp_parser::yypgoto_[] =
  {
    -307,  -307,    -5,  -307,  -307,  -307,  -307,  -307,  -307,  -307,
    -307,  -307,  -307,  -307,  -307,  -307,  -307,  -307,   199,   200,
    -307,  -306,  -307
  };

  const unsigned char
  genesyspp_parser::yydefgoto_[] =
  {
       0,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,   160,    70,    71,
      72,    73,    74
  };

  const short
  genesyspp_parser::yytable_[] =
  {
      76,   223,   322,   323,    75,   120,   102,   118,   333,   334,
      77,    78,   224,    98,   320,   103,   119,   103,   119,    79,
      80,    81,    82,   131,   132,   131,   132,    97,   125,   126,
     127,   128,   129,   130,   131,   132,    99,   321,    83,    84,
     124,   165,    85,    86,    87,    88,   121,   122,    89,    90,
      91,    92,    93,    94,    95,    96,   104,   105,   106,   107,
     108,   109,   125,   126,   127,   128,   129,   130,   131,   132,
     110,   163,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   162,   135,   136,   137,   136,   167,   168,   111,
     112,   231,   133,   134,   135,   136,   137,   138,   139,   113,
     232,   131,   132,   183,   184,   185,   131,   132,   187,   114,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   247,   133,   134,   135,   136,
     137,   138,   139,   115,   248,   116,   117,   123,   166,   170,
     164,   169,   171,   176,   177,   172,   225,   173,   227,   228,
     229,   230,   125,   126,   127,   128,   129,   130,   131,   132,
     174,   175,   178,   125,   126,   127,   128,   129,   130,   131,
     132,   -22,   136,   -22,   133,   134,   135,   136,   137,   179,
     180,   181,   182,   244,   233,   234,   125,   126,   127,   128,
     235,   252,   131,   132,   272,   273,   236,   237,   238,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   239,   262,
     240,   263,   241,   242,   243,   245,   246,   271,   294,   270,
     312,   274,   100,   101,   326,   249,   133,   134,   135,   136,
     137,   138,   139,   275,   250,   276,   264,   133,   134,   135,
     136,   137,   138,   139,   295,   265,   310,   313,   335,   336,
     287,     0,   288,   289,   290,   291,     0,     0,     0,   296,
     133,   134,   135,   136,   137,   138,   139,     0,     0,   301,
     302,   303,     0,     0,     0,     0,     0,     0,   311,     0,
       0,     0,     0,   314,     0,   315,     0,     0,     0,     0,
     318,     0,   319,     0,     0,   324,     0,     0,   327,     0,
       0,     0,   330,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   338,   339,
     340,   341,     0,     0,     0,     0,     0,     0,   346,     0,
     347,     0,     0,     0,   352,     0,   353,   -52,     1,     0,
       2,     3,     4,   -52,   -52,   -52,   -52,   -52,   -52,   -52,
     -52,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,     0,     0,     0,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,     0,    33,     0,     0,    34,     0,     0,    35,
      36,     0,     0,    37,    38,    39,    40,    41,    42,     0,
       0,    43,    44,    45,    46,    47,     0,     0,    48,    49,
      50,     0,     0,    51,     0,     0,     0,   -52,    52,   -52,
     -52,   -52,   -52,   -52,     0,     0,     0,     0,    53,     2,
       3,     4,   125,   126,   127,   128,   129,   130,   131,   132,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,     0,     0,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,     0,    33,     0,     0,    34,     0,     0,    35,    36,
       0,     0,    37,    38,    39,    40,    41,    42,     0,     0,
      43,    44,    45,    46,    47,     0,     0,    48,    49,    50,
       0,     0,    51,     0,     0,     0,   133,   161,   135,   136,
     137,   138,   139,     2,     3,     4,     0,    53,     0,     0,
       0,     0,     0,     0,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,     0,     0,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,     0,    33,     0,     0,    34,
       0,     0,    35,    36,     0,     0,    37,    38,    39,    40,
      41,    42,     0,     0,    43,    44,    45,    46,    47,     0,
       0,    48,    49,    50,     0,     0,    51,     0,     0,     0,
       0,    52,   125,   126,   127,   128,   129,   130,   131,   132,
       0,    53,   125,   126,   127,   128,   129,   130,   131,   132,
       0,     0,   125,   126,   127,   128,   129,   130,   131,   132,
       0,     0,   125,   126,   127,   128,   129,   130,   131,   132,
       0,     0,   125,   126,   127,   128,   129,   130,   131,   132,
       0,     0,   125,   126,   127,   128,   129,   130,   131,   132,
       0,     0,   125,   126,   127,   128,   129,   130,   131,   132,
       0,     0,     0,     0,     0,   266,   133,   134,   135,   136,
     137,   138,   139,     0,   267,   292,   133,   134,   135,   136,
     137,   138,   139,     0,   293,   297,   133,   134,   135,   136,
     137,   138,   139,     0,   298,   299,   133,   134,   135,   136,
     137,   138,   139,     0,   300,   304,   133,   134,   135,   136,
     137,   138,   139,     0,   305,   306,   133,   134,   135,   136,
     137,   138,   139,     0,   307,   342,   133,   134,   135,   136,
     137,   138,   139,     0,   343,   125,   126,   127,   128,   129,
     130,   131,   132,     0,     0,   125,   126,   127,   128,   129,
     130,   131,   132,     0,     0,   125,   126,   127,   128,   129,
     130,   131,   132,     0,   125,   126,   127,   128,   129,   130,
     131,   132,     0,   125,   126,   127,   128,   129,   130,   131,
     132,     0,   125,   126,   127,   128,   129,   130,   131,   132,
       0,   125,   126,   127,   128,   129,   130,   131,   132,     0,
     125,   126,   127,   128,   129,   130,   131,   132,   344,   133,
     134,   135,   136,   137,   138,   139,     0,   345,   348,   133,
     134,   135,   136,   137,   138,   139,     0,   349,   350,   133,
     134,   135,   136,   137,   138,   139,     0,   351,   133,   134,
     135,   136,   137,   138,   139,     0,   206,   133,   134,   135,
     136,   137,   138,   139,     0,   214,   133,   134,   135,   136,
     137,   138,   139,     0,   215,   133,   134,   135,   136,   137,
     138,   139,     0,   216,   133,   134,   135,   136,   137,   138,
     139,     0,   217,   125,   126,   127,   128,   129,   130,   131,
     132,     0,   125,   126,   127,   128,   129,   130,   131,   132,
       0,   125,   126,   127,   128,   129,   130,   131,   132,     0,
     125,   126,   127,   128,   129,   130,   131,   132,     0,   125,
     126,   127,   128,   129,   130,   131,   132,     0,   125,   126,
     127,   128,   129,   130,   131,   132,     0,   125,   126,   127,
     128,   129,   130,   131,   132,     0,   125,   126,   127,   128,
     129,   130,   131,   132,     0,     0,     0,   133,   134,   135,
     136,   137,   138,   139,     0,   218,   133,   134,   135,   136,
     137,   138,   139,     0,   219,   133,   134,   135,   136,   137,
     138,   139,     0,   220,   133,   134,   135,   136,   137,   138,
     139,     0,   221,   133,   134,   135,   136,   137,   138,   139,
       0,   222,   133,   134,   135,   136,   137,   138,   139,     0,
     284,   133,   134,   135,   136,   137,   138,   139,     0,   285,
     133,   134,   135,   136,   137,   138,   139,     0,   286,   125,
     126,   127,   128,   129,   130,   131,   132,     0,     0,   125,
     126,   127,   128,   129,   130,   131,   132,     0,     0,   125,
     126,   127,   128,   129,   130,   131,   132,     0,     0,   125,
     126,   127,   128,   129,   130,   131,   132,     0,     0,   125,
     126,   127,   128,   129,   130,   131,   132,     0,     0,   125,
     126,   127,   128,   129,   130,   131,   132,     0,     0,   125,
     126,   127,   128,   129,   130,   131,   132,     0,     0,     0,
       0,     0,     0,   133,   134,   135,   136,   137,   138,   139,
     186,   317,     0,   133,   134,   135,   136,   137,   138,   139,
     203,     0,     0,   133,   134,   135,   136,   137,   138,   139,
     204,     0,     0,   133,   134,   135,   136,   137,   138,   139,
     205,     0,     0,   133,   134,   135,   136,   137,   138,   139,
     207,     0,     0,   133,   134,   135,   136,   137,   138,   139,
     208,     0,     0,   133,   134,   135,   136,   137,   138,   139,
     125,   126,   127,   128,   129,   130,   131,   132,     0,     0,
     125,   126,   127,   128,   129,   130,   131,   132,     0,     0,
     125,   126,   127,   128,   129,   130,   131,   132,     0,     0,
     125,   126,   127,   128,   129,   130,   131,   132,     0,     0,
     125,   126,   127,   128,   129,   130,   131,   132,     0,     0,
       0,     0,     0,   125,   126,   127,   128,   129,   130,   131,
     132,     0,     0,   125,   126,   127,   128,   129,   130,   131,
     132,   209,     0,     0,   133,   134,   135,   136,   137,   138,
     139,   210,     0,     0,   133,   134,   135,   136,   137,   138,
     139,   211,   226,     0,   133,   134,   135,   136,   137,   138,
     139,   212,     0,     0,   133,   134,   135,   136,   137,   138,
     139,   213,     0,     0,   133,   134,   135,   136,   137,   138,
     139,     0,     0,     0,     0,     0,     0,   133,   134,   135,
     136,   137,   138,   139,   251,     0,     0,   133,   134,   135,
     136,   137,   138,   139,   125,   126,   127,   128,   129,   130,
     131,   132,   125,   126,   127,   128,   129,   130,   131,   132,
       0,     0,   125,   126,   127,   128,   129,   130,   131,   132,
       0,     0,   125,   126,   127,   128,   129,   130,   131,   132,
       0,     0,     0,     0,     0,   268,     0,     0,     0,     0,
       0,     0,     0,   269,   125,   126,   127,   128,   129,   130,
     131,   132,     0,     0,   125,   126,   127,   128,   129,   130,
     131,   132,     0,     0,     0,     0,     0,     0,   133,   134,
     135,   136,   137,   138,   139,     0,   133,   134,   135,   136,
     137,   138,   139,   277,     0,     0,   133,   134,   135,   136,
     137,   138,   139,   278,     0,     0,   133,   134,   135,   136,
     137,   138,   139,   125,   126,   127,   128,   129,   130,   131,
     132,     0,     0,     0,     0,   279,     0,     0,   133,   134,
     135,   136,   137,   138,   139,   280,     0,     0,   133,   134,
     135,   136,   137,   138,   139,   125,   126,   127,   128,   129,
     130,   131,   132,     0,     0,   125,   126,   127,   128,   129,
     130,   131,   132,   125,   126,   127,   128,   129,   130,   131,
     132,   125,   126,   127,   128,   129,   130,   131,   132,     0,
       0,     0,     0,     0,   281,     0,     0,   133,   134,   135,
     136,   137,   138,   139,   125,   126,   127,   128,   129,   130,
     131,   132,     0,     0,     0,   308,     0,     0,     0,     0,
       0,     0,     0,   309,     0,     0,   282,     0,     0,   133,
     134,   135,   136,   137,   138,   139,   283,     0,     0,   133,
     134,   135,   136,   137,   138,   139,     0,   133,   134,   135,
     136,   137,   138,   139,     0,   133,   134,   135,   136,   137,
     138,   139,   125,   126,   127,   128,   129,   130,   131,   132,
       0,     0,     0,     0,     0,   316,     0,     0,   133,   134,
     135,   136,   137,   138,   139,   125,   126,   127,   128,   129,
     130,   131,   132,   125,   126,   127,   128,   129,   130,   131,
     132,   125,   126,   127,   128,   129,   130,   131,   132,   125,
     126,   127,   128,   129,   130,   131,   132,     0,     0,   125,
     126,   127,   128,   129,   130,   131,   132,   125,   126,   127,
     128,   129,   130,   131,   132,   325,   133,   134,   135,   136,
     137,   138,   139,   125,   126,   127,   128,   129,   130,   131,
     132,     0,     0,     0,     0,     0,     0,     0,   328,   133,
     134,   135,   136,   137,   138,   139,   329,   133,   134,   135,
     136,   137,   138,   139,   331,   133,   134,   135,   136,   137,
     138,   139,   332,   133,   134,   135,   136,   137,   138,   139,
     337,     0,     0,   133,   134,   135,   136,   137,   138,   139,
     354,   133,   134,   135,   136,   137,   138,   139,   125,   126,
     127,   128,   129,   130,   131,   132,   355,   133,   134,   135,
     136,   137,   138,   139,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   133,   134,   135,   136,   137,   138,   139
  };

  const short
  genesyspp_parser::yycheck_[] =
  {
       5,    77,   308,   309,    90,    78,    78,    78,    78,    78,
      76,    76,    88,    49,    49,    87,    87,    87,    87,    76,
      76,    76,    76,    12,    13,    12,    13,    32,     6,     7,
       8,     9,    10,    11,    12,    13,    72,    72,    76,    76,
       0,    87,    76,    76,    76,    76,    51,    52,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,     6,     7,     8,     9,    10,    11,    12,    13,
      76,    78,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    82,    83,    84,    83,   102,   103,    76,
      76,    79,    80,    81,    82,    83,    84,    85,    86,    76,
      88,    12,    13,   118,   119,   120,    12,    13,   123,    76,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,    79,    80,    81,    82,    83,
      84,    85,    86,    76,    88,    76,    76,    76,    87,    51,
      78,    50,    55,    70,    63,    55,   161,    55,   163,   164,
     165,   166,     6,     7,     8,     9,    10,    11,    12,    13,
      55,    55,    63,     6,     7,     8,     9,    10,    11,    12,
      13,    82,    83,    84,    80,    81,    82,    83,    84,    63,
      63,    63,    70,    88,    77,    77,     6,     7,     8,     9,
      77,   206,    12,    13,    49,     3,    77,    77,    77,   214,
     215,   216,   217,   218,   219,   220,   221,   222,    77,   224,
      77,   226,    77,    77,    77,    88,    77,   232,    77,    87,
      49,    87,    33,    33,    77,    79,    80,    81,    82,    83,
      84,    85,    86,   248,    88,   250,    79,    80,    81,    82,
      83,    84,    85,    86,    88,    88,    87,    87,    87,    87,
     265,    -1,   267,   268,   269,   270,    -1,    -1,    -1,   274,
      80,    81,    82,    83,    84,    85,    86,    -1,    -1,   284,
     285,   286,    -1,    -1,    -1,    -1,    -1,    -1,   293,    -1,
      -1,    -1,    -1,   298,    -1,   300,    -1,    -1,    -1,    -1,
     305,    -1,   307,    -1,    -1,   310,    -1,    -1,   313,    -1,
      -1,    -1,   317,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   333,   334,
     335,   336,    -1,    -1,    -1,    -1,    -1,    -1,   343,    -1,
     345,    -1,    -1,    -1,   349,    -1,   351,     0,     1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    -1,    46,    -1,    -1,    49,    -1,    -1,    52,
      53,    -1,    -1,    56,    57,    58,    59,    60,    61,    -1,
      -1,    64,    65,    66,    67,    68,    -1,    -1,    71,    72,
      73,    -1,    -1,    76,    -1,    -1,    -1,    80,    81,    82,
      83,    84,    85,    86,    -1,    -1,    -1,    -1,    91,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    46,    -1,    -1,    49,    -1,    -1,    52,    53,
      -1,    -1,    56,    57,    58,    59,    60,    61,    -1,    -1,
      64,    65,    66,    67,    68,    -1,    -1,    71,    72,    73,
      -1,    -1,    76,    -1,    -1,    -1,    80,    81,    82,    83,
      84,    85,    86,     3,     4,     5,    -1,    91,    -1,    -1,
      -1,    -1,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    -1,    -1,    -1,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    -1,    46,    -1,    -1,    49,
      -1,    -1,    52,    53,    -1,    -1,    56,    57,    58,    59,
      60,    61,    -1,    -1,    64,    65,    66,    67,    68,    -1,
      -1,    71,    72,    73,    -1,    -1,    76,    -1,    -1,    -1,
      -1,    81,     6,     7,     8,     9,    10,    11,    12,    13,
      -1,    91,     6,     7,     8,     9,    10,    11,    12,    13,
      -1,    -1,     6,     7,     8,     9,    10,    11,    12,    13,
      -1,    -1,     6,     7,     8,     9,    10,    11,    12,    13,
      -1,    -1,     6,     7,     8,     9,    10,    11,    12,    13,
      -1,    -1,     6,     7,     8,     9,    10,    11,    12,    13,
      -1,    -1,     6,     7,     8,     9,    10,    11,    12,    13,
      -1,    -1,    -1,    -1,    -1,    79,    80,    81,    82,    83,
      84,    85,    86,    -1,    88,    79,    80,    81,    82,    83,
      84,    85,    86,    -1,    88,    79,    80,    81,    82,    83,
      84,    85,    86,    -1,    88,    79,    80,    81,    82,    83,
      84,    85,    86,    -1,    88,    79,    80,    81,    82,    83,
      84,    85,    86,    -1,    88,    79,    80,    81,    82,    83,
      84,    85,    86,    -1,    88,    79,    80,    81,    82,    83,
      84,    85,    86,    -1,    88,     6,     7,     8,     9,    10,
      11,    12,    13,    -1,    -1,     6,     7,     8,     9,    10,
      11,    12,    13,    -1,    -1,     6,     7,     8,     9,    10,
      11,    12,    13,    -1,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,     6,     7,     8,     9,    10,    11,    12,    13,
      -1,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
       6,     7,     8,     9,    10,    11,    12,    13,    79,    80,
      81,    82,    83,    84,    85,    86,    -1,    88,    79,    80,
      81,    82,    83,    84,    85,    86,    -1,    88,    79,    80,
      81,    82,    83,    84,    85,    86,    -1,    88,    80,    81,
      82,    83,    84,    85,    86,    -1,    88,    80,    81,    82,
      83,    84,    85,    86,    -1,    88,    80,    81,    82,    83,
      84,    85,    86,    -1,    88,    80,    81,    82,    83,    84,
      85,    86,    -1,    88,    80,    81,    82,    83,    84,    85,
      86,    -1,    88,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,     6,     7,     8,     9,    10,    11,    12,    13,
      -1,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
       6,     7,     8,     9,    10,    11,    12,    13,    -1,     6,
       7,     8,     9,    10,    11,    12,    13,    -1,     6,     7,
       8,     9,    10,    11,    12,    13,    -1,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,     6,     7,     8,     9,
      10,    11,    12,    13,    -1,    -1,    -1,    80,    81,    82,
      83,    84,    85,    86,    -1,    88,    80,    81,    82,    83,
      84,    85,    86,    -1,    88,    80,    81,    82,    83,    84,
      85,    86,    -1,    88,    80,    81,    82,    83,    84,    85,
      86,    -1,    88,    80,    81,    82,    83,    84,    85,    86,
      -1,    88,    80,    81,    82,    83,    84,    85,    86,    -1,
      88,    80,    81,    82,    83,    84,    85,    86,    -1,    88,
      80,    81,    82,    83,    84,    85,    86,    -1,    88,     6,
       7,     8,     9,    10,    11,    12,    13,    -1,    -1,     6,
       7,     8,     9,    10,    11,    12,    13,    -1,    -1,     6,
       7,     8,     9,    10,    11,    12,    13,    -1,    -1,     6,
       7,     8,     9,    10,    11,    12,    13,    -1,    -1,     6,
       7,     8,     9,    10,    11,    12,    13,    -1,    -1,     6,
       7,     8,     9,    10,    11,    12,    13,    -1,    -1,     6,
       7,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    80,    81,    82,    83,    84,    85,    86,
      77,    88,    -1,    80,    81,    82,    83,    84,    85,    86,
      77,    -1,    -1,    80,    81,    82,    83,    84,    85,    86,
      77,    -1,    -1,    80,    81,    82,    83,    84,    85,    86,
      77,    -1,    -1,    80,    81,    82,    83,    84,    85,    86,
      77,    -1,    -1,    80,    81,    82,    83,    84,    85,    86,
      77,    -1,    -1,    80,    81,    82,    83,    84,    85,    86,
       6,     7,     8,     9,    10,    11,    12,    13,    -1,    -1,
       6,     7,     8,     9,    10,    11,    12,    13,    -1,    -1,
       6,     7,     8,     9,    10,    11,    12,    13,    -1,    -1,
       6,     7,     8,     9,    10,    11,    12,    13,    -1,    -1,
       6,     7,     8,     9,    10,    11,    12,    13,    -1,    -1,
      -1,    -1,    -1,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,    -1,     6,     7,     8,     9,    10,    11,    12,
      13,    77,    -1,    -1,    80,    81,    82,    83,    84,    85,
      86,    77,    -1,    -1,    80,    81,    82,    83,    84,    85,
      86,    77,    45,    -1,    80,    81,    82,    83,    84,    85,
      86,    77,    -1,    -1,    80,    81,    82,    83,    84,    85,
      86,    77,    -1,    -1,    80,    81,    82,    83,    84,    85,
      86,    -1,    -1,    -1,    -1,    -1,    -1,    80,    81,    82,
      83,    84,    85,    86,    77,    -1,    -1,    80,    81,    82,
      83,    84,    85,    86,     6,     7,     8,     9,    10,    11,
      12,    13,     6,     7,     8,     9,    10,    11,    12,    13,
      -1,    -1,     6,     7,     8,     9,    10,    11,    12,    13,
      -1,    -1,     6,     7,     8,     9,    10,    11,    12,    13,
      -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,    -1,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    80,    81,
      82,    83,    84,    85,    86,    -1,    80,    81,    82,    83,
      84,    85,    86,    77,    -1,    -1,    80,    81,    82,    83,
      84,    85,    86,    77,    -1,    -1,    80,    81,    82,    83,
      84,    85,    86,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,    -1,    -1,    -1,    77,    -1,    -1,    80,    81,
      82,    83,    84,    85,    86,    77,    -1,    -1,    80,    81,
      82,    83,    84,    85,    86,     6,     7,     8,     9,    10,
      11,    12,    13,    -1,    -1,     6,     7,     8,     9,    10,
      11,    12,    13,     6,     7,     8,     9,    10,    11,    12,
      13,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
      -1,    -1,    -1,    -1,    77,    -1,    -1,    80,    81,    82,
      83,    84,    85,    86,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    -1,    -1,    77,    -1,    -1,    80,
      81,    82,    83,    84,    85,    86,    77,    -1,    -1,    80,
      81,    82,    83,    84,    85,    86,    -1,    80,    81,    82,
      83,    84,    85,    86,    -1,    80,    81,    82,    83,    84,
      85,    86,     6,     7,     8,     9,    10,    11,    12,    13,
      -1,    -1,    -1,    -1,    -1,    77,    -1,    -1,    80,    81,
      82,    83,    84,    85,    86,     6,     7,     8,     9,    10,
      11,    12,    13,     6,     7,     8,     9,    10,    11,    12,
      13,     6,     7,     8,     9,    10,    11,    12,    13,     6,
       7,     8,     9,    10,    11,    12,    13,    -1,    -1,     6,
       7,     8,     9,    10,    11,    12,    13,     6,     7,     8,
       9,    10,    11,    12,    13,    79,    80,    81,    82,    83,
      84,    85,    86,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,    80,
      81,    82,    83,    84,    85,    86,    79,    80,    81,    82,
      83,    84,    85,    86,    79,    80,    81,    82,    83,    84,
      85,    86,    79,    80,    81,    82,    83,    84,    85,    86,
      77,    -1,    -1,    80,    81,    82,    83,    84,    85,    86,
      79,    80,    81,    82,    83,    84,    85,    86,     6,     7,
       8,     9,    10,    11,    12,    13,    79,    80,    81,    82,
      83,    84,    85,    86,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    80,    81,    82,    83,    84,    85,    86
  };

  const signed char
  genesyspp_parser::yystos_[] =
  {
       0,     1,     3,     4,     5,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    46,    49,    52,    53,    56,    57,    58,
      59,    60,    61,    64,    65,    66,    67,    68,    71,    72,
      73,    76,    81,    91,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     110,   111,   112,   113,   114,    90,    94,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    94,    49,    72,
     110,   111,    78,    87,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    78,    87,
      78,    94,    94,    76,     0,     6,     7,     8,     9,    10,
      11,    12,    13,    80,    81,    82,    83,    84,    85,    86,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
     109,    81,    94,    78,    78,    87,    87,    94,    94,    50,
      51,    55,    55,    55,    55,    55,    70,    63,    63,    63,
      63,    63,    70,    94,    94,    94,    77,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    77,    77,    77,    88,    77,    77,    77,
      77,    77,    77,    77,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    77,    88,    94,    45,    94,    94,    94,
      94,    79,    88,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    88,    88,    77,    79,    88,    79,
      88,    77,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    79,    88,    79,    88,    47,    47,
      87,    94,    49,     3,    87,    94,    94,    77,    77,    77,
      77,    77,    77,    77,    88,    88,    88,    94,    94,    94,
      94,    94,    79,    88,    77,    88,    94,    79,    88,    79,
      88,    94,    94,    94,    79,    88,    79,    88,    48,    48,
      87,    94,    49,    87,    94,    94,    77,    88,    94,    94,
      49,    72,   113,   113,    94,    79,    77,    94,    79,    79,
      94,    79,    79,    78,    78,    87,    87,    77,    94,    94,
      94,    94,    79,    88,    79,    88,    94,    94,    79,    88,
      79,    88,    94,    94,    79,    79
  };

  const signed char
  genesyspp_parser::yyr1_[] =
  {
       0,    92,    93,    93,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    95,    95,    96,    96,    96,
      96,    96,    96,    97,    97,    97,    97,    97,    98,    98,
      98,    98,    98,    98,    99,    99,   100,   100,   101,   101,
     102,   102,   102,   102,   102,   102,   102,   103,   103,   103,
     103,   103,   104,   104,   104,   105,   105,   106,   106,   106,
     106,   106,   106,   106,   106,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   108,   109,   109,   110,
     110,   110,   110,   111,   111,   111,   111,   112,   112,   112,
     112,   113,   113,   113,   113,   113,   113,   113,   113,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114
  };

  const signed char
  genesyspp_parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     2,     3,     3,     3,     3,     2,     3,     3,
       3,     3,     3,     3,     1,     1,     5,     3,     8,     8,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     6,     1,     4,     6,     6,     6,
       6,     6,     6,     8,    10,     4,     4,     5,     3,     1,
       4,     6,     8,     1,     4,     6,     8,     1,     4,     6,
       8,     3,     6,     8,    10,     3,     6,     8,    10,     1,
       4,     4,     4,     6,     8,     4,     4,     4,     4,     4,
       4,     4
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
  "cELSE", "cFOR", "cTO", "cDO", "ATRIB", "CSTAT", "COUNTER", "fTAVG",
  "fCOUNT", "ILLEGAL", "RESOURCE", "fNR", "fMR", "fIRF", "fRESSEIZES",
  "fSTATE", "fSETSUM", "fRESUTIL", "QUEUE", "fNQ", "fFIRSTINQ", "fLASTINQ",
  "fSAQUE", "fAQUE", "fENTATRANK", "SET", "fNUMSET", "VARI", "FORM",
  "fNUMGR", "fATRGR", "\"(\"", "\")\"", "\"[\"", "\"]\"", "\"+\"", "\"-\"",
  "\"*\"", "\"^\"", "\"/\"", "\"<\"", "\">\"", "\"=\"", "\",\"", "NEG",
  "'\\n'", "\"USER\"", "$accept", "input", "expression", "numero",
  "aritmetica", "logica", "relacional", "comando", "comandoIF",
  "comandoFOR", "function", "kernelFunction", "elementFunction",
  "trigonFunction", "mathFunction", "probFunction", "userFunction",
  "listaparm", "atributo", "variavel", "formula", "atribuicao",
  "pluginFunction", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  genesyspp_parser::yyrline_[] =
  {
       0,   240,   240,   241,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   258,   262,   269,   270,   274,   275,   276,
     277,   278,   279,   283,   284,   285,   286,   287,   291,   292,
     293,   294,   295,   296,   300,   301,   305,   306,   311,   312,
     316,   317,   318,   319,   320,   321,   322,   326,   327,   328,
     329,   330,   333,   335,   339,   346,   347,   351,   352,   353,
     354,   355,   356,   357,   358,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   378,   383,   384,   410,
     420,   429,   438,   452,   453,   456,   459,   467,   469,   472,
     475,   483,   487,   491,   495,   501,   505,   509,   513,   524,
     527,   529,   530,   537,   542,   550,   551,   552,   553,   554,
     555,   571
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
#line 2767 "../GenesysParser.cpp"

#line 578 "bisonparser.yy"

void
yy::genesyspp_parser::error (const location_type& l,
                          const std::string& m)
{
  driver.error (l, m);
}
