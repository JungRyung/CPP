#include <iostream>
#include <string>
using namespace std;

void convertToASCII(string letter)
{
    for (int i = 0; i < letter.length(); i++)
    {
        char x = letter.at(i);
        cout << int(x) << endl;
    }
}

int main()
{
    string plainText;
    cout << "Enter text to convert to ASCII: ";
    getline(cin, plainText);
    convertToASCII(plainText);
    return 0;
}