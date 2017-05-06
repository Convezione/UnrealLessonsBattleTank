// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankBarrel.h"
#include "TankAimingComponent.h"
#include "TankTurret.h"
#include "Projectile.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	//TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	localBarrel = FindComponentByClass<UTankBarrel>();
}





void ATank::Shoot() {
	//UE_LOG(LogTemp, Warning, TEXT("Tank: %s firing."), *(this->GetName()));
	if (!ensure(localBarrel)) { return; }
	bool reloaded = FPlatformTime::Seconds() - lastFireTime >= reloadTimeSeconds;
	if (reloaded) {
		auto projectile = GetWorld()->SpawnActor<AProjectile>(projectileBlueprint, 
											localBarrel->GetSocketLocation(FName("Barrel End")),
											localBarrel->GetSocketRotation(FName("Barrel End")), 
											FActorSpawnParameters::FActorSpawnParameters());
		projectile->LaunchProjectile(launchSpeed);
		lastFireTime = FPlatformTime::Seconds();
	}
}