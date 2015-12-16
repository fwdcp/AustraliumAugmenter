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

class SessionInfo : public Module {
public:
	SessionInfo();

	static bool CheckDependencies();
};
