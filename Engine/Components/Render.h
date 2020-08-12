#pragma once
#include "Component.h"

namespace NC
{
	class Render : public Component
	{
	public:
		virtual void Draw() = 0;
	};
}