#pragma once
#include "ListPrinter.h"
#include "BSTPrinter.h"
#include "VectorPrinter.h"
#include <algorithm>
#include <map>


class SolutionBase
{
public:
	SolutionBase();
	virtual void RunTest();
	virtual void RunTestCase();
protected:
	ListPrinter* listPrinter;
	BSTPrinter* bstPrinter;
	VectorPrinter* vecPrinter;
};

