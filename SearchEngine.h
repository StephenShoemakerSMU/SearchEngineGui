//
// Created by stephenshoemaker on 5/21/20.
//

#ifndef SEARCHENGINE_SEARCHENGINE_H
#define SEARCHENGINE_SEARCHENGINE_H

#include "DocumentParser.h"
#include "porter2_stemmerWrapper.h"
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

        void search(std::string);

        void parseDirectory(std::string);
        void parseDocument(std::string);

        void saveDocumentIndex(std::string);

        void saveWogrdIndex(std::string);

        void loadPersistentDoc(std::string);
};


#endif //SEARCHENGINE_SEARCHENGINE_H
