//
// Created by stephenshoemaker on 5/20/20.
//

#include "Document.h"

Document::Document(std::string title, std::string path) {
    this->title = title;
    this->path = path;
}

Document::Document() {
    this->title = "";
    this->path = "";
}

Document::Document(const Document & cpy) {
    this->title = cpy.title;
    this->path = cpy.path;
}

Document::~Document() {

}

Document &Document::operator=(const Document &cpy) {
    this->path = cpy.path;
    this->title=cpy.path;
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



