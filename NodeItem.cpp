#include "NodeItem.hpp"

NodeItem::NodeItem(float radius, const std::string& text, const sf::Font& font)
    : sf::CircleShape(radius), label(text, font, radius / 2) {
    setOrigin(radius, radius); // Center the circle at the origin
    setOutlineColor(sf::Color::Black);
    setOutlineThickness(2);
    label.setFillColor(sf::Color::Black);
    label.setOrigin(label.getLocalBounds().width / 2, label.getLocalBounds().height / 2);
}

void NodeItem::draw(sf::RenderWindow& window) {
    window.draw(*this);
    label.setPosition(getPosition().x - label.getLocalBounds().width / 2, getPosition().y - label.getLocalBounds().height / 2);
    window.draw(label);
}
