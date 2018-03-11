#include <string>
#include <iostream>
#include "BencodeList.h"

using std::string;
using std::cout;
using std::endl;
using std::vector;

void BencodeList::AddBencodeValue(const std::shared_ptr<BencodeValue> &bencodeValue)
{
    _list.push_back(bencodeValue);
}