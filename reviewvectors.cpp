//
// Created by Suresh Melvin Sigera on 9/26/17.
//

#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<string> myString(5);
    myString[0] = "one";
    myString[1] = "two";
    myString[2] = "three";
    myString[3] = "four";
    myString[4] = "five";


    for(int i=0; i<myString.size(); i++){
        cout<<myString[i] <<endl;
    }

    cout << endl << endl;

    myString.pop_back();

    for(int i=0; i<myString.size(); i++){
        cout<<myString[i] <<endl;
    }

    return 0;
}