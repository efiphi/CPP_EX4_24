//efiphi10@gmail.com
#ifndef INORDERITERATOR_HPP
#define INORDERITERATOR_HPP

#include "TreeNode.hpp"
#include <stack>
#include <cstddef>

template <typename T>
class InOrderIterator {
private:
    std::stack<TreeNode<T>*> nodeStack;
    TreeNode<T>* current;
    void pushLeft(TreeNode<T>* node);
public:
    InOrderIterator(TreeNode<T>* root);
    bool operator!=(const InOrderIterator& other) const;
    T& operator*();
    InOrderIterator& operator++();
};

#include "InOrderIterator.cpp"
#endif // INORDERITERATOR_HPP
