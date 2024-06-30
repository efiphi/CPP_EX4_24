//efiphi10@gmail.com
#ifndef PREORDERITERATOR_HPP
#define PREORDERITERATOR_HPP

#include "TreeNode.hpp"
#include <stack>

template <typename T>
class PreOrderIterator {
private:
    std::stack<TreeNode<T>*> nodeStack;
public:
    PreOrderIterator(TreeNode<T>* root);
    bool operator!=(const PreOrderIterator& other) const;
    T& operator*();
    PreOrderIterator& operator++();
};

#include "PreOrderIterator.cpp"
#endif // PREORDERITERATOR_HPP
