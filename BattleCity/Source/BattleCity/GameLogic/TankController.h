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
	
	
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
private:
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
	ATank * GetContolledTank() const;
	// start the tank moving the barrel so that a shot would it where
	// the crosshair intersects the world
	void AimTowardsCrosshair();
	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5;
	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.33333;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000;
	
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitDirection) const;
	
};
