// Fill out your copyright notice in the Description page of Project Settings.


#include "Mover.h"
#include "Math/UnrealMathUtility.h"

// Sets default values for this component's properties
UMover::UMover()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMover::BeginPlay()
{
	Super::BeginPlay();
	OriginalLocation = GetOwner()->GetActorLocation();
}


// Called every frame
void UMover::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	FVector TargetLocation  =  OriginalLocation ;
	if(Move){
		TargetLocation  =  OriginalLocation + offset  ;
	}
	FVector CurrentLocation = GetOwner()->GetActorLocation();
	speed = offset.Length()/ time;
	FVector update = FMath::VInterpConstantTo(CurrentLocation ,TargetLocation , DeltaTime , speed );
	//FVector update = FMath::VInterpConstantTo(TargetLocation ,CurrentLocation , DeltaTime , speed );
	GetOwner()->SetActorLocation(update);
}
 
void UMover::SetShouldMove(bool NewMove){
	Move = NewMove;
}
