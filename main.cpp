#include <SFML/Graphics.hpp>

//  Avoid using namespace at all

int main()
{
    // Creating a render window
    //  We are gonna keep the main window in 720p i.e 1280x720 px and in Windowed mode
    // Here window is an object of class RenderWindow and constructor called

    sf::RenderWindow window(sf::VideoMode(1280, 720), "Dinosour Game", sf::Style::Close);
    // We will set the framerate to 60 for the current application
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
    sf::CircleShape circle(100.f);

    //  Now we will use this object to imply certain conditions
    while (window.isOpen())
    {
        //  Event handling
        sf::Event event;
        while (window.pollEvent(event))
        {
            //  Close window
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
        }

        //  Clear the window
        window.clear();

        // Draw Stuffs here

        //  Display the window
        window.display();
    }

    return 0;
}