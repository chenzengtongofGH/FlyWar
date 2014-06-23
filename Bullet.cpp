#include "Bullet.h"

USING_NS_CC;

Bullet::Bullet(void):	vy(15.5f),
						offsetY(0)
{
}


Bullet::~Bullet(void)
{
	
}
Bullet* Bullet::create()
{
	  Bullet* mBullet	=	new Bullet();
	  if(mBullet && mBullet->init())
	  {
		    //加入自动垃圾回收池
			mBullet->autorelease();
			return mBullet;
	  }
	  delete mBullet;
	  mBullet		=	NULL;
	  return NULL;
}

Bullet* Bullet::create(std::string fileName)
{
	Bullet* mBullet	=	new Bullet();
	
	char file[20];
	sprintf(file, "%s",fileName);
	if(mBullet && mBullet->initWithSpriteFrameName(file))
	{
		mBullet->autorelease();
		return mBullet;
	}

	delete mBullet;
	mBullet		=	NULL;

	return NULL;
}

Bullet* Bullet::create(BULLET_TYPE type)
{
	Bullet* mBullet	 =	new Bullet();
	
	//char chFileName[266];
	//sprintf(chFileName,"bullet%d.png",type);

	if(mBullet&& mBullet->initWithFile("bullet_0.png"))
	{
		 mBullet->autorelease();
		 return mBullet;
	}
	delete mBullet;
	mBullet	=	NULL;
	return NULL;
}

bool Bullet::init()
{
	CCSprite::init();
	initWithSpriteFrameName("fireflame/enemybullet02/planebullet/00.png");
	//initWithFile("bird.png");
	BulletAction();
	return true;
}
void Bullet::move()
{
	CCSize winSize	=	CCDirector::sharedDirector()->getVisibleSize();
	//如果偏移量是负数 就忽略
	//offsetY	=	offsetY >= 0 ? offsetY : 0;

	float x	=this->getPositionX() + vy;
	this->setPositionX(x);

	/*if (y>=winSize.height	+	this->getContentSize().height/2)
	{
		destory();
	}*/
	/*if(y + offsetY > winSize.height)
	{
		if(this->getParent())
			this->removeFromParent();
	}*/
}
void Bullet::destory()
{
	this->removeFromParent();
}
bool Bullet::hitTest(cocos2d::CCNode* enemy)
{
	//检测是否碰撞到
	
	return enemy->boundingBox().containsPoint(this->getPosition());
}
void Bullet::BulletAction()
{
	cocos2d::CCAction* _idleAction;
	CCArray *idleFrames=CCArray::create();
	idleFrames->retain();
	for(int i=0;i<5;i++)
	{
		CCSpriteFrame* frame=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(CCString::createWithFormat("fireflame/enemybullet02/planebullet/0%d.png",i)->getCString());
		idleFrames->addObject(frame);
	}

	CCAnimation* idleAnimation=CCAnimation::createWithSpriteFrames(idleFrames,0.05f);
	_idleAction=CCRepeatForever::create(CCAnimate::create(idleAnimation));
	_idleAction->retain();
	this->runAction(_idleAction);
}
