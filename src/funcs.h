/*
 *  funcs.h
 *  AustraliumAugmenter project
 *
 *  Copyright (c) 2015 Forward Command Post
 *  BSD 2-Clause License
 *  http://opensource.org/licenses/BSD-2-Clause
 *
 */

#pragma once

#include "sourcehook.h"

#include "steam/isteamgamecoordinator.h"

class Funcs {
public:
	static int AddHook_ISteamGameCoordinator_SendMessage(ISteamGameCoordinator *instance, fastdelegate::FastDelegate3<uint32, const void *, uint32, EGCResults> hook, bool post);

	static bool RemoveHook(int hookID);

	static void Unload();

	static void Pause();

	static void Unpause();
};

extern SourceHook::ISourceHook *g_SHPtr;
