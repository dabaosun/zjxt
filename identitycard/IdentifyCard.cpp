#include "IdentifyCard.h"
#include "HD_SDTapi_x64.h"

IdentifyCard::IdentifyCard()
{

	HD_InitComm(101);
}


IdentifyCard::~IdentifyCard()
{
}
