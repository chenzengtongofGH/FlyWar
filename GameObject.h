#ifndef _Game_Object_H_
#define _Game_Object_H_
#include "cocos2d.h"
class GameObject : public cocos2d::CCLayer
{
public:
	GameObject(void);
	~GameObject(void);
public:
	CREATE_FUNC(GameObject);
	virtual bool init();  
	void move();
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
private:
	cocos2d::CCSprite* back1;
	cocos2d::CCSprite* back2;
	//Ì®Ëú
	cocos2d::CCSprite* back3;
	cocos2d::CCSprite* back4;
	//·¿×Ó
	cocos2d::CCSprite* back5;
	cocos2d::CCSprite* back6;
	float vy;
	cocos2d::CCSize  Winsize;
	//static cocos2d::Scene* CreateScene();
};
#endif 
