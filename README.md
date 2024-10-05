# AYAMCHIKEN

Program ini adalah aplikasi kasir sederhana untuk "Gerobak Fried Chicken" yang menggunakan bahasa pemrograman C. Berikut adalah penjelasan dari setiap bagian program:

### 1. Deklarasi dan Inisialisasi Variabel
```c
int harga_ayam[3] = {2500, 2000, 1500};
char jenis_ayam[3] = {'D', 'P', 'S'};
char* nama_ayam[3] = {"Dada", "Paha", "Sayap"};
```
- `harga_ayam`: Array yang menyimpan harga tiap potongan ayam (Dada, Paha, Sayap).
- `jenis_ayam`: Array yang menyimpan kode jenis ayam (D untuk Dada, P untuk Paha, S untuk Sayap).
- `nama_ayam`: Array pointer yang menyimpan nama jenis ayam.

### 2. Menampilkan Menu
```c
printf("GEROBAK FRIED CHICKEN\n");
printf("---------------------\n");
printf("Kode   Jenis   Harga\n");
printf("---------------------\n");
printf("D      Dada    Rp. 2500\n");
printf("P      Paha    Rp. 2000\n");
printf("S      Sayap   Rp. 1500\n");
printf("---------------------\n");
```
Bagian ini menampilkan daftar menu ayam lengkap dengan kode, jenis, dan harga.

### 3. Input Banyak Jenis Ayam yang Dibeli
```c
int banyak_jenis;
printf("Banyak Jenis : ");
scanf("%d", &banyak_jenis);
```
- User diminta memasukkan berapa banyak jenis ayam yang akan dibeli.

### 4. Proses Input untuk Setiap Jenis Ayam
```c
for (i = 0; i < banyak_jenis; i++) {
    printf("Jenis ke-%d\n", i + 1);
    printf("Jenis Potong [D/P/S] : ");
    scanf(" %c", &jenis);
    printf("Banyak Potong : ");
    scanf("%d", &banyak_potong);
    ...
}
```
- Program meminta input jenis ayam (D/P/S) dan jumlah potongan untuk setiap jenis yang dipilih.

### 5. Pencarian Index Jenis Ayam
```c
for (j = 0; j < 3; j++) {
    if (jenis_ayam[j] == jenis) {
        index = j;
        break;
    }
}
```
- Program melakukan pencarian di array `jenis_ayam` untuk menentukan index dari jenis ayam yang dimasukkan.

### 6. Menyimpan Pesanan dan Menghitung Total Harga
```c
int pesanan[banyak_jenis][4]; 
// 0: index jenis, 1: harga per item, 2: banyak item, 3: jumlah harga

pesanan[i][0] = index;
pesanan[i][1] = harga_ayam[index];
pesanan[i][2] = banyak_potong;
pesanan[i][3] = harga_ayam[index] * banyak_potong;
```
- Program menyimpan data pesanan dalam array `pesanan`. Setiap item menyimpan index jenis ayam, harga per item, jumlah potongan, dan total harga untuk item tersebut.

### 7. Menghitung Pajak dan Grand Total
```c
int pajak = total_harga * 0.10;
int total_bayar = total_harga + pajak;
```
- Pajak sebesar 10% dari total harga ditambahkan ke total harga untuk mendapatkan `grand total`.

### 8. Menampilkan Ringkasan Pesanan
```c
printf("\nGEROBAK FRIED CHICKEN\n");
printf("No.   Jenis   Harga Satuan   Banyak Beli   Jumlah Harga\n");
for (i = 0; i < banyak_jenis; i++) {
    int index = pesanan[i][0];
    printf("%-6d%-8sRp. %-12d%-12dRp. %-12d\n", i + 1, nama_ayam[index], pesanan[i][1], pesanan[i][2], pesanan[i][3]);
}
```
- Menampilkan daftar pesanan dengan nomor urut, jenis ayam, harga satuan, jumlah beli, dan total harga per jenis.

### 9. Menampilkan Jumlah Bayar, Pajak, dan Grand Total
```c
printf("Jumlah Bayar                      Rp. %d\n", total_harga);
printf("Pajak 10%%                          Rp. %d\n", pajak);
printf("Grand Total                       Rp. %d\n", total_bayar);
```
- Menampilkan total harga, pajak 10%, dan jumlah total yang harus dibayar.

### Kesimpulan
Program ini secara efektif mencatat dan menghitung total harga pesanan ayam goreng berdasarkan jenis dan jumlah potongan yang dipilih oleh pengguna. Pajak 10% ditambahkan ke total harga untuk mendapatkan jumlah akhir yang harus dibayar.
