#include "BFSIterator.hpp"

template <typename T>
BFSIterator<T>::BFSIterator(TreeNode<T>* root) {
    if (root) {
        nodeQueue.push(root);
    }
}

template <typename T>
bool BFSIterator<T>::operator!=(const BFSIterator& other) const {
    return !nodeQueue.empty() || !other.nodeQueue.empty();
}

template <typename T>
T& BFSIterator<T>::operator*() {
    return nodeQueue.front()->value;
}

template <typename T>
BFSIterator<T>& BFSIterator<T>::operator++() {
    TreeNode<T>* node = nodeQueue.front();
    nodeQueue.pop();
    for (auto child : node->children) {
        nodeQueue.push(child);
    }
    return *this;
}
