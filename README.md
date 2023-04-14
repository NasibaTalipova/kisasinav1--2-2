# kisasinav1--2-2
##2 question
Toplam tek ise, dizinin eşit toplamlarla iki alt kümeye bölünemeyeceğini biliyoruz, bu nedenle 0 döndürürüz. Aksi takdirde, her alt kümenin toplamı olması gerektiğinden hedef değerimizi toplamın yarısı olarak belirleriz. /2.

Ardından, hedef+1 boyutunda bir dp dizisi oluşturuyoruz ve onu sıfırlarla başlatıyoruz. Toplamı 0 olan bir altkümeyi her zaman oluşturabileceğimiz için dp[0] = 1 yaparız.

Son olarak, giriş dizisindeki her bir öğeyi döngüye sokarız ve her öğe için, hedeften öğenin değerine kadar dp dizisini döngüye sokarız. Her adımda, dp[j]'nin değerini dp[j] || dp[j - sayılar[i]]. Bu, dp[j] zaten doğruysa veya dp[j - nums[i]] doğruysa, dp[j]'yi doğru olarak ayarladığımız anlamına gelir. Bu, giriş öğeleri kullanılarak oluşturulabilecek her olası toplam için dp dizisini oluşturmamıza izin verir.

Sonunda, eğer dp[hedef] doğruysa, dizinin eşit toplamlarla iki altkümeye bölünebileceğini biliyoruz. Aksi takdirde, dizi eşit toplamlarla iki alt kümeye bölünemez.

Bu kodu test etmek için, programı farklı girdi dizileriyle çalıştırmayı ve dizinin eşit toplamlarla iki alt kümeye bölünüp bölünemeyeceğini doğru bir şekilde tanımlayıp tanımlamadığını görmek için çıktıyı kontrol etmeyi deneyebilirsiniz. Programın çıktısını nasıl etkilediğini görmek için giriş dizisini değiştirmeyi de deneyebilirsiniz.
