//
// Created by ficon on 29.05.18.
//

#ifndef JIMP_EXERCISES_TREEITERATORS_H
#define JIMP_EXERCISES_TREEITERATORS_H

#include "Tree.h"
#include <vector>

namespace tree {
    template <class T>
    class InOrderTreeIterator{
    public:
        InOrderTreeIterator(Tree<T> *root){
            treeToVector(root);
            index = 0;
        };

        void treeToVector(Tree<T> *root){
            if (root->getLeft_()) treeToVector(root->getLeft_().get());
            treeVector_.emplace_back(root);
            if (root->getRight_()) treeToVector(root->getRight_().get());
        };

        InOrderTreeIterator<T> end(){
            index = treeVector_.size();
            return *this;
        }

        InOrderTreeIterator<T> operator++(){
            index++;
            return *this;
        };
        T operator* (){
            return treeVector_[index]->Value();
        };
        bool operator!= (const InOrderTreeIterator& other)const{
            return index!=other.index;
        };
    private:
        std::vector<Tree<T>*> treeVector_;
        size_t index;
    };

    template <class T>
    class InOrderTreeView{
    public:
        InOrderTreeView(Tree<T> *tree){
            root_ = tree;
        }
        InOrderTreeIterator<T> begin(){
            return InOrderTreeIterator<T>(root_);
        }
        InOrderTreeIterator<T> end(){
            return InOrderTreeIterator<T>(root_).end();
        }

    private:
        Tree<T> *root_;
    };

    template <class T>
    InOrderTreeView<T> InOrder(Tree<T> *tree){
        return InOrderTreeView<T>(tree);
    }

    /*----------------------------------------------------------*/

    template <class T>
    class PostOrderTreeIterator{
    public:
        PostOrderTreeIterator(Tree<T> *root){
            treeToVector(root);
            index = 0;
        };

        void treeToVector(Tree<T> *root){

            if (root->getLeft_()) treeToVector(root->getLeft_().get());
            if (root->getRight_()) treeToVector(root->getRight_().get());
            treeVector_.emplace_back(root);
        };

        PostOrderTreeIterator<T> end(){
            index = treeVector_.size();
            return *this;
        }

        PostOrderTreeIterator<T> operator++(){
            index++;
            return *this;
        };
        T operator* (){
            return treeVector_[index]->Value();
        };
        bool operator!= (const PostOrderTreeIterator& other)const{
            return index!=other.index;
        };
    private:
        std::vector<Tree<T>*> treeVector_;
        size_t index;
    };

    template <class T>
    class PostOrderTreeView{
    public:
        PostOrderTreeView(Tree<T> *tree){
            root_ = tree;
        }
        PostOrderTreeIterator<T> begin(){
            return PostOrderTreeIterator<T>(root_);
        }
        PostOrderTreeIterator<T> end(){
            return PostOrderTreeIterator<T>(root_).end();
        }

    private:
        Tree<T> *root_;
    };

    template <class T>
    PostOrderTreeView<T> PostOrder(Tree<T> *tree){
        return PostOrderTreeView<T>(tree);
    }

    /*----------------------------------------------------------*/


    template <class T>
    class PreOrderTreeIterator{
    public:
        PreOrderTreeIterator(Tree<T> *root){
            treeToVector(root);
            index = 0;
        };

        void treeToVector(Tree<T> *root){
            treeVector_.emplace_back(root);
            if (root->getLeft_()) treeToVector(root->getLeft_().get());
            if (root->getRight_()) treeToVector(root->getRight_().get());

        };

        PreOrderTreeIterator<T> end(){
            index = treeVector_.size();
            return *this;
        }

        PreOrderTreeIterator<T> operator++(){
            index++;
            return *this;
        };
        T operator* (){
            return treeVector_[index]->Value();
        };
        bool operator!= (const PreOrderTreeIterator& other)const{
            return index!=other.index;
        };
    private:
        std::vector<Tree<T>*> treeVector_;
        size_t index;
    };

    template <class T>
    class PreOrderTreeView{
    public:
        PreOrderTreeView(Tree<T> *tree){
            root_ = tree;
        }
        PreOrderTreeIterator<T> begin(){
            return PreOrderTreeIterator<T>(root_);
        }
        PreOrderTreeIterator<T> end(){
            return PreOrderTreeIterator<T>(root_).end();
        }

    private:
        Tree<T> *root_;
    };

    template <class T>
    PreOrderTreeView<T> PreOrder(Tree<T> *tree){
        return PreOrderTreeView<T>(tree);
    }



}


#endif //JIMP_EXERCISES_TREEITERATORS_H
