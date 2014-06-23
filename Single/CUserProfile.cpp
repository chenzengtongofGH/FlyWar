#include "CUserProfile.h"
USING_NS_CC;
CUserProfile::CUserProfile():lastgrade(0)
{

}
CUserProfile::~CUserProfile()
{

}
//ItemInfo* CUserProfile::getItemInfoByID( std::string strID)
//{
//	std::vector<ItemInfo>::iterator iter  = m_vecItemInfo.begin();
//	for (;iter!=m_vecItemInfo.end();++iter)
//	{
//		if (iter->mItemID == strID)
//		{
//			return &(*iter);
//		}
//	}
//	return NULL;
//}
////添加道具函数
//void CUserProfile::AddItem(std::string itemId)
//{
//	ItemInfo item;
//	item.mItemID = itemId;
//	m_vecItemInfo.push_back(item);
//}
////添加子弹函数
//void CUserProfile::AddWeapon(std::string WeaponId,std::string Weappicture)
//{
//	WeaponInfo weapon;
//	weapon.weapon_static_id = WeaponId;
//	weapon.weapon_picture   = Weappicture;
//	isWeapon=true;
//	m_vecWeaponInfo.push_back(weapon);
//}
////添加英雄函数
//void CUserProfile::AddHero(std::string heroId)
//{
//	HeroInfo hero;
//	hero.npc_id = heroId;
//	m_vecHeroInfo.push_back(hero);
//}
////设置英雄状态函数
//void CUserProfile::setHeroStatus(int index,int status)
//{
//	if(index >=0 && index < m_vecHeroInfo.size())
//		m_vecHeroInfo[index].npc_status = status;
//	//m_vecHeroInfo->at(index)
//}
////获取英雄状态
//int  CUserProfile::getHeroStatus(int index)
//{
//	if(index >=0 && index < m_vecHeroInfo.size())
//		return m_vecHeroInfo[index].npc_status;
//}
//void	CUserProfile::ClearItem()
//{
//	m_vecItemInfo.clear();
//}
