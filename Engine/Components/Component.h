#pragma once
#include "Object/Object.h"

namespace NC
{
	class GameObject;

	class Component : public Object
	{
	public:
		virtual void Update() = 0;

		friend class GameObject;

	protected:
		GameObject* m_owner{ nullptr };
	};
}