#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ObjectPoolPoolObjectInterface.h"
#include "ObjectPoolPoolBehaviour.generated.h"

UCLASS(Category = "ObjectPool")
class APoolBehaviour : public AActor, public IPoolObjectInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BluePrintCallable)
	virtual bool IsObjectActive() override;

	UFUNCTION(BluePrintCallable)
	virtual void ReturnObject() override;

	UFUNCTION(BluePrintCallable)
	virtual void OnEnableObject() override;

private:
	bool IsActive;
};