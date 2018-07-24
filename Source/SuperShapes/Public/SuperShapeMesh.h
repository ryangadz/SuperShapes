// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProceduralMeshComponent.h"
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

};
