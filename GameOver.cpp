#include "GameOver.h"
#include "WelComeLayer.h"

GameOver::GameOver(void)
{
}


GameOver::~GameOver(void)
{
}
//����һ��������װ��WelComeLayer��
CCScene* GameOver::CreateScene()
{
	// 'scene' is an autorelease object
	CCScene *scene = CCScene::create();

	// 'layer' is an autorelease object
	GameOver *layer = GameOver::create();
	// add layer as a child to scene
	scene->addChild(layer);
	// return the scene
	return scene;
}

bool GameOver::init()
{
	bool b1 = CCLayer::init();
	//CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("feiji1.plist");//�ṩplist�ӿڽ�ͼƬ���ص�������
	//CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Boss/mother.plist");
	//winSize = CCDirector::sharedDirector()->getVisibleSize();//��ÿ���ʾ����Ŀ�Ⱥ͸߶�
	CCSprite * backGround=CCSprite::create("GameOver.png");//��������ͼƬΪbg_01.png
	this->addChild(backGround);//��ӵ���ǰͼ����
	backGround->setAnchorPoint(ccp(0,0));//���ñ���ͼλ��


	CCMenuItemImage *pCloseItem = CCMenuItemImage::create( 
		"fanhui1.png", //png.jpg��ͼƬ��ʽ���ǿ��Ե�  
		"fanhui2.png",  
		this,  
		menu_selector(GameOver::fanhui));  
	CCMenu* pMenu = CCMenu::create(pCloseItem,NULL);
	
	pMenu->setScale(2);
	pMenu->setAnchorPoint(CCPointZero);
	pMenu->setPosition(ccp(500,100));
	this->addChild(pMenu,1);
	return b1;
}
void GameOver::fanhui(CCObject* pSender)
{
	//�滻��ǰ����
	CCDirector::sharedDirector()->replaceScene(WelComeLayer::CreateScene());
}
