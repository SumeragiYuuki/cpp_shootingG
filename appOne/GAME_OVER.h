#pragma once
#include "SCENE.h"
class GAME_OVER :
    public SCENE
{
public:
    GAME_OVER(class GAME* gaame);
    ~GAME_OVER();
    void update();
    void draw();
    void nextScene();
};
