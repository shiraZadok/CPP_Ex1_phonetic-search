//
// Created by shira on 24/03/2020.
//#1 - https://www.fluentcpp.com/2017/04/21/how-to-split-a-string-in-c/
//

#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

#include "PhoneticFinder.hpp"
using namespace std;

/**
 * This function looking for the word in the text with the agreed condition
 * @param text
 * @param word
 * @return if found = return the word from the text
 */
std::string phonetic::find(std::string text, std::string word) {
    word = checkForException(text, word);
    int indexT =0;
    int indexW =0;
    bool ans;

    // The following two lines from: #1
    istringstream streamText(text);
    vector<string> splitText(istream_iterator<string>{streamText},istream_iterator<string>());
    for (int i =0;i<splitText.size();i++){
        if(splitText[i].size()==word.size()){
            while(indexW<word.size()){
                ans = ifLegalChar(word.at(indexW++),splitText[i].at(indexT++)); //check for any char in the words if legal.
                if(!ans){
                    indexT=0;
                    indexW=0;
                    break;
                }
            }
            if(ans)
                return splitText[i];
        }
    }
    throw runtime_error("The word didn't found: " + word);
}


/**
 * This function check for illegal cases.
 * @param text to check
 * @param word to check
 * @return the word without spaces (if any)
 */
std::string phonetic::checkForException(std::string text,std::string word){
    //--check for illegal case--
    if(text=="") throw runtime_error("The text empty: " + text);

    //if there is space inside the word
    string wordWithoutSpaces;
    bool foundEnd = false;
    bool foundStart = false;
    for (char c: word) {
        if (c != ' ') {
            foundStart = true;
            if (!foundEnd)
                wordWithoutSpaces += c;
            else
                throw runtime_error("The word illegal - contain space inside the word: " + word);
        }
        else {
            if (foundStart)
                foundEnd = true;
        }
    }

    //if the word contain only space equals to empty word
    if(!foundStart) throw runtime_error("The word is empty: " + word);
    return wordWithoutSpaces;
}


/**
 * This function check if the char from the word and the char from the text it legal.
 * @param cword char from the word to check
 * @param ctxt char from the text to check
 * @return true if legat else false.
 */
bool phonetic::ifLegalChar(char cword,char ctxt){
    cword = tolower(cword); //convert to lower case because the two cases are legal.
    ctxt = tolower(ctxt); //convert to lower case because the two cases are legal.
    if((cword=='v' || cword=='w')&&(ctxt=='v' || ctxt=='w'))return true;
    if((cword=='g' || cword=='j')&&(ctxt=='g' || ctxt=='j'))return true;
    if((cword=='s' || cword=='z')&&(ctxt=='s' || ctxt=='z'))return true;
    if((cword=='d' || cword=='t')&&(ctxt=='d' || ctxt=='t'))return true;
    if((cword=='o' || cword=='u')&&(ctxt=='o' || ctxt=='u'))return true;
    if((cword=='i' || cword=='y')&&(ctxt=='i' || ctxt=='y'))return true;
    if((cword=='b' || cword=='f' ||cword=='p')&&(ctxt=='b' || ctxt=='f' ||ctxt=='p'))return true;
    if((cword=='c' || cword=='k' || cword=='q')&&(ctxt=='c' || ctxt=='k' || ctxt=='q'))return true;
    return ctxt==cword ? true: false;
}
