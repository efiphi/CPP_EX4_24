//efiphi10@gmail.com
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

    SUBCASE("DFS Traversal") {
        std::vector<int> result;
        for (auto it = intTree.begin_dfs_scan(); it != intTree.end_dfs_scan(); ++it) {
            result.push_back(*it);
        }
        std::vector<int> expected = {1, 2, 4, 5, 3, 6};
        CHECK(result == expected);
    }

     SUBCASE("Heap Functionality") {
        intTree.myHeap();
        std::vector<int> result;
        for (auto it = intTree.begin_bfs_scan(); it != intTree.end_bfs_scan(); ++it) {
            result.push_back(*it);
        }
        std::vector<int> expected = {1, 2, 3, 4, 5, 6}; 
        CHECK(result == expected);
    }


    SUBCASE("Tree Structure Check") {
        CHECK(root->value == 1);
        CHECK(root->children.size() == 2);
        CHECK(root->children[0]->value == 2);
        CHECK(root->children[1]->value == 3);
    }
}

TEST_CASE("Testing the Tree<double>") {
    Tree<double> doubleTree;
    doubleTree.add_root(1.1);
    TreeNode<double>* root = doubleTree.get_root();
    doubleTree.add_sub_node(root, 2.2);
    doubleTree.add_sub_node(root, 3.3);
    TreeNode<double>* n1 = root->children[0];
    TreeNode<double>* n2 = root->children[1];
    doubleTree.add_sub_node(n1, 4.4);
    doubleTree.add_sub_node(n1, 5.5);
    doubleTree.add_sub_node(n2, 6.6);

    SUBCASE("Pre-Order Traversal") {
        std::vector<double> result;
        for (auto it = doubleTree.begin_pre_order(); it != doubleTree.end_pre_order(); ++it) {
            result.push_back(*it);
        }
        std::vector<double> expected = {1.1, 2.2, 4.4, 5.5, 3.3, 6.6};
        CHECK(result == expected);
    }

    SUBCASE("Post-Order Traversal") {
        std::vector<double> result;
        for (auto it = doubleTree.begin_post_order(); it != doubleTree.end_post_order(); ++it) {
            result.push_back(*it);
        }
        std::vector<double> expected = {4.4, 5.5, 2.2, 6.6, 3.3, 1.1};
        CHECK(result == expected);
    }

    SUBCASE("In-Order Traversal") {
        std::vector<double> result;
        for (auto it = doubleTree.begin_in_order(); it != doubleTree.end_in_order(); ++it) {
            result.push_back(*it);
        }
        std::vector<double> expected = {4.4, 2.2, 5.5, 1.1, 6.6, 3.3};
        CHECK(result == expected);
    }

    SUBCASE("BFS Traversal") {
        std::vector<double> result;
        for (auto it = doubleTree.begin_bfs_scan(); it != doubleTree.end_bfs_scan(); ++it) {
            result.push_back(*it);
        }
        std::vector<double> expected = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};
        CHECK(result == expected);
    }

    SUBCASE("DFS Traversal") {
        std::vector<double> result;
        for (auto it = doubleTree.begin_dfs_scan(); it != doubleTree.end_dfs_scan(); ++it) {
            result.push_back(*it);
        }
        std::vector<double> expected = {1.1, 2.2, 4.4, 5.5, 3.3, 6.6};
        CHECK(result == expected);
    }

    SUBCASE("Heap Functionality") {
        doubleTree.myHeap();
        std::vector<double> result;
        for (auto it = doubleTree.begin_bfs_scan(); it != doubleTree.end_bfs_scan(); ++it) {
            result.push_back(*it);
        }
        std::vector<double> expected = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6}; 
        CHECK(result == expected);
    }



    SUBCASE("Tree Structure Check") {
        CHECK(root->value == 1.1);
        CHECK(root->children.size() == 2);
        CHECK(root->children[0]->value == 2.2);
        CHECK(root->children[1]->value == 3.3);
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

    SUBCASE("DFS Traversal") {
        std::vector<Complex> result;
        for (auto it = complexTree.begin_dfs_scan(); it != complexTree.end_dfs_scan(); ++it) {
            result.push_back(*it);
        }
        std::vector<Complex> expected = {Complex(1.0, 1.0), Complex(2.0, 2.0), Complex(4.0, 4.0), Complex(5.0, 5.0), Complex(3.0, 3.0), Complex(6.0, 6.0)};
        CHECK(result == expected);
    }

    SUBCASE("Heap Functionality") {
        complexTree.myHeap();
        std::vector<Complex> result;
        for (auto it = complexTree.begin_bfs_scan(); it != complexTree.end_bfs_scan(); ++it) {
            result.push_back(*it);
        }
        std::vector<Complex> expected = {Complex(1.0, 1.0), Complex(2.0, 2.0), Complex(3.0, 3.0), Complex(4.0, 4.0), Complex(5.0, 5.0), Complex(6.0, 6.0)}; 
        CHECK(result == expected);
    }


    SUBCASE("Tree Structure Check") {
        CHECK(root->value == Complex(1.0, 1.0));
        CHECK(root->children.size() == 2);
        CHECK(root->children[0]->value == Complex(2.0, 2.0));
        CHECK(root->children[1]->value == Complex(3.0, 3.0));
    }
}

TEST_CASE("Add Nodes for Tree<int>") {
    Tree<int> intTree;
    intTree.add_root(1);
    TreeNode<int>* root = intTree.get_root();
    intTree.add_sub_node(root, 2);
    intTree.add_sub_node(root, 3);

    // Adding more than max children should throw an exception
    CHECK_THROWS_AS(intTree.add_sub_node(root, 4), std::overflow_error);

    TreeNode<int>* n1 = root->children[0];
    intTree.add_sub_node(n1, 4);
    CHECK(n1->children.size() == 1);
    
}

TEST_CASE("Add Nodes for Tree<double>") {
    Tree<double> doubleTree;
    doubleTree.add_root(1.1);
    TreeNode<double>* root = doubleTree.get_root();
    doubleTree.add_sub_node(root, 2.2);
    doubleTree.add_sub_node(root, 3.3);

    // Adding more than max children should throw an exception
    CHECK_THROWS_AS(doubleTree.add_sub_node(root, 4.4), std::overflow_error);

    TreeNode<double>* n1 = root->children[0];
    doubleTree.add_sub_node(n1, 4.4);
    CHECK(n1->children.size() == 1);
    
}

TEST_CASE("Add Nodes for Tree<Complex>") {
    Tree<Complex> complexTree;
    complexTree.add_root(Complex(1.0, 1.0));
    TreeNode<Complex>* root = complexTree.get_root();
    complexTree.add_sub_node(root, Complex(2.0, 2.0));
    complexTree.add_sub_node(root, Complex(3.0, 3.0));

    // Adding more than max children should throw an exception
    CHECK_THROWS_AS(complexTree.add_sub_node(root, Complex(4.0, 4.0)), std::overflow_error);

    TreeNode<Complex>* n1 = root->children[0];
    complexTree.add_sub_node(n1, Complex(4.0, 4.0));
    CHECK(n1->children.size() == 1);
    
}

TEST_CASE("Testing the Tree<char>") {
    Tree<char> charTree;
    charTree.add_root('A');
    TreeNode<char>* root = charTree.get_root();
    charTree.add_sub_node(root, 'B');
    charTree.add_sub_node(root, 'C');
    TreeNode<char>* n1 = root->children[0];
    TreeNode<char>* n2 = root->children[1];
    charTree.add_sub_node(n1, 'D');
    charTree.add_sub_node(n1, 'E');
    charTree.add_sub_node(n2, 'F');

    SUBCASE("Pre-Order Traversal") {
        std::vector<char> result;
        for (auto it = charTree.begin_pre_order(); it != charTree.end_pre_order(); ++it) {
            result.push_back(*it);
        }
        std::vector<char> expected = {'A', 'B', 'D', 'E', 'C', 'F'};
        CHECK(result == expected);
    }

    SUBCASE("Post-Order Traversal") {
        std::vector<char> result;
        for (auto it = charTree.begin_post_order(); it != charTree.end_post_order(); ++it) {
            result.push_back(*it);
        }
        std::vector<char> expected = {'D', 'E', 'B', 'F', 'C', 'A'};
        CHECK(result == expected);
    }

    SUBCASE("In-Order Traversal") {
        std::vector<char> result;
        for (auto it = charTree.begin_in_order(); it != charTree.end_in_order(); ++it) {
            result.push_back(*it);
        }
        std::vector<char> expected = {'D', 'B', 'E', 'A', 'F', 'C'};
        CHECK(result == expected);
    }

    SUBCASE("BFS Traversal") {
        std::vector<char> result;
        for (auto it = charTree.begin_bfs_scan(); it != charTree.end_bfs_scan(); ++it) {
            result.push_back(*it);
        }
        std::vector<char> expected = {'A', 'B', 'C', 'D', 'E', 'F'};
        CHECK(result == expected);
    }

    SUBCASE("DFS Traversal") {
        std::vector<char> result;
        for (auto it = charTree.begin_dfs_scan(); it != charTree.end_dfs_scan(); ++it) {
            result.push_back(*it);
        }
        std::vector<char> expected = {'A', 'B', 'D', 'E', 'C', 'F'};
        CHECK(result == expected);
    }

    SUBCASE("Heap Functionality") {
        charTree.myHeap();
        std::vector<char> result;
        for (auto it = charTree.begin_bfs_scan(); it != charTree.end_bfs_scan(); ++it) {
            result.push_back(*it);
        }
        std::vector<char> expected = {'A', 'B', 'C', 'D', 'E', 'F'}; 
        CHECK(result == expected);
    }

    SUBCASE("Tree Structure Check") {
        CHECK(root->value == 'A');
        CHECK(root->children.size() == 2);
        CHECK(root->children[0]->value == 'B');
        CHECK(root->children[1]->value == 'C');
    }
}

TEST_CASE("Testing the Tree<std::string>") {
    Tree<std::string> stringTree;
    stringTree.add_root("root");
    TreeNode<std::string>* root = stringTree.get_root();
    stringTree.add_sub_node(root, "child1");
    stringTree.add_sub_node(root, "child2");
    TreeNode<std::string>* n1 = root->children[0];
    TreeNode<std::string>* n2 = root->children[1];
    stringTree.add_sub_node(n1, "child3");
    stringTree.add_sub_node(n1, "child4");
    stringTree.add_sub_node(n2, "child5");

    SUBCASE("Pre-Order Traversal") {
        std::vector<std::string> result;
        for (auto it = stringTree.begin_pre_order(); it != stringTree.end_pre_order(); ++it) {
            result.push_back(*it);
        }
        std::vector<std::string> expected = {"root", "child1", "child3", "child4", "child2", "child5"};
        CHECK(result == expected);
    }

    SUBCASE("Post-Order Traversal") {
        std::vector<std::string> result;
        for (auto it = stringTree.begin_post_order(); it != stringTree.end_post_order(); ++it) {
            result.push_back(*it);
        }
        std::vector<std::string> expected = {"child3", "child4", "child1", "child5", "child2", "root"};
        CHECK(result == expected);
    }

    SUBCASE("In-Order Traversal") {
        std::vector<std::string> result;
        for (auto it = stringTree.begin_in_order(); it != stringTree.end_in_order(); ++it) {
            result.push_back(*it);
        }
        std::vector<std::string> expected = {"child3", "child1", "child4", "root", "child5", "child2"};
        CHECK(result == expected);
    }

    SUBCASE("BFS Traversal") {
        std::vector<std::string> result;
        for (auto it = stringTree.begin_bfs_scan(); it != stringTree.end_bfs_scan(); ++it) {
            result.push_back(*it);
        }
        std::vector<std::string> expected = {"root", "child1", "child2", "child3", "child4", "child5"};
        CHECK(result == expected);
    }

    SUBCASE("DFS Traversal") {
        std::vector<std::string> result;
        for (auto it = stringTree.begin_dfs_scan(); it != stringTree.end_dfs_scan(); ++it) {
            result.push_back(*it);
        }
        std::vector<std::string> expected = {"root", "child1", "child3", "child4", "child2", "child5"};
        CHECK(result == expected);
    }

    SUBCASE("Tree Structure Check") {
        CHECK(root->value == "root");
        CHECK(root->children.size() == 2);
        CHECK(root->children[0]->value == "child1");
        CHECK(root->children[1]->value == "child2");
    }
}



