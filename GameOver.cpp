#include "GameOver.h"
#include "WelComeLayer.h"

GameOver::GameOver(void)
{
}


GameOver::~GameOver(void)
{
}
//创建一个场景，装载WelComeLayer类
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
	//CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("feiji1.plist");//提供plist接口将图片加载到缓存中
	//CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Boss/mother.plist");
	//winSize = CCDirector::sharedDirector()->getVisibleSize();//获得可显示区域的宽度和高度
	CCSprite * backGround=CCSprite::create("GameOver.png");//创建背景图片为bg_01.png
	this->addChild(backGround);//添加到当前图层中
	backGround->setAnchorPoint(ccp(0,0));//设置背景图位置


	CCMenuItemImage *pCloseItem = CCMenuItemImage::create( 
		"fanhui1.png", //png.jpg等图片格式都是可以的  
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
	//替换当前场景
	CCDirector::sharedDirector()->replaceScene(WelComeLayer::CreateScene());
}
