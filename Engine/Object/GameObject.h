#pragma once
#include "Object.h"
#include "Math/Transform.h"
#include <vector>

namespace NC
{
	class Component; 

	class GameObject : public Object
	{
	public:
		virtual bool Create(void* data = nullptr) override;
		virtual void Destroy() override;

		void AddComponent(Component* component);
		void RemoveComponent(Component* component);
		void RemoveAllComponent();

		void Update();
		void Draw();

		template<typename T>
		T* GetComponent()
		{
			T* result{ nullptr };
			for (auto component : m_components)
			{
				result = dynamic_cast<T*>(component);
				if (result) break;
			}
			return result;
		}

		friend class Component;
		friend class Physics;

	protected:
		Transform m_transform;
		std::vector<Component*> m_components;
	};
 }