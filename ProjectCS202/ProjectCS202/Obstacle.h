#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cstdlib>
#include <vector>
#include <iostream>
#include "DEFINITIONS.hpp"

using std::vector;
using std::string;


class Obstacle {
private:
	sf::Vector2f recPos;
	sf::Sprite sprite;
	sf::Texture model;
	float _Speed;
	float _Level;
	bool _RedLight;
public:
	Obstacle(float level);

	void SetTexture(string Load);
	void SetPosXY(float length, float height);
	void SetSpeed(float Coefficient);

	void Move(float width);
	void SwitchLightSignal();
	bool CheckLight();
	void Draw(sf::RenderWindow& window);
};

class Car : public Obstacle {
public:
	Car(float level);
	void LightSignal();
};

class Truck : public Obstacle {
public:
	Truck(float level);
	void LightSignal();
};

class Sheep : public Obstacle {
public:
	Sheep(float level);
};

class Dog : public Obstacle {
public:
	Dog(float level);
};

vector<Car> InitCar(float level);
vector<Truck> InitTruck(float level);
vector<Sheep> InitSheep(float level);
vector<Dog> InitDog(float level);
void InitTraffic(vector<sf::Sprite>& TrafficLight, sf::Texture& light);

void SwitchLightRed(vector<sf::Sprite>& TrafficLight, sf::Texture& light);
void SwitchLightGreen(vector<sf::Sprite>& TrafficLight, sf::Texture& light);
void CheckTime(sf::Clock& clock, sf::Time& elapsed, vector<sf::Sprite>& TrafficLight, sf::Texture& light, vector<Car>& testC, vector<Truck>& testT);

void MoveCar(vector<Car>& testC, sf::RenderWindow& window);
void MoveTruck(vector<Truck>& testT, sf::RenderWindow& window);
void MoveSheep(vector<Sheep>& testS, sf::RenderWindow& window);
void MoveDog(vector<Dog>& testD, sf::RenderWindow& window);