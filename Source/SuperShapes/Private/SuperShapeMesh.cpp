// Fill out your copyright notice in the Description page of Project Settings.

#include "SuperShapeMesh.h"

USuperShapeMesh::USuperShapeMesh(const FObjectInitializer &ObjectInitializer) : Super(ObjectInitializer)
{

}


 
// This is called when actor is already in level and map is opened
void USuperShapeMesh::PostLoad()
{
	Super::PostLoad();
	BuildSuperShapeMesh();
}

float USuperShapeMesh::GetRadius(float RadUnit)
{

    if (N1 != 0)
    { 
        float part1 = FGenericPlatformMath::Pow(FGenericPlatformMath::Abs(FGenericPlatformMath::Cos((RadUnit * M) / 4)), N2);
        float part2 = FGenericPlatformMath::Pow(FGenericPlatformMath::Abs(FGenericPlatformMath::Sin((RadUnit * M) / 4)), N3);
        float part3 = FGenericPlatformMath::Pow((part1 + part2), (-1 / N1));
        return part3;
    }
    else
        return 1;
}

void USuperShapeMesh::BuildSuperShapeMesh()
{
    float radUnit0;
    float radUnit1;
    float radius0;
    float radius1;

    for(int32 i = 0; i < Subdivisions; i++)
    {
        radUnit0 = ((float)i/(float)Subdivisions)*6.28;
        radUnit1 =  ((float)(i+1)/(float)Subdivisions)*6.28;
        radius0 = GetRadius(radUnit0);
        radius1 = GetRadius(radUnit1);
        Vertices.Add(FVector(0, 0, 0));
        Vertices.Add(FVector(FGenericPlatformMath::Cos(radUnit1)*100*radius1, FGenericPlatformMath::Sin(radUnit1)*100*radius1, 0));
        Vertices.Add(FVector(FGenericPlatformMath::Cos(radUnit0)*100*radius0, FGenericPlatformMath::Sin(radUnit0)*100*radius0, 0));
        Triangles.Add(i*3);
        Triangles.Add(i*3+1);
        Triangles.Add(i*3+2);
    }
    // Vertices.Add(FVector(0, 0, 0));
	// Vertices.Add(FVector(0, 100, 0));
	// Vertices.Add(FVector(0, 0, 100));
    // Triangles.Add(0);
	// Triangles.Add(1);
	// Triangles.Add(2);
    // void CreateMeshSection_LinearColor(int32 SectionIndex,
    //  const TArray<FVector>& Vertices, 
    //  const TArray<int32>& Triangles, 
    //  const TArray<FVector>& Normals, 
    //  const TArray<FVector2D>& UV0, 
    //  const TArray<FLinearColor>& VertexColors, 
    //  const TArray<FProcMeshTangent>& Tangents, 
    //  bool bCreateCollision);
    this->CreateMeshSection_LinearColor(0,Vertices, Triangles, Normals, UV0, VertexColors, Tangents, false );
}