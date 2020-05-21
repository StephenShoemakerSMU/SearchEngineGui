//
// Created by stephenshoemaker on 5/21/20.
//

#ifndef SEARCHENGINE_SEARCHENGINE_H
#define SEARCHENGINE_SEARCHENGINE_H

#include "DocumentParser.h"
#include <stdio.h>
#include <dirent.h>

//Class Dedicated to managing all of the componenets of the search engine
//Has a document parser that reads a document and extracts the document info
//Document Index stores the Documents and the data
//Word Index stores the words and what documents they appear in
class SearchEngine {
    private:
        DocumentParser* parser;
        DocumentIndex* docIndex;
        WordIndex* wordIndex;
    public:
        SearchEngine();
        ~SearchEngine();
        SearchEngine(SearchEngine&);

        void parseDirectory(std::string);
        void parseDocument(std::string);
};


#endif //SEARCHENGINE_SEARCHENGINE_H
