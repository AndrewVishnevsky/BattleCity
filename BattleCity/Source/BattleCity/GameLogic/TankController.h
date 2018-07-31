// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLECITY_API ATankController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATank * GetContolledTank() const;
	
	virtual void BeginPlay() override;
};
