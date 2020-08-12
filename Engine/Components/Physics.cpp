#include "pch.h"
#include "Physics.h"
#include "Object/GameObject.h"

bool NC::Physics::Create(void* data)
{
	return false;
}

void NC::Physics::Destroy()
{
}

void NC::Physics::Update()
{
	m_velocity = m_velocity + m_force;// *timer.DeltaTime();
	m_velocity = m_velocity * m_drag;
	m_owner->m_transform.position = m_owner->m_transform.position + m_velocity;// *timer.DeltaTime();

}
