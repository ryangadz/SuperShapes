// Copyright 2018 gadz.tech, All Rights Reserved.

#include "SuperShapes.h"
#include "SuperShapesStyle.h"
#include "SuperShapesCommands.h"
#include "Misc/MessageDialog.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "Editor/MaterialEditor/Public/MaterialEditorModule.h"
#include "LevelEditor.h"

static const FName SuperShapesTabName("SuperShapes");

#define LOCTEXT_NAMESPACE "FSuperShapesModule"

void FSuperShapesModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FSuperShapesStyle::Initialize();
	FSuperShapesStyle::ReloadTextures();

	FSuperShapesCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FSuperShapesCommands::Get().PluginAction,
		FExecuteAction::CreateRaw(this, &FSuperShapesModule::PluginButtonClicked),
		FCanExecuteAction());
		
	//FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	IMaterialEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<IMaterialEditorModule>("MaterialEditor");

	{
		TSharedPtr<FExtender> MenuExtender = MakeShareable(new FExtender());
		MenuExtender->AddMenuExtension("WindowLayout", EExtensionHook::After, PluginCommands, FMenuExtensionDelegate::CreateRaw(this, &FSuperShapesModule::AddMenuExtension));

		LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MenuExtender);
	}
	
	{
		TSharedPtr<FExtender> ToolbarExtender = MakeShareable(new FExtender);
		ToolbarExtender->AddToolBarExtension("Asset", EExtensionHook::After, PluginCommands, FToolBarExtensionDelegate::CreateRaw(this, &FSuperShapesModule::AddToolbarExtension));
		
		LevelEditorModule.GetToolBarExtensibilityManager()->AddExtender(ToolbarExtender);
	}
}

void FSuperShapesModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	FSuperShapesStyle::Shutdown();

	FSuperShapesCommands::Unregister();
}

void FSuperShapesModule::PluginButtonClicked()
{
	// Put your "OnButtonClicked" stuff here
	FText DialogText = FText::Format(
							LOCTEXT("PluginButtonDialogText", "Comming soon"),
							FText::FromString(TEXT("FSuperShapesModule::PluginButtonClicked()")),
							FText::FromString(TEXT("SuperShapes.cpp"))
					   );
	FMessageDialog::Open(EAppMsgType::Ok, DialogText);
}

void FSuperShapesModule::AddMenuExtension(FMenuBuilder& Builder)
{
	Builder.AddMenuEntry(FSuperShapesCommands::Get().PluginAction);
}

void FSuperShapesModule::AddToolbarExtension(FToolBarBuilder& Builder)
{
	Builder.AddToolBarButton(FSuperShapesCommands::Get().PluginAction);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FSuperShapesModule, SuperShapes)