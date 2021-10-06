#include "Boss.h"
Boss::Boss()
{
	rect.setSize(Vector2f(200,200));
	rect.setPosition(400, 200);
	rect.setFillColor(Color::Blue);
	rect.setOrigin(-70, -50);
	sprite.setTextureRect(IntRect(0, 0, 32, 32));
	sprite.setScale(10,10);

}

void Boss::update()
{
	sprite.setPosition(rect.getPosition());
	text.setPosition(rect.getPosition().x, rect.getPosition().y);
}

void Boss::updateMovement()
{

	if (direction == 1)
	{
		if (cantmoveup == true)
		{
			rect.move(0, -movespeed);
			sprite.setTextureRect(IntRect(0, countwalk * 32, 32, 32));
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
			sprite.setTextureRect(IntRect(0, countwalk * 32, 32, 32));
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
			sprite.setTextureRect(IntRect(0, countwalk * 32, 32, 32));
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
			sprite.setTextureRect(IntRect(0, countwalk * 32, 32, 32));
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
		if (countwalk == 4)
		{
			countwalk = 0;
		}
	}

	counter++;
	if (counter >= movementLength)
	{
		direction = generateRandom(4);
		counter = 0;
	}
}

