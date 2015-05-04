#include "NativeFunctionManager.h"

static std::map<std::string, hookedNative*> natives;

NativeFunctionManager::NativeFunctionManager()
{
	
}

NativeFunctionManager::~NativeFunctionManager()
{

}

NativeFunctionManager &NativeFunctionManager::get()
{
	static NativeFunctionManager instance;
	return instance;
}

void NativeFunctionManager::registerFunction(AMX* amx, std::string name, AMX_NATIVE functionAddr, int index)
{ 
	functions[name] = functionAddr;
	functionNames[index] = name;
	hookFunction(amx, functionAddr, name.c_str());
}

std::string NativeFunctionManager::getFunctionName(int index)
{
    std::unordered_map<int, std::string> ::iterator it = functionNames.find(index);
	return (it == functionNames.end()) ? "" : it->second;
}

AMX_NATIVE NativeFunctionManager::findFunction(char const *name)
{
    std::unordered_map<std::string, AMX_NATIVE>::iterator it = functions.find(name);
	return it != functions.end() ? it->second : nullptr;
}

std::map<std::string, hookedNative*> NativeFunctionManager::getNatives()
{
	return natives;
}

static cell AMX_NATIVE_CALL n_OnAmxCreateVehicle(AMX* amx, cell* params) {
	static hookedNative *hookedNative = natives["CreateVehicle"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	int paramcount = params[0] / sizeof(cell);
	if (paramcount == 8)
		OnAmxVehicleCreated(ret, params[1], amx_ctof(params[2]), amx_ctof(params[3]), amx_ctof(params[4]), amx_ctof(params[5]), 0, 0, params[6], params[7], params[8]);
	else if (paramcount == 7)
		OnAmxVehicleCreated(ret, params[1], amx_ctof(params[2]), amx_ctof(params[3]), amx_ctof(params[4]), amx_ctof(params[5]), 0, 0, params[6], params[7], 60);
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxAddStaticVehicle(AMX* amx, cell* params) {
	static hookedNative *hookedNative = natives["AddStaticVehicle"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	int paramcount = params[0] / sizeof(cell);
	if (paramcount == 8)
		OnAmxVehicleCreated(ret, params[1], amx_ctof(params[2]), amx_ctof(params[3]), amx_ctof(params[4]), amx_ctof(params[5]), 0, 0, params[6], params[7], params[8]);
	else if (paramcount == 7)
		OnAmxVehicleCreated(ret, params[1], amx_ctof(params[2]), amx_ctof(params[3]), amx_ctof(params[4]), amx_ctof(params[5]), 0, 0, params[6], params[7], 60);
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxAddStaticVehicleEx(AMX* amx, cell* params) {
	static hookedNative *hookedNative = natives["AddStaticVehicleEx"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	int paramcount = params[0] / sizeof(cell);
	if (paramcount == 8)
		OnAmxVehicleCreated(ret, params[1], amx_ctof(params[2]), amx_ctof(params[3]), amx_ctof(params[4]), amx_ctof(params[5]), 0, 0, params[6], params[7], params[8]);
	else if (paramcount == 7)
		OnAmxVehicleCreated(ret, params[1], amx_ctof(params[2]), amx_ctof(params[3]), amx_ctof(params[4]), amx_ctof(params[5]), 0, 0, params[6], params[7], 60);
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxDestroyVehicle(AMX* amx, cell* params) {
	static hookedNative *hookedNative = natives["DestroyVehicle"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	OnAmxDestroyVehicle(params[1]);
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxSampObjectCreated(AMX* amx, cell* params) {
	static hookedNative *hookedNative = natives["CreateObject"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	int paramcount = params[0] / sizeof(cell);
	if (paramcount == 7)
		OnAmxSampObjectCreated(ret, params[1], amx_ctof(params[2]), amx_ctof(params[3]), amx_ctof(params[4]), amx_ctof(params[5]), amx_ctof(params[6]), amx_ctof(params[7]), 0, 0, 0.0);
	else if (paramcount == 8)
		OnAmxSampObjectCreated(ret, params[1], amx_ctof(params[2]), amx_ctof(params[3]), amx_ctof(params[4]), amx_ctof(params[5]), amx_ctof(params[6]), amx_ctof(params[7]), 0, 0, amx_ctof(params[8]));
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxSampObjectDestroyed(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["DestroyObject"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	OnAmxSampObjectDestroyed(params[1]);
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxAttachObjectToVehicle(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["AttachObjectToVehicle"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	OnAmxAttachObjectToVehicle(params[1], params[2], amx_ctof(params[3]), amx_ctof(params[4]), amx_ctof(params[5]), amx_ctof(params[6]), amx_ctof(params[7]), amx_ctof(params[8]));
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxAttachObjectToPlayer(AMX *amx, cell* params)
{
	static hookedNative *hookedNative = natives["AttachObjectToPlayer"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	OnAmxAttachObjectToPlayer(params[1], params[2], amx_ctof(params[3]), amx_ctof(params[4]), amx_ctof(params[5]), amx_ctof(params[6]), amx_ctof(params[7]), amx_ctof(params[8]));
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxAttachObjectToObject(AMX *amx, cell* params)
{
	static hookedNative *hookedNative = natives["AttachObjectToObject"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	OnAmxAttachObjectToObject(params[1], params[2], amx_ctof(params[3]), amx_ctof(params[4]), amx_ctof(params[5]), amx_ctof(params[6]), amx_ctof(params[7]), amx_ctof(params[8]));
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxCreatePlayerObject(AMX *amx, cell* params)
{
	static hookedNative *hookedNative = natives["CreatePlayerObject"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	int paramcount = params[0] / sizeof(cell);
	if (paramcount == 8) //without drawdistance
		OnAmxCreatePlayerObject(params[1], params[2], amx_ctof(params[3]), amx_ctof(params[4]), amx_ctof(params[5]), amx_ctof(params[6]), amx_ctof(params[7]), amx_ctof(params[8]), 0.0, 0, 0, ret);
	else if (paramcount == 9) //with drawdistance
		OnAmxCreatePlayerObject(params[1], params[2], amx_ctof(params[3]), amx_ctof(params[4]), amx_ctof(params[5]), amx_ctof(params[6]), amx_ctof(params[7]), amx_ctof(params[8]), amx_ctof(params[9]), 0, 0, ret);
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxDestroyPlayerObject(AMX *amx, cell* params)
{
	static hookedNative *hookedNative = natives["DestroyPlayerObject"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	OnAmxDestroyPlayerObject(params[1], params[2]);
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxSetPlayerAttachedObject(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["SetPlayerAttachedObject"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	OnAmxSetPlayerAttachedObject(params[1], params[2], params[3], params[4], amx_ctof(params[5]), amx_ctof(params[6]), amx_ctof(params[7]), amx_ctof(params[8]), amx_ctof(params[9]), amx_ctof(params[10]), amx_ctof(params[11]), amx_ctof(params[12]), amx_ctof(params[13]), params[14], params[15]);
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxRemovePlayerAttachedObject(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["RemovePlayerAttachedObject"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	OnAmxRemovePlayerAttachedObject(params[1], params[2]);
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxDestroyPickup(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["DestroyPickup"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	OnAmxDestroyPickup(params[1]);
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxCreatePickup(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["CreatePickup"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	OnAmxCreatePickup(params[1], params[2], amx_ctof(params[3]), amx_ctof(params[4]), amx_ctof(params[5]), params[6], ret);
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxAddStaticPickup(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["AddStaticPickup"];
	hookedNative->hook->get()->unhook();
	hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	OnAmxAddStaticPickup(params[1], params[2], amx_ctof(params[3]), amx_ctof(params[4]), amx_ctof(params[5]), params[6]);
	return 1;
}

static cell AMX_NATIVE_CALL n_OnAmxCreateLabel(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["Create3DTextLabel"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	char text[1024];
	amx_GetString(amx, params[1], text, sizeof(text));
	OnAmxCreateLabel(text, params[2], amx_ctof(params[3]), amx_ctof(params[4]), amx_ctof(params[5]), amx_ctof(params[6]), params[7], params[8], ret);
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxDeleteLabel(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["Delete3DTextLabel"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	OnAmxDeleteLabel(params[1]);
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxAttachLabelToPlayer(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["Attach3DTextLabelToPlayer"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	OnAmxAttachLabelToPlayer(params[1], params[2], amx_ctof(params[3]), amx_ctof(params[4]), amx_ctof(params[5]));
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxAttachLabelToVehicle(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["Attach3DTextLabelToVehicle"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	OnAmxAttachLabelToVehicle(params[1], params[2], amx_ctof(params[3]), amx_ctof(params[4]), amx_ctof(params[5]));
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxLabelUpdateText(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["Update3DTextLabelText"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	char text[1024];
	amx_GetString(amx, params[3], text, sizeof(text));
	OnAmxUpdateLabel(params[1], params[2], text);
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxCreatePlayerLabel(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["CreatePlayer3DTextLabel"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	char text[1024];
	amx_GetString(amx, params[2], text, sizeof(text));
	OnAmxCreatePlayerLabel(params[1], text, params[3], amx_ctof(params[4]), amx_ctof(params[5]), amx_ctof(params[6]), amx_ctof(params[7]), params[8], params[9], params[10], ret);
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxDeletePlayerLabel(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["DeletePlayer3DTextLabel"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	OnAmxDeletePlayerLabel(params[1], params[2]);
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxUpdatePlayerLabel(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["UpdatePlayer3DTextLabelText"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	char text[1024];
	amx_GetString(amx, params[4], text, sizeof(text));
	OnAmxUpdatePlayerLabel(params[1], params[2], params[3], text);
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxCreateMenu(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["CreateMenu"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	char text[32];
	amx_GetString(amx, params[1], text, sizeof(text));
	OnAmxCreateMenu(text, params[2], amx_ctof(params[3]), amx_ctof(params[4]), amx_ctof(params[5]), amx_ctof(params[6]), ret);
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxSetMenuColumnHeader(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["SetMenuColumnHeader"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	char text[32];
	amx_GetString(amx, params[3], text, sizeof(text));
	OnAmxSetMenuColumnHeader(params[1], params[2], text);
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxDestroyMenu(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["DestroyMenu"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	OnAmxDestroyMenu(params[1]);
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxGangZoneCreate(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["GangZoneCreate"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	OnAmxGangZoneCreate(amx_ctof(params[1]), amx_ctof(params[2]), amx_ctof(params[3]), amx_ctof(params[4]), ret);
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxGangZoneDestroy(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["GangZoneDestroy"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	OnAmxGangZoneDestroy(params[1]);
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxGangZoneShowForPlayer(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["GangZoneShowForPlayer"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	OnAmxGangZoneShowForPlayer(params[1], params[2], params[3]);
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxGangZoneShowForAll(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["GangZoneShowForAll"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	OnAmxGangZoneShowForAll(params[1], params[2]);
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxGangZoneHideForPlayer(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["GangZoneHideForPlayer"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	OnAmxGangZoneHideForPlayer(params[1], params[2]);
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxGangZoneHideForAll(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["GangZoneHideForAll"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	OnAmxGangZoneHideForAll(params[1]);
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxGangZoneFlashForPlayer(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["GangZoneFlashForPlayer"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	OnAmxGangZoneFlashForPlayer(params[1], params[2], params[3]);
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxGangZoneFlashForAll(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["GangZoneFlashForAll"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	OnAmxGangZoneFlashForAll(params[1], params[2]);
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxGangZoneStopFlashForPlayer(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["GangZoneStopFlashForPlayer"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	OnAmxGangZoneStopFlashForPlayer(params[1], params[2]);
	return ret;

}

static cell AMX_NATIVE_CALL n_OnAmxGangZoneStopFlashForAll(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["GangZoneStopFlashForAll"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	OnAmxGangZoneStopFlashForAll(params[1]);
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxSetSkillLevel(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["SetPlayerSkillLevel"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	OnAmxSetSkillLevel(params[1], params[2], params[3]);
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxSetPlayerMapIcon(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["SetPlayerMapIcon"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	if(ret == 1) OnAmxSetPlayerMapIcon(params[1], params[2], amx_ctof(params[3]), amx_ctof(params[4]), amx_ctof(params[5]), params[6], params[7], params[8]);
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxRemovePlayerMapIcon(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["RemovePlayerMapIcon"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	if(ret == 1) OnAmxRemovePlayerMapIcon(params[1], params[2]);
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxShowPlayerDialog(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["ShowPlayerDialog"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	char caption[64], info[2048], button1[32], button2[32];
	amx_GetString(amx, params[4], caption, sizeof(caption));
	amx_GetString(amx, params[5], info, sizeof(info));
	amx_GetString(amx, params[6], button1, sizeof(button1));
	amx_GetString(amx, params[7], button2, sizeof(button2));
	OnAmxShowPlayerDialog(params[1], params[2], params[3], caption, info, button1, button2);
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxSetPlayerWorldBounds(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["SetPlayerWorldBounds"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	OnAmxSetPlayerWorldBounds(params[1], amx_ctof(params[2]), amx_ctof(params[3]), amx_ctof(params[4]), amx_ctof(params[5]));
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxSetPlayerWeather(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["SetPlayerWeather"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	OnAmxSetPlayerWeather(params[1], params[2]);
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxSetPlayerCheckpoint(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["SetPlayerCheckpoint"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	OnAmxSetPlayerCheckpoint(params[1], amx_ctof(params[2]), amx_ctof(params[3]), amx_ctof(params[4]), amx_ctof(params[5]));
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxDisablePlayerCheckpoint(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["DisablePlayerCheckpoint"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	OnAmxDisablePlayerCheckpoint(params[1]);
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxSetPlayerRaceCheckpoint(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["SetPlayerRaceCheckpoint"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	OnAmxSetPlayerRaceCheckpoint(params[1], params[2], amx_ctof(params[3]), amx_ctof(params[4]), amx_ctof(params[5]), amx_ctof(params[6]), amx_ctof(params[7]), amx_ctof(params[8]), amx_ctof(params[9]));
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxDisablePlayerRaceCheckpoint(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["DisablePlayerRaceCheckpoint"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	OnAmxDisablePlayerRaceCheckpoint(params[1]);
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxTogglePlayerSpectating(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["TogglePlayerSpectating"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	OnAmxTogglePlayerSpectating(params[1], params[2]);
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxPlayerSpectatePlayer(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["PlayerSpectatePlayer"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	OnAmxPlayerSpectatePlayer(params[1], params[2], params[3]);
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxPlayerSpectateVehicle(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["PlayerSpectateVehicle"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	OnAmxPlayerSpectateVehicle(params[1], params[2], params[3]);
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxEnableStuntBonusForPlayer(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["EnableStuntBonusForPlayer"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	OnAmxEnableStuntBonusForPlayer(params[1], params[2]);
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxStartRecording(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["StartRecordingPlayerData"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	char recordName[128];
	amx_GetString(amx, params[3], recordName, sizeof(recordName));
	OnAmxStartRecording(params[1], params[2], recordName);
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxStopRecording(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["StopRecordingPlayerData"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	OnAmxStopRecording(params[1]);
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxTogglePlayerControllable(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["TogglePlayerControllable"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	OnAmxToggleControllabel(params[1], params[2]);
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxTextDrawCreate(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["TextDrawCreate"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	char text[1024];
	amx_GetString(amx, params[3], text, sizeof(text));
	OnAmxTextDrawCreate(amx_ctof(params[1]), amx_ctof(params[2]), text, ret);
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxTextDrawDestroy(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["TextDrawShowForPlayer"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	OnAmxTextDrawDestroy(params[1]);
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxTextDrawSetString(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["TextDrawSetString"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	char text[1024];
	amx_GetString(amx, params[2], text, sizeof(text));
	OnAmxTextDrawSetString(params[1], text);
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxTextDrawShowForPlayer(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["TextDrawShowForPlayer"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	OnAmxTextDrawShowForPlayer(params[1], params[2]);
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxTextDrawHideForPlayer(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["TextDrawHideForPlayer"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	OnAmxTextDrawHideForPlayer(params[1], params[2]);
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxTextDrawShowForAll(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["TextDrawShowForAll"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	OnAmxTextDrawShowForAll(params[1]);
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxTextDrawHideForAll(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["TextDrawHideForAll"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	OnAmxTextDrawHideForAll(params[1]);
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxCreatePlayerTextDraw(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["CreatePlayerTextDraw"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	char text[1024];
	amx_GetString(amx, params[4], text, sizeof(text));
	OnAmxCreatePlayerTextDraw(params[1], amx_ctof(params[2]), amx_ctof(params[3]), text, ret);
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxDestroyPlayerTextDraw(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["PlayerTextDrawDestroy"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	OnAmxPlayerTextDrawDestroy(params[1], params[2]);
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxPlayerTextDrawSetString(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["PlayerTextDrawSetString"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	char text[1024];
	amx_GetString(amx, params[3], text, sizeof(text));
	OnAmxPlayerTextDrawSetString(params[1], params[2], text);
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxPlayerTextDrawShow(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["PlayerTextDrawShow"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	OnAmxPlayerTextDrawShow(params[1], params[2]);
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxPlayerTextDrawHide(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["PlayerTextDrawHide"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	OnAmxPlayerTextDrawHide(params[1], params[2]);
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxAddVehicleComponent(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["AddVehicleComponent"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	OnAmxAddVehicleComponent(params[1], params[2]);
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxLinkVehicleToInterior(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["LinkVehicleToInterior"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	OnAmxLinkVehicleToInterior(params[1], params[2]);
	return ret;
}

static cell AMX_NATIVE_CALL n_OnAmxChangeVehicleColor(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["ChangeVehicleColor"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	OnAmxChangeVehicleColor(params[1], params[2], params[3]);
	return ret;
}

static cell AMX_NATIVE_CALL n_SpawnPlayer(AMX* amx, cell* params)
{
	static hookedNative *hookedNative = natives["SpawnPlayer"];
	hookedNative->hook->get()->unhook();
	int ret = hookedNative->originalFunc(amx, params);
	hookedNative->hook->get()->hook();
	OnPlayerSpawn(params[1]);
	return ret;
}

AMX_NATIVE_INFO FunctionNatives[] =
{
	{ "CreateVehicle", n_OnAmxCreateVehicle },
	{ "AddStaticVehicle", n_OnAmxAddStaticVehicle },
	{ "AddStaticVehicleEx", n_OnAmxAddStaticVehicleEx },
	{ "DestroyVehicle", n_OnAmxDestroyVehicle },
	{ "CreateObject", n_OnAmxSampObjectCreated },
	{ "DestroyObject", n_OnAmxSampObjectDestroyed },
	{ "AttachObjectToVehicle", n_OnAmxAttachObjectToVehicle },
	{ "AttachObjectToPlayer", n_OnAmxAttachObjectToPlayer },
	{ "AttachObjectToObject", n_OnAmxAttachObjectToObject },
	{ "CreatePlayerObject", n_OnAmxCreatePlayerObject },
	{ "DestroyPlayerObject", n_OnAmxDestroyPlayerObject },
	{ "SetPlayerAttachedObject", n_OnAmxSetPlayerAttachedObject },
	{ "RemovePlayerAttachedObject", n_OnAmxRemovePlayerAttachedObject },
	{ "DestroyPickup", n_OnAmxDestroyPickup },
	{ "CreatePickup", n_OnAmxCreatePickup },
	{ "AddStaticPickup", n_OnAmxAddStaticPickup },
	{ "Create3DTextLabel", n_OnAmxCreateLabel },
	{ "Delete3DTextLabel", n_OnAmxDeleteLabel },
	{ "Attach3DTextLabelToPlayer", n_OnAmxAttachLabelToPlayer },
	{ "Attach3DTextLabelToVehicle", n_OnAmxAttachLabelToVehicle },
	{ "Update3DTextLabelText", n_OnAmxLabelUpdateText },
	{ "CreatePlayer3DTextLabel", n_OnAmxCreatePlayerLabel },
	{ "DeletePlayer3DTextLabel", n_OnAmxDeletePlayerLabel },
	{ "UpdatePlayer3DTextLabelText", n_OnAmxUpdatePlayerLabel },
	{ "CreateMenu", n_OnAmxCreateMenu },
	{ "SetMenuColumnHeader", n_OnAmxSetMenuColumnHeader },
	{ "DestroyMenu", n_OnAmxDestroyMenu },
	{ "GangZoneCreate", n_OnAmxGangZoneCreate },
	{ "GangZoneDestroy", n_OnAmxGangZoneDestroy },
	{ "GangZoneShowForPlayer", n_OnAmxGangZoneShowForPlayer },
	{ "GangZoneShowForAll", n_OnAmxGangZoneShowForAll },
	{ "GangZoneHideForPlayer", n_OnAmxGangZoneHideForPlayer },
	{ "GangZoneHideForAll", n_OnAmxGangZoneHideForAll },
	{ "GangZoneFlashForPlayer", n_OnAmxGangZoneFlashForPlayer },
	{ "GangZoneFlashForAll", n_OnAmxGangZoneFlashForAll },
	{ "GangZoneStopFlashForPlayer", n_OnAmxGangZoneStopFlashForPlayer },
	{ "GangZoneStopFlashForAll", n_OnAmxGangZoneStopFlashForAll },
	{ "SetPlayerSkillLevel", n_OnAmxSetSkillLevel },
	{ "SetPlayerMapIcon", n_OnAmxSetPlayerMapIcon },
	{ "RemovePlayerMapIcon", n_OnAmxRemovePlayerMapIcon },
	{ "ShowPlayerDialog", n_OnAmxShowPlayerDialog },
	{ "SetPlayerWorldBounds", n_OnAmxSetPlayerWorldBounds },
	{ "SetPlayerWeather", n_OnAmxSetPlayerWeather },
	{ "SetPlayerCheckpoint", n_OnAmxSetPlayerCheckpoint },
	{ "DisablePlayerCheckpoint", n_OnAmxDisablePlayerCheckpoint },
	{ "SetPlayerRaceCheckpoint", n_OnAmxSetPlayerRaceCheckpoint },
	{ "DisablePlayerRaceCheckpoint", n_OnAmxDisablePlayerRaceCheckpoint },
	{ "TogglePlayerSpectating", n_OnAmxTogglePlayerSpectating },
	{ "PlayerSpectatePlayer", n_OnAmxPlayerSpectatePlayer },
	{ "PlayerSpectateVehicle", n_OnAmxPlayerSpectateVehicle },
	{ "EnableStuntBonusForPlayer", n_OnAmxEnableStuntBonusForPlayer },
	{ "StartRecordingPlayerData", n_OnAmxStartRecording },
	{ "StopRecordingPlayerData", n_OnAmxStopRecording },
	{ "TogglePlayerControllable", n_OnAmxTogglePlayerControllable },
	{ "TextDrawCreate", n_OnAmxTextDrawCreate },
	{ "TextDrawDestroy", n_OnAmxTextDrawDestroy },
	{ "TextDrawSetString", n_OnAmxTextDrawSetString },
	{ "TextDrawShowForPlayer", n_OnAmxTextDrawShowForPlayer },
	{ "TextDrawHideForPlayer", n_OnAmxTextDrawHideForPlayer },
	{ "TextDrawShowForAll", n_OnAmxTextDrawShowForAll },
	{ "TextDrawHideForAll", n_OnAmxTextDrawHideForAll },
	{ "CreatePlayerTextDraw", n_OnAmxCreatePlayerTextDraw },
	{ "PlayerTextDrawDestroy", n_OnAmxDestroyPlayerTextDraw },
	{ "PlayerTextDrawSetString", n_OnAmxPlayerTextDrawSetString },
	{ "PlayerTextDrawShow", n_OnAmxPlayerTextDrawShow },
	{ "PlayerTextDrawHide", n_OnAmxPlayerTextDrawHide },
	{ "AddVehicleComponent", n_OnAmxAddVehicleComponent },
	{ "LinkVehicleToInterior", n_OnAmxLinkVehicleToInterior },
	{ "ChangeVehicleColor", n_OnAmxChangeVehicleColor },
	{ "SpawnPlayer", n_SpawnPlayer }
};

void NativeFunctionManager::hookFunction(AMX* amx, AMX_NATIVE function, const char *name)
{
	for (int i = 0; i < sizeof(FunctionNatives) / sizeof(AMX_NATIVE_INFO); i++)
	{
		if (!strcmp(name, FunctionNatives[i].name))
		{
            std::map<std::string, hookedNative*>::iterator it = natives.find(name);
			if (it != natives.end()) return;
			hookedNative *hook = new hookedNative();
			hook->funcName = std::string(name);
			hook->originalFunc = function;
			hook->hook = new std::shared_ptr<SimpleInlineHook>(new SimpleInlineHook);
			hook->hook->get()->init((void*)function, (void*)FunctionNatives[i].func);
            hook->hook->get()->hook();
			//amx_SetNativeAddress(amx, list[b].name, FunctionNatives[i].func);
			natives[hook->funcName] = hook;
			return;
		}
	}
}

void NativeFunctionManager::clearFunctions()
{
	for (auto& it : natives)
	{
		it.second->hook->get()->unhook();
		delete it.second;
	}
	natives.clear();
}