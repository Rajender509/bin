%{
#include "y.tab.h"
%}
%%
[a-zA-Z][a-zA-Z0-9]*    { return VARIABLE; }
.|\n                    { return yytext[0]; }

%%
int yywrap()
{
    return 1;
}

var.y
%{
#include <stdio.h>
%}
%token VARIABLE

%%
input:
    VARIABLE '\n'     { printf("Valid variable\n"); return 0; }
  | '\n'              { printf("Empty input\n"); return 0; }
  ;
%%

int main() {
    printf("Enter a variable name:\n");
    yyparse();
    return 0;
}
int yyerror(const char *msg) {
    printf("Invalid variable: %s\n", msg);
    return 0;
}

OUTPUT
kits@kits-Veriton-M200-B360:~/Desktop$ yacc -d var.y
kits@kits-Veriton-M200-B360:~/Desktop$ lex var.l
kits@kits-Veriton-M200-B360:~/Desktop$ gcc lex.yy.c y.tab.c -o varcheck
kits@kits-Veriton-M200-B360:~/Desktop$ ./varcheck
Enter a variable name:
username
Valid variable
kits@kits-Veriton-M200-B360:~/Desktop$ ./varcheck
Enter a variable name:
*user
Invalid variable: syntax error
c) Implementation of calculator using lex and yacc.

calc.l
%{
#include "y.tab.h"
%}

%%

[0-9]+              { yylval = atoi(yytext); return NUMBER; }
[ \t]               ; // ignore whitespace

\n                  { return NEWLINE; }

"+"                 { return PLUS; }
"-"                 { return MINUS; }
"*"                 { return MUL; }
"/"                 { return DIV; }
"("                 { return LPAREN; }
")"                 { return RPAREN; }

.                   { return yytext[0]; }

%%

int yywrap() {
    return 1;
}

calc.y
%{
#include <stdio.h>
#include <stdlib.h>
%}

%token NUMBER
%token PLUS MINUS MUL DIV LPAREN RPAREN NEWLINE

%left PLUS MINUS
%left MUL DIV
%left UMINUS

%%

input:
      input line
    | /* empty */
    ;
line:
      expr NEWLINE   { printf("Result = %d\n", $1); }
    | NEWLINE
    ;
expr:
      expr PLUS expr   { $$ = $1 + $3; }
    | expr MINUS expr  { $$ = $1 - $3; }
    | expr MUL expr    { $$ = $1 * $3; }
    | expr DIV expr    {
                          if ($3 == 0)
                              printf("Error: Division by zero!\n");
                          else
                              $$ = $1 / $3;
                       }
    | LPAREN expr RPAREN { $$ = $2; }
    | MINUS expr %prec UMINUS { $$ = -$2; }
    | NUMBER            { $$ = $1; }
    ;

%%

int main() {
    printf("Enter expressions (Ctrl+D to exit):\n");
    yyparse();
    return 0;
}

int yyerror(char *msg) {
    printf("Syntax error!\n");
    return 1;
}

OUTPUT

kits@kits-Veriton-M200-B360:~/Desktop$ yacc -d calc.y
kits@kits-Veriton-M200-B360:~/Desktop$ lex calc.l
kits@kits-Veriton-M200-B360:~/Desktop$ gcc lex.yy.c y.tab.c -o calculator
kits@kits-Veriton-M200-B360:~/Desktop$ ./calculator
Enter expressions (ctrl+d to exit):
3*4+2
Result = 14
3+4*2
Result = 11
4%2


