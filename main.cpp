#include <iostream>

#include "SearchEngine.h"

int main(int argc, char *argv[])
{

    SearchEngine searchEngine;
    searchEngine.parseDirectory("../Corpus");
    searchEngine.saveDocumentIndex("../Persistent/Documents");
}