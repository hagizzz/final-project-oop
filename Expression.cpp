#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

#include "Expression.h"
#include "Parser.h"
#include "helper.h"

bool Expression::isNum(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (!isNumber(s[i])) return false;
    }
    return true;
}

bool Expression::isFunction(string s) {
    vector<string> funcs{"sin", "cos", "sqrt", "ln", "log", "exp", "tan"};
    return inVector(funcs, s);
}

bool Expression::isOperand(string s) {
    if (isNum(s)) return true;

    vector<string> operands{"pi", "e"};
    return inVector(operands, s);
}

bool Expression::isOperator(string s) {
    vector<string> operators{"+", "-", "*", "/", "%", "^"};
    return inVector(operators, s) || isFunction(s);
}

int Expression::prec(string op) {
    if (op == "+" || op == "-") return 1;
    if (op == "*" || op == "/" || op == "%") return 2;
    if (op == "^") return 3;
    if (isFunction(op)) return 4;

    return 0;
}

void Expression::evalInfix() {
    string op = operators.pop();
    double right = operands.pop();
    double left = operands.pop();

    double res;
    if (op == "+") res = left + right;
    else if (op == "-") res = left - right;
    else if (op == "*") res = left * right;
    else if (op == "/") res = left / right;
    else if (op == "%") res = int(left) % int(right);
    else if (op == "^") res = pow(left, right);
    else if (op == "sqrt") res = sqrt(right);
    else if (op == "sin") res = sin(right);
    else if (op == "cos") res = cos(right);
    else if (op == "tan") res = tan(right);
    else if (op == "ln") res = log(right);
    else if (op == "log") res = log10(right);
    else if (op == "exp") res = exp(right);
    else {
        invalidSyntax(op);
    }

    operands.push(res);
}

void Expression::evalOperand(string operand) {
    double value;

    if (isNum(operand)) value = stod(operand);
    if (operand == "e") value = exp(1);
    if (operand == "pi") value = atan(1)*4;

    operands.push(value);
}

Expression::Expression(string s) {
    input = s;

    Parser p(input);
    tokens = p.parse();

    // Handle simple infix of expression
    if ((tokens[0] == "+" || tokens[0] == "-") && tokens.size() > 1 && isNum(tokens[1])) {
        tokens.insert(tokens.begin(), "0");
    }
}

double Expression::evaluate() {
    for (int i = 0; i < tokens.size(); i++) {
        string token = tokens[i];

        if (isOperator(token)) {
            while (!operators.isEmpty() && prec(token) <= prec(operators.topValue())) {
                evalInfix();
            }
            operators.push(token);
            if (isFunction(token)) operands.push(0);

        } else if (isOperand(token)) {
            evalOperand(token);

        } else if (token == "(") {
            operators.push(token);

        } else if (token == ")") {
            while (operators.topValue() != "(") {
                evalInfix();
            }
            operators.pop();
        } else {
            invalidSyntax(token);
        }
    }

    while (!operators.isEmpty()) {
        evalInfix();
    }

    return operands.topValue();
}
