#ifndef PHONEBOOK_TEST_H
#define PHONEBOOK_TEST_H

#include <string>
#include <vector>
#define main do_not_use_main
#include "phoneBook.cpp"
#undef main 

#include <iostream>
#include <cxxtest/TestSuite.h>

using namespace std;

// This requires CxxTest to be installed!
// For this CPPVideos example, navigate your terminal to CPPVideos and type:
// git submodule add https://github.com/CxxTest/cxxtest.git
// This will add the public CxxTest repository INSIDE the current repo.
// The current Makefile in this directory assumes cxxtest is a folder one
// level down.

// Write your test cases here.
class ImportTestCases: public CxxTest::TestSuite {
public:
    void testImport1(){
        phoneBook a;
        a.menu();
      // vector <contact> c = a.getInternalState();
       // TS_ASSERT_EQUALS(c.size(), 911);
        //TS_ASSERT_EQUALS(c[0].lname, "O'doherty");
        //TS_ASSERT_EQUALS(c[1].lname, "Rossi");
      }

};


#endif
