// Fill out your copyright notice in the Description page of Project Settings.


#include "VRTeleportInputLibrary.h"

void UVRTeleportInputLibrary::SwitchHandInput(bool bUseLeftHand)
{
	UInputSettings* CurrentInputSettings = UInputSettings::GetInputSettings();
	TArray<FInputActionKeyMapping> ForwardKeyMappings;
	CurrentInputSettings->GetActionMappingByName("Forward", ForwardKeyMappings);

	if (bUseLeftHand)
	{
		if (ForwardKeyMappings[0].Key != EKeys::OculusTouch_Right_Thumbstick_Up)
		{
			RemoveInputMappings(bUseLeftHand);

			// Off Hand
			CurrentInputSettings->AddActionMapping(GetLeftHandForwardMapping());
			CurrentInputSettings->AddActionMapping(GetLeftHandStrafeRightMapping());
			CurrentInputSettings->AddActionMapping(GetLeftHandStrafeLeftMapping());

			// Main Hand
			CurrentInputSettings->AddActionMapping(GetLeftHandTeleportAheadMapping());
			CurrentInputSettings->AddActionMapping(GetLeftHandTurnRightMapping());
			CurrentInputSettings->AddActionMapping(GetLeftHandTurnLeftMapping());
		}
	}
	else
	{
		if (ForwardKeyMappings[0].Key != EKeys::OculusTouch_Left_Thumbstick_Up)
		{
			RemoveInputMappings(bUseLeftHand);

			// Off Hand
			CurrentInputSettings->AddActionMapping(GetRightHandForwardMapping());
			CurrentInputSettings->AddActionMapping(GetRightHandStrafeRightMapping());
			CurrentInputSettings->AddActionMapping(GetRightHandStrafeLeftMapping());

			// Main Hand
			CurrentInputSettings->AddActionMapping(GetRightHandTeleportAheadMapping());
			CurrentInputSettings->AddActionMapping(GetRightHandTurnRightMapping());
			CurrentInputSettings->AddActionMapping(GetRightHandTurnLeftMapping());
		}
	}
}

bool UVRTeleportInputLibrary::IsUsingLeftHand()
{
	UInputSettings* CurrentInputSettings = UInputSettings::GetInputSettings();
	TArray<FInputActionKeyMapping> ForwardKeyMappings;
	CurrentInputSettings->GetActionMappingByName("Forward", ForwardKeyMappings);
	bool bIsUsingLeftHand = false;

	for (const FInputActionKeyMapping& KeyMapping : ForwardKeyMappings)
	{
		if (KeyMapping == GetLeftHandForwardMapping())
		{
			bIsUsingLeftHand = true;
		}
	}

	return bIsUsingLeftHand;
}

void UVRTeleportInputLibrary::RemoveInputMappings(bool bUseLeftHand)
{
	UInputSettings* CurrentInputSettings = UInputSettings::GetInputSettings();

	if (bUseLeftHand)
	{
		CurrentInputSettings->RemoveActionMapping(GetRightHandForwardMapping());
		CurrentInputSettings->RemoveActionMapping(GetRightHandStrafeRightMapping());
		CurrentInputSettings->RemoveActionMapping(GetRightHandStrafeLeftMapping());
		CurrentInputSettings->RemoveActionMapping(GetRightHandTeleportAheadMapping());
		CurrentInputSettings->RemoveActionMapping(GetRightHandTurnRightMapping());
		CurrentInputSettings->RemoveActionMapping(GetRightHandTurnLeftMapping());
	}
	else
	{
		CurrentInputSettings->RemoveActionMapping(GetLeftHandForwardMapping());
		CurrentInputSettings->RemoveActionMapping(GetLeftHandStrafeRightMapping());
		CurrentInputSettings->RemoveActionMapping(GetLeftHandStrafeLeftMapping());
		CurrentInputSettings->RemoveActionMapping(GetLeftHandTeleportAheadMapping());
		CurrentInputSettings->RemoveActionMapping(GetLeftHandTurnRightMapping());
		CurrentInputSettings->RemoveActionMapping(GetLeftHandTurnLeftMapping());
	}
}



FInputActionKeyMapping UVRTeleportInputLibrary::GetRightHandForwardMapping()
{
	return FInputActionKeyMapping("Forward", EKeys::OculusTouch_Left_Thumbstick_Up);
}

FInputActionKeyMapping UVRTeleportInputLibrary::GetLeftHandForwardMapping()
{
	return FInputActionKeyMapping("Forward", EKeys::OculusTouch_Right_Thumbstick_Up);
}

FInputActionKeyMapping UVRTeleportInputLibrary::GetRightHandStrafeRightMapping()
{
	return FInputActionKeyMapping("StrafeRight", EKeys::OculusTouch_Left_Thumbstick_Right);
}

FInputActionKeyMapping UVRTeleportInputLibrary::GetLeftHandStrafeRightMapping()
{
	return FInputActionKeyMapping("StrafeRight", EKeys::OculusTouch_Right_Thumbstick_Right);
}

FInputActionKeyMapping UVRTeleportInputLibrary::GetRightHandStrafeLeftMapping()
{
	return FInputActionKeyMapping("StrafeLeft", EKeys::OculusTouch_Left_Thumbstick_Left);
}

FInputActionKeyMapping UVRTeleportInputLibrary::GetLeftHandStrafeLeftMapping()
{
	return FInputActionKeyMapping("StrafeLeft", EKeys::OculusTouch_Right_Thumbstick_Left);
}

FInputActionKeyMapping UVRTeleportInputLibrary::GetRightHandTeleportAheadMapping()
{
	return FInputActionKeyMapping("TeleportAhead", EKeys::OculusTouch_Right_Thumbstick_Up);
}

FInputActionKeyMapping UVRTeleportInputLibrary::GetLeftHandTeleportAheadMapping()
{
	return FInputActionKeyMapping("TeleportAhead", EKeys::OculusTouch_Left_Thumbstick_Up);
}

FInputActionKeyMapping UVRTeleportInputLibrary::GetRightHandTurnRightMapping()
{
	return FInputActionKeyMapping("TurnRight", EKeys::OculusTouch_Right_Thumbstick_Right);
}

FInputActionKeyMapping UVRTeleportInputLibrary::GetLeftHandTurnRightMapping()
{
	return FInputActionKeyMapping("TurnRight", EKeys::OculusTouch_Left_Thumbstick_Right);
}

FInputActionKeyMapping UVRTeleportInputLibrary::GetRightHandTurnLeftMapping()
{
	return FInputActionKeyMapping("TurnLeft", EKeys::OculusTouch_Right_Thumbstick_Left);
}

FInputActionKeyMapping UVRTeleportInputLibrary::GetLeftHandTurnLeftMapping()
{
	return FInputActionKeyMapping("TurnLeft", EKeys::OculusTouch_Left_Thumbstick_Left);
}
