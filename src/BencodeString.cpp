#include <string>
#include <iostream>
#include "BencodeString.h"

using std::string;
using std::cout;
using std::endl;

void BencodeString::DecodeInternal(std::string& encodedString)
{
    int length = 0;
    length = getLength(encodedString);

    for(int i = 0; i < length; ++i)
    {
        _textValue += encodedString[0];
        removeFirstCharacter(encodedString);
    }
}