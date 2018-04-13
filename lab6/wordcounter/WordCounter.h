//
// Created by fajcon on 11.04.18.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include <iostream>
#include <iterator>
#include <utility>
#include <map>
#include <set>
#include <list>
#include <initializer_list>
#include <sstream>

namespace datastructures {


    class Counts{

    public:

        Counts();

        explicit Counts(int i);

        Counts &operator++();

        int getCount() const;

        bool operator==(const Counts &x);

        bool operator!=(const Counts &x);

        bool operator>(const Counts &x);

        bool operator<(const Counts &x);

        bool operator==(const int &x) const;

        bool operator!=(const int &x) const;

        bool operator>(const int &x);

        bool operator<(const int &x);



    private:

        int count_;

    };


    class Word{

    public:

        Word();

        explicit Word(const std::string &word);

        std::string getWord() const;

        bool operator==(const Word &x) const;
        bool operator>(const Word &x)const;
        bool operator<(const Word &x)const;


    private:
        std::string word_;

    };


    class WordCounter {
    public:

        WordCounter();

        WordCounter(std::initializer_list<Word> list);

        int DistinctWords();

        int TotalWords();

        int operator[](const std::string &);

        std::set<Word> Words();

    private:

        std::map<Word, Counts> map_;
        Word word_;

    };


}

#endif //JIMP_EXERCISES_WORDCOUNTER_H
