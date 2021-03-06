// -------------------------------------------------------------------------
//    @FileName			:    NFCLuaScriptModule.h
//    @Author           :    LvSheng.Huang
//    @Date             :    2013-07-08
//    @Module           :    NFCLuaScriptModule
//    @Desc             :
// -------------------------------------------------------------------------

#ifndef NFC_LUA_SCRIPT_MODULE_H
#define NFC_LUA_SCRIPT_MODULE_H

#define LUAINTF_LINK_LUA_COMPILED_IN_CXX 0

#include "Dep/LuaIntf/LuaIntf.h"
#include "NFComm/NFPluginModule/NFIKernelModule.h"
#include "NFComm/NFPluginModule/NFIClassModule.h"
#include "Plugins/NFLuaScriptPlugin/NFInterface/NFILuaScriptModule.h"
//#include "Plugins/NFLuaScriptPlugin/NFInterface/NFIScriptModule.h"

class NFCLuaScriptModule
    : public NFILuaScriptModule
{
public:
    NFCLuaScriptModule(NFIPluginManager* p)
    {
        pPluginManager = p;
    }

    virtual bool Init();
    virtual bool Shut();
    virtual bool Execute();

    virtual bool AfterInit();
    virtual bool BeforeShut();

    virtual bool AddPropertyCallBack(const NFGUID& self, std::string& strPropertyName, std::string& luaFunc);
    virtual bool AddRecordCallBack(const NFGUID& self, std::string& strRecordName, std::string& luaFunc);
    virtual bool AddEventCallBack(const NFGUID& self, const int nEventID, std::string& luaFunc);
    virtual bool AddHeartBeat(const NFGUID& self, std::string& strHeartBeatName, std::string& luaFunc, const float fTime, const int nCount);
    virtual int AddRow(const NFGUID& self, std::string& strRecordName, const NFIDataList& var);

    virtual bool AddClassCallBack(const std::string& className, std::string& funcName);

    virtual bool LoadScript(const std::string& strLuaFile);
    virtual bool AddScriptPackagePath(const std::string& strLuaFile);
    virtual bool DoLuaFunction0(const std::string& strFuncName);
    virtual bool DoLuaClassFunction(const std::string& strFuncName, const NFGUID& self, const std::string& strClassName, const CLASS_OBJECT_EVENT eClassEvent, const NFIDataList& var);

protected:
    template<typename... T1>
    bool DoGlobalScriptFun(const std::string& strFuncName, T1... arg);

    template<typename T>
    bool AddLuaFuncToMap(NFMap<T, NFMap<NFGUID, NFList<string>>>& funcMap, const NFGUID& self, T key, std::string& luaFunc);
    template<typename T1, typename... T2>
    bool CallLuaFuncFromMap(NFMap<T1, NFMap<NFGUID, NFList<string>>>& funcMap, T1 key, const NFGUID& self, T2... arg);

    int OnLuaPropertyCB(const NFGUID& self, const std::string& strPropertyName, const NFIDataList::TData& oldVar, const NFIDataList::TData& newVar);
    int OnLuaRecordCB(const NFGUID& self, const RECORD_EVENT_DATA& xEventData, const NFIDataList::TData& oldVar, const NFIDataList::TData& newVar);
    int OnLuaHeartBeatCB(const NFGUID& self, const std::string& strHeartBeatName, const float fTime, const int nCount);
    int OnLuaEventCB(const NFGUID& self, const int nEventID, const NFIDataList& argVar);

    int OnClassEventCB(const NFGUID& self, const std::string& strClassName, const CLASS_OBJECT_EVENT eClassEvent, const NFIDataList& var);

protected:
    bool Regisger();

protected:
    NFIElementModule* m_pElementModule;
    NFIKernelModule* m_pKernelModule;
    NFIClassModule* m_pLogicClassModule;

protected:
    LuaIntf::LuaContext l;
    int64_t mnTime;
    NFMap<std::string, NFMap<NFGUID, NFList<std::string>>> m_luaPropertyCallBackFuncMap;
    NFMap<std::string, NFMap<NFGUID, NFList<std::string>>> m_luaRecordCallBackFuncMap;
    NFMap<int, NFMap<NFGUID, NFList<std::string>>> m_luaEventCallBackFuncMap;
    NFMap<std::string, NFMap<NFGUID, NFList<std::string>>> m_luaHeartBeatCallBackFuncMap;

    NFMap<std::string, std::string> m_ClassEventFuncMap;
};



#endif
