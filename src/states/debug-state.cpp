#include "states/debug-state.hpp"

void DebugState::init()
{
    namespace filesystem = std::filesystem;
    // set framerate
    window->setFramerateLimit(60);

    // initialize ImGui
    ImGui::SFML::Init(*window);
    ImGui::NewFrame();
    dtTime = sf::Clock();

    // set view
    view = sf::View(sf::FloatRect(200, 200, 320, 240));

    // find textures
    std::vector<std::string> stringNames;
    std::string path = filesystem::current_path();
    for (const auto &entry : filesystem::directory_iterator(path + "/resources"))
        stringNames.push_back(entry.path().filename());

    teste = stringNames;
    /* int n = stringNames.size();
    this->nameSize = n;
    this->names = new const char *[n];
    for (int i = 0; i < n; i++)
    {
        this->names[i] = stringNames[i].c_str();
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << this->names[i] << std::endl;
    } */
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

    /* ImGui::ListBoxHeader("Sprite Names", nameSize, -1);
    for (auto & item : teste) {

    }

        ImGui::ListBox("Sprite Names", &currentItem, names, nameSize, 4, ); */
    /* if (ImGui::ListBoxHeader("List", size))
    {
        ImGui::Selectable("Selected", true);
        ImGui::Selectable("Not Selected", false);
        ImGui::ListBoxFooter();
    } */
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