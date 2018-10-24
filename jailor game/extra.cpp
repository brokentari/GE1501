#include <iostream>
#include <sstream>
#include <stdio.h>
#include <thread>
#include <chrono>

/*
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
    std::cout << std::endl
              << std::endl;
}

void hard_mode()
{
    int first_silver = rand() % 14;
    int second_silver = rand() % 14;

    while (first_silver == second_silver)
    {
        srand(rand() * 255);
        first_silver = rand() % 14;
        second_silver = rand() % 14;
    }

    int winning_condition = 0;
    int gold_coin;

    fillArray(board_spaces); // Fills board with periods

    board_spaces[first_silver] = 'x';
    std::cout << ("The jailor has put their first silver coin in space ") << first_silver + 1 << std::endl;

    board_spaces[second_silver] = 'x';
    std::cout << ("The jailor has put their second silver coin in space ") << second_silver + 1 << std::endl;

    printBoard();

    std::cout << ("Enter your gold coin location:  ");
    std::cin >> gold_coin;

    gold_coin = gold_coin - 1;
    board_spaces[gold_coin] = 's';

    std::cout << ("Current board: ");
    printBoard();
    std::cout << std::endl;

    while (winning_condition == 0) // As long at winning_conditions equals 0, the game continues
    {
        int dice_roll = rand() % 7 + 1;

        std::cout << ("You rolled a  ") << dice_roll << ("!") << std::endl;
        moveSpace(dice_roll);
        std::cout << ("You are now in space ") << current_pos + 1 << std::endl;
        printBoard();

        if (current_pos == first_silver || current_pos == second_silver)
        {
            std::cout << ("You are now dragon food :(") << std::endl;
            winning_condition = 1;
        }
        else if (current_pos == gold_coin)
        {
            std::cout << ("Congrulations! You've won freedom!") << std::endl;
            winning_condition = 1;
        }
    }
}

int main()
{
    std::cout << std::endl
              << ("Welcome to The Ploy of the Jailor") << std::endl
              << std::endl;

    /////////// Board Initialization ////////////////

    fillArray(board_spaces); // Fills board with periods

    board_spaces[first_silver] = 'x';
    std::cout << ("The jailor has put their first silver coin in space ") << first_silver + 1 << std::endl;

    board_spaces[second_silver] = 'x';
    std::cout << ("The jailor has put their second silver coin in space ") << second_silver + 1 << std::endl;

    printBoard();

    std::cout << ("Enter your gold coin location:  ");
    std::cin >> gold_coin;

    gold_coin = gold_coin - 1;
    board_spaces[gold_coin] = 's';

    std::cout << ("Current board: ");
    printBoard();
    std::cout << std::endl;

    ///////////////////////////////////////////////////

    while (winning_condition == 0) // As long at winning_conditions equals 0, the game continues
    {
        int dice_roll = rand() % 7 + 1;

        std::cout << ("You rolled a  ") << dice_roll << ("!") << std::endl;
        moveSpace(dice_roll);
        std::cout << ("You are now in space ") << current_pos + 1 << std::endl;
        printBoard();

        if (current_pos == first_silver || current_pos == second_silver)
        {
            std::cout << ("You are now dragon food :(") << std::endl;
            winning_condition = 1;
        }
        else if (current_pos == gold_coin)
        {
            std::cout << ("Congrulations! You've won freedom!") << std::endl;
            winning_condition = 1;
        }
        std::this_thread::sleep_for(std::chrono::seconds(2)); // Wait 2 seconds
    }
}
*/