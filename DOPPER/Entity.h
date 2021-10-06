#pragma once
#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <random>
#include <vector>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>


using namespace std;
using namespace sf;

class Entity
{
public:
	RectangleShape rect;
	Sprite sprite;
	Text text;
private:
protected:
};


#endif // !ENTITY_H
