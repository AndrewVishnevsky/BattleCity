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

bool ATankController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	OutHitLocation = FVector(1.0);
	return true;
}

ATank * ATankController::GetContolledTank() const
{
	return Cast<ATank>(GetPawn());
}


void ATankController::AimTowardsCrosshair()
{
	if (!GetContolledTank()) { return; }

	FVector HitLocation; // Out parameter
	if (GetSightRayHitLocation(HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());
		//Get world location if linetrace through crosshair
		//if it hits the landscape
			// TODO Tell controlled tank to aim at this point
	}
}

