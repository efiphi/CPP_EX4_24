#include "Tree.hpp"
#include <algorithm>

template <typename T>
Tree<T>::Tree(int max_children) : k(max_children), root(nullptr) {}

template <typename T>
Tree<T>::~Tree() {
    delete_tree(root);
}

template <typename T>
void Tree<T>::delete_tree(TreeNode<T>* node) {
    if (node) {
        for (auto child : node->children) {
            delete_tree(child);
        }
        delete node;
    }
}

template <typename T>
void Tree<T>::add_root(T value) {
    if (root) delete_tree(root);
    root = new TreeNode<T>(value);
}

template <typename T>
void Tree<T>::add_sub_node(TreeNode<T>* parent, T value) {
    if (parent->children.size() < k) {
        parent->children.push_back(new TreeNode<T>(value));
    } else {
        throw std::overflow_error("Max children reached");
    }
}

template <typename T>
TreeNode<T>* Tree<T>::get_root() {
    return root;
}

template <typename T>
PreOrderIterator<T> Tree<T>::begin_pre_order() {
    return PreOrderIterator<T>(root);
}

template <typename T>
PreOrderIterator<T> Tree<T>::end_pre_order() {
    return PreOrderIterator<T>(nullptr);
}

template <typename T>
PostOrderIterator<T> Tree<T>::begin_post_order() {
    return PostOrderIterator<T>(root);
}

template <typename T>
PostOrderIterator<T> Tree<T>::end_post_order() {
    return PostOrderIterator<T>(nullptr);
}

template <typename T>
InOrderIterator<T> Tree<T>::begin_in_order() {
    return InOrderIterator<T>(root);
}

template <typename T>
InOrderIterator<T> Tree<T>::end_in_order() {
    return InOrderIterator<T>(nullptr);
}

template <typename T>
BFSIterator<T> Tree<T>::begin_bfs_scan() {
    return BFSIterator<T>(root);
}

template <typename T>
BFSIterator<T> Tree<T>::end_bfs_scan() {
    return BFSIterator<T>(nullptr);
}

template <typename T>
DFSIterator<T> Tree<T>::begin_dfs_scan() {
    return DFSIterator<T>(root);
}

template <typename T>
DFSIterator<T> Tree<T>::end_dfs_scan() {
    return DFSIterator<T>(nullptr);
}

template <typename T>
void Tree<T>::heapify(TreeNode<T>* node) {
    if (!node) return;
    for (auto child : node->children) {
        if (child && node->value > child->value) {
            std::swap(node->value, child->value);
            heapify(child);
        }
    }
}

template <typename T>
void Tree<T>::myHeap() {
    if (!root) return;
    std::queue<TreeNode<T>*> nodes;
    nodes.push(root);
    while (!nodes.empty()) {
        TreeNode<T>* node = nodes.front();
        nodes.pop();
        heapify(node);
        for (auto child : node->children) {
            nodes.push(child);
        }
    }
}
