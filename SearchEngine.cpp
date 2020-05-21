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

void SearchEngine::search(std::string search) {
    std::set<std::pair<float,Document*>> docSet;

    std::string original = search;

    search = porter2_stemmerWrapper::stem(search);
    auto word = wordIndex->getWord(search);
    for(auto iter = word.docMap.begin(); iter !=word.docMap.end();iter++){
        docSet.insert(std::pair<float,Document*>(-1*((float)iter->second->getWordFrequency(search))/ iter->second->getLength(),iter->second));
    }

    std::cout<<"Search Results for: " << original << std::endl;

    for(auto iter = docSet.begin(); iter != docSet.end(); iter++){
        std::cout << iter->second->getTitle() << " " << -1*iter->first << std::endl;
    }
}
