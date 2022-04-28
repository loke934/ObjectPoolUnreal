#include "ObjectPoolPoolObject.h"
#include "Components/SphereComponent.h"

APoolObject::APoolObject()
{
	Collision = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
	RootComponent = Collision;
	
}