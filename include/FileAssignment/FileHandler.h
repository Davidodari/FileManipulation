//
// Created by blackcoder on 22/04/19.
//

#ifndef FILEASSIGNMENT_FILESIZEHANDLER_H
#define FILEASSIGNMENT_FILESIZEHANDLER_H

#include <string>


class FileHandler {
public:
    void getFileSize(std::string);

    int getBlankSpaces(std::string);

    void getCharacterFrequency(std::string);

    void getWordsBeginningWithVowels(std::string);

    int getLineCount(std::string);

    void createDuplicateFileWithLowercaseVowel(std::string);

    bool isVowels(std::string);


};


#endif //FILEASSIGNMENT_FILESIZEHANDLER_H
