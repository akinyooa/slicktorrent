#ifndef BENCODE_BENCODEDICTIONARY_H
#define BENCODE_BENCODEDICTIONARY_H

#include "BencodeString.h"
#include "BencodeValue.h"
#include <map>

/**
    CS-11 Asn 2
    BencodeValue.h
    Purpose: Decode bittorrent string.

    @author Ade Akinyooye
    @version 1.0 29/10/16 
*/
class BencodeDictionary : public BencodeValue {
  private:
    std::map<BencodeString, std::shared_ptr<BencodeValue> > _dictionary;

  public:
    BencodeValueType GetType() const { return BENCODEDICTIONARY; }
    std::map<BencodeString, std::shared_ptr<BencodeValue> > GetDictionary() { return _dictionary; }
    std::pair<std::map<BencodeString, std::shared_ptr<BencodeValue> >::iterator, bool> AddEntry(const BencodeString &key, const std::shared_ptr<BencodeValue> &bencodeValue);
};

#endif  // !BENCODE_BENCODEDICTIONARY_H