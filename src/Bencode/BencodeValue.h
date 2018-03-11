#ifndef BENCODE_BENCODEVALUE_H
#define BENCODE_BENCODEVALUE_H

#include <string>

enum BencodeValueType {
    BENCODEVALUE,
    BENCODEINTEGER,
    BENCODESTRING,
    BENCODEDICTIONARY,
    BENCODELIST
};

/**
    CS-11 Asn 2
    BencodeValue.h
    Purpose: Store bitorrent bencoded data.

    @author Ade Akinyooye
    @version 1.0 29/10/16
*/
class BencodeValue {
  public:
    virtual BencodeValueType GetType() const { return BENCODEVALUE; }

    virtual void print(std::ostream &os) const {};

    friend std::ostream &operator<<(std::ostream &os, BencodeValue &bencodeValue) {
        bencodeValue.print(os);
        return os;
    }

    virtual std::string GetTypeString() {
        switch (GetType()) {
        case BENCODEVALUE:
            return "BencodeValue";
        case BENCODEINTEGER:
            return "BencodeInteger";
        case BENCODESTRING:
            return "BencodeString";
        case BENCODEDICTIONARY:
            return "BencodeDictionary";
        case BENCODELIST:
            return "BencodeList";
        default:
            return "Not found";
        }
    }
};

#endif // !BENCODE_BENCODEVALUE_H
