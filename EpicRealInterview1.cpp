

/*
print all well-formed strings of length l
*/
#include <iostream>
#include <string>
#include <sstream>
#include <set>

#include <iterator>

const std::string characters = "abcdefghijklmnopqrstuvwxyz";


void printStrings(std::set<std::string> &allStrings) {

  using namespace std;
  set<string>::iterator itr = allStrings.begin();

  while( itr != allStrings.end() )
  {
    cout << *itr << endl;
    itr++;
  }

}

void addAddtionalStrings(std::string &theCharacter, std::set<std::string> &additionalStrings, std::string existingString) {

  using namespace std;

  stringstream s;

  cout << "existing String:" << existingString << endl;
  cout << "theCharacter: " << theCharacter << endl;
  
  //for (int i = 0; i < existingString.size(); i++) {
  int i = 0;
    s << theCharacter;
    s << existingString.substr(0, i);
    s << existingString.substr(i+1, existingString.size());

    cout << "Adding: " << s.str() << endl;
    additionalStrings.insert(s.str());
  //}
  
}

void evaluateStrings(int size) {

  if (size == 0)
    return;

  using namespace std;

  set<string> allStrings;

  int charSetSize = characters.size();

  string string1 = characters.substr(charSetSize-size, size);

  allStrings.insert(string1);

  set<string> additionalStrings;
  set<string>::iterator itr;

  for (int i = charSetSize - size - 1; i >=0 ; i--)
  {
    string theCharacter = characters.substr(i, 1);

    additionalStrings.clear();
    itr = allStrings.begin();

    while( itr != allStrings.end() )
    {
      addAddtionalStrings(theCharacter, additionalStrings, *itr);
      itr++;
    }

    allStrings.insert( additionalStrings.begin(), additionalStrings.end() );
  }

  printStrings(allStrings);
}



int main(int argc, char *argv[])
{
  using namespace std;
  int size = 0;


  if (argc < 2 )
  {  
    cout << "Please pass the size of the string: ";
    cin >> size;
  }
  else
  {
    string sizeString = argv[1];
    int size = atoi(sizeString.c_str()); 
  }
  evaluateStrings(size);
  
  return 0;

}

