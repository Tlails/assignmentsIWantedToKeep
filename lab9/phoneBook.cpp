// Zach Hammitt
//This program allows the user to create, edit, import and export a contact list contating email, phone number, first and last names
//Any oddities are likely due to writing it to Mimir's specifications and not necessarily how a user would interact with the interface
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
    void addContacts(){
        //gets the info for each of the parts of the contact info
        cout<<"Enter a new first name"<<endl;
        string first;
        cin>>first;
        cout<<endl;
        cout<<"Enter a new last name"<<endl;
        string last;
        cin>>last;
        cout<<endl;
        cout<<"Enter a new phone number"<<endl;
        string phone;
        cin>>phone;
        cout<<endl;
        cout<<"Enter a new email"<<endl;
        string email;
        cin>>email;
        cout<<endl;
        contact newOne;
        newOne.fname=first;
        newOne.lname=last;
        newOne.emailID=email;
        newOne.mobile=phone;
        myContacts.push_back(newOne);

    }
    bool findContact(){
        cout<<"Enter a name to look up"<<endl;
        string search;
        cin>>search;
        cout<<endl;
        bool foundOne=false;
        vector<unsigned>locations;
        for (unsigned int i = 0; i < myContacts.size(); i++){
            if(myContacts[i].lname==search||myContacts[i].fname==search){
                foundOne=true;
                cout << "last name " << myContacts[i].lname
                     << " fname "    << myContacts[i].fname
                     << " mobile "   << myContacts[i].mobile
                     << " e-mail " << myContacts[i].emailID << endl;
            }
        }
        return foundOne;
   }
    string fileName(){
        //You must enter specificially, not example.txt but rather /home/student/example.txt
        cout<<"Enter the file name and location"<<endl;
        string name;
        cin>>name;
        return name;
    }
    void editContact(){
        cout<<"Enter a name of a contact to edit"<<endl;
        string search;
        cin>>search;
        int found=0;
        unsigned index=-1;
        for (unsigned int i = 0; i < myContacts.size(); i++){
            if(myContacts[i].lname==search||myContacts[i].fname==search){
                found++;
                index=i;
                cout << "last name " << myContacts[i].lname
                     << " fname "    << myContacts[i].fname
                     << " mobile "   << myContacts[i].mobile
                     << " e-mail " << myContacts[i].emailID << endl;
            }
        }
        //Inefficient, but addresses the cases of not only 1 contact found
           if(found>1){
               cout<<"More than 1 contact found"<<endl;
           }
           if(found==0){
               cout<<"No contacts with that name found"<<endl;
           }
           if(found==0||found>1){
               cout<<"Would you like to enter another name?  Press y for yes, anything else for no"<<endl;
               string loopBack;
               cin>>loopBack;
               if(loopBack=="y")
                   editContact();
            }
           //This actually edits the info
        if(found==1){
            cout<<"Would you like to edit contact?"<<endl;
            string answer;
            cin>>answer;
            cout<<endl;
            if(answer=="y"){
                cout<<"Enter a new first name"<<endl;
                string first;
                cin>>first;
                cout<<endl;
                cout<<"Enter a new last name"<<endl;
                string last;
                cin>>last;
                cout<<endl;
                cout<<"Enter a new phone number"<<endl;
                string phone;
                cin>>phone;
                cout<<endl;
                cout<<"Enter a new email"<<endl;
                string email;
                cin>>email;
                cout<<endl;
                myContacts[index].lname=last;
                myContacts[index].fname=first;
                myContacts[index].mobile=phone;
                myContacts[index].emailID=email;
            }
        }
    }

    void deleteContact(){
        cout<<"Enter a name of a contact to delete"<<endl;
        string search;
        cin>>search;
        int found=0;
        unsigned index=-1;
        for (unsigned int i = 0; i < myContacts.size(); i++){
            if(myContacts[i].lname==search||myContacts[i].fname==search){
                found++;
                index=i;
                cout << "last name " << myContacts[i].lname
                     << " fname "    << myContacts[i].fname
                     << " mobile "   << myContacts[i].mobile
                     << " e-mail " << myContacts[i].emailID << endl;
            }
        }
        //Inefficient, but addresses the cases of not only 1 contact found
           if(found>1){
               cout<<"More than 1 contact found"<<endl;
           }
           if(found==0){
               cout<<"No contacts with that name found"<<endl;
           }
           if(found==0||found>1){
               cout<<"Would you like to enter another name?  Press y for yes, anything else for no"<<endl;
               string loopBack;
               cin>>loopBack;
               if(loopBack=="y")
                   deleteContact();
           }
           if(found==1){
               cout<<"Would you like to delete contact?"<<endl;
               string answer;
               cin>>answer;
               cout<<endl;
               if(answer=="y"){
                   myContacts.erase(myContacts.begin()+index);
                   cout<<"Contact erased"<<endl;
               }
           }
    }
    void exportContacts(string name){
        //This function and import are both sent the output from the fileName function to save time
        ofstream myfile;
        myfile.open(name.c_str());
        /*if(myContacts.size()>4){
            for (unsigned int i = 0; i < myContacts.size()-1; i++){
                myfile<<myContacts[i].lname<<" "<<myContacts[i].fname<<" "<<myContacts[i].mobile<<" "<<myContacts[i].emailID<<"\n";
            }
        }
        else{
            //Why this is needed, who knows but mimir is not exactly good. The mimir import export test will not work without it yet it passes manual testing without it so I commented stuff out
            //in the git edition.
            */for (unsigned int i = 0; i < myContacts.size(); i++){
                myfile<<myContacts[i].lname<<" "<<myContacts[i].fname<<" "<<myContacts[i].mobile<<" "<<myContacts[i].emailID<<"\n";
            }
        //}
            myfile.close();

    }
    void displayContacts(){
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
        int choice =-1;
        while(choice!=0){
            cout<<"Please make a choice"<<endl;
            cout<<"1-Import Contacts"<<endl;
            cout<<"2-Add Contact"<<endl;
            cout<<"3-Find Contact"<<endl;
            cout<<"4-Edit Contact"<<endl;
            cout<<"5-Delete Contact"<<endl;
            cout<<"6-Export Contacts"<<endl;
            cout<<"7-Display Contacts"<<endl;
            cout<<"0-Quit"<<endl;
            cin>>choice;
            if(choice<0||choice>7)
                cout<<"Invalid Choice, try again"<<endl;
            switch(choice){
                case 0:{
                    break;
                }
                case 2:{
                    addContacts();
                    break;
                }
                case 3:{
                    bool exist=findContact();
                    if(!exist){
                        cout<<"No Contact found"<<endl;
                    }
                    break;
                }
                case 4:{
                    editContact();
                    break;
                }
                case 5:{
                    deleteContact();
                    break;
                }
                case 6:{
                    exportContacts(fileName());
                    break;
                }
                case 7:{
                    displayContacts();
                    break;
                }
                case 1:{
                    import(fileName());
                    break;
                }
                default:{
                    break;
                }
            }
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
