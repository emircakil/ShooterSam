#include "ShooterSamPlayerController.h"

void AShooterSamPlayerController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);

    if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
        ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
    {
        // Priority 0 — base layer, all platforms
        if (DefaultMappingContext)
        {
            Subsystem->AddMappingContext(DefaultMappingContext, 0);
        }

        // Priority 1 — only on Desktop/Console, never on mobile
#if !PLATFORM_ANDROID && !PLATFORM_IOS
        if (MobileExcludedMappingContext)
        {
            Subsystem->AddMappingContext(MobileExcludedMappingContext, 1);
        }
#endif
    }
}

void AShooterSamPlayerController::OnUnPossess()
{
    if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
        ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
    {
        if (DefaultMappingContext)
        {
            Subsystem->RemoveMappingContext(DefaultMappingContext);
        }

#if !PLATFORM_ANDROID && !PLATFORM_IOS
        if (MobileExcludedMappingContext)
        {
            Subsystem->RemoveMappingContext(MobileExcludedMappingContext);
        }
#endif
    }

    Super::OnUnPossess();
}