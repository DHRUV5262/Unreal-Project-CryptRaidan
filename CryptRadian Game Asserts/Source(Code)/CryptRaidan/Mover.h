// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Mover.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CRYPTRAIDAN_API UMover : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMover();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION()
	void SetShouldMove(bool Move);

private:
	UPROPERTY(EditAnywhere)
	FVector offset = FVector(0,0,0) ;

	UPROPERTY(EditAnywhere)
	float time = 4 ;

	UPROPERTY(editAnywhere)
	bool Move = false;

	float speed ;
	FVector OriginalLocation ;
};
