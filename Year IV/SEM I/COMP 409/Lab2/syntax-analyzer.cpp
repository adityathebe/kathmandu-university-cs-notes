/* Check if a given input string is a valid C++ identifier 
  Dec 5, 2018
*/

#include <iostream>
#include <fstream>
#include <regex>
#include <string>

using namespace std;

int isValidIdentifier(string identifier) {
  return regex_match(identifier, regex("[_a-zA-Z][_a-zA-Z0-9]{0,30}"));
}

int main() {
  // Read Identifier
  string input;
  cout << "Identifier :: " ;
  cin >> input;

  // Read keywords file
  string file_name = "keywords.txt";
  ifstream file;
  file.open(file_name);

  // Check if input is a keyword
  string keyword;
  while (getline(file, keyword)) {
    if ( keyword == input) {
      cout << "It is a keyword" << endl;
      return 0;
    }
  }

  // Check if input is a valid identifier
  bool is_valid = isValidIdentifier(input);
  if (is_valid) {
    cout << "Valid identifier" << endl;
    return 1;
  }

  cout << "Invalid identifier" << endl;
  return 0;
}
