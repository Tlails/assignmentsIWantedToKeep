#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "phoneBook.cpp"

using namespace std;

int main(){
    phoneBook myphonebook;   // create an object of a class type phonebook
    myphonebook.menu();      // call a class method using the object. 
			     // You are calling the menu function
    return 0;
}

