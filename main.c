#include <stdio.h>

// irem dinç
// 2420161075
// https://www.btkakademi.gov.tr/portal/certificate/ZA1UrdeLOa

void dizi_yazdir(int dizi[], int BOYUT) {
    int i;
    for (i = 0; i < BOYUT; i++) {
        printf("%3d", dizi[i]);
    }
    printf("\n");
}

void takas(int *ap, int *bp) {
    int gecici = *ap;
    *ap = *bp;
    *bp = gecici;
}

int indis_min_hesapla(int dizi[], int BOYUT, int bas_ind) {
    int i;
    int min_eleman = dizi[bas_ind];
    int min_ind = bas_ind;

    for (i = bas_ind + 1; i < BOYUT; i++) {
        if (dizi[i] < min_eleman) {
            min_eleman = dizi[i];
            min_ind = i;
        }
    }
    return min_ind;
}

void secmeli_sirala(int dizi[], int BOYUT) {
    int i;
    int ind_min;

    for (i = 0; i < BOYUT - 1; i++) {
        ind_min = indis_min_hesapla(dizi, BOYUT, i);
        takas(dizi + i, dizi + ind_min);
        printf("iter.%2d: ", i + 1);
        dizi_yazdir(dizi, BOYUT);
    }
}

int ikili_arama(int dizi[], int BOYUT, int search, int ilk_ind, int son_ind) {
    int orta_ind = (ilk_ind + son_ind) / 2;

    if (search == dizi[orta_ind]) {
        return orta_ind;
    }
    else if (search > dizi[orta_ind] && (son_ind - ilk_ind) > 0) {
        return ikili_arama(dizi, BOYUT, search, orta_ind + 1, son_ind);
    }
    else if (search < dizi[orta_ind] && (son_ind - ilk_ind) > 0) {
        return ikili_arama(dizi, BOYUT, search, ilk_ind, orta_ind - 1);
    }
    else {
        return -1;
    }
}

int main() {
    int A[] = {12, 2, 91, 38, 5, 72, 23, 8, 56, 16};
    int N = sizeof(A) / sizeof(A[0]);

    int aranan, sonuc;

    printf("Orijinal dizi: ");
    dizi_yazdir(A, N);

    secmeli_sirala(A, N);

    printf("Sirali dizi:   ");
    dizi_yazdir(A, N);

    printf("Aranacak deger: ");
    scanf("%d", &aranan);

    sonuc = ikili_arama(A, N, aranan, 0, N - 1);

    if (sonuc == -1)
        printf("Aranan %d dizide bulunamadi!\n", aranan);
    else
        printf("Aranan %d, dizinin %d. indisinde bulundu!\n", aranan, sonuc);

    return 0;
}




