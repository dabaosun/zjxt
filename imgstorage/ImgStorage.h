#ifndef __IMGSTORAGE__
#define __IMGSTORAGE__

class ImgStorage
{
public:
	~ImgStorage();
private:
	static ImgStorage* m_instance;
	static ImgStorage* GetInstance();
	ImgStorage();


};

#endif //__IMGSTORAGE__
