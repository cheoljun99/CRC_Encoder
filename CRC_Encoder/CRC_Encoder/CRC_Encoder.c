// CRC-8 Encoder
#include<stdio.h>
#include<string.h>

int main() 
{
	printf("CRC-8 인코더 (입력 16-bit, 출력 24-bit)\n");
	while (1)
	{


		char input_D[17] = { 0 };
		int input_D_modify_into_number[24] = { 0, };
		int Divisor_G[9] = { 1,0,0,0,0,0,1,1,1 };
		char result[25] = { 0 };

		
		printf("입력: ");
		scanf("%s", input_D);
		//printf("input_D_modify_into_number: ");//테스트를 위한 코드
		for (int i = 0; input_D[i]; i++) {

			//입력받은 문자열 input_D를 계산의 편의성을 위해 int형으로 변환하는 과정
			input_D_modify_into_number[i] = input_D[i] - '0';
			//printf("%d", input_D_modify_into_number[i]);//테스트를 위한 코드

		}
		//printf("\n");//테스트를 위한 코드


		for (int i = 0; i < 16; i++) {
			//division이 왼쪽으로 n-k만큼 shifit
			//n=24,k=16
			//division이 즉 8만큼 왼쪽으로 shift 되었다고 가정하고
			//맨 왼쪽부터 확인하여 비트가 1인 것을 확인하면 Divisor_G를 가지고 modulo 2 arithmetic 즉 xor연산을 후의 바뀐 division을 계속해서 갱신하는데
			//해당 과정을 Q의 비트의 최대의 개수 즉 몫이 나올수 있는 최대의 횟수 (k) 동안 반복하여 나머지를 구한다.
			if (input_D_modify_into_number[i] == 1) {
				for (int j = 0; j < 9; j++) {
					input_D_modify_into_number[i + j] = Divisor_G[j] ^ input_D_modify_into_number[i + j];
				}
			}
			/*
			//테스트를 위한 코드
			printf("modulo 2 arithmetic 후 D: ");
			for (int k = 0; k < 24; k++) {
				printf("%d", input_D_modify_into_number[k]);

			}
			printf("\n");
			*/

		}

		/*
		////////////////////테스트 출력//////////////////////////
		char result_for_test[26] = { 0 };// 공백 하나 포함
		sprintf(result_for_test, "%s %d%d%d%d%d%d%d%d", input_D, input_D_modify_into_number[16], input_D_modify_into_number[17], input_D_modify_into_number[18], input_D_modify_into_number[19],
			input_D_modify_into_number[20], input_D_modify_into_number[21], input_D_modify_into_number[22], input_D_modify_into_number[23]);
		printf("출력(공백 포함 테스트용): %s\n", result_for_test);
		*/

		//몫이 나올수 있는 최대의 횟수 (k) 동안 반복하여 나온 division이 나머지가 된다. 아래는 원래의 division과 remainder를 합치는 과정이다.
		sprintf(result, "%s%d%d%d%d%d%d%d%d", input_D, input_D_modify_into_number[16], input_D_modify_into_number[17], input_D_modify_into_number[18], input_D_modify_into_number[19],
			input_D_modify_into_number[20], input_D_modify_into_number[21], input_D_modify_into_number[22], input_D_modify_into_number[23]);
		printf("출력: %s\n", result);
	}
	return 0;
}