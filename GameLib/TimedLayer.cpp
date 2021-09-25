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
		Timed* tim = dynamic_cast<Timed*>(t);
		res = tim->main(time); 
		if (res)
		{
			int out = recieve(*tim, res);
			if (out)
			{
				return out;
			}
		}
	}
	//std::cout << time << std::endl;
	return 0;
}

