#include <iostream>
#include <sstream>
#include <stdio.h>
#include <thread>
#include <chrono>

char board_spaces[15] = {'+'};
int current_pos = 0;

void fillArray(char str[15])
{
    for (int i = 1; i < 15; i++)
    {
        str[i] = '.';
    }
}

void moveSpace(int steps)
{
    if (current_pos + steps > 14)
    {
        board_spaces[current_pos] = '.';
        board_spaces[current_pos + steps - 15] = '+';
        current_pos = current_pos + steps - 15;
    }
    else
    {
        board_spaces[current_pos] = '.';
        board_spaces[current_pos + steps] = '+';
        current_pos = current_pos + steps;
    }
}

void printBoard()
{
    for (int i = 0; i < 15; i++)
    {
        std::cout << board_spaces[i];
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

int main()
{
    std::cout << std::endl;
    std::cout << ("Welcome to The Ploy of the Jailor") << std::endl;
    std::cout << std::endl;

    /////////// Board Initialization ////////////////
    int silver_coin = rand() % 14;
    int winning_condition = 0;

    fillArray(board_spaces); // Fills board with periods

    board_spaces[silver_coin] = 'x';
    std::cout << ("The jailor has put their silver coin in space ");
    std::cout << silver_coin + 1 << std::endl;

    printBoard();

    int first_gold, second_gold;

    std::cout << ("enter your first gold coin location:  ");
    std::cin >> first_gold;

    std::cout << ("enter your second gold coin location:  ");
    std::cin >> second_gold;
    std::cout << std::endl;

    board_spaces[first_gold - 1] = 's';
    board_spaces[second_gold - 1] = 's';

    first_gold = first_gold - 1;
    second_gold = second_gold - 1;

    std::cout << ("Current board: ");
    printBoard();
    std::cout << std::endl;

    ///////////////////////////////////////////////////

    while (winning_condition == 0) // As long at winning_conditions equals 0, the game continues
    {
        int dice_roll = rand() % 7 + 1;

        std::cout << ("Previous space: ") << current_pos + 1 << std::endl;

        std::cout << ("You moved ") << dice_roll << (" spaces") << std::endl;

        moveSpace(dice_roll);

        std::cout << ("New space: ") << current_pos + 1 << std::endl;

        printBoard();

        if (current_pos == silver_coin)
        {
            std::cout << ("loser") << std::endl;
            winning_condition = 1;
        }
        if (current_pos == first_gold || current_pos == second_gold)
        {
            std::cout << ("winner") << std::endl;
            winning_condition = 2;
        }
        else
        {
            winning_condition == 0;
        }
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}