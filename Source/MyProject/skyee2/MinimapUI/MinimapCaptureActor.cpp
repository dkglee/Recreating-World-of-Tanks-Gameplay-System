// Fill out your copyright notice in the Description page of Project Settings.


#include "MinimapCaptureActor.h"

#include "Components/SceneCaptureComponent2D.h"


// Sets default values
AMinimapCaptureActor::AMinimapCaptureActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CaptureComp = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("SceneCaptureComp"));
	CaptureComp->SetupAttachment(RootComponent);

	CaptureComp->ProjectionType = ECameraProjectionMode::Orthographic;
	CaptureComp->OrthoWidth = OrthoWidth;
	CaptureComp->bCaptureEveryFrame = false;
	CaptureComp->bCaptureOnMovement = false;
	CaptureComp->CaptureSource = SCS_FinalColorLDR;
}

// Called when the game starts or when spawned
void AMinimapCaptureActor::BeginPlay()
{
	Super::BeginPlay();

	CaptureComp->ProjectionType = ECameraProjectionMode::Orthographic;
	CaptureComp->OrthoWidth = OrthoWidth;

	CaptureOnlyOnce();
}

// Called every frame
void AMinimapCaptureActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMinimapCaptureActor::CaptureOnlyOnce()
{
	if (!CaptureComp || !RenderTarget) return;

	CaptureComp->CaptureScene();
}
