#include "global.h"

CBitmapManager* CBitmapManager::m_instance = nullptr;

void CBitmapManager::Initiallize()
{
	for (int i = 0; i < NUM_OF_IMAGES; ++i) {
		CImage tempImg;
		CString str;
		str.Format("%d.bmp",i);
		tempImg.Load(str);
		m_map.insert(make_pair(str,tempImg));
	}
}
void CBitmapManager::Update()
{
}
void CBitmapManager::Render()
{
}
void CBitmapManager::Release()
{
}

std::map<CString, CImage>& CBitmapManager::GetImage()
{
	return m_map;
}