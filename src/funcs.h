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

class Funcs {
public:
	static void Unload();

	static void Pause();

	static void Unpause();
};

extern SourceHook::ISourceHook *g_SHPtr;
