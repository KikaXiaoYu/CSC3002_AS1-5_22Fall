/*
 * File: RemoveComments.cpp
 * ------------------------
 * Prints out a file after removing comments.
 */
// header file for local test
#include <iostream>
#include <iomanip>
#include "csc300222fall/assignment1/RemoveComments.h" //for OJ
using namespace std;

#pragma GCC diagnostic ignored "-Wcomment"
/*
 * Function: removeComments
 * Usage: removeComments(is, os);
 * ------------------------------
 * Copies characters from the input stream is to the output stream os,
 * removing any comments it finds.  This program eliminates both the
 * /* and // comment forms but does not check to see if those characters
 * are embedded within strings.
 */

void removeComments(istream & is, ostream & os) {
   //TODO
    string line;
    bool char_ign = false;
    while (getline(is, line)){
        for (unsigned int i = 0; i < line.length(); i++){

            if ( (line.substr(i,2) == "//" ) 
               && (char_ign == false)  ){
                break;

            } else if ( (line.substr(i,2) == "/*") 
                      && (char_ign == false) ){
                char_ign = true;
                i++;

            } else if ( (line.substr(i,2) == "*/") 
                      && (char_ign == true) ){
                char_ign = false;
                i++;

            } else if ( char_ign == false){
                os << line[i];
                }
        }
        if ( char_ign == false){
            os << endl;
        }
    }
}

void TestRemoveComments(){
    removeComments(cin, cout);
}

// DO NOT modify the main() function
/*
 * sample output format:
 * input:  test file // this is a comment
           test file /* this is also a comment*/
/* output: test file
           test file
 */
int main(int argc, char* argv[]) {
    TestRemoveComments();
    return 0;
}
