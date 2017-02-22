#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <memory>
#include "BencodeValue.h"
#include "sys/socket.h"

int main(int argc, char *argv[])
{
    std::ifstream file("puppy.torrent");
    std::string content;

    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();

    content = buffer.str();

    std::cout << content << std::endl;
    BencodeValue::Decode(content);

    std::cout << "Finished parsing!" << std::endl;

    return 0;
}