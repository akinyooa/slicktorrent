#pragma once
#include "BencodeValue.h"

class BencodeInteger : public BencodeValue
{
private:
  int _intValue;

public:
  BencodeValueType GetType() const { return BENCODEINTEGER; }
  void DecodeInternal(std::string &encodedString);
  int GetIntValue() const { return _intValue; }
  void SetIntValue(int value) { _intValue = value; }

  void print(std::ostream &os) const
  {
    os << std::to_string(GetIntValue()).size() << ":" << GetIntValue();
  }
};