#pragma once
#include "ListPrinter.h"
#include "BSTPrinter.h"
#include "VectorPrinter.h"
class SolutionBase
{
public:
	SolutionBase();
protected:
	ListPrinter* listPrinter;
	BSTPrinter* bstPrinter;
	VectorPrinter* vecPrinter;
};

