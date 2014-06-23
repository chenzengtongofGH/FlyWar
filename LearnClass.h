#pragma once
#include <vector>
#include <string>
#include "c:\cocos2d-x-2.2.1\cocos2dx\layers_scenes_transitions_nodes\cclayer.h"
#include "cocos2d.h"
#include "cocos-ext.h" 
#include "IconvString.h"
using namespace cocos2d::extension;
using namespace cocos2d;
using namespace std;
struct SProblem
{
	string SID;
	string STitle;
	string SProblemA;
	string SProblemB;
	string SProblemC;
	string SProblemD;
	int    answer;
};
class LearnClass :public CCLayer
{
public:
	LearnClass(void);
	~LearnClass(void);
	CREATE_FUNC(LearnClass);
	virtual bool init();  //初始化函数
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	//static cocos2d::CCScene* CreateScene(CCRenderTexture *sqr, bool isFlip);//场景函数
	UILayer* GameEnd;
	UILayer* LearnLayer;
	UITextField* Tscore;
	UITextField* Thighchain;
	
	UILabel* Alabel[5];
	UITextButton* Abutton[4];
	UITextButton* AbttonOK;
	UITextButton* Blearn;
	UITextButton* Bend;

	char* zhuanyi(string str);
	void setfirstProblem();//设置第一个问题
	void setSecondProblem();//设置第二个问题
	void setThirdProblem();//设置第三个问题
	void setFourProblem();//设置第四个问题
	void setFiveProblem();//设置第五个问题

	void initUIFile();//初始化ui控件
	void setProblem(int i);//设置选取的题目
	void LsetText(int i);//设置UI分数显示界面
	void gotoLearn(CCObject* pSender);//弹出学习界面
	void gotoOver(CCObject* pSender);//跳出游戏结束界面
	void AchioceButton(CCObject* pSender);
	void BchioceButton(CCObject* pSender);
	void CchioceButton(CCObject* pSender);
	void DchioceButton(CCObject* pSender);
	void CheckisAnswer(CCObject* pSender);
	std::vector<SProblem* > Data;
	bool isAnswer;
	int  AnswerNum;
	bool recover;
};

