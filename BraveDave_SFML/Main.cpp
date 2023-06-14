#include <iostream>
#include <SFML/Graphics.hpp>
#include "Level.h"
#include <conio.h>

using namespace sf;

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Brave Dave");
    window.setFramerateLimit(60);

    GameObject titleScreen;
    titleScreen.setTexture("resources/Pictures/background.png");
    GameObject translucent;
    translucent.setTexture("resources/pictures/translucent.png");

    Level game;
    game.titleMusic.play();
    Clock time;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.key.code == Keyboard::Enter)
            {
                game.titleDraw = false;
                game.levelDraw = true;
                game.titleMusic.stop();
                game.level_number = 1;
            }
        }

        if (game.level_number == 1 && game.levelLoaded == false)
        {
            game.ClearLevelDrawings();
            game.musicLevel1.play();
            game.loadLevel_1();
        }

        if (game.level_number == 2 && game.levelLoaded == false)
        {
            game.ClearLevelDrawings();
            game.musicLevel1.stop();
            game.musicLevel2.play();
            game.loadLevel_2();
        }

        if (game.level_number == 3 && game.levelLoaded == false)
        {
            game.ClearLevelDrawings();
            game.musicLevel2.stop();
            game.musicLevel3.play();
            game.loadLevel_3();
        }

        window.clear();

        if (game.titleDraw)
            titleScreen.Draw(window);

        if (game.levelDraw)
            game.Draw(window, time, event);

        if (game.end == true)
        {
            game.musicLevel3.stop();
            translucent.Draw(window);
            window.draw(game.theEnd);
        }

        window.display();

        try
        { }
        catch (...)
        {
            std::cerr << "An unhandled exceotion is caught" << std::endl;
            return 0;
        }
    }

    return 0;
}