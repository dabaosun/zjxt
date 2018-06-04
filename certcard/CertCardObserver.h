#ifndef __CERTCARDOBSERVER__
#define __CERTCARDOBSERVER__

#include <memory>
typedef struct {
	std::shared_ptr<char> name;
	std::shared_ptr<char> gendar;
	std::shared_ptr<char> nation;
	std::shared_ptr<char> birth;
	std::shared_ptr<char> address;
	std::shared_ptr<char> certno;
	std::shared_ptr<char> department;
	std::shared_ptr<char> effectdata;
	std::shared_ptr<char> expire;
	std::shared_ptr<char> bmpdata;

} CertCardInfo;


class CertCardObserver
{
public:
	virtual ~CertCardObserver() {};
	virtual void UpdateCardAuthed(bool authed, std::string info) = 0 ;
	virtual void UpdateCertCardInfo(std::shared_ptr<CertCardInfo> info) = 0;

	virtual void StartProcess(int result, std::string info) = 0;
	virtual void EndProcess(int result, std::string info) = 0;
	virtual void UpdateProgressInfo(int progress, std::string info) = 0;
protected:
	CertCardObserver() {};
};

#endif
