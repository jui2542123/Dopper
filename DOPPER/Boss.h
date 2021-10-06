#pragma once

#ifndef BOSS_H
#define BOSS_H

#include "Entity.h"
#include "Random.h"

class Boss : public Entity
{
public:
	float movespeed = .5;
	int movementLength = 50;
	int attackdamage = 50; //Enemy damage
	int countwalk = 0;
	int direction = 0;
	int counter = 0;
	int hp = 1000;
	bool alive = true;
	int countframe = 0;
	bool cantmoveup = true;
	bool cantmovedown = true;
	bool cantmoveleft = true;
	bool cantmoveright = true;


	Boss();
	void update();
	void updateMovement();

};
#endif