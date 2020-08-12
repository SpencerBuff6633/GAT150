#include "pch.h"
#include "ResourceManager.h"

namespace NC
{
	bool NC::ResourceManager::Startup()
	{
		return false;
	}

	void NC::ResourceManager::Shutdown()
	{
	}

	void NC::ResourceManager::Update()
	{
	}
	void ResourceManager::RemoveAll()
	{
		for (auto resource : m_resources)
		{
			resource.second->Destroy();
			delete resource.second;
		}

		m_resources.clear();
	}
}
