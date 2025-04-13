#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf::Literals;

int main()
{
    const auto video_mode = sf::VideoMode(sf::Vector2u(800, 600));
    sf::RenderWindow window(video_mode, L"Moje okno z kształtami");

    sf::CircleShape circle(120.0f);
    sf::RectangleShape rect(sf::Vector2f{200.0f, 300.0f});
    sf::CircleShape tri(200.0f, 3);
    sf::ConvexShape convex(6);
    sf::RectangleShape line({120, 2});

    circle.setFillColor(sf::Color::Red);
    rect.setFillColor({255, 255, 0});
    tri.setFillColor({128, 128, 64});
    convex.setFillColor({128, 0, 255, 128});
    line.setFillColor({0, 255, 255});

    circle.setPosition({10, 10});
    rect.setPosition({500, 10});
    tri.setPosition({20, 150});
    convex.setPosition({450, 300});
    line.setPosition({130, 130});

    convex.setPoint(0, {100.f, 10.f});
    convex.setPoint(1, {140.f, 100.f});
    convex.setPoint(2, {200.f, 190.f});
    convex.setPoint(3, {100.f, 260.f});
    convex.setPoint(4, {10.f, 190.f});
    convex.setPoint(5, {70.f, 100.f});

    rect.setRotation(sf::degrees(15.0f));
    line.setRotation(sf::radians(0.25 * 3.141592f));
    tri.setRotation(10_deg);
    convex.setRotation(-0.125_rad);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        window.clear(sf::Color::Black);

        window.draw(circle);
        window.draw(rect);
        window.draw(tri);
        window.draw(convex);
        window.draw(line);

        window.display();
    }
}
