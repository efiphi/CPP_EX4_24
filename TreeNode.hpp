//efiphi10@gmail.com
#ifndef TREENODE_HPP
#define TREENODE_HPP

#include <vector>
#include <string>
#include <sstream>

template <typename T>
class TreeNode {
public:
    T value;
    std::vector<TreeNode<T>*> children;

    TreeNode(T val) : value(val) {}

    std::string to_str() const {
        std::ostringstream oss;
        oss << value;
        return oss.str();
    }

    std::string to_short_string() const {
        std::ostringstream oss;
        oss << value;
        return oss.str();
    }
};

#endif // TREENODE_HPP
