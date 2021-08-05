%skeleton "lalr1.cc" /* -*- C++ -*- */
%require "3.0.4"
%defines
%define api.parser.class {genesyspp_parser} //Name of the parses class
%define api.token.constructor //let that way or change YY_DECL prototype
%define api.value.type variant
%define parse.assert //Checks for constructor and destructor(?)
%code requires
{
#include <string>
#include <cmath>
#include "obj_t.h"
#include "../../util/Util.h"
#include "../Attribute.h"
/****begin_Includes_plugins****/
/**begin_Includes:Variable**/
#include "../../../plugins/elements/Variable.h"
/**end_Includes:Variable**/
/**begin_Includes:Queue**/
#include "../../../plugins/elements/Queue.h"
/**end_Includes:Queue**/
/**begin_Includes:Formula**/
#include "../../../plugins/elements/Formula.h"
/**end_Includes:Formula**/
/**begin_Includes:Resource**/
#include "../../../plugins/elements/Resource.h"
/**end_Includes:Resource**/
/**begin_Includes:Set**/
#include "../../../plugins/elements/Set.h"
/**end_Includes:Set**/
/****end_Includes_plugins****/

class genesyspp_driver;

}

//%define api.value.type {obj_t} //c++ types for semantic values
 //c++ types for semantic values
// The parsing context.
%param { genesyspp_driver& driver } //aditional params for yylex/yyparse
%locations // allows for more accurate syntax error messages.
%initial-action
{
  // Initialize the initial location.
  //@$.begin.filename = @$.end.filename = &driver.getFile();
};
%define parse.trace //for debugging
%define parse.error verbose //error level to show
%code
{
# include "Genesys++-driver.h"

}

// numbers
%token <obj_t> NUMD
%token <obj_t> NUMH
%token <obj_t> CTEZERO
// relational operators
%token <obj_t> oLE
%token <obj_t> oGE
%token <obj_t> oEQ
%token <obj_t> oNE
// logic operators
%token <obj_t> oAND
%token <obj_t> oOR
%token <obj_t> oNOT
// trigonometric functions
%token <obj_t> fSIN
%token <obj_t> fCOS
// aritmetic functions
%token <obj_t> fROUND
%token <obj_t> fMOD
%token <obj_t> fTRUNC
%token <obj_t> fFRAC
%token <obj_t> fEXP
// probability distributionsformulaValue
%token <obj_t> fRND1
%token <obj_t> fEXPO
%token <obj_t> fNORM
%token <obj_t> fUNIF
%token <obj_t> fWEIB
%token <obj_t> fLOGN
%token <obj_t> fGAMM
%token <obj_t> fERLA
%token <obj_t> fTRIA
%token <obj_t> fBETA
%token <obj_t> fDISC
// simulation infos
%token <obj_t> fTNOW
%token <obj_t> fTFIN
// algoritmic functions
%token <obj_t> cIF
%token <obj_t> cELSE
%token <obj_t> cFOR
%token <obj_t> cTO
%token <obj_t> cDO
// kernel elements
%token <obj_t> ATRIB
%token <obj_t> CSTAT
%token <obj_t> fTAVG
%token <obj_t> ILLEGAL     /* illegal token */

/****begin_Tokens_plugins****/
/**begin_Tokens:Resource**/
%token <obj_t> RESOURCE
%token <obj_t> fNR
%token <obj_t> fMR
%token <obj_t> fIRF
%token <obj_t> fRESSEIZES
%token <obj_t> fSTATE
%token <obj_t> fSETSUM
/**end_Tokens:Resource**/
/**begin_Tokens:Queue**/
%token <obj_t> QUEUE
%token <obj_t> fNQ
%token <obj_t> fFIRSTINQ
%token <obj_t> fLASTINQ
%token <obj_t> fSAQUE
%token <obj_t> fAQUE
/**end_Tokens:Queue**/
/**begin_Tokens:Set**/
%token <obj_t> SET
%token <obj_t> fNUMSET
/**end_Tokens:Set**/
/**begin_Tokens:Variable**/
%token <obj_t> VARI
/**end_Tokens:Variable**/
/**begin_Tokens:Formula**/
%token <obj_t> FORM
/**end_Tokens:Formula**/
/****end_Tokens_plugins****/

//
%token LPAREN "("
%token RPAREN ")"
%token LBRACKET "["
%token RBRACKET "]"
%token PLUS "+"
%token MINUS "-"
%token STAR "*"
%token POWER "^"
%token SLASH "/"
%token LESS "<"
%token GREATER ">"
%token ASSIGN "="
%token COMMA ","
%token END 0 "end of file" //need to declare, as bison doesnt in especific situation

///////////////////////////////
///////////////////////////////
%type <obj_t> input
%type <obj_t> programa
%type <obj_t> expressao
%type <obj_t> aritmetica
%type <obj_t> relacional
%type <obj_t> comando
%type <obj_t> comandoIF
%type <obj_t> comandoFOR
%type <obj_t> funcao
%type <obj_t> numero
%type <obj_t> atributo
%type <obj_t> atribuicao
%type <obj_t> funcaoKernel
%type <obj_t> funcaoTrig
%type <obj_t> funcaoArit
%type <obj_t> funcaoProb
%type <obj_t> funcaoPlugin
%type <obj_t> funcaoUser
%type <obj_t> listaparm
%type <obj_t> illegal

/****begin_TypeObj_plugins****/
/**begin_TypeObj::Variable**/
%type <obj_t> variavel
/**end_TypeObj::Variable**/
/**begin_TypeObj::Formula**/
%type <obj_t> formula
/**end_TypeObj::Formula**/
/****end_TypeObj_plugins****/

//%left oNOT;
//%left oAND oOR;
//%left oLE oGE oEQ oNE LESS GREATER LBRACKET cELSE;
//%left MINUS PLUS;
//%left STAR SLASH;
%precedence NEG;
//%left fROUND fMOD fTRUNC fFRAC;

//%printer { yyoutput << $$; } <*>; //prints when something
%%

///////////////////////////////
///////////////////////////////+std::to_string(static_cast<unsigned int>($5.valor))
///////////////////////////////
input	    : %empty  /* empty */
            | input '\n' {YYACCEPT;}
            | input programa                    { driver.setResult($2.valor);}
            | illegal
            | error '\n'                        { yyerrok; }
            ;

programa    : expressao                         { $$.valor = $1.valor;}
     	    ;

expressao   : numero                           {$$.valor = $1.valor;}
            | funcao                           {$$.valor = $1.valor;}
            | comando                          {$$.valor = $1.valor;}
            | atribuicao                       {$$.valor = $1.valor;}
			| aritmetica                       {$$.valor = $1.valor;}
            | relacional                       {$$.valor = $1.valor;}
            | "(" expressao ")"                {$$.valor = $2.valor;}
            | atributo                         {$$.valor = $1.valor;}
/****begin_Expression_plugins****/
/**begin_Expression:Variable**/
            | variavel                         {$$.valor = $1.valor;}
/**end_Expression:Variable**/
/**begin_Expression:Formula**/
            | formula                          {$$.valor = $1.valor;}
/**end_Expression:Formula**/
/****end_Expression_plugins****/
            ;

numero      : NUMD                             { $$.valor = $1.valor;}
            | NUMH                             { $$.valor = $1.valor;}
            ;

aritmetica  : expressao PLUS expressao         { $$.valor = $1.valor + $3.valor;}
            | expressao MINUS expressao        { $$.valor = $1.valor - $3.valor;}
            | expressao SLASH expressao        { $$.valor = $1.valor / $3.valor;}
            | expressao STAR expressao         { $$.valor = $1.valor * $3.valor;}
            | expressao POWER expressao        { $$.valor = pow($1.valor,$3.valor);}
            | fEXP "(" expressao ")"	       { $$.valor = exp($3.valor);}
            | MINUS expressao %prec NEG        { $$.valor = -$2.valor;}
            ;

relacional  : expressao oAND expressao         { $$.valor = (int) $1.valor && (int) $3.valor;}
            | expressao oOR  expressao         { $$.valor = (int) $1.valor || (int) $3.valor;}
            | expressao "<"  expressao         { $$.valor = $1.valor < $3.valor ? 1 : 0;}
            | expressao oLE  expressao         { $$.valor = $1.valor <= $3.valor ? 1 : 0;}
            | expressao ">"  expressao         { $$.valor = $1.valor > $3.valor ? 1 : 0;}
            | expressao oGE  expressao         { $$.valor = $1.valor >= $3.valor ? 1 : 0;}
            | expressao oEQ  expressao         { $$.valor = $1.valor == $3.valor ? 1 : 0;}
            | expressao oNE  expressao         { $$.valor = $1.valor != $3.valor ? 1 : 0;}
            ;

comando     : comandoIF	    { $$.valor = $1.valor; }
            | comandoFOR    { $$.valor = $1.valor; }
            ;

comandoIF   : cIF "(" expressao ")" expressao cELSE expressao   { $$.valor = $3.valor != 0 ? $5.valor : $7.valor; }
            | cIF "(" expressao ")" expressao                   { $$.valor = $3.valor != 0 ? $5.valor : 0;}
            ;
//Check for function/need, for now will let cout (these should be commands for program, not expression
comandoFOR  : cFOR variavel "=" expressao cTO expressao cDO atribuicao  {$$.valor = 0; }
            | cFOR atributo "=" expressao cTO expressao cDO atribuicao  {$$.valor = 0; }
            ;

funcao      : funcaoArit                       { $$.valor = $1.valor; }
            | funcaoTrig                       { $$.valor = $1.valor; }
            | funcaoProb                       { $$.valor = $1.valor; }
            | funcaoKernel                     { $$.valor = $1.valor; }
            | funcaoPlugin                     { $$.valor = $1.valor; }
            | funcaoUser                       { $$.valor = $1.valor; }
            ;

funcaoKernel    : fTNOW      { $$.valor = driver.getModel()->getSimulation()->getSimulatedTime();}
                | fTFIN      { $$.valor = driver.getModel()->getSimulation()->getReplicationLength();}
                | CSTAT		 { $$.valor = 0; }
                | fTAVG  "(" CSTAT ")"     {
                    StatisticsCollector* cstat = ((StatisticsCollector*)(driver.getModel()->getElements()->getElement(Util::TypeOf<StatisticsCollector>(), $3.id)));
                    double value = cstat->getStatistics()->average();
                    $$.valor = value; }
                ;

funcaoTrig  : fSIN   "(" expressao ")"         { $$.valor = sin($3.valor); }
            | fCOS   "(" expressao ")"         { $$.valor = cos($3.valor); }
            ;

funcaoArit  : fROUND "(" expressao ")"			    { $$.valor = round($3.valor);}
            | fFRAC  "(" expressao ")"			    { $$.valor = $3.valor - (int) $3.valor;}
            | fTRUNC "(" expressao ")"			    { $$.valor = trunc($3.valor);}
            | fMOD   "(" expressao "," expressao ")"        { $$.valor = (int) $3.valor % (int) $5.valor; }
            ;

funcaoProb  : fRND1					    { $$.valor = driver.sampler()->sampleUniform(0.0,1.0); $$.tipo = "Uniforme"; }
			| fEXPO  "(" expressao ")"                      { $$.valor = driver.sampler()->sampleExponential($3.valor); $$.tipo = "Exponencial";}
            | fNORM  "(" expressao "," expressao ")"        { $$.valor = driver.sampler()->sampleNormal($3.valor,$5.valor); $$.tipo = "Normal"; }
            | fUNIF  "(" expressao "," expressao ")"        { $$.valor = driver.sampler()->sampleUniform($3.valor,$5.valor); $$.tipo = "Uniforme"; }
            | fWEIB  "(" expressao "," expressao ")"        { $$.valor = driver.sampler()->sampleWeibull($3.valor,$5.valor); $$.tipo = "Weibull"; }
            | fLOGN  "(" expressao "," expressao ")"        { $$.valor = driver.sampler()->sampleLogNormal($3.valor,$5.valor); $$.tipo = "LOGNormal"; }
            | fGAMM  "(" expressao "," expressao ")"        { $$.valor = driver.sampler()->sampleGamma($3.valor,$5.valor); $$.tipo = "Gamma"; }
            | fERLA  "(" expressao "," expressao ")"        { $$.valor = driver.sampler()->sampleErlang($3.valor,$5.valor); $$.tipo = "Erlang"; }
            | fTRIA  "(" expressao "," expressao "," expressao ")"  { $$.valor = driver.sampler()->sampleTriangular($3.valor,$5.valor,$7.valor); $$.tipo = "Triangular"; }
            | fBETA  "(" expressao "," expressao "," expressao "," expressao ")"  { $$.valor = driver.sampler()->sampleBeta($3.valor,$5.valor,$7.valor,$9.valor); $$.tipo = "Beta"; }
            | fDISC  "(" listaparm ")"
            ;


//Maybe user defined functions, check if continues on the parser, for now returns the value of expressao
funcaoUser  : "USER" "(" expressao ")"         { $$.valor = $3.valor; }
            ;

//Probably returns parameters for something, check if continues on the parser, for now does nothing
listaparm   : listaparm "," expressao "," expressao
            | expressao "," expressao
            ;
//If illegal token, verifies if throws exception or set error message
illegal     : ILLEGAL           {
		      driver.setResult(-1);
		      if(driver.getThrowsException()){
			if($1.valor == 0){
			  throw std::string("Literal nao encontrado");
			}else if($1.valor == 1){
			  throw std::string("Caracter invalido encontrado");
			}
		      }else{
			if($1.valor == 0){
			  driver.setErrorMessage(std::string("Literal nao encontrado"));
			}else if($1.valor == 1){
			  driver.setErrorMessage(std::string("Caracter invalido encontrado"));
			}
		      }
		}
            ;


// 20181003  ATRIB now returns the attribute ID not the attribute value anymore. So, now get the attribute value for the current entity
atributo    : ATRIB      {  
		    double attributeValue = 0.0;
		    if (driver.getModel()->getSimulation()->getCurrentEntity() != nullptr) {
			// it could crach because there may be no current entity, if the parse is running before simulation and therefore there is no CurrentEntity
			attributeValue = driver.getModel()->getSimulation()->getCurrentEntity()->getAttributeValue($1.id);
		    }
			//std::cout << "Passei" << std::endl;
		    $$.valor = attributeValue; 
		}
	    | ATRIB LBRACKET expressao RBRACKET  {  
		    double attributeValue = 0.0;
		    std::string index = std::to_string(static_cast<unsigned int>($3.valor));
		    if (driver.getModel()->getSimulation()->getCurrentEntity() != nullptr) {
			// it could crach because there may be no current entity, if the parse is running before simulation and therefore there is no CurrentEntity
			attributeValue = driver.getModel()->getSimulation()->getCurrentEntity()->getAttributeValue(index, $1.id);
		    }
		    $$.valor = attributeValue; 
		}
	    | ATRIB LBRACKET expressao "," expressao RBRACKET  {  
		    double attributeValue = 0.0;
		    std::string index = std::to_string(static_cast<unsigned int>($3.valor))+","+std::to_string(static_cast<unsigned int>($5.valor));
		    if (driver.getModel()->getSimulation()->getCurrentEntity() != nullptr) {
			// it could crach because there may be no current entity, if the parse is running before simulation and therefore there is no CurrentEntity
			attributeValue = driver.getModel()->getSimulation()->getCurrentEntity()->getAttributeValue(index, $1.id);
		    }
		    $$.valor = attributeValue; 
		}
	    | ATRIB LBRACKET expressao "," expressao "," expressao RBRACKET  {  
		    double attributeValue = 0.0;
		    std::string index = std::to_string(static_cast<unsigned int>($3.valor))+","+std::to_string(static_cast<unsigned int>($5.valor))+","+std::to_string(static_cast<unsigned int>($7.valor));
		    if (driver.getModel()->getSimulation()->getCurrentEntity() != nullptr) {
			// it could crach because there may be no current entity, if the parse is running before simulation and therefore there is no CurrentEntity
			attributeValue = driver.getModel()->getSimulation()->getCurrentEntity()->getAttributeValue(index, $1.id);
		    }
		    $$.valor = attributeValue; 
		}
            ;

/****begin_ExpressionProdution_plugins****/
/**begin_ExpressionProdution:Variable**/
variavel    : VARI  {$$.valor = ((Variable*)(driver.getModel()->getElements()->getElement(Util::TypeOf<Variable>(), $1.id)))->value();} 
            | VARI LBRACKET expressao RBRACKET	    { 
                std::string index = std::to_string(static_cast<unsigned int>($3.valor));
                $$.valor = ((Variable*)(driver.getModel()->getElements()->getElement(Util::TypeOf<Variable>(), $1.id)))->value(index); }
            | VARI LBRACKET expressao "," expressao RBRACKET	    { 
                std::string index = std::to_string(static_cast<unsigned int>($3.valor))+","+std::to_string(static_cast<unsigned int>($5.valor)); 
                $$.valor = ((Variable*)(driver.getModel()->getElements()->getElement(Util::TypeOf<Variable>(), $1.id)))->value(index);}
            | VARI LBRACKET expressao "," expressao "," expressao RBRACKET    { 
                std::string index = std::to_string(static_cast<unsigned int>($3.valor))+","+std::to_string(static_cast<unsigned int>($5.valor))+","+std::to_string(static_cast<unsigned int>($7.valor));
                $$.valor = ((Variable*)(driver.getModel()->getElements()->getElement(Util::TypeOf<Variable>(), $1.id)))->value(index);}
            ;
/**end_ExpressionProdution:Variable**/

/**begin_ExpressionProdution:Formula**/
// \todo: THERE IS A PROBLEM WITH FORMULA: TO EVALUATE THE FORMULA EXPRESSION, PARSER IS REINVOKED, AND THEN IT CRASHES (NO REENTRACE?)
formula     : FORM	    { 
                $$.valor = ((Formula*)(driver.getModel()->getElements()->getElement(Util::TypeOf<Formula>(), $1.id)))->value();} 
            | FORM LBRACKET expressao RBRACKET {
                std::string index = std::to_string(static_cast<unsigned int>($3.valor));
                $$.valor = ((Formula*)(driver.getModel()->getElements()->getElement(Util::TypeOf<Formula>(), $1.id)))->value(index);}
            | FORM LBRACKET expressao "," expressao RBRACKET {
                std::string index = std::to_string(static_cast<unsigned int>($3.valor)) +","+std::to_string(static_cast<unsigned int>($5.valor));
                $$.valor = ((Formula*)(driver.getModel()->getElements()->getElement(Util::TypeOf<Formula>(), $1.id)))->value(index);}
            | FORM LBRACKET expressao "," expressao "," expressao RBRACKET {
                std::string index = std::to_string(static_cast<unsigned int>($3.valor)) +","+std::to_string(static_cast<unsigned int>($5.valor))+","+std::to_string(static_cast<unsigned int>($7.valor));
                $$.valor = ((Formula*)(driver.getModel()->getElements()->getElement(Util::TypeOf<Formula>(), $1.id)))->value(index);}
            ;
/**end_ExpressionProdution:Formula**/
/****end_ExpressionProdution_plugins****/

//Check if want to set the atributo or variavel with expressao or just return the expressao value, for now just returns expressao value
atribuicao  : ATRIB ASSIGN expressao    { 
                driver.getModel()->getSimulation()->getCurrentEntity()->setAttributeValue("", $1.id, $3.valor);
                $$.valor = $3.valor; }
            | ATRIB LBRACKET expressao RBRACKET ASSIGN expressao    { 
                std::string index = std::to_string(static_cast<unsigned int>($3.valor));
                driver.getModel()->getSimulation()->getCurrentEntity()->setAttributeValue(index, $1.id, $6.valor);
                $$.valor = $6.valor; }
            | ATRIB LBRACKET expressao "," expressao RBRACKET ASSIGN expressao   {
                std::string index = std::to_string(static_cast<unsigned int>($3.valor))+","+std::to_string(static_cast<unsigned int>($5.valor)); 
                driver.getModel()->getSimulation()->getCurrentEntity()->setAttributeValue(index, $1.id, $8.valor); 
                $$.valor = $8.valor;}
            | ATRIB LBRACKET expressao "," expressao "," expressao RBRACKET ASSIGN expressao      {
                std::string index = std::to_string(static_cast<unsigned int>($3.valor))+","+std::to_string(static_cast<unsigned int>($5.valor))+","+std::to_string(static_cast<unsigned int>($7.valor));
                driver.getModel()->getSimulation()->getCurrentEntity()->setAttributeValue(index, $1.id, $10.valor);
                $$.valor = $10.valor; }
/****begin_Assignment_plugins****/
/**begin_Assignment:Variable**/
            | VARI ASSIGN expressao        {
                ((Variable*)(driver.getModel()->getElements()->getElement(Util::TypeOf<Variable>(), $1.id)))->setValue($3.valor);
                $$.valor = $3.valor; }
            | VARI LBRACKET expressao RBRACKET ASSIGN expressao    { 
                std::string index = std::to_string(static_cast<unsigned int>($3.valor));
                ((Variable*)(driver.getModel()->getElements()->getElement(Util::TypeOf<Variable>(), $1.id)))->setValue(index, $6.valor); 
                $$.valor = $6.valor; }
            | VARI LBRACKET expressao "," expressao RBRACKET ASSIGN expressao   {
                std::string index = std::to_string(static_cast<unsigned int>($3.valor))+","+std::to_string(static_cast<unsigned int>($5.valor)); 
                ((Variable*)(driver.getModel()->getElements()->getElement(Util::TypeOf<Variable>(), $1.id)))->setValue(index, $8.valor);
                $$.valor = $8.valor; }
            | VARI LBRACKET expressao "," expressao "," expressao RBRACKET ASSIGN expressao      {
                std::string index = std::to_string(static_cast<unsigned int>($3.valor))+","+std::to_string(static_cast<unsigned int>($5.valor))+","+std::to_string(static_cast<unsigned int>($7.valor));
                ((Variable*)(driver.getModel()->getElements()->getElement(Util::TypeOf<Variable>(), $1.id)))->setValue(index, $10.valor); 
                $$.valor = $10.valor; }
/**end_Assignment:Variable**/
/****end_Assignment_plugins****/
            ;


funcaoPlugin  : CTEZERO                                        { $$.valor = 0; }
/**begin_FunctionProdution_plugins**/
/**begin_FunctionProdution:Queue**/
            | fNQ       "(" QUEUE ")"	    { $$.valor = ((Queue*)(driver.getModel()->getElements()->getElement(Util::TypeOf<Queue>(), $3.id)))->size();}
            | fLASTINQ  "(" QUEUE ")"       {/*For now does nothing because need acces to list of QUEUE, or at least the last element*/ }
            | fFIRSTINQ "(" QUEUE ")"       { 
                if (((Queue*)(driver.getModel()->getElements()->getElement(Util::TypeOf<Queue>(), $3.id)))->size() > 0){
                    //id da 1a entidade da fila, talvez pegar nome
                    $$.valor = ((Queue*)(driver.getModel()->getElements()->getElement(Util::TypeOf<Queue>(), $3.id)))->first()->getEntity()->getId();
                }else{
                    $$.valor = 0;
                } }
            | fSAQUE "(" QUEUE "," ATRIB ")"   {   
                Util::identification queueID = $3.id;
                Util::identification attrID = $5.id;
                double sum = ((Queue*)(driver.getModel()->getElements()->getElement(Util::TypeOf<Queue>(), $3.id)))->sumAttributesFromWaiting(attrID);
                $$.valor = sum; }
            | fAQUE "(" QUEUE "," NUMD "," ATRIB ")" {
                Util::identification queueID = $3.id;
                Util::identification attrID = $7.id;
                double value = ((Queue*)(driver.getModel()->getElements()->getElement(Util::TypeOf<Queue>(), $3.id)))->getAttributeFromWaitingRank($5.valor-1, attrID); // rank starts on 0 in genesys
                $$.valor = value; }
/**end_FunctionProdution:Queue**/

/**begin_FunctionProdution:Resource**/
           | fMR        "(" RESOURCE ")"	{ $$.valor = ((Resource*)driver.getModel()->getElements()->getElement(Util::TypeOf<Resource>(), $3.id))->getCapacity();}
           | fNR        "(" RESOURCE ")"        { $$.valor = ((Resource*)driver.getModel()->getElements()->getElement(Util::TypeOf<Resource>(), $3.id))->getNumberBusy();}
           | fRESSEIZES "(" RESOURCE ")"        { /*For now does nothing because needs get Seizes, check with teacher*/}
           | fSTATE     "(" RESOURCE ")"        {  $$.valor = static_cast<int>(((Resource*)driver.getModel()->getElements()->getElement(Util::TypeOf<Resource>(), $3.id))->getResourceState()); }
            | fIRF       "(" RESOURCE ")"        { $$.valor = ((Resource*)driver.getModel()->getElements()->getElement(Util::TypeOf<Resource>(), $3.id))->getResourceState() == Resource::ResourceState::FAILED ? 1 : 0; }
           | fSETSUM    "(" SET ")"  {
                unsigned int count=0;
                Resource* res;
                List<ModelElement*>* setList = ((Set*)driver.getModel()->getElements()->getElement(Util::TypeOf<Set>(),$3.id))->getElementSet(); 
                for (std::list<ModelElement*>::iterator it = setList->list()->begin(); it!=setList->list()->end(); it++) {
                    res = dynamic_cast<Resource*>(*it);
                    if (res != nullptr) {
                        if (res->getResourceState()==Resource::ResourceState::BUSY) {
                            count++;
                        }
                    }
                }
                $$.valor = count; }
/**end_FunctionProdution:Resource**/

/**begin_FunctionProdution:Set**/
           | fNUMSET    "(" SET ")"	{ $$.valor = ((Set*)driver.getModel()->getElements()->getElement(Util::TypeOf<Set>(),$3.id))->getElementSet()->size(); }

/**end_FunctionProdution:Set**/
/****end_FunctionProdution_plugins****/
           ;


%%
void
yy::genesyspp_parser::error (const location_type& l,
                          const std::string& m)
{
  driver.error (l, m);
}
