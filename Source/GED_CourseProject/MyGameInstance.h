// GameInstance/Singleton for GED_CourseProject, header file

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"


UCLASS()
class GED_COURSEPROJECT_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	// this here adds points to a player score
	UFUNCTION(BlueprintCallable, Category = "Score")
	void AddScore(int32 Points);

	// gets the score, so updates it pretty much
	UFUNCTION(BlueprintCallable, Category = "Score")
	int32 GetScore() const;

	// resets score, in case of new level but currently not used 
	UFUNCTION(BlueprintCallable, Category = "Score")
	void ResetScore();

	// adds or subtracts hp from player
	UFUNCTION(BlueprintCallable, Category = "Hit Points")
	void AddHitPoints(int32 HP);

	// gets and updates current hp value 
	UFUNCTION(BlueprintCallable, Category = "Hit Points")
	int32 GetHitPoints() const;

	// resets player hp (in the event of a game over or reset)
	UFUNCTION(BlueprintCallable, Category = "Hit Points")
	void ResetHitPoints();

	// alters numerical value of intensity 
	UFUNCTION(BlueprintCallable, Category = "Intensity")
	void AddIntensity(int32 Intensity);

	// gets and updates current intensity value
	UFUNCTION(BlueprintCallable, Category = "Intensity")
	int32 GetIntensity() const;

	// resets intensity value
	UFUNCTION(BlueprintCallable, Category = "Intensity")
	void ResetIntensity();

private:
	// Starting score is set at 0 (duh)
	int32 TotalScore = 0;

	// HP at the beginning of a playthrough
	int32 PlayerHitPoints = 10;

	// Sets initial Intenisty value which will shift per events that happen to player
	int32 IntensityValue = 0;
};
