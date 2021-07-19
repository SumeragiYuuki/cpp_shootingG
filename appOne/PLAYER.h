#pragma once
#include "GAME_OBJECT.h"
#include"libOne.h"
class PLAYER :
    public GAME_OBJECT
{
public:
    struct DATA {
        int img;
        VECTOR2 pos;
        float advSpeed;
        float angle;
        float limmitW;
        //íeî≠éÀ
        VECTOR2 launchVec;
        float triggerErapsedTime;
        float triggerInterval;
        float ofstLaunchDist;
        //è’ìÀîªíËóp
        float bcRadius;
        float invincibleTime;
        float invincibleRestTime;
        int hp;
        VECTOR2 HpGaugeOfst;
        COLOR collisionColor;
        COLOR normalColor;
        COLOR color;

    };
private:
    DATA Player;
public:
    PLAYER(class GAME* game);
    void create();
    void init();
    void update();
        void move();
        void launch();
        void collision();
    void draw();
    VECTOR2 pos() { return Player.pos; }
    int hp() { return Player.hp; }
};

