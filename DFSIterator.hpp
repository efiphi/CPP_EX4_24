#ifndef DFSITERATOR_HPP
#define DFSITERATOR_HPP

#include "TreeNode.hpp"
#include <stack>

template <typename T>
class DFSIterator {
private:
    std::stack<TreeNode<T>*> nodeStack;
public:
    DFSIterator(TreeNode<T>* root);
    bool operator!=(const DFSIterator& other) const;
    T& operator*();
    DFSIterator& operator++();
};

#include "DFSIterator.cpp"
#endif // DFSITERATOR_HPP
