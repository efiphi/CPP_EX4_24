#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Tree.hpp"
#include "Complex.hpp"

TEST_CASE("Testing the Tree<int>") {
    Tree<int> intTree;
    intTree.add_root(1);
    TreeNode<int>* root = intTree.get_root();
    intTree.add_sub_node(root, 2);
    intTree.add_sub_node(root, 3);
    TreeNode<int>* n1 = root->children[0];
    TreeNode<int>* n2 = root->children[1];
    intTree.add_sub_node(n1, 4);
    intTree.add_sub_node(n1, 5);
    intTree.add_sub_node(n2, 6);

    SUBCASE("Pre-Order Traversal") {
        std::vector<int> result;
        for (auto it = intTree.begin_pre_order(); it != intTree.end_pre_order(); ++it) {
            result.push_back(*it);
        }
        std::vector<int> expected = {1, 2, 4, 5, 3, 6};
        CHECK(result == expected);
    }

    SUBCASE("Post-Order Traversal") {
        std::vector<int> result;
        for (auto it = intTree.begin_post_order(); it != intTree.end_post_order(); ++it) {
            result.push_back(*it);
        }
        std::vector<int> expected = {4, 5, 2, 6, 3, 1};
        CHECK(result == expected);
    }

    SUBCASE("In-Order Traversal") {
        std::vector<int> result;
        for (auto it = intTree.begin_in_order(); it != intTree.end_in_order(); ++it) {
            result.push_back(*it);
        }
        std::vector<int> expected = {4, 2, 5, 1, 6, 3};
        CHECK(result == expected);
    }

    SUBCASE("BFS Traversal") {
        std::vector<int> result;
        for (auto it = intTree.begin_bfs_scan(); it != intTree.end_bfs_scan(); ++it) {
            result.push_back(*it);
        }
        std::vector<int> expected = {1, 2, 3, 4, 5, 6};
        CHECK(result == expected);
    }
}

TEST_CASE("Testing the Tree<Complex>") {
    Tree<Complex> complexTree;
    complexTree.add_root(Complex(1.0, 1.0));
    TreeNode<Complex>* root = complexTree.get_root();
    complexTree.add_sub_node(root, Complex(2.0, 2.0));
    complexTree.add_sub_node(root, Complex(3.0, 3.0));
    TreeNode<Complex>* n1 = root->children[0];
    TreeNode<Complex>* n2 = root->children[1];
    complexTree.add_sub_node(n1, Complex(4.0, 4.0));
    complexTree.add_sub_node(n1, Complex(5.0, 5.0));
    complexTree.add_sub_node(n2, Complex(6.0, 6.0));

    SUBCASE("Pre-Order Traversal") {
        std::vector<Complex> result;
        for (auto it = complexTree.begin_pre_order(); it != complexTree.end_pre_order(); ++it) {
            result.push_back(*it);
        }
        std::vector<Complex> expected = {Complex(1.0, 1.0), Complex(2.0, 2.0), Complex(4.0, 4.0), Complex(5.0, 5.0), Complex(3.0, 3.0), Complex(6.0, 6.0)};
        CHECK(result == expected);
    }

    SUBCASE("Post-Order Traversal") {
        std::vector<Complex> result;
        for (auto it = complexTree.begin_post_order(); it != complexTree.end_post_order(); ++it) {
            result.push_back(*it);
        }
        std::vector<Complex> expected = {Complex(4.0, 4.0), Complex(5.0, 5.0), Complex(2.0, 2.0), Complex(6.0, 6.0), Complex(3.0, 3.0), Complex(1.0, 1.0)};
        CHECK(result == expected);
    }

    SUBCASE("In-Order Traversal") {
        std::vector<Complex> result;
        for (auto it = complexTree.begin_in_order(); it != complexTree.end_in_order(); ++it) {
            result.push_back(*it);
        }
        std::vector<Complex> expected = {Complex(4.0, 4.0), Complex(2.0, 2.0), Complex(5.0, 5.0), Complex(1.0, 1.0), Complex(6.0, 6.0), Complex(3.0, 3.0)};
        CHECK(result == expected);
    }

    SUBCASE("BFS Traversal") {
        std::vector<Complex> result;
        for (auto it = complexTree.begin_bfs_scan(); it != complexTree.end_bfs_scan(); ++it) {
            result.push_back(*it);
        }
        std::vector<Complex> expected = {Complex(1.0, 1.0), Complex(2.0, 2.0), Complex(3.0, 3.0), Complex(4.0, 4.0), Complex(5.0, 5.0), Complex(6.0, 6.0)};
        CHECK(result == expected);
    }
}