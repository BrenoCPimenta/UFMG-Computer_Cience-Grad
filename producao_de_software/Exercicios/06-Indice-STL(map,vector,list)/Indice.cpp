#include "Indice.hpp"
#include <iostream>
#include <iomanip>

Indice::Indice(std::string& text){
    int text_size = text.length();
    std::string word = "";
    std::map<std::string, int> ::iterator itmap;
    word_number=0;

    for(int i=0; i<text_size; i++){
    	if( (text[i]==' ') || (i+1 == text_size) ){
    		if (i+1 == text_size){
    		       word += text[i];
    		}    
    
            word_number += 1;
    		words_of_text.push_back(word);
            
    		if(word.length() > 2){
    		     itmap = big_words_rep.find(word);
    		     if(itmap == big_words_rep.end()){
    			 big_words_rep[word] = 1;
    		     }else{
    	   	         big_words_rep[word] += 1;
    		     }
    		}          	 	     
    		word="";
    	}else{
    		word += text[i];
    	}

    }

}


void Indice::printBigWordsData(){
	float percentage = 0;
	for(auto it : big_words_rep){
		percentage = float(it.second)/float(word_number-1);
		std::cout
			<< it.first 
			<< " " 
			<< it.second  
			<< " "
			<< std::fixed
			<< std::setprecision(2)
			<< percentage
		<< std::endl;
	}
}
