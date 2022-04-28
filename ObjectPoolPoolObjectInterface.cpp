#include "ObjectPoolPoolObjectInterface.h"

bool IPoolObjectInterface::IsObjectActive()
{
	return false;
}

void IPoolObjectInterface::ReturnObject()
{
}

void IPoolObjectInterface::OnEnableObject()
{
}
