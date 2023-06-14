#pragma once
#include "Player.h"
#include <SFML/Audio.hpp>

#define SCREEN_WIDTH 1872
#define SCREEN_HEIGHT 1080

class Level
{

private:
	int numberOfPlatforms;
	bool key;
	Text Score, Level_text, GoToDoor, score, level, lives, jetPack, gun_text;
	Font font;

public:
	Player dave;
	std::vector<GameObject *> platform, hearts;
	std::vector<DynamicObject *> gems, weed_fire;
	std::vector<int> movable_platform_index;
	std::vector<char> gemsType;
	GameObject door, cup, monster, gun, bullet;
	bool levelDraw;
	bool titleDraw;
	bool end;
	Sound titleMusic, musicLevel1, musicLevel2, musicLevel3, collectable, soundCup;
	SoundBuffer title, level1, level2, level3, collect, bufferCup;
	int level_number;
	bool levelLoaded;
	Text theEnd;

	Level();
	void setNumOfPlatforms(int);
	void checkCollisions(bool face[5], double deltaTime);
	void loadLevel_1();
	void loadLevel_2();
	void loadLevel_3();
	void updateLevel_2(double deltaTime);
	void updateLevel_3(double deltaTime);
	void ClearLevelDrawings();
	void Draw(RenderWindow &window, Clock &time, Event &event);
	void loadRedGem();
	void loadBlueGem();
	void loadWeed();
	void loadFire();
	void loadText();
	void checkLevelEnd();
};
