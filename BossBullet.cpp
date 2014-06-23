#include "BossBullet.h"
USING_NS_CC;

BossBullet::BossBullet(void):vy(10.0),goal(ccp(0,0)),isit(false)
{
}


BossBullet::~BossBullet(void)
{

}
bool BossBullet::init()
{
	bool b1 = CCSprite::init();

	initWithFile("fireball.png");
	//BulletAction();
	return b1;
}
void BossBullet::move()
{
	float x	=this->getPositionX() - vy;
	this->setPositionX(x);
}
void BossBullet::destory()
{
	this->removeFromParent();
}
bool BossBullet::hitTest(cocos2d::CCNode* enemy)
{
	return enemy->boundingBox().containsPoint(this->getPosition());
}
void BossBullet::BulletAction()
{
	cocos2d::CCAction* _idleAction;
	CCArray *idleFrames=CCArray::create();
	idleFrames->retain();
	for(int i=0;i<5;i++)
	{
		CCSpriteFrame* frame=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(CCString::createWithFormat("flash/01/branch/0%d.png",i)->getCString());
		idleFrames->addObject(frame);
	}

	CCAnimation* idleAnimation=CCAnimation::createWithSpriteFrames(idleFrames,0.3f);
	_idleAction=CCRepeatForever::create(CCAnimate::create(idleAnimation));
	_idleAction->retain();
	this->runAction(_idleAction);
}
void BossBullet::dingxiangmove()
{
	float y=this->getPositionY();
	float x=this->getPositionX();
	if (!isit)
	{
		float x2 = vy*(x-goal.x)/sqrt((x-goal.x)*(x-goal.x)+(y-goal.y)*(y-goal.y));
		float y2 = vy*(y-goal.y)/sqrt((x-goal.x)*(x-goal.x)+(y-goal.y)*(y-goal.y));
		goal.setPoint(x2,y2);
		isit=true;
	}
	x=x-goal.x;
	y=y-goal.y;
	this->setPosition(ccp(x,y));
}