#include "EnemyBoss.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;
EnemyBoss::EnemyBoss(void) : Speedvy(5.5),islevel(false),isvertical(false),HP(1000),isBlowup(false),isit(false),vy(10.0)
{

}
EnemyBoss::~EnemyBoss(void)
{

}
void EnemyBoss::destory()
{
	this->removeFromParent();
}
void EnemyBoss::hrut(float dmg)// ‹…À
{
	HP -= dmg;
	if (!isBlowup)
	{
		if (HP<=0)
		{
			blowupAction();
		}
	}
	else 
	{
		destory();
	}
}
void EnemyBoss::bosshrutAction()
{
	BossBlowupSprite = CCSprite::create();
	BossBlowupSprite->setAnchorPoint(CCPointZero);
	BossBlowupSprite->setPosition(ccp(50,200));
	this->addChild(BossBlowupSprite,6);

	BossBlowupSprite1 =CCSprite::create();
	BossBlowupSprite1->setAnchorPoint(CCPointZero);
	BossBlowupSprite1->setPosition(ccp(100,200));
	this->addChild(BossBlowupSprite1,6);
	CCArray *idleFrames=CCArray::create();
	idleFrames->retain();
	for(int i=2;i<5;i++)
	{
		CCSpriteFrame* frame=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(CCString::createWithFormat("0%d.png",i)->getCString());
		idleFrames->addObject(frame);
	}

	CCAnimation* idleAnimation=CCAnimation::createWithSpriteFrames(idleFrames,0.1f);
	CCAnimate *Animate	=	CCAnimate::create(idleAnimation);
	CCRepeatForever *reforever = CCRepeatForever::create(Animate);
	BossBlowupSprite->runAction(reforever);
	BossBlowupSprite1->runAction(reforever);
	
}
bool EnemyBoss::IsBlowup()
{
	return isBlowup;
}
void EnemyBoss::blowupAction()//∂Ø◊˜
{
	isBlowup = true;
	
	int i;
	CCArray *idleFrames=CCArray::create();
	idleFrames->retain();
	for(i=1;i<13;i++)
	{
		CCSpriteFrame* frame;
		if (i>9)
		{
			 frame=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(CCString::createWithFormat("fireflame/missile-explode/h00%d.png",i)->getCString());
			
		}
		else
			 frame=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(CCString::createWithFormat("fireflame/missile-explode/h000%d.png",i)->getCString());
		
		idleFrames->addObject(frame);
	}
	CCAnimation* idleAnimation=CCAnimation::createWithSpriteFrames(idleFrames,0.2f);
	CCAnimate *Animate	=	CCAnimate::create(idleAnimation);
	CCRemoveSelf* remove =	CCRemoveSelf::create();
	CCSequence* seq	   =CCSequence::create(Animate,remove,NULL);
	this->runAction(seq);	
	this->removeAllChildren();
}
bool EnemyBoss::init()
{
	bool b1=true;
	initWithSpriteFrameName("mother/main.png");
	float w	=	this->getContentSize().width;
	float h	=	this->getContentSize().height;
	Winsize =CCDirector::sharedDirector()->getVisibleSize();
	this->setPosition(ccp(Winsize.width-w/4,Winsize.height-h/2 - 50));
	this->setScale(0.8f);
	//std::string key="mother/topgun.png";
	//◊ÛΩ≈
	leftleg = CCSprite::create();
	leftleg->initWithSpriteFrameName("mother/left.png");
	this->addChild(leftleg,-1);
	leftleg->setPosition(ccp(50,250));
	//”“Ω≈
	rightleg = CCSprite::create();
	rightleg->initWithSpriteFrameName("mother/engine_right.png");
	this->addChild(rightleg,1);
	rightleg->setPosition(ccp(300,60));

	//  ÷
	tophand = CCSprite::create();
	tophand->initWithSpriteFrameName("mother/gun_right.png");
	this->addChild(tophand,1);
	tophand->setPosition(ccp(350,300));
	//◊”µØ≈⁄Ã®
	
	//◊Û±ﬂ≈⁄Ã®
	gunleft = CCSprite::create();
	gunleft->initWithFile("Boss/cannon_left.png");
	this->addChild(gunleft,-1);
	gunleft->setPosition(ccp(0,380));
	gunleft->setScale(0.6f);
	//”“±ﬂ≈⁄Ã®
	gunright = CCSprite::create();
	gunright->initWithFile("Boss/cannon_left.png");
	this->addChild(gunright,2);
	gunright->setPosition(ccp(270,360));

	Bodymiddle = CCSprite::create("brother/00.png");
	this->addChild(Bodymiddle);
	Bodymiddle->setPosition(ccp(130,230));

	BombBig = CCSprite::create();
	BombBig->initWithSpriteFrameName("mother/bomb.png");
	this->addChild(BombBig);
	BombBig->setPosition(ccp(80,100));

	BodyHind=CCSprite::create();
	BodyHind->initWithSpriteFrameName("mother/bomb_shell.png");
	BodyHind->setPosition(ccp(80,90));
	this->addChild(BodyHind);

	manofgun=CCSprite::create();
	manofgun->initWithSpriteFrameName("mother/topgun.png");
	this->addChild(manofgun,3);
	manofgun->setPosition(ccp(30,240));
	manofgun->setRotation(-30);
	islevel=true;
	TimeCount=0;
	return b1;
}
void EnemyBoss::initBossEnemy()
{

}

void EnemyBoss::Bossmove()
{
	//ƒ∏Ω¢÷˜Ã‚
	CCPointArray * array1 = CCPointArray::create(20);
	array1->addControlPoint(ccp(this->getPositionX(),this->getPositionY()));
	array1->addControlPoint(ccp(this->getPositionX()+15,this->getPositionY()));
	array1->addControlPoint(ccp(this->getPositionX()+15,this->getPositionY()+15));
	array1->addControlPoint(ccp(this->getPositionX(),this->getPositionY()));
	CCActionInterval  * CardinalSplineTo1=CCCardinalSplineTo::create(2, array1, 0);
	CCActionInterval * repeatForever1 =CCRepeatForever::create((CCActionInterval* )CardinalSplineTo1);
	this->runAction(repeatForever1);
	//ƒ∏Ω¢”“Ω≈
	CCPointArray * array = CCPointArray::create(20);
	array->addControlPoint(ccp(300,60));
	array->addControlPoint(ccp(330,60));
	array->addControlPoint(ccp(330,90));
	array->addControlPoint(ccp(300,60));
	CCActionInterval  * CardinalSplineTo=CCCardinalSplineTo::create(2, array, 0);
	CCActionInterval * repeatForever =CCRepeatForever::create((CCActionInterval* )CardinalSplineTo);
	rightleg->runAction(repeatForever);
	//ƒ∏Ω¢ ÷
	//tophand->setPosition(ccp(350,300));
	CCPointArray * array2 = CCPointArray::create(20);
	array2->addControlPoint(ccp(330,300));
	array2->addControlPoint(ccp(330,330));
	array2->addControlPoint(ccp(350,330));
	array2->addControlPoint(ccp(350,300));
	CCActionInterval  * CardinalSplineTo2=CCCardinalSplineTo::create(2, array2, 0);
	CCActionInterval * repeatForever2 =CCRepeatForever::create((CCActionInterval* )CardinalSplineTo2);
	tophand->runAction(repeatForever2);
	//ƒ∏Ω¢ ÷≈⁄
	//gunright->setPosition(ccp(270,360));
	CCPointArray * array3 = CCPointArray::create(20);
	array3->addControlPoint(ccp(250,360));
	array3->addControlPoint(ccp(250,390));
	array3->addControlPoint(ccp(270,390));
	array3->addControlPoint(ccp(270,360));
	CCActionInterval  * CardinalSplineTo3=CCCardinalSplineTo::create(2, array3, 0);
	CCActionInterval * repeatForever3 =CCRepeatForever::create((CCActionInterval* )CardinalSplineTo3);
	gunright->runAction(repeatForever3);
	//ƒ∏Ω¢◊Û≈⁄Ã®
	CCPointArray * array4 = CCPointArray::create(20);
	array4->addControlPoint(ccp(0,380));
	array4->addControlPoint(ccp(20,400));
	array4->addControlPoint(ccp(20,380));
	array4->addControlPoint(ccp(0,380));
	CCActionInterval  * CardinalSplineTo4=CCCardinalSplineTo::create(2, array4, 0);
	CCActionInterval * repeatForever4 =CCRepeatForever::create((CCActionInterval* )CardinalSplineTo4);
	gunleft->runAction(repeatForever4);

	CCPointArray * array5 = CCPointArray::create(20);
	array5->addControlPoint(ccp(50,250));
	array5->addControlPoint(ccp(70,270));
	array5->addControlPoint(ccp(70,250));
	array5->addControlPoint(ccp(50,250));
	CCActionInterval  * CardinalSplineTo5=CCCardinalSplineTo::create(2, array5, 0);
	CCActionInterval * repeatForever5 =CCRepeatForever::create((CCActionInterval* )CardinalSplineTo5);
	leftleg->runAction(repeatForever5);
		//gunleft->setPosition(ccp(0,380));
		//leftleg->setPosition(ccp(50,250));
	//≈–∂œµ–ª˙ «∑Ò◊ﬂ≥ˆÕº≤„
	
}
void EnemyBoss::MoveBossBullet()
{
	float nextoneX = BombBig->getPositionX() - 10;
	BombBig->setPositionX(nextoneX);
	if (nextoneX<-900)
	{
		BombBig->setPosition(ccp(80,100));
	}
}
void EnemyBoss::MoveBombBig()
{
	float y=BombBig->getPositionY();
	float x=BombBig->getPositionX();
	if (!isit)
	{
		float x2 = vy*(x-goal.x)/sqrt((x-goal.x)*(x-goal.x)+(y-goal.y)*(y-goal.y));
		float y2 = vy*(y-goal.y)/sqrt((x-goal.x)*(x-goal.x)+(y-goal.y)*(y-goal.y));
		goal.setPoint(x2,y2);
		isit=true;
	}
	x=x-goal.x;
	y=y-goal.y;
	BombBig->setPosition(ccp(x,y));
}