//
// Created by stephenshoemaker on 5/20/20.
//

#ifndef SEARCHENGINE_DOCUMENTINDEX_H
#define SEARCHENGINE_DOCUMENTINDEX_H

#include <unordered_map>
#include "Document.h"

class DocumentIndex {
    private:
        std::unordered_map<std::string, Document*> docMap;
    public:
        DocumentIndex();
        DocumentIndex(DocumentIndex&);
        ~DocumentIndex();

        DocumentIndex& operator=(DocumentIndex&);

        void addDoc(Document*);

        Document* getDoc(std::string);

        void saveIndex(std::string);
};


#endif //SEARCHENGINE_DOCUMENTINDEX_H
