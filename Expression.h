
class Expression {
private:
    string input;
    Stack<string> operators;
    Stack<double> operands;
    vector<string> tokens;

    bool isNum(string);
    bool isFunction(string);
    bool isOperand(string);
    bool isOperator(string);

    void handleInvalidInfix(int tokenIndex);
    int prec(string);
    void evalInfix();
    void evalOperand(string);

public:
    Expression(string);
    double evaluate();
};
