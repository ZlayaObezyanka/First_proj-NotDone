#include <iostream>
#include <windows.h>
#include <conio.h>

#include "New_game.h"
//#include <windows.h>

#define UP 72
#define DOWN 80
#define ENTER 13

//void go_xy(int x, int y)
//{
//	COORD pos = { x, y };
//	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleCursorPosition(hCon, pos);
//}

class Menu
{
public:
	Menu() {}
	~Menu()
	{}

	void open()
	{	menu();	}

private:
	int menu()
	{
		Go_new_game go_game;
		char menu_navigatoion = 0;
		int activ_menu = 0;
		int complexity = 1;
		int y = 10;
		std::string Menu[] = {"Новая игра     ", "Выбор сложности", "Выбор персонажа", "Выход          "};

		while (true)
		{
			system("CLS");
			for (size_t i = 0; i < size(Menu); i++)
			{
				go_xy(40, y);
				++y;
				if (activ_menu == i)
				{
					std::cout << "»" << Menu[i] << "«" << std::endl;
				}
				else
					std::cout << " " << Menu[i] << " " << std::endl;

			}

			y = 10;

			menu_navigatoion = _getch();
			if (menu_navigatoion == -32)
			{
				menu_navigatoion = _getch();
			}
			//std::cout <<(int) menu_navigatoion;

			//std::cin >> menu_navigatoion;

			switch (menu_navigatoion)
			{
				case UP:
				{ 
					if (activ_menu > 0)
					--activ_menu;
					break;
				}

				case DOWN:
				{
					if (activ_menu < size(Menu) - 1)
						++activ_menu;
					break;
				}

				case ENTER:
				{
					if (activ_menu == 0)
					{
						
						go_game.game(complexity);
					}
					else if (activ_menu == 1)
					{
						complexity_game(complexity);
					}
					else if (activ_menu == 2)
					{
						system("CLS");
						std::cout << "В разработке" << std::endl;
						Sleep(4000);
					}
					else if (activ_menu == 3)
						exit(0);

					break;
				}
			default:
				break;
			
			}
		}
		return 0;
	}
	
	int complexity_game(int& co)
	{
		int y = 10;
		char select_complexity;
		int activ_menu = 0;
		std::string menu_navig[] = { "Лёгкий", "Средний", "Тяжелый" };
		do
		{
			system("CLS");
			for (int i = 0; i < size(menu_navig); i++)
			{
				go_xy(40, y);
				++y;
				if (activ_menu == i)
				{
					std::cout << "»" << menu_navig[i] << "«" << std::endl;
				}
				else
					std::cout << " " << menu_navig[i] << " " << std::endl;
			} 
			y = 10;
			select_complexity = _getch();
			if (select_complexity == -32)
				select_complexity = _getch();

			switch (select_complexity)
			{
			case UP:
			{
				if (activ_menu > 0)
				{
					--activ_menu;
					break;
				}
			}
			case DOWN:
			{
				if (activ_menu < size(menu_navig) - 1)
				{
					++activ_menu;
					break;
				}
			}
			case ENTER:
			{
				if (activ_menu == 0)
				{
					co = 1;
					return co;
				}
				else if (activ_menu == 1)
				{
					co = 2;
					return co;
				}
				else
				{
					co = 3;
					return co;
				}
			}

			default:
				break;
			}
		} 
		while (true);

	}
};
