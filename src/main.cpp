#include "Bencode/BencodeValue.h"
#include "Bencode/BencodeParser.h"
#include "sys/socket.h"
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>

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

    std::cout << content << std::endl;
    BencodeParser bencoderParser;
    shared_ptr<BencodeValue>  bencodeValue = bencoderParser.decode(content);

    //std::string announce = bencodeValue->GetDictionary().find("announce")->right;
    std::cout << "Finished parsing!" << std::endl;

    return 0;
}