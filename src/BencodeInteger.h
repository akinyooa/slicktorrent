#pragma once
#include "BencodeValue.h"

class BencodeInteger : public BencodeValue
{
  private:
    int _intValue;

  public:   
    void DecodeInternal(std::string& encodedString);
    int GetIntValue() { return _intValue; }
    void SetIntValue(int value) { _intValue = value; }
    BencodeInteger& operator +=(const int value) 
    { 
        _intValue += value;
        return *this;
    }
};