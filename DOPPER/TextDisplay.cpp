#include "TextDisplay.h"




TextDisplay::TextDisplay()
{
	text.setFillColor(Color::Red);
	text.setCharacterSize(25);
	text.setString(myString);

}

void TextDisplay::update()
{
	text.move(0, -movespeed);

	counter++;
	if (counter >= lifetimecounter)
	{
		destroy = true;
	}
}





