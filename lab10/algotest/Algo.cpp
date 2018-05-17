//
// Created by ficon on 15.05.18.
//

#include <set>
#include <map>
#include <vector>
#include "Algo.h"

namespace algo{

    void CopyInto(const std::vector<int> &v, int n_elements, std::vector<int> *out) {
        std::copy(v.begin(), v.begin()+n_elements, std::back_inserter(*out));
    }

    bool Contains(const std::vector<int> &v, int element) {
        if( std::find(std::begin(v), std::end(v), element) != std::end(v)){
            return true;
        }else{
            return false;
        }
    }

    void InitializeWith(int initial_value, std::vector<int> *v) {
        std::fill(v->begin(), v->end(), initial_value);

    }

    std::vector<int> InitializedVectorOfLength(int length, int initial_value) {
        std::vector<int> result(length);
        std::fill_n(result.begin(), length, initial_value);
        return result;
    }

    std::vector<std::string> MapToString(const std::vector<double> &v) {
        std::vector<std::string> result;
        std::transform(v.begin(), v.end(), back_inserter(result),
                       [](double c){ return std::to_string(c); });
        return result;
    }

    std::set<std::string> Keys(const std::map<std::string, int> &m) {
        std::set<std::string> result;
        std::transform (m.begin(), m.end(), std::inserter(result, result.begin()),
                        [] (std::pair<std::string, int> pair){
                            return pair.first; });
        return result;
    }

    bool ContainsKey(const std::map<std::string, int> &v, const std::string &key) {
        std::set<std::string> result;
        std::transform (v.begin(), v.end(), std::inserter(result, result.begin()),
                        [] (std::pair<std::string, int> pair){
                            return pair.first; });
        auto result1 = std::find(std::begin(result), std::end(result), key);
        if(result1 != std::end(result)){
            return true;
        }else{
            return false;
        }
    }

    std::vector<int> Values(const std::map<std::string, int> &m) {
        std::vector<int> result;
        std::transform (m.begin(), m.end(), std::inserter(result, result.begin()),
                        [] (std::pair<std::string, int> pair){
                            return pair.second; });
        return result;
    }

    bool ContainsValue(const std::map<std::string, int> &v, int value) {
        std::vector<int> result;
        std::transform (v.begin(), v.end(), std::inserter(result, result.begin()),
                        [] (std::pair<std::string, int> pair){
                            return pair.second; });
        auto result1 = std::find(std::begin(result), std::end(result), value);
        if(result1 != std::end(result)){
            return true;
        }else{
            return false;
        }

    }

    void SortInPlace(std::vector<int> *v) {
        std::sort(v->begin(), v->end());

    }

    std::vector<int> Sort(const std::vector<int> &v) {
        std::vector<int> result;
        std::copy(v.begin(), v.end(), std::back_inserter(result));
        std::sort(result.begin(), result.end());
        return result;
    }





    std::map<std::string, int> DivisableBy(const std::map<std::string, int> &m, int divisor) {
        return std::map<std::string, int>();
    }

    void SortByFirstInPlace(std::vector<std::pair<int, int>> *v) {
        std::sort(v->begin(), v->end(), [](const auto &l, const auto &r){return l.first<r.first;});
    }

    void SortByFSecondInPlace(std::vector<std::pair<int, int>> *v) {
        std::sort(v->begin(), v->end(), [](const auto &l, const auto &r){return l.second<r.second;});
    }

    void SortByThirdInPlace(std::vector<std::tuple<int, int, int>> *v) {
        std::sort(v->begin(), v->end(), [](const auto &l, const auto &r){return std::get<3>&l < std::get<3>&r;});

    }





}