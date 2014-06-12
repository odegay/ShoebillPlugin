/**
 * Copyright (C) 2011-2014 MK124
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "amx_helper.h"
#include "samp.h"

static cell AMX_NATIVE_CALL n_OnGameModeInit(AMX* amx, cell* params)
{
	return OnGameModeInit();
}

static cell AMX_NATIVE_CALL n_OnGameModeExit(AMX* amx, cell* params)
{
	return OnGameModeExit();
}

static cell AMX_NATIVE_CALL n_OnFilterScriptInit(AMX* amx, cell* params)
{
	return OnFilterScriptInit();
}

static cell AMX_NATIVE_CALL n_OnFilterScriptExit(AMX* amx, cell* params)
{
	return OnFilterScriptExit();
}

static cell AMX_NATIVE_CALL n_OnPlayerConnect(AMX* amx, cell* params)
{
	return OnPlayerConnect(params[1]);
}

static cell AMX_NATIVE_CALL n_OnPlayerDisconnect(AMX* amx, cell* params)
{
	return OnPlayerDisconnect(params[1], params[2]);
}

static cell AMX_NATIVE_CALL n_OnPlayerSpawn(AMX* amx, cell* params)
{
	return OnPlayerSpawn(params[1]);
}

static cell AMX_NATIVE_CALL n_OnPlayerDeath(AMX* amx, cell* params)
{
	return OnPlayerDeath(params[1], params[2], params[3]);
}

static cell AMX_NATIVE_CALL n_OnVehicleSpawn(AMX* amx, cell* params)
{
	return OnVehicleSpawn(params[1]);
}

static cell AMX_NATIVE_CALL n_OnVehicleDeath(AMX* amx, cell* params)
{
	return OnVehicleDeath(params[1], params[2]);
}

static cell AMX_NATIVE_CALL n_OnPlayerText(AMX* amx, cell* params)
{
	char text[1024];
	amx_GetString(amx, params[2], text, sizeof(text));

	return OnPlayerText(params[1], text);
}

static cell AMX_NATIVE_CALL n_OnPlayerCommandText(AMX* amx, cell* params)
{
	char text[1024];
	amx_GetString(amx, params[2], text, sizeof(text));

	return OnPlayerCommandText(params[1], text);
}

static cell AMX_NATIVE_CALL n_OnPlayerRequestClass(AMX* amx, cell* params)
{
	return OnPlayerRequestClass(params[1], params[2]);
}

static cell AMX_NATIVE_CALL n_OnPlayerEnterVehicle(AMX* amx, cell* params)
{
	return OnPlayerEnterVehicle(params[1], params[2], params[3]);
}

static cell AMX_NATIVE_CALL n_OnPlayerExitVehicle(AMX* amx, cell* params)
{
	return OnPlayerExitVehicle(params[1], params[2]);
}

static cell AMX_NATIVE_CALL n_OnPlayerStateChange(AMX* amx, cell* params)
{
	return OnPlayerStateChange(params[1], params[2], params[3]);
}

static cell AMX_NATIVE_CALL n_OnPlayerEnterCheckpoint(AMX* amx, cell* params)
{
	return OnPlayerEnterCheckpoint(params[1]);
}

static cell AMX_NATIVE_CALL n_OnPlayerLeaveCheckpoint(AMX* amx, cell* params)
{
	return OnPlayerLeaveCheckpoint(params[1]);
}

static cell AMX_NATIVE_CALL n_OnPlayerEnterRaceCheckpoint(AMX* amx, cell* params)
{
	return OnPlayerEnterRaceCheckpoint(params[1]);
}

static cell AMX_NATIVE_CALL n_OnPlayerLeaveRaceCheckpoint(AMX* amx, cell* params)
{
	return OnPlayerLeaveRaceCheckpoint(params[1]);
}

static cell AMX_NATIVE_CALL n_OnRconCommand(AMX* amx, cell* params)
{
	char text[1024];
	amx_GetString(amx, params[1], text, sizeof(text));

	return OnRconCommand(text);
}

static cell AMX_NATIVE_CALL n_OnPlayerRequestSpawn(AMX* amx, cell* params)
{
	return OnPlayerRequestSpawn(params[1]);
}

static cell AMX_NATIVE_CALL n_OnObjectMoved(AMX* amx, cell* params)
{
	return OnObjectMoved(params[1]);
}

static cell AMX_NATIVE_CALL n_OnPlayerObjectMoved(AMX* amx, cell* params)
{
	return OnPlayerObjectMoved(params[1], params[2]);
}

static cell AMX_NATIVE_CALL n_OnPlayerPickUpPickup(AMX* amx, cell* params)
{
	return OnPlayerPickUpPickup(params[1], params[2]);
}

static cell AMX_NATIVE_CALL n_OnVehicleMod(AMX* amx, cell* params)
{
	return OnVehicleMod(params[1], params[2], params[3]);
}

static cell AMX_NATIVE_CALL n_OnEnterExitModShop(AMX* amx, cell* params)
{
	return OnEnterExitModShop(params[1], params[2], params[3]);
}

static cell AMX_NATIVE_CALL n_OnVehiclePaintjob(AMX* amx, cell* params)
{
	return OnVehiclePaintjob(params[1], params[2], params[3]);
}

static cell AMX_NATIVE_CALL n_OnVehicleRespray(AMX* amx, cell* params)
{
	return OnVehicleRespray(params[1], params[2], params[3], params[4]);
}

static cell AMX_NATIVE_CALL n_OnVehicleDamageStatusUpdate(AMX* amx, cell* params)
{
	return OnVehicleDamageStatusUpdate(params[1], params[2]);
}

static cell AMX_NATIVE_CALL n_OnUnoccupiedVehicleUpdate(AMX* amx, cell* params)
{
	return OnUnoccupiedVehicleUpdate(params[1], params[2], params[3], amx_ctof(params[4]), amx_ctof(params[5]), amx_ctof(params[6]));
}

static cell AMX_NATIVE_CALL n_OnPlayerSelectedMenuRow(AMX* amx, cell* params)
{
	return OnPlayerSelectedMenuRow(params[1], params[2]);
}

static cell AMX_NATIVE_CALL n_OnPlayerExitedMenu(AMX* amx, cell* params)
{
	return OnPlayerExitedMenu(params[1]);
}

static cell AMX_NATIVE_CALL n_OnPlayerInteriorChange(AMX* amx, cell* params)
{
	return OnPlayerInteriorChange(params[1], params[2], params[3]);
}

static cell AMX_NATIVE_CALL n_OnPlayerKeyStateChange(AMX* amx, cell* params)
{
	return OnPlayerKeyStateChange(params[1], params[2], params[3]);
}

static cell AMX_NATIVE_CALL n_OnRconLoginAttempt(AMX* amx, cell* params)
{
	char ip[16], password[64];
	amx_GetString(amx, params[1], ip, sizeof(ip));
	amx_GetString(amx, params[2], password, sizeof(password));

	return OnRconLoginAttempt(ip, password, params[3]);
}

static cell AMX_NATIVE_CALL n_OnPlayerUpdate(AMX* amx, cell* params)
{
	return OnPlayerUpdate(params[1]);
}

static cell AMX_NATIVE_CALL n_OnPlayerStreamIn(AMX* amx, cell* params)
{
	return OnPlayerStreamIn(params[1], params[2]);
}

static cell AMX_NATIVE_CALL n_OnPlayerStreamOut(AMX* amx, cell* params)
{
	return OnPlayerStreamOut(params[1], params[2]);
}

static cell AMX_NATIVE_CALL n_OnVehicleStreamIn(AMX* amx, cell* params)
{
	return OnVehicleStreamIn(params[1], params[2]);
}

static cell AMX_NATIVE_CALL n_OnVehicleStreamOut(AMX* amx, cell* params)
{
	return OnVehicleStreamOut(params[1], params[2]);
}

static cell AMX_NATIVE_CALL n_OnDialogResponse(AMX* amx, cell* params)
{
	char text[1024];
	amx_GetString(amx, params[5], text, sizeof(text));

	return OnDialogResponse(params[1], params[2], params[3], params[4], text);
}

static cell AMX_NATIVE_CALL n_OnPlayerTakeDamage(AMX* amx, cell* params)
{
	return OnPlayerTakeDamage(params[1], params[2], amx_ctof(params[3]), params[4], params[5]);
}

static cell AMX_NATIVE_CALL n_OnPlayerGiveDamage(AMX* amx, cell* params)
{
	return OnPlayerGiveDamage(params[1], params[2], amx_ctof(params[3]), params[4], params[5]);
}

static cell AMX_NATIVE_CALL n_OnPlayerClickMap(AMX* amx, cell* params)
{
	return OnPlayerClickMap(params[1], amx_ctof(params[2]), amx_ctof(params[3]), amx_ctof(params[4]));
}

static cell AMX_NATIVE_CALL n_OnPlayerClickTextDraw(AMX* amx, cell* params)
{
	return OnPlayerClickTextDraw(params[1], params[2]);
}

static cell AMX_NATIVE_CALL n_OnPlayerClickPlayerTextDraw(AMX* amx, cell* params)
{
	return OnPlayerClickPlayerTextDraw(params[1], params[2]);
}

static cell AMX_NATIVE_CALL n_OnPlayerClickPlayer(AMX* amx, cell* params)
{
	return OnPlayerClickPlayer(params[1], params[2], params[3]);
}

static cell AMX_NATIVE_CALL n_OnPlayerEditObject(AMX* amx, cell* params)
{
	return OnPlayerEditObject(params[1], params[2], params[3], params[4], amx_ctof(params[5]), amx_ctof(params[6]), amx_ctof(params[7]), amx_ctof(params[8]), amx_ctof(params[9]), amx_ctof(params[10]));
}

static cell AMX_NATIVE_CALL n_OnPlayerEditAttachedObject(AMX* amx, cell* params)
{
	return OnPlayerEditAttachedObject(params[1], params[2], params[3], params[4], params[5], amx_ctof(params[6]), amx_ctof(params[7]), amx_ctof(params[8]), amx_ctof(params[9]), amx_ctof(params[10]), amx_ctof(params[11]), amx_ctof(params[12]), amx_ctof(params[13]), amx_ctof(params[14]));
}

static cell AMX_NATIVE_CALL n_OnPlayerSelectObject(AMX* amx, cell* params)
{
	return OnPlayerSelectObject(params[1], params[2], params[3], params[4], amx_ctof(params[5]), amx_ctof(params[6]), amx_ctof(params[7]));
}

static cell AMX_NATIVE_CALL n_OnPlayerWeaponShot(AMX* amx, cell* params)
{
	return OnPlayerWeaponShot(params[1], params[2], params[3], params[4], amx_ctof(params[5]), amx_ctof(params[6]), amx_ctof(params[7]));
}

static cell AMX_NATIVE_CALL n_OnIncomingConnection(AMX* amx, cell* params)
{
	char str[24];
	amx_GetString(amx, params[2], str, sizeof(str));
	return OnIncomingConnection(params[1], str, params[3]);
}


AMX_NATIVE_INFO CallbackNatives[] =
{
	{ "n_OnGameModeInit", n_OnGameModeInit },
	{ "n_OnGameModeExit", n_OnGameModeExit },
	{ "n_OnFilterScriptInit", n_OnFilterScriptInit },
	{ "n_OnFilterScriptExit", n_OnFilterScriptExit },
	{ "n_OnPlayerConnect", n_OnPlayerConnect },
	{ "n_OnPlayerDisconnect", n_OnPlayerDisconnect },
	{ "n_OnPlayerSpawn", n_OnPlayerSpawn },
	{ "n_OnPlayerDeath", n_OnPlayerDeath },
	{ "n_OnVehicleSpawn", n_OnVehicleSpawn },
	{ "n_OnVehicleDeath", n_OnVehicleDeath },
	{ "n_OnPlayerText", n_OnPlayerText },
	{ "n_OnPlayerCommandText", n_OnPlayerCommandText },
	{ "n_OnPlayerRequestClass", n_OnPlayerRequestClass },
	{ "n_OnPlayerEnterVehicle", n_OnPlayerEnterVehicle },
	{ "n_OnPlayerExitVehicle", n_OnPlayerExitVehicle },
	{ "n_OnPlayerStateChange", n_OnPlayerStateChange },
	{ "n_OnPlayerEnterCheckpoint", n_OnPlayerEnterCheckpoint },
	{ "n_OnPlayerLeaveCheckpoint", n_OnPlayerLeaveCheckpoint },
	{ "n_OnPlayerEnterRaceCheckpoint", n_OnPlayerEnterRaceCheckpoint },
	{ "n_OnPlayerLeaveRaceCheckpoint", n_OnPlayerLeaveRaceCheckpoint },
	{ "n_OnRconCommand", n_OnRconCommand },
	{ "n_OnPlayerRequestSpawn", n_OnPlayerRequestSpawn },
	{ "n_OnObjectMoved", n_OnObjectMoved },
	{ "n_OnPlayerObjectMoved", n_OnPlayerObjectMoved },
	{ "n_OnPlayerPickUpPickup", n_OnPlayerPickUpPickup },
	{ "n_OnVehicleMod", n_OnVehicleMod },
	{ "n_OnEnterExitModShop", n_OnEnterExitModShop },
	{ "n_OnVehiclePaintjob", n_OnVehiclePaintjob },
	{ "n_OnVehicleRespray", n_OnVehicleRespray },
	{ "n_OnVehicleDamageStatusUpdate", n_OnVehicleDamageStatusUpdate },
	{ "n_OnUnoccupiedVehicleUpdate", n_OnUnoccupiedVehicleUpdate },
	{ "n_OnPlayerSelectedMenuRow", n_OnPlayerSelectedMenuRow },
	{ "n_OnPlayerExitedMenu", n_OnPlayerExitedMenu },
	{ "n_OnPlayerInteriorChange", n_OnPlayerInteriorChange },
	{ "n_OnPlayerKeyStateChange", n_OnPlayerKeyStateChange },
	{ "n_OnRconLoginAttempt", n_OnRconLoginAttempt },
	{ "n_OnPlayerUpdate", n_OnPlayerUpdate },
	{ "n_OnPlayerStreamIn", n_OnPlayerStreamIn },
	{ "n_OnPlayerStreamOut", n_OnPlayerStreamOut },
	{ "n_OnVehicleStreamIn", n_OnVehicleStreamIn },
	{ "n_OnVehicleStreamOut", n_OnVehicleStreamOut },
	{ "n_OnDialogResponse", n_OnDialogResponse },
	{ "n_OnPlayerTakeDamage", n_OnPlayerTakeDamage },
	{ "n_OnPlayerGiveDamage", n_OnPlayerGiveDamage },
	{ "n_OnPlayerClickMap", n_OnPlayerClickMap },
	{ "n_OnPlayerClickTextDraw", n_OnPlayerClickTextDraw },
	{ "n_OnPlayerClickPlayerTextDraw", n_OnPlayerClickPlayerTextDraw },
	{ "n_OnPlayerClickPlayer", n_OnPlayerClickPlayer },
	{ "n_OnPlayerEditObject", n_OnPlayerEditObject },
	{ "n_OnPlayerEditAttachedObject", n_OnPlayerEditAttachedObject },
	{ "n_OnPlayerSelectObject", n_OnPlayerSelectObject },
	{ "n_OnPlayerWeaponShot", n_OnPlayerWeaponShot },
	{ "n_OnIncomingConnection", n_OnIncomingConnection },
	{ 0, 0 }
};