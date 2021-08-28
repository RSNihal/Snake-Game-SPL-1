#include <vector>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>

class Snake
{
    private:
        int snake_head, z, Dollars, time_tail, Bonus, time, tail;

        char *map;
        bool Left, Right, Down, Up, Bool_Condition;
        std::vector<int> past;

    public:
        Snake()
        {
            map = new char[2000];
            Left = 0;
            Right = 1;
            Down = 0;
            Up = 0;
            Bool_Condition = 0;
            tail = 1;
            snake_head = 1000;
            Dollars = 0;
            Bonus = 0;
            time = 40;
            z = 1;
        }

        ~Snake()
        {
            delete[] map;
        }

        void Graphics();
        void GameLogic();
        void KEYBOARD();
        void Pineapple();
        int GameOver();
        void Start();
        friend void clearscreen();
        friend void sp();
        friend void s();
};

void clearscreen()
{
    HANDLE hOut;
    COORD Position;

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    Position.X = 0;
    Position.Y = 0;
    SetConsoleCursorPosition(hOut, Position);
}

void sp(int choosecolor)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), choosecolor);
}
void s()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

}

void Snake::Start()
{
    for (int p = 0; p < 2000; p++)
    {
        map[p] = ' ';
    }

    map[snake_head] = char(219);
    Pineapple();
    Graphics();
}

int Snake::GameOver()
{
    Sleep(2500);
    system("cls");
    std::cout << std::endl
              << "Your Score " << Dollars + Bonus << " Point";

    Sleep(1800);
    return 0;
}
void Snake::Graphics()
{
    sp(697);
    std::cout << Dollars + Bonus;
    std::cout << "\n";
    s();
    for (int u = 0; u < 50; u++)
    {
        sp(750);
        std::cout << char(219);
        s();
    }

    std::cout << std::endl;

    for (int x1 = 0; x1 < 2000; x1++)
    {
        if (x1 % 50 == 0 && x1 != 0)
        {
            std::cout << std::endl;
        }
        if (x1 % 50 == 0 || (x1 - (x1 / 50)) % 49 == 0)
        {
            map[x1] = char(219);
            sp(750);
            std::cout << map[x1];
            s();
        }
        else if (map[x1] != char(219) && map[x1] != map[z])
        {
            std::cout << map[x1];
        }
        else if (x1 == z)
        {
            sp(10);
            std::cout << map[x1];
            s();
        }
        else
        {
            sp(750);
            std::cout << map[x1];
            s();
        }
    }

    std::cout << std::endl;

    for (int u = 0; u < 50; u++)
    {
        sp(750);
        std::cout << char(219);
        s();
    }
    if (Up == 1 || Down == 1)
    {
        Sleep(19);
    }
    if (map[z] == char(5))
    {
        time--;
        if (time == 0)
        {
            Dollars++;
            time = 40;
            Pineapple();
        }
    }

    clearscreen();
    GameLogic();
}

void Snake::Pineapple()
{
    map[z] = ' ';
    if (Dollars % 8 != 0 || Dollars == 0)

    {
        while (map[z] != ' ' && z % 50 != 0 && (z - (z / 50)) % 49 != 0)
            ;

        {
            z = rand() % 2000 + 1;
        }

        map[z] = char(229);

    }

    else
    {
        while (map[z] != ' ' && z % 50 != 0 && (z - (z / 50)) % 49 != 0)
            ;

        {
            z = rand() % 2000 + 1;
        }
        map[z] = char(5);
    }
}

void Snake::KEYBOARD()
{

    if (_kbhit())

    {
        char key;
        key = _getch();
        switch (key)
        {
        case 'd':

            {
                if (Left == 0)
                {
                    Left = 0, Up = 0, Down = 0,
                        Right = 1;
                }
                break;
            }

        case 'w':
        {
            if (Down == 0)
            {
                Left = 0, Down = 0, Right = 0,
                Up = 1;
            }
            break;
        }

        case 'a':
        {
            if (Right == 0)
            {
                Down = 0, Up = 0, Right = 0,
                Left = 1;
            }
            break;
        }

        case 's':
        {
            if (Up == 0)
            {
                Left = 0, Up = 0, Right = 0,
                Down = 1;
            }
            break;
        }
        }
    }
}


void Snake::GameLogic()
{
    past.insert(past.begin(), snake_head);
    KEYBOARD();
    if (Right == 1)
    {
        snake_head++;
    }
    else if (Left == 1)
    {
        snake_head--;
    }
    else if (Up == 1)
    {
        snake_head -= 50;
    }
    else
    {
        snake_head += 50;
    }
    if (map[snake_head] == char(219) || snake_head % 50 == 0 || snake_head > 2000 || snake_head < 0 || (snake_head - (snake_head / 50)) % 49 == 0)

    {
        GameOver();
        return;
    }
    if (map[snake_head] == char(229))

    {
        Bool_Condition = true;
        tail++;
        Pineapple();
        Dollars++;
    }
    else if (map[snake_head] == char(5))
    {
        Bool_Condition = true;
        tail++;
        Pineapple();
        Bonus += time;
    }

    map[snake_head] = char(219);

    if (Bool_Condition == false)
    {
        time_tail = past[past.size() - tail];
        map[time_tail] = ' ';
    }

    Bool_Condition = false;
    if (tail != 1)
    {
        for (int u = past.size() - 2; u > 0; u--)
        {
            past[u + 1] = past[u];
        }
        past.erase(past.end() - tail);
    }
    else
    {
        past.erase(past.begin());
    }
    Graphics();
}
int main()
{
    srand((unsigned)time(0));
    Snake SNAKE;
    SNAKE.Start();
}


