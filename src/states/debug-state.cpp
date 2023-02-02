#include "states/debug-state.hpp"

void DebugState::init()
{
    namespace filesys = std::filesystem;
    // set framerate
    window->setFramerateLimit(60);

    // initialize ImGui
    ImGui::SFML::Init(*window);
    ImGui::NewFrame();
    dtTime = sf::Clock();

    // set view
    view = sf::View(sf::FloatRect(200, 200, 320, 240));

    // find textures
    std::string path = filesys::current_path();
    for (const auto &entry : filesys::directory_iterator(path + "/resources"))
    {
        if (!filesys::is_directory(entry))
        {
            std::string fileName = entry.path().filename();
            names.push_back(fileName);
        }
    }
}

void DebugState::handle_input()
{
    sf::Event event;
    while (window->pollEvent(event))
    {
        ImGui::SFML::ProcessEvent(*window, event);

        if (sf::Event::Closed == event.type)
        {
            window->close();
        }
    }
}

void DebugState::update(float delta_time)
{
    // Mouse coordinates
    sf::Vector2i pixelPos = sf::Mouse::getPosition(*window);
    sf::Vector2f worldPos = window->mapPixelToCoords(pixelPos, view);

    // update ImGui
    sf::Time time(dtTime.restart());
    ImGui::SFML::Update(*window, time);
    ImGui::Begin("Debug mode");
    ImGui::Button("This is the debug mode.");
    ImGui::Text("World coord: %f %f", worldPos.x, worldPos.y);
    static int currentItem = 2;

    // COMBO
    static int item_current_id = 0;
    const char *preview_value = names[item_current_id].c_str();
    if (ImGui::BeginCombo("Sprite Combo", preview_value))
    {
        for (int n = 0; n < names.size(); n++)
        {
            const bool is_selected = (item_current_id == n);
            if (ImGui::Selectable(names[n].c_str(), is_selected))
                item_current_id = n;
            if (is_selected)
                ImGui::SetItemDefaultFocus();
        }
        ImGui::EndCombo();
    }
    ImGui::End();
    ImGui::EndFrame();
}

void DebugState::draw(float delta_time)
{
    window->clear(sf::Color(56, 42, 55));
    // view
    window->setView(view);
    ImGui::SFML::Render(*window);

    window->display();
}