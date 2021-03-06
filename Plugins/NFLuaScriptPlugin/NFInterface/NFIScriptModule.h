// -------------------------------------------------------------------------
//    @FileName         ��    NFIScriptModule.h
//    @Author           ��    LvSheng.Huang
//    @Date             ��    2013-07-08
//    @Module           ��    NFIScriptModule
//    @Desc             :     every script plugin need to export two interfaces(NFCScriptVarList and most of NFCScriptKernel)
// -------------------------------------------------------------------------

#ifndef NFI_SCRIPT_MODULE_H
#define NFI_SCRIPT_MODULE_H

#include <iostream>
#include "NFComm/NFPluginModule/NFIModule.h"
#include "NFComm/NFCore/NFCDataList.h"
#include "NFComm/NFPluginModule/NFGUID.h"
#include "NFComm/NFPluginModule/NFIElementModule.h"
#include "NFComm/NFPluginModule/NFIKernelModule.h"
#include "NFComm/NFPluginModule/NFIClassModule.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"

class NFIScriptModule
    : public NFIModule
{

public:

};

#endif
