#include "GameObject.h"
USING_NS_CC;

GameObject::GameObject(void) :back1(NULL),back2(NULL),back3(NULL),vy(5.5f)
{
}


GameObject::~GameObject(void)
{
}
bool GameObject::init()
{
	bool b1 = CCLayer::init();
	back1 =CCSprite::create("background/skybk0002.png");
	this->addChild(back1,1);
	back1->setAnchorPoint(ccp(0,0));//设置00的坐标
	back1->setPosition(ccp(0,0));

	back2 =CCSprite::create("background/star0005.png");
	this->addChild(back2,2);
	back2->setAnchorPoint(ccp(0,0));//设置00的坐标
	back2->setPosition(ccp(200,200));
	//back2->setPosition(ccp(back1->getPositionX()+back1->getContentSize().width - 2,0));//将图片放在图片1上
	//冰块滚动
	back3 =CCSprite::create("background/far0007.png");
	this->addChild(back3,3);
	back3->setAnchorPoint(ccp(0,0));//设置00的坐标
	back4 =CCSprite::create("background/far0007.png");
	this->addChild(back4,3);
	back4->setAnchorPoint(ccp(0,0));//设置00的坐标
	back4->setPosition(ccp(back3->getPositionX()+back3->getContentSize().width - 2,0));
	

	back5 =CCSprite::create("background/boat0003.png");
	this->addChild(back5,4);
	back5->setAnchorPoint(ccp(0,0));//设置00的坐标
	
	back6 =CCSprite::create("background/boat0002.png");
	this->addChild(back6,4);
	back6->setAnchorPoint(ccp(0,0));//设置00的坐标
	back6->setPosition(ccp(back3->getPositionX()+back3->getContentSize().width - 2,0));
	Winsize=CCDirector::sharedDirector()->getVisibleSize();
//	back3->setPosition(ccp(back1->getPositionX()+back1->getContentSize().width - 2,0));//将图片放在图片1上

	return b1;
}
void GameObject::move()
{
	//计算移动速度
	float oneNextPos	= back3->getPositionX() - vy;
	float twoNextPos	= back4->getPositionX() - vy;
	float threeNextPos	= back5->getPositionX() - vy -10 ;
	float fourNextPos	= back6->getPositionX() - vy -10 ;
	//设置图片跑起来
	back3->setPositionX(oneNextPos);
	back4->setPositionX(twoNextPos);
	back5->setPositionX(threeNextPos);
	back6->setPositionX(fourNextPos);
	if (oneNextPos <= -back3->getContentSize().width)
	{
		//将第一张图片设置为第二张的高度,第一张图片压在第二张图片上面
		oneNextPos	=	back4->getPositionX() + back4->getContentSize().width;
		back3->setPositionX(oneNextPos);
	}else if(twoNextPos <= -back4->getContentSize().width)
	{
		twoNextPos	=	back3->getPositionX() + back3->getContentSize().width;
		back4->setPositionX(twoNextPos);
	}
	if (fourNextPos<=0 && threeNextPos<=0)
	{
		back5->setPositionX(Winsize.width);
		back6->setPositionX(back5->getPositionX()*2);
	}
}
