// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/InputSettings.h"
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "VRTeleportInputLibrary.generated.h"

/**
 *
 */
UCLASS()
class FP_VRHANDS_API UVRTeleportInputLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category = HandInput)
	static FInputActionKeyMapping GetRightHandForwardMapping();

	UFUNCTION(BlueprintPure, Category = HandInput)
	static FInputActionKeyMapping GetLeftHandForwardMapping();

	UFUNCTION(BlueprintPure, Category = HandInput)
	static FInputActionKeyMapping GetRightHandStrafeRightMapping();

	UFUNCTION(BlueprintPure, Category = HandInput)
	static FInputActionKeyMapping GetLeftHandStrafeRightMapping();

	UFUNCTION(BlueprintPure, Category = HandInput)
	static FInputActionKeyMapping GetRightHandStrafeLeftMapping();

	UFUNCTION(BlueprintPure, Category = HandInput)
	static FInputActionKeyMapping GetLeftHandStrafeLeftMapping();

	UFUNCTION(BlueprintPure, Category = HandInput)
	static FInputActionKeyMapping GetRightHandTeleportAheadMapping();

	UFUNCTION(BlueprintPure, Category = HandInput)
	static FInputActionKeyMapping GetLeftHandTeleportAheadMapping();

	UFUNCTION(BlueprintPure, Category = HandInput)
	static FInputActionKeyMapping GetRightHandTurnRightMapping();

	UFUNCTION(BlueprintPure, Category = HandInput)
	static FInputActionKeyMapping GetLeftHandTurnRightMapping();

	UFUNCTION(BlueprintPure, Category = HandInput)
	static FInputActionKeyMapping GetRightHandTurnLeftMapping();

	UFUNCTION(BlueprintPure, Category = HandInput)
	static FInputActionKeyMapping GetLeftHandTurnLeftMapping();

	/** Switch the input actions for VR localmotion with motion controllers to the opposite hand */
	UFUNCTION(BlueprintCallable, Category = HandInput)
	static void SwitchHandInput(bool bUseLeftHand);

	/** Returns true if using left hand controller scheme */
	UFUNCTION(BlueprintCallable, Category = HandInput)
	static bool IsUsingLeftHand();

private:

	static void RemoveInputMappings(bool bUseLeftHand);
};
