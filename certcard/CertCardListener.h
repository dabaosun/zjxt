/***************************************************************
* Name:      CertCardListener.h
* Purpose:   Cert card's listener interface.
* Author:    sunzhenbao (suzhenbao@live.com)
* Copyright: sunzhenbao ()
* License:
**************************************************************/

#ifndef __ICERTCARDLISTENER__
#define __ICERTCARDLISTENER__

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


class ICertCardListener
{
public:
	virtual ~ICertCardListener() {};
	virtual void UpdateCardAuthed(bool authed, const std::string& info) = 0 ;
	virtual void UpdateCertCardInfo(const std::shared_ptr<CertCardInfo>& info) = 0;

	virtual void StartProcess(const std::string& info) = 0;
	virtual void EndProcess(int result, const std::string& info) = 0;
	virtual void UpdateProgressInfo(int progress, const std::string& info) = 0;
protected:
	ICertCardListener() {};
};

#endif //__ICERTCARDLISTENER__
