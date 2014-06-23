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
	virtual bool init();  //��ʼ������
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	//static cocos2d::CCScene* CreateScene(CCRenderTexture *sqr, bool isFlip);//��������
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
	void setfirstProblem();//���õ�һ������
	void setSecondProblem();//���õڶ�������
	void setThirdProblem();//���õ���������
	void setFourProblem();//���õ��ĸ�����
	void setFiveProblem();//���õ��������

	void initUIFile();//��ʼ��ui�ؼ�
	void setProblem(int i);//����ѡȡ����Ŀ
	void LsetText(int i);//����UI������ʾ����
	void gotoLearn(CCObject* pSender);//����ѧϰ����
	void gotoOver(CCObject* pSender);//������Ϸ��������
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

