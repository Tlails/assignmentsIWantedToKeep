// Fill in student names and description of program

#include <string>
#include <vector>
#include <bitset>
#include <fstream>

using namespace std;

struct contact {
    string lname;
    string fname;
    string mobile;
    string emailID;
};

class phoneBook {
private:
    //vector of the contacts. Notice the type of the vector
    vector<contact> myContacts;
    void displayPhoneBook(){
        for (unsigned int i = 0; i < myContacts.size(); i++){
    	   cout << "last name " << myContacts[i].lname 
                << " fname "    << myContacts[i].fname
                << " mobile "   << myContacts[i].mobile
                << " e-mail " << myContacts[i].emailID << endl;
        }
    }

    //Other functions here.

public:
    // Menu is for sure a public functions. Others may or may not be
    void menu(){
        // Test import
        if(import("/home/student/phonebook.txt")){
            displayPhoneBook();
        }
        else{
            cout << "phonebook.txt file can not be opened" << endl;
        }
    }
    // For testing purposes, Please leave intact
#ifdef MIMIR_TEST
    vector <contact> getInternalState() {
        return myContacts;
    }
#endif
    // returns a true if the file is found and is readable
    // returns a false if the file in not found or not readable
    bool import(string phoneBookFile){
        //This is the only function partially filled. Write the other functions as well.
        //Create a file-stream object with stream class to read from files (ifstream)
        ifstream myFile;
        //Link the input file to this object;
        myFile.open(phoneBookFile.c_str());

        if(!myFile) return false;

        //Read the strings in the text file and copy them to your phonebook
        contact temp;
        while(!myFile.eof()){

            myFile >> temp.lname
                   >> temp.fname
                   >> temp.mobile
                   >> temp.emailID;
            myContacts.push_back(temp);
        }

        myFile.close();

        return true;
    }

};
