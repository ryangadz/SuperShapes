// Copyright 2018 gadz.tech, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ProceduralMeshComponent.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "SuperShapeMesh.generated.h"

/**
 * 
 */
UCLASS(ClassGroup=(SuperShapes), meta=(BlueprintSpawnableComponent))
class SUPERSHAPES_API USuperShapeMesh : public UProceduralMeshComponent
{
	GENERATED_BODY()
	
public:

	USuperShapeMesh(const FObjectInitializer &ObjectInitializer);

	UPROPERTY(EditAnywhere, BlueprintReadWrite,DisplayName = "Subdivisions", Category = "SuperShape Properties")
	int32 Subdivisions = 4;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,DisplayName = "M", Category = "SuperShape Properties")
	float M = 4.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,DisplayName = "N1", Category = "SuperShape Properties")
	float N1 = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,DisplayName = "N2", Category = "SuperShape Properties")
	float N2 = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,DisplayName = "N3", Category = "SuperShape Properties")
	float N3 = 1.f;

	UPROPERTY()
	class UMaterialInterface* DefaultMaterial;

	UPROPERTY()
	class UMaterialInstanceDynamic* InstancedMaterial;


	UPROPERTY()
	TArray<FVector> Vertices;

	UPROPERTY()
	TArray<int32> Triangles;

	UPROPERTY()
	TArray<FVector> Normals;

	UPROPERTY()
	TArray<FVector2D> UV0;

	UPROPERTY()
	TArray<FLinearColor> VertexColors;

	UPROPERTY()
	TArray<FProcMeshTangent> Tangents;
	
	UFUNCTION()
	float GetRadius(float RadUnit);

	UFUNCTION()
	void BuildSuperShapeMesh();

	virtual void PostLoad() override;

	virtual void PostInitProperties() override;

	virtual void OnRegister() override;

	#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	#endif

};
