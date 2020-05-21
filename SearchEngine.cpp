//
// Created by stephenshoemaker on 5/21/20.
//

#include <iostream>
#include "SearchEngine.h"

void SearchEngine::parseDocument(std::string path) {
    parser->setCurrentDoc(path);
    parser->parseDoc();
}

SearchEngine::SearchEngine() {
    this->parser = new DocumentParser();
    this->docIndex = new DocumentIndex();
    this->wordIndex = new WordIndex();
    parser->setDocIndex(docIndex);
    parser->setIndex(wordIndex);
}

SearchEngine::~SearchEngine() {
    delete parser;
    delete docIndex;
    delete wordIndex;
}

SearchEngine::SearchEngine(SearchEngine & cpy) {
    parser = new DocumentParser(*cpy.parser);
    docIndex = new DocumentIndex(*cpy.docIndex);
    wordIndex = new WordIndex(*cpy.wordIndex);
    parser->setDocIndex(docIndex);
    parser->setIndex(wordIndex);
}

void SearchEngine::parseDirectory(std::string directory) {
    struct dirent *entry = nullptr;
    DIR *dp = nullptr;

    dp = opendir(directory.c_str());
    if(dp!= nullptr)
        while((entry = readdir(dp))){
            if(strcmp(entry->d_name,".")!=0 && strcmp(entry->d_name,"..")!=0) {
                parseDocument(directory + "/" + std::string(entry->d_name));
            }
        }

}
