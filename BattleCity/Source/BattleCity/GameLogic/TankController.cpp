// Fill out your copyright notice in the Description page of Project Settings.


#include "TankController.h"
#include "Tank.h"
#include "GameFramework/Actor.h"


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
	
	//find crosshair in pixel 
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX*CrossHairXLocation, ViewportSizeY*CrossHairYLocation);
	
	//"de-project" the screen position
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{	
		//line trace along that look direction
		GetLookVectorHitLocation(LookDirection, OutHitLocation);
	}
	return true;
}

bool ATankController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitDirection) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection*LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility))
				//Line trace succeeds))
		{
		HitResult.Location;
		return true;
		}
	return false;
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
		UE_LOG(LogTemp, Warning, TEXT("Hit Direction: %s"), *HitLocation.ToString());
		//Get world location if linetrace through crosshair
		//if it hits the landscape
			// TODO Tell controlled tank to aim at this point
	}
}

bool ATankController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldPos;	//to be discarded
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y, 
		CameraWorldPos,
		LookDirection
		);
}