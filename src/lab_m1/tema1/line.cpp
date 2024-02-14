#include "lab_m1/tema1/tema.h"

#include <vector>
#include <iostream>
#include <random>

#include "lab_m1/tema1/transform2D.h"
#include "lab_m1/tema1/object2D.h"


using namespace std;
using namespace m1;


line::line() {

}

line::line(int line_Ypos,
	int slot0X, int slot0Y,
	int slot1X, int slot1Y,
	int slot2X, int slot2Y,
	float enemiesY, float bulletsY,
	float lawnMowerX) {

	this->line_Ypos = line_Ypos;
	this->slot0X = slot0X;
	this->slot0Y = slot0Y;
	this->slot1X = slot1X;
	this->slot1Y = slot1Y;
	this->slot2X = slot2X;
	this->slot2Y = slot2Y;
	this->occupied_slot0 = false;
	this->occupied_slot1 = false;
	this->occupied_slot2 = false;
	this->used_lawnMower = false;
	this->activateLawnMower = false;
	this->enemiesY = enemiesY;
	this->bulletsY = bulletsY;
	this->lawnMowerX = lawnMowerX;
	this->bulletRotation = 1;
	this->angularWheel = 1;
}

line::~line() {}


bool line::spawnEnemy(int deltaTimeSeconds) {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(1, 100000);

	int randomNum = dist(mt);

	bool randNum = false;
	bool canSpawn = true;

	if (randomNum > 99960) {
		randNum = true;
	}

	for (auto& enemy : enemiesOnLine) {
		if (enemy.first.first > 900) {
			canSpawn = false;
		}
	}

	return randNum && canSpawn;
}


int line::enemyType() {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(1, 100);

	int randomNum = dist(mt);

	return randomNum % 4;
}