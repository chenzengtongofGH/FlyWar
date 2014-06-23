#ifndef _Enemy_Base_H_
#define _Enemy_Base_H_
#include "cocos2d.h"
class EnemyBase : public cocos2d::CCSprite
{
public:
	EnemyBase(void);
	~EnemyBase(void);
	virtual bool init();  
	CREATE_FUNC(EnemyBase);
public:
	void move();//�ƶ�
	void hrut(float dmg);//����
	void blowupAction();//����
	void initEnemy(const std::string& frameName,const int&blowup,int hp,int speed);//��ʼ���л�
	void destory();//��ʧ
	bool IsBlowup();
public:
	std::string mframeName;
	int blowupNums ;
	float Speedvy;
	float Hp;
	bool isBlowup;
};
#endif

