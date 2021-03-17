#include "common/include_header.h"

struct IntDouble{
	int x;
	double y;
};

int main(){
	LOG_INFO("size of IntDouble "<< sizeof(IntDouble) );
}