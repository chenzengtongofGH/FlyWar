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
	void Bossmove();//�ƶ�
	//void hrut(float dmg);//����
	//void blowupAction();//����
	void initBossEnemy(const std::string& frameName,const int&blowup,int hp,int speed);//��ʼ���л�
	CCSize Winsize;
	//void destory();//��ʧ
	//bool IsBlowup();
};


