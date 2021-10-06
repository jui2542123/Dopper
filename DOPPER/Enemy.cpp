#include "Enemy.h"

Enemy::Enemy()
{
	rect.setSize(Vector2f(40,40));
	rect.setPosition(400, 200);
	rect.setFillColor(Color::Blue);
	rect.setOrigin(-10,-10);
	sprite.setTextureRect(IntRect(32, 0, 32, 32));
	sprite.setScale(2, 2);

}

void Enemy::update()
{
	sprite.setPosition(rect.getPosition());
	text.setPosition(rect.getPosition().x , rect.getPosition().y);
}

void Enemy::updateMovement()
{
	
	if (direction == 1)
	{
		if (cantmoveup == true)
		{
			rect.move(0, -movespeed);
			sprite.setTextureRect(IntRect(countwalk * 32, 0, 32, 32));
			cantmoveup = true;
			cantmovedown = true;
			cantmoveleft = true;
			cantmoveright = true;
		}
		
	}
	else if (direction == 2)
	{
		if (cantmovedown == true)
		{
			rect.move(0, movespeed);
			sprite.setTextureRect(IntRect(countwalk * 32, 0, 32, 32));
			cantmoveup = true;
			cantmovedown = true;
			cantmoveleft = true;
			cantmoveright = true;
		}
	}
	else if (direction == 3)
	{
		if (cantmoveup == true)
		{
			rect.move(-movespeed, 0);
			sprite.setTextureRect(IntRect(countwalk * 32, 0, 32, 32));
			cantmoveup = true;
			cantmovedown = true;
			cantmoveleft = true;
			cantmoveright = true;
		}

	}
	else if (direction == 4)
	{
		if (cantmoveup == true)
		{
			rect.move(movespeed, 0);
			sprite.setTextureRect(IntRect(countwalk * 32, 0, 32, 32));
			cantmoveup = true;
			cantmovedown = true;
			cantmoveleft = true;
			cantmoveright = true;
		}
	}
	else 
	{
		//Stop
	}

	countframe++;

	if (countframe == 15)
	{
		countframe = 0;
		countwalk++;
		if (countwalk == 3)
		{
			countwalk = 0;
		}
	}

	counter++;
	if (counter >= movementLength)
	{
		direction = generateRandom(5);
		counter = 0;
	}
}

