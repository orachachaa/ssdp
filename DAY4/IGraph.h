// IGraph.h
#pragma once

class Subject;

struct IGraph
{
	virtual void update(int data, Subject* sender) = 0;
	virtual ~IGraph() {}
};

