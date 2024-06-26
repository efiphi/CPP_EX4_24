/**
 * Demo app for Ex4
 */
#include <iostream>
#include <string>
#include "TreeNode.hpp"
#include "Tree.hpp"

using namespace std;

int main() {
    Tree<double> tree; // Binary tree that contains doubles.
    tree.add_root(1.1);

    tree.add_sub_node(tree.get_root(), 1.2);
    tree.add_sub_node(tree.get_root(), 1.3);
    TreeNode<double>* n1 = tree.get_root()->children[0];
    TreeNode<double>* n2 = tree.get_root()->children[1];
    tree.add_sub_node(n1, 1.4);
    tree.add_sub_node(n1, 1.5);
    tree.add_sub_node(n2, 1.6);

    // The tree should look like:
    /**
     *       root = 1.1
     *     /       \
     *    1.2      1.3
     *   /  \      /
     *  1.4  1.5  1.6
     */

    cout << "Pre-Order: ";
    for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Post-Order: ";
    for (auto it = tree.begin_post_order(); it != tree.end_post_order(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "In-Order: ";
    for (auto it = tree.begin_in_order(); it != tree.end_in_order(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "BFS: ";
    for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    Tree<double> three_ary_tree(3); // 3-ary tree.
    three_ary_tree.add_root(1.1);
    three_ary_tree.add_sub_node(three_ary_tree.get_root(), 1.2);
    three_ary_tree.add_sub_node(three_ary_tree.get_root(), 1.3);
    three_ary_tree.add_sub_node(three_ary_tree.get_root(), 1.4);
    three_ary_tree.add_sub_node(three_ary_tree.get_root()->children[0], 1.5);
    three_ary_tree.add_sub_node(three_ary_tree.get_root()->children[1], 1.6);

    cout << "3-ary Tree BFS: ";
    for (auto it = three_ary_tree.begin_bfs_scan(); it != three_ary_tree.end_bfs_scan(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    system("./TreeVisualizer");

    return 0;
}
