

#pragma once

#include "CoreMinimal.h"
#include "TickTickBoom.h"
#include "GameFramework/PlayerController.h"
#include "TTBPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ATTBPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	/* Camera actor class to spawn as the main camera */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Camera)
	TSubclassOf<class ATTBCameraActor> CameraActorClass;
	
	/* Active camera */
	UPROPERTY(BlueprintReadWrite)
	class ATTBCameraActor* CameraActor;

	bool bIsPaused;

	/* Set up player input */
	virtual void SetupInputComponent() override;

	void BeginPlay();

	/* Sets up the camera.  Called by gamestate */
	void Inititialize();

	UFUNCTION(BlueprintCallable)
	void SetCameraFocusTarget(AActor* TargetActor);

	UFUNCTION(BlueprintCallable)
	void TogglePauseGame();

};
