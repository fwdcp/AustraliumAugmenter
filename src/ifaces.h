/**
 *  ifaces.h
 *  AustraliumAugmenter project
 *
 *  Copyright (c) 2015 Forward Command Post
 *  MIT License
 *  http://opensource.org/licenses/MIT
 *
 */

#pragma once

#include "interface.h"

class CSteamAPIContext;

class Interfaces {
	public:
		static void Load(CreateInterfaceFn interfaceFactory, CreateInterfaceFn gameServerFactory);
		static void Unload();

		static CSteamAPIContext *pSteamAPIContext;

		static bool steamLibrariesAvailable;
};
