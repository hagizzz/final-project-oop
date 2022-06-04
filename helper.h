#pragma once
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

string toStr(char ch) {
    string s(1, ch);
    return s;
}

bool isSign(char ch) {
    vector<char> signs{'+', '-', '*', '/', '%', '^', '(', ')'};
    for (int i = 0; i < signs.size(); i++) {
        if (ch == signs[i]) return true;
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
    string s = to_string(x);
    size_t dot = s.find_first_of('.'), last = s.find_last_not_of(".0");

    if (dot != string::npos) cout << s.substr(0, max(dot,last+1));
    else cout << s;
}

void throwErr(string msg) {
    cout << "[!] " << msg;
    exit(0);
}

void invalidSyntax(string token) {
    throwErr("Invalid syntax: '" + token + "'");
}
