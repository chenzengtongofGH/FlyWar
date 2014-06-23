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
	void Bossmove();//�ƶ�
	void hrut(float dmg);//����
	void hrutAction();
	void blowupAction();//����
	void destory();//��ʧ
	virtual bool init();  
	CREATE_FUNC(EnemyBoss);
	void initBossEnemy();//��ʼ���л�
	CCSize Winsize;
	
	float Speedvy;

	CCSprite* BossBlowupSprite;
	CCSprite* BossBlowupSprite1;
	CCSprite* BossBlowupSprite2;
	void bosshrutAction();

	CCSprite* rightleg;//�ҽ�
	CCSprite* leftleg;//���
	CCSprite* tophand;//����
	CCSprite* gunmiddle;//�ӵ��м�

	CCSprite* Bodymiddle;//���
	CCSprite* BodyHind;//���ء�
	CCSprite* BombBig;//����
	CCSprite* gunleft;//�ӵ����
	CCSprite* gunright;//�ӵ��ұ�
	CCSprite* manofgun;//���˵��ӵ�
	bool islevel;
	bool isvertical;
	int TimeCount;
	float HP;
	CCSprite* fire;
	
	bool isBlowup;
//	void destory();//��ʧ
	bool IsBlowup();
	void MoveBossBullet();

	float vy;
	cocos2d::CCPoint goal;
	bool isit;
	void MoveBombBig();
};


