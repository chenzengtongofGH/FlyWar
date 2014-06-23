#include "WelComeLayer.h"
#include "InGameLayer.h"
USING_NS_CC;
WelComeLayer::WelComeLayer(void) :winSize()
{

}


WelComeLayer::~WelComeLayer(void)
{
}

//����һ��������װ��WelComeLayer��
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
	//CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("feiji1.plist");//�ṩplist�ӿڽ�ͼƬ���ص�������
	//CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Boss/mother.plist");
	winSize = CCDirector::sharedDirector()->getVisibleSize();//��ÿ���ʾ����Ŀ�Ⱥ͸߶�
	CCSprite * backGround=CCSprite::create("skybk0002.png");//��������ͼƬΪbg_01.png
	this->addChild(backGround);//��ӵ���ǰͼ����
	backGround->setAnchorPoint(ccp(0,0));//���ñ���ͼλ��
	logoAction();//����LOGO�ĺ�������ʾ��ͼ�㵱��
	//
	CCMenuItemImage *pCloseItem = CCMenuItemImage::create( 
		"login_normal.png", //png.jpg��ͼƬ��ʽ���ǿ��Ե�  
		"login_press.png",  
		this,  
		menu_selector(WelComeLayer::btnPlayMenuCallBack));  
	CCMenu* pMenu = CCMenu::create(pCloseItem,NULL);
	pMenu->setPosition(ccp(480,320));
	this->addChild(pMenu);

	CCMenuItemImage *pCloseItem1 = CCMenuItemImage::create( 
		"regist_normal.png", //png.jpg��ͼƬ��ʽ���ǿ��Ե�  
		"regist_press.png",  
		this,  
		menu_selector(WelComeLayer::btnPlayMenuCallBack));  
	CCMenu* pMenu1 = CCMenu::create(pCloseItem1,NULL);
	pMenu1->setPosition(ccp(480,250));
	this->addChild(pMenu1);
	//CCLabelTTF* BeginTTF =CCLabelTTF::create("play Game","Minion Pro",64);//����Label����
	//CCMenuItemLabel* item =CCMenuItemLabel::create(BeginTTF,this,callfuncO_selector(WelComeLayer::btnPlayMenuCallBack));//������ťLabel
	//CCMenu* playMenu = CCMenu::create(item,NULL);//�����˵���ť
	//this->addChild(playMenu);//���˵����뵽��Ϸͼ�㵱��
	return b1;
}
void WelComeLayer::logoAction()
{
	CCSprite * logo  =CCSprite::create("LOGO.png");//����LOGO����
	this->addChild(logo);//������̨
	logo->setOpacity(255);//����LOGO͸����
	//����LOGO��Բ���
	logo->setPositionX(winSize.width / 2);
	logo->setPositionY(winSize.height -100);
	//��LOGO�ѵ������ʽ�������
	CCFadeIn * danru=CCFadeIn::create(1.0);
	logo->runAction(danru);
}

void WelComeLayer::btnPlayMenuCallBack(CCObject* pSender)
{
	//�滻��ǰ����
	CCDirector::sharedDirector()->replaceScene(InGameLayer::CreateScene());
}
