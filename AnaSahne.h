#ifndef ANASAHNE_H
#define ANASAHNE_H

#include "cocos2d.h"
#include "Test.h"
#include "ui/CocosGUI.h"

using namespace std;
USING_NS_CC;

class AnaSahne : public Scene
{
public:
		static Scene* createScene();
		virtual bool init();
		void nickNameCallBack(Ref* pSender, cocos2d::ui::TextField* test, cocos2d::Label* l,
								Test* deneme, cocos2d::Sprite* sandstone);
		void tusYerAyarla(MenuItemImage* tus, float x, float y, const char* filename);
		virtual bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*);

		CREATE_FUNC(AnaSahne);

private:
	Test deneme;
	MenuItemImage* gonderTus;

};

#endif //ANASAHNE_H
