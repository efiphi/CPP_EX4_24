#include "Tree.hpp"
#include "Complex.hpp"
#include "TreeNode.hpp"
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;

int main() {
    // Creating and populating a binary tree with doubles
    Tree<double> tree; // Binary tree that contains doubles.
    tree.add_root(1.1);

    tree.add_sub_node(tree.get_root(), 1.2);
    tree.add_sub_node(tree.get_root(), 1.3);
    TreeNode<double>* n1 = tree.get_root()->children[0];
    TreeNode<double>* n2 = tree.get_root()->children[1];
    tree.add_sub_node(n1, 1.4);
    tree.add_sub_node(n1, 1.5);
    tree.add_sub_node(n2, 1.6);

    // Pre-Order traversal
    cout << "Pre-Order: ";
    for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Post-Order traversal
    cout << "Post-Order: ";
    for (auto it = tree.begin_post_order(); it != tree.end_post_order(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // In-Order traversal
    cout << "In-Order: ";
    for (auto it = tree.begin_in_order(); it != tree.end_in_order(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // BFS traversal
    cout << "BFS: ";
    for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Demonstrating the 3-ary tree
    Tree<double> three_ary_tree(3);
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

    // Visualizing the binary tree
    sf::RenderWindow window(sf::VideoMode(800, 600), "Tree Visualization");
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error loading font" << std::endl;
        return 1;
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::White);
        tree.draw(window, font);
        window.display();
    }

    // Visualizing a k-ary tree with complex numbers
    Tree<Complex> complex_tree(3); // 3-ary tree with complex numbers.
    complex_tree.add_root(Complex(1, 1));
    complex_tree.add_sub_node(complex_tree.get_root(), Complex(2, 2));
    complex_tree.add_sub_node(complex_tree.get_root(), Complex(3, 3));
    complex_tree.add_sub_node(complex_tree.get_root(), Complex(4, 4));
    complex_tree.add_sub_node(complex_tree.get_root()->children[0], Complex(5, 5));
    complex_tree.add_sub_node(complex_tree.get_root()->children[0], Complex(6, 6));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::White);
        complex_tree.draw(window, font);
        window.display();
    }

    return 0;
}
