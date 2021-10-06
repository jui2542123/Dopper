#include "Wall.h"



Wall::Wall()
{
	rect.setSize(Vector2f(65,65 ));
	rect.setPosition(0,0);
	rect.setFillColor(Color::Yellow);
	sprite.setTextureRect(IntRect(0, 0, 70, 70));
}


void Wall::update()
{
	sprite.setPosition(rect.getPosition());
	
}