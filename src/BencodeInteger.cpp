#include <string>
#include <iostream>
#include "BencodeInteger.h"

using std::string;
using std::cout;
using std::endl;

void BencodeInteger::DecodeInternal(std::string& encodedString)
{
    string integerString;

    if (encodedString[0] != 'i')
    {
        throw std::runtime_error("Expected a dictionary entry");
    }

    removeFirstCharacter(encodedString);

    for (int i = 0; encodedString[0] != 'e'; i++)
    {
        integerString += encodedString[0];
        removeFirstCharacter(encodedString);
    }

    if (integerString.size() > 0)
    {
        _intValue = std::stoi(integerString);
        removeFirstCharacter(encodedString);
    }
}