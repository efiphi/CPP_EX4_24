#include "PostOrderIterator.hpp"

template <typename T>
PostOrderIterator<T>::PostOrderIterator(TreeNode<T>* root) {
    if (root) {
        pushChildren(root);
    }
}

template <typename T>
void PostOrderIterator<T>::pushChildren(TreeNode<T>* node) {
    if (node) {
        nodeStack.push(node);
        for (auto child : node->children) {
            pushChildren(child);
        }
    }
}

template <typename T>
bool PostOrderIterator<T>::operator!=(const PostOrderIterator& other) const {
    return !nodeStack.empty() || !other.nodeStack.empty();
}

template <typename T>
T& PostOrderIterator<T>::operator*() {
    return nodeStack.top()->value;
}

template <typename T>
PostOrderIterator<T>& PostOrderIterator<T>::operator++() {
    nodeStack.pop();
    return *this;
}
