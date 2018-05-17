//
// Created by ficon on 15.05.18.
//

#ifndef JIMP_EXERCISES_ALGO_H
#define JIMP_EXERCISES_ALGO_H

#include <algorithm>
#include <string>
#include <tuple>
#include <utility>

namespace algo {

    void CopyInto(const std::vector<int> &v, int n_elements, std::vector<int> *out);

    bool Contains(const std::vector<int> &v, int element);\

    void InitializeWith(int initial_value, std::vector<int> *v);

    std::vector<int> InitializedVectorOfLength(int length, int initial_value);

    std::vector<std::string> MapToString(const std::vector<double> &v);

    std::set<std::string> Keys(const std::map<std::string, int> &m);

    bool ContainsKey(const std::map<std::string, int> &v, const std::string &key);

    std::vector<int> Values(const std::map<std::string, int> &m);

    bool ContainsValue(const std::map<std::string, int> &v, int value);

    void SortInPlace(std::vector<int> *v);

    std::vector<int> Sort(const std::vector<int> &v);

    void SortByFirstInPlace(std::vector<std::pair<int,int>> *v);

    void SortBySecondInPlace(std::vector<std::pair<int,int>> *v);

    void SortByThirdInPlace(std::vector<std::tuple<int,int,int>> *v);

    std::map<std::string, int> DivisableBy(const std::map<std::string, int> &m,int divisor);

}


#endif //JIMP_EXERCISES_ALGO_H
