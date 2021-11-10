#pragma once

#include <map>
#include <memory>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include<SFML/Audio/Music.hpp>

//  This is a singleton class that manages all the assets
namespace engine
{
    class AssetManager
    {
    private:
    //  We will be using a map to store the assets
    //  So A map for textures and a map for fonts
    //  It's basically a map of ints to unique pointers
    // So we can use the int as a key to the asset
    //  and we can use the unique pointer as the value
    //  To know more about unique pointers, check out
    //  https://en.cppreference.com/w/cpp/memory/unique_ptr
    
        std::map<int, std::unique_ptr<sf::Texture>> m_textures;
        std::map<int, std::unique_ptr<sf::Font>> m_fonts;
        std::map<int,std::unique_ptr<sf::Music>> m_sounds;

    public:
        AssetManager();
        ~AssetManager();

        // Loads a texture from a file
        void loadTexture(int id, const std::string &filename, bool wantRepeated = false);

        // Loads a font from a file
        void loadFont(int id, const std::string &filename);

        // Loads a sound from a file
        void loadSound(int id, const std::string &filename);

        //  We will be using a smart pointer to return the asset
        const sf::Texture &getTexture(int id) const;
        const sf::Font &getFont(int id) const;
        const sf::Music &getSound(int id) const;
    };

} // namespace engine
