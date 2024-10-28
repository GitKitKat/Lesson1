#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include "Player.h"
#include "Enemy.h"

class Game {
public:
	Game();
	~Game();

	// Function Declarations
	void PlayerTurn(Player& player, std::vector<Enemy>& enemies);
	void EnemyTurn(Player& player, Enemy& enemy);
	void GameLoop(Player& player, std::vector<Enemy>& enemies);

	Player Player1;
	Enemy Enemy1;
	Enemy Enemy2;
	std::vector<Enemy> Enemies;
};

#endif