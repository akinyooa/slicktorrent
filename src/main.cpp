#include "Bencode/BencodeValue.h"
#include "Bencode/BencodeParser.h"
#include "sys/socket.h"
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <map>

using std::shared_ptr;

int main(int argc, char *argv[]) {
    std::string fileName = "puppy.torrent";

    if (argc > 1) {
        fileName = argv[1];
    }
    std::ifstream file(fileName);
    std::string content;

    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();

    content = buffer.str();

    //std::cout << content << std::endl;
    BencodeParser bencoderParser;
    shared_ptr<BencodeValue>  bencodeValue = bencoderParser.decode(content);

    std::cout << "Finished parsing!" << std::endl;
    std::shared_ptr<BencodeDictionary> dictionary = std::dynamic_pointer_cast<BencodeDictionary>(bencodeValue);
    std::map<BencodeString, std::shared_ptr<BencodeValue> > mymap = dictionary->GetDictionary();
    std::map<BencodeString, std::shared_ptr<BencodeValue> >::const_iterator findValue = mymap.find("announce");

    if (findValue == mymap.end())
        std::cout << "Not found" << std::endl;
    else
        std::cout << *(findValue->second) << std::endl;

    //std::cout << *bencodeValue << std::endl;
    return 0;
}