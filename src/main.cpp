#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>


int main()
{
    sf::Window window(sf::VideoMode(800, 600), "SMFL Starter");
    window.setVerticalSyncEnabled(false);
    //window.setFramerateLimit(0);
    
    // activate the window's context
    window.setActive(true);

    glEnable(GL_TEXTURE_2D);


    sf::Clock globalClock;
    bool running = true;

    while (running) {
        // Display FPS in the title bar
        float elapsed = globalClock.restart().asSeconds();
        window.setTitle("FPS:" + std::to_string(1.0f / elapsed));
        
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // check the type of the event...
            switch (event.type)
            {
                // window closed
                case sf::Event::Closed:
                    running = false;
                    break;
                // key pressed
                case sf::Event::KeyPressed:
                    break;
                case sf::Event::Resized:
                    std::cout << "new width: " << event.size.width << std::endl;
                    std::cout << "new height: " << event.size.height << std::endl;
                    // adjust the viewport when the window is resized
                    glViewport(0, 0, event.size.width, event.size.height);
                    break;
                // we don't process other types of events
                case sf::Event::LostFocus:
                case sf::Event::GainedFocus:
                default:
                    break;
            }
        }
        // Clear the buffers
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        // Draw
        
        // end the current frame (internally swaps the front and back buffers)
        window.display();
    }

    // deactivate the window's context
    window.setActive(false);

    window.close();

    return 0;
}