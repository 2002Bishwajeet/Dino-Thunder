#include <asset_manager.hpp>

engine::AssetManager::AssetManager()
{
}

engine::AssetManager::~AssetManager()
{
}

void engine::AssetManager::loadTexture(int id, const std::string &filename, bool wantRepeated = false)
{
    auto texture = std::make_unique<sf::Texture>();

    if (texture->loadFromFile(filename))
    {
        if (wantRepeated)
        {
            texture->setRepeated(true);
        }

        m_textures[id] = std::move(texture);
    }
}
void engine::AssetManager::loadFont(int id, const std::string &filename)
{
    auto font = std::make_unique<sf::Font>();

    if (font->loadFromFile(filename))
    {

        m_fonts[id] = std::move(font);
    }
}

const sf::Texture &engine::AssetManager::getTexture() const {
    return *(m_textures.at(id)).get();
}
const sf::Font &engine::AssetManager::getFont() const
{
    return *(m_fonts.at(id)).get();
}