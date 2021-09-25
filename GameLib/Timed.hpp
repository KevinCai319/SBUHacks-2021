#pragma once
#include "Layer.hpp"
class Timed : public virtual Layer
{
	public: 
		Timed(); 
		virtual int main(float dt) = 0; 
	protected:
};

