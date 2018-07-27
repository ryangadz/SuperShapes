// Copyright 2018 gadz.tech, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "SuperShapesStyle.h"

class FSuperShapesCommands : public TCommands<FSuperShapesCommands>
{
public:

	FSuperShapesCommands()
		: TCommands<FSuperShapesCommands>(TEXT("SuperShapes"), NSLOCTEXT("Contexts", "SuperShapes", "SuperShapes Plugin"), NAME_None, FSuperShapesStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > PluginAction;
};
