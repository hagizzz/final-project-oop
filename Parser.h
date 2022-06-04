#pragma once

class Parser {
private:
    string input;
    int pos;
    char ch;
    vector<string> tokens;

    void readChar();
    string parseNumber();
    string parseWord();
    void skipWhitespace();

public:
    Parser(string);
    vector<string> parse();
};
