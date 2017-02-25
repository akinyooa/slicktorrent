#include <string>
#include <iostream>
#include "BencodeDictionary.h"

using std::string;
using std::cout;
using std::endl;
using std::map;
using std::shared_ptr;

void BencodeDictionary::DecodeInternal(std::string &encodedString)
{
    int length = 0;

    if (encodedString[0] != 'd')
    {
        throw std::runtime_error("Expected a dictionary entry");
    }

    removeFirstCharacter(encodedString);

    for (int i = 0; encodedString[0] != 'e'; ++i)
    {
        BencodeString key;
        if (length == 0)
        {
            length = getLength(encodedString);

            for (int i = 0; i < length; ++i)
            {
                key += encodedString[0];
                removeFirstCharacter(encodedString);
            }

            length = 0;
            auto value = BencodeValue::Decode(encodedString);

            if (key.size() > 0)
            {
                std::pair<std::map<BencodeString, shared_ptr<BencodeValue>>::iterator, bool> res = AddEntry(key, value);
                if (!res.second)
                {
                    cout << "key " << key << " already exists "
                         << " with value " << *value << endl;
                }
                else
                {
                    cout << "created key " << key << " with value " << *value << endl;
                }
            }
        }
    }
    removeFirstCharacter(encodedString);
}

std::pair<std::map<BencodeString, shared_ptr<BencodeValue>>::iterator, bool> BencodeDictionary::AddEntry(const BencodeString &key, const shared_ptr<BencodeValue> &bencodeValue)
{
    return _dictionary.insert({key, bencodeValue});
}