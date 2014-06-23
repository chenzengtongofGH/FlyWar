#pragma once
#include "Singleton.h"
//class FlyClass
//{
//public:
//	int lastgrade;
//	FlyClass()
//	{
//		lastgrade=0;
//	}
//};
class CUserProfile : public Singleton<CUserProfile>
{
public:
	CUserProfile();
	~CUserProfile(void);

	/*void	AddItem(std::string itemId);
	void	ClearItem();
	void	SetMoney(int money) { m_money = money;	}
	void	AddMoney(int money)	{ m_money += money;	}
	void	UseMoney(int money) { m_money -= money;	}*/

	//获取英雄数据列表
	//const std::vector<HeroInfo>& getHeroInfo() const { return m_vecHeroInfo; }	
	//void	AddHero(std::string heroId);		//添加一个英雄，例如招募英雄调用
	//void	setHeroStatus(int index,int status);	//设置英雄的状态：出战，治疗，空闲，升级等状态
	//int		getHeroStatus(int index);		//获得由index指定的英雄的状态
	//获取子弹列表
	//const std::vector<WeaponInfo>& getWeaponInfo() const { return m_vecWeaponInfo; }
	//void	AddWeapon(std::string WeaponId,std::string Weappicture);		//添加一个英雄，例如招募英雄调用
	//WeaponInfo* getWeaponInfoByID(std::string strID);
	//std::string getWeaponInfoBypicture();
	//bool isWeapon;
	//bool GetWeapon(){ return isWeapon;}

	//const std::vector<ItemInfo>& getItemInfo() const { return m_vecItemInfo; }
	//ItemInfo* getItemInfoByID( std::string strID);

	//显示最后成绩
	void AddGrade(int grade){lastgrade = grade;};
	int  GetGrade(){return lastgrade;};
private:
	//std::vector<ItemInfo>	m_vecItemInfo;
	int						m_money;
	int lastgrade;
	//std::vector<HeroInfo>	m_vecHeroInfo;

	//std::vector<WeaponInfo>	m_vecWeaponInfo;
	//std::vector<FlyPlayer>	m_vecFly;
};
