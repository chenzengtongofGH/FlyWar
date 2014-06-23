#ifndef _IN_GAME_LAYER_H_
#define _IN_GAME_LAYER_H_
#include "cocos2d.h"
#include "GameObject.h"
#include "FlyPlayer.h"
#include "EnemyBase.h"
#include "Bullet.h"
#include "EnemyBoss.h"
#include "BossBullet.h"
#include "cocos-ext.h" 
#include "LearnClass.h"
using namespace cocos2d::extension;
class InGameLayer :public cocos2d::CCLayer
{
public:
	InGameLayer(void);
	~InGameLayer(void);
public:
	CREATE_FUNC(InGameLayer);
	virtual bool init();  
	virtual void onEnterTransitionDidFinish();
	//virtual void registerWithTouchDispatcher();
	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);//��ʼ����
	virtual void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);//��������


	
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::CCScene* CreateScene();
	
	//��ͼʱ������Ļص�����
	void gameStart();//��ʼ��Ϸ
	void gameStep(float dt);//��Ϸ����
	void addFlyPlane(float dt);
	void createEnemyWithTimer(float dt);//�о�����
	void createButtleWithTimer(float dt);//�����ӵ�����
	void createBossButtleWithTimer(float dt);//����Boss�ӵ�����
	void MoveAllEnemy();//�ƶ����Եط��ɻ�
	void MoveAllBullet();//�ӵ���������
	void MoveAllBossBullet();//Boss�ӵ�����
	void CheckBulletWithEnemy();//����ӵ���ײ
	void CheckBulletWithPlayer();//�����Һ͵л�����ײ
	void CheckBulletWithBoss();//����ӵ���Boss
	void CheckBossBulletWithPlayer();//���Boss�ӵ����ɻ�
	void UpdateNumber(int i);//��������л��ĸ���
	void EnemyBoss1();//����Bosss
	void GameOver();
	void MoveBoss(float dt);//�ƶ��л�
	void PauseScene(CCObject* pSender);
	void BeginScene(CCObject* pSender);
	void resurgence(float dt);
private:
	
	GameObject* mBack;//��������
	FlyPlayer* mPlayer;//�ɻ�����
	LearnClass *Learnlayer;
	cocos2d::CCPoint touchPos;//�ɻ�������
	cocos2d::CCSize Winsize;//���ڴ�С
	cocos2d::CCLabelTTF *gradeMoney;//Ǯ��Lab
	int gradeNumber;//������ٵл�����
	std::vector<Bullet*>	playerBullet;//�ӵ�����
	std::vector<EnemyBase*>	enemyList;//�л�����
	std::vector<BossBullet*>	bossBullet;//�ӵ�����
	bool BossStart;//�Ƿ񴴽�boss
	bool startB;//�Ƿ�ʼboss
	EnemyBoss* mBoss;//����boss����
	bool isBoss;//boos�Ƿ�ը
	UILayer* xianshikuang;//Ѫ������ʾ
	UILayer* GameEnd;
	CCProgressTimer *BossBlood;
	bool isbossBlowup;
	bool isStartGame;

};
#endif // _IN_GAME_LAYER_H_

