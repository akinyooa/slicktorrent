#pragma once
#include "BencodeValue.h"

class BencodeString : public BencodeValue
{
  private:
    std::string _textValue;

  public:   
    void DecodeInternal(const char** encodedString);
    std::string GetTextValue() { return _textValue; }
    void SetTextValue(std::string value) { _textValue = value; }
    BencodeString& operator +=(const std::string value) 
    { 
        _textValue += value;
        return *this;
    }
};