#include <string>
#include <iostream>
#include "BencodeList.h"

using std::string;
using std::cout;
using std::endl;
using std::vector;

void BencodeList::DecodeInternal(std::string &encodedString)
{
    if (encodedString[0] != 'l')
    {
        throw std::runtime_error("Expected a list entry");
    }

    removeFirstCharacter(encodedString);

    for (int i = 0; encodedString[0] != 'e'; ++i)
    {
        auto value = BencodeValue::Decode(encodedString);
        AddBencodeValue(value);
        cout << "Added to list: " << *value << endl;
    }
    cout << "List size is " << GetList().size() << endl;
    removeFirstCharacter(encodedString);
}

void BencodeList::AddBencodeValue(const std::shared_ptr<BencodeValue> &bencodeValue)
{
    _list.push_back(bencodeValue);
}