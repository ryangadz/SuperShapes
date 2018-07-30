// Copyright 2018 gadz.tech, All Rights Reserved.

#include "SuperShapeMesh.h"

USuperShapeMesh::USuperShapeMesh(const FObjectInitializer &ObjectInitializer) : Super(ObjectInitializer)
{  
    
    static ConstructorHelpers::FObjectFinder<UMaterialInterface> defMaterial(TEXT("Material'/SuperShapes/M_SSSample.M_SSSample'"));
    if(defMaterial.Object != NULL)
    {
        DefaultMaterial = defMaterial.Object;
        ParentMaterial = DefaultMaterial;
       // InstancedMaterial = UMaterialInstanceDynamic::Create(DefaultMaterial, this);
      //  if (InstancedMaterial != NULL)
      //  this->SetMaterial(0,InstancedMaterial);
    }
}

//This is called when actor is already in level and map is opened
void USuperShapeMesh::PostLoad()
{
	 Super::PostLoad();
	// BuildSuperShapeMesh();
    // InstancedMaterial = UMaterialInstanceDynamic::Create(DefaultMaterial, this);
    //     if (InstancedMaterial != NULL)
    //     {
    //         InstancedMaterial->SetScalarParameterValue("M", M);
    //         InstancedMaterial->SetScalarParameterValue("N1", N1);
    //         InstancedMaterial->SetScalarParameterValue("N2", N2);
    //         InstancedMaterial->SetScalarParameterValue("N3", N3);
    //         this->SetMaterial(0,InstancedMaterial);
    //     }



}

void USuperShapeMesh::PostEditChangeProperty(FPropertyChangedEvent &PropertyChangedEvent)
{
    Super::PostEditChangeProperty(PropertyChangedEvent);
    // BuildSuperShapeMesh();
    // InstancedMaterial = UMaterialInstanceDynamic::Create(DefaultMaterial, this);
    //     if (InstancedMaterial != NULL)
    //     {
    //         InstancedMaterial->SetScalarParameterValue("M", M);
    //         InstancedMaterial->SetScalarParameterValue("N1", N1);
    //         InstancedMaterial->SetScalarParameterValue("N2", N2);
    //         InstancedMaterial->SetScalarParameterValue("N3", N3);
    //         this->SetMaterial(0,InstancedMaterial);
    //     }
}

void USuperShapeMesh::PostInitProperties()
{
    Super::PostInitProperties();
  //  BuildSuperShapeMesh();
}

void USuperShapeMesh::OnRegister()
{
	Super::OnRegister();

	BuildSuperShapeMesh();
    InstancedMaterial = UMaterialInstanceDynamic::Create(ParentMaterial, this);
        if (InstancedMaterial != NULL)
        {
            InstancedMaterial->SetScalarParameterValue("M", M);
            InstancedMaterial->SetScalarParameterValue("N1", N1);
            InstancedMaterial->SetScalarParameterValue("N2", N2);
            InstancedMaterial->SetScalarParameterValue("N3", N3);
            this->SetMaterial(0,InstancedMaterial);
        }

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
    this->ClearAllMeshSections();
    float radUnit0;
    float radUnit1;
    float radius0;
    float radius1;

    for (int32 i = 0; i < Subdivisions; i++)
    {
        radUnit0 = ((float)( i) / (float)Subdivisions) * (2*PI);
        radUnit1 = ((float)( i + 1) / (float)Subdivisions) * (2*PI);
        radius0 = GetRadius(radUnit0);
        radius1 = GetRadius(radUnit1);

        Vertices.Add(FVector(0, 0, 0));
        Vertices.Add(FVector(FGenericPlatformMath::Sin(radUnit0) * 100 * radius0, FGenericPlatformMath::Cos(radUnit0) * 100 * radius0, 0));
        Vertices.Add(FVector(FGenericPlatformMath::Sin(radUnit1) * 100 * radius1, FGenericPlatformMath::Cos(radUnit1) * 100 * radius1, 0));

        Triangles.Add(i * 3);
        Triangles.Add(i * 3 + 1);
        Triangles.Add(i * 3 + 2);

        UV0.Add(FVector2D(.5f, .5f));
        UV0.Add(FVector2D((FGenericPlatformMath::Sin(radUnit0) * radius0 + 1) / 2, (FGenericPlatformMath::Cos(radUnit0) * radius0 + 1) / 2));
        UV0.Add(FVector2D((FGenericPlatformMath::Sin(radUnit1) * radius1 + 1) / 2, (FGenericPlatformMath::Cos(radUnit1) * radius1 + 1) / 2));

    }
    this->CreateMeshSection_LinearColor(0, Vertices, Triangles, Normals, UV0, VertexColors, Tangents, false);
}