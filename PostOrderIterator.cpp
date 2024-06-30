//efiphi10@gmail.com
#include "PostOrderIterator.hpp"

template <typename T>
PostOrderIterator<T>::PostOrderIterator(TreeNode<T>* root) : lastVisited(nullptr) {
    if (root) pushChildren(root);
}

template <typename T>
void PostOrderIterator<T>::pushChildren(TreeNode<T>* node) {
    nodeStack.push(node);
    for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) {
        pushChildren(*it);
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
    lastVisited = nodeStack.top();
    nodeStack.pop();
    return *this;
}
