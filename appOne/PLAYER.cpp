#include"CONTAINER.h"
#include"GAME.h"
#include "PLAYER_BULLETS.h"
#include "ENEMY_BULLETS.h"
#include "PLAYER.h"
PLAYER::PLAYER(class GAME* game):
GAME_OBJECT(game) {

}
void PLAYER::create() {
	Player = game()->container()->player();
}
void PLAYER::init(){
	Player.pos= game()->container()->player().pos;
	Player.hp= game()->container()->player().hp;
}
void PLAYER::update() {
	move();
	launch();
	collision();
}
void PLAYER::move() {
	if (Player.pos.x > Player.limmitW && isPress(KEY_A)) {
		Player.pos.x += -Player.advSpeed * delta;
	}
	else if (Player.pos.x < width - Player.limmitW && isPress(KEY_D)) {
		Player.pos.x += Player.advSpeed * delta;
	}
}
void PLAYER::launch() {
	if (isPress(KEY_SPACE)) {
		Player.triggerErapsedTime += delta;
		if (Player.triggerErapsedTime >= Player.triggerInterval) {
			VECTOR2 pos = Player.pos + Player.launchVec*Player.ofstLaunchDist;
			game()->playerBullets()->launch(pos, Player.launchVec);
			Player.triggerErapsedTime = 0;
		}
	}
	else {
		Player.triggerErapsedTime = Player.triggerInterval;
	}
}
void PLAYER::collision() {
	if (Player.invincibleRestTime > 0) {
		Player.invincibleRestTime -= delta;
	}
	else {
		Player.color = Player.normalColor;

		ENEMY_BULLETS* bullets = game()->enemyBullets();
		float distance = Player.bcRadius + bullets->bcRadius();
		float sqDistance = distance * distance;
		for (int i = bullets->curNum() - 1; i >= 0; i--) {
			VECTOR2 vec = Player.pos - bullets->pos(i);
			if (sqLength(vec) < sqDistance) {
				Player.hp--;
				Player.invincibleRestTime = Player.invincibleTime;
				Player.color = Player.collisionColor;
				bullets->kill(i);
				i = 0;
			}
		}
	}
}
void PLAYER::draw() {
	imageColor(Player.color);
	rectMode(CENTER);
	image(Player.img, Player.pos.x, Player.pos.y, Player.angle);
	game()->hpGauge()->draw(Player.pos, Player.HpGaugeOfst, Player.hp);
}