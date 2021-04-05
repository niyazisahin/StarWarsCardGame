#include "Sporcu.h"
#include "Basketbolcu.h"
#include "Futbolcu.h"
#include "AudioEngine.h"

#define SES_OYNA(x) cocos2d::AudioEngine::play2d(x, false ,1.0f, nullptr)

void Sporcu::setKart(string dosya_adi) {
	
	// ekranýn büyüklüðü ve origin noktasý
	auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
	auto origin = cocos2d::Director::getInstance()->getVisibleOrigin();
	kart = cocos2d::Sprite::create(dosya_adi);
	kart->setScale(0.20, 0.20);
	kart->setPosition(cocos2d::Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

}

cocos2d::Sprite* Sporcu::getKart() {
	return kart;
}

/*
Bir kartýn pozisyonunu deðiþtiren fonksiyon
 x Kartýn gideceði X kordinatý
 y Kartýn gideceði Y kordinatý
*/
void Sporcu::setPos(double x, double y) {

	cocos2d::MoveTo* nodeAction = cocos2d::MoveTo::create(1, cocos2d::Vec2(x, y));
	kart->runAction(nodeAction);

}

/*
Bir kartýn pozisyonunu bir noktaya ondan sonra
baþladýðý nooktaya geri dönderen fonksiyon
 x,y : ilk gideceði nokta
 x2,y2 ikini gideceði nokta
*/
void Sporcu::setPos2(double x, double y, double x2, double y2) {

	cocos2d::MoveTo* nodeAction = cocos2d::MoveTo::create(1, cocos2d::Vec2(x, y));
	cocos2d::MoveTo* nodeAction2 = cocos2d::MoveTo::create(1, cocos2d::Vec2(x2, y2));

	auto seq = cocos2d::Sequence::createWithTwoActions(nodeAction, nodeAction2);
	kart->runAction(seq);

}


cocos2d::Vec2 Sporcu::getPos() {
	return kart->getPosition();
}

int Sporcu::SporcuPuaniGoster(Sporcu* b1, Sporcu* i1, bool Futbolcumu) {
	int random = 1 + rand() % 3;
	CCLOG(" ozellik secildi : %d", random);
	b1->TersDondur();

	if (Futbolcumu) 
		CCLOG("Futbolcu");
	else 
		CCLOG("Basketci");

	CCLOG("=============================================================================================================================");

	switch (random) {

	case 1:

		if (Futbolcumu)
			SES_OYNA("Penalti.mp3");
		else
			SES_OYNA("SerbestAtis.mp3");
	
		if (i1->getOzellik1() > b1->getOzellik1())
		{
			i1->setPos(600, 450);
			b1->setPos(800, 450);

			return 1;
		}
		else if (i1->getOzellik1() < b1->getOzellik1())
		{
			i1->setPos(600, 450);
			b1->setPos(800, 450);
			return 0;
		}
		else {

			CCLOG("Iste gidiyor"); // özel harekat
			b1->setPos2(800, 450, b1->getAnaPos().x, b1->getAnaPos().y);
			i1->setPos2(600, 450, i1->getAnaPos().x, i1->getAnaPos().y);
			b1->getKart()->setLocalZOrder(2);
			i1->getKart()->setLocalZOrder(2);
			i1->setKullanildiMi(false);
			b1->setKullanildiMi(false);

			auto delayt = cocos2d::DelayTime::create(1);
			auto callback = cocos2d::CallFunc::create(CC_CALLBACK_0(Sporcu::TersDondur, b1));
			b1->getKart()->runAction(cocos2d::Sequence::create(delayt, callback, nullptr));

			return -1;

		}

		break;

	case 2:
		if (Futbolcumu)
			SES_OYNA("KarsiKarsiya.mp3");
		else
			SES_OYNA("ikilik.mp3");

		if (i1->getOzellik2() > b1->getOzellik2())
		{
			i1->setPos(600, 450);
			b1->setPos(800, 450);
			return 1;
		}

		else if (i1->getOzellik2() < b1->getOzellik2())
		{
			i1->setPos(600, 450);
			b1->setPos(800, 450);
			return 0;
		}

		else {

			CCLOG("Iste gidiyor"); // özel harekat
			b1->setPos2(800, 450, b1->getAnaPos().x, b1->getAnaPos().y);
			i1->setPos2(600, 450, i1->getAnaPos().x, i1->getAnaPos().y);
			b1->getKart()->setLocalZOrder(2);
			i1->getKart()->setLocalZOrder(2);
			i1->setKullanildiMi(false);
			b1->setKullanildiMi(false);

			auto delayt = cocos2d::DelayTime::create(1);
			auto callback = cocos2d::CallFunc::create(CC_CALLBACK_0(Sporcu::TersDondur, b1));
			b1->getKart()->runAction(cocos2d::Sequence::create(delayt, callback, nullptr));

			return -1;

		}
		break;

	case 3:
		if (Futbolcumu)
			SES_OYNA("SerbestVurus.mp3");
		else
			SES_OYNA("Ucluk.mp3"); 

		if (i1->getOzellik3() > b1->getOzellik3())
		{
			i1->setPos(600, 450);
			b1->setPos(800, 450);
			return 1;
		}

		else if (i1->getOzellik3() < b1->getOzellik3())
		{
			i1->setPos(600, 450);
			b1->setPos(800, 450);
			return 0;
		}

		else {
			CCLOG("Iste gidiyor"); // özel harekat
			b1->setPos2(800, 450, b1->getAnaPos().x, b1->getAnaPos().y);
			i1->setPos2(600, 450, i1->getAnaPos().x, i1->getAnaPos().y);
			b1->getKart()->setLocalZOrder(2);
			i1->getKart()->setLocalZOrder(2);
			i1->setKullanildiMi(false);
			b1->setKullanildiMi(false);

			auto delayt = cocos2d::DelayTime::create(1);
			auto callback = cocos2d::CallFunc::create(CC_CALLBACK_0(Sporcu::TersDondur, b1));
			b1->getKart()->runAction(cocos2d::Sequence::create(delayt, callback, nullptr));

			return -1;
		}
		break;
	}

}

/*
Kartlarý ters döndüren fonksiyon
*/
void Sporcu::TersDondur() {

	string bas = "kartlar/";
	string son = ".png";

	// eðer tersse düz yap
	if (tersmi) {
		kart->setTexture(bas + _sprocuAdi + son);
		tersmi = false;
	}
	else {
		// eðer düzse ters yap
		kart->setTexture(bas + "Bos" + son);
		tersmi = true;
	}
}
