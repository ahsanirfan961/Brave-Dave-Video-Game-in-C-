#include "Level.h"
#include "time.h"
#include "stdlib.h"
#include <string>

Level::Level() : numberOfPlatforms(0), key(false), end(false), levelLoaded(false), level_number(0)
{
   
    // setting the door
    door.setTexture("resources/pictures/door.png");
    Vector2f *textureSize = new Vector2f(door.texture.getSize());
    Vector2f *textureScale = new Vector2f(3, 3);
    Vector2f *tileSize = new Vector2f(textureScale->x * textureSize->x, textureScale->y * textureSize->y);
    door.setOrigin(textureSize->x / 2, textureSize->y / 2);
    door.setTextureSource(0, 0, textureSize->x, textureSize->y);
    door.setTextureRepitition(false);
    door.setScale(textureScale->x, textureScale->y);
    delete textureScale, textureSize, tileSize;

    // setting the player
    dave.setTexture("resources/pictures/Dave_Idle.png");
    textureSize = new Vector2f(dave.texture.getSize());
    textureScale = new Vector2f(1.2, 1.2);
    dave.setOrigin(textureSize->x / (2*6), textureSize->y / 2);
    dave.setSpeed(5);
    dave.setTextureSource(0, 0, textureSize->x / 6, textureSize->y);
    dave.setScale(textureScale->x, textureScale->y);
    dave.setNumOfAnimation(3);
    // walking animation
    dave.animation[0].setSpeed(5);
    dave.animation[0].set_n_images(6);
    dave.animation[0].setWidth("resources/pictures/Dave_Walk.png");
    dave.animation[0].setSound("resources/audio/Footstep.ogg");
    dave.animation[0].sound.setVolume(100);
    // jumping animation
    dave.animation[1].setSpeed(5);
    dave.animation[1].set_n_images(1);
    dave.animation[1].setWidth("resources/pictures/Dave_Jump.png");
    dave.setHealth(3);
    dave.gravity.setGravitionalAcceleration(1);
    delete textureScale, textureSize;

    // setting start
    // start.setTexture("resources/pictures/start.png");
    // textureSize = new Vector2f(start.texture.getSize());
    // textureScale = new Vector2i(1, 1);
    // tileSize = new Vector2f(textureScale->x * textureSize->x, textureScale->y * textureSize->y);
    // start.setOrigin(textureSize->x / 2, textureSize->y / 2);
    // start.setTextureSource(0, 0, textureSize->x, textureSize->y);
    // start.setTextureRepitition(false);
    // start.setScale(textureScale->x, textureScale->y);
    // delete textureScale, textureSize, tileSize;

    // setting the cup
    cup.setTexture("resources/pictures/cup1.png");
    textureSize = new Vector2f(cup.texture.getSize());
    textureScale = new Vector2f(3, 3);
    tileSize = new Vector2f(textureScale->x * textureSize->x, textureScale->y * textureSize->y);
    cup.setOrigin(textureSize->x / 2, textureSize->y / 2);
    cup.setTextureSource(0, 0, textureSize->x, textureSize->y);
    cup.setTextureRepitition(false);
    cup.setScale(textureScale->x, textureScale->y);
    delete textureScale, textureSize, tileSize;

    // setting the monster
    monster.setTexture("resources/pictures/monster.png");
    textureSize = new Vector2f(monster.texture.getSize());
    textureScale = new Vector2f(3, 3);
    tileSize = new Vector2f(textureScale->x * textureSize->x, textureScale->y * textureSize->y);
    monster.setOrigin(textureSize->x / 2, textureSize->y / 2);
    monster.setTextureSource(0, 0, textureSize->x, textureSize->y);
    monster.setTextureRepitition(false);
    monster.setScale(textureScale->x, textureScale->y);
    delete textureScale, textureSize, tileSize;

    // setting the gun
    gun.setTexture("resources/pictures/gun.png");
    textureSize = new Vector2f(gun.texture.getSize());
    textureScale = new Vector2f(2, 2);
    tileSize = new Vector2f(textureScale->x * textureSize->x, textureScale->y * textureSize->y);
    gun.setOrigin(textureSize->x / 2, textureSize->y / 2);
    gun.setTextureSource(0, 0, textureSize->x, textureSize->y);
    gun.setTextureRepitition(false);
    gun.setScale(textureScale->x, textureScale->y);
    delete textureScale, textureSize, tileSize;

    // setting the bullet
    bullet.setTexture("resources/pictures/monsterBullet.png");
    textureSize = new Vector2f(bullet.texture.getSize());
    textureScale = new Vector2f(2, 2);
    tileSize = new Vector2f(textureScale->x * textureSize->x, textureScale->y * textureSize->y);
    bullet.setOrigin(textureSize->x / 2, textureSize->y / 2);
    bullet.setTextureSource(0, 0, textureSize->x, textureSize->y);
    bullet.setTextureRepitition(false);
    bullet.setScale(textureScale->x, textureScale->y);
    delete textureScale, textureSize, tileSize;

    // setting the lives
    for (int i = 0; i < dave.getHealth(); i++)
    {
        GameObject *a = new GameObject;
        a->setTexture("resources/pictures/heart1.png");
        textureSize = new Vector2f(a->texture.getSize());
        textureScale = new Vector2f(1, 1);
        tileSize = new Vector2f(textureScale->x * textureSize->x, textureScale->y * textureSize->y);
        a->setTextureSource(0, 0, textureSize->x, textureSize->y);
        a->setTextureRepitition(false);
        a->setScale(textureScale->x, textureScale->y);
        a->setPosition(21.5 * 72 + i * tileSize->x * 1.5, 10);
        delete textureScale, textureSize, tileSize;
        hearts.push_back(a);
    }

    // setting level draw and title draw
    levelDraw = false;
    titleDraw = true;

    // setting music for titlescreen
    if (title.loadFromFile("resources/Audio/Title.wav"))
        std::cout << "error";
    titleMusic.setBuffer(title);
    titleMusic.setLoop(true);
    titleMusic.setVolume(50);

    // setting music for level 1
    level1.loadFromFile("resources/Audio/level1.flac");
    musicLevel1.setBuffer(level1);
    musicLevel1.setLoop(true);
    musicLevel1.setVolume(30);

    // setting music for level 2
    level2.loadFromFile("resources/Audio/level2.flac");
    musicLevel2.setBuffer(level2);
    musicLevel2.setLoop(true);
    musicLevel2.setVolume(30);

    // setting music for level 3
    level3.loadFromFile("resources/Audio/level3.flac");
    musicLevel3.setBuffer(level3);
    musicLevel3.setLoop(true);
    musicLevel3.setVolume(30);

    // setting sound of collectibles
    collect.loadFromFile("resources/Audio/collect.wav");
    collectable.setBuffer(collect);
    collectable.setVolume(80);

    // setting sound for cup
    if (!bufferCup.loadFromFile("resources/Audio/cup.wav"))
        std::cout << "error loading cup sound";
    soundCup.setBuffer(bufferCup);
    soundCup.setVolume(100);
}

void Level::loadRedGem()
{
    Texture redGem;
    redGem.loadFromFile("resources/pictures/redDiamonds.png");
    Vector2i *textureScale = new Vector2i(3, 3);
    Vector2f *textureSize = new Vector2f(redGem.getSize());
    Vector2f *tileSize = new Vector2f(textureScale->x * textureSize->x, textureScale->y * textureSize->y);
    DynamicObject *g = new DynamicObject;
    g->setTexture("resources/pictures/redDiamonds.png");
    g->setOrigin(textureSize->x / 2, textureSize->y / 2);
    g->setTextureSource(0, 0, textureSize->x, textureSize->y);
    g->setTextureRepitition(false);
    g->setScale(textureScale->x, textureScale->y);
    gems.push_back(g);
    gemsType.push_back('r');
}

void Level::loadBlueGem()
{
    Texture blueGem;
    blueGem.loadFromFile("resources/pictures/diamonds.png");
    Vector2i *textureScale = new Vector2i(3, 3);
    Vector2f *textureSize = new Vector2f(blueGem.getSize());
    Vector2f *tileSize = new Vector2f(textureScale->x * textureSize->x, textureScale->y * textureSize->y);
    DynamicObject *g = new DynamicObject;
    g->setTexture("resources/pictures/diamonds.png");
    g->setOrigin(textureSize->x / 2, textureSize->y / 2);
    g->setTextureSource(0, 0, textureSize->x, textureSize->y);
    g->setTextureRepitition(false);
    g->setScale(textureScale->x, textureScale->y);
    gems.push_back(g);
    gemsType.push_back('b');
}

void Level::loadWeed()
{
    Texture weedTexture;
    weedTexture.loadFromFile("resources/pictures/weed1.png");
    Vector2i *textureScale = new Vector2i(3, 3);
    Vector2f *textureSize = new Vector2f(weedTexture.getSize());
    Vector2f *tileSize = new Vector2f(textureScale->x * textureSize->x, textureScale->y * textureSize->y);
    DynamicObject *w = new DynamicObject;
    w->setTexture("resources/pictures/weed.png");
    w->setOrigin(textureSize->x / 2, textureSize->y / 2);
    w->setTextureSource(0, 0, textureSize->x, textureSize->y);
    w->setTextureRepitition(false);
    w->setScale(textureScale->x, textureScale->y);
    w->setNumOfAnimation(1);
    w->animation[0].set_n_images(4);
    w->animation[0].setSpeed(5);
    w->animation[0].setWidth("resources/pictures/weed.png");
    weed_fire.push_back(w);
}

void Level::loadFire()
{
    Texture weedTexture;
    weedTexture.loadFromFile("resources/pictures/fire1.png");
    Vector2i *textureScale = new Vector2i(3, 12);
    Vector2f *textureSize = new Vector2f(weedTexture.getSize());
    Vector2f *tileSize = new Vector2f(textureScale->x * textureSize->x, textureScale->y * textureSize->y);
    DynamicObject *w = new DynamicObject;
    w->setTexture("resources/pictures/fire.png");
    w->setOrigin(textureSize->x / 2, textureSize->y / 2);
    w->setTextureSource(0, 0, textureSize->x, textureSize->y);
    w->setTextureRepitition(false);
    w->setScale(textureScale->x, textureScale->y);
    w->setNumOfAnimation(1);
    w->animation[0].set_n_images(4);
    w->animation[0].setSpeed(5);
    w->animation[0].setWidth("resources/pictures/fire.png");
    weed_fire.push_back(w);
}

void Level::setNumOfPlatforms(int n)
{

    int platformSize = platform.size();
    numberOfPlatforms = n;

    if (n > platformSize)
    {
        for (int i = 0; i < (n - platformSize); i++)
        {
            GameObject *p = new GameObject;
            platform.push_back(p);
        }
    }
    if (n < platformSize)
    {
        for (int i = 0; i < (-n + platformSize); i++)
            platform.pop_back();
    }
}

void Level::checkCollisions(bool face[5], double deltaTime)
{
    for (int i = 0; i < 5; i++)
        face[i] = false;

    // check collision with platforms
    for (int i = 0; i < numberOfPlatforms; i++)
    {
        Vector2i temp = dave.collider ^ platform[i]->collider;
        if (temp.x)
        {
            face[temp.x] = true;
        }
        if (temp.y)
        {
            face[temp.y] = true;
        }
    }

    // check collisions with gems
    Texture blue, red;
    blue.loadFromFile("resources/pictures/diamonds.png");
    red.loadFromFile("resources/pictures/redDiamonds.png");
    for (int i = 0; i < gems.size(); i++)
    {
        if ((dave.collider ^ gems[i]->collider).x || (dave.collider ^ gems[i]->collider).y)
        {
            if (gemsType[i] == 'b')
                dave.setPoints(dave.getPoints() + 50);
            if (gemsType[i] == 'r')
                dave.setPoints(dave.getPoints() + 100);
            collectable.play();
            gems.erase(gems.begin() + i);
            gemsType.erase(gemsType.begin() + i);
        }
    }

    // check collision with cup
    if ((dave.collider ^ cup.collider).x || (dave.collider ^ cup.collider).y)
    {
        key = true;
        dave.setPoints(dave.getPoints() + 500);
        soundCup.play();
        cup.setScale(0, 0);
        cup.setPosition(0, 0);
    }

    // check collision with weed/fire
    for (DynamicObject *w : weed_fire)
    {
        if ((dave.collider ^ w->collider).x || (dave.collider ^ w->collider).y)
        {
            static double totalTime = 2;
            if (totalTime >= 2)
            {
                dave.setHealth(dave.getHealth() - 1);
                try {
                    if (hearts.at(0))
                        hearts.pop_back();
                }
                catch (const std::out_of_range& e) {
                    end = true;
                }
                totalTime = 0;
            }
            else
                totalTime += deltaTime;
        }
    }

    // check collision with monster
    if ((dave.collider ^ monster.collider).x || (dave.collider ^ monster.collider).y)
    {
        static double totalTime = 2;
        if (totalTime >= 2)
        {
            dave.setHealth(dave.getHealth() - 2);
            try {
                if (hearts.at(1))
                    hearts.pop_back();
                if (hearts.at(0))
                    hearts.pop_back();
            }
            catch (const std::out_of_range& e) {
                end = true;
            }
            totalTime = 0;
        }
        else
            totalTime += deltaTime;
    }

    // check collision with gun
    if ((dave.collider ^ gun.collider).x || (dave.collider ^ gun.collider).y)
    {
        dave.setGunStatus(true);
        gun.setScale(0, 0);
        gun.setPosition(0, 0);
    }

    // bullet x monster
    if ((monster.collider ^ bullet.collider).x || (monster.collider ^ bullet.collider).y)
    {
        monster.setScale(0, 0);
        monster.setPosition(0, 0);
        bullet.setPosition(-bullet.getSize().x - 50, 0);
    }
}

void Level::checkLevelEnd()
{
    // check collision with door
    if (((dave.collider ^ door.collider).x || (dave.collider ^ door.collider).y) && key)
    {
        dave.setScale(dave.getScale().x - 0.1, dave.getScale().y - 0.1);
    }
    if (dave.getScale().x < 1 && dave.getScale().y < 1)
    {
        if (key) {
            level_number++;
            key = false;
        }
        if (level_number == 4)
            end = true;
        levelLoaded = false;
        dave.setScale(1.2, 1.2);
    }
}

void Level::loadText()
{
    double textSize = 36;

    // setting font
    font.loadFromFile("resources/fonts/SuperMario256.ttf");

    // setting Score text
    Score.setString("Score : ");
    Score.setFillColor(Color::White);
    Score.setPosition(Vector2f(72, 10));
    Score.setCharacterSize(textSize);
    Score.setFont(font);
    Score.setOutlineThickness(4);
    Score.setOutlineColor(Color::Red);

    // setting score
    score.setFillColor(Color::White);
    score.setPosition(Vector2f(3.5 * 72, 10));
    score.setCharacterSize(textSize);
    score.setFont(font);
    score.setOutlineThickness(4);
    score.setOutlineColor(Color::Red);

    // setting level text
    Level_text.setString("Level : ");
    Level_text.setFillColor(Color::White);
    Level_text.setPosition(Vector2f(10 * 72, 10));
    Level_text.setCharacterSize(textSize);
    Level_text.setFont(font);
    Level_text.setOutlineThickness(4);
    Level_text.setOutlineColor(Color::Red);

    // setting level
    level.setFillColor(Color::White);
    level.setPosition(Vector2f(12.5 * 72, 10));
    level.setCharacterSize(textSize);
    level.setFont(font);
    level.setOutlineThickness(4);
    level.setOutlineColor(Color::Red);

    // setting text lives
    lives.setString("Lives : ");
    lives.setFillColor(Color::White);
    lives.setPosition(Vector2f(18 * 72, 10));
    lives.setCharacterSize(textSize);
    lives.setFont(font);
    lives.setOutlineThickness(4);
    lives.setOutlineColor(Color::Red);

    // setting Go through the door
    GoToDoor.setString("Go through the Door!");
    GoToDoor.setFillColor(Color::Red);
    GoToDoor.setPosition(Vector2f(SCREEN_WIDTH / 2 - 3 * 72, SCREEN_HEIGHT - 60));
    GoToDoor.setCharacterSize(textSize);
    GoToDoor.setFont(font);
    GoToDoor.setOutlineThickness(4);
    GoToDoor.setOutlineColor(Color::Yellow);

    // setting gun text
    gun_text.setString("GUN");
    gun_text.setFillColor(Color::White);
    gun_text.setPosition(Vector2f(SCREEN_WIDTH / 2 - 400, SCREEN_HEIGHT - 60 - 72 - 900 - 40));
    gun_text.setCharacterSize(textSize - 12);
    gun_text.setFont(font);
    gun_text.setOutlineThickness(2);
    gun_text.setOutlineColor(Color::Red);

    // setting jetpack text
    jetPack.setString("Jetpack : ");
    jetPack.setFillColor(Color::White);
    jetPack.setPosition(Vector2f(72, SCREEN_HEIGHT - 60 - 72));
    jetPack.setCharacterSize(textSize - 24);
    jetPack.setFont(font);
    jetPack.setOutlineThickness(4);
    jetPack.setOutlineColor(Color::Red);

    // setting Score text
    theEnd.setString("The End!");
    theEnd.setFillColor(Color::Red);
    theEnd.setPosition(Vector2f(SCREEN_WIDTH / 2 - 500, SCREEN_HEIGHT / 2 - 200));
    theEnd.setCharacterSize(200);
    theEnd.setFont(font);
    theEnd.setOutlineThickness(10);
    theEnd.setOutlineColor(Color::White);
}

// LEVEL 3   ----------------------------------------------------
void Level::loadLevel_3()
{
    level_number = 3;
    /*Loading text*/
    loadText();
    level_number = 3;
    level.setString("3");

    /*Making plaforms*/
    Texture goldTile;
    goldTile.loadFromFile("resources/pictures/goldTile72.png");
    Vector2f *textureScale = new Vector2f(0.9, 0.9);
    Vector2f *textureSize = new Vector2f(goldTile.getSize());
    Vector2f *tileSize = new Vector2f(textureScale->x * textureSize->x, textureScale->y * textureSize->y);
    int *numOfTiles_horizontal = new int(SCREEN_WIDTH / (tileSize->x));
    int *numOfTiles_vertical = new int(SCREEN_HEIGHT / (tileSize->y));

    int numOfPlatforms = (*numOfTiles_horizontal + 2 * *numOfTiles_vertical) + 70;

    setNumOfPlatforms(numOfPlatforms);

    // initializing walls
    for (int i = 0; i < numOfPlatforms; i++)
    {
        platform[i]->setTexture("resources/pictures/goldTile72.png");
        platform[i]->setOrigin((textureSize->x / 2), textureSize->y / 2);
        platform[i]->setTextureSource(0, 0, textureSize->x, textureSize->y);
        platform[i]->setScale(textureScale->x, textureScale->y);
    }

    int p = 0;
    // blasted the roof, change numofplatforms (also) above if wish to restore roof
    //  for (int i = 0; i <= *numOfTiles_horizontal; i++)
    //   platform[p++]->setPosition(tileSize->x / 2 + i * tileSize->x, tileSize->y * 1.5);

    for (int i = 0; i <= *numOfTiles_horizontal; i++)
        platform[p++]->setPosition(tileSize->x / 2 + i * tileSize->x, SCREEN_HEIGHT - tileSize->y / 2);

    for (int i = 0; i < *numOfTiles_vertical; i++)
        platform[p++]->setPosition(tileSize->x / 2, tileSize->y / 2 + i * tileSize->y);

    for (int i = 0; i < *numOfTiles_vertical; i++)
        platform[p++]->setPosition(SCREEN_WIDTH - tileSize->x / 2, tileSize->y / 2 + i * tileSize->y);

    for (int i = 0; i < 3; i++)
    {
        platform[p++]->setPosition(tileSize->x * 1.5 + i * tileSize->x, SCREEN_HEIGHT - 3.5 * tileSize->y + i * tileSize->y);
        platform[p++]->setPosition(tileSize->x * 2.5 + i * tileSize->x, SCREEN_HEIGHT - 3.5 * tileSize->y + i * tileSize->y);
    }

    for (int i = 0; i < 5; i++)
    {
        platform[p++]->setPosition(tileSize->x * 10.5 + i * tileSize->x, SCREEN_HEIGHT - 1.5 * tileSize->y - i * tileSize->y);
        platform[p++]->setPosition(tileSize->x * 11.5 + i * tileSize->x, SCREEN_HEIGHT - 1.5 * tileSize->y - i * tileSize->y);
    }
    for (int i = 0; i < 3; i++)
    {
        platform[p++]->setPosition(tileSize->x * 15.5 + i * tileSize->x, SCREEN_HEIGHT - 4.5 * tileSize->y + i * tileSize->y);
        platform[p++]->setPosition(tileSize->x * 16.5 + i * tileSize->x, SCREEN_HEIGHT - 4.5 * tileSize->y + i * tileSize->y);
    }

    for (int i = 0; i < 9; i++)
        platform[p++]->setPosition(tileSize->x * 17.5 + i * tileSize->x, tileSize->y * 9.5);

    platform[p++]->setPosition(tileSize->x * 25.5, tileSize->y * 8.5);
    platform[p++]->setPosition(tileSize->x * 19.5, tileSize->y * 5.5);
    for (int i = 0; i < 5; i++)
        platform[p++]->setPosition(tileSize->x * 19.5 + i * tileSize->x, tileSize->y * 6.5);

    for (int i = 0; i < 10; i++)
        platform[p++]->setPosition(tileSize->x * 1.5 + i * tileSize->x, tileSize->y * 6.5);
    platform[p++]->setPosition(tileSize->x * 10.5, tileSize->y * 5.5);

    loadFire();
    weed_fire[weed_fire.size() - 1]->setPosition(tileSize->x * 5.5, tileSize->y * 5.5);

    for (int i = 0; i < 10; i++)
        platform[p++]->setPosition(tileSize->x * 10.5 + i * tileSize->x, tileSize->y * 4.5);

    loadFire();
    weed_fire[weed_fire.size() - 1]->setPosition(tileSize->x * 12.5, tileSize->y * 3.5);

    loadFire();
    weed_fire[weed_fire.size() - 1]->setPosition(tileSize->x * 16.5, tileSize->y * 3.5);


    std::cout << "p is" << p;
    std::cout << "  total platforms: " << numberOfPlatforms;

    // setting random number generator
    srand(time(NULL));

    int choice = rand() % 2;
    for (int i = 0; i < 4; i++) {
        if (choice++ % 2)
            loadRedGem();
        else
            loadBlueGem();

        gems[gems.size() - 1]->setPosition(tileSize->x * 13.5 + i * tileSize->x, tileSize->y * 15);
    }
    for (int i = 0; i < 2; i++) {
        if (choice++ % 2)
            loadRedGem();
        else
            loadBlueGem();

        gems[gems.size() - 1]->setPosition(tileSize->x * 14.5 + i * tileSize->x, tileSize->y * 14);
    }
    if (choice++ % 2)
        loadRedGem();
    else
        loadBlueGem();
    gems[gems.size() - 1]->setPosition(tileSize->x * 14.5, tileSize->y * 3.5);

    if (choice++ % 2)
        loadRedGem();
    else
        loadBlueGem();

    gems[gems.size() - 1]->setPosition(tileSize->x * 4, tileSize->y * 9.5);

    if (choice++ % 2)
        loadRedGem();
    else
        loadBlueGem();

    gems[gems.size() - 1]->setPosition(tileSize->x * 21.5, tileSize->y * 4.5);
 
    delete numOfTiles_horizontal, numOfTiles_vertical;

    monster.setPosition(tileSize->x * 20.5, tileSize->y * 8);

    gun.setPosition(tileSize->x * 24.5, tileSize->y * 15);

    // setting position of the door
    door.setPosition(tileSize->x * 27.25, tileSize->y * 15.25);

    // setting position of the cup
    cup.setPosition(tileSize->x * 1.5, tileSize->y * 5.5);
    cup.setScale(3, 3);

    /*Making player*/
    dave.setPosition(tileSize->x * 4.5 + 4, SCREEN_HEIGHT - (3.5 * tileSize->y));
    delete textureScale, textureSize, tileSize;

    levelLoaded = true;
}

void Level::updateLevel_3(double deltaTime)
{
    Vector2f tileSize = platform[0]->getSize();
    tileSize.x *= 0.9;
    tileSize.y *= 0.9;

    Vector2f position = monster.getPosition();

    enum
    {
        left,
        right
    };
    static short int dir = right;
    // tileSize->x * 18.5, tileSize->y * 8.5
    if (position.x >= 25.5 * tileSize.x)
        dir = left;
    else if (position.x <= 20.5 * tileSize.x)
        dir = right;

    if (dir == left)
        monster.setPosition(position.x - deltaTime * 70, position.y);
    else if (dir == right)
        monster.setPosition(position.x + deltaTime * 70, position.y);
}

void Level::ClearLevelDrawings()
{
    platform.clear();
    gems.clear();
    movable_platform_index.clear();
    weed_fire.clear();
}

// LEVEL 2   ----------------------------------------------------
void Level::loadLevel_2()
{
    level_number = 2;
    /*Loading text*/
    loadText();
    level_number = 2;
    level.setString("2");

    /*Making plaforms*/
    Texture blueTile;
    blueTile.loadFromFile("resources/pictures/blueTile72.png");
    Vector2f *textureScale = new Vector2f(0.9, 0.9);
    Vector2f *textureSize = new Vector2f(blueTile.getSize());
    Vector2f *tileSize = new Vector2f(textureScale->x * textureSize->x, textureScale->y * textureSize->y);
    int *numOfTiles_horizontal = new int(SCREEN_WIDTH / (tileSize->x));
    int *numOfTiles_vertical = new int(SCREEN_HEIGHT / (tileSize->y));

    int numOfPlatforms = (*numOfTiles_horizontal + 2 * *numOfTiles_vertical) + 46;

    setNumOfPlatforms(numOfPlatforms);

    // setting cup

    // initializing walls
    for (int i = 0; i < numOfPlatforms; i++)
    {
        platform[i]->setTexture("resources/pictures/blueTile72.png");
        platform[i]->setOrigin((textureSize->x / 2), textureSize->y / 2);
        platform[i]->setTextureSource(0, 0, textureSize->x, textureSize->y);
        platform[i]->setScale(textureScale->x, textureScale->y);
    }

    int p = 0;
    // blasted the roof, change numofplatforms (also) above if wish to restore roof
    //  for (int i = 0; i <= *numOfTiles_horizontal; i++)
    //   platform[p++]->setPosition(tileSize->x / 2 + i * tileSize->x, tileSize->y * 1.5);

    for (int i = 0; i <= *numOfTiles_horizontal; i++)
        platform[p++]->setPosition(tileSize->x / 2 + i * tileSize->x, SCREEN_HEIGHT - tileSize->y / 2);

    for (int i = 0; i < *numOfTiles_vertical; i++)
        platform[p++]->setPosition(tileSize->x / 2, tileSize->y / 2 + i * tileSize->y);

    for (int i = 0; i < *numOfTiles_vertical; i++)
        platform[p++]->setPosition(SCREEN_WIDTH - tileSize->x / 2, tileSize->y / 2 + i * tileSize->y);

    platform[p++]->setPosition(tileSize->x * 2, tileSize->y * 7);
    platform[p++]->setPosition(tileSize->x * 6.5, tileSize->y * 7);
    for (int i = 0; i < 10; i++)
        platform[p++]->setPosition(tileSize->x * 8.5 + i * tileSize->x, tileSize->y * 5);
    for (int i = 0; i < 11; i++)
        platform[p++]->setPosition(tileSize->x * 17.5 + i * tileSize->x, tileSize->y * 4);
    for (int i = 0; i < 3; i++)
        platform[p++]->setPosition(tileSize->x * 3 + i * tileSize->x, tileSize->y * 10);
    for (int i = 0; i < 4; i++)
        platform[p++]->setPosition(tileSize->x * 7.5 + i * tileSize->x, tileSize->y * 13);
    for (int i = 0; i < 4; i++)
        platform[p++]->setPosition(tileSize->x * 11.5 + i * tileSize->x, tileSize->y * 10);
    for (int i = 0; i < 5; i++)
        platform[p++]->setPosition(tileSize->x * 15.5, tileSize->y * 10 + i * tileSize->x);
    for (int i = 0; i < 2; i++)
        platform[p++]->setPosition(tileSize->x * 24.5 + i * tileSize->x, tileSize->y * 10.5);

    for (int i = 0; i < 2; i++)
    {
        movable_platform_index.push_back(p);
        platform[p++]->setPosition(tileSize->x * 20.5 + i * tileSize->x, tileSize->y * 10 + i);
    }

    for (int i = 0; i < 8; i++)
    {
        loadWeed();
        weed_fire[weed_fire.size() - 1]->setPosition(tileSize->x * 16.5 + i * tileSize->x, SCREEN_HEIGHT - tileSize->y * 1.5);
    }

    std::cout << "p is" << p;
    std::cout << "  total platforms: " << numberOfPlatforms;

    // setting random number generator
    srand(time(NULL));

    int choice = rand() % 2;
    if (choice++ % 2)
        loadRedGem();
    else
        loadBlueGem();

    gems[gems.size() - 1]->setPosition(tileSize->x * 7.5 + tileSize->x + rand() % 4, tileSize->y * 12);

    if (choice++ % 2)
        loadRedGem();
    else
        loadBlueGem();

    gems[gems.size() - 1]->setPosition(tileSize->x * 3 + rand() % 4, tileSize->y * 9);

    if (choice++ % 2)
        loadRedGem();
    else
        loadBlueGem();

    gems[gems.size() - 1]->setPosition(tileSize->x * 2, tileSize->y * 6);

    if (choice++ % 2)
        loadRedGem();
    else
        loadBlueGem();

    gems[gems.size() - 1]->setPosition(tileSize->x * 24.5, tileSize->y * 9.5);

    if (choice++ % 2)
        loadRedGem();
    else
        loadBlueGem();

    gems[gems.size() - 1]->setPosition(tileSize->x * 10.5, tileSize->y * 4);

    for (int i = 0; i < 4; i++) {
        if (choice++ % 2)
            loadRedGem();
        else
            loadBlueGem();

        gems[gems.size() - 1]->setPosition(tileSize->x * 19.5 + i*2*tileSize->x, tileSize->y * 3);
    }

    delete numOfTiles_horizontal, numOfTiles_vertical;

    // setting position of the door
    door.setPosition(tileSize->x * 27.25, tileSize->y * 15.25);

    // setting position of the cup
    cup.setPosition(tileSize->x * 6.5, tileSize->y * 3.5);
    cup.setScale(3, 3);

    /*Making player*/
    dave.setPosition(tileSize->x * 4.5 + 4, SCREEN_HEIGHT - (3.5 * tileSize->y));
    delete textureScale, textureSize, tileSize;

    levelLoaded = true;
    key = false;
}
void Level::updateLevel_2(double deltaTime)
{
    Vector2f tileSize = platform[0]->getSize();
    tileSize.x *= 0.9;
    tileSize.y *= 0.9;

    for (int i = 0; i < 2; i++)
    {
        Vector2f position = platform[movable_platform_index[i]]->getPosition();
        // std::cout << "   position: " << position.x << " " << position.y;
        enum
        {
            left,
            right
        };
        static short int dir = left;
        if (position.x >= 25.5 * tileSize.x + i)
            dir = left;
        else if (position.x <= 19.5 * tileSize.x + i)
            dir = right;

        if (dir == left)
            platform[movable_platform_index[i]]->setPosition(position.x - deltaTime * 70, position.y);
        else if (dir == right)
            platform[movable_platform_index[i]]->setPosition(position.x + deltaTime * 70, position.y);
    }
}

// LEVEL 1  ---------------------------------------------------------

void Level::loadLevel_1()
{
    level_number = 1;
    /*Loading text*/
    loadText();
    level_number = 1;
    level.setString("1");

    /*Making plaforms*/
    Texture redTile;
    redTile.loadFromFile("resources/pictures/redTile.png");
    Vector2i *textureScale = new Vector2i(3, 3);
    Vector2f *textureSize = new Vector2f(redTile.getSize());
    Vector2f *tileSize = new Vector2f(textureScale->x * textureSize->x, textureScale->y * textureSize->y);
    int *numOfTiles_horizontal = new int(SCREEN_WIDTH / (textureSize->x * textureScale->x));
    int *numOfTiles_vertical = new int(SCREEN_HEIGHT / (textureSize->y * textureScale->y) - 6);

    int numOfPlatforms = 2 * (*numOfTiles_horizontal + *numOfTiles_vertical) + 26;

    setNumOfPlatforms(numOfPlatforms);

    // initializing walls
    for (int i = 0; i < numOfPlatforms; i++)
    {
        platform[i]->setTexture("resources/pictures/redTile.png");
        platform[i]->setOrigin((textureSize->x / 2), textureSize->y / 2);
        platform[i]->setTextureSource(0, 0, textureSize->x, textureSize->y);
        platform[i]->setScale(textureScale->x, textureScale->y);
    }

    // setting wall positions       VERY DIFFICULT ALGORITHM , DON'T TRY TO UNDERSTAND
    Vector2f *add = new Vector2f(tileSize->x / 2, tileSize->y * 2.5);
    for (int i = 0; i < 2 * (*numOfTiles_horizontal + *numOfTiles_vertical) + 1; i++)
    {
        if ((add->x <= SCREEN_WIDTH - (tileSize->x / 2)) && (add->y == tileSize->y * 2.5))
        {
            platform[i]->setPosition(add->x, add->y);
            add->x += tileSize->x;
        }
        else if ((add->x == SCREEN_WIDTH + (tileSize->x / 2)) && (add->y < SCREEN_HEIGHT - (tileSize->y * 2.5)))
        {
            add->y += tileSize->y;

            platform[i]->setPosition(add->x - tileSize->x, add->y);
        }
        else if ((add->y == SCREEN_HEIGHT - tileSize->y * 2.5) && (add->x > tileSize->x / 2))
        {
            add->x -= tileSize->x;

            platform[i]->setPosition(add->x, add->y);
        }
        else if ((add->x == tileSize->x / 2) && (add->y >= tileSize->y * 3.5))
        {
            add->y -= tileSize->y;
            platform[i]->setPosition(add->x, add->y);
        }
    }
    delete add, numOfTiles_horizontal, numOfTiles_vertical;

    // setting random number generator
    srand(time(NULL));

    // setting other platforms and diamond positions
    platform[71]->setPosition(SCREEN_WIDTH - (tileSize->x * 10.5), SCREEN_HEIGHT - tileSize->y * 3.5);
    for (int i = 72; i < 80; i++)
        platform[i]->setPosition(SCREEN_WIDTH - (tileSize->x * 10.5) + (i - 72) * tileSize->x, SCREEN_HEIGHT - tileSize->y * 4.5);

    for (int i = 80; i < 87; i++)
    {
        platform[i]->setPosition(tileSize->x * 5.5 + (i - 80) * tileSize->x, SCREEN_HEIGHT - tileSize->y * 4.5);
    }

    for (int i = 87; i < 90; i++)
    {
        platform[i]->setPosition(tileSize->x * 1.5 + (i - 87) * 9 * tileSize->x, SCREEN_HEIGHT - tileSize->y * 6.5);
        int choice = rand() % 2;
        if (choice)
        {
            loadRedGem();
            gems[gems.size() - 1]->setPosition(tileSize->x * 1.5 + (i - 87) * 9 * tileSize->x, SCREEN_HEIGHT - tileSize->y * 7.5);
        }
        else
        {
            loadBlueGem();
            gems[gems.size() - 1]->setPosition(tileSize->x * 1.5 + (i - 87) * 9 * tileSize->x, SCREEN_HEIGHT - tileSize->y * 7.5);
        }
    }

    for (int i = 90; i < 93; i++)
    {
        platform[i]->setPosition(tileSize->x * 6.5 + (i - 90) * 9 * tileSize->x, SCREEN_HEIGHT - tileSize->y * 8.5);
        int choice = rand() % 2;
        if (choice)
        {
            loadRedGem();
            gems[gems.size() - 1]->setPosition(tileSize->x * 6.5 + (i - 90) * 9 * tileSize->x, SCREEN_HEIGHT - tileSize->y * 9.5);
        }
        else
        {
            loadBlueGem();
            gems[gems.size() - 1]->setPosition(tileSize->x * 6.5 + (i - 90) * 9 * tileSize->x, SCREEN_HEIGHT - tileSize->y * 9.5);
        }
    }

    for (int i = 93; i < 96; i++)
    {
        platform[i]->setPosition(tileSize->x * 1.5 + (i - 93) * 9 * tileSize->x, SCREEN_HEIGHT - tileSize->y * 9.5);
        int choice = rand() % 2;
        if (choice)
        {
            loadRedGem();
            gems[gems.size() - 1]->setPosition(tileSize->x * 1.5 + (i - 93) * 9 * tileSize->x, SCREEN_HEIGHT - tileSize->y * 10.5);
        }
        else
        {
            loadBlueGem();
            gems[gems.size() - 1]->setPosition(tileSize->x * 1.5 + (i - 93) * 9 * tileSize->x, SCREEN_HEIGHT - tileSize->y * 11.5);
        }
    }

    // setting position of the door
    door.setPosition(SCREEN_WIDTH - (9.5 * tileSize->x), SCREEN_HEIGHT - (3.5 * tileSize->y));

    // setting position of the cup
    cup.setPosition(tileSize->x * 5.5, SCREEN_HEIGHT - tileSize->y * 5.5);

    /*Making player*/
    dave.setPosition(tileSize->x * 2.5 + 4, SCREEN_HEIGHT - (3.5 * tileSize->y) - 4);
    delete textureScale, textureSize, tileSize;

    levelLoaded = true;
}

// Draw --------------------------------
void Level::Draw(RenderWindow &window, Clock &time, Event &event)
{
    // array to check which faces of the player are colliding
    bool face[5] = {false};

    // For calculating deltatime
    double deltatime = time.restart().asSeconds();
    switch (level_number)
    {
    case 2:
        updateLevel_2(deltatime);
        break;
    case 3:
        updateLevel_3(deltatime);
        break;
    }

    try
    {
        checkCollisions(face, deltatime);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what();
    }

    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }

    // setting score
    score.setString(std::to_string(dave.getPoints()));

    // For player movement
    if (Keyboard::isKeyPressed(Keyboard::D) && !face[2])
    {

        dave.updatePosition(dave.getSpeed(), 0);
        if (face[3])
        {
            dave.setTexture("resources/pictures/Dave_Walk.png");
            dave.setTextureSource(dave.animation[0].update(deltatime, dave.getTextureRect()));
        }
        dave.setScale(abs(dave.getScale().x), dave.getScale().y);
    }
    if (Keyboard::isKeyPressed(Keyboard::A) && !face[4])
    {

        dave.updatePosition(-dave.getSpeed(), 0);
        if (face[3] == true)
        {
            dave.setTexture("resources/pictures/Dave_Walk.png");
            dave.setTextureSource(dave.animation[0].update(deltatime, dave.getTextureRect()));
        }
        dave.setScale(-abs(dave.getScale().x), dave.getScale().y);
    }

    if (!(Keyboard::isKeyPressed(Keyboard::A)) && !(Keyboard::isKeyPressed(Keyboard::D)) && face[3])
    {
        dave.setTexture("resources/pictures/Dave_Idle.png");
        dave.setTextureSource(0, 0, 50, 80);
    }

    static double totalTime = 0;
    totalTime += deltatime;
    if (Keyboard::isKeyPressed(Keyboard::W) && !face[1])
    {
        dave.Jump(totalTime);
        dave.setSpeed(2.5);
    }


    static bool isShooting = false;
    if ((Keyboard::isKeyPressed(Keyboard::Space) && dave.getGunStatus()) || isShooting)
    {
        dave.shoot(isShooting, deltatime, bullet);
    }

    if (!face[1] && !face[2] && !face[3] && !face[4])
    {
        dave.setTexture("resources/pictures/Dave_Jump.png");
        dave.setTextureSource(0, 0, 50, 80);
    }



    // for gravity
    if (face[3])
    {
        totalTime = 0;
        dave.setSpeed(5);
        dave.gravity.setGravity(deltatime, false);
    }
    else
        dave.gravity.setGravity(deltatime, true);

    // for checking the end of level
    checkLevelEnd();

    /*For drawing the level*/

    // platforms
    for (int i = 0; i < platform.size(); i++)
        platform[i]->Draw(window);

    for (DynamicObject *w : weed_fire)
    {
        w->Draw(window);
        w->setTextureSource(w->animation[0].update(deltatime, w->getTextureRect()));
    }

    // gun
    gun.Draw(window);
    // door
    door.Draw(window);
    // dave
    dave.Draw(window);
    // monster
    monster.Draw(window);
    // bullet
    bullet.Draw(window);

    // gems
    for (int i = 0; i < gems.size(); i++)
        gems[i]->Draw(window);
    // cup
    cup.Draw(window);

    // text
    window.draw(Score);
    window.draw(Level_text);
    if (key)
        window.draw(GoToDoor);
    window.draw(lives);
    window.draw(score);
    window.draw(level);
    if (dave.getGunStatus())
        window.draw(gun_text);
    if (dave.getJetEquipStatus())
        window.draw(jetPack);

    // drawing hearts
    for (int i = 0; i < hearts.size(); i++)
        hearts[i]->Draw(window);
}
