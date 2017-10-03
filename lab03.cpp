/**
    Course: CSC326
    Filename : lab03.cpp
    @author Suresh Melvin Sigera
    @date 09/14/2017
*/

#include <iostream>
#include <string>
#include<math.h>
#include<fstream>

using namespace std;

class Node {
public:
    int value;
    Node *next;

    Node() {
        value = 0;
        next = NULL;
    }

    Node(int n) {
        value = n;
        next = NULL;
    }
};

class linkedNumber {
public:
    void addNode(Node *&head, int n) {
        Node *tmp = new Node(n);
        tmp->next = head;
        head = tmp;
    }

    void print(Node *h) {
        if (!h) return;
        print(h->next);
        cout << h->value;
    }

    Node *add(Node *list1, Node *list2) {
        int carry = 0, sum;
        Node *result = NULL;
        Node *tempNode = NULL;
        Node *previousNode = NULL;

        while (list1 != NULL || list2 != NULL) {
            sum = carry + ((list1 ? list1->value : 0) + (list2 ? list2->value : 0));
            if (sum >= 10000)
                carry = 1;
            else
                carry = 0;

            sum = sum % 10000;
            tempNode = new Node(sum);

            if (result == NULL) {
                result = tempNode;
            } else {
                previousNode->next = tempNode;
            }

            previousNode = tempNode;
            if (list1)
                list1 = list1->next;
            if (list2)
                list2 = list2->next;
        }
        if (carry > 0)
            tempNode->next = new Node(carry);
        return result;
    }

    Node *divide(Node *list1, Node *list2) {
        int carry = 0, multiplyResult;
        Node *result = NULL;
        Node *tempNode = NULL;
        Node *previousNode = NULL;
        Node *finalResult = NULL;
        Node *tempList2 = NULL;
        int count = 0;

        while (list1 != NULL) {
            tempList2 = list2;
            if (count > 0) {
                count = pow(10, count);
                list1->value = list1->value * count;
            }
            count++;
            result = NULL;
            while (tempList2 != NULL) {
                multiplyResult = carry + (list1->value * tempList2->value);
                if (multiplyResult >= 10)
                    carry = (multiplyResult / 10);
                else
                    carry = 0;
                multiplyResult = multiplyResult % 10;
                tempNode = new Node(multiplyResult);

                if (result == NULL) {
                    result = tempNode;
                } else {
                    previousNode->next = tempNode;
                }
                previousNode = tempNode;
                if (tempList2)
                    tempList2 = tempList2->next;
                //if (carry > 0)
                ///tempNode->next = new Node(carry);

                if (tempList2 == NULL && carry != 0)
                    previousNode->next = new Node(carry);
            }
            if (list1)
                list1 = list1->next;
            finalResult = add(result, finalResult);

        }

        if (carry > 0)
            tempNode->next = new Node(carry);
        return finalResult;
    }

    Node *multiply(Node *list1, Node *list2) {
        int carry = 0, multiplyResult;
        Node *result = NULL;
        Node *tempNode = NULL;
        Node *previousNode = NULL;
        Node *finalResult = NULL;
        Node *tempList2 = NULL;
        int count = 0;
        while (list1 != NULL) {
            tempList2 = list2;
            if (count > 0) {
                count = pow(10000, count);
                list1->value = list1->value * count;
            }
            count++;
            result = NULL;
            while (tempList2 != NULL) {
                multiplyResult = carry + (list1->value * tempList2->value);
                if (multiplyResult >= 10000)
                    carry = (multiplyResult / 10000);
                else
                    carry = 0;

                multiplyResult = multiplyResult % 10000;

                tempNode = new Node(multiplyResult);

                if (result == NULL) {
                    result = tempNode;
                } else {
                    previousNode->next = tempNode;
                }

                previousNode = tempNode;


                if (tempList2)
                    tempList2 = tempList2->next;

                //if (carry > 0)
                ///tempNode->next = new Node(carry);

                if (tempList2 == NULL && carry != 0)
                    previousNode->next = new Node(carry);

            }
            if (list1)
                list1 = list1->next;

            finalResult = add(result, finalResult);

        }

        if (carry > 0)
            tempNode->next = new Node(carry);

        return finalResult;
    }

    Node *subtract(Node *list1, Node *list2) {
        int carry = 0, sum;
        Node *result = NULL;
        Node *tempNode = NULL;
        Node *previousNode = NULL;

        while (list1 != NULL || list2 != NULL) {
            sum = carry + ((list1 ? list1->value : 0) - (list2 ? list2->value : 0));

            if (sum < 0)
                carry = -10000;
            else
                carry = 0;


            if (carry < 0)
                sum += 10000;

            /*sum = sum % 10;*/

            tempNode = new Node(sum);
            if (result == NULL) {
                result = tempNode;
            } else {
                previousNode->next = tempNode;
            }
            previousNode = tempNode;
            if (list1)
                list1 = list1->next;
            if (list2)
                list2 = list2->next;
        }
        //if(carry < 0)
        /*tmp->next = new Node(carry);*/

        return result;
    }

};

int main() {
    string number1, number2;
    char operation, choice;
    string fileName;
    int v;
    linkedNumber link;

    ifstream file;
    file.open("/home/mr47/Documents/Universal/CSI/2017/Fall/CSC326/workspace/lab03data.txt");

    if (file.is_open()) {
        cout << "File is open" << endl;
        cout << "What operation you want to perform: " << endl;
        cout << "Add '+'" << endl;
        cout << "Subtract '-'" << endl;
        cout << "Divide '/'" << endl;
        cout << "Multiply '*'" << endl;

        cout << "Enter your choice:";
        cin >> operation;

        while (!file.eof()) {

            file >> number1;
            file >> number2;

            Node *list1 = NULL;
            Node *list2 = NULL;
            Node *result = NULL;

            string temp = "";
            for (int i = number1.length() - 1; i >= 0; i -= 4) {
                link.addNode(list1, stoi(number1.substr(i, 4)));
            }

            for (int i = number2.length() - 1; i >= 0; i -= 4) {
                link.addNode(list2, stoi(number2.substr(i, 4)));
            }

            cout << "\n First Number:";
            link.print(list1);
            cout << endl;

            cout << "\n Second Number:";
            link.print(list2);
            cout << endl;

            if (operation == '+') {
                result = link.add(list1, list2);
            } else if (operation == '-') {
                if (number2 > number1) {
                    result = link.subtract(list2, list1);
                } else {
                    result = link.subtract(list1, list2);
                }
            } else if (operation == '*') {
                result = link.multiply(list1, list2);
            }

            cout << "\n Result:";
            link.print(result);

            cout << endl << endl << endl;
            file >> number1;
        }
    } else {
        cerr << "Cannot open the file" << endl;
    }

    return 0;
}