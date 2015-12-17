/**
 *  ifaces.cpp
 *  AustraliumAugmenter project
 *
 *  Copyright (c) 2015 Forward Command Post
 *  MIT License
 *  http://opensource.org/licenses/MIT
 *
 */

#include "ifaces.h"

#include "tier3/tier3.h"
#include "steam/steam_api.h"
#include "steam/isteamgamecoordinator.h"

#include "common.h"
#include "exceptions.h"

CSteamAPIContext *Interfaces::pSteamAPIContext = nullptr;
ISteamGameCoordinator *Interfaces::pSteamGameCoordinator = nullptr;

bool Interfaces::steamLibrariesAvailable = false;

void Interfaces::Load(CreateInterfaceFn interfaceFactory, CreateInterfaceFn gameServerFactory) {
	ConnectTier1Libraries(&interfaceFactory, 1);
	ConnectTier2Libraries(&interfaceFactory, 1);
	ConnectTier3Libraries(&interfaceFactory, 1);

	pSteamAPIContext = new CSteamAPIContext();
	steamLibrariesAvailable = SteamAPI_InitSafe() && pSteamAPIContext->Init();

	if (steamLibrariesAvailable) {
		pSteamGameCoordinator = (ISteamGameCoordinator *) SteamClient()->GetISteamGenericInterface(SteamAPI_GetHSteamUser(), SteamAPI_GetHSteamPipe(), STEAMGAMECOORDINATOR_INTERFACE_VERSION);
	}
}

void Interfaces::Unload() {
	DisconnectTier3Libraries();
	DisconnectTier2Libraries();
	DisconnectTier1Libraries();

	pSteamAPIContext->Clear();
}
