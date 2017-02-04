#include <string>
#include <iostream>
#include "BencodeValue.h"
#include "BencodeDictionary.h"
#include "BencodeString.h"

using std::string;
using std::cout;
using std::endl;

BencodeValue BencodeValue::Decode(std::string& encodedString)
{
    cout << encodedString << endl;

    BencodeValue bencodeValue;

    switch (encodedString[0])
    {
    case ('i'):
        {
            cout << "integer" << endl;
            break;
        }
    case ('d'):
        {
            cout << "dictionary" << endl;        
            BencodeDictionary bencodeDict;
            bencodeDict.DecodeInternal(encodedString);
            bencodeValue = bencodeDict;
            return bencodeValue;
            break;
        }
    case ('1'):
    case ('2'):
    case ('3'):
    case ('4'):
    case ('5'):
    case ('6'):
    case ('7'):
    case ('8'):
    case ('9'):
    case ('0'):
        {
            cout << "found string value" << endl;
            BencodeString bstring;
            bstring.DecodeInternal(encodedString);
            bencodeValue = bstring;
            return bstring;
            break;
        }
    default:
        cout << "Unsupported value";
    }

    return bencodeValue;
}