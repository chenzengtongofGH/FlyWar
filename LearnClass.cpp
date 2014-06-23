#include "LearnClass.h"
#include "GameOver.h"
LearnClass::LearnClass(void):isAnswer(false),AnswerNum(0),recover(false)
{
}


LearnClass::~LearnClass(void)
{
}
char* LearnClass::zhuanyi(string str)
{
	char *inBuf = new char[str.length()+1] ;
	strcpy(inBuf,str.c_str());
	size_t inLen = strlen(inBuf);
	size_t outLen = inLen << 1;
	char *outBuf = (char *)malloc(outLen);
	gbk2utf8(inBuf, inLen, outBuf, outLen);
	return outBuf;
}
//创建一个场景，装载WelComeLayer类
bool LearnClass::init()
{
	bool b1 = CCLayer::init();
	//读取题目库
	GameEnd=UILayer::create();
	this->addChild(GameEnd);
	GameEnd->addWidget(GUIReader::shareReader()->widgetFromJsonFile("UI/DeadScene_1/DeadScene_1.json"));
	GameEnd->setTouchEnabled(true);
	GameEnd->setScale(1.5);
	GameEnd->setPosition(517,330);
	Tscore	=	dynamic_cast<UITextField*>(GameEnd->getWidgetByName("TextField_score"));
	Thighchain	=dynamic_cast<UITextField*>(GameEnd->getWidgetByName("TextField_highchain"));
	Blearn = dynamic_cast<UITextButton*>(GameEnd->getWidgetByName("Button_learn"));
	Bend   = dynamic_cast<UITextButton*>(GameEnd->getWidgetByName("Button_end"));
	if (Blearn)
	{
		Blearn->addReleaseEvent(this, coco_releaseselector(LearnClass::gotoLearn));
	}
	if (Bend)
	{
		Bend->addReleaseEvent(this, coco_releaseselector(LearnClass::gotoOver));
	}
	
	//Blearn->setTouchEnabled(true);
	return b1;
}
void LearnClass::gotoLearn(CCObject* pSender)
{
	this->removeChild(GameEnd);
	LearnLayer=UILayer::create();
	LearnLayer->addWidget(GUIReader::shareReader()->widgetFromJsonFile("UI/DialogDesign_1/DialogDesign_1.json"));
	this->addChild(LearnLayer);
	LearnLayer->setPosition(ccp(250,180));
	std::string path = CCFileUtils::sharedFileUtils()->fullPathForFilename("LearnScene/test.json");
	unsigned long nSize = 0;
	unsigned char* strInfo = CCFileUtils::sharedFileUtils()->getFileData(path.c_str(), "rb", &nSize);
	std::string strJson = std::string((char*)strInfo);
	CSJson::Reader reader;
	CSJson::Value root;
	if(reader.parse(strJson, root))
	{
		for(CSJson::Value::iterator iter = root.begin(); iter != root.end(); ++iter)
		{
			SProblem *NewData =new SProblem();
			NewData->SID=(*iter)["ID"].asString();
			NewData->STitle=(*iter)["Title"].asString();
			NewData->SProblemA=(*iter)["ProblemA"].asString();
			NewData->SProblemB=(*iter)["ProblemB"].asString();
			NewData->SProblemC=(*iter)["ProblemC"].asString();
			NewData->SProblemD=(*iter)["ProblemD"].asString();
			Data.push_back(NewData);
		}
	}
	initUIFile();
	int a =CCRANDOM_0_1()*5+1;
	setProblem(a);
}
void LearnClass::initUIFile()
{
	for (int i=0;i<5;i++)
	{
		char b[20];
		sprintf(b,"Label_%d",i+1);
		Alabel[i] = dynamic_cast<UILabel*>(LearnLayer->getWidgetByName(b));
	}
	for (int i=0;i<4;i++)
	{
		char b[20];
		sprintf(b,"Button_%d",i+1);
		Abutton[i] = dynamic_cast<UITextButton*>(LearnLayer->getWidgetByName(b));
	}
	Abutton[0]->addReleaseEvent(this, coco_releaseselector(LearnClass::AchioceButton));
	Abutton[1]->addReleaseEvent(this, coco_releaseselector(LearnClass::BchioceButton));
	Abutton[2]->addReleaseEvent(this, coco_releaseselector(LearnClass::CchioceButton));
	Abutton[3]->addReleaseEvent(this, coco_releaseselector(LearnClass::DchioceButton));
	AbttonOK = dynamic_cast<UITextButton*>(LearnLayer->getWidgetByName("Button_OK"));
	AbttonOK->addReleaseEvent(this, coco_releaseselector(LearnClass::CheckisAnswer));
}
void LearnClass::setfirstProblem()
{
	std::vector<SProblem*>::iterator itemlist =Data.begin();
	for(;itemlist != Data.end(); ++itemlist)
	{
		if (((*itemlist)->SID)=="1")
		{
			Alabel[0]->setText(zhuanyi((*itemlist)->STitle));
			Alabel[0]->setFontSize(18);
			Alabel[1]->setText(zhuanyi((*itemlist)->SProblemA));
			Alabel[2]->setText(zhuanyi((*itemlist)->SProblemB));
			Alabel[3]->setText(zhuanyi((*itemlist)->SProblemC));
			Alabel[4]->setText(zhuanyi((*itemlist)->SProblemD));
			AnswerNum=1;
		}
	}
}
void LearnClass::setSecondProblem()
{
	std::vector<SProblem*>::iterator itemlist =Data.begin();
	for(;itemlist != Data.end(); ++itemlist)
	{
		if (((*itemlist)->SID)=="2")
		{
			Alabel[0]->setText(zhuanyi((*itemlist)->STitle));
			Alabel[0]->setFontSize(18);
			Alabel[1]->setText(zhuanyi((*itemlist)->SProblemA));
			Alabel[2]->setText(zhuanyi((*itemlist)->SProblemB));
			Alabel[3]->setText(zhuanyi((*itemlist)->SProblemC));
			Alabel[4]->setText(zhuanyi((*itemlist)->SProblemD));
			AnswerNum=2;
		}
	}
}
void LearnClass::setThirdProblem()//设置第三个问题
{
	std::vector<SProblem*>::iterator itemlist =Data.begin();
	for(;itemlist != Data.end(); ++itemlist)
	{
		if (((*itemlist)->SID)=="3")
		{
			Alabel[0]->setText(zhuanyi((*itemlist)->STitle));
			Alabel[0]->setFontSize(18);
			Alabel[1]->setText(zhuanyi((*itemlist)->SProblemA));
			Alabel[2]->setText(zhuanyi((*itemlist)->SProblemB));
			Alabel[3]->setText(zhuanyi((*itemlist)->SProblemC));
			Alabel[4]->setText(zhuanyi((*itemlist)->SProblemD));
			AnswerNum=3;
		}
	}
}
void LearnClass::setFourProblem()//设置第四个问题
{
	std::vector<SProblem*>::iterator itemlist =Data.begin();
	for(;itemlist != Data.end(); ++itemlist)
	{
		if (((*itemlist)->SID)=="4")
		{
			Alabel[0]->setText(zhuanyi((*itemlist)->STitle));
			Alabel[0]->setFontSize(18);
			Alabel[1]->setText(zhuanyi((*itemlist)->SProblemA));
			Alabel[2]->setText(zhuanyi((*itemlist)->SProblemB));
			Alabel[3]->setText(zhuanyi((*itemlist)->SProblemC));
			Alabel[4]->setText(zhuanyi((*itemlist)->SProblemD));
			AnswerNum=4;
		}
	}
}
void LearnClass::setFiveProblem()//设置第五个问题
{
	std::vector<SProblem*>::iterator itemlist =Data.begin();
	for(;itemlist != Data.end(); ++itemlist)
	{
		if (((*itemlist)->SID)=="5")
		{
			Alabel[0]->setText(zhuanyi((*itemlist)->STitle));
			Alabel[0]->setFontSize(18);
			Alabel[1]->setText(zhuanyi((*itemlist)->SProblemA));
			Alabel[2]->setText(zhuanyi((*itemlist)->SProblemB));
			Alabel[3]->setText(zhuanyi((*itemlist)->SProblemC));
			Alabel[4]->setText(zhuanyi((*itemlist)->SProblemD));
			AnswerNum=5;
		}
	}
}
void LearnClass::setProblem(int i)
{

	switch(i)
	{
	case 1:
		setfirstProblem();//设置第一个问题
		break;
	case 2:
		setSecondProblem();//设置第二个问题
		break;
	case 3:
		setThirdProblem();//设置第三个问题
		break;
	case 4:
		setFourProblem();//设置第四个问题
		break;
	case 5:
		setFiveProblem();//设置第五个问题
		break;
	}
}
void LearnClass::gotoOver(CCObject* pSender)
{
	//替换当前场景
	CCDirector::sharedDirector()->replaceScene(GameOver::CreateScene());
}
//选择A按钮函数
void LearnClass::AchioceButton(CCObject* pSender)
{
	std::vector<SProblem*>::iterator itemlist =Data.begin();
	for(;itemlist != Data.end(); ++itemlist)
	{
		if (((*itemlist)->SID)=="2"&&AnswerNum==2||((*itemlist)->SID)=="5"&&AnswerNum==5)
			isAnswer=true;
	}
}
//选择B按钮函数
void LearnClass::BchioceButton(CCObject* pSender)
{
	std::vector<SProblem*>::iterator itemlist =Data.begin();
	for(;itemlist != Data.end(); ++itemlist)
	{
		if (((*itemlist)->SID)=="1"&&AnswerNum==1)
			isAnswer=true;
	}
}
//选择C按钮函数
void LearnClass::CchioceButton(CCObject* pSender)
{
	std::vector<SProblem*>::iterator itemlist =Data.begin();
	for(;itemlist != Data.end(); ++itemlist)
	{
		if (((*itemlist)->SID)=="3"&&AnswerNum==3)
			isAnswer=true;
	}
}
//选择D按钮函数
void LearnClass::DchioceButton(CCObject* pSender)
{
	std::vector<SProblem*>::iterator itemlist =Data.begin();
	for(;itemlist != Data.end(); ++itemlist)
	{
		if (((*itemlist)->SID)=="4"&&AnswerNum==4)
			isAnswer=true;
	}
}
void LearnClass::CheckisAnswer(CCObject* pSender)
{
	if (isAnswer)
	{
		this->removeAllChildren();
		recover=true;
		//CCScene *s = CCDirector::sharedDirector()->getRunningScene();
		//InGameLayer::addFlyPlane();
	}
	else 
		gotoOver(pSender);
}
//设置分数显示框
void LearnClass::LsetText(int i)
{
	char buff[20];
	int  x = 100000-i;
	sprintf(buff,"%d",i);
	Tscore->setText(buff);
	Tscore->setFontSize(24);
	sprintf(buff,"%d",x);
	Thighchain->setText(buff);
	Thighchain->setFontSize(24);
}