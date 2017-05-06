// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTrack;


UCLASS(ClassGroup=(Movement), meta=(BlueprintSpawnableComponent))
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable,Category="Movement")
		void IntendMoveForward(float Throw);
	UFUNCTION(BlueprintCallable, Category = "Movement")
		void IntendTurnRight(float Throw);
	UFUNCTION(BlueprintCallable, Category = "Setup")
		void Initialise(UTankTrack* lToSet, UTankTrack* rToSet);


	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;
private:
	UTankTrack* leftTrack = nullptr;
	UTankTrack* rightTrack = nullptr;
};
