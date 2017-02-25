#pragma once
enum BencodeValueType
{
    BENCODEVALUE,
    BENCODEINTEGER,
    BENCODESTRING,
    BENCODEDICTIONARY,
    BENCODELIST
};

/**
    CS-11 Asn 2
    BencodeValue.h
    Purpose: Decode bittorrent string.

    @author Ade Akinyooye
    @version 1.0 29/10/16 
*/
class BencodeValue
{
  public:
    /**
    Returns the decoded bittorrent string.

    @param encodedString The encoded string to decode.
    @return the decoded bittorrent string.
    */
    static std::shared_ptr<BencodeValue> Decode(std::string &encodedString);

    virtual BencodeValueType GetType() const { return BENCODEVALUE; }

    virtual void DecodeInternal(std::string &encodedString){};

    virtual void print(std::ostream &os) const {};

    friend std::ostream &operator<<(std::ostream &os, BencodeValue &bencodeValue)
    {
        bencodeValue.print(os);
        return os;
    }

    virtual std::string GetTypeString()
    {
        switch (GetType())
        {
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

  protected:
    virtual int getLength(std::string &encodedString);
    virtual void removeFirstCharacter(std::string &encodedString);
};