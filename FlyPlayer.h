#ifndef _Fly_Player_H_
#define _Fly_Player_H_
#include "cocos2d.h"
class FlyPlayer:public cocos2d::CCSprite
{
public:
	FlyPlayer(void);
	~FlyPlayer(void);
public:
	virtual bool init();  
	CREATE_FUNC(FlyPlayer);
	//�ƶ����ִ���λ��
	void moveTo(cocos2d::CCPoint pos);
	//���û���
	void destory();
	void flyAction();
	void blowupAction();

};
#endif

