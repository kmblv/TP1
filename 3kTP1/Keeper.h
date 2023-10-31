#pragma once
#include <fstream>
#include <string>
#include "List.h"
#include "Ship.h"
#include "Submarine.h"
#include "Sailboat.h"
#include "Speedboat.h"
class Keeper
{
private:
	List<Ship*> ships;

public:
	Keeper();
	~Keeper();
	void print();					// вывод на экран производных объектов абстрактного класса Base
	void add(Ship* elem);			// добавление     производных объектов абстрактного класса Base
	void del(size_t num);			// удаление       производных объектов абстрактного класса Base
	bool save(std::string file);			// полное сохранение     себя в  файле
	bool load(std::string file);			// полное восстановление себя из файла
	size_t size();
};

///////////////////////////


Keeper::Keeper()
{
	std::cout << "Keeper()\n";
}

Keeper::~Keeper()
{
	std::cout << "~Keeper()\n";
}

void Keeper::print()
{
	for (size_t i = 0; i < ships.size(); i++)
		std::cout << "\n\n------------------------------------------------------------------------------\n\n"
		<< "Корабль № " << i + 1 << ":\n" << ships[i]->getPrintData();
}

void Keeper::add(Ship* elem)
{
	ships.push_back(elem);
}

void Keeper::del(size_t num)
{
	delete ships.pop(num);
}

bool Keeper::save(string file)
{
	std::ofstream fout(file);
	if (!fout) return 0;
	fout << to_string(ships.size()) << std::endl;
	for (size_t i = 0; i < ships.size(); ++i)
		fout << ships[i]->getData();

	fout.close();
	return 1;
}

bool Keeper::load(string file)
{
	std::ifstream fin(file);
	if (!fin) return 0;

	std::string type;
	size_t ship_amount;

	fin >> ship_amount;
	for (size_t i = 0; i < ship_amount; i++)
	{
		fin >> type;
		if (type == "Sailboat")
		{

			std::string Type, name;
			int hull_length, speed, crew;
			bool is_peaceful;
			fin >> crew >> Type >> name >> is_peaceful >> hull_length >> speed;
			ships.push_back(new Sailboat(Type, name, is_peaceful, hull_length, speed, crew));
		}
		else if (type == "Speedboat")
		{
			std::string purpose, hull_material, driving_characteristics;
			int speed, crew;
			fin >> crew >> purpose >> hull_material >> driving_characteristics >> speed;
			ships.push_back(new Speedboat(purpose, hull_material, driving_characteristics, speed, crew));
		}
		else if (type == "Submarine")
		{
			double Length, Width;
			int TimeUnderWater, MaxUnderWaterSpeed, crew;
			std::string Weapon;

			fin >> crew >> Length >> Width >> TimeUnderWater >> MaxUnderWaterSpeed >> Weapon;
			ships.push_back(new Submarine(crew, Length, Width, TimeUnderWater, MaxUnderWaterSpeed, Weapon));
		}
	}
	return 1;
}

size_t Keeper::size()
{
	return ships.size();
}