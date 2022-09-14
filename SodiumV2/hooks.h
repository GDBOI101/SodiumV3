#pragma once
#include <Windows.h>
#include <string>
#include <iostream>
#include <fstream>
#include <ostream>
#include <regex>
#include <locale>
#include <sstream>
#include <codecvt>
#include "CHook.h"
#include "URL.hpp"
#include "Finder.h"
bool GiveItemDB = false;
float FNVersion = 0.0f;
bool Restarted = false;
bool IsNewest = false;
bool MatchStarted = false;
#pragma comment(lib,"minhook.lib")
#include "MinHook.h"
#define S13
#define Hybrid
bool InitDone = false;
#define GObjects_G "49 63 C8 48 8D 14 40 48 8B 05 ? ? ? ? 48 8B 0C C8 48 8D 04 D1" //10
#define Free_G "48 85 C9 74 2E 53"
#define FNTS_C2 "48 89 5C 24 ?? 55 56 57 48 8B EC 48 83 EC 30 8B 01 48 8B F1 44 8B 49 04 8B F8"

#define CurlSetEasy_Latest "89 54 24 10 4C 89 44 24 18 4C 89 4C 24 20 48 83 EC 28 48 85 C9 75 08 8D 41 2B 48 83 C4 28 C3 4C"
#define CurlSetEasy "89 54 24 10 4C 89 44 24 18 4C 89 4C 24 20 48 83 EC 28 48 85 C9"
#define CurlSet "48 89 5C 24 08 48 89 6C 24 10 48 89 74 24 18 57 48 83 EC 30 33 ED 49 8B F0 48 8B D9"
#define LatestCheck "48 8B 05 ? ? ? ? 48 8B 0C C8 48 8B 04 D1"
#define RequestExitWithStatus_Latest "48 8B C4 48 89 58 18 88 50 10 88 48 08 57 48 83 EC 30"
#define RequestExitWithStatus "48 89 5C 24 ? 57 48 83 EC 40 41 B9 ? ? ? ? 0F B6 F9 44 38 0D ? ? ? ? 0F B6 DA 72 24 89 5C 24 30 48 8D 05 ? ? ? ? 89 7C 24 28 4C 8D 05 ? ? ? ? 33 D2 48 89 44 24 ? 33 C9 E8 ? ? ? ?"

#define DetoursEasy(address, hook) \
	DetourTransactionBegin(); \
    DetourUpdateThread(GetCurrentThread()); \
    DetourAttach(reinterpret_cast<void**>(&address), hook); \
    DetourTransactionCommit();

void RequestExitWithStatusHook(bool Force, uint8_t ReturnCode)
{
	printf("\nRequest Exit Bypassed!\n");
}

typedef enum
{
	CURLE_OK = 0,
	CURLE_UNSUPPORTED_PROTOCOL,
	/* 1 */
	CURLE_FAILED_INIT,
	/* 2 */
	CURLE_URL_MALFORMAT,
	/* 3 */
	CURLE_NOT_BUILT_IN,
	/* 4 - [was obsoleted in August 2007 for
									   7.17.0, reused in April 2011 for 7.21.5] */
									   CURLE_COULDNT_RESOLVE_PROXY,
									   /* 5 */
									   CURLE_COULDNT_RESOLVE_HOST,
									   /* 6 */
									   CURLE_COULDNT_CONNECT,
									   /* 7 */
									   CURLE_WEIRD_SERVER_REPLY,
									   /* 8 */
									   CURLE_REMOTE_ACCESS_DENIED,
									   /* 9 a service was denied by the server
																		  due to lack of access - when login fails
																		  this is not returned. */
																		  CURLE_FTP_ACCEPT_FAILED,
																		  /* 10 - [was obsoleted in April 2006 for
																											 7.15.4, reused in Dec 2011 for 7.24.0]*/
																											 CURLE_FTP_WEIRD_PASS_REPLY,
																											 /* 11 */
																											 CURLE_FTP_ACCEPT_TIMEOUT,
																											 /* 12 - timeout occurred accepting server
																																				[was obsoleted in August 2007 for 7.17.0,
																																				reused in Dec 2011 for 7.24.0]*/
																																				CURLE_FTP_WEIRD_PASV_REPLY,
																																				/* 13 */
																																				CURLE_FTP_WEIRD_227_FORMAT,
																																				/* 14 */
																																				CURLE_FTP_CANT_GET_HOST,
																																				/* 15 */
																																				CURLE_HTTP2,
																																				/* 16 - A problem in the http2 framing layer.
																																												   [was obsoleted in August 2007 for 7.17.0,
																																												   reused in July 2014 for 7.38.0] */
																																												   CURLE_FTP_COULDNT_SET_TYPE,
																																												   /* 17 */
																																												   CURLE_PARTIAL_FILE,
																																												   /* 18 */
																																												   CURLE_FTP_COULDNT_RETR_FILE,
																																												   /* 19 */
																																												   CURLE_OBSOLETE20,
																																												   /* 20 - NOT USED */
																																												   CURLE_QUOTE_ERROR,
																																												   /* 21 - quote command failure */
																																												   CURLE_HTTP_RETURNED_ERROR,
																																												   /* 22 */
																																												   CURLE_WRITE_ERROR,
																																												   /* 23 */
																																												   CURLE_OBSOLETE24,
																																												   /* 24 - NOT USED */
																																												   CURLE_UPLOAD_FAILED,
																																												   /* 25 - failed upload "command" */
																																												   CURLE_READ_ERROR,
																																												   /* 26 - couldn't open/read from file */
																																												   CURLE_OUT_OF_MEMORY,
																																												   /* 27 */
																																												   /* Note: CURLE_OUT_OF_MEMORY may sometimes indicate a conversion error
																																															instead of a memory allocation error if CURL_DOES_CONVERSIONS
																																															is defined
																																												   */
																																												   CURLE_OPERATION_TIMEDOUT,
																																												   /* 28 - the timeout time was reached */
																																												   CURLE_OBSOLETE29,
																																												   /* 29 - NOT USED */
																																												   CURLE_FTP_PORT_FAILED,
																																												   /* 30 - FTP PORT operation failed */
																																												   CURLE_FTP_COULDNT_USE_REST,
																																												   /* 31 - the REST command failed */
																																												   CURLE_OBSOLETE32,
																																												   /* 32 - NOT USED */
																																												   CURLE_RANGE_ERROR,
																																												   /* 33 - RANGE "command" didn't work */
																																												   CURLE_HTTP_POST_ERROR,
																																												   /* 34 */
																																												   CURLE_SSL_CONNECT_ERROR,
																																												   /* 35 - wrong when connecting with SSL */
																																												   CURLE_BAD_DOWNLOAD_RESUME,
																																												   /* 36 - couldn't resume download */
																																												   CURLE_FILE_COULDNT_READ_FILE,
																																												   /* 37 */
																																												   CURLE_LDAP_CANNOT_BIND,
																																												   /* 38 */
																																												   CURLE_LDAP_SEARCH_FAILED,
																																												   /* 39 */
																																												   CURLE_OBSOLETE40,
																																												   /* 40 - NOT USED */
																																												   CURLE_FUNCTION_NOT_FOUND,
																																												   /* 41 - NOT USED starting with 7.53.0 */
																																												   CURLE_ABORTED_BY_CALLBACK,
																																												   /* 42 */
																																												   CURLE_BAD_FUNCTION_ARGUMENT,
																																												   /* 43 */
																																												   CURLE_OBSOLETE44,
																																												   /* 44 - NOT USED */
																																												   CURLE_INTERFACE_FAILED,
																																												   /* 45 - CURLOPT_INTERFACE failed */
																																												   CURLE_OBSOLETE46,
																																												   /* 46 - NOT USED */
																																												   CURLE_TOO_MANY_REDIRECTS,
																																												   /* 47 - catch endless re-direct loops */
																																												   CURLE_UNKNOWN_OPTION,
																																												   /* 48 - User specified an unknown option */
																																												   CURLE_TELNET_OPTION_SYNTAX,
																																												   /* 49 - Malformed telnet option */
																																												   CURLE_OBSOLETE50,
																																												   /* 50 - NOT USED */
																																												   CURLE_PEER_FAILED_VERIFICATION,
																																												   /* 51 - peer's certificate or fingerprint
																																																					   wasn't verified fine */
																																																					   CURLE_GOT_NOTHING,
																																																					   /* 52 - when this is a specific error */
																																																					   CURLE_SSL_ENGINE_NOTFOUND,
																																																					   /* 53 - SSL crypto engine not found */
																																																					   CURLE_SSL_ENGINE_SETFAILED,
																																																					   /* 54 - can not set SSL crypto engine as
																																																														  default */
																																																														  CURLE_SEND_ERROR,
																																																														  /* 55 - failed sending network data */
																																																														  CURLE_RECV_ERROR,
																																																														  /* 56 - failure in receiving network data */
																																																														  CURLE_OBSOLETE57,
																																																														  /* 57 - NOT IN USE */
																																																														  CURLE_SSL_CERTPROBLEM,
																																																														  /* 58 - problem with the local certificate */
																																																														  CURLE_SSL_CIPHER,
																																																														  /* 59 - couldn't use specified cipher */
																																																														  CURLE_SSL_CACERT,
																																																														  /* 60 - problem with the CA cert (path?) */
																																																														  CURLE_BAD_CONTENT_ENCODING,
																																																														  /* 61 - Unrecognized/bad encoding */
																																																														  CURLE_LDAP_INVALID_URL,
																																																														  /* 62 - Invalid LDAP URL */
																																																														  CURLE_FILESIZE_EXCEEDED,
																																																														  /* 63 - Maximum file size exceeded */
																																																														  CURLE_USE_SSL_FAILED,
																																																														  /* 64 - Requested FTP SSL level failed */
																																																														  CURLE_SEND_FAIL_REWIND,
																																																														  /* 65 - Sending the data requires a rewind
																																																																							 that failed */
																																																																							 CURLE_SSL_ENGINE_INITFAILED,
																																																																							 /* 66 - failed to initialise ENGINE */
																																																																							 CURLE_LOGIN_DENIED,
																																																																							 /* 67 - user, password or similar was not
																																																																																accepted and we failed to login */
																																																																																CURLE_TFTP_NOTFOUND,
																																																																																/* 68 - file not found on server */
																																																																																CURLE_TFTP_PERM,
																																																																																/* 69 - permission problem on server */
																																																																																CURLE_REMOTE_DISK_FULL,
																																																																																/* 70 - out of disk space on server */
																																																																																CURLE_TFTP_ILLEGAL,
																																																																																/* 71 - Illegal TFTP operation */
																																																																																CURLE_TFTP_UNKNOWNID,
																																																																																/* 72 - Unknown transfer ID */
																																																																																CURLE_REMOTE_FILE_EXISTS,
																																																																																/* 73 - File already exists */
																																																																																CURLE_TFTP_NOSUCHUSER,
																																																																																/* 74 - No such user */
																																																																																CURLE_CONV_FAILED,
																																																																																/* 75 - conversion failed */
																																																																																CURLE_CONV_REQD,
																																																																																/* 76 - caller must register conversion
																																																																																								   callbacks using curl_easy_setopt options
																																																																																								   CURLOPT_CONV_FROM_NETWORK_FUNCTION,
																																																																																								   CURLOPT_CONV_TO_NETWORK_FUNCTION, and
																																																																																								   CURLOPT_CONV_FROM_UTF8_FUNCTION */
																																																																																								   CURLE_SSL_CACERT_BADFILE,
																																																																																								   /* 77 - could not load CACERT file, missing
																																																																																																	  or wrong format */
																																																																																																	  CURLE_REMOTE_FILE_NOT_FOUND,
																																																																																																	  /* 78 - remote file not found */
																																																																																																	  CURLE_SSH,
																																																																																																	  /* 79 - error from the SSH layer, somewhat
																																																																																																										 generic so the error message will be of
																																																																																																										 interest when this has happened */

																																																																																																										 CURLE_SSL_SHUTDOWN_FAILED,
																																																																																																										 /* 80 - Failed to shut down the SSL
																																																																																																																			connection */
																																																																																																																			CURLE_AGAIN,
																																																																																																																			/* 81 - socket is not ready for send/recv,
																																																																																																																											   wait till it's ready and try again (Added
																																																																																																																											   in 7.18.2) */
																																																																																																																											   CURLE_SSL_CRL_BADFILE,
																																																																																																																											   /* 82 - could not load CRL file, missing or
																																																																																																																																				  wrong format (Added in 7.19.0) */
																																																																																																																																				  CURLE_SSL_ISSUER_ERROR,
																																																																																																																																				  /* 83 - Issuer check failed.  (Added in
																																																																																																																																													 7.19.0) */
																																																																																																																																													 CURLE_FTP_PRET_FAILED,
																																																																																																																																													 /* 84 - a PRET command failed */
																																																																																																																																													 CURLE_RTSP_CSEQ_ERROR,
																																																																																																																																													 /* 85 - mismatch of RTSP CSeq numbers */
																																																																																																																																													 CURLE_RTSP_SESSION_ERROR,
																																																																																																																																													 /* 86 - mismatch of RTSP Session Ids */
																																																																																																																																													 CURLE_FTP_BAD_FILE_LIST,
																																																																																																																																													 /* 87 - unable to parse FTP file list */
																																																																																																																																													 CURLE_CHUNK_FAILED,
																																																																																																																																													 /* 88 - chunk callback reported error */
																																																																																																																																													 CURLE_NO_CONNECTION_AVAILABLE,
																																																																																																																																													 /* 89 - No connection available, the
																																																																																																																																																						session will be queued */
																																																																																																																																																						CURLE_SSL_PINNEDPUBKEYNOTMATCH,
																																																																																																																																																						/* 90 - specified pinned public key did not
																																																																																																																																																															match */
																																																																																																																																																															CURLE_SSL_INVALIDCERTSTATUS,
																																																																																																																																																															/* 91 - invalid certificate status */
																																																																																																																																																															CURLE_HTTP2_STREAM,
																																																																																																																																																															/* 92 - stream error in HTTP/2 framing layer
																																																																																																																																																																							   */
																																																																																																																																																																							   CURL_LAST /* never use! */
} CURLcode;

LPVOID LP_CSO;
LPVOID LP_CESO;

auto Yeet = new CHook();

LONG(*CSO)(LPVOID, INT, va_list) = nullptr;

LONG CSOVA(LPVOID lpContext, INT iOption, ...) {
	va_list arg;
	LONG result;

	va_start(arg, iOption);

	result = CSO(lpContext, iOption, arg);

	va_end(arg);

	return result;
}

void replace(std::string& str, const std::string& from, const std::string& to) {
	size_t start_pos = str.find(from);
	if (start_pos == std::string::npos)
		return;
	str.replace(start_pos, from.length(), to);
}
void* (__fastcall* GetObjectName)(FString*, void*);


void UpdateInventory()
{
	UObject* FortInventory = reinterpret_cast<Pointer*>((uintptr_t)GPC + __int64(ObjectFinder::FindOffset("Class /Script/FortniteGame.FortPlayerController", "WorldInventory", true)))->Value;

	static auto HandleWorldInventoryLocalUpdate = FindObject(("Function /Script/FortniteGame.FortPlayerController.HandleWorldInventoryLocalUpdate"));
	static auto HandleInventoryLocalUpdate = FindObject(("Function /Script/FortniteGame.FortInventory.HandleInventoryLocalUpdate"));
	static auto ClientForceUpdateQuickbar = FindObject(("Function /Script/FortniteGame.FortPlayerController.ClientForceUpdateQuickbar"));

	ProcessEventOG(FortInventory, HandleInventoryLocalUpdate, nullptr);
	ProcessEventOG(GPC, HandleWorldInventoryLocalUpdate, nullptr);

	auto PrimaryQuickbar = EFortQuickBars::Primary;
	auto SecondaryQuickbar = EFortQuickBars::Secondary;
	ProcessEventOG(GPC, ClientForceUpdateQuickbar, &PrimaryQuickbar);
	ProcessEventOG(GPC, ClientForceUpdateQuickbar, &SecondaryQuickbar);
}

UObject* CreateTemporaryItemInstanceBP(UObject* ItemDefinition, int Count, int Level)
{
	static UObject* CreateTemporaryItemInstanceBP = FindObject(("Function /Script/FortniteGame.FortItemDefinition.CreateTemporaryItemInstanceBP"));

	struct
	{
		int Count;
		int Level;
		UObject* ReturnValue;
	} Params;

	Params.Count = Count;
	Params.Level = Level;

	ProcessEventOG(ItemDefinition, CreateTemporaryItemInstanceBP, &Params);

	return Params.ReturnValue;
}

void SetOwningControllerForTemporaryItem(UObject* Item, UObject* Controller)
{
	static UObject* SetOwningControllerForTemporaryItem = FindObject(("Function /Script/FortniteGame.FortItem.SetOwningControllerForTemporaryItem"));
	ProcessEventOG(Item, SetOwningControllerForTemporaryItem, &Controller);
}

UObject* CreateItem(UObject* ItemDefinition, int Count)
{
	UObject* TemporaryItemInstance = CreateTemporaryItemInstanceBP(ItemDefinition, Count, 1);

	SetOwningControllerForTemporaryItem(TemporaryItemInstance, GPC);

	int* CurrentCount = reinterpret_cast<int*>(__int64(TemporaryItemInstance) + static_cast<__int64>(ObjectFinder::FindOffset("Class /Script/FortniteGame.FortWorldItem", "ItemEntry", true)) + static_cast<__int64>(ObjectFinder::FindOffset("ScriptStruct /Script/FortniteGame.FortItemEntry", "Count", true)));
	*CurrentCount = Count;

	return TemporaryItemInstance;
}

void AddItemToInventory(UObject* ItemDef, int Count, bool bAddToQuickBars = false, EFortQuickBars QuickBarType = EFortQuickBars::Max_None, int32_t slot = 0)
{
	GPC = GFPC(*GWorldPtr);
	UObject* FortInventory = reinterpret_cast<Pointer*>(__int64(GPC) + __int64(ObjectFinder::FindOffset("Class /Script/FortniteGame.FortPlayerController", "WorldInventory", true)))->Value;

	if (ItemDef)
	{
		UObject* ItemInstance = CreateItem(ItemDef, Count);
		auto ItemEntry = reinterpret_cast<FFortItemEntry*>(__int64(ItemInstance) + __int64(ObjectFinder::FindOffset("Class /Script/FortniteGame.FortWorldItem", "ItemEntry", true)));
		reinterpret_cast<TArray<FFortItemEntry>*>(__int64(FortInventory) + __int64(ObjectFinder::FindOffset("Class /Script/FortniteGame.FortInventory", "Inventory", true)) + static_cast<__int64>(ObjectFinder::FindOffset("ScriptStruct /Script/FortniteGame.FortItemList", "ReplicatedEntries", true)))->Add(*ItemEntry);
	}
	UpdateInventory();
}

namespace Pickup
{
	static void OnRep_PrimaryPickupItemEntry(UObject* FortPickup)
	{
		static UObject* OnRep_PrimaryPickupItemEntry = FindObject("Function /Script/FortniteGame.FortPickup.OnRep_PrimaryPickupItemEntry");

		ProcessEventOG(FortPickup, OnRep_PrimaryPickupItemEntry, nullptr);
	}

	static void SpawnPickupAtLocation(UObject* ItemDefinition, int Count, FVector Location)
	{
		auto FortPickupAthena = SpawnActor(*GWorldPtr, FindObject("Class /Script/FortniteGame.FortPickupAthena"), new FVector(Location), {}, {});

		auto EntryCount = reinterpret_cast<int*>(__int64(FortPickupAthena) + static_cast<__int64>(ObjectFinder::FindOffset("Class /Script/FortniteGame.FortPickup", "PrimaryPickupItemEntry")) + static_cast<__int64>(ObjectFinder::FindOffset("ScriptStruct /Script/FortniteGame.FortItemEntry", "Count")));
		auto EntryItemDefinition = reinterpret_cast<UObject**>(__int64(FortPickupAthena) + static_cast<__int64>(ObjectFinder::FindOffset("Class /Script/FortniteGame.FortPickup", "PrimaryPickupItemEntry")) + static_cast<__int64>(ObjectFinder::FindOffset("ScriptStruct /Script/FortniteGame.FortItemEntry", "ItemDefinition")));

		*EntryCount = Count;
		*EntryItemDefinition = ItemDefinition;

		OnRep_PrimaryPickupItemEntry(FortPickupAthena);
		TossPickup(FortPickupAthena, Location, GetPawn(), 6, true);
	}
}

void ToggleAuthority(ENetRole role)
{
	UObject* Pawn = GetPawn();
	GPC = GFPC(*GWorldPtr);
	auto LocalRole = reinterpret_cast<TEnumAsByte<ENetRole>*>(__int64(Pawn) + __int64(ObjectFinder::FindOffset(("Class /Script/Engine.Actor"), ("Role"), true)));

	auto RemoteRole = reinterpret_cast<TEnumAsByte<ENetRole>*>(__int64(Pawn) + __int64(ObjectFinder::FindOffset(("Class /Script/Engine.Actor"), ("RemoteRole"), true)));

	auto PCLocalRole = reinterpret_cast<TEnumAsByte<ENetRole>*>(__int64(GPC) + __int64(ObjectFinder::FindOffset(("Class /Script/Engine.Actor"), ("Role"), true)));

	auto PCRemoteRole = reinterpret_cast<TEnumAsByte<ENetRole>*>(__int64(GPC) + __int64(ObjectFinder::FindOffset(("Class /Script/Engine.Actor"), ("RemoteRole"), true)));

	*PCLocalRole = role;
	*PCRemoteRole = role;

	*LocalRole = role;
	*RemoteRole = role;
}

struct UField_New : UObject
{
	UField_New* Next;
	void* padding_01;
	void* padding_02;
};

struct UStruct_New : UField_New
{
	void* Super;
	UField_New* Children;
	uint32_t Size;
	char pad[0x44];
};

struct UStruct_New2 : UField_New
{
	//Neonite
	UStruct_New2* SuperStruct;
	UField_New* Children;
	FField* ChildProperties;
	int32_t Size;
	int32_t MinAlignment;
	TArray<uint8_t> Script;
	FProperty* PropertyLink;
	FProperty* RefLink;
	FProperty* DestructorLink;
	FProperty* PostConstructLink;
};

int32_t GetSize(UObject* Struct) {
	UStruct_New2* TStruct = reinterpret_cast<UStruct_New2*>(Struct);
	return TStruct->Size;
}

std::string Num2Hex(int Num) {
	std::stringstream ss;
	ss << std::hex << Num; // int decimal_value
	std::string res(ss.str());
	return res;
}

void* PEHook(void* Object, void* Func, void* Params) {
	FString* ObjName = new FString();
	GetObjectName(ObjName, Object);
	FString* FuncName2 = new FString();
	GetObjectName(FuncName2, Func);
	std::string FuncName = FuncName2->ToString();
	if (FuncName.find("ReadyToStartMatch") != std::string::npos) {
		MatchStarted = true;
		GPC = GFPC(*GWorldPtr);
		StaticConstructObjectInternal = decltype(StaticConstructObjectInternal)(FindPattern("4C 89 44 24 18 55 53 56 57 41 54 41 55 41 56 41 57 48 8D AC 24 ? ? ? ? 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4"));
		//Cheat Manager
		UObject* CheatManager = StaticConstructObjectInternal(FindObject("Class /Script/Engine.CheatManager"), GPC, 0, 0, 0, 0, 0, 0, 0);

		UObject** MCM = reinterpret_cast<UObject**>(__int64(GPC) + __int64(ObjectFinder::FindOffset("Class /Script/Engine.PlayerController", "CheatManager", true)));
		*MCM = CheatManager;

		//UE4 Console
		UObject* GVC = FindObject("FortGameViewportClient /Engine/Transient.FortEngine");
		UObject* Console = StaticConstructObjectInternal(FindObject("Class /Script/Engine.Console"), GVC, 0, 0, 0, 0, 0, 0, 0);
		*reinterpret_cast<UObject**>(__int64(GVC) + __int64(ObjectFinder::FindOffset("Class /Script/Engine.GameViewportClient", "ViewportConsole"))) = Console;
	}

	if (FuncName.find("ServerLoadingScreenDropped") != std::string::npos && MatchStarted == true) {
		MatchStarted = false;
		GPC = GFPC(*GWorldPtr);
		UObject* Pawn = GetPawn();
		auto Hero = FindObject(("FortHero /Engine/Transient.FortHero"));
		auto CharacterParts = *reinterpret_cast<TArray<UObject*>*>(__int64(Hero) + __int64(ObjectFinder::FindOffset("Class /Script/FortniteGame.FortHero", "CharacterParts")));
		auto AD_Offset = ObjectFinder::FindOffset("Class /Script/FortniteGame.CustomCharacterPart", "AdditionalData",true);
		for (int i = 0; i < CharacterParts.Num(); i++) {
			UObject* AD = *reinterpret_cast<UObject**>(__int64(CharacterParts[i]) + __int64(AD_Offset));
			if (AD->IsA(FindObject("Class /Script/FortniteGame.CustomCharacterHeadData"))) {
				struct
				{
					TEnumAsByte<EFortCustomPartType> Type;
					UObject* ChosenCharacterPart;
				} Params;

				Params.Type = EFortCustomPartType::Head;
				Params.ChosenCharacterPart = CharacterParts[i];
				ProcessEventOG(Pawn, FindObject("Function /Script/FortniteGame.FortPlayerPawn.ServerChoosePart"), &Params);
			}
			if (AD->IsA(FindObject("Class /Script/FortniteGame.CustomCharacterBodyPartData"))) {
				struct
				{
					TEnumAsByte<EFortCustomPartType> Type;
					UObject* ChosenCharacterPart;
				} Params;

				Params.Type = EFortCustomPartType::Body;
				Params.ChosenCharacterPart = CharacterParts[i];
				ProcessEventOG(Pawn, FindObject("Function /Script/FortniteGame.FortPlayerPawn.ServerChoosePart"), &Params);
			}
			if (AD->IsA(FindObject("Class /Script/FortniteGame.CustomCharacterHatData"))) {
				struct
				{
					TEnumAsByte<EFortCustomPartType> Type;
					UObject* ChosenCharacterPart;
				} Params;

				Params.Type = EFortCustomPartType::Hat;
				Params.ChosenCharacterPart = CharacterParts[i];
				ProcessEventOG(Pawn, FindObject("Function /Script/FortniteGame.FortPlayerPawn.ServerChoosePart"), &Params);
			}
			if (AD->IsA(FindObject("Class /Script/FortniteGame.CustomCharacterBackpackData"))) {
				struct
				{
					TEnumAsByte<EFortCustomPartType> Type;
					UObject* ChosenCharacterPart;
				} Params;

				Params.Type = EFortCustomPartType::Backpack;
				Params.ChosenCharacterPart = CharacterParts[i];
				ProcessEventOG(Pawn, FindObject("Function /Script/FortniteGame.FortPlayerPawn.ServerChoosePart"), &Params);
			}
		}
	}

	//Pretty much NPP CheatScript
	if (FuncName.find("CheatScript") != std::string::npos) {
		struct CSParams
		{
			FString Command;
		};

		FString Command = reinterpret_cast<CSParams*>(Params)->Command;

		if (Command.IsValid()) {
			std::string Arg;
			std::string CommandS = Command.ToString();
			if (CommandS.find(" ") != std::string::npos) {
				Arg = CommandS.substr(CommandS.find(" ") + 1);
			}

			//Crashes iirc
			if (CommandS.find("equipitem") != std::string::npos) {
				UObject* Item = FindObject(Arg);
				AddItemToInventory(Item, 1);
			}

			if (CommandS.find("showskin") != std::string::npos) {
				GPC = GFPC(*GWorldPtr);
				UObject* Pawn = GetPawn();
				auto Hero = FindObject(("FortHero /Engine/Transient.FortHero"));
				auto CharacterParts = *reinterpret_cast<TArray<UObject*>*>(__int64(Hero) + __int64(ObjectFinder::FindOffset("Class /Script/FortniteGame.FortHero", "CharacterParts")));
				auto AD_Offset = ObjectFinder::FindOffset("Class /Script/FortniteGame.CustomCharacterPart", "AdditionalData", true);
				for (int i = 0; i < CharacterParts.Num(); i++) {
					UObject* AD = *reinterpret_cast<UObject**>(__int64(CharacterParts[i]) + __int64(AD_Offset));
					if (AD->IsA(FindObject("Class /Script/FortniteGame.CustomCharacterHeadData"))) {
						struct
						{
							TEnumAsByte<EFortCustomPartType> Type;
							UObject* ChosenCharacterPart;
						} Params;

						Params.Type = EFortCustomPartType::Head;
						Params.ChosenCharacterPart = CharacterParts[i];
						ProcessEventOG(Pawn, FindObject("Function /Script/FortniteGame.FortPlayerPawn.ServerChoosePart"), &Params);
					}
					if (AD->IsA(FindObject("Class /Script/FortniteGame.CustomCharacterBodyPartData"))) {
						struct
						{
							TEnumAsByte<EFortCustomPartType> Type;
							UObject* ChosenCharacterPart;
						} Params;

						Params.Type = EFortCustomPartType::Body;
						Params.ChosenCharacterPart = CharacterParts[i];
						ProcessEventOG(Pawn, FindObject("Function /Script/FortniteGame.FortPlayerPawn.ServerChoosePart"), &Params);
					}
					if (AD->IsA(FindObject("Class /Script/FortniteGame.CustomCharacterHatData"))) {
						struct
						{
							TEnumAsByte<EFortCustomPartType> Type;
							UObject* ChosenCharacterPart;
						} Params;

						Params.Type = EFortCustomPartType::Hat;
						Params.ChosenCharacterPart = CharacterParts[i];
						ProcessEventOG(Pawn, FindObject("Function /Script/FortniteGame.FortPlayerPawn.ServerChoosePart"), &Params);
					}
					if (AD->IsA(FindObject("Class /Script/FortniteGame.CustomCharacterBackpackData"))) {
						struct
						{
							TEnumAsByte<EFortCustomPartType> Type;
							UObject* ChosenCharacterPart;
						} Params;

						Params.Type = EFortCustomPartType::Backpack;
						Params.ChosenCharacterPart = CharacterParts[i];
						ProcessEventOG(Pawn, FindObject("Function /Script/FortniteGame.FortPlayerPawn.ServerChoosePart"), &Params);
					}
				}
			}

			//Old Messy Pasted code
			if (CommandS.find("spawnitem") != std::string::npos) {
				FVector* Loc = new FVector(GetLocation(GetPawn()));
				UObject* FortPickup = SpawnActor(*GWorldPtr, FindObject("Class /Script/FortniteGame.FortPickupAthena"), Loc, {}, {});
				auto entry = reinterpret_cast<FFortItemEntry*>((uintptr_t)FortPickup + __int64(ObjectFinder::FindOffset("Class /Script/FortniteGame.FortPickup", "PrimaryPickupItemEntry")));
				*reinterpret_cast<UObject**>((uintptr_t)entry + __int64(ObjectFinder::FindOffset("ScriptStruct /Script/FortniteGame.FortItemEntry", "ItemDefinition"))) = FindObject(Arg);
				*reinterpret_cast<int*>((uintptr_t)entry + __int64(ObjectFinder::FindOffset("ScriptStruct /Script/FortniteGame.FortItemEntry", "Count"))) = 1;
				auto Fn = FindObject(("Function /Script/FortniteGame.FortPickup.TossPickup"));
				auto Fn2 = FindObject(("Function /Script/FortniteGame.FortPickup.OnRep_PrimaryPickupItemEntry"));

				enum class EFortPickupSourceTypeFlag : uint8_t
				{
					Other = 0,
					Player = 1,
					Destruction = 2,
					Container = 3,
					AI = 4,
					Tossed = 5,
					FloorLoot = 6,
					Fishing = 7,
					EFortPickupSourceTypeFlag_MAX = 8
				};

				enum class EFortPickupSpawnSource : uint8_t
				{
					Unset = 0,
					PlayerElimination = 1,
					Chest = 2,
					SupplyDrop = 3,
					AmmoBox = 4,
					Drone = 5,
					ItemSpawner = 6,
					BotElimination = 7,
					NPCElimination = 8,
					EFortPickupSpawnSource_MAX = 9,
				};

				struct
				{
					FVector FinalLocation;
					UObject* Pawn;
					int32_t OverrideMaxStackCount;
					bool bToss;
					bool bShouldCombinePickupsWhenTossCompletes;
					EFortPickupSourceTypeFlag InPickupSourceTypeFlags;
					EFortPickupSpawnSource InPickupSpawnSource;
				}params;

				params.FinalLocation = *Loc;
				params.bToss = true;
				params.bShouldCombinePickupsWhenTossCompletes = true;
				params.Pawn = GetPawn();
				params.OverrideMaxStackCount = 6;
				params.InPickupSourceTypeFlags = EFortPickupSourceTypeFlag::Other;
				params.InPickupSpawnSource = EFortPickupSpawnSource::Unset;

				ProcessEventOG(FortPickup, Fn2, nullptr);
				ProcessEventOG(FortPickup, Fn, &params);
				MessageBoxA(0, "Spawned with SV3 by GD#2022", "SV3", MB_OK);
			}

			//Object Spawning (Scuffed + Client Sided)
			if (CommandS.find("spawnobject") != std::string::npos) {
				FVector* Loc = new FVector(GetLocation(GetPawn()));
				Loc->X += 100;
				UObject* BPGC = FindObject("Class /Script/Engine.BlueprintGeneratedClass");
				std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
				std::wstring wide = converter.from_bytes(Arg);
				StaticLoadObject(BPGC, nullptr, wide.c_str(), nullptr, 0, 0, 0, 0); //Load Object into Memory
				UObject* Object = FindObject(Arg, false, true);
				SpawnActor(*GWorldPtr, Object, Loc, {}, {}); //Spawn the Actor
				MessageBoxA(0, "Spawned with SV3 by GD#2022", "SV3", MB_OK);
			}
		}
	}

	//UAC Bypass (Credits to FortniteTools: https://github.com/ItsKaitlyn03/FortniteTools/blob/master/FortniteTools/core.h#L123)
	if (FuncName.find("SendClientHello") != std::string::npos || FuncName.find("SendPacketToServer") != std::string::npos || FuncName.find("SendPacketToClient") != std::string::npos) {
		return NULL;
	}
	return ProcessEventOG(Object, Func, Params);
}

struct curl_slist
{
	char* data;
	struct curl_slist* next;
};

LONG CESO(LPVOID Context, INT Tag, ...) {
	va_list a, c;
	LONG res;
	if (Context == nullptr) {
		return 43;
	}

	va_start(a, Tag);

	if (Tag == 10002) {
		va_copy(c, a);
		std::string url(va_arg(c, char*));
#ifdef S13
		if (url.find("ClientQuest") != std::string::npos && InitDone == false) {
			InitDone = true;
			GFPC = decltype(GFPC)(FindPattern("83 B9 ? ? ? ? ? 7E ? 48 8B 89 ? ? ? ? E9"));
			GObjs = reinterpret_cast<GObjects*>(FindPattern(GObjects_G, true, 10));
			FNameToString = decltype(FNameToString)(FindPattern(FNTS_C2));
			FnFree = decltype(FnFree)(FindPattern(Free_G));
			StaticLoadObject = decltype(StaticLoadObject)(FindPattern("4C 89 4C 24 ? 48 89 54 24 ? 48 89 4C 24 ? 55 53 56 57 41 54 41 55 41 56 41 57 48 8B EC"));
			GetObjectName = decltype(GetObjectName)(FindPattern("40 53 48 83 EC 20 48 8B D9 48 85 D2 75 45 33 C0 48 89 01 48 89 41 08 8D 50 05 E8 ? ? ? ? 8B 53 08 8D 42 05 89 43 08 3B 43 0C 7E 08 48 8B CB E8 ? ? ? ? 48 8B 0B 48 8D 15 ? ? ? ? 41 B8 ? ? ? ? E8 ? ? ? ? 48 8B C3 48 83 C4 20 5B C3 48 8B 42 18"));
			auto PEAddr = (void*)FindPattern("40 55 56 57 41 54 41 55 41 56 41 57 48 81 EC ? ? ? ? 48 8D 6C 24 ? 48 89 9D ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C5 48 89 85 ? ? ? ? 8B 41 0C 45 33 F6 3B 05 ? ? ? ? 4D 8B F8 48 8B F2 4C 8B E1 41 B8 ? ? ? ? 7D 2A");
			uintptr_t GWorldAddr = FindPattern("48 89 05 ? ? ? ? 48 8B B6 ? ? ? ?", true, 3);
			if (GWorldAddr == 0) {
				GWorldAddr = FindPattern("48 8B 1D ? ? ? ? 48 85 DB 74 3B 41", true, 3);
			}
			GWorldPtr = reinterpret_cast<UObject**>(GWorldAddr);
			uintptr_t SAAddr = FindPattern("53 56 57 48 83 EC 70 48 8B 05 ? ? ? ? 48 33 C4 48 89 44 24 60 0F 28 1D ? ? ? ? 0F 57 D2 48 8B B4 24 B0");
			SpawnActor = decltype(SpawnActor)(SAAddr);
			MH_CreateHook((LPVOID)PEAddr, PEHook, (LPVOID*)&ProcessEventOG);
			MH_EnableHook((LPVOID)PEAddr);

			Url redirect(url);
			std::cout << url << "\n";
			redirect.scheme("http");
			redirect.host("createfn.herokuapp.com");
			redirect.port("80");
			url = redirect.str();

			va_end(c);
		}
#endif
#ifdef Hybrid
		if (url.find("platform=Windows") != std::string::npos) {
			replace(url, "platform=Windows", "platform=IOS");
		}

		if (url.find("cloudstorage") != std::string::npos || url.find("versioncheck") != std::string::npos || url.find("socialban") != std::string::npos || url.find("fortnite-game") != std::string::npos || url.find("/client/") != std::string::npos) {
			Url redirect(url);
			std::cout << url << "\n";
			redirect.scheme("http");
			redirect.host("createfn.herokuapp.com");
			redirect.port("80");
			url = redirect.str();

			va_end(c);
		}
#else
		if (url.find("oauth/token") != std::string::npos && FNVersion >= 4.0f && FNVersion < 5.0f && IsNewest == false && Restarted == false) {
			Restarted = true;
			auto CurlEasyAdd = FindPattern(CurlSetEasy);

			auto CurlSetAdd = FindPattern(CurlSet);

			CSO = decltype(CSO)(CurlSetAdd);

			Yeet->Unhook();
			MH_CreateHook((LPVOID)CurlEasyAdd, CESO, nullptr);
			MH_EnableHook((LPVOID)CurlEasyAdd);
		}

		if (url.find("epicgames.com") != std::string::npos) {
			Url redirect(url);
			std::cout << url << "\n";
			redirect.scheme("http");
			redirect.host("127.0.0.1");
			redirect.port("5595");
			url = redirect.str();

			va_end(c);
		}
#endif // DEBUG
		res = CSOVA(Context, Tag, url.c_str());
	}
	else if (Tag == 10064) {
		res = CSOVA(Context, Tag, 0);
	}
	else if (Tag == 10081) {
		res = CSOVA(Context, Tag, 0);
	}
	else if (Tag == 10117) {
		res = CSOVA(Context, Tag, "");
	}
	else if (Tag == 10230) {
		return CURLcode::CURLE_OK;
	}
	else
	{
		res = CSO(Context, Tag, a);
	}
	if (Tag == 10023 && FNVersion == 0.0f)
	{
		va_copy(c, a);
		auto list = va_arg(c, curl_slist*);;

		while (list->next != nullptr && list->data)
		{
			std::string listData = list->data;
			if (listData.starts_with(("User-Agent:")))
			{
				const auto version = listData.erase(0, listData.find_first_of("0123456789")); //find first number
				FNVersion = std::stof(version);
			}
			list = list->next;
		}
	}

	va_end(a);

	return res;
}