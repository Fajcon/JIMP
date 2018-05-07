//
// Created by fajcon on 25.04.18.
//

#include "Iterable.h"
namespace utility{

    /*ZipperIterator::ZipperIterator(std::vector<int>::const_iterator left,
                                   std::vector<std::string>::const_iterator right,
                                   std::vector<int>::const_iterator left_end,
                                   std::vector<std::string>::const_iterator right_end) {



        left_ = left;
        right_ = right;

    }*/

    std::pair<int, std::string> ZipperIterator::Dereference() const {
        return std::make_pair(*left_, *right_);
    }

    IterableIterator &ZipperIterator::Next() {
        ++left_;
        ++right_;
        return *this;
    }

    bool ZipperIterator::NotEquals(const std::unique_ptr<IterableIterator> &other) const {
        return ((right_!=other->right_) || (left_!=other->left_));
    }

    ZipperIterator::ZipperIterator(std::vector<int>::const_iterator left,
                                   std::vector<std::string>::const_iterator right) {

        left_=left;
        right_=right;

    }

    ProductIterator::ProductIterator(std::vector<int>::const_iterator left,
                                     std::vector<std::string>::const_iterator right) {

        left_=left;
        right_=right;

    }

    std::pair<int, std::string> ProductIterator::Dereference() const {
        return std::make_pair(*left_, *right_);
    }

    IterableIterator &ProductIterator::Next() {
        ++left_;
        ++right_;
        return *this;
    }

    bool ProductIterator::NotEquals(const std::unique_ptr<IterableIterator> &other) const {
        return ((right_!=other->right_) || (left_!=other->left_));;
    }

    IterableIteratorWrapper::IterableIteratorWrapper(std::unique_ptr<IterableIterator> iterator) {
        iterator_=move(iterator);
    }

    bool IterableIteratorWrapper::operator!=(const IterableIteratorWrapper &other) {
        return iterator_->NotEquals(other.iterator_);
    }

    std::pair<int, std::string> IterableIteratorWrapper::operator*() {
        return iterator_->Dereference();
    }

    IterableIteratorWrapper &IterableIteratorWrapper::operator++() {
        iterator_->Next();
        return *this;
    }

    IterableIteratorWrapper Iterable::begin() const {
        return IterableIteratorWrapper(ConstBegin());
    }

    IterableIteratorWrapper Iterable::end() const {
        return IterableIteratorWrapper(ConstEnd());
    }

    //IterableIteratorWrapper Iterable::begin() const {
     //   return cbegin();
    //}

    //IterableIteratorWrapper Iterable::end() const {
     //   return cend();
    //}

    Zipper::Zipper(std::vector<int> vectorInt, std::vector<std::string> vectorString) {
        vectorInt_=vectorInt;
        vectorString_=vectorString;
        if (vectorInt_.size()>vectorString_.size()){
            for (auto i=vectorString_.size(); i<vectorInt_.size(); ++i){
                vectorString_.emplace_back(vectorString.back());
            }
        }else{
            for (auto i = vectorInt_.size(); i < vectorString_.size(); ++i) {
                vectorInt_.emplace_back(vectorInt.back());
            }
        }

    }

    std::unique_ptr<IterableIterator> Zipper::ConstBegin() const {
        ZipperIterator zipperit (vectorInt_.begin(),vectorString_.begin());
        std::unique_ptr<IterableIterator> ptr = std::make_unique<ZipperIterator>(zipperit);
        return ptr;
    }

    std::unique_ptr<IterableIterator> Zipper::ConstEnd() const {
        ZipperIterator zipperit (vectorInt_.end(),vectorString_.end());
        std::unique_ptr<IterableIterator> ptr = std::make_unique<ZipperIterator>(zipperit);
        return ptr;
    }


    Enumerate::Enumerate(std::vector<std::string> vectorString) {
        vectorString_ = vectorString;
        for (int i=1;i<=vectorString_.size();++i){
            vectorInt_.emplace_back(i);
        }
    }

    std::unique_ptr<IterableIterator> Enumerate::ConstBegin() const {
        ZipperIterator zit (vectorInt_.begin(),vectorString_.begin());
        std::unique_ptr<IterableIterator> ptr = std::make_unique<ZipperIterator>(zit);
        return ptr;
    }

    std::unique_ptr<IterableIterator> Enumerate::ConstEnd() const {
        ZipperIterator zit (vectorInt_.end(),vectorString_.end());
        std::unique_ptr<IterableIterator> ptr = std::make_unique<ZipperIterator>(zit);
        return ptr;
    }

    Product::Product(std::vector<int> vectorInt, std::vector<std::string> vectorString) {
        for (auto it:vectorInt){
            for (auto it2:vectorString){
                vectorInt_.emplace_back(it);
                vectorString_.emplace_back(it2);
            }
        }
    }

    std::unique_ptr<IterableIterator> Product::ConstBegin() const {
        ProductIterator zit (vectorInt_.begin(),vectorString_.begin());
        std::unique_ptr<IterableIterator> ptr = std::make_unique<ProductIterator>(zit);
        return ptr;
    }

    std::unique_ptr<IterableIterator> Product::ConstEnd() const {
        ProductIterator zit (vectorInt_.end(),vectorString_.end());
        std::unique_ptr<IterableIterator> ptr = std::make_unique<ProductIterator>(zit);
        return ptr;
    }


}