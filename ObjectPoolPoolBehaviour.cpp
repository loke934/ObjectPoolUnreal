#include "ObjectPoolPoolBehaviour.h"


bool APoolBehaviour::IsObjectActive()
{
	return IsActive;
}

void APoolBehaviour::ReturnObject()
{
	IsActive = false;

	//Hides visible components
	SetActorHiddenInGame(true);
	//Disable collision components
	SetActorEnableCollision(false);
	//Stops actor from ticking
	SetActorTickEnabled(false);

	//Reset position and rotation
	SetActorRotation(FRotator::ZeroRotator);
}

void APoolBehaviour::OnEnableObject()
{
	IsActive = true;

	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);
	SetActorTickEnabled(true);
	
}
