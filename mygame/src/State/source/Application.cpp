#include "..\headers\Application.h"

Application::Application() :
Window(sf::VideoMode(1366, 768), "SFML Application", sf::Style::Fullscreen),
mStateStack(Window, textures, fonts, player)
{
	textures.load(Textures::MainMenu, "../media/textures/background/PNG/menu/menu.png");
	fonts.load(Fonts::MainMenu, "../media/fonts/menu/menu.ttf");

	registerStates();
	mStateStack.pushState(States::Menu);
}

void Application::run()
{
	sf::Clock clock;
	while (Window.isOpen())
	{
		sf::Time deltaTime = clock.restart();
		update(deltaTime);
		render();
		processEvents();
	}
	if (mStateStack.isEmpty())
		Window.close();
}

void Application::registerStates()
{
	mStateStack.registerState<MenuState>(States::Menu);
	mStateStack.registerState<GameState>(States::Game);
	//mStateStack.registerState<PauseState>(States::Pause);
}

void Application::processEvents()
{
	sf::Event event;
	while (Window.pollEvent(event))
	{
		mStateStack.handleEvent(event);
		
		if (event.type == sf::Event::Closed)
			Window.close();
	}
}

void Application::update(sf::Time deltaTime)
{
	mStateStack.update(deltaTime);
}

void Application::render()
{
	Window.clear();
	mStateStack.draw();
	Window.display();
}
