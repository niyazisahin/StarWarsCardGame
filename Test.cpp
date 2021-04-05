#include "Test.h"
#include "AudioEngine.h"
#include "ui/CocosGUI.h"
#include "AnaSahne.h"

#define SES_OYNA(x) cocos2d::AudioEngine::play2d(x, false ,1.0f, nullptr)

void Test::kartDagit() {
	srand(time(0));
	random_shuffle(&deste[0], &deste[7]);
	random_shuffle(&deste[8], &deste[15]);

	int index = 0;
	for (int i = poz1; i <= poz8; i += KART_POZ * 2) {// poz1 poz3 poz5 poz7

		auto tmp = deste[index];
		auto tmp2 = deste[index + 8];

		_insan.KartListesi[index] = tmp; // 0 - 4 arasý futbolcu
		_insan.KartListesi[index + 4] = tmp2; // 4 - 8 arasý basketci

		_sahne->addChild(_insan.KartListesi[index]->getKart(), 3);
		_sahne->addChild(_insan.KartListesi[index + 4]->getKart(), 3);

		index++;

		tmp->setPos(i, 200.0);
		tmp2->setPos(i + KART_POZ, 200.0);
		tmp->setAnaPos(cocos2d::Vec2(i, 200.0));
		tmp2->setAnaPos(cocos2d::Vec2(i + KART_POZ, 200.0));

	}

	for (int i = poz1; i < poz8; i += KART_POZ * 2) {

		auto tmp = deste[index];
		auto tmp2 = deste[index + 8];

		_robot.KartListesi[index - 4] = tmp;
		_robot.KartListesi[index] = tmp2;

		_sahne->addChild(_robot.KartListesi[index - 4]->getKart(), 3);
		_sahne->addChild(_robot.KartListesi[index]->getKart(), 3);

		index++;

		tmp->setPos(i, 700.0);
		tmp2->setPos(i + KART_POZ, 700.0);
		tmp->setAnaPos(cocos2d::Vec2(i, 700.0));
		tmp2->setAnaPos(cocos2d::Vec2(i + KART_POZ, 700.0));
		tmp->TersDondur();
		tmp2->TersDondur();

	}
	auto bos_beyaz_kart = cocos2d::Sprite::create("boskartbeyaz.png");
	bos_beyaz_kart->setPosition(cocos2d::Vec2(meydan1, 450));
	bos_beyaz_kart->setScale(0.20, 0.20);
	_sahne->addChild(bos_beyaz_kart, 1);
	auto bos_siyah_kart = cocos2d::Sprite::create("boskartsiyah.png");
	bos_siyah_kart->setPosition(cocos2d::Vec2(meydan2, 450));
	bos_siyah_kart->setScale(0.20, 0.20);
	_sahne->addChild(bos_siyah_kart, 1);
}

Kullanici Test::getKullanýcý() {
	return _insan;
}

string Test::getKullaniciAd() {
	return _insan.getOyuncuAD();
}

void Test::setSahne(cocos2d::Scene* sahne) {
	_sahne = sahne;
}

Bilgisayar Test::getBilgisayar() {
	return _robot;
}



void Test::BilgisayarKartOyna(int insan_index) {

	srand(time(0));
	int hangi_pozisyon = rand() % 3;

	int robot_index = _robot.KartSec(insan_index);
	
	auto kart = _robot.KartListesi[robot_index];
	kart->setKullanildiMi(true); // kartý kullanýldý hale getir

	if (insan_index >= 4) {



		// Debug bilgileri
		CCLOG(kart->getSporcuAdý().c_str());
		CCLOG("serbest atis: %d", kart->getOzellik1());
		CCLOG("iklik: %d", kart->getOzellik2());
		CCLOG("ucluk: %d", kart->getOzellik3());

		// Pozisyon Puanlarýnýn Hesaplanmasý
		kart->getKart()->setLocalZOrder(1);


		int sonuc = kart->SporcuPuaniGoster(kart, _insan.KartListesi[insan_index], false);

		if (sonuc == 1) {
			_insan.setSkor(100);
			CCLOG("Kullanici kazandi");
			SES_OYNA("kullanici2.mp3");
			
		}
		else if (sonuc == 0) {
			CCLOG("Bilgisayar Kazandi");
			_robot.setSkor(100);
			SES_OYNA("bilgisayar2.mp3");
		}

		CCLOG("bilgisayar puani : %d   //   kullanici puani : %d", _robot.getSkor(), _insan.getSkor());

	}
	else {

		CCLOG(kart->getSporcuAdý().c_str());
		CCLOG("Penalti: %d", kart->getOzellik1());
		CCLOG("serbest: %d", kart->getOzellik2());
		CCLOG("karsi karsiya: %d", kart->getOzellik3());

		// Pozisyon Puanýnýn Hesaplanmasý.
		kart->getKart()->setLocalZOrder(1);

		int sonuc = kart->SporcuPuaniGoster(_robot.KartListesi[robot_index], _insan.KartListesi[insan_index], true);

		if (sonuc == 1) {
			_insan.setSkor(100);
			CCLOG("kullanici kazandi");
			SES_OYNA("kullanici2.mp3");
		}
		else if (sonuc == 0) {
			CCLOG("bilgisayar Kazandi");
			_robot.setSkor(100);
			SES_OYNA("bilgisayar2.mp3");
		}

		CCLOG("bilgisayar puani : %d   //   kullanici puani : %d", _robot.getSkor(), _insan.getSkor());    //



	}

	adlarýYenile();

	if (_insan.getSkor() + _robot.getSkor() >= 800) {
		
		auto delayt = cocos2d::DelayTime::create(3);
		auto callback = cocos2d::CallFunc::create(CC_CALLBACK_0(Test::oyunuBitir, this));

		kullanici_skor->runAction((cocos2d::Sequence::create(delayt, callback, nullptr)));
	}

}


void Test::adlarýYaz() {

	auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
	string insan_skor = to_string(_insan.getSkor());
	string robot_skor = to_string(_robot.getSkor());
	
	kullanici_skor = cocos2d::Label::createWithTTF(insan_skor, "fonts/Modak-Regular.ttf", 80);
	bilgisayar_skor = cocos2d::Label::createWithTTF(robot_skor, "fonts/Modak-Regular.ttf", 80);

	_sahne->addChild(kullanici_skor, 3);
	kullanici_skor->setPosition(100, 400);
	_sahne->addChild(bilgisayar_skor, 3);
	bilgisayar_skor->setPosition(100, 500);

}

void Test::adlarýYenile() {
	kullanici_skor->setString(to_string(_insan.getSkor()));
	bilgisayar_skor->setString(to_string(_robot.getSkor()));
}

void Test::oyunuBitir() {
	int insan_skor = _insan.getSkor();
	int bilgisayar_skor = _robot.getSkor();
	string dosya_adi = "";
	string ses_adi = "";

	if (insan_skor > bilgisayar_skor) {

		dosya_adi = "win.png";
		ses_adi = "win.mp3";
	}
	else if (insan_skor < bilgisayar_skor) {
		dosya_adi = "lose.png";
		ses_adi = "lose-audio.mp3";
	}
	else{
		dosya_adi = "draw.png";
		ses_adi = "lose-audio.mp3";
	}


	auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
	auto origin = cocos2d::Director::getInstance()->getVisibleOrigin();
	auto end = cocos2d::Sprite::create(dosya_adi);
	_sahne->addChild(end, 3);
	end->setPosition(cocos2d::Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	cocos2d::AudioEngine::play2d(ses_adi, false ,1.0f, nullptr);
	

	auto button = cocos2d::ui::Button::create("restart.png");

	//button->setTitleText("RESTART");

	button->addTouchEventListener([&](cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type) {
		switch (type)
		{
		case cocos2d::ui::Widget::TouchEventType::BEGAN:
			break;
		case cocos2d::ui::Widget::TouchEventType::ENDED:

			auto director = cocos2d::Director::getInstance();
			auto scene = AnaSahne::createScene();

			director->replaceScene(scene);

			CCLOG("Button 1 clicked");
			break;

		}
		});

	_sahne->addChild(button, 4);
	button->setPosition(cocos2d::Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y -150));

}