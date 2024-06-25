#include "DFSIterator.hpp"

template <typename T>
DFSIterator<T>::DFSIterator(TreeNode<T>* root) {
    if (root) {
        nodeStack.push(root);
    }
}

template <typename T>
bool DFSIterator<T>::operator!=(const DFSIterator& other) const {
    return !nodeStack.empty() || !other.nodeStack.empty();
}

template <typename T>
T& DFSIterator<T>::operator*() {
    return nodeStack.top()->value;
}

template <typename T>
DFSIterator<T>& DFSIterator<T>::operator++() {
    TreeNode<T>* node = nodeStack.top();
    nodeStack.pop();
    for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) {
        nodeStack.push(*it);
    }
    return *this;
}
