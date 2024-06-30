//efiphi10@gmail.com
#ifndef BFSITERATOR_HPP
#define BFSITERATOR_HPP

#include "TreeNode.hpp"
#include <queue>

template <typename T>
class BFSIterator {
private:
    std::queue<TreeNode<T>*> nodeQueue;
public:
    BFSIterator(TreeNode<T>* root);
    bool operator!=(const BFSIterator& other) const;
    T& operator*();
    BFSIterator& operator++();
};

#include "BFSIterator.cpp"
#endif // BFSITERATOR_HPP
