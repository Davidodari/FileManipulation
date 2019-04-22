//
// Created by blackcoder on 22/04/19.
//

#include <iostream>
#include <fstream>
#include <iterator>
#include <sstream>
#include "../include/FileAssignment/FileHandler.h"

using std::string;
using std::cout;
using std::ios;
using std::ifstream;
using std::streampos;

void FileHandler::getFileSize(string file) {
    streampos begin, end;
    ifstream myfile(file, ios::binary);
    begin = myfile.tellg();
    myfile.seekg(0, ios::end);
    end = myfile.tellg();
    myfile.close();
    cout << "Size of file is: " << (end - begin) << " bytes.\n";
}

int FileHandler::getBlankSpaces(string file) {
    int space_count = 0;
    ifstream in(file);
    while (in.good()) {
        if (32 == in.get()) space_count++;
    }
    in.close();
    return space_count;
}

void FileHandler::getCharacterFrequency(string file) {
    cout << "___CHARACTER FREQUENCY__" << std::endl;
    int i, count[256] = {0};

    string STRING;
    ifstream infile;
    infile.open(file);
    if (!infile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    while (!infile.eof()) // To get you all the lines.
    {
        getline(infile, STRING); // Saves the line in STRING.
        for (i = 0; STRING[i] != '\0'; i++) {
            // Populate frequency count array
            count[STRING[i]]++;
        }

    }
    infile.close();
    cout << "\nCharacter   Frequency\n";
    for (i = 0; i < 256; i++) {
        if (count[i] != 0 && i != 32 && i != 46) {
            cout << "  " << (char) i << "         " << count[i] << std::endl;
        }
    }
}

int FileHandler::getLineCount(string filel) {
    cout << "___LINE COUNT__" << std::endl;
    int count = 0;
    string line;
    ifstream file(filel);
    while (getline(file, line))
        count++;
    file.close();
    return count;
}


void FileHandler::getWordsBeginningWithVowels(string file) {
    cout << "___WORDS BEGINNING WITH VOWELS__" << std::endl;
    int count = 0;
    string line;
    ifstream infile;
    infile.open(file);
    if (!infile) {
        cout << "Unable to open file";
        exit(1);
    }
    while (!infile.eof()) {
        getline(infile, line);
        std::stringstream stream(line);
        std::string word;
        while (!stream.eof()) {
            stream >> word;
            if (isVowels(word)) {
                cout << word << std::endl;
                count++;
            }
        }
    }
    cout << count << " words begin with a vowel." << std::endl;
    infile.close();
}

void FileHandler::createDuplicateFileWithLowercaseVowel(string file) {
    cout << "___NEW FILE WITH NON VOWEL__" << std::endl;
    string line;
    ifstream infile;
    std::ofstream outfile("../src/TEXT2.txt");
    infile.open(file);
    if (!infile) {
        cout << "Unable to open file";
        exit(1);
    }
    while (!infile.eof()) {
        getline(infile, line);
        std::stringstream stream(line);
        std::string word;
        while (!stream.eof()) {
            stream >> word;
            if (!(isVowels(word))) {
                outfile << word << std::endl;
            }
        }
    }
    infile.close();
    outfile.close();
}

bool FileHandler::isVowels(string word) {
    bool isVowelA = word.at(0) == 'a' || word.at(0) == 'A';
    bool isVowelE = word.at(0) == 'e' || word.at(0) == 'E';
    bool isVowelI = word.at(0) == 'i' || word.at(0) == 'I';
    bool isVowelO = word.at(0) == 'o' || word.at(0) == 'O';
    bool isVowelU = word.at(0) == 'u' || word.at(0) == 'U';
    return isVowelA || isVowelE || isVowelI || isVowelO || isVowelU;
}
