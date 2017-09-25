/**
    Course: CSC326
    Filename : lab02.cpp
    @author Suresh Melvin Sigera
    @date 09/14/2017
*/
#include <iostream>
#include <vector>
#include<string>

using namespace std;

/**
*
* @tparam ItemType
*/
template<class ItemType>
class ArrayBag {
private:
    static const int DEFAULT_CAPACITY = 200; // bag only holds 200 items
    ItemType items[DEFAULT_CAPACITY];
    int itemCount;
    int maxItems;

public:

    ArrayBag() {
        itemCount = 0;
        maxItems = DEFAULT_CAPACITY;
    }

    int getCurrentSize() const;

    int getIndexOf(const ItemType &target) const;

    int getFrequencyOf(const ItemType &anEntry) const;

    bool add(const ItemType &newEntry);

    bool isEmpty() const;

    bool remove(const ItemType &anEntry);

    void clear();

    bool contains(const ItemType &anEntry) const;

    vector<ItemType> toVector() const;

    ArrayBag<ItemType> findUnion(ArrayBag<ItemType>);

    ArrayBag<ItemType> findIntersection(ArrayBag<ItemType>);

    ArrayBag<ItemType> findDifferenece(ArrayBag<ItemType>);
};

/**
*
* @tparam ItemType
* @param target
* @return
*/
template<class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType &target) const {
    bool isFound = false;
    int result = -1;
    int searchIndex = 0;

    // If the bag is empty, itemCount is zero, so loop is skipped
    while (!isFound && (searchIndex < itemCount)) {
        isFound = (items[searchIndex] == target);
        if (isFound) {
            result = searchIndex;
        } else {
            searchIndex++;
        }  // end if
    }  // end while

    return result;
}  // end getIndexOf

/**
*
* @tparam ItemType
* @param anEntry
* @return
*/
template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType &anEntry) {
    int locatedIndex = getIndexOf(anEntry);
    bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
    if (canRemoveItem) {
        itemCount--;
        items[locatedIndex] = items[itemCount];
    }  // end if

    return canRemoveItem;
}  // end remove

/**
*
* @tparam ItemType
*/
template<class ItemType>
void ArrayBag<ItemType>::clear() {
    itemCount = 0;
}  // end clear

/**
*
* @tparam ItemType
* @param anEntry
* @return
*/
template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType &anEntry) const {
    int frequency = 0;
    int curIndex = 0;       // Current array index
    while (curIndex < itemCount) {
        if (items[curIndex] == anEntry) {
            frequency++;
        }  // end if

        curIndex++;          // Increment to next entry
    }  // end while

    return frequency;
}  // end getFrequencyOf


/**
*
* @tparam ItemType
* @return
*/
template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const {
    return itemCount;
}

/**
*
* @tparam ItemType
* @param newEntry
* @return
*/
template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType &newEntry) {
    bool hasRoomToAdd = (itemCount < maxItems);
    if (hasRoomToAdd) {
        items[itemCount] = newEntry;
        itemCount++;
    }  // end if

    return hasRoomToAdd;
}  // end add

/**
*
* @tparam ItemType
* @return
*/
template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const {
    return itemCount == 0;
}

/**
*
* @tparam ItemType
* @param anEntry
* @return
*/
template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType &anEntry) const {
    bool isFound = false;
    int curIndex = 0; // Current array index
    while (!isFound && (curIndex < itemCount)) {
        isFound = (anEntry == items[curIndex]);
        if (!isFound)
            curIndex++; // Increment to next entry
    } // end while

    return isFound;
} // end contains

/**
*
* @tparam ItemType
* @return
*/
template<class ItemType>
vector<ItemType> ArrayBag<ItemType>::toVector() const {
    vector<ItemType> bagContents;
    for (int i = 0; i < itemCount; i++) {
        bagContents.push_back(items[i]);
        //cout << bagContents[i];
    }

    return bagContents;
}  // end toVector

/**
 *
 * @tparam ItemType
 * @param bag2
 * @return
 */
template<class ItemType>
ArrayBag<ItemType> ArrayBag<ItemType>::findUnion(ArrayBag<ItemType> bag2) {
    ArrayBag<ItemType> unionBag;
    vector<ItemType> arrayBag2 = bag2.toVector();

    for (int i = 0; i < itemCount; i++) {
        unionBag.add(items[i]);
    }

    for (int i = 0; i < arrayBag2.size(); i++) {
        unionBag.add(arrayBag2.at(i));
    }

    return unionBag;

}

/**
 *
 * @tparam ItemType
 * @param bag2
 * @return
 */
template<class ItemType>
ArrayBag<ItemType> ArrayBag<ItemType>::findIntersection(ArrayBag<ItemType> bag2) {
    ArrayBag<ItemType> intersectionBag;
    vector<ItemType> arrayBag1 = toVector();
    vector<ItemType> arrayBag2 = bag2.toVector();

    ItemType tempValue;

    //sort(arrayBag1.begin(), arrayBag1.end());

    for (int i = 0; i < itemCount; i++) {
        tempValue = items[i];

        for (int j = 0; j < arrayBag2.size(); j++) {
            if (tempValue == arrayBag2.at(j)) {
                arrayBag2.erase(arrayBag2.begin() + j);
                intersectionBag.add(tempValue);
            }
        }
    }
    return intersectionBag;
}

/**
 *
 * @tparam ItemType
 * @param bag2
 * @return
 */
template<class ItemType>
ArrayBag<ItemType> ArrayBag<ItemType>::findDifferenece(ArrayBag<ItemType> bag2) {
    ArrayBag<ItemType> differenceBag;
    vector<ItemType> arrayBag1 = toVector();
    vector<ItemType> arrayBag2 = bag2.toVector();

    ItemType tempValue;

    //sort(arrayBag1.begin(), arrayBag1.end());

    bool found;

    for (int i = 0; i < itemCount; i++) {
        tempValue = items[i];
        found = false;
        for (int j = 0; j < arrayBag2.size(); j++) {
            if (tempValue == arrayBag2.at(j)) {
                found = true;
                arrayBag2.erase(arrayBag2.begin() + j);
                break;
            }
        }
        if (!found) {
            differenceBag.add(tempValue);
        }
    }
    return differenceBag;
}

/**
 *
 * @param bag
 */
void displayBag(ArrayBag<string> &bag) {
    cout << "The bag contains " << bag.getCurrentSize()
         << " items:" << endl;
    vector<string> bagItems = bag.toVector();
    int numberOfEntries = (int) bagItems.size();

    for (int i = 0; i < numberOfEntries; i++) {
        cout << bagItems[i] << "     ";
    }  // end for

    cout << endl << endl;
}  // end displayBag

/**
 *
 * @return
 */
int main() {

    string bag1Items[] = {"two", "four", "six", "eight", "ten", "twelve", "four"};
    string bag2Items[] = {"four", "eleven", "two", "thirteen", "ten", "twelve"};

    ArrayBag<string> bag1;
    ArrayBag<string> bag2;
    ArrayBag<string> bag3;

    int sizeArray1 = sizeof(bag1Items) / sizeof(bag1Items[0]);
    int sizeArray2 = sizeof(bag2Items) / sizeof(bag2Items[0]);

    for (int i = 0; i < sizeArray1; i++)
        bag1.add(bag1Items[i]);

    for (int i = 0; i < sizeArray2; i++)
        bag2.add(bag2Items[i]);


    cout << "\n--------------------------------------------------------\n";

    cout << "Displaying bag 1 : " << endl << endl;
    displayBag(bag1);
    cout << "\n--------------------------------------------------------\n";
    cout << "Displaying bag 2 : " << endl;
    displayBag(bag2);

    cout << "\n--------------------------------------------------------\n";
    cout << "Result of Union of Bag 1 and Bag2 : " << endl << endl;

    bag3 = bag1.findUnion(bag2);
    displayBag(bag3);


    cout << "\n--------------------------------------------------------\n";
    cout << "Result of Intersection of Bag 1 and Bag2 : " << endl << endl;

    bag3 = bag1.findIntersection(bag2);
    displayBag(bag3);


    cout << "\n--------------------------------------------------------\n";
    cout << "Result of Difference of Bag 1 and Bag2 : " << endl << endl;
    bag3 = bag1.findDifferenece(bag2);
    displayBag(bag3);

//    system("pause");

    return 0;
}