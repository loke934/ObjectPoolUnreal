#pragma once

#include"ObjectPoolPoolBehaviour.h"
#include"ObjectPoolPoolObject.generated.h"

class USphereComponent;

UCLASS(Blueprintable)
class APoolObject : public APoolBehaviour
{
	GENERATED_BODY()

public:
	APoolObject();

	UPROPERTY(VisibleAnywhere)
	USphereComponent* Collision;

};



