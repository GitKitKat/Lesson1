#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "Entity.h"
#include <iostream>
#include <string>
#include <vector>

Game::Game() {

    Player1.SetName("Hero");
 
    Enemy1.SetName("Goblin");
    Enemies.push_back(Enemy1);

    Enemy2.SetName("Orc");
    Enemies.push_back(Enemy2);

    std::cout << "Welcome to the dungeon!\n";
    GameLoop(Player1, Enemies);
    std::cout << "Game Over!\n";

}

Game::~Game() {}

void Game::PlayerTurn(Player& player, std::vector<Enemy>& enemies)
{
    std::cout << "1. Attack\n2. Defend\n3. Run\n";
    std::cout << "Your choice: ";
    int choice;
    std::cin >> choice;
    std::cout << std::endl;

    if (choice == 1)
    {
        std::cout << "Choose an enemy to attack:\n";
        for (size_t i = 0; i < enemies.size(); ++i)
        {
            if (enemies[i].GetHealth() > 0)
            {
                std::cout << i + 1 << ". " << enemies[i].GetName() << " (Health: " << enemies[i].GetHealth() << ")\n";
            }
        }

        int enemyChoice;
        std::cin >> enemyChoice;
        if (enemyChoice >= 1 && enemyChoice <= enemies.size() && enemies[enemyChoice - 1].GetHealth() > 0)
        {
            player.PlayerAttack(player, enemies[enemyChoice - 1]);
        }
        else
        {
            std::cout << "Invalid choice!\n";
        }
    }
    else if (choice == 2)
    {
        std::cout << player.GetName() << " defends!\n";
    }
    else if (choice == 3)
    {
        std::cout << player.GetName() << " runs away!\n";
    }
}

void Game::EnemyTurn(Player& player, Enemy& enemy)
{
    std::cout << enemy.GetName() << " attacks!\n";
    enemy.EnemyAttack(player, enemy);
}

void Game::GameLoop(Player& player, std::vector<Enemy>& enemies)
{
    bool gameOver = false;
    while (!gameOver)
    {
        PlayerTurn(player, enemies);

        bool allEnemiesDefeated = true;
        for (auto& enemy : enemies)
        {
            if (enemy.GetHealth() > 0)
            {
                allEnemiesDefeated = false;
                break;
            }
        }

        if (allEnemiesDefeated)
        {
            std::cout << "All enemies are defeated! You win!\n";
            gameOver = true;
            break;
        }

        for (auto& enemy : enemies)
        {
            if (enemy.GetHealth() > 0)
            {
                EnemyTurn(player, enemy);
                if (player.GetHealth() <= 0)
                {
                    std::cout << player.GetName() << " has fallen!\n";
                    gameOver = true;
                    break;
                }
            }
        }
    }
}