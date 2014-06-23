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
	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);//开始触摸
	virtual void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);//结束触摸


	
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::CCScene* CreateScene();
	
	//地图时间滚动的回调函数
	void gameStart();//开始游戏
	void gameStep(float dt);//游戏动画
	void addFlyPlane(float dt);
	void createEnemyWithTimer(float dt);//敌军动画
	void createButtleWithTimer(float dt);//创建子弹动画
	void createBossButtleWithTimer(float dt);//创建Boss子弹动画
	void MoveAllEnemy();//移动所以地方飞机
	void MoveAllBullet();//子弹发射设置
	void MoveAllBossBullet();//Boss子弹发射
	void CheckBulletWithEnemy();//检测子弹碰撞
	void CheckBulletWithPlayer();//检测玩家和敌机的碰撞
	void CheckBulletWithBoss();//检测子弹跟Boss
	void CheckBossBulletWithPlayer();//检测Boss子弹跟飞机
	void UpdateNumber(int i);//计算消灭敌机的个数
	void EnemyBoss1();//创建Bosss
	void GameOver();
	void MoveBoss(float dt);//移动敌机
	void PauseScene(CCObject* pSender);
	void BeginScene(CCObject* pSender);
	void resurgence(float dt);
private:
	
	GameObject* mBack;//背景对象
	FlyPlayer* mPlayer;//飞机对象
	LearnClass *Learnlayer;
	cocos2d::CCPoint touchPos;//飞机触摸点
	cocos2d::CCSize Winsize;//窗口大小
	cocos2d::CCLabelTTF *gradeMoney;//钱的Lab
	int gradeNumber;//计算击毁敌机数量
	std::vector<Bullet*>	playerBullet;//子弹容器
	std::vector<EnemyBase*>	enemyList;//敌机容器
	std::vector<BossBullet*>	bossBullet;//子弹容器
	bool BossStart;//是否创建boss
	bool startB;//是否开始boss
	EnemyBoss* mBoss;//申明boss对象
	bool isBoss;//boos是否爆炸
	UILayer* xianshikuang;//血条的显示
	UILayer* GameEnd;
	CCProgressTimer *BossBlood;
	bool isbossBlowup;
	bool isStartGame;

};
#endif // _IN_GAME_LAYER_H_

