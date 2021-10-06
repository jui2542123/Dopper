#pragma once
#ifndef PICKUP_H
#define PICKUP_H

#include "Entity.h"

class Pickup : public Entity
{
public:
	bool isCoin = true;
	int coinvalue = 2;
	bool destroy = false;
	bool isfood = true;
	int heal = 2;

	Pickup();
	void update();
	//void updateMovement();

};

#endif
