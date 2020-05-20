//
// Created by stephenshoemaker on 5/20/20.
//

#ifndef SEARCHENGINE_PORTER2_STEMMERWRAPPER_H
#define SEARCHENGINE_PORTER2_STEMMERWRAPPER_H


#include "SingletonStemmer.h"

//The goal of this is so that there is one stemmer for the whole runtime
//This reduces redundancy by instead of stemming the same word multiple times, it is just mapped to the correct output

class porter2_stemmerWrapper {
    private:
        //Singleton Stemmer Pointer
        static SingletonStemmer* stemmer;
    public:
        //Takes an input string and poops out the output
        static std::string stem(std::string);
};



#endif //SEARCHENGINE_PORTER2_STEMMERWRAPPER_H
