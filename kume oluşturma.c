#include <stdio.h>
/*öncelikle dizideki tüm elemanlarýn toplamýný hesaplýyoruz.*/
int canPartition(int* nums, int numsSize) {
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    /*hedef+1 boyutunda bir dp dizisi oluþturuyoruz ve onu sýfýrlarla baþlatýyoruz.*/
    if (sum % 2 != 0) {
        return 0;
    }
    int target = sum / 2;
    int dp[target+1];
    for (int i = 0; i <= target; i++) {
        dp[i] = 0;
    }
    /*giriþ öðeleri kullanýlarak oluþturulabilecek her olasý toplam için dp dizisini oluþturmamýza izin verir.*/
    dp[0] = 1;
    for (int i = 0; i < numsSize; i++) {
        for (int j = target; j >= nums[i]; j--) {
            dp[j] = dp[j] || dp[j - nums[i]];
        }
    }
    return dp[target];
}
/*giriþ dizisindeki her bir öðeyi döngüye sokarýz ve her öðe için, hedeften öðenin deðerine kadar dp dizisini döngüye sokarýz.*/
/*giriþ öðeleri kullanýlarak oluþturulabilecek her olasý toplam için dp dizisini oluþturmamýza izin verir.*/
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
