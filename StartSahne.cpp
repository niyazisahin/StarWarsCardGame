
#include "StartSahne.h"
#include "AnaSahne.h"

USING_NS_CC; // using namespace cocos2d

Scene* StartSahne::createScene()
{
    return StartSahne::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool StartSahne::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize(); // ekranýn görünen boyutu(objesi boyut içinde)
    Vec2 origin = Director::getInstance()->getVisibleOrigin(); // opengl merkez kordinatý bunu pozisyonlara eklemek gerekiyor

    /////////////////////////////
    // Alt kýsým ekranýn ortasýna oyuna baþlamak için gerekli tuþu ekler

    auto bitisTus = MenuItemImage::create(
                                           "exit.png",
                                           "exit.png",
                                           CC_CALLBACK_1(StartSahne::menuCloseCallback, this)); // BU tuþa basýldýðýnda çalýþtýrýlan fonksiyo

    auto startTus = MenuItemImage::create(
        "play.png",
        "play.png",
        CC_CALLBACK_1(StartSahne::menuStartGameCallback, this)
    );

    
    tusYerAyarla(bitisTus, (origin.x + visibleSize.width / 2), (origin.y + visibleSize.height / 2), "'exit.png'");
    tusYerAyarla(startTus, (origin.x + visibleSize.width / 2), (origin.y + visibleSize.height / 2  + 100), "'play.png'");


    // Menu objesini yaratma
    auto menu = Menu::create(startTus, bitisTus, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    // Baþlýk yazýsý

    auto label = Label::createWithTTF("~ STAR WARS ~", "fonts/Modak-Regular.ttf", 180);
    if (label == nullptr)
    {
        problemLoading("'fonts/Modak-Regular.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height +120));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }
 
    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("arkaplan-yeni.jpg");
    sprite->setScale(1.45, 1.45);


    if (sprite == nullptr)
    {
        problemLoading("'HelloWorld.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

        // add the sprite as a child to this layer
        this->addChild(sprite, 0);
    }
    return true;
}


void StartSahne::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

}

void StartSahne::menuStartGameCallback(Ref* pSender)
{
    auto director = Director::getInstance();
    auto scene = AnaSahne::createScene();

    director->replaceScene(TransitionFade::create(0.5, scene, Color3B(0, 0, 0)));
    
}

void StartSahne::tusYerAyarla(MenuItemImage* tus, float x, float y, const char* filename) {
    // startTus null mu diye kontrol
    if (tus == nullptr ||
        tus->getContentSize().width <= 0 ||
        tus->getContentSize().height <= 0)
    {
        problemLoading(filename);
    }
    else
    {
        // Tuþu ekranýn ortasýna koyar
        tus->setPosition(Vec2(x, y));
    }
}