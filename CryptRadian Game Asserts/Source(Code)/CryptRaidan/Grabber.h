// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CRYPTRAIDAN_API UGrabber : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION(BluePrintCallable)
	void Release() ;
	UFUNCTION(BluePrintCallable)
	void Grab() ;

private:
	UPROPERTY(EditAnywhere)
	float GrabDistance = 400 ;

	UPROPERTY(EditAnywhere)
	float GrabRadius = 10;

	UFUNCTION(BluePrintCallable)
	UPhysicsHandleComponent* GetPhysicsHandle() const;

	UPROPERTY(EditAnyWhere)
	float HoldDistance = 200 ;

	UFUNCTION(BluePrintCallable)
	bool GetGrabInReach(FHitResult &OutHit) const ;

	class ACryptRaidanGameMode* Crypt ;
};
