#include <asset_manager.hpp>

engine::AssetManager::AssetManager()
{
}

engine::AssetManager::~AssetManager()
{
}

void engine::AssetManager::loadTexture(int id, const std::string &filename, bool wantRepeated)
{
    //  At first we create a variable of type sf::Texture and then we load the Texture from the file.
    //  If the Texture is loaded successfully, we store it in the map using the id as a key.
    //  Std::unique_ptr is used to ensure that the memory is freed when the object is destroyed.
    //  std::move is used to move the unique_ptr into the map. 
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
    //  At first we create a variable of type sf::Font and then we load the font from the file.
    //  If the font is loaded successfully, we store it in the map using the id as a key.
    //  Std::unique_ptr is used to ensure that the memory is freed when the object is destroyed.
    //  std::move is used to move the unique_ptr into the map. 
    auto font = std::make_unique<sf::Font>();

    if (font->loadFromFile(filename))
    {

        m_fonts[id] = std::move(font);
    }
}

//  These function will return the reference to the texture stored in the map
const sf::Texture &engine::AssetManager::getTexture(int id) const
{
    return *(m_textures.at(id)).get();
}
//  These function will return the reference to the font stored in the map
const sf::Font &engine::AssetManager::getFont(int id) const
{
    return *(m_fonts.at(id)).get();
}