#include <iostream>
#include <string>
#include <Windows.h>
#include "List.h"
#include "Keeper.h"
#include "Ship.h"
#include "Submarine.h"
#include "Speedboat.h"
#include "Sailboat.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Keeper kipper;
	int c;

	while (true)
	{
		cout << "\nМеню"
			<< "\n1.Восстановление из файла"
			<< "\n2.Добавить Корабль"
			<< "\n3.Вывод данных на экран"
			<< "\n4.Удалить Корабль"
			<< "\n5.Сохранение в файл"
			<< "\n0.Выход без сохранения\n->";
		cin >> c;

		switch (c)
		{
		case 1: {
			if (kipper.load("save.txt"))
				cout << "\tДанные успешно загружены\n";
			else
				cout << "\tФайл не найден или повреждён\n";
			break; }
		case 2: {
			int type;
			cout << "\tВыберите Корабль:\n"
				<< "\n\t1.Подводная лодка"
				<< "\n\t2.Катер"
				<< "\n\t3.Парусная лодка\n\t->";
			cin >> type;
			switch (type)
			{
			case 1: {
				std::string Weapon;
				int crew, Length, Width, TimeUnderWater, MaxUnderWaterSpeed;
				cout << "\tЭкипаж: ";
				cin >> crew;
				cout << "\tДлина корпуса: ";
				cin >> Length;
				cout << "\tШирина корпуса: ";
				cin >> Width;
				cout << "\tВремя под водой: ";
				cin >> TimeUnderWater;
				cout << "\tМаксимальная подводная скорость: ";
				cin >> MaxUnderWaterSpeed;
				cout << "\tВооружение: ";
				cin >> Weapon;
				kipper.add(new Submarine(crew, Length, Width, TimeUnderWater, MaxUnderWaterSpeed, Weapon));
				cout << "\tКорабль №" << kipper.size() << " успешно добавлен\n";
				break; }
			case 2: {

				string purpose, hull_material, driving_characteristics;
				int speed, crew;
				cout << "\tВведите назначение: ";
				cin >> purpose;
				cout << "\tМатериал корпуса: ";
				cin >> hull_material;
				cout << "\tХодовые свойства: ";
				cin >> driving_characteristics;
				cout << "\tСкорость: ";
				cin >> speed;
				cout << "\tЭкипаж: ";
				cin >> crew;
				kipper.add(new Speedboat(purpose, hull_material, driving_characteristics, speed, crew));
				cout << "\tКорабль №" << kipper.size() << " успешно добавлен\n";
				break; }
			case 3: {
				string type, name;
				int hull_length, speed, crew;
				bool is_peaceful;
				cout << "\tВведите тип: ";
				getline(cin, type);
				cout << "\tВведите имя: ";
				getline(cin, name);
				cout << "\tМирный ли корабль?(1/0) ";
				cin >> is_peaceful;
				cout << "\tДлина корпуса: ";
				cin >> hull_length;
				cout << "\tСкорость: ";
				cin >> speed;
				cout << "\t'Экипаж: ";
				cin >> crew;
				kipper.add(new Sailboat(type, name, is_peaceful, hull_length, speed, crew));
				cout << "\tКорабль №" << kipper.size() << " успешно добавлен\n";
				break; }
			default: cout << "\tВыбрано недопустимое значение!\n";
			}
			break; }
		case 3: {
			if (kipper.size() == 0)
				cout << "\tКораблей нет.\n";
			else
				kipper.print();
			break; }
		case 4: {
			if (kipper.size() == 0)
				cout << "\tКораблей нет.\n";
			else
			{
				size_t num;
				cout << "\tВыбирите Корабль. Доступны: №"
					<< (kipper.size() == 1 ? "" : "1 - №")
					<< (kipper.size() == 1 ? 1 : kipper.size())
					<< "\n\t->";
				cin >> num;
				try
				{
					kipper.del(num - 1);
					cout << "\tДанные успешно удалены\n";
				}
				catch (int)
				{
					cout << "\tВыбрано недопустимое значение!\n";
				}
			}
			break; }
		case 5: {
			if (kipper.save("save.txt"))
				cout << "\tДанные успешно сохранены\n";
			else
				cout << "\tПри сохранении произошла ошибка\n";
			break; }
		case 0: {
			cout << "\t\t  Все несохраненные данные будут утеряны!"
				<< "\n\t\t  Продолжить?(1-Да / 0-Нет)\n\t\t->";
			cin >> c;
			if (c == 1) return 0; }
		}
	}
}