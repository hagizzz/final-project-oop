#include <iostream>
using namespace std;

template <class Type> class Node {
public:
    Type value;
    Node* next;
};

template <class Type> class Stack {
Node<Type>* head;
public:
    Stack() {
        head = NULL;
    }
    Type topValue() {
        return head->value;
    }
    bool isEmpty() {
        return head == NULL;
    }
    void push(Type value) {
        Node<Type>* p = new Node<Type>();
        p->value = value;
        p->next = NULL;

        if (isEmpty()) {
            head = p;
        } else {
            p->next = head;
            head = p;
        }
        // cout << "Push: " << value << endl;
    }
    Type pop() {
        Node<Type>* p = head;
        Type value = head->value;
        head = p->next;
        delete p;
        // cout << "Pop: " << value << endl;
        return value;
    }
};
