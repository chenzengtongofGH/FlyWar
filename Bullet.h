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
	/*�򵥹������ṩһ�ӿ� ���ڴ���ĳ�ֶ��� -�����ظö���*/
	static Bullet* create();
	static Bullet* create(std::string fileName);
	static Bullet* create(BULLET_TYPE type);
public:
	/*�ƶ�ƫ����*/
	float offsetY;
public:
	void move();
	void destory();
	bool hitTest(cocos2d::CCNode* enemy);
	void BulletAction();
private:
	/*�ƶ��ٶ�*/
	float vy;

};

#endif	//_BULLET_H_


