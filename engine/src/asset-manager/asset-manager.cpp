#include "asset-manager/asset-manager.hpp"

namespace pte
{
    // Texture
    void AssetManager::load_texture(std::string name, std::string file_name)
    {
        sf::Texture texture;

        if (texture.loadFromFile(file_name))
        {
            this->textures[name] = texture;
        }
        else
        {
            std::cout << "error loading texture " << file_name << std::endl;
        }
    }

    sf::Texture &AssetManager::get_texture(std::string name)
    {
        return this->textures.at(name); 
    }

    // Font
    void AssetManager::load_font(std::string name, std::string file_name)
    {
        sf::Font font;

        if (font.loadFromFile(file_name))
        {
            this->fonts[name] = font;
        }
        else
        {
            std::cout << "error loading font " << file_name << std::endl;
        }
    }

    sf::Font &AssetManager::get_font(std::string name)
    {
        return this->fonts.at(name); 
    }
}