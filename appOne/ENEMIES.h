#pragma once
#include "GAME_OBJECT.h"
#include"libOne.h"
class ENEMIES :
    public GAME_OBJECT
{
public:
    struct DATA {
        int img;
        int totalNum;
        int curNum;
        float majRadius;
        float minRadius;
        VECTOR2 centerPos;
        float fallSpeed;
        float targetPosY;
        float refTheta;
        float thetaSpeed;
        float triggerInterval;
        float ofstLaunchDist;
        //衝突判定用
        float bcRadius;
        float invincibleTime;
        int initHp;
        VECTOR2 HpGaugeOfst;
        COLOR collisionColor;
        COLOR normalColor;
    };

private:
    //共通データ
    DATA Enemy;
    //単体データの配列
    struct ENEMY {
        VECTOR2 pos;
        float ofstTheta;
        float triggerErapsedTime;
        float invincibleRestTime;
        int hp;
        COLOR color;
    };
    ENEMY* Enemies;

public:
    ENEMIES(class GAME* game);
    ~ENEMIES();
    void create();
    void init();
    void update();
        void move();
        void launch();
        void collision();
    void draw();

    //getter
    int curNum() { return Enemy.curNum; }
};

