#include "TimedLayer.hpp"

TimedLayer::TimedLayer()
{
	time = 0.0f;
	timer.restart();
}

int TimedLayer::main()
{
	time = (timer.getElapsedTime().asSeconds());
	timer.restart();
	int res = Layer::main();
	if (res) return res;
	std::set<Layer*> timed = Layer::getTag("Timed");
	for (Layer* t : timed) {
		res = dynamic_cast<Timed*>(t)->main(time); 
		if (res) return res;
	}
	std::cout << time << std::endl;
	return 0;
}

