#pragma once
#include "UE.h"

class ObjectFinder
{
public:
	static DWORD FindOffset(std::string ClassName, std::string VarName, bool Force = false)
	{
		auto ObjectClass = (UClass*)FindObject(ClassName, Force);

		if (ObjectClass != nullptr)
		{
			FField* next = ObjectClass->ChildProperties->Next;

			if (next == nullptr)
				return 0;

			auto fPropertyName = ObjectClass->ChildProperties->GetName();

			if (fPropertyName == VarName)
			{
				return *(uint32_t*)(__int64(ObjectClass->ChildProperties) + 0x4C);
			}

			while (next)
			{
				auto nextName = next->GetName();

				if (nextName == VarName) {
					return *(uint32_t*)(__int64(next) + 0x4C);
				}
				else {
					next = next->Next;
				}
			}
		}

		return 0;
	}
};