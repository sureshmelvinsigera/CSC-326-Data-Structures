//
// Created by mr47 on 11/14/17.
//

#include <iostream>

using namespace std;

template<class T>
class Node {
public:
    Node();

    Node(T anItem);

    Node(T anItem, Node<T> *nodePtr);

    T item;

    Node<T> *next;
};

template<class T>
Node<T>::Node() {
    cout << "Calling default Node() constructor";
    next = nullptr;
}

template<class T>
Node<T>::Node(T anItem) {
    cout << "Calling default Node(T anItem) constructor";
    item = anItem;
}

template<class T>
Node<T>::Node(T anItem, Node<T> *nodePtr) {
    cout << "Calling default Node(T anItem, Node<T> *nodePtr)";
    item = anItem;
    next = nullptr;
}