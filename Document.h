//
// Created by stephenshoemaker on 5/20/20.
//

#ifndef SEARCHENGINE_DOCUMENT_H
#define SEARCHENGINE_DOCUMENT_H


#include <string>

class Document {
    private:
        std::string title;
        std::string path;
    public:
        Document(std::string, std::string);
        Document();
        Document(const Document&);
        ~Document();

        Document& operator=(const Document&);

        std::string getTitle();
        std::string getPath();

        void setTitle(std::string);
        void setPath(std::string);

        bool operator<(const Document&) const ;
};


#endif //SEARCHENGINE_DOCUMENT_H
