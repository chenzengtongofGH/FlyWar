#ifndef _WELCOME_LAYER_H_
#define _WELCOME_LAYER_H_
#include "cocos2d.h"
class WelComeLayer:public cocos2d::CCLayer
{
public:
	WelComeLayer(void);
	~WelComeLayer(void);
public:
	CREATE_FUNC(WelComeLayer);
	virtual bool init();  //初始化函数
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::CCScene* CreateScene();//场景函数
private:
	void logoAction();//设置首界面LOGO
	cocos2d::CCSize winSize;//获取当前窗口大小
	void btnPlayMenuCallBack(CCObject* pSender);//开始游戏按钮，跳转界面
};
#endif // _WELCOME_LAYER_H_

