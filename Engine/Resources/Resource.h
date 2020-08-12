#pragma once
#include <string>

namespace NC
{
	class Resource
	{
	public:
		virtual bool Create(const std::string& name, void* data = nullptr) = 0;
		virtual void Destroy() = 0;
	};

}