#include <string>
#include <iostream>
#include "BencodeString.h"

using std::string;
using std::cout;
using std::endl;

void BencodeString::DecodeInternal(const char** encodedString)
{
    int length = 0;
    string lengthString;

    while (**encodedString != ':')
    {
        lengthString += **encodedString;
        *encodedString++;
    }

    if (lengthString.size() > 0)
    {
        length = std::stoi(lengthString);
        lengthString = "";
        *encodedString++;
    }

    for(int i = 0; i < length; i++)
    {
        _textValue += **encodedString;
        *encodedString++;
    }
}