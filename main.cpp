#include <iostream>
#include <stdlib.h>
#include <time.h>


void fun_ini(int* ms_2, int x) {
	int id = 0;
	int id_2 = 0;
	int id_3 = 0;
	int id_4 = 0;
	for (int i = 0; i < x; i++) {
		if (ms_2[i] == 2 || ms_2[i] == 3 || ms_2[i] == 5 || ms_2[i] == 7) {
			continue;
		}
		if (ms_2[i] / 2 == 0 || ms_2[i] / 3 == 0 || ms_2[i] / 5 == 0 || ms_2[i] / 7 == 0) {
			ms_2[i] = 0;
		}
	 }
	
}
void fun_zap(int* ms_1,int x) {
	for (int i = 0; i < x; i++) {
		ms_1[i] = rand() % 9 +1;
	}
}
void fun_zap_2(int* ms_1, int x) {
	for (int i = 0; i < x; i++) {
		ms_1[i] = rand() % 50 - 25;
	}
}

void fun_print(int* ms_1, int x) {
	for (int i = 0; i < x; i++) {
		std::cout << ms_1[i] << " ";
	}
}
void fun_element(int* ms_1, int x, int num) {
	ms_1 = (int*)realloc(ms_1, (x + 1)*sizeof(int));
	ms_1[x] = num;
}

void fun_elem_indx(int* ms_1, int x, int num, int id) {
	ms_1 = (int*)realloc(ms_1, (x + 1) * sizeof(int));
	x++;
	for (int i = x; i > id-1;i--) {
		ms_1[i] = ms_1[i-1];
	}
	ms_1[id-1] = num;
}

void fun_del(int* ms_1, int x, int id) {
	for (int i = id-1; i < x-1; i++) {
		ms_1[i] = ms_1[i + 1];
	}
	ms_1 = (int*)realloc(ms_1, (x - 1) * sizeof(int));
}


int* fun_ms(int* ms_2, int x,int* ms_3) {
	int ind = 0;
	int ind_2 = 0;
	int ind_3 = 0;
	int ind_4 = 0;
	
	
	ind = 0;
	for (int i = 0; i < x; i++) {
		if (ms_2[i] != 0) {
			ms_3[ind] = ms_2[i];
			ind++;
		}
	}

	return ms_3;
}

int main() {
	srand(time(NULL));
	int flag_menu = 0;

	do {
		std::cout << "\n" << "Vuberete nomer zadani9 : " << "\n";
		std::cin >> flag_menu;

		if (flag_menu == 1) {

			int x;
			int num;
			int id = 0;
			std::cout << "\n" << "Vvedite razmer massiva" << "\n";
			std::cin >> x;
			int flag_de = 0;
			int* ms_1 = (int*)calloc(x, sizeof(int));
			do {
				std::cout << "\n" << "Vuberete deistvie : 1-inicil massiva, 2-pi4at massiva, 3-dell mass, 4-dobav element, 5-vstavka element, 6-del element 7-zaponenie randomon" << "\n";
				std::cin >> flag_de;

				if (flag_de == 1) {
					std::cout << "\n" << "Inicial massiva" << "\n";
					
					//fun_ini(ms_1, x);
					std::cout << "\n" << "Zaferheno" << "\n";
				}
				if (flag_de == 7) {
					std::cout << "\n" << "Zapolnenie massiva " << "\n";
					fun_zap(ms_1, x);
					std::cout << "\n" << "Zaverheno" << "\n";
				}
				if (flag_de == 2) {
					std::cout << "\n" << "Vuvod massiva :" << "\n";
					fun_print(ms_1, x);
					std::cout << "\n" << "Zaverheno" << "\n";
				}

				if (flag_de == 3) {
					std::cout << "\n" << "Dell mass" << "\n";
					free(ms_1);
					std::cout << "\n" << "zaverheno" << "\n";
				}
				if (flag_de == 4) {
					std::cout << "\n" << "Dobavit element , vvidite num :" << "\n";
					std::cin >> num;
					fun_element(ms_1, x, num);
					x++;
					std::cout << "\n" << "zaverheno" << "\n";
				}
				if (flag_de == 5) {
					std::cout << "\n" << "dobav element po indexy, vvedite element : " << "\n";
					std::cin >> num;
					std::cout << "\n" << "Vvedite index vstavki : " << "\n";
					std::cin >> id;
					fun_elem_indx(ms_1, x, num, id);
					x++;
				}
				if (flag_de == 6) {
					std::cout << "\n" << "Dell element " << "\n";
					std::cout << "\n" << "vvedite index : " << "\n";
					std::cin >> id;
					fun_del(ms_1, x, id);
					x--;
				}

			} while (flag_de != 0);



		}


		if (flag_menu == 2) {
			std::cout << "\n" << "Zadaca nomer 2" << "\n";
			int x;
			int num;
			int id = 0;
			std::cout << "\n" << "Vvedite razmer massiva" << "\n";
			std::cin >> x;

			int* ms_2 = (int*)calloc(x, sizeof(int));

			int* ms_t = (int*)calloc(x, sizeof(int));
			std::cout << "\n" << "Vvedenii massiv" << "\n";
			fun_zap(ms_2, x);
			fun_print(ms_2, x);
			std::cout << "\n" << "Izmenenni massiv" << "\n";
			 fun_ms(ms_2, x,ms_t);

			fun_print(ms_t, x);
			
		}

		if (flag_menu == 3) {
			std::cout << "\n" << "Zadaca nomer 3 " << "\n";
			std::cout << "\n" << "Dan massiv : " << "\n";
			int ms_5[15] = { 0 };
			for (int i = 0; i < 15; i++) {
				ms_5[i] = rand() % 12 - 5;
				std::cout << ms_5[i] << " ";
			}
			int num_o = 0;
			int num_n = 0;
			int num_p = 0;

			for (int i = 0; i < 15; i++) {
				if (ms_5[i] > 0) {
					num_p++;
				}
				if (ms_5[i] == 0) {
					num_n++;
				}
				if (ms_5[i] < 0) {
					num_o++;
				}
			}


			int* ms_d1 = (int*)calloc(num_p, sizeof(int));
			int* ms_d2 = (int*)calloc(num_n, sizeof(int));
			int* ms_d3 = (int*)calloc(num_o, sizeof(int));
			int ind = 0;
			int ind_2 = 0;
			for (int i = 0; i <15; i++) {
				if (ms_5[i] > 0) {
					ms_d1[ind] = ms_5[i];
					ind++;
				}
				if (ms_5[i] < 0) {
					ms_d3[ind_2] = ms_5[i];
					ind_2++;
				
				}
			}

			std::cout << "\n" << "Polu4enie massivu : " << "\n";
			fun_print(ms_d1, num_p);
			std::cout << "\n";
			fun_print(ms_d2, num_n);
			std::cout << "\n";
			fun_print(ms_d3, num_o);

		}

		if (flag_menu == 4) {
			int x = 0;
			int x_2 = 0;
			std::cout << "\n" << "Vvedite razmer 1-ogo massiva : " << "\n";
			std::cin >> x;
			std::cout << "\n" << "Vvedite rezmer 2-ogo maasiva : " << "\n";
			std::cin >> x_2;
			
			int* ms_d1 = (int*)calloc(x, sizeof(int));
			int* ms_d2 = (int*)calloc(x_2, sizeof(int));
			int x_3;
			fun_zap_2(ms_d1, x);
			fun_zap_2(ms_d2, x_2);

			std::cout << "\n" << "Polu4 maasivu :" << "\n";
			fun_print(ms_d1, x);
			std::cout << "\n";
			fun_print(ms_d2, x_2);
			int id = 0;
			for (int i = 0; i < x; i++) {
				for (int j = 0; j < x_2; j++) {
					if (ms_d1[i] > 0 && ms_d1[i] == ms_d2[j]) {
						id++;
					}
				}
			}
			int id_2 = 0;
			int id_3=0;

			for (int i = 0; i < x; i++) {
				if (ms_d1[i] > 0) {
					id_2++;
				}
			}
			for (int i = 0; i < x_2; i++) {
				if (ms_d2[i] > 0) {
					id_3++;
				}
			}

			x_3 = id_2 + id_3 - id;

			int* ms_d3 = (int*)calloc(x_3, sizeof(int));
			int ind = 0;
			for (int i = 0; i < x; i++) {
				if (ms_d1[i] > 0) {
					ms_d3[ind] = ms_d1[i];
					ind++;
				}
			}
			for (int i = 0; i < x_2; i++) {
				for (int j = 0; j < ind; j++) {
					if (ms_d2[i] > 0 && ms_d2[i] != ms_d3[j]) {
						ms_d3[ind] = ms_d2[i];
						ind++;
					}
				}
			}
			std::cout << "\n" << "Rezult : " << "\n";
			fun_print(ms_d3, x_3);


			//free(ms_d1);
			//free(ms_d2);
			//free(ms_d3);

		}

		if (flag_menu = 5) {
			std::cout << "\n" << "Zadaca nomer 2" << "\n";
			int x;
			int num;
			int id = 0;
			std::cout << "\n" << "Vvedite razmer massiva" << "\n";
			std::cin >> x;

			int* ms_2 = (int*)calloc(x, sizeof(int));

			fun_zap(ms_2, x);
			std::cout << "\n" << "Polu4 massiv :" << "\n";
			fun_print(ms_2, x);

			std::cout << "\n" << "Result :: " << "\n";

			fun_ini(ms_2, x);
			fun_print(ms_2, x);

		}



	} while (flag_menu != 0);



}