#pragma once
#include "BencodeValue.h"

class BencodeString : public BencodeValue
{
private:
  std::string _textValue;

public:
  BencodeValueType GetType() const { return BENCODESTRING; }

  void DecodeInternal(std::string &encodedString);

  std::string GetTextValue() const { return _textValue; }

  int size() { return _textValue.size(); }

  void print(std::ostream &os) const
  {
    os << GetTextValue().size() << ":" << GetTextValue();
  }

  BencodeString &operator+=(const char *value)
  {
    _textValue += value;
    return *this;
  }

  BencodeString &operator+=(char value)
  {
    _textValue += value;
    return *this;
  }

  bool operator<(const BencodeString &rhs)
  {
    return _textValue < rhs.GetTextValue();
  }

  friend bool operator<(const BencodeString &lhs, const BencodeString &rhs)
  {
    return lhs.GetTextValue() < rhs.GetTextValue();
  }
};