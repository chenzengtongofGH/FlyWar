#pragma once
#include "c:\cocos2d-x-2.2.1\cocos2dx\layers_scenes_transitions_nodes\cclayer.h"
#include "cocos2d.h"
using namespace cocos2d;
class GameOver :public CCLayer
{
public:
	GameOver(void);
	~GameOver(void);
	
	CREATE_FUNC(GameOver);
	virtual bool init();  //��ʼ������
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::CCScene* CreateScene();//��������
	void fanhui(CCObject* pSender);

};

