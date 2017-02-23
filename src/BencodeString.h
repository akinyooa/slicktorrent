#pragma once
#include "BencodeValue.h"

class BencodeString : public BencodeValue
{
  private:
    std::string _textValue;

  public:
    BencodeValueType GetType() const { return BENCODESTRING; }
    void DecodeInternal(std::string& encodedString);
    std::string GetTextValue() { return _textValue; }
};