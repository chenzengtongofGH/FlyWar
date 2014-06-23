#include "WelComeLayer.h"
#include "InGameLayer.h"
USING_NS_CC;
WelComeLayer::WelComeLayer(void) :winSize()
{

}


WelComeLayer::~WelComeLayer(void)
{
}

//创建一个场景，装载WelComeLayer类
CCScene* WelComeLayer::CreateScene()
{
	// 'scene' is an autorelease object
	CCScene *scene = CCScene::create();

	// 'layer' is an autorelease object
	WelComeLayer *layer = WelComeLayer::create();
	// add layer as a child to scene
	scene->addChild(layer);
	// return the scene
	return scene;
}
bool WelComeLayer::init()
{
	bool b1 = CCLayer::init();
	//CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("feiji1.plist");//提供plist接口将图片加载到缓存中
	//CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Boss/mother.plist");
	winSize = CCDirector::sharedDirector()->getVisibleSize();//获得可显示区域的宽度和高度
	CCSprite * backGround=CCSprite::create("skybk0002.png");//创建背景图片为bg_01.png
	this->addChild(backGround);//添加到当前图层中
	backGround->setAnchorPoint(ccp(0,0));//设置背景图位置
	logoAction();//调用LOGO的函数，显示到图层当中
	//
	CCMenuItemImage *pCloseItem = CCMenuItemImage::create( 
		"login_normal.png", //png.jpg等图片格式都是可以的  
		"login_press.png",  
		this,  
		menu_selector(WelComeLayer::btnPlayMenuCallBack));  
	CCMenu* pMenu = CCMenu::create(pCloseItem,NULL);
	pMenu->setPosition(ccp(480,320));
	this->addChild(pMenu);

	CCMenuItemImage *pCloseItem1 = CCMenuItemImage::create( 
		"regist_normal.png", //png.jpg等图片格式都是可以的  
		"regist_press.png",  
		this,  
		menu_selector(WelComeLayer::btnPlayMenuCallBack));  
	CCMenu* pMenu1 = CCMenu::create(pCloseItem1,NULL);
	pMenu1->setPosition(ccp(480,250));
	this->addChild(pMenu1);
	//CCLabelTTF* BeginTTF =CCLabelTTF::create("play Game","Minion Pro",64);//创建Label文字
	//CCMenuItemLabel* item =CCMenuItemLabel::create(BeginTTF,this,callfuncO_selector(WelComeLayer::btnPlayMenuCallBack));//创建按钮Label
	//CCMenu* playMenu = CCMenu::create(item,NULL);//创建菜单按钮
	//this->addChild(playMenu);//将菜单加入到游戏图层当中
	return b1;
}
void WelComeLayer::logoAction()
{
	CCSprite * logo  =CCSprite::create("LOGO.png");//申明LOGO对象
	this->addChild(logo);//放置舞台
	logo->setOpacity(255);//设置LOGO透明度
	//设置LOGO相对布局
	logo->setPositionX(winSize.width / 2);
	logo->setPositionY(winSize.height -100);
	//让LOGO已淡入的形式载入界面
	CCFadeIn * danru=CCFadeIn::create(1.0);
	logo->runAction(danru);
}

void WelComeLayer::btnPlayMenuCallBack(CCObject* pSender)
{
	//替换当前场景
	CCDirector::sharedDirector()->replaceScene(InGameLayer::CreateScene());
}
