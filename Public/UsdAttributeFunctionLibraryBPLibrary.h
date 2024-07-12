// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "USDIncludesStart.h"
#include <pxr/base/vt/value.h>
// #include "USDIncludesEnd.h"


#include "Kismet/BlueprintFunctionLibrary.h"
#include "UsdAttributeFunctionLibraryBPLibrary.generated.h"


/* 
*	Function library class.
*	Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.
*
*	When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.
*	BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.
*	BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.
*	DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.
*				Its lets you name the node using characters not allowed in C++ function names.
*	CompactNodeTitle - the word(s) that appear on the node.
*	Keywords -	the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu. 
*				Good example is "Print String" node which you can find also by using keyword "log".
*	Category -	the category your node will be under in the Blueprint drop-down menu.
*
*	For more info on custom blueprint nodes visit documentation:
*	https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation
*/
namespace UE
{
	class FUsdPrim;
	class FSdfPath;
	class FUsdAttribute;
	class FVtValue;
}
//
// namespace pxr
// {
// 	class VtValue;
// }

class AUsdStageActor;

UCLASS()
class UUsdAttributeFunctionLibraryBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()
	
public:
	
	static UE::FUsdAttribute GetUsdAttributeInternal(AUsdStageActor* StageActor, FString PrimName, FString AttrName);

	template <typename T>
	static T ExtractAttributeValue(UE::FVtValue& Value);
	
	template <typename T>
	static T GetUsdAttributeValueInternal(AUsdStageActor* StageActor, FString PrimName, FString AttrName);

	template <typename T>
	static T GetUsdAnimatedAttributeValueInternal(AUsdStageActor* StageActor, FString PrimName, FString AttrName, double TimeSample);

	template <typename T>
	static FVector ConvertUsdVectorToFVector(const pxr::VtValue& pxrValue);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "UsdAttributes")
	static FVector GetUsdVec3Attribute(AUsdStageActor* StageActor, FString PrimName, FString AttrName);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "UsdAttributes")
	static float GetUsdFloatAttribute(AUsdStageActor* StageActor, FString PrimName, FString AttrName);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "UsdAttributes")
	static double GetUsdDoubleAttribute(AUsdStageActor* StageActor, FString PrimName, FString AttrName);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "USD Attributes")
	static int GetUsdIntAttribute(AUsdStageActor* StageActor, FString PrimName, FString AttrName);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "UsdAttributes")
	static float GetUsdAnimatedFloatAttribute(AUsdStageActor* StageActor, FString PrimName, FString AttrName, double TimeSample);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "UsdAttributes")
	static double GetUsdAnimatedDoubleAttribute(AUsdStageActor* StageActor, FString PrimName, FString AttrName, double TimeSample);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "USD Attributes")
	static int GetUsdAnimatedIntAttribute(AUsdStageActor* StageActor, FString PrimName, FString AttrName, double TimeSample);


	static void GetSdfPathWithName(UE::FUsdPrim& CurrentPrim, FString TargetName, UE::FSdfPath& OutPath);

};

