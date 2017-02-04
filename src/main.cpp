#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <memory>
#include "BencodeValue.h"

int main(int argc, char *argv[])
{
    std::ifstream file("puppy.torrent");
    std::string content;

    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();

    content = buffer.str();
    BencodeValue bencode;

    //const char* cont = content.c_str();
    //std::shared_ptr encodedContent = std:make_shared<std:string>(content);
    bencode.Decode(content);

    return 0;
}