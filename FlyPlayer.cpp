#include "FlyPlayer.h"
USING_NS_CC;

FlyPlayer::FlyPlayer(void)
{
}


FlyPlayer::~FlyPlayer(void)
{
}
bool FlyPlayer::init()
{
	bool b1 = CCSprite::init();
	
	initWithSpriteFrameName("plane/0023/k0003.png");
	flyAction();
	//initWithSpriteFrameName("fly1.png");
	return b1;
}
void FlyPlayer::moveTo(cocos2d::CCPoint pos)
{
	CCSize	winSize	=CCDirector::sharedDirector()->getVisibleSize();
	float w=this->getContentSize().width;
	float h=this->getContentSize().height;

	this->setPosition(pos);
	if (this->getPositionX() <= w/2)
	{
		//this->setPosition(w/2);
		this->setPositionX(w/2);
	}else  if(this->getPositionX()>=winSize.width - w/2)
	{
		this->setPositionX(winSize.width - w/2);
	}

	if (this->getPositionY() <= h/2)
	{
		//this->setPosition(w/2);
		this->setPositionY(h/2);
	}else  if(this->getPositionY()>=winSize.height - w/2)
	{
		this->setPositionY(winSize.height - w/2);
	}

}
void FlyPlayer::destory()
{
	//移除当前对象
	this->removeFromParent();
}
void FlyPlayer::flyAction()
{
	//auto frame
	int i;
	cocos2d::CCAction* _idleAction;
	CCArray *idleFrames=CCArray::create();
	idleFrames->retain();
	for(i=3;i<5;i++)
	{
		CCSpriteFrame* frame=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(CCString::createWithFormat("plane/0023/k000%d.png",i)->getCString());
		idleFrames->addObject(frame);
	}

	CCAnimation* idleAnimation=CCAnimation::createWithSpriteFrames(idleFrames,0.3f);
	_idleAction=CCRepeatForever::create(CCAnimate::create(idleAnimation));
	_idleAction->retain();
	this->runAction(_idleAction);
}
void FlyPlayer::blowupAction()//动作
{
	this->stopAllActions();
	//cocos2d::CCAction* _idleAction;
	CCArray *idleFrames=CCArray::create();
	idleFrames->retain();
	for(int i=1;i<3;i++)
	{
		CCSpriteFrame* frame=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(CCString::createWithFormat("explosion_0%d.png",i)->getCString());
		idleFrames->addObject(frame);
	}
	CCAnimation* idleAnimation=CCAnimation::createWithSpriteFrames(idleFrames,0.2f);
	CCAnimate *Animate	=	CCAnimate::create(idleAnimation);
	CCRemoveSelf* remove =	CCRemoveSelf::create();
	CCSequence* seq	   =CCSequence::create(Animate,remove,NULL);
	this->runAction(seq);
}
