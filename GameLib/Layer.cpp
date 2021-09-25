#include "Layer.hpp"

Layer::Layer()
{

}

sf::Window* Layer::getScreen()
{
	return screen;
}

void Layer::setScreen(sf::Window* screen)
{
	this->screen = screen;
}

void Layer::linkParent(Layer* parent)
{
	this->parent = parent;
	if (parent) 
	{
		screen = parent->getScreen();
	}
	else 
	{
		screen = nullptr;
	}
}

void Layer::refresh()
{
	createEntities();
	destroyEntities();
}

int Layer::update()
{
	status = 0;
	refresh();
	int out = main();
	return out;
}

int Layer::main()
{
	return updateChildren();
}

int Layer::updateChildren() {
	for (Layer* group : toUpdate)
	{
		int signal = group->update();
		if (signal)
		{
			int out = recieve(*group, signal);
			if (out)
			{
				return out;
			}
		}
	}
	return 0;
}

void Layer::killAll()
{
	killChildren();	
	tags.clear();
}

void Layer::killChildren()
{
	for (Layer* child : toUpdate)
	{
		child->killChildren();
		removeEntity(child);
	}
	destroyEntities();
}

void Layer::draw(sf::RenderTarget& target, sf::RenderStates states) const {

	states.transform *= getTransform();
	for (const Layer* group : toUpdate) {
		target.draw(*group, states);
	}
	render(target, states);
}
void Layer::render(sf::RenderTarget& target, sf::RenderStates states)const {

}
void Layer::createEntities() {
	while (!addEntityQueue.empty())
	{
		Layer* newEntity = addEntityQueue.front();
		newEntity->linkParent(this);
		if (!newEntity->tags.empty())
		{
			std::set<std::string> tagsToBeAdded = newEntity->tags;
			for (std::string tag : tagsToBeAdded)
			{
				entities[tag].insert(newEntity);
			}
		}
		toUpdate.insert(newEntity);
		addEntityQueue.pop();
	}
}

void Layer::destroyEntities() 
{
	while (!removeEntityQueue.empty())
	{
		Layer* garbageEntity = removeEntityQueue.front();
		if (!garbageEntity->tags.empty())
		{
			std::set<std::string> tagsToBeRemoved = garbageEntity->tags;
			for (std::string tag : tagsToBeRemoved)
			{
				if (entities.count(tag) > 0)
				{
					entities[tag].erase(garbageEntity);
				}
				else
				{
					std::cout << "Something really bad happened...\n";
				}
			}
			removeEntityQueue.pop();
		}
		toUpdate.erase(garbageEntity);
		
	}
}

bool Layer::addEntity(Layer* layer)
{
	this->addEntityQueue.push(layer);
	return true;
}

bool Layer::removeEntity(Layer* layer)
{
	this->removeEntityQueue.push(layer);
	return true;
}

const std::set<Layer*>& Layer::getTag(const std::string& tag)
{
	return entities[tag];
}

Layer& Layer::getUniqueEntity(const std::string& tag)
{
	if (entities[tag].size() != 1) 
	{
		throw	"Asked for unique object of tag:" + tag +
			", but found" +
			std::to_string(entities[tag].size()) +
			"items.";
	}
	return const_cast<Layer&> (**(entities[tag].begin()));
}

bool Layer::modifyEntityTag(Layer* layer, const std::string& oldTag, const std::string& newTag)
{
	if (!layer) 
	{
		return false;
	}
	if (oldTag == newTag)return true;
	entities[oldTag].erase(layer);
	entities[newTag].insert(layer);
	return true;
}

//This method will be called to prepare what to return to parent. 
//This method will not directly interrupt parent.
void Layer::notify(Layer& layer, int status) 
{
	
}

Layer::~Layer()
{
	//const std::string type = (tags.empty())?"NULL":tags.back();
	//std::cout << "trying to delete:{"<< type << std::endl;
	killAll();
	//std::cout << "}deleted " <<type<< " successfully!" << std::endl;
}