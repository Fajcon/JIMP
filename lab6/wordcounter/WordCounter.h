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
#include <algorithm>

namespace datastructures {


    class Counts{

    public:

        Counts();

        explicit Counts(int i);

        Counts &operator++();

        int getCount() const;

        bool operator==(const Counts &x)const;

        bool operator<(const Counts &x)const;

    private:
        int count_;
    };

    bool operator==(const int a, const Counts &b);
    bool operator>(const Counts &a, const int b);

    class Word{

    public:
        Word();
        Word(std::string word);
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

        Counts operator[](std::string);

        std::set<Word> Words();

    private:

        std::map<Word, Counts> map_;

    };


}

#endif //JIMP_EXERCISES_WORDCOUNTER_H
