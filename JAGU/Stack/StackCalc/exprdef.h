#ifndef _EXPR_DEF_
#define _EXPR_DEF_

typedef enum PrecedenceType { lparen, rparen, times, divide, PLUS, MINUS, operand } Precedence;
// lparen : ( , rparen : ), times : *, divide : /, plus : +, minus: -, operand : 피연산자(0, 1, 2, ...)

class ExprToken {
public:
	float value;
	Precedence type;
};

#endif