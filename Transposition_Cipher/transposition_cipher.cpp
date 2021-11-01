#include <string>
#include <stdlib.h>
#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    //check args
    if (argc != 3)
    {
        std::cout << "Usage" << argv[0] << "{text to crypt} {key}" << std::endl;
        return 1;
    }
    //read args
    std::string clearText(argv[1]);
    int key = std::stoi(argv[2]);


    if (clearText.size() < key)
    {
        std::cerr << "Key cannot be grater than size of plaintext" << std::endl;
    }
    //add the end padding to make the string fit in the table
    while ((clearText.size() % key) != 0)
    {
        clearText.push_back('x');
    }
    //construct the table (this step is not necessary, but doing it is clearer)
    std::vector<std::string> chipherTable;
    for (int iRow = 0; iRow < (clearText.size() / key); iRow++)
    {
        chipherTable.push_back(clearText.substr(iRow * key, key));
    }
    //write the table by column
    for (int iCol = 0; iCol < key; iCol++)
    {
        for (int iRow = 0; iRow < chipherTable.size() ;iRow++)
        {
            std::cout <<chipherTable[iRow][iCol];
        }
    }
    std::cout <<std::endl;
    return 0;
}
