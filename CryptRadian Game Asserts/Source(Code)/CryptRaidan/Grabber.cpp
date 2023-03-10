// Fill out your copyright notice in the Description page of Project Settings.


#include "Grabber.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "CryptRaidanGameMode.h"


// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();
}
// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	UPhysicsHandleComponent *PhysicsHandle = GetPhysicsHandle();
	if(PhysicsHandle == nullptr){
		return;
	}
	if(PhysicsHandle->GetGrabbedComponent() != nullptr){
		FVector TargetLocation = GetComponentLocation() + GetForwardVector() * HoldDistance ; 
	PhysicsHandle->SetTargetLocationAndRotation(TargetLocation , GetComponentRotation());
	}
}

void UGrabber::Grab(){

	UPhysicsHandleComponent *PhysicsHandle = GetPhysicsHandle();
	if(PhysicsHandle == nullptr){
		return;
	}
	FHitResult OutHit;
	bool HasHit = GetGrabInReach(OutHit);
	if(HasHit){
		UPrimitiveComponent* HitComponent = OutHit.GetComponent();
		HitComponent->SetSimulatePhysics(true);
		HitComponent->WakeAllRigidBodies();
		OutHit.GetActor()->Tags.Add("Grabbed");
		OutHit.GetActor()->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
		PhysicsHandle->GrabComponentAtLocationWithRotation(
			HitComponent,
			NAME_None,
			OutHit.ImpactPoint,
			GetComponentRotation()
		);
	}
}
void UGrabber::Release(){

	FHitResult OutHit;
	UPhysicsHandleComponent *PhysicsHandle = GetPhysicsHandle();
	if(PhysicsHandle == nullptr){
		return;
	}

	if(PhysicsHandle->GetGrabbedComponent() != nullptr){
		AActor* Grabbed = PhysicsHandle->GetGrabbedComponent()->GetOwner();
		Grabbed->Tags.Remove("Grabbed");
		PhysicsHandle->GetGrabbedComponent()->WakeAllRigidBodies();
		PhysicsHandle->ReleaseComponent();
	}
} 

UPhysicsHandleComponent* UGrabber::GetPhysicsHandle() const{
	UPhysicsHandleComponent *Result = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if(Result == nullptr){
		UE_LOG(LogTemp, Display, TEXT("Physics Handle Component is not avaliable"));
	}
	return Result ;
}

bool  UGrabber::GetGrabInReach(FHitResult& OutHit) const
{
	FVector Start = GetComponentLocation();
	FVector End = Start + GetForwardVector()* GrabDistance; 
	DrawDebugLine(GetWorld() , Start ,End , FColor::Red);
	DrawDebugSphere(GetWorld() , End , 10 ,10 ,FColor::Blue , false ,5);
	FCollisionShape Sphere = FCollisionShape::MakeSphere(GrabRadius);
	bool HasHit = GetWorld()->SweepSingleByChannel(OutHit ,
	 	Start , End 
		,FQuat::Identity 
	 	,ECC_GameTraceChannel2 
	 	,Sphere
		);
	return HasHit ;
}