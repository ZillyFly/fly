/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */
#ifndef GAME_SERVER_GAMEMODES_MOD_H
#define GAME_SERVER_GAMEMODES_MOD_H
#include <game/server/gamecontroller.h>
#include <game/server/entity.h>

// you can subclass GAMECONTROLLER_CTF, GAMECONTROLLER_TDM etc if you want
// todo a modification with their base as well.
class CGameControllerFLY : public IGameController
{
	// balancing
	virtual bool CanBeMovedOnBalance(int ClientID) const;

	// game
	class CFlag *m_apFlags[2];

	virtual bool DoWincheckMatch();

public:
	CGameControllerFLY(class CGameContext *pGameServer);

	// event
	virtual void OnCharacterSpawn(class CCharacter *pChr);
	virtual int OnCharacterDeath(class CCharacter *pVictim, class CPlayer *pKiller, int Weapon);
	virtual void OnFlagReturn(class CFlag *pFlag);
	virtual bool OnEntity(int Index, vec2 Pos);

	// general
	virtual void Snap(int SnappingClient);
	virtual void Tick();

	void FlyTick();
};
#endif
