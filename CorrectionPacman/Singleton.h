#pragma once
#include "CoreMinimal.h"

template<typename T>
class Singleton
{
protected:
	static T instance;

public:
	static inline T& GetInstance()
	{
		return instance;
	}
};

template<typename T>
T Singleton<T>::instance;

