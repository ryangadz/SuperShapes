// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "SuperShapesCommands.h"

#define LOCTEXT_NAMESPACE "FSuperShapesModule"

void FSuperShapesCommands::RegisterCommands()
{
	UI_COMMAND(PluginAction, "SuperShapes", "Execute SuperShapes action", EUserInterfaceActionType::Button, FInputGesture());
}

#undef LOCTEXT_NAMESPACE
