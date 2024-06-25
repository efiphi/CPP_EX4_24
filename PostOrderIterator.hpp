#ifndef POSTORDERITERATOR_HPP
#define POSTORDERITERATOR_HPP

#include "TreeNode.hpp"
#include <stack>
#include <vector>

template <typename T>
class PostOrderIterator {
private:
    std::stack<TreeNode<T>*> nodeStack;
    void pushChildren(TreeNode<T>* node);
public:
    PostOrderIterator(TreeNode<T>* root);
    bool operator!=(const PostOrderIterator& other) const;
    T& operator*();
    PostOrderIterator& operator++();
};

#include "PostOrderIterator.cpp"
#endif // POSTORDERITERATOR_HPP
