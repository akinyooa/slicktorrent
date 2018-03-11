#pragma once
#include "BencodeValue.h"
#include <vector>

class BencodeList : public BencodeValue
{
  private:
    std::vector<std::shared_ptr<BencodeValue>> _list;

  public:   
    BencodeValueType GetType() const { return BENCODELIST; }
    void DecodeInternal(std::string& encodedString);
    std::vector<std::shared_ptr<BencodeValue>> GetList() const { return _list; }
    void AddBencodeValue(const std::shared_ptr<BencodeValue>& bencodeValue);
};