#pragma once
#include "cocos2d.h"
class BossBullet:public cocos2d::CCSprite
{
public:
	BossBullet(void);
	~BossBullet(void);
public:
	virtual bool init();
	void move();
	void dingxiangmove();
	void destory();
	bool hitTest(cocos2d::CCNode* enemy);
	CREATE_FUNC(BossBullet);
	void BulletAction();
	cocos2d::CCPoint goal;
	bool isit;
private:
	/*ÒÆ¶¯ËÙ¶È*/
	float vy;
};

