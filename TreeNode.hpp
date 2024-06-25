#ifndef TREENODE_HPP
#define TREENODE_HPP

#include <vector>

template <typename T>
class TreeNode {
public:
    T value;
    std::vector<TreeNode*> children;
    TreeNode(T val) : value(val) {}
    T get_value() const { return value; }
};

#endif // TREENODE_HPP
