/**
    Course: CSC326
    Filename : lab01.cpp
    Purpose:
    @author Suresh Melvin Sigera
    @date 09/10/2017
*/

#include<iostream>

using namespace std;

const int dSize = 10; // default size

template<class T>
class SA {
private:
    T *pT; // pointer of T type
    int lIdx; // low index
    int hIdx; // high index
public:
    //Default Constructor
    SA() {
        pT = new T[dSize];    //Initializing memory
        lIdx = 0;    //Lowest index
        hIdx = 9;    //Highest Index

    }

    //parameterized SA(int n)constructor
    SA(int n) {
        pT = new T[n];    //Initializing memory
        lIdx = 0;    //Lowest index
        hIdx = 9;    //Highest Index

    }

    //parameterized SA(int l, int h) constructor
    SA(int l, int h) {
        pT = new T[h - l + 1];
        lIdx = l;
        hIdx = h;


    }

    //copy Constructor
    SA(const SA &sa) {
        pT = new T[sa.getSize()];    //initializing memory

        for (int i = 0; i < sa.getSize(); i++) {
            pT[i] = sa[i];    //copying the elements from other object
        }
    }

    //destructor
    ~SA() {
        delete[] pT;    //deallocating memory
    }

    //function to get size
    int getSize() const {
        return hIdx + 1;
    }

    //assignment opertator overload
    SA &operator=(const SA &SA);

    //outstream operator overload
    template<class T2>
    friend ostream &operator<<(ostream &out, const SA <T2> &obj);

    //array assignment  operator
    T &operator[](const int index);

    //array get operator
    const T &operator[](const int index) const;
};

//assignment operator
template<class T>
SA<T> &SA<T>::operator=(const SA &sa) {

    if (this == &sa)
        return *this;
    pT = new T[sa.getSize()];    //intialize array according to size of other object
    for (int i = 0; i < sa.getSize(); i++) {
        pT[i] = sa[i];    //copying elements
    }

    return *this;
}

//outstream operator overload
template<class T2>
ostream &operator<<(ostream &out, const SA<T2> &obj) {
    out << obj->pT << endl;    //output the element
    return out;
}

//for array assignment
template<class T>
T &SA<T>::operator[](const int index) {
    if (index >= lIdx && index <= hIdx)
        return pT[index];
    else
        cout << "\n Error: Index out of range..!!";
}

//for array index access
template<class T>
const T &SA<T>::operator[](const int index) const {
    if (index >= lIdx && index <= hIdx)
        return pT[index];
    else
        cout << "\n Error: Index out of range..!!";

}

int main() {
    SA<int> tempOBj;
    SA<int> tempObj3(tempOBj);
    tempOBj[0] = 123;
    SA<int> tempOBj2;
    tempOBj2[0] = tempOBj[0];
    cout << tempOBj[43];
    cout << tempOBj[-5];

    SA<double> tempOBj4;
    tempOBj4[0] = 2.5;
    SA<double> tempObj5(tempOBj4);
    cout << endl << tempObj5[0] << endl;

    cout << endl << endl;

    return 0;
}