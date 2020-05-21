//
// Created by stephenshoemaker on 5/21/20.
//

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
