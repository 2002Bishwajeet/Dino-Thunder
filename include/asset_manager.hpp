#pragma once

#include <map>
#include <memory>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>

namespace engine
{
    class AssetManager
    {
    private:
        std::map<int, std::unique_ptr<sf::Texture>> m_textures;
        std::map<int, std::unique_ptr<sf::Font>> m_fonts;

    public:
        AssetManager();
        ~AssetManager();

        void loadTexture(int id, const std::string &filename, bool wantRepeated = false);
        void loadFont(int id, const std::string &filename);

        const sf::Texture &getTexture(int id) const;
        const sf::Font &getFont(int id) const;
    };

} // namespace engine
