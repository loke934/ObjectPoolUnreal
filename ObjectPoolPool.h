#pragma once


#include "GameFrameWork/Actor.h"
#include "ObjectPoolPool.generated.h"

class APoolBehaviour;

USTRUCT()
struct FPoolSettings
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, Category = "PoolSettings")
	int PoolSize;

	UPROPERTY(EditDefaultsOnly, Category = "PoolSettings")
	TSubclassOf<APoolBehaviour> PoolClass;
};

UCLASS(Blueprintable)
class APool : public AActor
{
	GENERATED_BODY()

public:
	static APool* GetPoolInstance();

	UFUNCTION(BluePrintCallable)
	void CreatePools();

	UFUNCTION(BluePrintCallable)
	APoolBehaviour* GetPoolObject(TSubclassOf<APoolBehaviour> PoolClass, FVector position, FRotator rotation);

	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "PoolSettings")
	TArray<FPoolSettings> PoolSettingsArray;

	TMap<TSubclassOf<APoolBehaviour>, TArray<APoolBehaviour*>> PoolsMap;


private:
	APool() = default;

};

