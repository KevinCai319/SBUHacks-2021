#include "Handler.hpp"


Handler::Handler(Layer* defaultScene):
	running(defaultScene),
	defaultScene(*defaultScene->tags.begin()),
	runningScene(*defaultScene->tags.begin())
{
	addEntity(defaultScene);
}

int Handler::main()
{
	int status = running->update();
	if (status) 
	{
		int out = recieve(*running,status);
		if (out) 
		{
			return out;
		}
	}
	return 0;
}

void Handler::switchScene(Layer* active)
{
	if (running == active) {
		throw std::exception("added duplicate scene");
	}
	removeEntity(running);
	destroyEntities();
	addEntity(active);
	createEntities();
	running = active;
	runningScene = *running->tags.begin();
}
Handler::~Handler() {
	//delete running;
}

