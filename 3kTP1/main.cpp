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
		cout << "\n����"
			<< "\n1.�������������� �� �����"
			<< "\n2.�������� �������"
			<< "\n3.����� ������ �� �����"
			<< "\n4.������� �������"
			<< "\n5.���������� � ����"
			<< "\n0.����� ��� ����������\n->";
		cin >> c;

		switch (c)
		{
		case 1: {
			if (kipper.load("save.txt"))
				cout << "\t������ ������� ���������\n";
			else
				cout << "\t���� �� ������ ��� ��������\n";
			break; }
		case 2: {
			int type;
			cout << "\t�������� �������:\n"
				<< "\n\t1.��������� �����"
				<< "\n\t2.�����"
				<< "\n\t3.�������� �����\n\t->";
			cin >> type;
			switch (type)
			{
			case 1: {
				std::string Weapon;
				int crew, Length, Width, TimeUnderWater, MaxUnderWaterSpeed;
				cout << "\t������: ";
				cin >> crew;
				cout << "\t����� �������: ";
				cin >> Length;
				cout << "\t������ �������: ";
				cin >> Width;
				cout << "\t����� ��� �����: ";
				cin >> TimeUnderWater;
				cout << "\t������������ ��������� ��������: ";
				cin >> MaxUnderWaterSpeed;
				cout << "\t����������: ";
				cin >> Weapon;
				kipper.add(new Submarine(crew, Length, Width, TimeUnderWater, MaxUnderWaterSpeed, Weapon));
				cout << "\t������� �" << kipper.size() << " ������� ��������\n";
				break; }
			case 2: {

				string purpose, hull_material, driving_characteristics;
				int speed, crew;
				cout << "\t������� ����������: ";
				cin >> purpose;
				cout << "\t�������� �������: ";
				cin >> hull_material;
				cout << "\t������� ��������: ";
				cin >> driving_characteristics;
				cout << "\t��������: ";
				cin >> speed;
				cout << "\t������: ";
				cin >> crew;
				kipper.add(new Speedboat(purpose, hull_material, driving_characteristics, speed, crew));
				cout << "\t������� �" << kipper.size() << " ������� ��������\n";
				break; }
			case 3: {
				string type, name;
				int hull_length, speed, crew;
				bool is_peaceful;
				cout << "\t������� ���: ";
				getline(cin, type);
				cout << "\t������� ���: ";
				getline(cin, name);
				cout << "\t������ �� �������?(1/0) ";
				cin >> is_peaceful;
				cout << "\t����� �������: ";
				cin >> hull_length;
				cout << "\t��������: ";
				cin >> speed;
				cout << "\t'������: ";
				cin >> crew;
				kipper.add(new Sailboat(type, name, is_peaceful, hull_length, speed, crew));
				cout << "\t������� �" << kipper.size() << " ������� ��������\n";
				break; }
			default: cout << "\t������� ������������ ��������!\n";
			}
			break; }
		case 3: {
			if (kipper.size() == 0)
				cout << "\t�������� ���.\n";
			else
				kipper.print();
			break; }
		case 4: {
			if (kipper.size() == 0)
				cout << "\t�������� ���.\n";
			else
			{
				size_t num;
				cout << "\t�������� �������. ��������: �"
					<< (kipper.size() == 1 ? "" : "1 - �")
					<< (kipper.size() == 1 ? 1 : kipper.size())
					<< "\n\t->";
				cin >> num;
				try
				{
					kipper.del(num - 1);
					cout << "\t������ ������� �������\n";
				}
				catch (int)
				{
					cout << "\t������� ������������ ��������!\n";
				}
			}
			break; }
		case 5: {
			if (kipper.save("save.txt"))
				cout << "\t������ ������� ���������\n";
			else
				cout << "\t��� ���������� ��������� ������\n";
			break; }
		case 0: {
			cout << "\t\t  ��� ������������� ������ ����� �������!"
				<< "\n\t\t  ����������?(1-�� / 0-���)\n\t\t->";
			cin >> c;
			if (c == 1) return 0; }
		}
	}
}