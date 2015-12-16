/*
 *  australiumaugmenter.cpp
 *  AustraliumAugmenter project
 *
 *  Copyright (c) 2015 Forward Command Post
 *  MIT License
 *  http://opensource.org/licenses/MIT
 *
 */

#include "australiumaugmenter.h"

#include "convar.h"

#include "common.h"
#include "ifaces.h"
#include "modules.h"

ModuleManager *g_ModuleManager = nullptr;

// The plugin is a static singleton that is exported as an interface
AustraliumAugmenterPlugin g_AustraliumAugmenterPlugin;
EXPOSE_SINGLE_INTERFACE_GLOBALVAR(AustraliumAugmenterPlugin, IServerPluginCallbacks, INTERFACEVERSION_ISERVERPLUGINCALLBACKS, g_AustraliumAugmenterPlugin);

AustraliumAugmenterPlugin::AustraliumAugmenterPlugin() {}
AustraliumAugmenterPlugin::~AustraliumAugmenterPlugin() {}

bool AustraliumAugmenterPlugin::Load(CreateInterfaceFn interfaceFactory, CreateInterfaceFn gameServerFactory) {
	PRINT_TAG();
	ConColorMsg(Color(0, 255, 255, 255), "version %s | a Forward Command Post project (http://fwdcp.net)\n", PLUGIN_VERSION);

	PRINT_TAG();
	ConColorMsg(Color(255, 255, 0, 255), "Loading plugin...\n");

	Interfaces::Load(interfaceFactory, gameServerFactory);

	g_ModuleManager = new ModuleManager();

	ConVar_Register();

	PRINT_TAG();
	ConColorMsg(Color(0, 255, 0, 255), "Finished loading!\n");

	return true;
}

void AustraliumAugmenterPlugin::Unload(void) {
	PRINT_TAG();
	ConColorMsg(Color(255, 255, 0, 255), "Unloading plugin...\n");

	g_ModuleManager->UnloadAllModules();

	ConVar_Unregister();
	Interfaces::Unload();

	PRINT_TAG();
	ConColorMsg(Color(0, 255, 0, 255), "Finished unloading!\n");
}

void AustraliumAugmenterPlugin::Pause(void) {}
void AustraliumAugmenterPlugin::UnPause(void) {}

const char *AustraliumAugmenterPlugin::GetPluginDescription(void) {
	std::stringstream ss;
	std::string desc;

	ss << "AustraliumAugmenter " << PLUGIN_VERSION;
	ss >> desc;

	return desc.c_str();
}

void AustraliumAugmenterPlugin::LevelInit(char const *pMapName) {}
void AustraliumAugmenterPlugin::ServerActivate(edict_t *pEdictList, int edictCount, int clientMax) {}
void AustraliumAugmenterPlugin::GameFrame(bool simulating) {}
void AustraliumAugmenterPlugin::LevelShutdown(void) {}
void AustraliumAugmenterPlugin::ClientActive(edict_t *pEntity) {}
void AustraliumAugmenterPlugin::ClientDisconnect(edict_t *pEntity) {}
void AustraliumAugmenterPlugin::ClientPutInServer(edict_t *pEntity, char const *playername) {}
void AustraliumAugmenterPlugin::SetCommandClient(int index) {}
void AustraliumAugmenterPlugin::ClientSettingsChanged(edict_t *pEdict) {}
PLUGIN_RESULT AustraliumAugmenterPlugin::ClientConnect(bool *bAllowConnect, edict_t *pEntity, const char *pszName, const char *pszAddress, char *reject, int maxrejectlen) { return PLUGIN_CONTINUE; }
PLUGIN_RESULT AustraliumAugmenterPlugin::ClientCommand(edict_t *pEntity, const CCommand &args) { return PLUGIN_CONTINUE; }
PLUGIN_RESULT AustraliumAugmenterPlugin::NetworkIDValidated(const char *pszUserName, const char *pszNetworkID) { return PLUGIN_CONTINUE; }
void AustraliumAugmenterPlugin::OnQueryCvarValueFinished(QueryCvarCookie_t iCookie, edict_t *pPlayerEntity, EQueryCvarValueStatus eStatus, const char *pCvarName, const char *pCvarValue) {}
void AustraliumAugmenterPlugin::OnEdictAllocated(edict_t *edict) {}
void AustraliumAugmenterPlugin::OnEdictFreed(const edict_t *edict) {}
