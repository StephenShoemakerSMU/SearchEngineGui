//
// Created by stephenshoemaker on 5/20/20.
//

#ifndef SEARCHENGINE_PORTER2_STEMMERWRAPPER_H
#define SEARCHENGINE_PORTER2_STEMMERWRAPPER_H


#include "SingletonStemmer.h"

class porter2_stemmerWrapper {
    private:
        static SingletonStemmer* stemmer;
    public:


        static std::string stem(std::string);
};



#endif //SEARCHENGINE_PORTER2_STEMMERWRAPPER_H
