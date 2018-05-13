#include "BencodeParser.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::make_shared;
using std::shared_ptr;
using std::string;

BencodeParser::BencodeParser() : _currentIndex(0) {
}

shared_ptr<BencodeValue> BencodeParser::decode(string &encodedValue) {
    shared_ptr<BencodeValue> bencodeValue = make_shared<BencodeValue>();

    switch (encodedValue[_currentIndex]) {
    case ('i'): {
        //cout << "integer" << endl;
        return decodeInteger(encodedValue);
    }
    case ('d'): {
        //cout << "dictionary" << endl;
        return decodeDictionary(encodedValue);
    }
    case ('l'): {
        //cout << "list" << endl;
        return decodeList(encodedValue);
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
    case ('0'): {
        //cout << "found string value" << endl;
        return decodeString(encodedValue);
    }
    default:
        cout << "Unsupported value";
    }

    return bencodeValue;
}

shared_ptr<BencodeDictionary> BencodeParser::decodeDictionary(string &encodedValue) {
    shared_ptr<BencodeDictionary> bencodeDictionary = make_shared<BencodeDictionary>();

    int length = 0;

    if (encodedValue[_currentIndex] != 'd') {
        throw std::runtime_error("Expected a dictionary entry");
    }

    updateCurrentIndex(1);

    while (encodedValue[_currentIndex] != 'e') {
        BencodeString key;
        if (length == 0) {
            length = getLength(encodedValue);

            key.setTextValue(encodedValue.substr(_currentIndex, length));
            updateCurrentIndex(length);

            length = 0;
            auto value = decode(encodedValue);

            if (key.size() > 0) {
                //std::pair<std::map<BencodeString, shared_ptr<BencodeValue> >::iterator, bool> res = 
                bencodeDictionary->AddEntry(key, value);
                /*if (!res.second) {
                    cout << "key " << key << " already exists " << " with value " << *value << endl;
                } else {
                    cout << "created key " << key << " with value " << *value << endl;
                }*/
            }
        }
    }

    updateCurrentIndex(1);

    return bencodeDictionary;
}

shared_ptr<BencodeInteger> BencodeParser::decodeInteger(string &encodedValue) {
    shared_ptr<BencodeInteger> bencodeInteger = make_shared<BencodeInteger>();

    string integerString;

    if (encodedValue[_currentIndex] != 'i')
        throw std::runtime_error("Expected a dictionary entry");

    updateCurrentIndex(1);

    while (encodedValue[_currentIndex] != 'e') {
        integerString += encodedValue[_currentIndex];
        updateCurrentIndex(1);
    }

    if (integerString.size() > 0) {
        bencodeInteger->SetIntValue(std::stoi(integerString));
        updateCurrentIndex(1);
    }

    return bencodeInteger;
}

shared_ptr<BencodeList> BencodeParser::decodeList(string &encodedValue) {
    shared_ptr<BencodeList> bencodeList = make_shared<BencodeList>();
    if (encodedValue[_currentIndex] != 'l') {
        throw std::runtime_error("Expected a list entry");
    }
    updateCurrentIndex(1);

    for (int i = 0; encodedValue[_currentIndex] != 'e'; ++i) {
        shared_ptr<BencodeValue> value = decode(encodedValue);
        bencodeList->AddBencodeValue(value);
        //cout << "Added to list: " << *value << endl;
    }
    //cout << "List size is " << bencodeList->GetList().size() << endl;
    updateCurrentIndex(1);

    return bencodeList;
}

shared_ptr<BencodeString> BencodeParser::decodeString(string &encodedValue) {
    int length = 0;
    length = getLength(encodedValue);
    shared_ptr<BencodeString> bencodeString = make_shared<BencodeString>();
    bencodeString->setTextValue(encodedValue.substr(_currentIndex, length));
    updateCurrentIndex(length);
    return bencodeString;
}

int BencodeParser::getLength(string &encodedValue) {
    string lengthString;
    int length = 0;

    while (encodedValue[_currentIndex] != ':') {
        lengthString += encodedValue[_currentIndex];
        updateCurrentIndex(1);
    }

    if (lengthString.size() > 0) {
        length = std::stoi(lengthString);
    }

    updateCurrentIndex(1);
    return length;
}

void BencodeParser::updateCurrentIndex(int value) {
    _currentIndex += value;
}