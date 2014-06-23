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
	virtual bool init();  //��ʼ������
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::CCScene* CreateScene();//��������
private:
	void logoAction();//�����׽���LOGO
	cocos2d::CCSize winSize;//��ȡ��ǰ���ڴ�С
	void btnPlayMenuCallBack(CCObject* pSender);//��ʼ��Ϸ��ť����ת����
};
#endif // _WELCOME_LAYER_H_

