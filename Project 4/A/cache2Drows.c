//Progam by William Wilson
//
//
///////////////////////////

int array[3000][500];


int main(int argc, char *argv[]) {

    for(int i = 0; i < 3000; i++) {
        for(int j = 0; j < 500; j++) {
	    array[i][j] = i + j;
	}
    }
}
