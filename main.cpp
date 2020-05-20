#include <iostream>
#include "DocumentParser.h"
#include "WordIndex.h"

int main(int argc, char *argv[])
{
    WordIndex* wordIndex = new WordIndex();
	DocumentParser* parser = new DocumentParser("../Corpus/0a00a6df208e068e7aa369fb94641434ea0e6070.json");
	parser->setIndex(wordIndex);
	parser->parseDoc();
	delete parser;
	delete wordIndex;
}