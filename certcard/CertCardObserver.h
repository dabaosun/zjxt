#ifndef __CERTCARDOBSERVER__
#define __CERTCARDOBSERVER__

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
	virtual void CertCardAuthed() = 0 ;
	virtual void UpdateCertCardInfo(std::shared_ptr<CertCardInfo> info) = 0;
protected:
	CertCardObserver() {};
};

#endif
