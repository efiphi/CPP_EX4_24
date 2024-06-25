#include "PreOrderIterator.hpp"

template <typename T>
PreOrderIterator<T>::PreOrderIterator(TreeNode<T>* root) {
    if (root) {
        nodeStack.push(root);
    }
}

template <typename T>
bool PreOrderIterator<T>::operator!=(const PreOrderIterator& other) const {
    return !nodeStack.empty() || !other.nodeStack.empty();
}

template <typename T>
T& PreOrderIterator<T>::operator*() {
    return nodeStack.top()->value;
}

template <typename T>
PreOrderIterator<T>& PreOrderIterator<T>::operator++() {
    TreeNode<T>* node = nodeStack.top();
    nodeStack.pop();
    for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) {
        nodeStack.push(*it);
    }
    return *this;
}
