#include <iostream>

#define UP 72
#define DOWN 80

void go_xy(int x, int y)
{
	COORD pos = { x, y };
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hCon, pos);
}

class Go_new_game
{
public:
	Go_new_game() {}
	~Go_new_game() {}

	void game(int &co)
	{
		do
		{
			if (_kbhit())
			{
				switch (_getch())
				{
				case UP:

					jump();

				default:
					break;
				}
			}


			go_xy(x, y);
			for (int i = 0; i < 2; i++)
			{
				std::cout << "__" << std::endl;
				go_xy(x, y+1);
			}

			Sleep(143);
			system("CLS");
			x++;

		} while (true);

		std::cout << co << std::endl;
	}

private:
	char person_up;
	int x = 0;
	int y = 10;

	void jump()
	{
		for (int i = 0, z = -5; i < 8; i++, z++)
		{
			Sleep(143);
			system("CLS");

			if (i < 5)
			{
				go_xy(x +i, y - i);
				for (size_t i = 0; i < 2; i++)
				{
					std::cout << "__" << std::endl;
				}

			}
			else if (i == 5)
			{
				go_xy(x, y);
				std::cout << "__" << std::endl;
			}
			else {
				go_xy(x - z, y + z);
				std::cout << "__" << std::endl;
			}
		}
	}
};
