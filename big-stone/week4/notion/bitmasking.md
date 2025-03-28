# 4주차 비트 마스킹 개념
## 1. 이진수
### 1-1. 10진수를 2진수로, 2진수를 10진수로 바로 나타내는 연습을 하자.
- 0001(2)=1	0101(2)=5
- 0010(2)=2	0110(2)=6
- 0011(2)=3	0111(2)=7
- 0100(2)=4	1000(2)=

### 1-2. Bool 배열로 나타내는 2진수의 활용
- 0101(2)=5 는 [false,true,false,true] 꼴의 bool 배열의 값을 바로 나타내는것과 같다.

## 2. 비트연산자
### 2-1. 비트연산자의 기초 +,-
+1001(2)
0001(2) -> carry를 기준으로
### 2-2. And,Or(&,|)
```c++
void ops_and_or() {
    int a=9; // 1001(2)
    int b=8; // 1000(2)
    cout << (a&b) << "\n"; // 1000(2) == 8
    cout << (a|b) << "\n"; // 1001(2) == 9
}
```

### 2-3. Shift (<< , >> )
- a << b 는 a * 2**b와 같다.
```c++
void shift_test(){
	int a=7; //111(2)
	int b=a<<2; //11100(2) == 7 * pow(2,2);
	cout << (a<<1) << endl; // 7*2
	cout << (a<<2) << endl; // 7*pow(2,2)
	cout << (a<<3) << endl; // 7*pow(2,3)
}
```
- shift 연산자는 n번째 요소를 “켠다” 는 의미로 사용된다.
```c++
int turn_on_nth(int n){
	return 1<<n;
}
int main(){
	cout << turn_on_nth(3) << endl; // 1000(2) == 8
}
```

- a >> b 는 a * pow(1/2,b) 의 연산과 같다.
```c++
void shift_test(){
	int a=11; // 1011(2)
	cout << (a>>2) << endl; // 10(2) == 2
}
```

### 2-4. Xor(^) , one’s complementary (~)
- xor 연산은 반대값 만 true이다
```c++
int a=9;//1001(2)
int b=8;//1000(2)
int c=10;//1010(2)
cout << (a^b) <<endl; // 0001(2) == 1
cout << (a^c) <<endl; // 0011(2) == 3
```

- ~ 연산의 결과는 모든 비트의 반전(1의 보수)이다.
- ~ 연산의 값은 2의 보수법과 1의 보수법을 연합하여 해석하면 ~a = -(a+1)이다
- ~1 == -2 ==. -(1+1)
```c++
int a=8;//1000(2)
cout << ~a << endl; //0111(2) + 0001(2) == -a => 0111(2) == -8-1;
```

## 3. 비트연산의 활용
### 3-1. idx 번째 비트 끄기
int s 의 idx 번째 비트끄기 : s&~(1<<idx);
```c++
int S=10; // 1010(2);
int idx=1; 
S&~(1<<1);
cout << S << endl; // 1000(2)
```