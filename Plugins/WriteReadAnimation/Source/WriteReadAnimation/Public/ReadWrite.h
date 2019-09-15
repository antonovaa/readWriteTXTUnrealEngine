// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Paths.h"
#include "FileHelper.h"
#include "ReadWrite.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct WRITEREADANIMATION_API FArrayFromFile
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
	TArray<FString> value;

};

USTRUCT(BlueprintType)
struct WRITEREADANIMATION_API FMapFromFile
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
	TMap<FString, FArrayFromFile> mapKeyVArray;

};















USTRUCT(BlueprintType)
struct WRITEREADANIMATION_API FMapParams
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
	FString nameParam;
	UPROPERTY(BlueprintReadWrite)
	FString valueParam;

};


USTRUCT(BlueprintType)
struct WRITEREADANIMATION_API FArrayAllParams
{
	GENERATED_USTRUCT_BODY()

public:

	UPROPERTY(BlueprintReadWrite)
	TArray<FMapParams> Allparams;
	UPROPERTY(BlueprintReadWrite)
	FString time;
};

UCLASS()
class WRITEREADANIMATION_API UReadWrite : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:

	//~UReadWrite();
	static FString fn;
	static TArray<FString> allLines;
	UFUNCTION(BlueprintCallable, Category = "Smooth Anim", meta = (DisplayName = "write new data"))
		static void writeNewData(FString fileName, FArrayAllParams params, FString delimiter ="$");
	UFUNCTION(BlueprintCallable, Category = "Smooth Anim", meta = (DisplayName = "write data to file"))
		static void writeDataToFile();
	UFUNCTION(BlueprintCallable, Category = "Smooth Anim", meta = (DisplayName = "read data from file"))
		static FMapFromFile readFromFileToData(FString fileName, FString delimiter = "$");
};
