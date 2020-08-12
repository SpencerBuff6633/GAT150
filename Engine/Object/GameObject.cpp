#include "pch.h"
#include "GameObject.h"
#include "Components/Component.h"
#include "Components/Render.h"

bool NC::GameObject::Create(void* data)
{
	return false;
}

void NC::GameObject::Destroy()
{
	RemoveAllComponent();
}

void NC::GameObject::AddComponent(Component* component)
{
	component->m_owner = this;
	m_components.push_back(component);
}

void NC::GameObject::RemoveComponent(Component* component)
{
	auto iter = std::find(m_components.begin(), m_components.end(), component);
		if (iter != m_components.end())
		{
			(*iter)->Destroy();
			delete (*iter);
		}
}

void NC::GameObject::RemoveAllComponent()
{
	for (auto component : m_components)
	{
		component->Destroy();
		delete component;
	}
	m_components.clear();
}

void NC::GameObject::Update()
{
	for (auto component : m_components)
	{
		component->Update();
	}
}

void NC::GameObject::Draw()
{
	Render* component = GetComponent<Render>();
	if (component)
	{
		component->Draw();
	}

}
