/*
 *  sessioninfo.h
 *  AustraliumAugmenter project
 *
 *  Copyright (c) 2015 Forward Command Post
 *  MIT License
 *  http://opensource.org/licenses/MIT
 *
 */

#pragma once

#include "../modules.h"

#include "steam/isteamgamecoordinator.h"

class SessionInfo : public Module {
public:
	SessionInfo();

	static bool CheckDependencies();
private:
	EGCResults GCSendMessageOverride(uint32 unMsgType, const void *pubData, uint32 cubData);
};
