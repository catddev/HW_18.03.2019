#include <iostream>
#include <iomanip>
#include<math.h>
#include<ctime>
#include<cstring>
#include<fstream>

using namespace std;

//1.**Описать структуру Data(день, месяц, год).
// Описать структуру Student(фамилия, группа, дата поступления).
// Проиллюстрировать работу с этим классом.
struct Date {
	int day, month, year;
};
struct Student {
	char surname[30];
	char group[10];
	Date regist;

	void print() {
		cout << surname << " " << group << " ";
		cout << regist.day << "." << regist.month << "." << regist.year << endl;
	}
};

//2.**Описать структуру ОЗУ(фирма, частота, объем).
// Создать массив экземпляров структуры ОЗУ и написать программу, позволяющую:
//-динамически изменять размер массива;
//-выводить список памяти с частотой больше заданной;
//-выводить список памяти с объемом больше заданного;
struct ozu {
	char manufact[30];
	int freq;
	int vol;

	void print() {
		cout << manufact << " " << freq << " MHz " << vol << " GB" << endl;
	}
};

int main()
{
	srand(time(NULL));

	setlocale(LC_ALL, "Rus");

	int tn = 0;

	while (true)
	{
		cout << "Задача № ";
		cin >> tn; cin.get();

		switch (tn)
		{
		case 1:
		{
			ifstream in_file("in.txt");
			Student *s;
			int n;
			in_file >> n;
			s = new Student[n];

			for (int i = 0; i < n; i++)
				in_file >> s[i].surname >> s[i].group >> s[i].regist.day >> s[i].regist.month >> s[i].regist.year;

			int choice;
			while (true)
			{
				cout << endl;
				cout << "Enter 1 to search by surname" << endl;
				cout << "Enter 2 to search by group" << endl;
				cout << "Enter 3 to search by date" << endl;
				cout << "Enter 4 to print all" << endl;
				cout << "Enter 0 to exit" << endl;
				cin >> choice;
				if (choice == 0) break;
				switch (choice)
				{
				case 1:
					char sn[30];
					cout << "Enter needed surname" << endl;
					cin >> sn;
					for (int i = 0; i < n; i++)
						if (strcmp(sn, s[i].surname) == 0)
							s[i].print();
					break;
				case 2:
					char gr[10];
					cout << "Enter needed group" << endl;
					cin >> gr;
					for (int i = 0; i < n; i++)
						if (strcmp(gr, s[i].group) == 0)
							s[i].print();
					break;
				case 3:
				{
					int d, m, y;
					int k = 0;
					cout << "Enter needed date: day, month and year" << endl;
					cin >> d >> m >> y;
					for (int i = 0; i < n; i++)
					{
						k = 0;
						if (d == s[i].regist.day) k++;
						if (m == s[i].regist.month) k++;
						if (y == s[i].regist.year) k++;
						if (k == 3) s[i].print();
					}
				}
				break;
				case 4:
					for (int i = 0; i < n; i++)
						s[i].print();
					cout << endl;
					break;
				}
			}
			delete[] s;
		}
		break;
		case 2:
		{
			ifstream in_file("in2.txt");
			ozu *RAM;
			int n;
			in_file >> n;
			RAM = new ozu[n];

			for (int i = 0; i < n; i++)
				in_file >> RAM[i].manufact >> RAM[i].freq >> RAM[i].vol;

			int choice;
			while (true)
			{
				cout << endl;
				cout << "Enter 1 to search by frequency" << endl;
				cout << "Enter 2 to search by volume" << endl;
				cout << "Enter 3 to print all" << endl;
				cout << "Enter 0 to exit" << endl;
				cin >> choice;
				if (choice == 0) break;
				switch (choice)
				{
				case 1:
					int f;
					cout << "Enter minimal needed frequency" << endl;
					cin >> f;
					for (int i = 0; i < n; i++)
						if (f <= RAM[i].freq)
							RAM[i].print();
					break;
				case 2:
					int v;
					cout << "Enter minimal needed volume" << endl;
					cin >> v;
					for (int i = 0; i < n; i++)
						if (v <= RAM[i].vol)
							RAM[i].print();
					break;
				case 3:
					for (int i = 0; i < n; i++)
						RAM[i].print();
					cout << endl;
					break;
				}
			}
			delete[] RAM;
		}
		break;
		default:
			cout << "нет такой задачи" << endl << endl;
		}
	}
	system("pause");
	return 0;
}