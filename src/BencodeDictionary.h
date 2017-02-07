#pragma once
#include "BencodeValue.h"
#include <map>

/**
    CS-11 Asn 2
    BencodeValue.h
    Purpose: Decode bittorrent string.

    @author Ade Akinyooye
    @version 1.0 29/10/16 
*/
class BencodeDictionary : public BencodeValue
{
  private:
    std::map<std::string, BencodeValueSp> _dictionary;

  public:   
    BencodeValueType GetType() const { return BENCODEDICTIONARY; }
    void DecodeInternal(std::string& encodedString);
    std::map<std::string, BencodeValueSp> GetDictionary() { return _dictionary; }
};