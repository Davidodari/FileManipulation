#include <iostream>
#include "../include/FileAssignment/FileHandler.h"


int main() {
    std::string fileLocation = "../src/TEXT1.txt";

    FileHandler fileHandler;

//    File Size
    fileHandler.getFileSize(fileLocation);

// No Of Spaces
    std::cout << "The file has " << fileHandler.getBlankSpaces(fileLocation) << " Spaces." << std::endl;

// Alphabets Frequency Table
    fileHandler.getCharacterFrequency(fileLocation);

//    No of lines in file
    std::cout << fileHandler.getLineCount(fileLocation) << " Lines" << std::endl;

//  Words beginning with a vowel only
    fileHandler.getWordsBeginningWithVowels(fileLocation);

    fileHandler.createDuplicateFileWithLowercaseVowel(fileLocation);

    return 0;
}