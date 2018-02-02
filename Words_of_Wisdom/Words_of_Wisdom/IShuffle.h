#pragma once

class IShuffle
{
public:
	virtual void shuffle() = 0;
	virtual void shuffle(unsigned int i, unsigned int j) = 0;
};