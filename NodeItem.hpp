//efiphi10@gmail.com
#ifndef NODEITEM_HPP
#define NODEITEM_HPP

#include <SFML/Graphics.hpp>
#include <string>

class NodeItem : public sf::CircleShape {
public:
    NodeItem(float radius, const std::string& text, const sf::Font& font);

    void draw(sf::RenderWindow& window);

private:
    sf::Text label;
};

#endif // NODEITEM_HPP
