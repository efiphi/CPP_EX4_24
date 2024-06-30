//efiphi10@gmail.com
#ifndef TREE_HPP
#define TREE_HPP

#include "TreeNode.hpp"
#include "PreOrderIterator.hpp"
#include "PostOrderIterator.hpp"
#include "InOrderIterator.hpp"
#include "BFSIterator.hpp"
#include "DFSIterator.hpp"
#include "NodeItem.hpp"
#include "Complex.hpp"
#include <stdexcept>
#include <vector>
#include <queue>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <sstream>

template <typename T>
class Tree {
private:
    TreeNode<T>* root;
    int k;
    void heapify(TreeNode<T>* node);

public:
    Tree(int max_children = 2);
    ~Tree();
    void add_root(T value);
    void add_sub_node(TreeNode<T>* parent, T value);
    void delete_tree(TreeNode<T>* node);
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
    void draw(sf::RenderWindow& window, const sf::Font& font) const;

private:
    void draw(sf::RenderWindow& window, TreeNode<T>* node, const sf::Font& font, int x, int y, int circleSize, int horizontalSpacing, int verticalSpacing, int depth) const;
    void position_nodes(TreeNode<T>* node, float x, float y, float horizontal_spacing, float vertical_spacing, std::map<TreeNode<T>*, sf::Vector2f>& positions) const;
};

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
    if (parent->children.size() >= k) {
        throw std::overflow_error("Max children reached");
    }
    parent->children.push_back(new TreeNode<T>(value));
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

template <typename T>
void Tree<T>::draw(sf::RenderWindow& window, const sf::Font& font) const {
    if (!root) return;

    const float node_radius = 25.f;
    const float vertical_spacing = 80.f;
    const float initial_horizontal_spacing = 200.f;

    std::map<TreeNode<T>*, sf::Vector2f> positions;
    position_nodes(root, window.getSize().x / 2.f, node_radius + 50.f, initial_horizontal_spacing, vertical_spacing, positions);

    for (const auto& pair : positions) {
        TreeNode<T>* node = pair.first;
        sf::Vector2f position = pair.second;

        sf::CircleShape circle(node_radius);
        circle.setFillColor(sf::Color::Yellow);
        circle.setPosition(position - sf::Vector2f(node_radius, node_radius));
        window.draw(circle);

        sf::Text text;
        text.setFont(font);
        if constexpr (std::is_same<T, Complex>::value) {
            text.setString(node->value.to_string());
        } else {
            text.setString(std::to_string(node->value));
        }
        text.setCharacterSize(16);
        text.setFillColor(sf::Color::Black);
        sf::FloatRect text_bounds = text.getLocalBounds();
        text.setOrigin(text_bounds.left + text_bounds.width / 2.0f, text_bounds.top + text_bounds.height / 2.0f);
        text.setPosition(position);
        window.draw(text);

        for (TreeNode<T>* child : node->children) {
            if (child) {
                sf::Vector2f child_position = positions[child];
                sf::Vertex line[] =
                {
                    sf::Vertex(position, sf::Color::Black),
                    sf::Vertex(child_position, sf::Color::Black)
                };
                window.draw(line, 2, sf::Lines);
            }
        }
    }
}

template <typename T>
void Tree<T>::position_nodes(TreeNode<T>* node, float x, float y, float horizontal_spacing, float vertical_spacing, std::map<TreeNode<T>*, sf::Vector2f>& positions) const {
    if (!node) return;

    positions[node] = sf::Vector2f(x, y);

    float child_x_offset = x - (node->children.size() - 1) * horizontal_spacing / 2.f;

    for (size_t i = 0; i < node->children.size(); ++i) {
        TreeNode<T>* child = node->children[i];
        if (child) {
            position_nodes(child, child_x_offset + i * horizontal_spacing, y + vertical_spacing, horizontal_spacing / 2.f, vertical_spacing, positions);
        }
    }
}

#endif // TREE_HPP
