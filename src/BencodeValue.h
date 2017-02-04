#pragma once
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
    BencodeValue Decode(std::string& encodedString);

    virtual void DecodeInternal(std::string& encodedString) { };
  
  private:
    /**
    Decode dictionary bittorent string.

    @param encodedDictionary The encoded dictionary string to decode.
    */
    void decodeDictionary(char& encodedDictionary);

    /**
    Decode dictionary bittorent string.

    @param encodedString The encoded string to decode.
    */
    void decodeString(char& encodedString);

    /**
    Decode dictionary bittorent string.

    @param encodedList The encoded list string to decode.
    */
    void decodeList(char *encodedList);

    /**
    Decode dictionary bittorent string.

    @param encodedNumber The encoded number string to decode.
    */
    void decodeNumber(char *encodedNumber);
};