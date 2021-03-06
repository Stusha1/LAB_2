#include "Bintree.h"


int test(char* name, char type) {

	node_tr* x = NULL;
	if (NULL != tree_s(x, 2)) {
		return 1;
	}
	x = tree_c(2);

	if (NULL == tree_s(x, 2)) {
		return 2;
	}

	tree_a(x, 20);
	if (NULL == tree_s(x, 20)) {
		return 3;
	}
	
	if (type == "w") {
		FILE* fp = fopen(name, type);
		if (x == NULL) {
			return 4;
		}
		serialize(x, fp);
		fclose(fp);
	}
	
	if (type == 'r') {
		node_tr* y = NULL;
		FILE* fn = fopen(name, type);
		if (fn == NULL) {
			return 5;
		}
		y = deserialize(y, fn);

		if (NULL == y) {
			return 6;
		}
	}

	return 0;
}


int main(int argc, char** argv) {
	
	return test(argv[1], argv[2]);
}
