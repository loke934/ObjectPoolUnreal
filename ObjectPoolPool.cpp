#include "ObjectPoolPool.h"
#include "ObjectPoolPoolBehaviour.h"

APool* APool::GetPoolInstance()
{
	static APool PoolInstance;
	return &PoolInstance;
}

void APool::CreatePools()
{
	FTransform SpawnTransform = GetActorTransform();

	for (int i = 0; i < PoolSettingsArray.Num(); i++)
	{
		TArray<APoolBehaviour*> ObjectArray;

		for (int k = 0; k < PoolSettingsArray[i].PoolSize; k++)
		{
			APoolBehaviour* obj = GetWorld()->SpawnActor<APoolBehaviour>(PoolSettingsArray[i].PoolClass, SpawnTransform);
			obj->ReturnObject();
			ObjectArray.Add(obj);
		}

		PoolsMap.Add(PoolSettingsArray[i].PoolClass, ObjectArray);
	}
}

APoolBehaviour* APool::GetPoolObject(TSubclassOf<APoolBehaviour> PoolClass,FVector position, FRotator rotation)
{
	APoolBehaviour* PoolObject = nullptr;

	for (int i = 0; i < PoolsMap[PoolClass].Num(); i++)
	{
		if (!PoolsMap[PoolClass][i]->IsObjectActive())
		{
			PoolObject = PoolsMap[PoolClass][i];
			break;
		}
	}

	if (PoolObject == nullptr)
	{
		PoolObject = GetWorld()->SpawnActor<APoolBehaviour>(PoolClass, GetActorTransform());
		PoolsMap[PoolClass].Add(PoolObject);
	}

	PoolObject->OnEnableObject();
	PoolObject->SetActorLocation(position);
	PoolObject->SetActorRotation(rotation);

	return PoolObject;

}

void APool::BeginPlay()
{
	Super::BeginPlay();

	CreatePools();
}
