#include "PLAYER_BULLETS.h"
#include"GAME.h"
#include"CONTAINER.h"
PLAYER_BULLETS::PLAYER_BULLETS(class GAME* game):
	BULLETS(game){

}
void PLAYER_BULLETS::create() {
	SetBullets(game()->container()->playerBullet());
}