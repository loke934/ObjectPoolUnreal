#pragma once

#include "ObjectPoolPoolObjectInterface.generated.h"

UINTERFACE()
class UPoolObjectInterface : public UInterface
{
    GENERATED_BODY()
};

class IPoolObjectInterface
{
    GENERATED_BODY()

public:
    virtual bool IsObjectActive();
    virtual void ReturnObject();
    virtual void OnEnableObject();
};