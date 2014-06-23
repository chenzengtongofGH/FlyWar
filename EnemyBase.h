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
	void move();//移动
	void hrut(float dmg);//受伤
	void blowupAction();//动作
	void initEnemy(const std::string& frameName,const int&blowup,int hp,int speed);//初始化敌机
	void destory();//消失
	bool IsBlowup();
public:
	std::string mframeName;
	int blowupNums ;
	float Speedvy;
	float Hp;
	bool isBlowup;
};
#endif

