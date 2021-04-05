#include "AnaSahne.h"
#include "Test.h"

/*
TODO
Mouse kart�n �zerine geldi�inde ka��d�n boyunun b�y�mesi ve kenarl���n�n rengini de�i�mesi. ( ge�i� ile )
*/

USING_NS_CC; // using namespace cocos2d;

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool AnaSahne::init() {
    //////////////////////////////
// 1. super init first
    if (!Scene::init())
    {
        return false;
    }
    
    deneme.setSahne(this);
    auto visibleSize = Director::getInstance()->getVisibleSize(); // ekran�n g�r�nen boyutu(objesi boyut i�inde)
    Vec2 origin = Director::getInstance()->getVisibleOrigin(); // opengl merkez kordinat� bunu pozisyonlara eklemek gerekiyor

    auto Background = Sprite::create("x.jpg");
    this->addChild(Background, 1);
    Background->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    Background->setScale(1.5, 1.5);
    
   
    // Kullan�c� Ad� Giri� Kutusu Arka Plan
    auto Sandstone = Sprite::create("x-panel.jpg");
    Sandstone->setScale(0.8, 0.8);
    Sandstone->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(Sandstone, 4);

    // Kullan�c� Ad� Giri� Kutusu
    auto textField = ui::TextField::create("Entr Nickname", "fonts/Modak-Regular.ttf", 35);
    this->addChild(textField, 5);
    textField->setPosition(Sandstone->getPosition());
    textField->setMaxLength(15);
    textField->setMaxLengthEnabled(true);
    textField->setColor(Color3B(255, 255, 255));

    // Kullan�c� Ad�
    auto label = Label::createWithTTF(deneme.getKullaniciAd(), "fonts/Modak-Regular.ttf", 65);
    label->setPosition(Vec2(visibleSize.width / 2, 65));
    this->addChild(label, 2);

    //Bilgisayar Ad�
    auto label2 = Label::createWithTTF("Bilgisayar", "fonts/Modak-Regular.ttf", 70);
    label2->setPosition(Vec2(visibleSize.width / 2, 850));
    this->addChild(label2, 2);



    gonderTus = MenuItemImage::create(
        "play.png",
        "play.png",
        CC_CALLBACK_1(AnaSahne::nickNameCallBack, this, textField, label, &deneme, Sandstone)
    );


    tusYerAyarla(gonderTus, (origin.x + visibleSize.width / 2), (origin.y + visibleSize.height / 2 - 70), "'play.png'");

    // Menu objesini yaratma
    auto menu = Menu::create(gonderTus, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 5);

    deneme.kartDagit();

    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = CC_CALLBACK_2(AnaSahne::onTouchBegan, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
    
   
    deneme.adlar�Yaz();
    
    return true;
}

bool AnaSahne::onTouchBegan(Touch* touch, Event* event)
{

    auto pos = touch->getLocation();
    // Kullan�c� i�in collision detection

    for (int i = 0; i < 8; i++)
    {

        bool kontrol = deneme.getKullan�c�().KartSec(pos, i);
        auto kart = deneme.getKullan�c�().KartListesi[i];

        if (kontrol) {
            
            kart->getKart()->setLocalZOrder(1);
            kart->setKullanildiMi(true);
            deneme.BilgisayarKartOyna(i);

        }
    }

    return true;

}



Scene* AnaSahne::createScene() {
	return AnaSahne::create();
}

void AnaSahne::tusYerAyarla(MenuItemImage* tus, float x, float y, const char* filename) {
    // startTus null mu diye kontrol
    if (tus == nullptr ||
        tus->getContentSize().width <= 0 ||
        tus->getContentSize().height <= 0)
    {
        problemLoading(filename);
    }
    else
    {
        // Tu�u ekran�n ortas�na koyar
        tus->setPosition(Vec2(x, y));
    }
}

void AnaSahne::nickNameCallBack(Ref* pSender, ui::TextField* test, Label* l, Test* deneme, 
                                Sprite* sandstone) 
{
    string yazi = test->getString();
    if (yazi.length())
    {
        l->setString(yazi);
        deneme->getKullan�c�().setOyuncuAD(yazi);
        sandstone->setPosition(Vec2(5000, 5000));
        test->setPosition(sandstone->getPosition());
        gonderTus->setPosition(Vec2(5000, 5000));
    }


}