#include "EnemyBase.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;
using namespace CocosDenshion;
EnemyBase::EnemyBase(void) :mframeName(""),blowupNums(0),Speedvy(0),Hp(0),isBlowup(false)
{
}
EnemyBase::~EnemyBase(void)
{
}
void EnemyBase::move()//移动
{
	
	float nextPosX	= this->getPositionX() - Speedvy;
	this->setPositionX(nextPosX);
	//判断敌机是否走出图层
	float aa=this->getContentSize().width/2;
	/*if (nextPosX <= 100)
	{
		isBlowup=true;
		destory();
	}*/
}
void EnemyBase::hrut(float dmg)//受伤
{
	Hp -= dmg;
	if (Hp<=0)
	{
		blowupAction();
	}
}
bool EnemyBase::IsBlowup()
{
	return isBlowup;
}
void EnemyBase::blowupAction()//动作
{
	isBlowup = true;
	//SimpleAudioEngine::getInstance()->playEffect("explosion.mp3");
	//char keyBack[20];
	int i;
	//cocos2d::CCAction* _idleAction;
	CCArray *idleFrames=CCArray::create();
	idleFrames->retain();
	for(i=0;i<16;i++)
	{
		CCSpriteFrame* frame=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(CCString::createWithFormat("explosion_0%d.png",i)->getCString());
		idleFrames->addObject(frame);
	}

	CCAnimation* idleAnimation=CCAnimation::createWithSpriteFrames(idleFrames,0.1f);
	CCAnimate *Animate	=	CCAnimate::create(idleAnimation);
	CCRemoveSelf* remove =	CCRemoveSelf::create();
	CCSequence* seq	   =CCSequence::create(Animate,remove,NULL);
	this->runAction(seq);
}
bool EnemyBase::init()
{
	bool b1 = CCSprite::init();
	return b1;
}
void EnemyBase::initEnemy(const std::string& frameName,const int&blowup,int hp,int speed)//初始化敌机
{
	mframeName	=	frameName;
	blowupNums	=	blowup;
	Speedvy		=	speed;//0.00001~0.49999999
	Hp			=	hp;//(frameName.at(5)-'0')*10;//根据ASSCL码
	char file[30];
	std::string	key	=frameName+".png";
	sprintf(file, "%s",key.c_str());
	initWithSpriteFrameName(file);
	
	float w	=	this->getContentSize().width;
	float h	=	this->getContentSize().height;
	CCSize Winsize =CCDirector::sharedDirector()->getVisibleSize();
	this->setPosition(ccp(Winsize.width+w,CCRANDOM_0_1()*(Winsize.height-h-50)+h/2));
}
void EnemyBase::destory()//消失
{
	//this->remv
		this->removeFromParent();
}
