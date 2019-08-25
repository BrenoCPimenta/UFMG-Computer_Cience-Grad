#ifndef INDICE_H
#define INDICE_H

#include <string>
#include <vector>
#include <map>

struct Indice{
	std::vector<std::string> words_of_text;
	std::map<std::string, int> big_words_rep; 
    int word_number;


	Indice(std::string&);
	

	void printBigWordsData();
};

#endif

