#include <string>
#include <iostream>
#include "BencodeDictionary.h"

using std::string;
using std::cout;
using std::endl;
using std::map;

void BencodeDictionary::DecodeInternal(const char** encodedString)
{
    string lengthString;
    int length = 0;
    bool canFinish = false;
    string key;
    BencodeValue value;
    string hello;

    if (**encodedString != 'd')
    {
        throw std::runtime_error("Expected a dictionary entry");
    }

    **encodedString++;
    while (!canFinish && **encodedString != 'e')
    {
        if (length == 0)
        {
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

            for (int i = 0; i < length; i++)
            {
                key += **encodedString;
                *encodedString++;
            }

            length = 0;
            value = value.Decode(encodedString);

            if (key.size() > 0)
            {
                std::pair<std::map<string, BencodeValue>::iterator, bool> res = GetDictionary().insert({key, value});
                if (!res.second)
                {
                    cout << "key " << key << " already exists " << " with value " << endl;
                }
                else
                {
                    cout << "created key " << key << " with value " << endl;
                }
            }
        }
        *encodedString++;
    }
}