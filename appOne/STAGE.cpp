#include"libOne.h"
#include"GAME.h"
#include"PLAYER.h"
#include"PLAYER_BULLETS.h"
#include"ENEMIES.h"
#include"ENEMY_BULLETS.h"
#include "STAGE.h"
STAGE::STAGE(class GAME* game) :
	SCENE(game) {

}
STAGE::~STAGE() {

}
void STAGE::init() {
	game()->player()->init();
	game()->enemies()->init();
	game()->playerBullets()->init();
	game()->enemyBullets()->init();
}
void STAGE::update() {
	game()->player()->update();
	game()->enemies()->update();
	game()->playerBullets()->update();
	game()->enemyBullets()->update();
}
void STAGE::draw() {
	clear();
	game()->draw();
}
void STAGE::nextScene() {
	if (game()->enemies()->curNum() <= 0) {
		game()->changeScene(GAME::GAME_CLEAR_ID);
	}
	if (game()->player()->hp() <= 0) {
		game()->changeScene(GAME::GAME_OVER_ID);
	}
}