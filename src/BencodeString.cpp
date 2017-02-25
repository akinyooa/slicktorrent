#include <string>
#include <iostream>
#include "BencodeString.h"

using std::string;
using std::cout;
using std::endl;

void BencodeString::DecodeInternal(string &encodedString)
{
    int length = 0;
    length = getLength(encodedString);
    _textValue = encodedString.substr(0, length);
    encodedString = encodedString.substr(length);
}