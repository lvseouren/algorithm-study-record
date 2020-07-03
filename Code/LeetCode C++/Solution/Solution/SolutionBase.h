#pragma once
#include "ListPrinter.h"
#include "BSTPrinter.h"
class SolutionBase
{
public:
	SolutionBase();
protected:
	ListPrinter* listPrinter;
	BSTPrinter* bstPrinter;
};

