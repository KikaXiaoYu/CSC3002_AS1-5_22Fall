/* Q3
 * File: MorseCode.cpp
 * -------------------
 * This program translates to and from Morse Code using maps to
 * assist in the translation.
 */

#include <iostream>
#include <string>
#include <map>
#include "csc300222fall/assignment2/lib.h" 
#include "csc300222fall/assignment2/morsecode.h" 
using namespace std;


/*
 * TODO function
 * Function: translateLettersToMorse
 * Usage: string morse = translateLettersToMorse(line);
 * ----------------------------------------------------
 * Translates a string of letters into Morse Code characters separated
 * by spaces.  Characters that don't appear in the table are simply ignored.
 */

string translateLettersToMorse(string line) {
   // TODO
   map<string,string> map1 = createMorseCodeMap();
   string res;
   map<string,string>::iterator idx;
   for (int i = 0; i < line.length(); i++) {
      idx = map1.find(line.substr(i, 1));
      if (idx != map1.end()) {
         if (i != 0) {
            res += " ";
         }
         res += map1.at(line.substr(i, 1));
      }
   }
   return res;
}

/*
 * TODO function
 * Function: translateMorseToLetters
 * Usage: string letters = translateLettersToMorse(line);
 * ------------------------------------------------------
 * Translates a string in Morse Code into English letters.
 * Because word breaks are not represented in Morse code, the
 * letters in the output will be run together.  The characters
 * of the Morse Code input must be separated by a single space.
 * Any other character in the input is simply ignored.  If there
 * is no English equivalent for the Morse Code character, this
 * function indicates that fact by inserting a question mark (?).
 *
 * Implementation note: To eliminate the special case of the last
 * character in the line, this function begins by adding a space
 * to the end of the input string.
 */

string translateMorseToLetters(string line) {
   // TODO
   map<string,string> map2 = invertMap(createMorseCodeMap());
   int start = 0;
   map<string,string>::iterator idx;
   string res;
   string new_code;
   line += " ";
   for (int i = 0; i <= line.length(); i++) {
      if (line.substr(i, 1) == " " && new_code != "") {
         idx = map2.find(new_code);
         if (idx != map2.end()) {
            res += map2.at(new_code);
         } else {
            res += "?";
         }
         start = i+1;
         new_code = "";
      } else {
         if (line.substr(i, 1) == "-" 
           || line.substr(i, 1) == "." ) {
            new_code += line.substr(i, 1);
           }
      }
   }
   return res;
}

/*
 * Function: createMorseCodeMap
 * Usage: map<string> map = createMorseCodeMap();
 * ----------------------------------------------
 * Returns a map in which each uppercase letter is mapped into its
 * Morse code equivalent.
 */

map<string,string> createMorseCodeMap() {
   map<string,string> map;
   map["A"] = ".-";
   map["B"] = "-...";
   map["C"] = "-.-.";
   map["D"] = "-..";
   map["E"] = ".";
   map["F"] = "..-.";
   map["G"] = "--.";
   map["H"] = "....";
   map["I"] = "..";
   map["J"] = ".---";
   map["K"] = "-.-";
   map["L"] = ".-..";
   map["M"] = "--";
   map["N"] = "-.";
   map["O"] = "---";
   map["P"] = ".--.";
   map["Q"] = "--.-";
   map["R"] = ".-.";
   map["S"] = "...";
   map["T"] = "-";
   map["U"] = "..-";
   map["V"] = "...-";
   map["W"] = ".--";
   map["X"] = "-..-";
   map["Y"] = "-.--";
   map["Z"] = "--..";
   return map;
}

/*
 * TODO function
 * Function: invertMap
 * Usage: map<string> inverse = invertMap(map);
 * --------------------------------------------
 * Creates an inverted copy of the specified map in which the values
 * in the original become the keys of the new map and refer back to
 * their associated keys.  Thus, if "abc" is bound to "xyz" in the
 * original map, the inverted map will bind "xyz" to "abc".  If two
 * keys in the original map have the same value, this function will
 * signal an error condition.
 */

map<string,string> invertMap(const map<string,string> & m) {
   // // TODO
   map<string,string> org_map = createMorseCodeMap();
   map<string,string> res_map;
   for (map<string,string>::iterator i = org_map.begin(); i != org_map.end(); i++) {
      res_map[i->second] = i->first;
   }
   return res_map;

}

int main() {
    /* A sample translator:
     *                     > SOS
     *                     ... --- ...
     *                     > ... --- ...
     *                     SOS
     */
    string line;
    
    while (getline(cin, line) && line.length() > 0) {
       line = toUpperCase(line);
       if (line[0] == '.' || line[0] == '-') {
           cout << translateMorseToLetters(line) << endl;
       } else {
           cout << translateLettersToMorse(line) << endl;
       }
    }
    return 0;
   
}

