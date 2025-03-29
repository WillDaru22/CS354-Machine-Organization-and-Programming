//Program by William Wilson
//
//
////////////////////////////

int array[128][8];


int main(int argc, char *argv[]) {

    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 128; j += 64) {
	    for(int k = 0; k < 8; k++) {
	        array[j][k] = i + j + k;
	    }
	}
    }

}
