/*
Bai 2
Ten: Vo Ha Giang
MSSV: 20110172
*/
#include "lib.h"
#include "include.h"

using namespace std;

int main() {
    string input;
    cout << "Welcome to expression evaluator" << endl;
    cout << "Type \"exit\" to escape the program" << endl;
    while (true) {
        cout << ">> ";
        getline(cin, input);

        if (input == "exit") break;

        Expression expr(input);
        double value = expr.evaluate();
        printFormat(value);
    }
    cout << "Goodbye!";

    return 0;
}
