// GameInstance/Singleton for GED_CourseProject, cpp file


#include "MyGameInstance.h"

void UMyGameInstance::AddScore(int32 Points)
{
	TotalScore += Points;

	// debug text to see if function is even going through or not
	UE_LOG(LogTemp, Log, TEXT("You got a gem! Your Score is now: %d"), TotalScore);
}

int32 UMyGameInstance::GetScore() const
{
	return TotalScore;
}

void UMyGameInstance::ResetScore()
{
	TotalScore = 0;
}

void UMyGameInstance::AddHitPoints(int32 HP)
{
	PlayerHitPoints += HP;

	// debug text to see if function is even going through or not
	UE_LOG(LogTemp, Log, TEXT("Your current HP value is: %d"), PlayerHitPoints);
}

int32 UMyGameInstance::GetHitPoints() const
{
	return PlayerHitPoints;
}

void UMyGameInstance::ResetHitPoints()
{
	PlayerHitPoints = 10;
}

void UMyGameInstance::AddIntensity(int32 Intensity)
{
	IntensityValue += Intensity;

	// debug text to see if function is even going through or not
	UE_LOG(LogTemp, Log, TEXT("Current Intenisty Value: %d"), IntensityValue);
}

int32 UMyGameInstance::GetIntensity() const
{
	return IntensityValue;
}

void UMyGameInstance::ResetIntensity()
{
	IntensityValue = 0;
}