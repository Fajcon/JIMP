//
// Created by fajcon on 11.04.18.
//

#include "WordCounter.h"
namespace datastructures {

    //Word------------------//

    //Word::Word(){
    //
    //}

    Word::Word(std::string word) {
        word_ = word;

    }

    //bool Word::operator==(const Word &x) const{
     //   return this->getWord()==x.getWord();
    //}

    bool Word::operator==(const Word &x) const {
        return word_ == x.getWord();
    }

    bool Word::operator>(const Word &x) const {
        return word_>x.getWord();
    }

    bool Word::operator<(const Word &x) const {
        return word_<x.getWord();
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

    bool Counts::operator==(const Counts &x)const{
        return this->getCount()==x.getCount();
    }

    bool Counts::operator<(const Counts &x)const {
        return this->getCount()<x.getCount();
    }



    //Word counter ---------------------------//



    WordCounter::WordCounter(std::initializer_list<Word> list) {
        for(auto& i : list){
            ++(map_[i]);

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
        std::set<Word> result;
        for (auto i:this->map_){
            result.insert(i.first);
        }
        return result;
    }

    Counts WordCounter::operator[](std::string word) {
        auto i = map_.find(Word(word));
        if (i != map_.end()) {
            return i->second;
        } else {
            return Counts(0);
        }
    }

    WordCounter::WordCounter() {

    }

    bool operator==(int a, const Counts &b) {
        return(a==b.getCount());
    }

    bool operator>(Counts &a, const int b) {
        return a.getCount()>b;
    }
}