/*
 *  funcs.cpp
 *  AustraliumAugmenter project
 *
 *  Copyright (c) 2015 Forward Command Post
 *  BSD 2-Clause License
 *  http://opensource.org/licenses/BSD-2-Clause
 *
 */

#include "funcs.h"

#include "sourcehook_impl.h"

#include "common.h"
#include "ifaces.h"

class AustraliumAugmenterUnloader : public SourceHook::Impl::UnloadListener
{
public:
	virtual void ReadyToUnload(SourceHook::Plugin plug);
};

void AustraliumAugmenterUnloader::ReadyToUnload(SourceHook::Plugin plug) {};

SourceHook::Impl::CSourceHookImpl g_SourceHook;
SourceHook::ISourceHook *g_SHPtr = &g_SourceHook;
int g_PLID = 0;

void Funcs::Unload() {
	g_SourceHook.UnloadPlugin(g_PLID, new AustraliumAugmenterUnloader());
}

void Funcs::Pause() {
	g_SourceHook.PausePlugin(g_PLID);
}

void Funcs::Unpause() {
	g_SourceHook.UnpausePlugin(g_PLID);
}
