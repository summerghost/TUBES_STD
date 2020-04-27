#include <iostream>
//include parrent here//
#include "listChild.h"

using namespace std;

typedef struct Relasi* relateAddress;

struct relasi {
	//address parrent disini//
	addressParent warteg;
	addressChild mamin;
	relateAddress next;
	relateAddress prev;
};

struct listRelasi {
	relateAddress first;
	relateAddress last;
};
