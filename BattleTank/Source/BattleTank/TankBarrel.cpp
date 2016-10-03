// Fill out your copyright notice in the Description page of Project Settings.
#include "BattleTank.h"
#include "TankBarrel.h"


void UTankBarrel::Elevate(float RelativeSpeed)
{
	// Move the barrel the right amount this frame
	// Given a max elevation speed, and the frame time
	
	if (GetWorld()){

		RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.5, +1.5);
		auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
		auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
		auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);
		UE_LOG(LogTemp, Warning, TEXT("Elevation %f"), Elevation);
		SetRelativeRotation(FRotator(Elevation, 0, 0));
	}
}