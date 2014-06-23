#include "InGameLayer.h"
#include "WelComeLayer.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;

InGameLayer::InGameLayer(void) :Winsize(0,0),
							    mBack(NULL),
								mPlayer(NULL),
								mBoss(NULL),
								isBoss(false),	
								touchPos(ccp(200,200)),
								gradeNumber(0),
								BossStart(false),
								startB(false),
								isbossBlowup(false),
								isStartGame(false)
{
}
																				
InGameLayer::~InGameLayer(void)
{ 
}
CCScene* InGameLayer::CreateScene()
{
	// 'scene' is an autorelease object
	CCScene *scene = CCScene::create();
	// 'layer' is an autorelease object
	InGameLayer *layer = InGameLayer::create();
	// add layer as a child to scene
	scene->addChild(layer);
	// return the scene
	return scene;
}
bool InGameLayer::init()
{
	bool b1 = CCLayer::init();
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("feiji.plist");//提供plist接口将图片加载到缓存中
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Boss/mother.plist");
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("plane/plane.plist");
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("weapon/fireflame.plist");
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("weapon/flash.plist");
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("weapon/h.plist");
	mBack = GameObject::create();
	this->addChild(mBack);
	//设置锚点
	mBack->setAnchorPoint(ccp(0,0));
	mBack->setPosition(0,0);
	
	addFlyPlane(1.0);
 	
	Winsize	=CCDirector::sharedDirector()->getVisibleSize();
	//SimpleAudioEngine::getInstance()->playEffect("shoot.mp3");
	mBack->move();

	//分数条
	gradeMoney =CCLabelTTF::create("Grade:0","Minion Pro",36);
	this->addChild(gradeMoney,5);
	gradeMoney->setPosition(ccp(Winsize.width*2/3,Winsize.height-60));

	
	//上面的UI设计
	xianshikuang=UILayer::create();
	xianshikuang->addWidget(GUIReader::shareReader()->widgetFromJsonFile("UI/MainFlyAction_1/MainFlyAction_1.json"));
	this->addChild(xianshikuang,2);
	xianshikuang->setPosition(ccp(0,Winsize.height-xianshikuang->getContentSize().height/7));
	//
	//暂停游戏
	CCMenuItemImage *pCloseItem = CCMenuItemImage::create( 
		"pauseN.png", //png.jpg等图片格式都是可以的  
		"pauseN.png",  
		this,  
		menu_selector(InGameLayer::PauseScene));  
	CCMenu* pMenu = CCMenu::create(pCloseItem,NULL);
	pMenu->setPosition(ccp(Winsize.width-395,Winsize.height-37));
	this->addChild(pMenu,2);
	//开始游戏
	CCMenuItemImage *pCloseItem1 = CCMenuItemImage::create( 
		"begin.png", //png.jpg等图片格式都是可以的  
		"begin.png",  
		this,  
		menu_selector(InGameLayer::BeginScene));  
	CCMenu* pMenu1 = CCMenu::create(pCloseItem1,NULL);
	pMenu1->setPosition(ccp(Winsize.width/6,Winsize.height-20));
	this->addChild(pMenu1,2);

	//血条
	BossBlood = CCProgressTimer::create(CCSprite::create("blood.png"));
	BossBlood->setType(kCCProgressTimerTypeBar);	//设置为条形 
	//设置初始进度为满血 
	BossBlood->setPercentage(100.0f);
	BossBlood->setBarChangeRate(ccp(1,0));
	BossBlood->setMidpoint(ccp(0,0));//设置扣血向量
	//设置位置，与上里的空血框堆叠，且居于其上 
	BossBlood->setPosition(ccp(Winsize.width-110,Winsize.height-27));
	BossBlood->setScale(1.1f);
	this->addChild(BossBlood,2);
	//bosshrutAction();
	//EnemyBase* mEnemy	=	EnemyBase::create();
	//mEnemy->initEnemy("enemy",4);
	//this->addChild(mEnemy);
	return b1;
}
//重新添加飞机
void InGameLayer::addFlyPlane(float dt)
{
	mPlayer=FlyPlayer::create();
	this->addChild(mPlayer);
	mPlayer->setPosition(ccp(200,300));
	isStartGame=true;
}
//开始游戏
void InGameLayer::BeginScene(CCObject* pSender)
{
	CCDirector::sharedDirector()->startAnimation();
}
//暂停游戏
void InGameLayer::PauseScene(CCObject* pSender)
{
	CCDirector::sharedDirector()->stopAnimation();
}
//游戏开始
void InGameLayer::gameStart()
{
	this->schedule(SEL_SCHEDULE(&InGameLayer::gameStep),0.02f);//提供接口开启时间调用函数，0.02秒调用一次
	if (BossStart)
	{
		
	}
	else 
	{
		if (isStartGame)//是否开始游戏
		{
			this->schedule(SEL_SCHEDULE(&InGameLayer::createEnemyWithTimer),CCRANDOM_0_1()+0.5f);//提供接口开启时间调用函数，0.02秒调用一次
		}
		
	}
		
	this->schedule(SEL_SCHEDULE(&InGameLayer::createButtleWithTimer),0.1f);
}
//移动Boss
void InGameLayer::MoveBoss(float dt)
{
	if (!isBoss)
	{
		mBoss->Bossmove();
	}
	
}
//更新调用函数
void InGameLayer::gameStep(float dt)
{
	if (isStartGame)
	{
		mBack->move();
		mPlayer->moveTo(touchPos);

		MoveAllBullet();
		MoveAllBossBullet();
		CheckBulletWithPlayer();

		if (BossStart)
		{
			if (!startB)
			{
				EnemyBoss1();
				this->schedule(SEL_SCHEDULE(&InGameLayer::createBossButtleWithTimer),CCRANDOM_0_1()+3.0f);

			}
			if (!isBoss)
			{
				CheckBulletWithBoss();
				CheckBossBulletWithPlayer();

			}
			this->unschedule(SEL_SCHEDULE(&InGameLayer::createEnemyWithTimer));
		}
		else

		{
			this->unschedule(SEL_SCHEDULE(&InGameLayer::createBossButtleWithTimer));
			this->schedule(SEL_SCHEDULE(&InGameLayer::createEnemyWithTimer),CCRANDOM_0_1()+0.5f);
			CheckBulletWithEnemy();
			MoveAllEnemy();
		}
	}
	
}
//敌机创建
void InGameLayer::EnemyBoss1()//创建Boss
{
	//炸毁所以小敌机
	EnemyBase* getEnemy		=	NULL;
	for (int i = enemyList.size()-1;i>=0;i--)
	{
		getEnemy	=	enemyList.at(i);
		getEnemy->blowupAction();
		int countGrade=getEnemy->blowupNums;//计算应该得分
		switch(countGrade)
		{
		case 1:
			UpdateNumber(2);
			break;
		case 2:
			UpdateNumber(1);
			break;
		case 3:
			UpdateNumber(5);
		case 4:
			UpdateNumber(3);
			break;
		}
		std::vector<EnemyBase*>::iterator iter1 = enemyList.begin()+i;
		enemyList.erase(iter1);
	}
	//创建Boss
	mBoss = EnemyBoss::create();
	this->addChild(mBoss);
	mBoss->Bossmove();
	startB=true;
}
//更新分数
void InGameLayer::UpdateNumber(int i)
{
	char sz[20];
	gradeNumber+=i;
	if (gradeNumber%51==0)
	{
		BossStart=true;
		isBoss=false;
	}
	sprintf(sz,"Grade:%d",gradeNumber);
	gradeMoney->setString(sz);
}
//进入游戏启用函数
void InGameLayer::onEnterTransitionDidFinish()
{
	gameStart();
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,0,true);	
}
/*移动所有的敌机*/
void InGameLayer::MoveAllEnemy()
{
 	EnemyBase* getEnemy =NULL;
 	for (int i = enemyList.size()-1; i>=0;i--)
 	{
 		getEnemy	=	enemyList.at(i);
		getEnemy->move();
 		if (getEnemy->getPositionX() <=-getEnemy->getContentSize().width/2)
 		{
			getEnemy->destory();
 			std::vector<EnemyBase*>::iterator iter = enemyList.begin()+i;
 			enemyList.erase(iter);
 		}
 	}
}

bool InGameLayer::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)//开始触摸
{
	return true;//true成功，false不成功
}
 void InGameLayer::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)//开始触摸
{
	touchPos= pTouch->getLocation();//获取当前鼠标位置给飞机
}
void InGameLayer::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)//开始触摸
{

}
/*定时创建敌机*/
void InGameLayer::createEnemyWithTimer(float dt)
{
 	int enemyType	=	CCRANDOM_0_1()*4+1;
 	EnemyBase* mEnemy	=	EnemyBase::create();
	switch(enemyType)
	{
	case 1:
		mEnemy->initEnemy("enemy_m",enemyType,100,5);
		break;
	case 2:
		mEnemy->initEnemy("enemy_s",enemyType,50,10);
		break;
	case 3:
		mEnemy->initEnemy("enemy_b",enemyType,200,2);
	case 4:
		mEnemy->initEnemy("enemy_t",enemyType,150,3);
		break;
	}
 	this->addChild(mEnemy);
 	enemyList.push_back(mEnemy);
}
//定时创建Boss子弹
void InGameLayer::createBossButtleWithTimer(float dt)//创建Boss子弹动画
{
	BossBlood->setPercentage(100);
	mBoss->goal = mPlayer->getPosition();
	BossBullet* mBossBullet[10];	
	for (int i = 0 ;i<5;i++)
	{
		mBossBullet[i]=BossBullet::create();
		this->addChild(mBossBullet[i]);
		mBossBullet[i]->setPosition(ccp(Winsize.width-50-30*i,Winsize.height/2));
		bossBullet.push_back(mBossBullet[i]);
		float x=mBoss->getPositionX();
		float y=mBoss->getPositionY();
	}	
	BossBullet* m1;
	m1=BossBullet::create();
	this->addChild(m1);
	m1->goal=mPlayer->getPosition();
	m1->setPosition(ccp(Winsize.width-100,200));
	bossBullet.push_back(m1);
}
/*定时创建子弹*/
void InGameLayer::createButtleWithTimer(float dt)
{
	if (isStartGame)
	{
		Bullet* mBullet	=	Bullet::create();
		this->addChild(mBullet);
		mBullet->setPosition(mPlayer->getPosition() +ccp(mPlayer->getContentSize().width/2,0));
		playerBullet.push_back(mBullet);
	}
 	
}
//检查Boss子弹和我方飞机
void InGameLayer::CheckBossBulletWithPlayer()//检测Boss子弹跟飞机
{
	BossBullet* getBossBullet		=	NULL;
	for (int i = bossBullet.size()-1;i>=0;i--)
	{
		getBossBullet	=	bossBullet.at(i);
		if (getBossBullet->boundingBox().containsPoint(mPlayer->getPosition()))
		{
			mPlayer->blowupAction();
			GameOver(); 
		}
	}
}
//检车我方子弹和Boss
void InGameLayer::CheckBulletWithBoss()
{
	mBoss->MoveBossBullet();//Boss子弹移动
	Bullet*	   getBullet	=	NULL;
		for (int j	=	playerBullet.size()-1;j>=0;j--)
		{
			getBullet	=	playerBullet.at(j);
			if (!isBoss)
			{
				if (getBullet->hitTest(mBoss))
				{
					//把子弹删除
					getBullet->destory();
					std::vector<Bullet*>::iterator iter = playerBullet.begin()+j;
					playerBullet.erase(iter);
					mBoss->hrut(5.0f);
					BossBlood->setPercentage(mBoss->HP/10);
					if (mBoss->HP<500&&!isbossBlowup)
					{
						mBoss->bosshrutAction();
						isbossBlowup=true;
					}
					//mBoss->hrutAction();
					//检测碰撞扣血
					if (mBoss->IsBlowup())
					{
						mBoss->blowupAction();
						UpdateNumber(20);
						BossStart=false;
						isBoss=true;
						startB=false;
					}
				}
			}
		}
}
//检测子弹碰撞的函数
void InGameLayer::CheckBulletWithEnemy()
{
	//获取所以的子弹和敌机
 	EnemyBase* getEnemy		=	NULL;
 	Bullet*	   getBullet	=	NULL;
 	for (int i = enemyList.size()-1;i>=0;i--)
 	{
 		getEnemy	=	enemyList.at(i);
 		for (int j	=	playerBullet.size()-1;j>=0;j--)
 		{
 			getBullet	=	playerBullet.at(j);
 			if (getEnemy->IsBlowup())
 			{
 				std::vector<EnemyBase*>::iterator iter1 = enemyList.begin()+i;
 				enemyList.erase(iter1);
 				break;
 			}
 			if (getBullet->hitTest(getEnemy))
 			{
 				//把子弹删除
 				getBullet->destory();
 				std::vector<Bullet*>::iterator iter = playerBullet.begin()+j;
 				playerBullet.erase(iter);
 				//检测碰撞扣血
 				getEnemy->hrut(20.0f);
 				if (getEnemy->IsBlowup())
 				{
					int countGrade=getEnemy->blowupNums;//计算应该得分
					switch(countGrade)
					{
					case 1:
						UpdateNumber(2);
						break;
					case 2:
						UpdateNumber(1);
						break;
					case 3:
						UpdateNumber(5);
					case 4:
						UpdateNumber(4);
						break;
					}
 					std::vector<EnemyBase*>::iterator iter1 = enemyList.begin()+i;
 					enemyList.erase(iter1);
 					break;
 				}
 			}
 		}
 	}
}
//检测敌机和我方飞机函数
void InGameLayer::CheckBulletWithPlayer()
{
	EnemyBase* getEnemy		=	NULL;
	for (int i = enemyList.size()-1;i>=0;i--)
	{
		getEnemy	=	enemyList.at(i);
		if (getEnemy->boundingBox().containsPoint(mPlayer->getPosition()))
		{
			//mPlayer->blowupAction();
			GameOver(); 
		}
	}
}
void InGameLayer::GameOver()
{
	////剔除
	this->removeChild(mPlayer);
	isStartGame=false;
	this->unscheduleAllSelectors();
	CCScene *s = CCDirector::sharedDirector()->getRunningScene();

	//CCScene* pause = LearnClass::CreateScene();
	Learnlayer = LearnClass::create();
	s->addChild(Learnlayer,5);
	Learnlayer->setAnchorPoint(CCPointZero);
	//Learnlayer->setPosition(ccp(Winsize.width/2,Winsize.height/2));
	Learnlayer->LsetText(gradeNumber);
	this->schedule(SEL_SCHEDULE(&InGameLayer::resurgence),1.0f);
	//pause->setPosition(Winsize.width/2,Winsize.height/2);
	//CCDirector::sharedDirector()->pushScene(pause);
//	CCDirector::sharedDirector()->replaceScene(LearnClass::CreateScene());
}
void InGameLayer::resurgence(float dt)
{
	if (Learnlayer->recover)
	{
		//this->resumeSchedulerAndActions();
		this->unschedule(SEL_SCHEDULE(&InGameLayer::resurgence));
		this->removeChild(Learnlayer);
		touchPos=ccp(200,200);
		gameStart();
		this->schedule(SEL_SCHEDULE(&InGameLayer::createBossButtleWithTimer),CCRANDOM_0_1()+3.0f);
		this->scheduleOnce(SEL_SCHEDULE(&InGameLayer::addFlyPlane),2.0f);
	}
}
//移动所以的子弹
void InGameLayer::MoveAllBullet()
{
 	Bullet* getBullet =	NULL;
 	//EnemyBase* getEnemy =NULL;
 	for (int i = playerBullet.size()-1; i>=0;i--)
 	{
 		getBullet	=playerBullet[i];
 		getBullet->move();
		//getBullet->BulletAction();
 		//在Vector中删除对象
 		if (getBullet->getPositionX()>=Winsize.width+getBullet->getContentSize().width/2)
 		{
 			getBullet->destory();
 			std::vector<Bullet*>::iterator iter = playerBullet.begin()+i;
 			playerBullet.erase(iter);
 		}
 	}
}
//移动所以的Boss子弹
void InGameLayer::MoveAllBossBullet()
{
	
	BossBullet* getBullet =	NULL;
	for (int i = bossBullet.size()-1; i>=0;i--)
	{
		getBullet	=bossBullet[i];
		//getBullet->move();
		getBullet->dingxiangmove();
		//getBullet->BulletAction();
		//在Vector中删除对象
		if (getBullet->getPositionX()<=0)
		{
			getBullet->destory();
			std::vector<BossBullet*>::iterator iter = bossBullet.begin()+i;
			bossBullet.erase(iter);
		}
	}
}
