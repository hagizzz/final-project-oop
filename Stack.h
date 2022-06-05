
template <class Type> class Node {
public:
    Type value;
    Node* next;
};

template <class Type> class Stack {
Node<Type>* head;
public:
    Stack();
    Type topValue();
    bool isEmpty();
    void push(Type value);
    Type pop();
};
