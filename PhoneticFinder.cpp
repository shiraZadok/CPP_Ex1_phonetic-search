//
// Created by shira on 24/03/2020.
//

#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

#include "PhoneticFinder.hpp"
using namespace std;


std::string phonetic::find(std::string text, std::string word) {
    word = checkForException(text, word);
    int indexT =0;
    int indexW =0;
    bool ans;

    istringstream streamText(text);
    vector<string> splitText(istream_iterator<string>{streamText},istream_iterator<string>());
    for (int i =0;i<splitText.size();i++){
        if(splitText[i].size()==word.size()){
            while(indexW<word.size()){
                char cT = splitText[i].at(indexT);
                char cW = word.at(indexW);
                ans = ifLegalChar(word.at(indexW++),splitText[i].at(indexT++));
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
    switch (cword){
        case ('v'):
            return (ctxt=='v' || ctxt=='w')? true: false;
        case ('w'):
            return (ctxt=='v' || ctxt=='w')? true: false;
        case ('g'):
            return (ctxt=='g' || ctxt=='j')? true: false;
        case ('j'):
            return (ctxt=='g' || ctxt=='j')? true: false;
        case ('s'):
            return (ctxt=='s' || ctxt=='z')? true: false;
        case ('z'):
            return (ctxt=='s' || ctxt=='z')? true: false;
        case ('d'):
            return (ctxt=='d' || ctxt=='t')? true: false;
        case ('t'):
            return (ctxt=='d' || ctxt=='t')? true: false;
        case ('o'):
            return (ctxt=='o' || ctxt=='u')? true: false;
        case ('u'):
            return (ctxt=='o' || ctxt=='u')? true: false;
        case ('i'):
            return (ctxt=='i' || ctxt=='y')? true: false;
        case ('y'):
            return (ctxt=='i' || ctxt=='y')? true: false;
        case ('b'):
            return (ctxt=='b' || ctxt=='f' ||ctxt=='p')? true: false;
        case ('f'):
            return (ctxt=='b' || ctxt=='f' ||ctxt=='p')? true: false;
        case ('p'):
            return (ctxt=='b' || ctxt=='f' ||ctxt=='p')? true: false;
        case ('c'):
            return (ctxt=='c' || ctxt=='k' || ctxt=='q')? true: false;
        case ('k'):
            return (ctxt=='c' || ctxt=='k' || ctxt=='q')? true: false;
        case ('q'):
            return (ctxt=='c' || ctxt=='k' || ctxt=='q')? true: false;
        default:
            return ctxt==cword? true: false;
    }
}
