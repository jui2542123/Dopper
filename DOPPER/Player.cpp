#include "Player.h"

Player::Player()
{
	rect.setSize(Vector2f(40,64));
	rect.setPosition(400, 200);
	rect.setFillColor(Color::Blue);
	rect.setOrigin(-22.5f,-5);
	sprite.setTextureRect(IntRect(32, 0, 32, 32));
	sprite.setScale(2.5f, 2.5f);	




}

void Player::update()
{
	sprite.setPosition(rect.getPosition());
	
}

void Player::updateMovement()
{

	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		if (cantmoveup == true)
		{
			
			rect.move(0, -movespeed);
			sprite.setTextureRect(IntRect(countwalk * 32, 96, 32, 32));
			direction = 1;
			cantmoveup = true;
			cantmovedown = true;
			cantmoveleft = true;
			cantmoveright = true;
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		if (cantmovedown == true)
		{ 
			
			rect.move(0, movespeed);
			sprite.setTextureRect(IntRect(countwalk * 32, 0, 32, 32));
			direction = 2;
			cantmoveup = true;
			cantmovedown = true;
			cantmoveleft = true;
			cantmoveright = true;
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		if (cantmoveleft == true)
		{
			
			rect.move(-movespeed, 0);
			sprite.setTextureRect(IntRect(countwalk * 32, 32, 32, 32));
			direction = 3;
			cantmoveup = true;
			cantmovedown = true;
			cantmoveleft = true;
			cantmoveright = true;
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		if (cantmoveright == true)
		{
			rect.move(movespeed, 0);
			sprite.setTextureRect(IntRect(countwalk * 32, 64, 32, 32));
			direction = 4;
			cantmoveup = true;
			cantmovedown = true;
			cantmoveleft = true;
			cantmoveright = true;
		}
	}
	else
	{
		//Constant
	}

	countframe++;

	if (countframe == 20)
	{
		countframe = 0;
		countwalk++;
		if (countwalk == 3)
		{
			countwalk = 0;
		}
	}
}

