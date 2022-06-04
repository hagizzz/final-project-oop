#pragma once
#include "Parser.h"
#include "helper.h"

Parser::Parser(string str) {
    input = str;
    pos = 0;
    readChar();
}

vector<string> Parser::parse() {
    while (pos <= input.length()) {
        skipWhitespace();

        if (isSign(ch)) {
            tokens.push_back(toStr(ch));
            readChar();

        } else if (isNumber(ch)) {
            string num = parseNumber();
            tokens.push_back(num);

        } else if (isLetter(ch)) {
            string word = parseWord();
            tokens.push_back(word);

        } else {
            string msg = "Invalid character: '";
            msg.push_back(ch);
            msg.push_back('\'');
            throwErr(msg);
        }
    }
    return tokens;
}

void Parser::readChar() {
    if (pos >= input.length()) ch = 0; // NULL char

    ch = input[pos];
    pos++;
}

string Parser::parseNumber() {
    string num;
    while (isNumber(ch)) {
        num.push_back(ch);
        readChar();
    }
    return num;
}

string Parser::parseWord() {
    string word;
    while (isLetter(ch)) {
        word.push_back(ch);
        readChar();
    }
    return word;
}

void Parser::skipWhitespace() {
    while (ch == ' ' || ch == '\t' || ch == '\n') {
        readChar();
    }
}
