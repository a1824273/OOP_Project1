#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
  string input;
  vector<string> command;
  cout << "Input Command" << endl;
  system("make test");
  getline(cin, input);

  istringstream ss(input);
  string del;

  while(getline(ss, del, ' '))
  {
      command.push_back(del);
  }


  vector<string>::iterator itr = command.begin();

  //cout << command.size();

  for (size_t i = 0; i < command.size(); i++) {
    cout << command[i] << endl;
  }
}
