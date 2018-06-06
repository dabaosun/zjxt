#ifndef __IMGSTORAGE__
#define __IMGSTORAGE__
#include <string>
#include <mutex>

class ImgStorage
{
public:
	static ImgStorage* GetInstance();
	int UploadFile(const std::string& filename, std::string& remoteurl);
	~ImgStorage();
private:
	static ImgStorage* m_instance;
	ImgStorage();

};

#endif //__IMGSTORAGE__
