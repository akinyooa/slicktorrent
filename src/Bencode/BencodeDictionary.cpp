#include "BencodeDictionary.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::map;
using std::shared_ptr;
using std::string;

std::pair<std::map<BencodeString, shared_ptr<BencodeValue> >::iterator, bool> BencodeDictionary::AddEntry(const BencodeString &key, const shared_ptr<BencodeValue> &bencodeValue) {
    return _dictionary.insert(std::pair<BencodeString, shared_ptr<BencodeValue> >(key, bencodeValue));
}

void BencodeDictionary::print(std::ostream &os) const {
    for (map<BencodeString, shared_ptr<BencodeValue> >::const_iterator it = _dictionary.begin(); it != _dictionary.end(); it++) {
        os << "key: " << it->first.GetTextValue() << " value: { " << *(it->second) << "} " << endl;
    }
}