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
        //�Փ˔���p
        float bcRadius;
        float invincibleTime;
        int initHp;
        VECTOR2 HpGaugeOfst;
        COLOR collisionColor;
        COLOR normalColor;
    };

private:
    //���ʃf�[�^
    DATA Enemy;
    //�P�̃f�[�^�̔z��
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

