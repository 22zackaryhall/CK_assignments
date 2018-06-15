#include "SRPG.h"


Player player {
	player.name[16],
	player.MAX_HP = 20,
	player.HP = 20,
	player.MAX_MP = 10,
	player.MP = 10,
	player.MAX_Exp = 20,
	player.Exp = 0,

	player.strength = 2,
	player.agility = 2,
	player.defence = 1,

	//소속 및 상태
	player.isUndead = false,
	player.dead = false,
	player.isCorrupted = false
};

Enemy enemy = {
	enemy.name[16],	
	enemy.MAX_HP = 20,
	enemy.HP = 20,
	enemy.MAX_MP = 10,
	enemy.MP = 10,
	enemy.MAX_Exp = 20,
	enemy.Exp = 0,

	enemy.strength = 2,
	enemy.agility = 2,
	enemy.defence = 1,

	//소속 및 상태
	enemy.isUndead = false,
	enemy.dead = false,
	enemy.isCorrupted = false
};