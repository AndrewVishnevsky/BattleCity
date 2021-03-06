// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLECITY_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:
	ATank * GetContolledTank() const;
	
	virtual void BeginPlay() override;

private:
	ATank * GetPlayerTank() const;
	virtual void Tick(float DeltaTime) override;
	
};
