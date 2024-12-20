#include <stdio.h>
#include <string.h>

struct Menu {
    int stt;
    char tenmon[100];
    int gia;
};

struct Menu menu[5] = {
    {1, "ga", 100},
    {2, "vit", 80},
    {3, "cha", 15},
    {4, "nem", 50},
    {5, "ruou", 35}
};

int main() {
    int kichThuoc = 5;
    int chon;
    int kiemtra = -1;

    do {
        printf("\n--- MENU ---\n");
        printf("1. In ra danh sach cac mon an\n");
        printf("2. Them mot mon an vao cuoi\n");
        printf("3. Sua thong tin mon an o vi tri chi dinh\n");
        printf("4. Xoa mon an cuoi cung\n");
        printf("5. Sap xep mon an theo gia tang dan\n");
        printf("6. Tim kiem mon an theo ten\n");
        printf("7. Thoát\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &chon);
        getchar(); 

        switch (chon) {
            case 1: 
                for (int i = 0; i < kichThuoc; i++) {
                    printf(" thong tin mon an thu %d\n",i+1);
				        printf ("stt : ");
					    printf("%d\n",menu[i].stt);
					    printf ("ten mon : ");
					    printf("%s\n",menu[i].tenmon);
					    printf ("gia : ");
					    printf("%d K\n",menu[i].gia);
                }
                break;

            case 2: 
                
                    printf("Nhap ten mon muon them: ");
                    fgets(menu[kichThuoc].tenmon, sizeof(menu[kichThuoc].tenmon), stdin);
                    menu[kichThuoc].tenmon[strcspn(menu[kichThuoc].tenmon, "\n")] = '\0'; 

                    printf("Nhap gia tien: ");
                    scanf("%d", &menu[kichThuoc].gia);
                    menu[kichThuoc].stt = kichThuoc + 1;
                    kichThuoc++;
                    for (int i = 0; i < kichThuoc; i++) {
                    printf(" thong tin mon an thu %d\n",i+1);
				        printf ("stt : ");
					    printf("%d\n",menu[i].stt);
					    printf ("ten mon : ");
					    printf("%s\n",menu[i].tenmon);
					    printf ("gia : ");
					    printf("%d K\n",menu[i].gia);
                }
                break;

            case 3: 
                printf("Nhap vi tri mon muon sua : ");
                int vitri;
                scanf("%d", &vitri);
                getchar(); 

                if (vitri >= 1 && vitri <= kichThuoc) {
                    printf("Nhap ten mon moi: ");
                    fgets(menu[vitri - 1].tenmon, sizeof(menu[vitri - 1].tenmon), stdin);
                    menu[vitri - 1].tenmon[strcspn(menu[vitri - 1].tenmon, "\n")] = '\0';

                    printf("Nhap gia tien moi: ");
                    scanf("%d", &menu[vitri - 1].gia);
                    for (int i = 0; i < kichThuoc; i++) {
                    printf("thong tin mon an thu %d\n",i+1);
				        printf ("stt : ");
					    printf("%d\n",menu[i].stt);
					    printf ("ten mon : ");
					    printf("%s\n",menu[i].tenmon);
					    printf ("gia : ");
					    printf("%d K\n",menu[i].gia);
					    }
                } else {
                    printf("Vi tri khong hop le !\n");
                }
                break;

            case 4: 
                    kichThuoc--;
                    printf("Da xoa mon an cuoi cung.\n");
                    for (int i = 0; i < kichThuoc; i++) {
                    printf(" thong tin mon an thu %d\n",i+1);
				        printf ("stt : ");
					    printf("%d\n",menu[i].stt);
					    printf ("ten mon : ");
					    printf("%s\n",menu[i].tenmon);
					    printf ("gia : ");
					    printf("%d K\n",menu[i].gia);
               			}
                break;

            case 5: 
                for (int i = 0; i < kichThuoc - 1; i++) {
                    for (int j = 0; j < kichThuoc - i - 1; j++) {
                        if (menu[j].gia > menu[j + 1].gia) {
                            struct Menu temp = menu[j];
                            menu[j] = menu[j + 1];
                            menu[j + 1] = temp;
                        }
                    }
                }
                printf("Menu da duoc sap xep theo gia tang dan.\n");
                 for (int i = 0; i < kichThuoc; i++){ 
                if(menu[i].stt==0){
                    break;
                }
                printf("In thong tin mon an thu %d\n",i+1);
				        printf ("stt : ");
					    printf("%d\n",menu[i].stt);
					    printf ("ten mon : ");
					    printf("%s\n",menu[i].tenmon);
					    printf ("gia : ");
					    printf("%d K\n",menu[i].gia);
            }
                
                break;

            case 6:
                printf("Nhap ten mon an can tim: ");
                char timKiem[100];
                fgets(timKiem, sizeof(timKiem), stdin);
                timKiem[strcspn(timKiem, "\n")] = '\0'; 
                for (int i = 0; i < kichThuoc; i++) {
                    if (strcmp(menu[i].tenmon, timKiem) == 0) {
                        kiemtra = i;
                        break;
                    }
                }

                if (kiemtra != -1) {
                    printf("Mon an '%s' nam o vi tri: %d\n", timKiem, kiemtra + 1);
                } else {
                    printf("Khong tim thay mon an '%s'.\n", timKiem);
                }
                break;

            case 7: 
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop l?!\n");
                break;
        }
    } while (chon != 7);

    return 0;
}

