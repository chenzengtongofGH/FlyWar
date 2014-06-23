#pragma once
#include "cocos2d.h"
#include "EnemyBase.h"
#include "BossBullet.h"
using namespace cocos2d;
class EnemyBoss : public CCSprite
{
public:
	EnemyBoss(void);
	~EnemyBoss(void);
public:
	void Bossmove();//移动
	void hrut(float dmg);//受伤
	void hrutAction();
	void blowupAction();//动作
	void destory();//消失
	virtual bool init();  
	CREATE_FUNC(EnemyBoss);
	void initBossEnemy();//初始化敌机
	CCSize Winsize;
	
	float Speedvy;

	CCSprite* BossBlowupSprite;
	CCSprite* BossBlowupSprite1;
	CCSprite* BossBlowupSprite2;
	void bosshrutAction();

	CCSprite* rightleg;//右脚
	CCSprite* leftleg;//左脚
	CCSprite* tophand;//上手
	CCSprite* gunmiddle;//子弹中间

	CCSprite* Bodymiddle;//人物。
	CCSprite* BodyHind;//隐藏。
	CCSprite* BombBig;//火炮
	CCSprite* gunleft;//子弹左边
	CCSprite* gunright;//子弹右边
	CCSprite* manofgun;//男人的子弹
	bool islevel;
	bool isvertical;
	int TimeCount;
	float HP;
	CCSprite* fire;
	
	bool isBlowup;
//	void destory();//消失
	bool IsBlowup();
	void MoveBossBullet();

	float vy;
	cocos2d::CCPoint goal;
	bool isit;
	void MoveBombBig();
};


