#pragma once
#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"
#include "Random.h"

class Enemy : public Entity
{
public:
	float movespeed = .5;
	int movementLength = 20;
	int attackdamage = 2; //Enemy damage
	int countwalk = 0;
	int direction = 0;
	int counter = 0;
	int hp = 25;
	bool alive = true;
	int countframe = 0;
	bool cantmoveup = true;
	bool cantmovedown = true;
	bool cantmoveleft = true;
	bool cantmoveright = true;


	Enemy();
	void update();
	void updateMovement();

};
#endif