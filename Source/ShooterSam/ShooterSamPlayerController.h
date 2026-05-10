#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "ShooterSamPlayerController.generated.h"

UCLASS()
class SHOOTERSAM_API AShooterSamPlayerController : public APlayerController
{
    GENERATED_BODY()

public:
    // Added on ALL platforms
    UPROPERTY(EditDefaultsOnly, Category = "Input")
    TObjectPtr<UInputMappingContext> DefaultMappingContext;

    // Added on all platforms EXCEPT Android and iOS
    UPROPERTY(EditDefaultsOnly, Category = "Input")
    TObjectPtr<UInputMappingContext> MobileExcludedMappingContext;

protected:
    virtual void OnPossess(APawn* InPawn) override;
    virtual void OnUnPossess() override;
};