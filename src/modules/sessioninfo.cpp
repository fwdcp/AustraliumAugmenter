/*
 *  sessioninfo.cpp
 *  AustraliumAugmenter project
 *
 *  Copyright (c) 2015 Forward Command Post
 *  MIT License
 *  http://opensource.org/licenses/MIT
 *
 */

#include "sessioninfo.h"

#include "steam/steam_api.h"
#include "steam/isteamgamecoordinator.h"

#include "../common.h"
#include "../ifaces.h"

SessionInfo::SessionInfo() {

}

bool SessionInfo::CheckDependencies() {
	bool ready = true;

	if (!Interfaces::steamLibrariesAvailable) {
		PRINT_TAG();
		Warning("Required Steam libraries for module %s not available!\n", g_ModuleManager->GetModuleName<SessionInfo>().c_str());

		ready = false;
	}

	if (!Interfaces::pSteamGameCoordinator) {
		PRINT_TAG();
		Warning("Required Steam game coordinator interface for module %s not available!\n", g_ModuleManager->GetModuleName<SessionInfo>().c_str());

		ready = false;
	}

	return ready;
}
