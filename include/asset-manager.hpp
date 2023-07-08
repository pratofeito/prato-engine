/**
 * @file asset-manager.hpp
 * @date 2023-01-06
 *
 * @brief Tools to manage assets
 *
 */

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

            /**
             * @brief Load a texture
             * 
             * @param name descriptive name used to search texture later
             * @param file_name texture file path
             */
            void load_texture(std::string name, std::string file_name);

            /**
             * @brief Get the texture object
             * 
             * @param name name of the texture
             * @return sf::Texture& 
             */
            sf::Texture &get_texture(std::string name);
            
            /**
             * @brief Load a font
             * 
             * @param name descriptive name used to search font later
             * @param file_name font file path
             */
            void load_font(std::string name, std::string file_name);

            /**
             * @brief Get the font object
             * 
             * @param name name of the font
             * @return sf::Font& 
             */
            sf::Font &get_font(std::string name);
    };
}

#endif