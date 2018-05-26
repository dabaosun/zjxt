#include "ImgStorage.h"

ImgStorage* ImgStorage::m_instance = new ImgStorage();

ImgStorage* ImgStorage::GetInstance()
{
	return m_instance;
}

