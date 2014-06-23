#pragma once
#include "cocos2d.h"
#include "EnemyBase.h"
using namespace cocos2d;
class EnemyBoss : public EnemyBase
{
public:
	EnemyBoss(void);
	~EnemyBoss(void);
public:
	void Bossmove();//移动
	//void hrut(float dmg);//受伤
	//void blowupAction();//动作
	void initBossEnemy(const std::string& frameName,const int&blowup,int hp,int speed);//初始化敌机
	CCSize Winsize;
	//void destory();//消失
	//bool IsBlowup();
};


