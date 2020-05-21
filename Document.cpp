//
// Created by stephenshoemaker on 5/20/20.
//

#include "Document.h"

Document::Document(std::string title, std::string path, int length) {
    this->title = title;
    this->path = path;
    this->length = length;
}

Document::Document() {
    this->title = "";
    this->path = "";
}

Document::Document(const Document & cpy) {
    this->title = cpy.title;
    this->path = cpy.path;
    this->length = cpy.length;
}

Document::~Document() {

}

Document &Document::operator=(const Document &cpy) {
    this->path = cpy.path;
    this->title=cpy.path;
    this->length = cpy.length;
    return *this;
}

std::string Document::getTitle(){
    return title;
}

std::string Document::getPath(){
    return path;
}

void Document::setTitle(std::string title) {
    this->title = title;
}

void Document::setPath(std::string path) {
    this->path = path;
}

bool Document::operator<(const Document& rhs) const {
    return path.compare(rhs.path)<0;
}

void Document::addWordMap(std::unordered_map<std::string,int> & newMap) {
    this->wordMap = newMap;
}

int Document::getLength() {
    return length;
}

int Document::getWordFrequency(std::string word) {
    return wordMap.find(word)->second;
}



