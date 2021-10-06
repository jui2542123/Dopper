#include "Pickup.h"


Pickup::Pickup()
{
	rect.setSize(Vector2f(100,100));
	rect.setPosition(0,0);
	rect.setFillColor(Color::Yellow);
	rect.setOrigin(-25, -20);
	sprite.setScale(2, 2);


}

void Pickup::update()
{
	sprite.setPosition(rect.getPosition());
	text.setPosition(rect.getPosition().x, rect.getPosition().y - 30);
}

