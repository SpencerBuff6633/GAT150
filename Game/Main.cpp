#include "pch.h"
#include "Graphics/Texture.h"
#include "Graphics/Renderer.h"
#include "Resources/ResourceManager.h"
#include "Input/InputSystem.h"
#include "Math/Vector2.h"
#include "Core/Timer.h"

NC::ResourceManager resourceManager;
NC::Renderer renderer;
InputSystem inputSystem;
NC::FrameTimer timer;



namespace NC
{
using clock = std::chrono::high_resolution_clock;
using clock_duration = std::chrono::duration<clock::rep, std::milli>;
}

int main(int, char**)
{
	NC::clock::time_point start = NC::clock::now();
	inputSystem.Startup();
	renderer.Startup();
	renderer.Create("GAT150", 800, 600);

	NC::Texture* car = resourceManager.Get<NC::Texture>("cars.png", &renderer);
	NC::Texture* background = resourceManager.Get<NC::Texture>("background.png", &renderer);

	NC::Vector2 velocity;
	float angle = 0;
	NC::Vector2 position;
	position = { 400, 300 };
	SDL_Event event;
	bool quit = false;
	while (!quit)
	{
		SDL_PollEvent(&event);
		switch (event.type)
		{
		case SDL_QUIT:
			quit = true;
			break;
		}
		timer.Tick();

		inputSystem.Update();
		resourceManager.Update();

		//player controller
		if (inputSystem.GetButtonState(SDL_SCANCODE_A) == InputSystem::eButtonState::HELD)
		{
			angle = angle - 200.0f * timer.Deltatime();
		}
		if (inputSystem.GetButtonState(SDL_SCANCODE_D) == InputSystem::eButtonState::HELD)
		{
			angle = angle + 200.0f * timer.Deltatime();
		}

		NC::Vector2 force{ 0, 0 };
		if (inputSystem.GetButtonState(SDL_SCANCODE_W) == InputSystem::eButtonState::HELD)
		{
			force = NC::Vector2::forward * 1000.0f;
		}
		force = NC::Vector2::Rotate(force, NC::DegreesToRadians(angle));

		//physics
		//velocity += force * timer.Deltatime();
		//velocity = velocity * .9f;
		//position += velocity * timer.Deltatime();
		velocity = velocity + force * timer.Deltatime();
		velocity = velocity * 0.95f;
		position = position + velocity * timer.Deltatime();


		//draw
		renderer.BeginFrame();
		
		background->Draw({ 0, 0}, {1, 1}, 0);
		car->Draw({ 128, 120, 48, 98 }, position, {1, 1}, angle);
				
		renderer.EndFrame();
	}

	renderer.Shutdown();
	inputSystem.Shutdown();

	SDL_Quit();
	return 0;
}

