
#include <iostream>

#include <stdint.h>

#include <stdio.h>

#include <faio/faio.h>

int main(int argc, char** argv)
{
    if (argc != 3)
    {
        std::cout << "The Freeablo MPQ tool accepts two parameters: " << std::endl;
        std::cout << argv[0] << " <path to file in MPQ> <output file on file system>" << std::endl;
        std::cout << "The tool extracts the specified file within the Diablo MPQ file and extracts it to ";
        std::cout << "the output file as requested." << std::endl;
        return 1;
    }

    FAIO::init();

    FAIO::FAFile* file = FAIO::FAfopen(argv[1]);
    FILE* output = fopen(argv[2], "w");

    int read = 1;
    uint8_t buffer[1024];

    while(read > 0)
    {
        read = FAIO::FAfread(buffer, 1, sizeof(buffer), file);
        fwrite(buffer, 1, read, output);
    }

    fclose(output);

    FAIO::quit();
    return 0;
}