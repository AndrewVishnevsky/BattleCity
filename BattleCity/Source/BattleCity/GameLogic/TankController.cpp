// Fill out your copyright notice in the Description page of Project Settings.


#include "TankController.h"
#include "Tank.h"


void ATankController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetContolledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possesing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possesing: %s"), *(ControlledTank->GetName()));
	}

}

void ATankController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank * ATankController::GetContolledTank() const
{
	return Cast<ATank>(GetPawn());
}


void ATankController::AimTowardsCrosshair()
{
	if (!GetContolledTank()) { return; }
	// Get world location if linetrace through crosshair
	//if it hits the landscape
		//Tell controlled tank to aim at this point
}

