/*
 * File: BanishLetters.cpp
 * -----------------------
 * This program removes all instances of a set of letters from
 * an input file.
 */

#include <iostream>
#include "csc300222fall/assignment1/lib.h" //for local version
using namespace std;


int banishLetters() {
    string letters;
    getline(cin, letters);
    string line;
    while (getline(cin, line)){
      for (int i = 0; i < line.length(); i++){
        bool result = true;
        for (int j = 0; j < letters.length(); j++){
          if (tolower(letters[j]) ==line[i] or toupper(letters[j]) == line[i]){
            result = false;
            break;
          }
        }
        if (result == true){
          cout << line[i];
        }
      }
      cout << endl;
    }
    return 0;
}


/* DO NOT modify this main() part */
/*
 sample output:
 input: S
        this is a testing 1
        this is a testing 2
 output:
        thi i a teting 1
        thi i a teting 2
*/
int main(int argc, char* argv[]) {
    banishLetters();
    return 0;
}
