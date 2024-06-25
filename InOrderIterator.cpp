#include "InOrderIterator.hpp"
#include <cstddef>

template <typename T>
InOrderIterator<T>::InOrderIterator(TreeNode<T>* root) {
    pushLeft(root);
}

template <typename T>
void InOrderIterator<T>::pushLeft(TreeNode<T>* node) {
    while (node) {
        nodeStack.push(node);
        if (!node->children.empty())
            node = node->children[0];
        else
            break;
    }
}

template <typename T>
bool InOrderIterator<T>::operator!=(const InOrderIterator& other) const {
    return !nodeStack.empty() || !other.nodeStack.empty();
}

template <typename T>
T& InOrderIterator<T>::operator*() {
    return nodeStack.top()->value;
}

template <typename T>
InOrderIterator<T>& InOrderIterator<T>::operator++() {
    TreeNode<T>* node = nodeStack.top();
    nodeStack.pop();
    if (!node->children.empty() && nodeStack.empty()) {
        for (size_t i = 1; i < node->children.size(); ++i) {
            pushLeft(node->children[i]);
        }
    }
    return *this;
}
