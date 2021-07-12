#5     
2096_내려가기       
maxDp[y][0] = max(maxDp[y-1][0], maxDp[y-1][1])          
maxDp[y][1] = max(maxDp[y-1][0], max(maxDp[y-1][1], maxDp[y-1][2]))      
maxDp[y][2] = max(maxDp[y-1][2], maxDp[y-1][1])        

minDp[y][0] = min(minDp[y-1][0], minDp[y-1][1])        
minDp[y][1] = min(minDp[y-1][0], min(minDp[y-1][1], maxDp[y-1][2]))      
minDp[y][2] = min(minDp[y-1][2], minDp[y-1][1])     
이다    

하지만 이렇게만 하면 메모리 초과가 뜬다     

그래서 저렇게 보면 dp에서도 전에 y와 y-1번째 배열들만 사용하기 때문에      
y=1로 고정하여 배열 원소의 개수를 6개로 고정하고    

점화식 후 y=1인 배열의 값들을 y=0인 배열에 복사해준다.    

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
