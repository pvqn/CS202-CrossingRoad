#include "Obstacle.h"


Obstacle::Obstacle(float level)
{
	_Level = level;
	_RedLight = 0;
}
void Obstacle::SetTexture(string Load)
{
	model.loadFromFile(Load);
	sprite.setTexture(model);
}

void Obstacle::SetPosXY(float length, float height)
{
	recPos.x = length;
	recPos.y = height;
}

void Obstacle::Move(int width)
{
	recPos.x += _Speed;
	if (recPos.x > SCREEN_WIDTH) recPos.x = -width;
	else if (recPos.x < -width) recPos.x = SCREEN_WIDTH;
}

void Obstacle::SetSpeed(float Coefficient)
{
	_Speed = _Level * Coefficient;
}

void Obstacle::SwitchLightSignal()
{
	_RedLight = !_RedLight;
}

bool Obstacle::CheckLight()
{
	if (_RedLight) return true;
	return false;
}

void Obstacle::Draw(sf::RenderWindow& window)
{
	sprite.setPosition(recPos);
	window.draw(sprite);
}



Car::Car(float level) : Obstacle(level) {
	SetSpeed(CAR_SPEED);
};
void Car::LightSignal()
{
	if (CheckLight()) SetSpeed(0);
	else SetSpeed(CAR_SPEED);
}

Truck::Truck(float level) : Obstacle(level) {
	SetSpeed(TRUCK_SPEED);
};
void Truck::LightSignal()
{
	if (CheckLight()) SetSpeed(0);
	else SetSpeed(TRUCK_SPEED);
}

Sheep::Sheep(float level) : Obstacle(level) {
	SetSpeed(SHEEP_SPEED);
}

Dog::Dog(float level) : Obstacle(level) {
	SetSpeed(-DOG_SPEED);
}

vector<Car> InitCar(int level)
{
	vector<Car> testC;
	for (int i = 0; i < VEHICLE_AMOUNT; ++i) {
		testC.push_back(Car(level));
		testC[i].SetPosXY(i * (VEHICLE_WIDTH + (SCREEN_WIDTH - VEHICLE_AMOUNT * VEHICLE_WIDTH) / (VEHICLE_AMOUNT - 1)), 240);
	}
	string Load = string(RESOURCE_PATH) + "car.png";
	for (int i = 0; i < VEHICLE_AMOUNT; ++i) {
		testC[i].SetTexture(Load);
	}
	return testC;
}

vector<Truck> InitTruck(int level)
{
	vector<Truck> testT;
	for (int i = 0; i < VEHICLE_AMOUNT; ++i) {
		testT.push_back(Truck(level));
		testT[i].SetPosXY(i * (VEHICLE_WIDTH + (SCREEN_WIDTH - VEHICLE_AMOUNT * VEHICLE_WIDTH) / (VEHICLE_AMOUNT - 1)), 636);
	}
	string Load = string(RESOURCE_PATH) + "truck.png";
	for (int i = 0; i < VEHICLE_AMOUNT; ++i) {
		testT[i].SetTexture(Load);
	}
	return testT;
}

vector<Sheep> InitSheep(int level)
{
	vector<Sheep> testS;
	for (int i = 0; i < ANIMAL_AMOUNT; ++i) {
		testS.push_back(Sheep(level));
		testS[i].SetPosXY(i * (ANIMAL_WIDTH + (SCREEN_WIDTH - ANIMAL_AMOUNT * ANIMAL_WIDTH) / (ANIMAL_AMOUNT - 1)), 504);
	}
	string Load = string(RESOURCE_PATH) + "sheep.png";
	for (int i = 0; i < ANIMAL_AMOUNT; ++i) {
		testS[i].SetTexture(Load);
	}
	return testS;
}

vector<Dog> InitDog(int level)
{
	vector<Dog> testD;
	for (int i = 0; i < ANIMAL_AMOUNT; ++i) {
		testD.push_back(Dog(level));
		testD[i].SetPosXY(i * (ANIMAL_WIDTH + (SCREEN_WIDTH - ANIMAL_AMOUNT * ANIMAL_WIDTH) / (ANIMAL_AMOUNT - 1)), 373);
	}
	string Load = string(RESOURCE_PATH) + "shiba.png";
	for (int i = 0; i < ANIMAL_AMOUNT; ++i) {
		testD[i].SetTexture(Load);
	}
	return testD;
}

void InitTraffic(vector<sf::Sprite>& TrafficLight, sf::Texture& light)
{
	sf::Sprite TL;
	string Load = string(RESOURCE_PATH) + "greentrafficlight.png";
	light.loadFromFile(Load);
	TL.setTexture(light);
	TrafficLight.push_back(TL);
	TrafficLight.push_back(TL);
	TrafficLight[0].setPosition(sf::Vector2f(0, 174));
	TrafficLight[1].setPosition(sf::Vector2f(0, 437));
}

void SwitchLightRed(vector<sf::Sprite>& TrafficLight, sf::Texture& light)
{
	string Load = string(RESOURCE_PATH) + "redtrafficlight.png";
	light.loadFromFile(Load);
	TrafficLight[0].setTexture(light);
	TrafficLight[1].setTexture(light);
}

void SwitchLightGreen(vector<sf::Sprite>& TrafficLight, sf::Texture& light)
{
	string Load = string(RESOURCE_PATH) + "greentrafficlight.png";
	light.loadFromFile(Load);
	TrafficLight[0].setTexture(light);
	TrafficLight[1].setTexture(light);
}

void CheckTime(sf::Clock& clock, sf::Time& elapsed, vector<sf::Sprite>& TrafficLight, sf::Texture& light, vector<Car>& testC, vector<Truck>& testT)
{
	if (elapsed.asSeconds() >= LIGHT_TIME) {
		if (testC[0].CheckLight())
			SwitchLightGreen(TrafficLight, light);
		else SwitchLightRed(TrafficLight, light);

		for (int i = 0; i < 4; ++i) {
			testC[i].SwitchLightSignal();
			testT[i].SwitchLightSignal();
			clock.restart();
		}
	}
}



void MoveCar(vector<Car>& testC, sf::RenderWindow& window)
{
	for (int i = 0; i < testC.size(); ++i)
	{
		testC[i].LightSignal();
		testC[i].Draw(window);
		testC[i].Move(VEHICLE_WIDTH);
	}
}

void MoveTruck(vector<Truck>& testT, sf::RenderWindow& window)
{
	for (int i = 0; i < testT.size(); ++i)
	{
		testT[i].LightSignal();
		testT[i].Draw(window);
		testT[i].Move(VEHICLE_WIDTH);
	}
}

void MoveSheep(vector<Sheep>& testS, sf::RenderWindow& window)
{
	for (int i = 0; i < testS.size(); ++i)
	{
		testS[i].Draw(window);
		testS[i].Move(ANIMAL_WIDTH);
	}
}

void MoveDog(vector<Dog>& testD, sf::RenderWindow& window)
{
	for (int i = 0; i < testD.size(); ++i)
	{
		testD[i].Draw(window);
		testD[i].Move(ANIMAL_WIDTH);
	}
}