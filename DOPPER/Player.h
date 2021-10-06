#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public Entity
{
public:
	int movespeed = 6;
	int attackdamage = 5;
	int countwalk = 0;
	int direction = 0;
	int hp = 10; //PLAYER HP
	int maxhp = 10;
	int countframe = 0;
	bool cantmoveup = true;
	bool cantmovedown = true;
	bool cantmoveleft = true;
	bool cantmoveright = true;
	int score = 0;
	


	Player();
	void update();
	void updateMovement();

};

#endif // ! PLAYER_H