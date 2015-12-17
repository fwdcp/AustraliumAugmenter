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

SH_DECL_HOOK3(ISteamGameCoordinator, SendMessage, SH_NOATTRIB, 0, EGCResults, uint32, const void *, uint32);

int Funcs::AddHook_ISteamGameCoordinator_SendMessage(ISteamGameCoordinator *instance, fastdelegate::FastDelegate3<uint32, const void *, uint32, EGCResults> hook, bool post) {
	return SH_ADD_HOOK(ISteamGameCoordinator, SendMessage, instance, hook, post);
}

void Funcs::Unload() {
	g_SourceHook.UnloadPlugin(g_PLID, new AustraliumAugmenterUnloader());
}

void Funcs::Pause() {
	g_SourceHook.PausePlugin(g_PLID);
}

void Funcs::Unpause() {
	g_SourceHook.UnpausePlugin(g_PLID);
}
