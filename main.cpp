/*
Bai 2
Ten: Vo Ha Giang
MSSV: 20110172
*/

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

#include "Parser.cpp"
#include "Stack.cpp"
#include "Expression.cpp"

int main() {
    string input;
    cout << "Enter expression: ";
    getline(cin, input);

    Expression expr(input);
    double value = expr.evaluate();

    cout << "Value: ";
    printFormat(value);

    return 0;
}
