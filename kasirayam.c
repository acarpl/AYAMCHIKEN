#include <stdio.h>
#include <conio.h> 

int main() {
    int harga_ayam[3] = {2500, 2000, 1500};
    char jenis_ayam[3] = {'D', 'P', 'S'};
    char* nama_ayam[3] = {"Dada", "Paha", "Sayap"};

    printf("GEROBAK FRIED CHICKEN\n");
    printf("---------------------\n");
    printf("Kode   Jenis   Harga\n");
    printf("---------------------\n");
    printf("D      Dada    Rp. 2500\n");
    printf("P      Paha    Rp. 2000\n");
    printf("S      Sayap   Rp. 1500\n");
    printf("---------------------\n");

    //banyak jenis item yang dibeli
    int banyak_jenis;
    printf("Banyak Jenis : ");
    scanf("%d", &banyak_jenis);

    int total_harga = 0;
    char jenis;
    int banyak_potong;
    int i, j;

   
    int pesanan[banyak_jenis][4]; //0: index jenis, 1: harga per item, 2: banyak item, 3: jumlah harga

    for (i = 0; i < banyak_jenis; i++) {
        printf("Jenis ke-%d\n", i + 1);
        printf("Jenis Potong [D/P/S] : ");
        scanf(" %c", &jenis);
        printf("Banyak Potong : ");
        scanf("%d", &banyak_potong);

        int index = -1;
        for (j = 0; j < 3; j++) {
            if (jenis_ayam[j] == jenis) {
                index = j;
                break;
            }
        }

        if (index != -1) {
            int harga_satuan = harga_ayam[index];
            int jumlah_harga = harga_satuan * banyak_potong;
            total_harga += jumlah_harga;

            //jumlah pesanan
            pesanan[i][0] = index;
            pesanan[i][1] = harga_satuan;
            pesanan[i][2] = banyak_potong;
            pesanan[i][3] = jumlah_harga;
        } else {
            printf("masukan input yang benar\n");
            i--;
        }
    }

    //tax
    int pajak = total_harga * 0.10;
    int total_bayar = total_harga + pajak;

    //menu grandtotal
    printf("\nGEROBAK FRIED CHICKEN\n");
    printf("------------------------------------------------------------------------------------\n");
    printf("No.   Jenis   Harga Satuan   Banyak Beli   Jumlah Harga\n");
    printf("------------------------------------------------------------------------------------\n");
    for (i = 0; i < banyak_jenis; i++) {
        int index = pesanan[i][0];
        printf("%-6d%-8sRp. %-12d%-12dRp. %-12d\n", 
               i + 1, nama_ayam[index], pesanan[i][1], 
               pesanan[i][2], pesanan[i][3]);
    }
    printf("------------------------------------------------------------------------------------\n");
    printf("Jumlah Bayar                      Rp. %d\n", total_harga);
    printf("Pajak 10%%                          Rp. %d\n", pajak);
    printf("Grand Total                       Rp. %d\n", total_bayar);

    getch(); 
    return 0;
}
