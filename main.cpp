#include <bits/stdc++.h>
#include "LinkedList.hpp"
// #include "LinkedList.hpp"

using namespace std;

int main (int argc, char *argv[]) {
    LinkedList<int> myList;
    myList.addAtHead(3);
    myList.addAtHead(2);

    cout << myList.get(0) << endl;



    return 0;
}