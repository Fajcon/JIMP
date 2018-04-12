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
#include <initializer_list>
#include <sstream>

namespace datastructures {


    class Counts{

    public:

        Counts();

        explicit Counts(int i);

        Counts &operator++();

        int getCount();

    private:

        int count_;

    };

    class Word{

    public:

        Word();

        explicit Word(const std::string &word);

    private:
        std::string word_;

    };

    class WordCounter {
    public:

        WordCounter();

        WordCounter(const std::initializer_list<Word>);

        unsigned long DistinctWords();

        int TotalWords();

        int operator[](const std::string &);


    private:

        std::map<Word, Counts> map_;

    };


}

#endif //JIMP_EXERCISES_WORDCOUNTER_H
