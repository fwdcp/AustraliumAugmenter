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

#include <inttypes.h>

#include "steam/steam_api.h"

#include "../common.h"
#include "../funcs.h"
#include "../ifaces.h"

SessionInfo::SessionInfo() {
	Funcs::AddHook_ISteamGameCoordinator_SendMessage(Interfaces::pSteamGameCoordinator, SH_MEMBER(this, &SessionInfo::GCSendMessageOverride), false);
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

EGCResults SessionInfo::GCSendMessageOverride(uint32 unMsgType, const void *pubData, uint32 cubData) {
	PRINT_TAG();
	Msg("Sending message %"PRIu32"\n", unMsgType & ~0x80000000);

	RETURN_META_VALUE(MRES_IGNORED, k_EGCResultOK);
}
