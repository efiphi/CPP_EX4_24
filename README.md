# CPP_EX4_24 - Tree Data Structure Implementation
## Introduction

This project implements various types of tree data structures with support for different data types such as int, double, Complex, std::string, and char. The implementation includes tree traversal methods, tree operations, and the ability to convert a binary tree to a min-heap. The project is programmed in C++ and is designed to demonstrate the core functionalities of tree data structures, including traversal and manipulation.
Class Hierarchy

The project is structured into several classes, each representing different parts of the tree data structure:
TreeNode

Represents a node in the tree.

    Attributes:
        value: The value of the node.
        children: A vector of child nodes.

    Methods:
        TreeNode(T val): Constructor to initialize the node with a value.
        addChild(TreeNode<T>* child): Adds a child to the node.

## Tree

Represents the tree structure.

    Attributes:
        root: The root node of the tree.
        k: Maximum number of children a node can have.

    Methods:
        Tree(int max_children): Constructor to initialize the tree with a specified maximum number of children.
        add_root(T value): Adds the root node to the tree.
        add_sub_node(TreeNode<T>* parent, T value): Adds a child node to the specified parent node.
        get_root(): Returns the root node of the tree.
        begin_pre_order(), end_pre_order(): Iterators for pre-order traversal.
        begin_post_order(), end_post_order(): Iterators for post-order traversal.
        begin_in_order(), end_in_order(): Iterators for in-order traversal.
        begin_bfs_scan(), end_bfs_scan(): Iterators for breadth-first search (BFS) traversal.
        begin_dfs_scan(), end_dfs_scan(): Iterators for depth-first search (DFS) traversal.
        myHeap(): Converts the tree to a min-heap.
        draw(sf::RenderWindow&, const sf::Font&) const: Draws the tree using SFML.

## Complex

Represents a complex number.

    Attributes:
        real: The real part of the complex number.
        imag: The imaginary part of the complex number.

    Methods:
        Complex(double r = 0, double i = 0): Constructor to initialize the complex number.
        get_real(): Returns the real part of the complex number.
        get_imag(): Returns the imaginary part of the complex number.
        to_string(): Returns a string representation of the complex number.

    Operators:
        operator<<: Overloads the insertion operator for outputting the complex number.
        operator==: Checks if two complex numbers are equal.
        operator!=: Checks if two complex numbers are not equal.
        operator<: Checks if one complex number is less than another.
        operator>: Checks if one complex number is greater than another.


## Tree Traversal Iterators

Provides iterators for different types of tree traversals:

    PreOrderIterator: Pre-order traversal.
    PostOrderIterator: Post-order traversal.
    InOrderIterator: In-order traversal.
    BFSIterator: Breadth-first search (BFS) traversal.
    DFSIterator: Depth-first search (DFS) traversal.

## Libraries Used

    <iostream>: For input and output operations.
    <vector>: For using dynamic arrays.
    <map>: For mapping data types.
    <string>: For handling string operations.
    <sstream>: For string stream operations.
    <SFML/Graphics.hpp>: For graphical rendering using SFML.
    <doctest.h>: For unit testing.

## How to Run
Clone the repository:

bash

    git clone https://github.com/efiphi/CPP_EX4_24.git

Navigate to the project directory:

bash

    cd CPP_EX4_24

Build the project:

bash

    make
    make test

Run the main program:

bash

    ./tree

Run the tests:

bash

    ./test

Authors

    Efi Phillips
    efiphi10@gmail.com
