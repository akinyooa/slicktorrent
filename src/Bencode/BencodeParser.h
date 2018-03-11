#ifndef BENCODE_BENCODEPARSER_H
#define BENCODE_BENCODEPARSER_H

#include "BencodeDictionary.h"
#include "BencodeInteger.h"
#include "BencodeList.h"
#include "BencodeParser.h"
#include "BencodeString.h"
#include "BencodeValue.h"
#include <string>

class BencodeParser {
  public:
    BencodeParser();

    std::shared_ptr<BencodeValue> decode(std::string &encodedString);
    std::shared_ptr<BencodeDictionary> decodeDictionary(std::string &encodedString);
    std::shared_ptr<BencodeInteger> decodeInteger(std::string &encodedString);
    std::shared_ptr<BencodeList> decodeList(std::string &encodedString);
    std::shared_ptr<BencodeString> decodeString(std::string &encodedString);
    int getLength(std::string &encodedString);
    void removeFirstCharacter(std::string &encodedString);

  private:
    int _currentIndex;
    void updateCurrentIndex(int value);
};

#endif // !BENCODE_BENCODEPARSER_H