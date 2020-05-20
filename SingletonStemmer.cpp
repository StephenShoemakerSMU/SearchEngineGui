//
// Created by stephenshoemaker on 5/20/20.
//

#include "SingletonStemmer.h"

//Implementation of Porter2_stemmer
std::string SingletonStemmer::stem(std::string input) {

    //If it is already stemmed, just return it
    if(stemMap.find(input) != stemMap.end()){
        return stemMap.find(input)->second;

    //Stem new word
    } else{
        //Save original for the map
        std::string original = input;

        //Trim and Stem
        Porter2Stemmer::trim(input);
        Porter2Stemmer::stem(input);

        //Insert into map
        stemMap.insert(std::pair<std::string,std::string>(original,input));

        return input;
    }
}
