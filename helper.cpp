#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include <math.h>
using namespace std;

string toStr(char ch) {
    string s(1, ch);
    return s;
}

bool isSymbol(char ch) {
    vector<char> symbols{'+', '-', '*', '/', '%', '^', '(', ')'};
    for (int i = 0; i < symbols.size(); i++) {
        if (ch == symbols[i]) return true;
    }
    return false;
}

bool isNumber(char ch) {
    return '0' <= ch && ch <= '9' || ch == '.';
}

bool isLetter(char ch) {
    return ('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z');
}

bool inVector(vector<string>& arr, string s) {
    for (string& each : arr) {
        if (each == s) {
            return true;
        }
    }
    return false;
}

void printFormat(double x) {
    if (x > pow(2, 100)) {
        cout << fixed << x << endl;
        return;
    }

    string s = to_string(x);
    size_t dot = s.find_first_of('.'), last = s.find_last_not_of(".0");

    if (dot != string::npos) cout << s.substr(0, max(dot,last+1));
    else cout << s;

    cout << endl;
}

void throwErr(string msg) {
    cout << "[!] " << msg;
    exit(0);
}

void invalidSyntax(string token) {
    throwErr("Invalid syntax: '" + token + "'");
}
