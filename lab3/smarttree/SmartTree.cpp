//
// Created by fajcon on 19.03.18.
//

#include "SmartTree.h"

#include <iostream>
#include <string>
#include <memory>

namespace datastructures {

    std::unique_ptr<SmartTree> Init();

    std::unique_ptr<SmartTree> CreateLeaf(int value) {
        auto new_leaf = std::make_unique<SmartTree>();
        new_leaf->value = value;
        new_leaf->left = nullptr;
        new_leaf->right = nullptr;
        return new_leaf;
    }

    std::unique_ptr<SmartTree>
    InsertLeftChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> left_subtree) {
        tree->left = std::move(left_subtree);
        return tree;

    }

    std::unique_ptr<SmartTree>
    InsertRightChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> right_subtree) {
        tree->right = std::move(right_subtree);
        return tree;

    }

    std::string GoInto(const std::unique_ptr<SmartTree> &unique_ptr){
        if(unique_ptr->left == nullptr){

        }

        else{
            return GoInto(unique_ptr->left)+", "+std::to_string(unique_ptr->left->value);
        }
    }

    void PrintTreeInOrder(const std::unique_ptr<SmartTree> &unique_ptr, std::ostream *out) {
        std::cout << GoInto(unique_ptr);
    }



    std::string DumpTree(const std::unique_ptr<SmartTree> &tree) {

    }

    std::unique_ptr<SmartTree> RestoreTree(const std::string &tree) {

    }
}