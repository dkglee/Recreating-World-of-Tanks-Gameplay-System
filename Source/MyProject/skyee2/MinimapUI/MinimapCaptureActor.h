// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MinimapCaptureActor.generated.h"

UCLASS()
class MYPROJECT_API AMinimapCaptureActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMinimapCaptureActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category="Minimap")
	TObjectPtr<USceneCaptureComponent2D> CaptureComp;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="Minimap")
	TObjectPtr<UTextureRenderTarget2D> RenderTarget;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Minimap")
	FIntPoint RenderTargetSize = FIntPoint(512, 512);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Minimap")
	float OrthoWidth = 50000.f;

	UFUNCTION(BlueprintCallable, Category = "Minimap")
	void CaptureOnlyOnce();

	UFUNCTION(BlueprintPure, Category="Minimap")
	USceneCaptureComponent2D* GetCapture() const { return CaptureComp; }

};
