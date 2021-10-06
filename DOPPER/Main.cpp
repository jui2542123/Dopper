#include <SFML/Graphics.hpp>
#include <iostream>

#include "Player.h"
#include "Entity.h"
#include "Projectile.h"
#include "Enemy.h"
#include "Random.h"
#include "TextDisplay.h"
#include "Pickup.h"
#include "Wall.h"
#include "Boss.h"


using namespace std;
using namespace sf;





int main() {
	//Main window
	RenderWindow window(VideoMode(1000, 800), "DOPPER");
	window.setFramerateLimit(60);
	

	//Clock

	Clock clock;
	Clock clock2;
	Clock clock3;

	//View
	View view1(FloatRect(200,200,300,200));
	view1.setSize(Vector2f(window.getSize().x,window.getSize().y));
	view1.setCenter(Vector2f(view1.getSize().x / 2, view1.getSize().y / 2));
	window.setView(view1);


	//Variables
	srand(time(NULL));
	int movespeed = 2;
	int countwalk = 0;
	int counter = 0;
	int counter2 = 0;
	int counter3 = 0;


	//Load sprite to display



	Texture texturePlayer;
	if (!texturePlayer.loadFromFile("Assets/Clone3.png")) {
		return EXIT_FAILURE;
	}
	Texture textureenemy1;
	if (!textureenemy1.loadFromFile("Assets/enemy1.png")) {
		return EXIT_FAILURE;
	}
	Font font;
	if (!font.loadFromFile("Assets/Acens.ttf"))
	{
		return EXIT_FAILURE;
	}
	Texture Coin;
	if (!Coin.loadFromFile("Assets/Gem.png")) {
		return EXIT_FAILURE;
	}
	Texture food;
	if (!food.loadFromFile("Assets/pizza.png")) {
		return EXIT_FAILURE;
	}
	Texture knife;
	if (!knife.loadFromFile("Assets/knife.png")) {
		return EXIT_FAILURE;
	}
	Texture Bosskin;
	if (!Bosskin.loadFromFile("Assets/Boss.png")) {
		return EXIT_FAILURE;

	}
	Texture Walls;
	if (!Walls.loadFromFile("Assets/Block.png")) {
		return EXIT_FAILURE;

	}

	//Money
	Text text("Cot :",font,30);
	text.setFillColor(Color::Yellow);
	text.setPosition(0,0);
	//Player HP
	Text HP("HP :", font, 30);
	HP.setFillColor(Color::Green);
	HP.setPosition(0, 0);


	Text text2("Cot :", font, 30);
	text2.setFillColor(Color::Magenta);
	text2.setPosition(0, 0);
	
	///SOUND!!!!
	SoundBuffer Coinpick;
	if (!Coinpick.loadFromFile("Sounds/Pickup_Coin9.ogg"))
	{
		return -1;
	}
	Sound pickcoin;
	pickcoin.setBuffer(Coinpick);

	SoundBuffer Nom;
	if (!Nom.loadFromFile("Sounds/chomp.ogg"))
	{
		return -1;
	}
	Sound chomp;
	chomp.setBuffer(Nom);
	
	Music music;
	if (!music.openFromFile("Sounds/Frostellar.ogg"))
		return -1; // error
	music.play();

	SoundBuffer Throwsound;
	if (!Throwsound.loadFromFile("Sounds/woosh.ogg"))
	{
		return -1;
	}
	Sound knifesound;
	knifesound.setBuffer(Throwsound);

	SoundBuffer Knifehit;
	if (!Knifehit.loadFromFile("Sounds/Hit.ogg"))
	{
		return -1;
	}
	Sound Stab;
	Stab.setBuffer(Knifehit);

	SoundBuffer enemyhit;
	if (!enemyhit.loadFromFile("Sounds/bite-small.wav"))
	{
		return -1;
	}
	Sound Bite;
	Bite.setBuffer(enemyhit);





	//Sprite Player(texturePlayer);
	//Player.setPosition(window.getSize().x/2 , window.getSize().y / 2);
	//Player.setTextureRect(IntRect(36,36,36,36));
	//Player.setScale(2.f, 2.f); 

	//class object
	class Player player1;
	player1.sprite.setTexture(texturePlayer);

	//Projectile Vector Array
	vector<Projectile>::const_iterator iter;
	vector<Projectile>projectileArray;
	
	//Projectile Object
	class Projectile projectile1;
	projectile1.sprite.setTexture(knife);


	//Enemy Vector Array
	vector<Enemy>::const_iterator iter4;
	vector<Enemy>enemyArray;

	// Enemy Object
	class Enemy enemy1;
	enemy1.sprite.setTexture(textureenemy1);
	enemy1.text.setFont(font);
	enemy1.text.setCharacterSize(10);
	enemy1.text.setFillColor(Color::Red);
	//enemy1.sprite.setTextureRect(IntRect(32,0,32,32));

	//Boss
	vector<Boss>::const_iterator iter5;
	vector<Boss>bossArray;


	class Boss boss1;
	boss1.sprite.setTexture(Bosskin);
	boss1.text.setFont(font);
	boss1.text.setCharacterSize(10);
	boss1.text.setFillColor(Color::Red);

	//enemy1.rect.setPosition(600, 200);
	//enemyArray.push_back(enemy1);


	//Text Vector Array
	vector<TextDisplay>::const_iterator iter8;
	vector<TextDisplay>TextDisplayArray;

	//Text Display Object
	class TextDisplay TextDisplay1;
	TextDisplay1.text.setFont(font);

	//Wall Vector Array
	vector<Wall>::const_iterator iter2;
	vector<Wall>wallArray;

	class Wall wall1;
	wall1.sprite.setTexture(Walls);



	//wall1.sprite.setTexture(walls);
	//wall1.sprite.setTextureRect(IntRect(0, 0, 32, 32));

	//wall1.rect.setPosition(100,100);

	
	//wallArray.push_back(wall1);

	int roomsize = generateRandom(10) + 7;
	int verticaldoor = generateRandom(4);
	int block = 70;
	int roomstartX = 0;
	int roomstartY = 0;
	int doorleft = 3;
	int doorright = 3;
	int doorup = 5;
	int doordown = 3;

	//Pickup Vector Array
	vector<Pickup>::const_iterator iter11;
	vector<Pickup>PickupArray;

	//Coin Object
	class Pickup pickup1;
	pickup1.sprite.setTexture(Coin);
	pickup1.text.setFont(font);
	pickup1.text.setCharacterSize(32);
	pickup1.text.setFillColor(Color::Green);
	pickup1.rect.setPosition(500, 500);
	pickup1.rect.setSize(Vector2f(16, 16));

	//foodObject
	class Pickup pickup2;
	pickup2.sprite.setTexture(food);
	pickup2.rect.setPosition(500, 500);
	pickup2.rect.setSize(Vector2f(16, 16));


	//CustomRoom 1!!!

	roomsize = 7;
	verticaldoor = 4;
	block = 70;
	roomstartX = 0;
	roomstartY = 0;
	
	
	
	//Create Wall Horizon

	counter = 0;
	while (counter < roomsize)
	{
		wall1.rect.setPosition(block*counter+ roomstartX,roomstartY);
		wallArray.push_back(wall1);

		counter++;
	}
	counter = 0;
	while (counter < roomsize)
	{
		wall1.rect.setPosition(block * counter+ roomstartX,block * roomsize +  roomstartY);
		wallArray.push_back(wall1);


		counter++;
	}
	//Create Wall Verti
	counter = 0;
	while (counter < roomsize)
	{
		wall1.rect.setPosition(0 + roomstartX, block * counter+ roomstartY);
		wallArray.push_back(wall1);


		counter++;
	}

	counter = 0;
	while (counter < roomsize + 1)
	{

		if (counter != verticaldoor && counter != verticaldoor - 1)
		{
			wall1.rect.setPosition(block  * roomsize + roomstartX, block * counter+ roomstartY);
			wallArray.push_back(wall1);
		}

		counter++;
	}



	//CustomRoom 2 Big!!!

	roomsize = 10;
	doorleft = 3;
	doorright = 3;
	doorup = 5;
	doordown = 3;
	block = 70;
	roomstartX = 7 * 70;
	roomstartY = 0;

	enemy1.rect.setPosition((((roomsize-3)*70)+140), (((roomsize - 3) * 70) -70));
	enemyArray.push_back(enemy1);
	

	//Create Wall Horizon

	counter = 0;
	while (counter < roomsize)
	{
		if(counter != doorup && counter != doorup - 1)
		{

			wall1.rect.setPosition(block*counter + roomstartX, roomstartY);
			wallArray.push_back(wall1);
		
		}

		counter++;
	}
	counter = 0;
	while (counter < roomsize)
	{
		if (counter != doordown && counter != doordown - 1)
		{
			wall1.rect.setPosition(block * counter + roomstartX, block * roomsize + roomstartY);
			wallArray.push_back(wall1);

		}
		counter++;
	}
	//Create Wall Verti
	counter = 0;
	while (counter < roomsize)
	{
		if (counter != doorleft && counter != doorleft + 1)
		{
			wall1.rect.setPosition(0 + roomstartX, block * counter + roomstartY);
			wallArray.push_back(wall1);
		}

		counter++;
	}

	counter = 0;
	while (counter < roomsize + 1)
	{
		

			wall1.rect.setPosition(block  * roomsize + roomstartX, block * counter + roomstartY);
			wallArray.push_back(wall1);
		

		counter++;
	}


	//CustomRoom 4 Big!!!

	roomsize = 15;
	doorleft = 3;
	doorright = 3;
	doorup = 5;
	doordown = 5;
	block = 70;
	roomstartX = 7 * 70;
	roomstartY = -(15 *70);


	

	//Create Wall Horizon

	counter = 0;
	while (counter < roomsize)
	{
		
			wall1.rect.setPosition(block*counter + roomstartX, roomstartY);
			wallArray.push_back(wall1);
		

		counter++;
	}
	counter = 0;
	while (counter < roomsize)
	{
		if (counter != doordown && counter != doordown - 1)
		{
			wall1.rect.setPosition(block * counter + roomstartX, block * roomsize + roomstartY);
			wallArray.push_back(wall1);

		}
		counter++;
	}
	//Create Wall Verti
	counter = 0;
	while (counter < roomsize)
	{
		if (counter != doorleft && counter != doorleft - 1)
		{
			wall1.rect.setPosition(0 + roomstartX, block * counter + roomstartY);
			wallArray.push_back(wall1);

		}
		counter++;
	}

	counter = 0;
	while (counter < roomsize + 1)
	{
		if (counter != doorright && counter != doorright- 1)
		{

			wall1.rect.setPosition(block  * roomsize + roomstartX, block * counter + roomstartY);
			wallArray.push_back(wall1);

		}
		counter++;
	}

	//Generate Stuff
	counter = 0;
	while (counter < (roomsize - 1))
	{
		counter2 = 0;
		while(counter2 <(roomsize - 1))

		{
			int tempRandom = generateRandom(3); // type of object to spawn
			if (tempRandom == 1)
			{
				enemy1.rect.setPosition((counter * 70) + 70 + roomstartX, (counter2 * 70) + 70 + roomstartY);
				enemyArray.push_back(enemy1);
				
			}
			counter2++;
		}
		counter++;
	}

	//CustomRoom 5 Big!!!

	roomsize = 15;
	doorleft = 3;
	doorright = 3;
	doorup = 3;
	doordown = 5;
	block = 70;
	roomstartX = 7 * 70;
	roomstartY = 11 * 70;




	//Create Wall Horizon

	counter = 0;
	while (counter < roomsize)
	{
		if (counter != doorup && counter != doorup - 1)
		{
			wall1.rect.setPosition(block*counter + roomstartX, roomstartY);
			wallArray.push_back(wall1);

		}
		counter++;
	}
	counter = 0;
	while (counter < roomsize)
	{
		
			wall1.rect.setPosition(block * counter + roomstartX, block * roomsize + roomstartY);
			wallArray.push_back(wall1);

		
		counter++;
	}
	//Create Wall Verti
	counter = 0;
	while (counter < roomsize)
	{

		wall1.rect.setPosition(0 + roomstartX, block * counter + roomstartY);
		wallArray.push_back(wall1);


		counter++;
	}

	counter = 0;
	while (counter < roomsize + 1)
	{


		wall1.rect.setPosition(block  * roomsize + roomstartX, block * counter + roomstartY);
		wallArray.push_back(wall1);


		counter++;
	}

	//Generate Stuff

	boss1.rect.setPosition(1000,1300);
	bossArray.push_back(boss1);
	
	enemy1.rect.setPosition(800, 1500);
	enemyArray.push_back(enemy1);
	





	

	//start game loop
	while (window.isOpen())
	{
		

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();

			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {
				window.close();
			}


		}

		window.clear();


		//Clock
		Time elapsed1 = clock.getElapsedTime();
		Time elapsed2 = clock.getElapsedTime();
		Time elapsed3 = clock.getElapsedTime();



		//Enemy collides wall
		
		counter = 0;
		for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
		{
			counter2 = 0;
			for (iter2 = wallArray.begin(); iter2 != wallArray.end(); iter2++)
			{
				if (enemyArray[counter].rect.getGlobalBounds().intersects(wallArray[counter2].rect.getGlobalBounds()))
				{
					//Hit Wall
					if (enemyArray[counter].direction == 1) //Up
					{
						enemyArray[counter].cantmoveup = false;
						enemyArray[counter].rect.move(0, 1);
					}
					else if (enemyArray[counter].direction == 2) //Down
					{
						enemyArray[counter].cantmovedown = false;
						enemyArray[counter].rect.move(0, -1);
					}
					else if (enemyArray[counter].direction == 3) //LEft
					{
						enemyArray[counter].cantmoveleft = false;
						enemyArray[counter].rect.move(1, 0);
					}
					else if (enemyArray[counter].direction == 4) //RIGHT
					{
						enemyArray[counter].cantmoveright = false;
						enemyArray[counter].rect.move(-1, 0);
					}
					else
					{

					}

				}

				counter2++;
			}

			counter++;
		}

		//boss collide wall
		counter = 0;
		for (iter5 = bossArray.begin(); iter5 != bossArray.end(); iter5++)
		{
			counter2 = 0;
			for (iter2 = wallArray.begin(); iter2 != wallArray.end(); iter2++)
			{
				if (bossArray[counter].rect.getGlobalBounds().intersects(wallArray[counter2].rect.getGlobalBounds()))
				{
					//Hit Wall
					if (bossArray[counter].direction == 1) //Up
					{
						bossArray[counter].cantmoveup = false;
						bossArray[counter].rect.move(0, 1);
					}
					else if (enemyArray[counter].direction == 2) //Down
					{
						bossArray[counter].cantmovedown = false;
						bossArray[counter].rect.move(0, -1);
					}
					else if (enemyArray[counter].direction == 3) //LEft
					{
						bossArray[counter].cantmoveleft = false;
						bossArray[counter].rect.move(1, 0);
					}
					else if (enemyArray[counter].direction == 4) //RIGHT
					{
						bossArray[counter].cantmoveright = false;
						bossArray[counter].rect.move(-1, 0);
					}
					else
					{

					}

				}

				counter2++;
			}

			counter++;
		}

		
		//Player Collide wall

		counter = 0;
		for (iter2 = wallArray.begin(); iter2 != wallArray.end(); iter2++)
		{
			if (player1.rect.getGlobalBounds().intersects(wallArray[counter].rect.getGlobalBounds()))
			{
				//Hit Wall
				if (player1.direction == 1) //Up
				{
					player1.cantmoveup = false;
					player1.rect.move(0, 1);
				}
				else if (player1.direction == 2) //Down
				{
					player1.cantmovedown = false;
					player1.rect.move(0, -1);
				}
				else if (player1.direction == 3) //LEft
				{
					player1.cantmoveleft = false;
					player1.rect.move(1, 0);
				}
				else if (player1.direction == 4) //RIGHT
				{
					player1.cantmoveright = false;
					player1.rect.move(-1, 0);
				}
				else
				{

				}
			}
				counter++;
		}

		




		//Player collide item
		counter = 0;
		for (iter11 = PickupArray.begin(); iter11 != PickupArray.end(); iter11++)
		{
			if (player1.rect.getGlobalBounds().intersects(PickupArray[counter].rect.getGlobalBounds()))
			{
				
				if (PickupArray[counter].isCoin == true)
				{
					pickcoin.play();

					projectile1.attackdamage += 2;

					//player1.currency += PickupArray[counter].coinvalue;

				}
				else if (PickupArray[counter].isfood == true)
				{
					chomp.play();
					player1.maxhp += 2;
					if (player1.hp < player1.maxhp) {
						player1.hp += PickupArray[counter].heal;
					}
	
				}

				PickupArray[counter].destroy = true;
			}
			counter++;
		}




		//Player take damage when collide with enemy
		if (elapsed2.asSeconds() >= 0.5) // fixed <- 0.25 or lower?
		{
			clock2.restart();

			counter = 0;

			for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
			{
				if (player1.rect.getGlobalBounds().intersects(enemyArray[counter].rect.getGlobalBounds()))
				{

					//TExt Display
					TextDisplay1.text.setString(to_string(enemyArray[counter].attackdamage));
					TextDisplay1.text.setPosition(player1.rect.getPosition().x + player1.rect.getSize().x / 2, player1.rect.getPosition().y - player1.rect.getSize().y / 2);
					TextDisplayArray.push_back(TextDisplay1);
					
					//Sound
					Bite.play();
					
					player1.hp -= enemyArray[counter].attackdamage;
					if (player1.hp <= 0)
					{
						player1.movespeed = 0;
						TextDisplay1.text.setFillColor(Color::Cyan);
						TextDisplay1.movespeed = 0;
						TextDisplay1.text.setCharacterSize(40);
						TextDisplay1.lifetimecounter = 1000000;

						TextDisplay1.text.setString("Press ESC to exit  You are dead");
						TextDisplay1.text.setPosition(player1.rect.getPosition().x/2, player1.rect.getPosition().y);
						TextDisplayArray.push_back(TextDisplay1);

						TextDisplay1.text.setFillColor(Color::Red);
						TextDisplay1.movespeed = 2;
						TextDisplay1.text.setCharacterSize(25);
						TextDisplay1.lifetimecounter = 100;
					}
					
				}
			
				counter++;
			}

		}

		//Player take damage when collide with boss
		if (elapsed2.asSeconds() >= 0.5) // fixed <- 0.25 or lower?
		{
			clock2.restart();

			counter = 0;

			for (iter5 = bossArray.begin(); iter5 != bossArray.end(); iter5++)
			{
				if (player1.rect.getGlobalBounds().intersects(bossArray[counter].rect.getGlobalBounds()))
				{



					//TExt Display
					TextDisplay1.text.setString(to_string(bossArray[counter].attackdamage));
					TextDisplay1.text.setPosition(player1.rect.getPosition().x + player1.rect.getSize().x / 2, player1.rect.getPosition().y - player1.rect.getSize().y / 2);
					TextDisplayArray.push_back(TextDisplay1);
					//Sound
					Bite.play();

					player1.hp -= bossArray[counter].attackdamage;
					if (player1.hp <= 0)
					{
						player1.movespeed = 0;
						TextDisplay1.text.setFillColor(Color::Cyan);
						TextDisplay1.movespeed = 0;
						TextDisplay1.text.setCharacterSize(40);
						TextDisplay1.lifetimecounter = 1000000;

						TextDisplay1.text.setString("Press ESC to exit  You are dead");
						TextDisplay1.text.setPosition(player1.rect.getPosition().x / 2, player1.rect.getPosition().y);
						TextDisplayArray.push_back(TextDisplay1);

						TextDisplay1.text.setFillColor(Color::Red);
						TextDisplay1.movespeed = 2;
						TextDisplay1.text.setCharacterSize(25);
						TextDisplay1.lifetimecounter = 100;
					}

				}

				counter++;
			}

		}

		///Projectile on wall
		counter = 0;
		for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
		{
			counter2 = 0;
			for (iter2 = wallArray.begin(); iter2 != wallArray.end(); iter2++)
			{
				if (projectileArray[counter].rect.getGlobalBounds().intersects(wallArray[counter2].rect.getGlobalBounds()))
				{
						//souund
					Stab.play();
					projectileArray[counter].destroy = true;
					

				}

				counter2++;
			}
			counter++;
		}

		//enemy chase
		counter = 0;
		for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
		{
			if (elapsed3.asSeconds() >= 1)
			{
				clock.restart();

				if (player1.rect.getPosition().y < enemyArray[counter].rect.getPosition().y)
				{
					/*projectile1.direction = 1;
					projectile1.rect.setPosition(bossArray[counter].rect.getPosition().x ,bossArray[counter].rect.getPosition().y );
					projectileArray.push_back(projectile1);*/
					enemyArray[counter].rect.move(-movespeed, 0);
				}
				else if
					(player1.rect.getPosition().y > enemyArray[counter].rect.getPosition().y)
				{

					enemyArray[counter].rect.move(movespeed, 0);
				}
				if
					(player1.rect.getPosition().x < enemyArray[counter].rect.getPosition().x)
				{

					enemyArray[counter].rect.move(0, -movespeed);
				}
				else if
					(player1.rect.getPosition().x > enemyArray[counter].rect.getPosition().x)
				{

					enemyArray[counter].rect.move(0, movespeed);
				}

			}
			counter++;

		}


		//Aggro Boss Chase
		counter = 0;
		for (iter5 = bossArray.begin(); iter5 != bossArray.end(); iter5++)
		{
			if (elapsed3.asSeconds() >= 1)
			{
				clock.restart();

				if (player1.rect.getPosition().y < bossArray[counter].rect.getPosition().y)
				{
					/*projectile1.direction = 1;
					projectile1.rect.setPosition(bossArray[counter].rect.getPosition().x ,bossArray[counter].rect.getPosition().y );
					projectileArray.push_back(projectile1);*/
					bossArray[counter].rect.move(-movespeed,0);
				}
				else if
					(player1.rect.getPosition().y > bossArray[counter].rect.getPosition().y)
				{
					
					bossArray[counter].rect.move(movespeed, 0);
				}
				if
					(player1.rect.getPosition().x < bossArray[counter].rect.getPosition().x)
				{
					
					bossArray[counter].rect.move( 0, -movespeed);
				}
				else if
					(player1.rect.getPosition().x > bossArray[counter].rect.getPosition().x)
				{
					
					bossArray[counter].rect.move(0, movespeed );
				}
					
			}
			counter++;

		}
	

		
		 

		//Projectile hit enemy //collision

		counter = 0;
		for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
		{
			counter2 = 0;
			for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
			{

				if (projectileArray[counter].rect.getGlobalBounds().intersects(enemyArray[counter2].rect.getGlobalBounds()))
				{
					
						Stab.play();
						projectileArray[counter].destroy = true;

						

						//TExt display

						TextDisplay1.text.setString(to_string(projectileArray[counter].attackdamage));
						TextDisplay1.text.setPosition(enemyArray[counter2].rect.getPosition().x + enemyArray[counter2].rect.getSize().x / 2, enemyArray[counter2].rect.getPosition().y - enemyArray[counter2].rect.getSize().y / 2);
						TextDisplayArray.push_back(TextDisplay1);

						enemyArray[counter2].hp -= projectileArray[counter].attackdamage;

						if (enemyArray[counter2].hp <= 0)
						{
							enemyArray[counter2].alive = false;
						}

					
				}

				counter2++;
			}
			counter++;
		}

		//Projectile hit boss //collision

		counter = 0;
		for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
		{
			counter2 = 0;
			for (iter5 = bossArray.begin(); iter5 != bossArray.end(); iter5++)
			{

				if (projectileArray[counter].rect.getGlobalBounds().intersects(bossArray[counter2].rect.getGlobalBounds()))
				{
					

					Stab.play();
					projectileArray[counter].destroy = true;

					if (generateRandom(6) == 1) {
						enemy1.rect.setPosition(1200, 1500);
						enemyArray.push_back(enemy1);
					}
					else if (generateRandom(6) == 2) {
						enemy1.rect.setPosition(1200, 1000);
						enemyArray.push_back(enemy1);
					}
					else if (generateRandom(6) == 3) {
						enemy1.rect.setPosition(800, 1250);
						enemyArray.push_back(enemy1);
					}
					else if (generateRandom(6) == 4) {
						enemy1.rect.setPosition(600, 1350);
						enemyArray.push_back(enemy1);
					}

					//TExt display

					TextDisplay1.text.setString(to_string(projectileArray[counter].attackdamage));
					TextDisplay1.text.setPosition(bossArray[counter2].rect.getPosition().x + bossArray[counter2].rect.getSize().x / 2, bossArray[counter2].rect.getPosition().y - bossArray[counter2].rect.getSize().y / 2);
					TextDisplayArray.push_back(TextDisplay1);
					

					bossArray[counter2].hp -= projectileArray[counter].attackdamage;

					if (bossArray[counter2].hp <= 0)
					{
						bossArray[counter2].alive = false;
						cout << "WIN" << endl;
						
					}

					
				}

				counter2++;
			}
			counter++;
		}

		//Delete enemy when died
		counter = 0;
		for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
		{
			if (enemyArray[counter].alive == false)
			{
				cout << "Enemy slain" << endl;
				player1.score += 50;

				if (generateRandom(5) == 1)
				{
					enemy1.rect.setPosition(900, -300);
					enemyArray.push_back(enemy1);
				}
				if (generateRandom(5) == 2)
				{
					enemy1.rect.setPosition(1100, -500);
					enemyArray.push_back(enemy1);
				}
				if (generateRandom(5) == 3)
				{
					enemy1.rect.setPosition(1500, -700);
					enemyArray.push_back(enemy1);
				}

				//Drop coin
				if (generateRandom(4) == 1)
				{
					pickup1.isCoin = true;
					pickup1.isfood = false;
					pickup1.rect.setPosition(enemyArray[counter].rect.getPosition());
					PickupArray.push_back(pickup1);

				}
				//drop food
				else if (generateRandom(4) == 2)
				{
					pickup2.isCoin = false;
					pickup2.isfood = true;
					pickup2.rect.setPosition(enemyArray[counter].rect.getPosition());
					PickupArray.push_back(pickup2);
				}
				enemyArray.erase(iter4);

				break;
			}

			counter++;

		}

		//Delete boss when died
		counter = 0;
		for (iter5 = bossArray.begin(); iter5 != bossArray.end(); iter5++)
		{
			if (bossArray[counter].alive == false)
			{
				cout << "boss slain" << endl;

				bossArray.erase(iter5);

				
				cout << "Win" << endl;

				player1.movespeed = 0;
				TextDisplay1.text.setFillColor(Color::Cyan);
				TextDisplay1.movespeed = 0;
				TextDisplay1.text.setCharacterSize(40);
				TextDisplay1.lifetimecounter = 1000000;

				TextDisplay1.text.setString("Press ESC to exit    Your Score:  " + to_string(player1.score));
				TextDisplay1.text.setPosition(player1.rect.getPosition().x,player1.rect.getPosition().y);
				TextDisplayArray.push_back(TextDisplay1);

				TextDisplay1.text.setFillColor(Color::Red);
				TextDisplay1.movespeed = 2;
				TextDisplay1.text.setCharacterSize(25);
				TextDisplay1.lifetimecounter = 100;

				break;

		
			}
			counter++;
		}

		//Delete shot
		counter = 0;
		for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
		{
			if (projectileArray[counter].destroy == true)
			{
				projectileArray.erase(iter);
				break;
			}

			counter++;

		}

		 
		//Fire shots "Z"
		if (elapsed1.asSeconds() >= 0.5)
		{
			clock.restart();

			if (Keyboard::isKeyPressed(Keyboard::Z))
			{

				knifesound.play();
				projectile1.rect.setPosition(player1.rect.getPosition().x  ,player1.rect.getPosition().y  );
				projectile1.direction = player1.direction;
				projectileArray.push_back(projectile1);
				if (projectile1.attackdamage > 10)
				{
					knifesound.play();
					projectile1.rect.setPosition(player1.rect.getPosition().x + 10, player1.rect.getPosition().y + 10);
					projectile1.direction = player1.direction;
					projectileArray.push_back(projectile1);
				}
				if (projectile1.attackdamage > 30)
				{

					knifesound.play();
					projectile1.rect.setPosition(player1.rect.getPosition().x - 10, player1.rect.getPosition().y - 10);
					projectile1.direction = player1.direction;
					projectileArray.push_back(projectile1);
				}

				
			}
		}

		//Spawnboss
		if (Keyboard::isKeyPressed(Keyboard::H))
		{
			boss1.rect.setPosition(1000, 1300);
			bossArray.push_back(boss1);


		}
		

		//Draw Wall
		counter = 0;
		for (iter2 = wallArray.begin(); iter2 != wallArray.end(); iter2++)
		{
			wallArray[counter].update();
			window.draw(wallArray[counter].rect);
			window.draw(wallArray[counter].sprite);
			counter++;
		}

		


		//Draw Pickup items
		counter = 0;
		for (iter11 = PickupArray.begin(); iter11 != PickupArray.end(); iter11++)
		{

			PickupArray[counter].update();
			//window.draw(PickupArray[counter].rect); //check hitbox //checked
			window.draw(PickupArray[counter].sprite);

			counter++;
		}



		//Draw projectiles
		
		counter = 0;
		for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
		{
			projectileArray[counter].update(); 
			//window.draw(projectileArray[counter].rect); //check projectile hitbox //checked
			window.draw(projectileArray[counter].sprite);

			counter++;
		}

		//Delete text
		counter = 0;
		for (iter8 = TextDisplayArray.begin(); iter8 != TextDisplayArray.end(); iter8++)
		{
			if (TextDisplayArray[counter].destroy == true)
			{
				TextDisplayArray.erase(iter8);
				break;
			}

			counter++;

		}

		//Delete Pickup items
		counter = 0;
		for (iter11 = PickupArray.begin(); iter11 != PickupArray.end(); iter11++)
		{
			if (PickupArray[counter].destroy == true)
			{
				PickupArray.erase(iter11);
				break;
			}

			counter++;
		}


		
		


		//Update player
		player1.update();
		player1.updateMovement();
	
		//Player View
		window.setView(view1);
		view1.setCenter(player1.rect.getPosition());

		//Draw player
		window.draw(player1.sprite);
		//window.draw(player1.rect); //Use to check Hitbox


		//Draw Enemies
		counter = 0;
		for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
		{
			

			enemyArray[counter].update();
			enemyArray[counter].updateMovement();

			//window.draw(enemyArray[counter].rect); //Check enemy hitbox
			window.draw(enemyArray[counter].sprite);

			counter++;
		}
		//Draw boss

		counter = 0;
		for (iter5 = bossArray.begin(); iter5 != bossArray.end(); iter5++)
		{


			bossArray[counter].update();
			bossArray[counter].updateMovement();


			window.draw(bossArray[counter].sprite);
			//window.draw(bossArray[counter].rect); //check boss hitbox

			counter++;
		}
		

		//Draw Text
		counter = 0;
		for (iter8 = TextDisplayArray.begin(); iter8 != TextDisplayArray.end(); iter8++)
		{
			TextDisplayArray[counter].update();
			window.draw(TextDisplayArray[counter].text);

			counter++;

		}
		//Current HUD
		
		HP.setString("HP :  " + to_string(player1.hp) + "/ " + to_string(player1.maxhp));
		text.setString("DPS :  " + to_string(projectile1.attackdamage));
		text2.setString("Score: " + to_string(player1.score));

		window.draw(HP);
		window.draw(text);
		window.draw(text2);

		HP.setPosition(player1.rect.getPosition().x - window.getSize().x / 2, (player1.rect.getPosition().y - window.getSize().y / 2));
		text.setPosition(player1.rect.getPosition().x - window.getSize().x / 2, (player1.rect.getPosition().y - window.getSize().y / 2) + 30);
		text2.setPosition(player1.rect.getPosition().x - window.getSize().x / 2, (player1.rect.getPosition().y - window.getSize().y / 2) + 60);

		//Update window
		window.display();
	}
	return 0;

}

