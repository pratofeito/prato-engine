#ifndef PTE_ASSET_MANAGER_HPP
#define PTE_ASSET_MANAGER_HPP

#include <map>
#include <iostream>
#include <SFML/Graphics.hpp>

namespace pte {
    class AssetManager
    {
        private:
            std::map<std::string, sf::Texture> textures;
            std::map<std::string, sf::Font> fonts;

        public:
            AssetManager() {}
            ~AssetManager() {}

            void load_texture(std::string name, std::string file_name);
            sf::Texture &get_texture(std::string name);
            
            void load_font(std::string name, std::string file_name);
            sf::Font &get_font(std::string name);
    };
}

#endif