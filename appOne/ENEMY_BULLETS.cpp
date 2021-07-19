#include "ENEMY_BULLETS.h"
#include"GAME.h"
#include"CONTAINER.h"
ENEMY_BULLETS::ENEMY_BULLETS(class GAME* game) :
	BULLETS(game) {

}
void ENEMY_BULLETS::create() {
	SetBullets(game()->container()->enemyBullet());
}