
#ifndef START_SAHNE_H
#define START_SAHNE_H

#include "cocos2d.h"

class StartSahne : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    void menuStartGameCallback(cocos2d::Ref* pSender);
    void tusYerAyarla(cocos2d::MenuItemImage* tus, float x, float y, const char* filename);


    // implement the "static create()" method manually
    CREATE_FUNC(StartSahne);
};

#endif // START_SAHNE_H
