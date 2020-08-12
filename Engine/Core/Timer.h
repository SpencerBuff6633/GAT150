#pragma once
#include <chrono>

namespace NC {
	class Timer
	{
	public:
		using clock = std::chrono::high_resolution_clock;
		using clock_duration = std::chrono::duration<clock::rep, std::nano>;
		
	public:
		Timer() : m_timePoint(clock::now()) {}

		void Reset();
		clock::rep ElapsedTicks();
		clock::rep TicksPerSecond();

		double ElapsedSeconds();

	protected:
		clock::time_point m_timePoint;
	};

	class FrameTimer : public Timer
	{
	public:
		void Tick();
		float Deltatime() { return dt; };

	protected:
		float dt{ 0 };
	};
}