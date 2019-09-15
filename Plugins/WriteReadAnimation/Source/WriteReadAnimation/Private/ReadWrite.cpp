// Fill out your copyright notice in the Description page of Project Settings.


#include "ReadWrite.h"



FString UReadWrite::fn = "test.txt";
TArray<FString> UReadWrite::allLines;

void UReadWrite::writeNewData(FString fileName, FArrayAllParams params, FString delimiter) {

	//first line as header;
	if (allLines.Num()==0) {
		fn=FPaths::Combine(FPaths::GameDir(), fileName);
		FString line;
		line.Append("time");
		line.Append(delimiter);
		for (int i = 0; i < params.Allparams.Num();i++) {

			line.Append(params.Allparams[i].nameParam);
			line.Append(delimiter);
		}
		allLines.Add(line);

		line = "";
		line.Append(params.time);
		line.Append(delimiter);
		for (int i = 0; i < params.Allparams.Num(); i++) {

			line.Append(params.Allparams[i].valueParam);
			line.Append(delimiter);
		}
		allLines.Add(line);
	}
	else {
		FString line;
		line.Append(params.time);
		line.Append(delimiter);
		for (int i = 0; i < params.Allparams.Num(); i++) {

			line.Append(params.Allparams[i].valueParam);
			line.Append(delimiter);
		}
		allLines.Add(line);
	}
}


FMapFromFile UReadWrite::readFromFileToData(FString fileName, FString delimiter)
{
	FMapFromFile mff;
	
	FString pathWithFile = FPaths::Combine(FPaths::GameDir(), fileName);
	TArray<FString> mapKey;
	TArray<FString> result;
	if (FPaths::FileExists(pathWithFile)) {
		FFileHelper::LoadFileToStringArray(result, *pathWithFile);

		TArray<FString> mapValue;
		result[0].ParseIntoArray(mapKey, *delimiter);

		//TMap<FString, FArrayFromFile> p;
		for (size_t j = 0; j < mapKey.Num(); j++)
		{
			TArray<FString> v;
			FArrayFromFile ffa;
			ffa.value = v;
			mff.mapKeyVArray.Add(mapKey[j], ffa);
		}
		//mff.mapKeyVArray = p;
		for (size_t i = 1; i < result.Num(); i++)
		{
			result[i].ParseIntoArray(mapValue, *delimiter);
			for (size_t j = 0; j < mapValue.Num(); j++)
			{
				FArrayFromFile aff = mff.mapKeyVArray[mapKey[j]];
				mff.mapKeyVArray[mapKey[j]].value.Add(mapValue[j]);
			}
		}

		return mff;
	}
	else {
		return mff;

	}
}

void UReadWrite::writeDataToFile() {

	FFileHelper::SaveStringArrayToFile(allLines, *fn);

}



