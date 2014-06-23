#ifndef _BULLET_H_
#define _BULLET_H_

#include "cocos2d.h"

enum BULLET_TYPE
{
   BULLET_RED = 1,
   BULLET_BLUE
};

class Bullet : public cocos2d::CCSprite
{
public:
	Bullet(void);
	~Bullet(void);
public:
	virtual bool init();
public:
	/*简单工厂：提供一接口 用于创建某种对象 -并返回该对象*/
	static Bullet* create();
	static Bullet* create(std::string fileName);
	static Bullet* create(BULLET_TYPE type);
public:
	/*移动偏移量*/
	float offsetY;
public:
	void move();
	void destory();
	bool hitTest(cocos2d::CCNode* enemy);
	void BulletAction();
private:
	/*移动速度*/
	float vy;

};

#endif	//_BULLET_H_


