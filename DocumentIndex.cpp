//
// Created by stephenshoemaker on 5/20/20.
//

#include <iostream>
#include "DocumentIndex.h"
#include "fstream"
DocumentIndex::DocumentIndex() {

}

DocumentIndex::DocumentIndex(DocumentIndex & cpy) {
    for(auto iter = cpy.docMap.begin(); iter !=cpy.docMap.end();iter++){
        this->docMap.insert(std::pair<std::string,Document*>(iter->first,new Document(*iter->second)));
    }
}

DocumentIndex::~DocumentIndex() {
    for(auto iter = docMap.begin(); iter!=docMap.end();iter++){
        delete iter->second;
    }
}

DocumentIndex &DocumentIndex::operator=(DocumentIndex & cpy) {
    this->~DocumentIndex();
    for(auto iter = cpy.docMap.begin(); iter !=cpy.docMap.end();iter++){
        this->docMap.insert(std::pair<std::string,Document*>(iter->first,new Document(*iter->second)));
    }

    return *this;
}

void DocumentIndex::addDoc(Document * doc) {
    docMap.insert(std::pair<std::string,Document*>(doc->getPath(),doc));
}

Document* DocumentIndex::getDoc(std::string path) {
    return docMap.find(path)->second;
}

void DocumentIndex::saveIndex(std::string path) {
    for(auto index = docMap.begin();index!=docMap.end();index++){
        std::string output = path + "/" + index->second->getTitle()+ ".txt";
        std::ofstream file(output);
        file << index->second->getJson();
        file.close();
    }
}

void DocumentIndex::loadDocument(std::string path) {
    std::ifstream file(path);
    std::string line;
    if(file.good()){
        Document* newDoc = new Document();
        getline(file,line);
        newDoc->setPath(line);

        getline(file,line);
        newDoc->setTitle(line);
        std::string word;
        std::string frequency;

        while(file.good()){
            getline(file,word,' ');
            getline(file,frequency);

            newDoc->addWord(word,std::stoi(frequency));

        }

        docMap.insert(std::pair<std::string,Document*>(newDoc->getPath(),newDoc));


    }
}
