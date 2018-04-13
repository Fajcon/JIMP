//
// Created by fajcon on 11.04.18.
//

#include "WordCounter.h"
namespace datastructures {

    //Word------------------//

    Word::Word(){

    }

    Word::Word(const std::string &word) {

        word_ = word;

    }

    //bool Word::operator==(const Word &x) const{
     //   return this->getWord()==x.getWord();
    //}

    bool Word::operator==(const Word &x) const {
        return word_ == x.getWord();
    }

    bool Word::operator>(const Word &x) const {
        return false;
    }

    bool Word::operator<(const Word &x) const {
        return false;
    }

    std::string Word::getWord() const{
        return word_;
    }


    //Counts ---------------- //
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

    int Counts::getCount() const{
        return count_;
    }

    bool Counts::operator==(const Counts &x){
        return this->getCount()==x.getCount();
    }

    bool Counts::operator>(const Counts &x){
        return this->getCount()>x.getCount();
    }

    bool Counts::operator<(const Counts &x) {
        return this->getCount()<x.getCount();
    }

    bool Counts::operator==(const int &x) const{
        return this->getCount()==x;
    }

    bool Counts::operator>(const int &x){
        return this->getCount()>x;
    }

    bool Counts::operator<(const int &x){
        return this->getCount()<x;
    }

    bool Counts::operator!=(const Counts &x) {
        return this->getCount()!=x.getCount();
    }

    bool Counts::operator!=(const int &x) const {
        return this->getCount()!=x;
    }


    //Word counter ---------------------------//
    WordCounter::WordCounter() = default;


    WordCounter::WordCounter(std::initializer_list<Word> list) {
        for(auto& i : list){
            word_=i;
            ++(map_[word_]);

        }
    }

    int  WordCounter::DistinctWords() {
        int result=0;
        for(auto i : map_) {
            if (i.second.getCount()>0){
                ++result;
            }
        }
        return result;
    }

    int WordCounter::TotalWords() {
        int result=0;
        for(auto i : map_){
            result+=i.second.getCount();
        }
        return result;
    }

    std::set<Word>WordCounter::Words(){
        int n=0;
        std::set<Word> result;
        for(auto i : map_){
            n=i.second.getCount();
            for (int j = n; j > 0; --j) {
                result.insert(i.first);
            }
        }
        return result;
    }

    int WordCounter::operator[](const std::string &word) {
        auto result = map_[Word(word)].getCount();
        return result;
    }
}