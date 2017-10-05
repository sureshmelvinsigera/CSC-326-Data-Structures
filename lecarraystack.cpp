//
// Created by Suresh Melvin Sigera on 10/5/17.
//

#include <iostream>

using namespace std;

/**
 *
 * @tparam T
 */
template<class T>
class arrayStack {
private:
    static const int DECAP = 100;
    T items[DECAP];
    int top;

public:

    /**
     * default constructor
     */
    arrayStack();

    /**
     *
     * @return bool
     */
    bool isEmpty() const;  /* const type methodname() const*/

    /**
     *
     * @param nEntry
     * @return
     */
    bool push(const T &nEntry);

    /**
     *
     * @return
     */
    bool pop();

    /**
     * look for specific item
     * @return
     */
    bool peek() const;

    /**
     *
     */
    void printStack() const;
};

template<class T>
arrayStack<T>::arrayStack() {
    this->top = -1;
    cout << endl << "Calling default constructor" << endl;
}

/**
 *
 * @tparam T
 * @return
 */
template<class T>
bool arrayStack<T>::isEmpty() const {
    return this->top < 0;
}

/**
 *
 * @tparam T
 * @param nEntry
 * @return
 */
template<class T>
bool arrayStack<T>::push(const T &nEntry) {
    bool result = false;
    if (top = DECAP - 1) {
        top++;
        items[top] = nEntry;
        result = true;
    }
    return result;
}

/**
 *
 * @tparam T
 * @return
 */
template<class T>
bool arrayStack<T>::pop() {
    bool result = false;
    if (!isEmpty()) {
        items[top] = 0;
        top--;
        result = true;
    }
    return true;
}

/**
 *
 * @tparam T
 * @return
 */
template<class T>
bool arrayStack<T>::peek() const {

}


template<class T>
void arrayStack<T>::printStack() const {
    cout << endl;
    for (int i = 0; i < top; i++) {
        cout << items[i] << " ";
    }
    cout << endl;

}

/**
 *
 * @return
 */
int main() {
    int itemObjects[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    arrayStack<int> arrayStackObj;
    cout << endl << "Is stack is empty " << arrayStackObj.isEmpty();
    cout << endl << "Inserting the items ";

    for (int i = 0; i < 9; i++) {
        cout << itemObjects[i];
        arrayStackObj.push(itemObjects[i]);
    }

    cout << endl << "Let see what in the stack";
    arrayStackObj.printStack();
}