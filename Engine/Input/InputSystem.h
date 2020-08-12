#pragma once
#include "Core/System.h"

class InputSystem : public NC::System
{
public:
	enum class eButtonState
	{
		IDLE,
		PRESSED,
		HELD,
		RELEASED
	};

	// Inherited via System
	virtual bool Startup() override;
	virtual void Shutdown() override;
	virtual void Update() override;

	eButtonState GetButtonState(int id);
	bool GetButtonDown(int id);
	bool GetPreviousButtonDown(int id);


protected:
	Uint8* m_keystate;
	Uint8* m_prevKeystate;
	int m_numKeys;

};