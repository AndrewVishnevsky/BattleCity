// Fill out your copyright notice in the Description page of Project Settings.


#include "TankController.h"

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

ATank * ATankController::GetContolledTank() const
{
	return Cast<ATank>(GetPawn());
}


