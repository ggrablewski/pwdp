#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf::Literals;

int main()
{
    const int fps = 60;  // frames per second czyli częstość odświeżania ekranu
    const int window_width = 800;
    const int window_height = 600;
    const auto video_mode = sf::VideoMode(sf::Vector2u(window_width, window_height));

    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;
    sf::RenderWindow window(video_mode, L"Moja animacja", sf::Style::Default, sf::State::Windowed, settings);

    window.setFramerateLimit(fps);

    sf::CircleShape tri(window_width / 4, 3);
    tri.setFillColor({128, 128, 255});
    tri.setOrigin({window_width / 4.0f, window_width / 4.0f});
    tri.setPosition({window_width / 2.0f, window_height / 2.0f});

    sf::CircleShape circ(window_width / 4, 100);
    circ.setOrigin({window_width / 4.0f, window_width / 4.0f});
    circ.setPosition({window_width / 2.0f, window_height / 2.0f});
    circ.setFillColor(sf::Color::Transparent);
    circ.setOutlineColor(sf::Color::Yellow);
    circ.setOutlineThickness(1.5f);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        window.clear(sf::Color::Black);
        window.draw(tri);
        window.draw(circ);
        window.display();
        tri.rotate(6_deg / fps);
    }
}
