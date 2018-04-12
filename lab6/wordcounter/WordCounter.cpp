//
// Created by fajcon on 11.04.18.
//

#include "WordCounter.h"
namespace datastructures {

    //Konstruktory ------------------//

    Word::Word(){

    }

    Word::Word(const std::string &word) {

        word_ = word;

    }

    Counts::Counts() {

        count_ = 0;

    }

    Counts::Counts(int i) {

        count_ = i;

    }

    Counts &Counts::operator++() {
        ++count_;
        return *this;

    }

    int Counts::getCount() {
        return count_;
    }

    WordCounter::WordCounter(){

    }


    WordCounter::WordCounter(const std::initializer_list<Word> list) {
        for(auto i : list){
            if(map_.count(i)>0) {
                ++(map_[i]);
            }
            else{
                map_.insert(std::make_pair(Word(i), Counts(1)));
            }
        }
    }

    //Metody ----------------------------//

    unsigned long  WordCounter::DistinctWords() {
        return 0;
    }

    int WordCounter::TotalWords() {
        return 0;
    }

    int WordCounter::operator[](const std::string &word) {
        auto result = map_[Word(word)].getCount();
        return result;
    }
}