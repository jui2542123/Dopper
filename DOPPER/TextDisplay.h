#pragma once
#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include "Entity.h"

class TextDisplay : public Entity
{
public:
	int movespeed = 2;
	int counter = 0;
	int lifetimecounter = 100;
	bool destroy = false;
	string myString = "Default";

	TextDisplay();
	void update();
	//void updateMovement();

};


#endif