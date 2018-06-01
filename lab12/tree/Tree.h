//
// Created by ficon on 29.05.18.
//

#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H

#include <functional>
#include <memory>

namespace tree {
    template<class Element>
    class Tree {
    public:
        Tree(const Element &e) {
            value_ = e;
            left_ = nullptr;
            right_ = nullptr;
        }

        void Insert(const Element &e) {
            if (e > Value()){
                if(left_ == nullptr) {
                    left_ = std::make_unique<Tree<Element>>(e);
                }
                else{
                    left_->Insert(e);
                }
            }
            else{
                if(right_ == nullptr) {
                    right_ = std::make_unique<Tree<Element>>(e);
                }
                else{
                    right_->Insert(e);
                }
            }
        }

        bool Find(const Element &e) {
            return false;
        }

        size_t Depth() {
            if(left_ == nullptr && right_ == nullptr){
                return 1;
            }
            else if(left_ != nullptr){
                return left_->Depth() + 1;
            }
            else if(right_ != nullptr){
                return right_->Depth() + 1;
            }
        }

        size_t Size() {
            if(left_ == nullptr && right_ == nullptr){
                return 1;
            }
            else if(left_ != nullptr && right_ != nullptr){
                return left_->Size() + right_->Size() + 1;
            }
            else if(left_ != nullptr){
                return left_->Size() + 1;
            }
            else{
                return right_->Size() + 1;
            }
        }

        Element Value(){
            return value_;
        }

    private:
        std::unique_ptr<Tree> left_;
        std::unique_ptr<Tree> right_;
        Element value_;
    };
}


#endif //JIMP_EXERCISES_TREE_H
