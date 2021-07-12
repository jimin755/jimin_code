#5     
2096_내려가기     
9251_LCS     


11051_이항계수2
![image](https://user-images.githubusercontent.com/57628980/125251425-4165e980-e332-11eb-873f-09fac9abacc0.png)
이것을 응용하여
dp[y][x] = dp[y-1][x-1]+dp[y][x-1] 
해당 점화식을 위한 가정 
1. 1<=y<=k , 2<=x<=n
2. 배열은 n*n의 2차원 배열
3. 배열은 모두 1로 초기화
4. y==x인 경우는 contiune
