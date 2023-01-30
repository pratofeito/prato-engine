#include <iostream>
#include "engine/include/game.hpp"
#include "definitions.hpp"
#include "states/splash-state.hpp"
#include "states/game-state.hpp"
#include <SFML/Graphics.hpp>

// int main()
// {
//     // First, create a new game. Before starting, set initial state
//     pte::Game game = pte::Game(SCREEN_WIDTH, SCREEN_HEIGHT, "Demo");
//     game.init_state<GameState>();
//     game.run();

//     return 0;
// }

int main() {
    sf::RenderWindow window(sf::VideoMode(640, 480), "ImGui + SFML = <3");
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    sf::Clock deltaClock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(window, event);

            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        ImGui::SFML::Update(window, deltaClock.restart());

        ImGui::Begin("Hello, world!");
        ImGui::Button("Look at this pretty button");
        ImGui::End();

        window.clear();
        window.draw(shape);
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
}