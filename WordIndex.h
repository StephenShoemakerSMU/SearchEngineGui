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
class WordIndex {
    private:

        struct DocumentCompare
        {
            bool operator() (const Document& lhs, const Document& rhs) const
            {
                return lhs < rhs;
            }
        };
        struct Word{
            std::string text;
            std::map<Document,float> frequency;

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

        void addDoc(std::string, std::string, std::string, float);
};


#endif //SEARCHENGINE_WORDINDEX_H
