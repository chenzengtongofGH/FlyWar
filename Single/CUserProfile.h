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

	//��ȡӢ�������б�
	//const std::vector<HeroInfo>& getHeroInfo() const { return m_vecHeroInfo; }	
	//void	AddHero(std::string heroId);		//���һ��Ӣ�ۣ�������ļӢ�۵���
	//void	setHeroStatus(int index,int status);	//����Ӣ�۵�״̬����ս�����ƣ����У�������״̬
	//int		getHeroStatus(int index);		//�����indexָ����Ӣ�۵�״̬
	//��ȡ�ӵ��б�
	//const std::vector<WeaponInfo>& getWeaponInfo() const { return m_vecWeaponInfo; }
	//void	AddWeapon(std::string WeaponId,std::string Weappicture);		//���һ��Ӣ�ۣ�������ļӢ�۵���
	//WeaponInfo* getWeaponInfoByID(std::string strID);
	//std::string getWeaponInfoBypicture();
	//bool isWeapon;
	//bool GetWeapon(){ return isWeapon;}

	//const std::vector<ItemInfo>& getItemInfo() const { return m_vecItemInfo; }
	//ItemInfo* getItemInfoByID( std::string strID);

	//��ʾ���ɼ�
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
