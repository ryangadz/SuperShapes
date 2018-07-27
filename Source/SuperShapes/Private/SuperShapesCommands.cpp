// Copyright 2018 gadz.tech, All Rights Reserved.

#include "SuperShapesCommands.h"

#define LOCTEXT_NAMESPACE "FSuperShapesModule"

void FSuperShapesCommands::RegisterCommands()
{
	UI_COMMAND(PluginAction, "SuperShapes", "Execute SuperShapes action", EUserInterfaceActionType::Button, FInputGesture());
}

#undef LOCTEXT_NAMESPACE
