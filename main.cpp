/*
Bai 2
Ten: Vo Ha Giang
MSSV: 20110172
*/
#include "lib.h"
#include "helper.cpp"
#include "Parser.cpp"
#include "Stack.cpp"
#include "Expression.cpp"

using namespace std;

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
