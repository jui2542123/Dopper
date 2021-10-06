#include "Projectile.h"



Projectile::Projectile()
{
	rect.setSize(Vector2f(15, 15));
	rect.setPosition(0,0);
	rect.setFillColor(Color::Yellow);
	rect.setOrigin(-25, -25); //check
	sprite.setTextureRect(IntRect(0, 0, 32, 32));
	sprite.setScale(2, 2);
}

void Projectile::update()
{
	if (direction == 1)//UP
	{
		rect.move(0, -movespeed);
		sprite.setTextureRect(IntRect(0, 0, 32, 32));
	}
	if (direction == 2)//DOWN
	{
		rect.move(0, movespeed);
		sprite.setTextureRect(IntRect(0, 64, 32, 32));
	}
	if (direction == 3)//LEFT
	{
		rect.move(-movespeed, 0);
		sprite.setTextureRect(IntRect(0, 32, 32, 32));
	}
	if (direction == 4)//RIGHT
	{
		rect.move(movespeed, 0);
		sprite.setTextureRect(IntRect(0, 96, 32, 32));
	}

	counterLifetime++;
	if (counterLifetime >= lifeTime)
	{
		destroy = true;
	}

	//Sprite set at Rect
	sprite.setPosition(rect.getPosition());

}
