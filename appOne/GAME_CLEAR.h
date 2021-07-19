#pragma once
#include "SCENE.h"
class GAME_CLEAR :
    public SCENE
{
public:
    GAME_CLEAR(class GAME* gaame);
    ~GAME_CLEAR();
    void update();
    void draw();
    void nextScene();
};
