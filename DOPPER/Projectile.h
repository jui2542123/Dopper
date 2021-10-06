#pragma once
#ifndef PROJECTILE_H
#define PROJECTILE_H


#include "Entity.h"

class Projectile : public Entity
{
public:
	//knife
	float movespeed = 15; //projectile speed
	int attackdamage = 5; // Damage
	int direction = 0;
	bool destroy = false;
	int counterLifetime = 0;
	int lifeTime = 100; //Distant shot
	

	Projectile();
	void update();
	//void updateMovement();

};

#endif // !PROJECTILE_H