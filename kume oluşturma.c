#include <stdio.h>
/*�ncelikle dizideki t�m elemanlar�n toplam�n� hesapl�yoruz.*/
int canPartition(int* nums, int numsSize) {
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    /*hedef+1 boyutunda bir dp dizisi olu�turuyoruz ve onu s�f�rlarla ba�lat�yoruz.*/
    if (sum % 2 != 0) {
        return 0;
    }
    int target = sum / 2;
    int dp[target+1];
    for (int i = 0; i <= target; i++) {
        dp[i] = 0;
    }
    /*giri� ��eleri kullan�larak olu�turulabilecek her olas� toplam i�in dp dizisini olu�turmam�za izin verir.*/
    dp[0] = 1;
    for (int i = 0; i < numsSize; i++) {
        for (int j = target; j >= nums[i]; j--) {
            dp[j] = dp[j] || dp[j - nums[i]];
        }
    }
    return dp[target];
}
/*giri� dizisindeki her bir ��eyi d�ng�ye sokar�z ve her ��e i�in, hedeften ��enin de�erine kadar dp dizisini d�ng�ye sokar�z.*/
/*giri� ��eleri kullan�larak olu�turulabilecek her olas� toplam i�in dp dizisini olu�turmam�za izin verir.*/
int main() {
    int nums[] = {1, 5, 11, 5};
    int numsSize = 4;
    if (canPartition(nums, numsSize)) {
        printf("The array can be divided into two subsets with equal sums\n");
    } else {
        printf("The array cannot be divided into two subsets with equal sums\n");
    }
    return 0;
}
