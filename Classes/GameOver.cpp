#include "HelloWorldScene.h"
#include "SceneOne.h"
#include "GameOver.h"
#include "GameScene.h"
USING_NS_CC;

Scene* GameOver::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = GameOver::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool GameOver::init()
{
	
	if (!Layer::init())
	{
		return false;
	}
 
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	 

	auto label = Label::createWithTTF("GameOver_Scene", "fonts/Marker Felt.ttf", 24);

	 
	label->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - label->getContentSize().height));
	//this->addChild(label);
 
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("game.plist");//ʹ��plist�ļ������ؾ���֡

	auto background = Sprite::createWithSpriteFrameName("bg.png");//ʹ�þ���֡��������ʼ������
	background->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(background, 0);

	auto gameoverSprite = Sprite::createWithSpriteFrameName("gameover.png");//����gameoverͼ��
	gameoverSprite->setPosition(Vec2(visibleSize.width/2,2*visibleSize.height/3));
	this->addChild(gameoverSprite, 1);

 
	auto start_bt = Sprite::createWithSpriteFrameName("start_btn.png");//��ʼ��������ť����
	auto pressed_bt = Sprite::createWithSpriteFrameName("start_btn_pressed.png");
	//���ò˵����飬������������Ϸ�ص�����
	auto reStartItem = MenuItemSprite::create(
		start_bt, 
		pressed_bt,
		CC_CALLBACK_1(GameOver::menuReStartCallback, this));

	reStartItem->setPosition(Vec2(visibleSize.width / 2 + origin.x,
		visibleSize.height / 2 - background->getPositionY() + 3 * reStartItem->getContentSize().height));

	 
	auto menu = Menu::create(reStartItem, NULL);//ʹ�ò˵����鴴���˵�
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 101);

	auto GameOverlabel = Label::createWithTTF("EXIT", "fonts/arial.ttf", 24);//�����˳��˵��������˳���Ϸ�ص�����
	auto gameOverItem = MenuItemLabel::create(GameOverlabel,CC_CALLBACK_1(GameOver::menuGameOverCallback,this));
	gameOverItem->setPosition(Vec2(visibleSize.width / 2 + origin.x,
		visibleSize.height / 2 - background->getPositionY() + 4 * gameOverItem->getContentSize().height));
	auto gameovermenu = Menu::create(gameOverItem, NULL);
	gameovermenu->setPosition(Vec2::ZERO);

	this->addChild(gameovermenu, 101);
 

	return true;
}


void GameOver::menuReStartCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.", "Alert");
	return;
#endif
	auto scene = GameScene::createScene();//��ʼ����Ϸ����
	auto transition = TransitionFade::create(1, scene);
	// run
	Director::getInstance()->replaceScene(transition);

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}
void GameOver::menuGameOverCallback(cocos2d::Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.", "Alert");
	return;
#endif
 
	Director::getInstance()->end();//ֱ���˳�

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}
void GameOver::scrollLand(float dt)
{
	this->land1->setPositionX(this->land1->getPositionX() - 2.0f);
	this->land2->setPositionX(this->land1->getPositionX() + this->land1->getContentSize().width - 2.0f);

	if (this->land2->getPositionX() == 0) {
		this->land1->setPositionX(0);
	}

}

void GameOver::update(float delta)
{
	int posLand1 = land1->getPositionX();
	int posLand2 = land2->getPositionX();

	int speed = 1;

	posLand1 -= speed;
	posLand2 -= speed;



	auto landsize = land2->getContentSize();

	if (posLand1 < -landsize.width / 2 + 142)
	{
		posLand2 = landsize.width / 2;
		posLand1 = landsize.width + landsize.width / 2;
	}

	if (posLand2 < -landsize.width / 2 + 142)
	{
		posLand1 = landsize.width / 2;
		posLand2 = landsize.width + landsize.width / 2;
	}
	land1->setPositionX(posLand1);
	land2->setPositionX(posLand2);
}

void GameOver::myupdate(float delta)
{
	int posLand1 = land1->getPositionX();
	int posLand2 = land2->getPositionX();

	int speed = 1;

	posLand1 -= speed;
	posLand2 -= speed;



	auto landsize = land2->getContentSize();

	if (posLand1 < -landsize.width / 2 + 142)
	{
		posLand2 = landsize.width / 2;
		posLand1 = landsize.width + landsize.width / 2;
	}

	if (posLand2 < -landsize.width / 2 + 142)
	{
		posLand1 = landsize.width / 2;
		posLand2 = landsize.width + landsize.width / 2;
	}
	land1->setPositionX(posLand1);
	land2->setPositionX(posLand2);
}