#ifndef TREE_HPP
#define TREE_HPP

#include "TreeNode.hpp"
#include "PreOrderIterator.hpp"
#include "PostOrderIterator.hpp"
#include "InOrderIterator.hpp"
#include "BFSIterator.hpp"
#include "DFSIterator.hpp"
#include <stdexcept>
#include <vector>

template <typename T>
class Tree {
private:
    TreeNode<T>* root;
    int k;
    void delete_tree(TreeNode<T>* node);
    void heapify(TreeNode<T>* node);
public:
    Tree(int max_children = 2);
    ~Tree();
    void add_root(T value);
    void add_sub_node(TreeNode<T>* parent, T value);
    TreeNode<T>* get_root();

    PreOrderIterator<T> begin_pre_order();
    PreOrderIterator<T> end_pre_order();
    PostOrderIterator<T> begin_post_order();
    PostOrderIterator<T> end_post_order();
    InOrderIterator<T> begin_in_order();
    InOrderIterator<T> end_in_order();
    BFSIterator<T> begin_bfs_scan();
    BFSIterator<T> end_bfs_scan();
    DFSIterator<T> begin_dfs_scan();
    DFSIterator<T> end_dfs_scan();
    void myHeap();
};

#include "Tree.cpp"
#endif // TREE_HPP
