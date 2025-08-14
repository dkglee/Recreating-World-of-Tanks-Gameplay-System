// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MinimapUI.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UMinimapUI : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(meta=(BindWidget))
	class UImage* Img_Minimap;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Minimap")
	float UpdateHz = 20.f;
};
