// Sample.h
class Sample
{
public:
	void foo();

	inline static int data = 0;	// ok.
								// declaration & definition
							
};



// Sample.cpp
#include "Sample.h"


void Sample::foo()
{
}