#include <iostream>
#include <sstream>
#include <stdio.h>
#include <thread>
#include <chrono>

char board_spaces[16] = {'+'};
int current_pos = 0;

void fillArray(char str[16])
{
    for (int i = 1; i < 16; i++)
    {
        str[i] = '.';
    }
}

void moveSpace(int steps)
{
    if (current_pos + steps > 15)
    {
        board_spaces[current_pos] = '.';
        board_spaces[current_pos + steps - 16] = '+';
        current_pos = current_pos + steps - 16;
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
    for (int i = 0; i < 16; i++)
    {
        std::cout << board_spaces[i];
    }
    std::cout << std::endl
              << std::endl;
}

void hard_mode()
{
    int first_silver = rand() % 15 + 1;
    int second_silver = rand() % 15 + 1;

    while (first_silver == second_silver)
    {
        first_silver = rand() % 15 + 1;
        second_silver = rand() % 15 + 1;
    }

    int winning_condition = 0;
    int gold_coin;
    int choice = 1;

    fillArray(board_spaces); // Fills board with periods

    board_spaces[first_silver] = 'x';
    std::cout << ("The jailor has put their first silver coin in space ") << first_silver << std::endl;

    board_spaces[second_silver] = 'x';
    std::cout << ("The jailor has put their second silver coin in space ") << second_silver << std::endl;

    printBoard();
    do
    {
        std::cout << ("Enter your gold coin location:  ");
        std::cin >> gold_coin;
        if ((gold_coin == first_silver) || (gold_coin == second_silver))
        {
            std::cout << ("Can't place your coin on the same space as either the jailor's coins. Try again") << std::endl;
        }
    } while ((gold_coin == first_silver) || (gold_coin == second_silver));

    board_spaces[gold_coin] = 's';

    std::cout << ("Current board: ");
    printBoard();
    std::cout << std::endl;

    while (winning_condition == 0) // As long at winning_conditions equals 0, the game continues
    {
        int dice_roll = rand() % 5 + 1;
        std::cout << ("You rolled a  ") << dice_roll << ("!") << std::endl;
        moveSpace(dice_roll);
        std::cout << ("You are now in space ") << current_pos << std::endl;
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
        else
        {
            if (choice == 1)
            {
                board_spaces[first_silver] = '.';
                first_silver = rand() % 5 + 1;
                board_spaces[first_silver] = 'x';
                std::cout << ("The jailor has moved their first silver coin to space ") << first_silver << std::endl;
                choice = 2;
            }
            else if (choice == 2)
            {
                board_spaces[second_silver] = '.';
                second_silver = rand() % 5 + 1;
                board_spaces[second_silver] = 'x';
                std::cout << ("The jailor has moved their second silver coin to space ") << second_silver << std::endl;
                choice = 1;
            }
        }
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}

void easy_mode()
{

    int winning_condition = 0;
    int first_gold, second_gold;

    fillArray(board_spaces); // Fills board with periods

    int silver_coin = rand() % 15 + 1;
    board_spaces[silver_coin] = 'x';
    std::cout << ("The jailor has put their silver coin in space ") << silver_coin << std::endl;

    printBoard();

    do
    {
        std::cout << ("enter your first gold coin location:  ");
        std::cin >> first_gold;

        std::cout << ("enter your second gold coin location:  ");
        std::cin >> second_gold;
        std::cout << std::endl;

        if (first_gold == silver_coin || second_gold == silver_coin)
        {
            std::cout << ("Can't place your coin on the same space as the jailor. Try again.") << std::endl;
        }
        else if (first_gold == second_gold)
        {
            std::cout << ("Can't place both your coin on the same place. Try again.") << std::endl;
        }
    } while ((first_gold == silver_coin || second_gold == silver_coin) || (first_gold == second_gold));

    board_spaces[first_gold] = 's';
    board_spaces[second_gold] = 's';

    std::cout << ("Current board: ");
    printBoard();
    std::cout << std::endl;

    ///////////////////////////////////////////////////

    while (winning_condition == 0) // As long at winning_conditions equals 0, the game continues
    {
        int dice_roll = rand() % 5 + 1;

        std::cout << ("You rolled a  ") << dice_roll << ("!") << std::endl;
        moveSpace(dice_roll);
        std::cout << ("You are now in space ") << current_pos << std::endl;
        printBoard();

        if (current_pos == silver_coin)
        {
            std::cout << ("You are now dragon food :(") << std::endl;
            winning_condition = 1;
        }
        else if (current_pos == first_gold || current_pos == second_gold)
        {
            std::cout << ("Congrulations! You've won freedom!") << std::endl;
            winning_condition = 1;
        }
        std::this_thread::sleep_for(std::chrono::seconds(2)); // Wait 2 seconds
    }
}

int main()
{
    int difficulty;
    std::cout << std::endl
              << ("Welcome to The Ploy of the Jailor") << std::endl
              << std::endl
              << ("Easy (1) mode or Hard (2) mode?  ");
    std::cin >> difficulty;

    if (difficulty == 1)
    {
        easy_mode();
    }
    else if (difficulty == 2)
    {
        hard_mode();
    }
    else
    {
        std::cout << ("Not a valid difficulty") << std::endl;
    }
}