#include <string>
#include <iostream>
#include "BencodeValue.h"
#include "BencodeDictionary.h"
#include "BencodeString.h"
#include "BencodeInteger.h"
#include "BencodeList.h"

using std::string;
using std::cout;
using std::endl;

std::shared_ptr<BencodeValue> BencodeValue::Decode(std::string &encodedString)
{
    BencodeValue bencodeValue;

    switch (encodedString[0])
    {
    case ('i'):
    {
        cout << "integer" << endl;
        std::shared_ptr<BencodeValue> bencodeInteger = std::make_shared<BencodeInteger>();
        bencodeInteger->DecodeInternal(encodedString);
        return bencodeInteger;
    }
    case ('d'):
    {
        cout << "dictionary" << endl;
        std::shared_ptr<BencodeValue> bencodeDict  = std::make_shared<BencodeDictionary>();
        bencodeDict->DecodeInternal(encodedString);
        return bencodeDict;
    }
    case ('l'):
    {
        cout << "list" << endl;
        std::shared_ptr<BencodeValue> bencodeList  = std::make_shared<BencodeList>();
        bencodeList->DecodeInternal(encodedString);
        return bencodeList;
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
        std::shared_ptr<BencodeValue> bstring = std::make_shared<BencodeString>();
        bstring->DecodeInternal(encodedString);
        return bstring;
    }
    default:
        cout << "Unsupported value";
    }

    return nullptr;
}

int BencodeValue::getLength(string &encodedString)
{
    string lengthString;
    int length = 0;

    for (int i = 0; encodedString[i] != ':'; i++)
    {
        lengthString += encodedString[i];
    }

    if (lengthString.size() > 0)
    {
        length = std::stoi(lengthString);
    }

    for (int i = 0; i <= lengthString.size(); i++)
    {
        removeFirstCharacter(encodedString);
    }

    return length;
}

void BencodeValue::removeFirstCharacter(std::string &encodedString)
{
    encodedString = encodedString.substr(1).append(encodedString.substr(0, 1));
}