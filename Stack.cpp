#pragma once
#include "Stack.h"

template<typename Type>
Stack<Type>::Stack() {
    head = NULL;
}

template<typename Type>
Type Stack<Type>::topValue() {
    return head->value;
}

template<typename Type>
bool Stack<Type>::isEmpty() {
    return head == NULL;
}

template<typename Type>
void Stack<Type>::push(Type value) {
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

template<typename Type>
Type Stack<Type>::pop() {
    Node<Type>* p = head;
    Type value = head->value;
    head = p->next;
    delete p;
    // cout << "Pop: " << value << endl;
    return value;
}
