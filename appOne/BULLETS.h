#pragma once
#include "GAME_OBJECT.h"
#include"libOne.h"
class BULLETS :
    public GAME_OBJECT
{
public:
    struct DATA {
        int totalNum;
        int curNum;
        int img;
        float advSpeed;
        float angSpeed;
        float bcRadius;
    };
private:
    //���ʃf�[�^
    DATA Bullet;
    //�P�̃f�[�^�z��
    struct BULLET {
        VECTOR2 pos;
        VECTOR2 vec;
        float angle;
    };
    BULLET* Bullets;
protected:
    void SetBullets(const BULLETS::DATA& data);
public:
    BULLETS(class GAME* game);
    ~BULLETS();
    void init();
    void launch(const VECTOR2& pos, const VECTOR2& vec);
    void update();
    void kill(int i);
    void draw();
    //bullet���
    VECTOR2 pos(int i) { return Bullets[i].pos; }
    float bcRadius() { return Bullet.bcRadius; }
    int curNum() { return Bullet.curNum; }
};

