// Fill out your copyright notice in the Description page of Project Settings.

#pragma once



#include "Player/ShooterPlayerController.h"
#include "Net/UnrealNetwork.h"
#include "Online.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "NORAA0000PlayerController.generated.h"

#define CHECKRET(cond) if (!(cond)) { UE_LOG(LogTemp, Error, TEXT("CHECKRET(%s) Failed"), TEXT(#cond)); return; }

UCLASS(config = Game)
class NORAA0000_API ANORAA0000PlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	void PushToTalkAreaChannelPressed();
	void PushToTalkAreaChannelReleased();
	void PushToTalkTeamChannelPressed();
	void PushToTalkTeamChannelReleased();

	void PushToToggleAreaChannel();
	void PushToToggleTeamChannel();

	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	//virtual void HandleReturnToMainMenu() override;
	void ClientReturnToMainMenu_Implementation(const FString& ReturnReason) override;

	UFUNCTION(reliable, client)
		void ClientJoinVoice(const FString &GameMode, const FString &OnlineSessionId, const int32 &TeamNum = -1);

	
};
