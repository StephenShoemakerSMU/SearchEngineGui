//
// Created by stephenshoemaker on 5/20/20.
//

#ifndef SEARCHENGINE_WORDINDEX_H
#define SEARCHENGINE_WORDINDEX_H


#include <string>
#include <map>

#include <unordered_map>
#include "Document.h"
#include "utility"

//Stores Each Word and what Documents it is in
//Does this by mapping a string to a Word Object
//Each Word stores what it is, and a map that tracks a Document and its frequency
class WordIndex {
    private:

        struct Word{
            std::string text;
            std::map<std::string,Document*> docMap;

            Word();
            Word(std::string);
            Word(Word&);
            ~Word();

            Word& operator=(const Word&);
        };

        std::unordered_map<std::string, Word*> wordMap;
    public:
        WordIndex();
        WordIndex(WordIndex&);
        ~WordIndex();

        WordIndex& operator=(const WordIndex&);

        //Add a Doc to a word and its respective frequency
        void addEntry(std::string word, Document* doc);

        Word& getWord(std::string);
};


#endif //SEARCHENGINE_WORDINDEX_H
