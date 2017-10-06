//
// Created by Suresh Melvin Sigera on 10/6/17.
//

#include <iostream>

using namespace std;

class Person {
public:
    /**
     * Default constructor
     * @param thisAge
     * @param thisName
     */
    Person(int thisAge, string thisName) {
        this->age = thisAge;
        this->name = thisName;
        cout << endl << "Default constructor is called";
        cout << endl << "Name is " << this->name << " Age is " << this->age;
    }

    /**
     * Copy constructor
     * @param source
     */
    Person(const Person &source);

    /**
     *
     * @param thisAge
     * @param thisName
     */
    void updateInformation(int thisAge, string thisName);

    /**
     * print data members
     */
    void print();

private:
    int age;
    string name;
};

/**
 *
 * @param source
 */
Person::Person(const Person &source) {
    cout << endl << "copy constructor is called" << endl;
    age = source.age;
    name = source.name;
    cout << endl << "Name is " << this->name << " Age is " << this->age;
    cout << endl;
}

/**
 *
 * @param thisAge
 * @param thisName
 */
void Person::updateInformation(int thisAge, string thisName) {
    cout << endl << "The old name is " << this->name;
    cout << endl << "The old name is " << this->age;

    this->name = thisName;
    this->age = thisAge;

    cout << endl << "The new name is " << this->name;
    cout << endl << "The old name is " << this->age;
}

/**
 * print data members
 */
void Person::print() {
    cout << endl << "Name is " << this->name;
    cout << endl << "Age is " << this->age;
    cout << endl;
}

/**
 *
 * @return
 */
int main() {
    Person obj1(11, "Suresh");
    //Person melvin(suresh);
    //Person melvin = suresh;

    Person obj2 = obj1; //copying the object 1 to object 2; shallow copy

    Person *obj1Ptr = &obj1; //hold the address of object1
    Person *obj2Ptr = &obj2; //hold the address of object1

    cout << endl << "Address of this object is suresh is " << obj1Ptr;
    cout << endl << "Address of this object is melvin is " << obj2Ptr;

    cout << endl << "Printing values" << endl;

    obj1.print();
    obj2.print();
    obj2.updateInformation(76, "John");
    obj1.print();
    obj2.print();
}